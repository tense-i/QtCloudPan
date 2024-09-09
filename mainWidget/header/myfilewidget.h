//
// Created by tensei on 2024/9/9.
//

#ifndef QCLOUDOBJ_MYFILEWIDGET_H
#define QCLOUDOBJ_MYFILEWIDGET_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui {
    class MyFileWidget;
}
QT_END_NAMESPACE

class MyFileWidget : public QWidget {
    Q_OBJECT

public:
    explicit MyFileWidget(QWidget *parent = nullptr);
    ~MyFileWidget() override;

private:
    Ui::MyFileWidget *ui;
};


#endif//QCLOUDOBJ_MYFILEWIDGET_H
