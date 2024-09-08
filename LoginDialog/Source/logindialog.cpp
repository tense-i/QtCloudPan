//
// Created by lenovo on 2024/8/11.
//

// You may need to build the project (run Qt uic code generator) to get "ui_LoginDialog.h" resolved

#include "logindialog.h"
#include "../utils/header/Common.h"
#include "../utils/header/QHttpRequest.h"
#include "./header/LoginUserInfo.h"
#include "QDebug"
#include "QImageWriter"
#include "QPainter"

#include "ui_LoginDialog.h"
#include "ui_TitleWidget.h"


#include <QCryptographicHash>
#include <QFile>
#include <QJsonDocument>
#include <QLabel>
#include <QLineEdit>

#include <QNetworkReply>

#include <QPushButton>
#include <QRegularExpression>
#include <QToolButton>


const QString username_reg = "^[a-zA-Z0-9_\u4e00-\u9fa5]{4,16}$";
const QString password_reg = "^[a-zA-Z0-9]{6,12}$";
const QString email_reg = "^[a-zA-Z0-9_-]+@[a-zA-Z0-9_-]+(\\.[a-zA-Z0-9_-]+)+$";


void initQSS() {
    // 读取QSS样式
    qDebug() << "initQSS";
    QFile file(":/style/LoginDialogStyle.qss");
    if (file.open(QIODevice::ReadOnly)) {
        QString styleSheet = QString::fromUtf8(file.readAll());
        qApp->setStyleSheet(styleSheet);
        file.close();
    }
}
LoginDialog::LoginDialog(QWidget *parent) : QDialog(parent), ui(new Ui::LoginDialog) {
    ui->setupUi(this);
    // 初始化QSS样式
    initQSS();
    // 隐藏自带标题栏
    this->setWindowFlags(Qt::FramelessWindowHint);
    // 设为密码输入
    ui->editPasswd->setEchoMode(QLineEdit::Password);
    ui->editPasswd_rg->setEchoMode(QLineEdit::Password);
    ui->editConfirmPasswd->setEchoMode(QLineEdit::Password);

    // 绑定标题栏的信号与曹
    auto titleBarUI = ui->titleBarWidget->getUi();
    connect(titleBarUI->toolBtnMin, &QToolButton::clicked, this, &LoginDialog::showMinimized);
    connect(titleBarUI->toolBtnMax, &QToolButton::clicked, this, &LoginDialog::showMaximized);
    connect(titleBarUI->toolBtnClose, &QToolButton::clicked, this, &LoginDialog::close);
    connect(ui->toolBtnLogin, &QToolButton::clicked, this, &LoginDialog::login);
    connect(ui->btnRegister, &QToolButton::clicked, this, &LoginDialog::registerUser);
    connect(ui->toRegitsePage, &QToolButton::clicked, [this]() {
        ui->stackedWidget->setCurrentIndex(1);
    });
    connect(ui->toLoginPage, &QToolButton::clicked, [this]() {
        ui->stackedWidget->setCurrentIndex(0);
    });


    // 设置窗口大小
    this->setFixedSize(600, 400);
    ui->stackedWidget->setCurrentIndex(0);
    //    ui->editUsername->setText("admin");

    // 读取登录信息
    QString username;
    QString password;
    bool isRemember;
    Common::readLoginInfo(username, password, isRemember);
    // 渲染登录信息
    if (isRemember) {
        ui->editUsername->setText(username);
        ui->editPasswd->setText(password);
        ui->ckboxSavePasswd->setChecked(true);
    }
}


LoginDialog::~LoginDialog() {
    delete ui;
}

void LoginDialog::paintEvent(QPaintEvent *event) {
    //    QPainter painter(this);
    //    QPixmap pix(":/icon/login_bk.jpg");
    //    painter.drawPixmap(0, 0, this->width(), this->height(), pix);
}


// 校验函数

