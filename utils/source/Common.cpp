//
// Created by tensei on 2024/9/8.
//

#include "../header/Common.h"
#include "../utils/header/des.h"
#include <QCryptographicHash>
#include <QDir>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>

Common::~Common() {
}
void Common::writeLoginInfo(QString username, QString password, bool isRemember, QString token, QString path) {

    // des加密username
    unsigned char encUsername[1024] = {0};
    int encUsernameLen = 0;

    int res = DesEnc((unsigned char *) username.toLocal8Bit().data(), username.toLocal8Bit().length(), encUsername, &encUsernameLen);
    if (res != 0) {
        qDebug() << "DesEnc error";
        return;
    }

    // des加密password
    unsigned char encPassword[1024] = {0};
    int encPasswordLen = 0;
    res = DesEnc((unsigned char *) password.toLocal8Bit().data(), password.toLocal8Bit().length(), encPassword, &encPasswordLen);
    if (res != 0) {
        qDebug() << "DesEnc error";
        return;
    }

    // 使用base64编码
    QString encUsernameBase64 = QByteArray((char *) encUsername, encUsernameLen).toBase64();
    QString encPasswordBase64 = QByteArray((char *) encPassword, encPasswordLen).toBase64();

    QMap<QString, QVariant> map;
    map.insert("username", encUsernameBase64);
    map.insert("password", encPasswordBase64);
    if (isRemember) {
        map.insert("isRemember", "true");
    } else {
        map.insert("isRemember", "false");
    }
    map.insert("token", token);
    QJsonDocument doc = QJsonDocument::fromVariant(map);
    QFile file(path);
    // 输出当前路径
    qDebug() << QDir::currentPath();

    if (file.open(QIODevice::WriteOnly)) {
        file.write(doc.toJson());
        file.close();
    } else {
        qDebug() << "writeLoginInfo error";
    }
}


void Common::readLoginInfo(QString &username, QString &password, bool &isRemember, QString path) {
    QFile file(path);
    QString usernameBase64AndDec;
    QString passwordBase64AndDec;
    QString isRememberStr;

    if (file.open(QIODevice::ReadOnly)) {
        QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
        QJsonObject json = doc.object();
        usernameBase64AndDec = json.value("username").toString();
        passwordBase64AndDec = json.value("password").toString();
        isRememberStr = json.value("isRemember").toString();
        file.close();
    }

    // base64解码
    QByteArray usernameBase64 = QByteArray::fromBase64(usernameBase64AndDec.toLocal8Bit());
    QByteArray passwordBase64 = QByteArray::fromBase64(passwordBase64AndDec.toLocal8Bit());

    // des解密username
    unsigned char desUsername[1024] = {0};
    int desUsernameLen = 0;
    DesDec((unsigned char *) usernameBase64.data(), usernameBase64.length(), desUsername, &desUsernameLen);

    // des解密password
    unsigned char desPassword[1024] = {0};
    int desPasswordLen = 0;
    DesDec((unsigned char *) passwordBase64.data(), passwordBase64.length(), desPassword, &desPasswordLen);

    username = QString::fromUtf8(reinterpret_cast<const char *>(desUsername));
    password = QString::fromUtf8(reinterpret_cast<const char *>(desPassword));
    isRemember = isRememberStr == "true";
}

QString Common::getMD5(QString str) {
    QByteArray ba;
    ba.append(str.toUtf8());
    return QCryptographicHash::hash(ba, QCryptographicHash::Md5).toHex();
}
