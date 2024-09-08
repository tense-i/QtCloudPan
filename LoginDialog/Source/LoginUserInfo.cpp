//
// Created by tensei on 2024/9/8.
//

#include "LoginUserInfo.h"

LoginUserInfo *LoginUserInfo::instance = new LoginUserInfo();

QString LoginUserInfo::getUsername() const {
    return username;
}
