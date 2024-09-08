//
// Created by tensei on 2024/9/2.
//

// You may need to build the project (run Qt uic code generator) to get "ui_mainWindow.h" resolved

#include "mainwindow.h"
#include "ui_mainWindow.h"


mainWindow::mainWindow(QWidget *parent) : QWidget(parent), ui(new Ui::mainWindow) {
    ui->setupUi(this);
}

mainWindow::~mainWindow() {
    delete ui;
}
