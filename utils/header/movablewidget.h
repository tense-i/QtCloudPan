//
// Created by tensei on 2024/8/16.
//

#ifndef QCLOUDOBJ_MOVABLEWIDGET_H
#define QCLOUDOBJ_MOVABLEWIDGET_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui {
    class MovableWidget;
}
QT_END_NAMESPACE

class MovableWidget : public QWidget {
    Q_OBJECT

public:
    explicit MovableWidget(QWidget *parent = nullptr);
    ~MovableWidget() override;

protected:
    void mouseMoveEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;

private:
    QWidget *parent_ = nullptr;// 父窗口、用于移动窗口
    QPoint startPoint_;        // 鼠标相对窗口的起始位置
};


#endif//QCLOUDOBJ_MOVABLEWIDGET_H
