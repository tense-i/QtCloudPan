//
// Created by tensei on 2024/9/9.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MyFileWidget.h" resolved

#include "myfilewidget.h"
#include "ui_MyFileWidget.h"


MyFileWidget::MyFileWidget(QWidget *parent) : QWidget(parent), ui(new Ui::MyFileWidget) {
    ui->setupUi(this);
}

MyFileWidget::~MyFileWidget() {
    delete ui;
}
