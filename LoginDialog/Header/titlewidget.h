//
// Created by lenovo on 2024/8/11.
//

#ifndef QCLOUDOBJ_TITLEWIDGET_H
#define QCLOUDOBJ_TITLEWIDGET_H

#include "../utils/header/movablewidget.h"
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
    class TitleWidget;
}
QT_END_NAMESPACE

class TitleWidget : public MovableWidget {
    Q_OBJECT

public:
    explicit TitleWidget(QWidget *parent = nullptr);
    ~TitleWidget() override;

    Ui::TitleWidget *const getUi() const;

private:
    Ui::TitleWidget *ui;
    void initUI();
};


#endif//QCLOUDOBJ_TITLEWIDGET_H
