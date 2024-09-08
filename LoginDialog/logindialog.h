//
// Created by lenovo on 2024/8/11.
//

#ifndef QCLOUDOBJ_LOGINDIALOG_H
#define QCLOUDOBJ_LOGINDIALOG_H

#include <QDialog>
#include <QLabel>


QT_BEGIN_NAMESPACE
namespace Ui {
    class LoginDialog;
}
QT_END_NAMESPACE

class LoginDialog : public QDialog {
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = nullptr);
    ~LoginDialog() override;

protected:
    void paintEvent(QPaintEvent *event) override;// 重写绘图事件、绘制背景图

private:
    Ui::LoginDialog *ui;
    // 写一个错误枚举
    enum ErrorType {
        NoError,              // 无错误
        EmptyUsername,        // 用户名为空
        EmptyPassword,        // 密码为空
        EmptyConfirmPasswd,   // 确认密码为空
        EmptyUsernameOrPasswd,// 用户名或密码为空
        EmptyEmail,           // 邮箱为空
        PasswordNotEqual,     // 两次密码不一致
        InvalidEmail,         // 邮箱格式不正确
        InvalidUsername,      // 用户名格式不正确
        InvalidPassword,      // 密码格式不正确
        IncalidUserOrPasswd   // 用户名或密码错误

    };
    ErrorType checkInput(QString username, QString password, QLabel *labTip);
    void rememberUser(QString username, QString password);
    void saveUserInfo(QString username, QString password, QString token, bool isRemember);
    //    void initQSS();// 初始化QSS样式
private slots:
    void login();       // 登录槽函数
    void registerUser();// 注册槽函
    void loginSuccess();
    void registerSuccess();
signals:
    // 登录成功信号
    void loginSuccessSignal();
    // 注册成功信号
    void registerSuccessSignal();
};


#endif//QCLOUDOBJ_LOGINDIALOG_H
