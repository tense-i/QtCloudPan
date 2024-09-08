//
// Created by tensei on 2024/9/8.
//

#include "../header/Common.h"
#include <QCryptographicHash>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>

Common::~Common() {
}
void Common::writeLoginInfo(QString username, QString password, bool isRemember, QString path) {
    QJsonObject json;
    json.insert("username", username);
    QString md5Passwd = Common::getMD5(password);
    json.insert("password", md5Passwd);
    if (isRemember) {
        json.insert("isRemember", "true");
    } else {
        json.insert("isRemember", "false");
    }
    QJsonDocument doc(json);
    QFile file(path);
    if (file.open(QIODevice::WriteOnly)) {
        file.write(doc.toJson());
        file.close();
    }
}
f

        void
        Common::readLoginInfo(QString &username, QString &password, bool &isRemember, QString path) {
    QFile file(path);
    if (file.open(QIODevice::ReadOnly)) {
        QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
        QJsonObject json = doc.object();
        username = json.value("username").toString();
        password = json.value("password").toString();
        isRemember = json.value("isRemember").toBool();
        file.close();
    }
}

QString Common::getMD5(QString str) {
    QByteArray ba;
    ba.append(str.toUtf8());
    return QCryptographicHash::hash(ba, QCryptographicHash::Md5).toHex();
}
