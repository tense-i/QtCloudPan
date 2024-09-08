//
// Created by lenovo on 2024/8/11.
//

// You may need to build the project (run Qt uic code generator) to get "ui_TitleWidget.h" resolved

#include "Header/titlewidget.h"
#include "ui_TitleWidget.h"
#include <QMouseEvent>

void TitleWidget::initUI() {
    ui->setupUi(this);
    //    // 设置标题栏图标
    ui->labLog->setPixmap(QPixmap(":/icon/logo.png").scaled(40, 40));
    // 取出标题栏
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setContentsMargins(0, 0, 0, 0);

    //
}

TitleWidget::TitleWidget(QWidget *parent) : MovableWidget(parent), ui(new Ui::TitleWidget) {
    initUI();
}

TitleWidget::~TitleWidget() {
    delete ui;
}
Ui::TitleWidget *const TitleWidget::getUi() const {
    return ui;
}
