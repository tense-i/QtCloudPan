
#include "../LoginDialog/Header/LoginUserInfo.h"
#include "../utils/header/DBUtils.h"
#include "./LoginDialog/logindialog.h"
#include "./mainWidget/header/myfilewidget.h"
#include "./mainWidget/mainwindow.h"

#include "Header/titlewidget.h"
#include "QDir"
#include <QApplication>
#include <QFile>
#include <QPushButton>
void initApplicationConfig() {
    // 设置应用程序名称
    QApplication::setApplicationName("QCloudObj");
    // 设置应用程序版本号
    QApplication::setApplicationVersion("1.0.0");
    // 设置应用程序组织名称
    QApplication::setOrganizationName("QCloudObj");
    // 设置应用程序组织域名
    QApplication::setOrganizationDomain("qcloudobj.com");
    // 添加jpg等库路径
    QApplication::addLibraryPath("D:/App/Qt/6.2.4/mingw_64/plugins");
}

int main(int argc, char *argv[]) {
    initApplicationConfig();
    QApplication a(argc, argv);

    mainWindow mw;
    mw.resize(800, 600);
    mw.showLoginDialog();

    return QApplication::exec();
}
