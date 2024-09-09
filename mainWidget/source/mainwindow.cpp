//
// Created by tensei on 2024/9/2.
//

// You may need to build the project (run Qt uic code generator) to get "ui_mainWindow.h" resolved

#include "mainwindow.h"
#include "header/topbtngroup.h"
#include "ui_TopBtnGroup.h"
#include "ui_mainWindow.h"

#include <QFile>
#include <QToolButton>

mainWindow::mainWindow(QWidget *parent) : QWidget(parent), ui(new Ui::mainWindow) {
    ui->setupUi(this);
    initBaseQSS();
    initSlot();
    // 去除自带的标题栏
    setWindowFlags(Qt::FramelessWindowHint);
}

mainWindow::~mainWindow() {
    delete ui;
}


void mainWindow::initBaseQSS() {
    // 设置QSS样式
    QFile file(":/style/base.qss");
    QString baseStyle;
    if (file.open(QIODevice::ReadOnly)) {
        baseStyle = QString::fromUtf8(file.readAll());
        file.close();
    }
    QString styleSheet;
    QFile file2(":/style/mainWindow.qss");
    if (file2.open(QIODevice::ReadOnly)) {
        styleSheet = QString::fromUtf8(file2.readAll());
        file2.close();
    }
    setStyleSheet(baseStyle + styleSheet);
}
void mainWindow::showMaxed() {
    if (isMaximized_) {
        showNormal();
        isMaximized_ = false;
        ui->topTitleWidget->getUi()->btnMax->setIcon(QIcon(":/icon/zuidahua_1.png"));
    } else {
        showMaximized();
        ui->topTitleWidget->getUi()->btnMax->setIcon(QIcon(":/icon/zuidahua.png"));
        isMaximized_ = true;
    }
}
void mainWindow::setUsernameInUI(QString username) {
    ui->topTitleWidget->getUi()->btnUser->setText(username);
}
void mainWindow::initSlot() {
    // 初始化信号与槽
    connect(ui->topTitleWidget->getUi()->btnHint, &QToolButton::clicked, this, &mainWindow::showMinimized);
    connect(ui->topTitleWidget->getUi()->btnClose, &QToolButton::clicked, this, &mainWindow::close);
    connect(ui->topTitleWidget->getUi()->btnMax, &QToolButton::clicked, this, &mainWindow::showMaxed);
    connect(ui->topTitleWidget, &TopBtnGroup::open_UserPage, this, [=]() {
        ui->stackedWidget->setCurrentWidget(ui->page_User);
    });
    connect(ui->topTitleWidget, &TopBtnGroup::open_myFilePage, this, [=]() {
        ui->stackedWidget->setCurrentWidget(ui->pageMyfile);
    });
    connect(ui->topTitleWidget, &TopBtnGroup::open_downloadListPage, this, [=]() {
        ui->stackedWidget->setCurrentWidget(ui->page_downlowdLIst);
    });
    connect(ui->topTitleWidget, &TopBtnGroup::open_uploadListPage, this, [=]() {
        ui->stackedWidget->setCurrentWidget(ui->pageUpdateList);
    });
    connect(ui->topTitleWidget, &TopBtnGroup::open_shareListPage, this, [=]() {
        ui->stackedWidget->setCurrentWidget(ui->page_shareList);
    });
}
