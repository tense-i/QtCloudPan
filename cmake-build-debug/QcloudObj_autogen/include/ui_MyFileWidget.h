/********************************************************************************
** Form generated from reading UI file 'myfilewidget.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYFILEWIDGET_H
#define UI_MYFILEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyFileWidget
{
public:
    QVBoxLayout *verticalLayout;
    QListWidget *listWidget;

    void setupUi(QWidget *MyFileWidget)
    {
        if (MyFileWidget->objectName().isEmpty())
            MyFileWidget->setObjectName(QString::fromUtf8("MyFileWidget"));
        MyFileWidget->resize(595, 443);
        verticalLayout = new QVBoxLayout(MyFileWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        listWidget = new QListWidget(MyFileWidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        verticalLayout->addWidget(listWidget);


        retranslateUi(MyFileWidget);

        QMetaObject::connectSlotsByName(MyFileWidget);
    } // setupUi

    void retranslateUi(QWidget *MyFileWidget)
    {
        MyFileWidget->setWindowTitle(QCoreApplication::translate("MyFileWidget", "MyFileWidget", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MyFileWidget: public Ui_MyFileWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYFILEWIDGET_H
