//
// Created by tensei on 2024/9/9.
//

// You may need to build the project (run Qt uic code generator) to get "ui_TopBtnGroup.h" resolved

#include "header/topbtngroup.h"
#include "ui_TopBtnGroup.h"


TopBtnGroup::TopBtnGroup(QWidget *parent) : MovableWidget(parent), ui(new Ui::TopBtnGroup) {
    ui->setupUi(this);

    //  初始化信号与曹
    connect(ui->btnFile, &QToolButton::clicked, this, &TopBtnGroup::open_myFilePage);
    connect(ui->btnUser, &QToolButton::clicked, this, &TopBtnGroup::open_UserPage);
    connect(ui->btnDownlowdList, &QToolButton::clicked, this, &TopBtnGroup::open_downloadListPage);
    connect(ui->btnUpdateList, &QToolButton::clicked, this, &TopBtnGroup::open_uploadListPage);
    connect(ui->btnShareList, &QToolButton::clicked, this, &TopBtnGroup::open_shareListPage);
}

TopBtnGroup::~TopBtnGroup() {
    delete ui;
}
Ui::TopBtnGroup *const TopBtnGroup::getUi() const {
    return ui;
}