void LoginDialog::login() {
    QString username = ui->editUsername->text();
    QString password = ui->editPasswd->text();
    bool isRemember = ui->ckboxSavePasswd->isChecked();
    LoginDialog::ErrorType err = checkInput(username, password, ui->labTip);
    switch (err) {
        case ErrorType::EmptyUsernameOrPasswd:
            return;
        case ErrorType::InvalidUsername:
            ui->editUsername->setText("");
            return;
        case ErrorType::InvalidPassword:
            ui->editPasswd->setText("");
            return;
    }

    // md5加密
    QByteArray pswdMd5 = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Md5);
    QString md5Passwd = QString(pswdMd5.toHex());

    // 发送请求到服务器
    QHttpRequest *request = new QHttpRequest();
    request->setRequestUrl("http://localhost:8080/cloudObj/login");
    request->addRequestParameterInJson("username", username);
    request->addRequestParameterInJson("password", md5Passwd);
    request->sendPostRequest();

    QNetworkReply *reply = request->getReply();
    connect(reply, &QNetworkReply::finished, [=]() {
        if (reply->error() == QNetworkReply::NoError) {
            QByteArray data = reply->readAll();
            QJsonDocument doc = QJsonDocument::fromJson(data);
            QJsonObject obj = doc.object();
            if (obj.value("status").toInt() == 1) {
                emit loginSuccessSignal();
                ui->labTip->setText("登录成功");
                // 读取Token
                QString token = obj.value("token").toString();
                qDebug() << "token: " << token;
                // 保存登录信息
                Common::writeLoginInfo(username, password, isRemember, token);
                // 保存登录信息到单例
                saveUserInfo(username, password, token, isRemember);

            } else {
                ui->labTip->setText("用户名或密码错误");
                return;
            }
        } else {
            qDebug() << reply->error();
            ui->labTip->setText("网络错误");
            return;
        }

        if (ui->ckboxSavePasswd->isChecked()) {
        }
    });
}
void LoginDialog::registerUser() {

    QString username = ui->editUsername_rg->text();
    QString password = ui->editPasswd_rg->text();
    QString confirmPasswd = ui->editConfirmPasswd->text();
    QString email = ui->editEmail->text();

    ui->labTip_rg->setStyleSheet("color: red");
    LoginDialog::ErrorType error = checkInput(username, password, ui->labTip_rg);
    switch (error) {
        case ErrorType::EmptyUsernameOrPasswd:
            return;
        case ErrorType::InvalidUsername:
            ui->editUsername_rg->setText("");
            return;
        case ErrorType::InvalidPassword:
            ui->editPasswd_rg->setText("");
            return;
    }

    // 匹配确认密码
    if (password != confirmPasswd) {
        ui->labTip_rg->setText("两次密码不一致");
        ui->editConfirmPasswd->setText("");
        return;
    }

    // 匹配邮箱
    QRegularExpression reg;
    reg.setPattern(email_reg);
    if (!reg.match(email).hasMatch()) {
        ui->labTip_rg->setText("邮箱格式错误");
        ui->editEmail->setText("");
        return;
    }

    // 使用MD5加密密码
    QByteArray md5Passwd = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Md5);

    // 发送请求到服务器
    QHttpRequest *request = new QHttpRequest();
    request->setRequestUrl("http://localhost:8080/cloudObj/register");
    request->addRequestParameterInJson("username", username);
    request->addRequestParameterInJson("password", QString(md5Passwd.toHex()));
    request->addRequestParameterInJson("email", email);
    request->sendPostRequest();
    QNetworkReply *reply = request->getReply();
    // 接收响应
    connect(reply, &QNetworkReply::finished, [this, reply]() {
        if (reply->error() == QNetworkReply::NoError) {
            QByteArray data = reply->readAll();
            QJsonDocument doc = QJsonDocument::fromJson(data);
            QJsonObject obj = doc.object();
            int status = obj.value("status").toInt();

            if (obj.value("status").toInt() == 1) {
                ui->labTip_rg->setStyleSheet("color: green");
                ui->labTip_rg->setText("注册成功");

                // 注册成功
                emit registerSuccessSignal();

            } else if (status == 2) {
                ui->labTip_rg->setText("用户名已存在");
                ui->editUsername_rg->setText("");
                return;
            } else {
                ui->labTip_rg->setText("注册失败");
                return;
            }
        } else {
            ui->labTip_rg->setText("网络错误");
        }
    });
}
LoginDialog::ErrorType LoginDialog::checkInput(QString username, QString password, QLabel *labTip) {
    labTip->setText("");// 清空提示f
    labTip->setStyleSheet("color: red");
    if (username.isEmpty() || password.isEmpty()) {
        labTip->setText("用户名或密码不能为空");
        return ErrorType::EmptyUsernameOrPasswd;
    }

    // 匹配用户名、包含中文、字母、数字、下划线
    QRegularExpression reg(username_reg);
    if (!reg.match(username).hasMatch()) {
        labTip->setText("用户名格式错误");
        return ErrorType::InvalidUsername;
    }

    // 匹配密码
    reg.setPattern(password_reg);
    if (!reg.match(password).hasMatch()) {
        labTip->setText("密码格式错误");
        return ErrorType::InvalidPassword;
    }

    return ErrorType::NoError;
}
void LoginDialog::loginSuccess() {
}
void LoginDialog::registerSuccess() {
}
void LoginDialog::rememberUser(QString username, QString password) {
}
void LoginDialog::saveUserInfo(QString username, QString password, QString token, bool isRemember) {
    LoginUserInfo *loginUserInfo = LoginUserInfo::getInstance();
    loginUserInfo->setUsername(username);
    loginUserInfo->setToken(token);
    loginUserInfo->setIsRemember(isRemember);
    loginUserInfo->setIp("localhost");
    loginUserInfo->setPort("8080");
}
