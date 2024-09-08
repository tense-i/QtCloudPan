//
// Created by tensei on 2024/9/8.
//

#ifndef QCLOUDOBJ_LOGINUSERINFO_H
#define QCLOUDOBJ_LOGINUSERINFO_H

#include <QString>

class LoginUserInfo {
private:
    LoginUserInfo() = default;
    static LoginUserInfo *instance;

public:
    static LoginUserInfo *getInstance() {
        if (instance == nullptr) {
            instance = new LoginUserInfo();
        }
        return instance;
    }

    QString getUsername() const;

    void setUsername(const QString &username) {
        LoginUserInfo::username = username;
    }

    bool isIsRemember() const {
        return isRemember;
    }

    void setIsRemember(bool isRemember) {
        LoginUserInfo::isRemember = isRemember;
    }

    QString getToken() const {
        return token;
    }

    void setToken(const QString &token) {
        LoginUserInfo::token = token;
    }

    QString getIp() const {
        return ip;
    }

    void setIp(const QString &ip) {
        LoginUserInfo::ip = ip;
    }

    QString getPort() const {
        return port;
    }

    void setPort(const QString &port) {
        LoginUserInfo::port = port;
    }

private:
    QString username;
    bool isRemember;
    QString token;
    QString ip;
    QString port;
};


#endif//QCLOUDOBJ_LOGINUSERINFO_H
