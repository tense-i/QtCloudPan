//
// Created by tensei on 2024/9/2.
//

#ifndef QCLOUDOBJ_MAINWINDOW_H
#define QCLOUDOBJ_MAINWINDOW_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui {
    class mainWindow;
}
QT_END_NAMESPACE

class mainWindow : public QWidget {
    Q_OBJECT

public:
    explicit mainWindow(QWidget *parent = nullptr);
    ~mainWindow() override;

private:
    Ui::mainWindow *ui;
};


#endif//QCLOUDOBJ_MAINWINDOW_H
