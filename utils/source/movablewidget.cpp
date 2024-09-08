//
// Created by tensei on 2024/8/16.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MovableWidget.h" resolved

#include "../header/movablewidget.h"
#include <QMouseEvent>

MovableWidget::MovableWidget(QWidget *parent) : QWidget(parent) {
    parent_ = parent;
}

MovableWidget::~MovableWidget() {
}
void MovableWidget::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        startPoint_ = event->globalPosition().toPoint() - parent_->geometry().topLeft();
    }
}
void MovableWidget::mouseMoveEvent(QMouseEvent *event) {
    if (event->buttons() & Qt::LeftButton) {
        parent_->move(event->globalPosition().toPoint() - startPoint_);
    }
}
