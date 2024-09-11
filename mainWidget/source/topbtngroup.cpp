//
// Created by tensei on 2024/9/9.
//

// You may need to build the project (run Qt uic code generator) to get "ui_TopBtnGroup.h" resolved

#include "header/topbtngroup.h"
#include "ui_TopBtnGroup.h"


const QString TopBtnGroup::selectBtnColor = "QToolButton{color:#00a1d6;}";
const QString TopBtnGroup::unSelectBtnColor = "QToolButton{color:#000000;}";

TopBtnGroup::TopBtnGroup(QWidget *parent) : MovableWidget(parent), ui(new Ui::TopBtnGroup) {
    ui->setupUi(this);

    //  初始化信号与曹
    connect(ui->btnFile, &QToolButton::clicked, this, [=] {
        emit open_myFilePage();
        if (currentSelectBtn != nullptr) {
            // 重置上一个按钮的样式
            currentSelectBtn->setStyleSheet(unSelectBtnColor);
            lastSelectBtn = currentSelectBtn;
        }
        // 设置当前按钮的样式
        ui->btnFile->setStyleSheet(selectBtnColor);
        currentSelectBtn = ui->btnFile;
        emit sig_changedSelectBtn(ui->btnFile);
    });
    connect(ui->btnUser, &QToolButton::clicked, this, [=] {
        emit open_UserPage();
        if (currentSelectBtn != nullptr) {
            // 重置上一个按钮的样式
            currentSelectBtn->setStyleSheet(unSelectBtnColor);
            lastSelectBtn = currentSelectBtn;
        }
        // 设置当前按钮的样式
        ui->btnUser->setStyleSheet(selectBtnColor);
        currentSelectBtn = ui->btnUser;
        emit sig_changedSelectBtn(ui->btnUser);
    });
    connect(ui->btnDownlowdList, &QToolButton::clicked, this, [=] {
        emit open_downloadListPage();
        if (currentSelectBtn != nullptr) {
            // 重置上一个按钮的样式
            currentSelectBtn->setStyleSheet(unSelectBtnColor);
            lastSelectBtn = currentSelectBtn;
        }
        // 设置当前按钮的样式
        ui->btnDownlowdList->setStyleSheet(selectBtnColor);
        currentSelectBtn = ui->btnDownlowdList;
        emit sig_changedSelectBtn(ui->btnDownlowdList);
    });
    connect(ui->btnUpdateList, &QToolButton::clicked, this, [=] {
        emit open_uploadListPage();
        if (currentSelectBtn != nullptr) {
            // 重置上一个按钮的样式颜色为黑色
            currentSelectBtn->setStyleSheet(unSelectBtnColor);
            lastSelectBtn = currentSelectBtn;
        }
        // 设置当前按钮的样式
        ui->btnUpdateList->setStyleSheet(selectBtnColor);
        currentSelectBtn = ui->btnUpdateList;
        emit sig_changedSelectBtn(ui->btnUpdateList);
    });
    connect(ui->btnShareList, &QToolButton::clicked, this, [=] {
        emit open_shareListPage();
        if (currentSelectBtn != nullptr) {
            // 重置上一个按钮的样式
            currentSelectBtn->setStyleSheet(unSelectBtnColor);
            lastSelectBtn = currentSelectBtn;
        }
        // 设置当前按钮的样式
        ui->btnShareList->setStyleSheet(selectBtnColor);
        currentSelectBtn = ui->btnShareList;
        emit sig_changedSelectBtn(ui->btnShareList);
    });


    connect(ui->btnUploadFile, &QToolButton::clicked, this, [=] {
        emit sig_uploadfile();
        if (currentSelectBtn != nullptr) {
            // 重置上一个按钮的样式
            currentSelectBtn->setStyleSheet(unSelectBtnColor);
            lastSelectBtn = currentSelectBtn;
        }
        // 设置当前按钮的样式
        ui->btnShareList->setStyleSheet(selectBtnColor);
        currentSelectBtn = ui->btnShareList;
        emit sig_changedSelectBtn(ui->btnUploadFile);
    });
}

TopBtnGroup::~TopBtnGroup() {
    delete ui;
}
Ui::TopBtnGroup *const TopBtnGroup::getUi() const {
    return ui;
}
