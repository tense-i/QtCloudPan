//
// Created by tensei on 2024/9/8.
//

#ifndef QCLOUDOBJ_COMMON_H
#define QCLOUDOBJ_COMMON_H


#include <QString>


const QString LOGIN_INFO_PATH = "config/cfg.json";

class Common {
public:
    Common();
    ~Common();

    // 写登录信息
    static void writeLoginInfo(QString username, QString password, bool isRemember, QString path = LOGIN_INFO_PATH);
    // 读登录信息
    static void readLoginInfo(QString &username, QString &password, bool &isRemember, QString path = LOGIN_INFO_PATH);


    // 获取md5加密后的字符串
    static QString getMD5(QString str);
};


#endif//QCLOUDOBJ_COMMON_H
