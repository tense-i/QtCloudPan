/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "topbtngroup.h"

QT_BEGIN_NAMESPACE

class Ui_mainWindow
{
public:
    QVBoxLayout *verticalLayout;
    TopBtnGroup *topTitleWidget;
    QSpacerItem *verticalSpacer;
    QWidget *mainErea;
    QVBoxLayout *verticalLayout_2;
    QStackedWidget *stackedWidget;
    QWidget *pageMyfile;
    QLabel *label;
    QWidget *page_User;
    QLabel *label_4;
    QWidget *page_downlowdLIst;
    QLabel *label_5;
    QWidget *pageUpdateList;
    QLabel *label_2;
    QWidget *page_shareList;
    QLabel *label_3;
    QWidget *page;

    void setupUi(QWidget *mainWindow)
    {
        if (mainWindow->objectName().isEmpty())
            mainWindow->setObjectName(QString::fromUtf8("mainWindow"));
        mainWindow->resize(508, 307);
        verticalLayout = new QVBoxLayout(mainWindow);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        topTitleWidget = new TopBtnGroup(mainWindow);
        topTitleWidget->setObjectName(QString::fromUtf8("topTitleWidget"));
        topTitleWidget->setMinimumSize(QSize(0, 21));

        verticalLayout->addWidget(topTitleWidget);

        verticalSpacer = new QSpacerItem(20, 107, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        mainErea = new QWidget(mainWindow);
        mainErea->setObjectName(QString::fromUtf8("mainErea"));
        mainErea->setMinimumSize(QSize(0, 200));
        verticalLayout_2 = new QVBoxLayout(mainErea);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        stackedWidget = new QStackedWidget(mainErea);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        pageMyfile = new QWidget();
        pageMyfile->setObjectName(QString::fromUtf8("pageMyfile"));
        label = new QLabel(pageMyfile);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(60, 70, 54, 16));
        stackedWidget->addWidget(pageMyfile);
        page_User = new QWidget();
        page_User->setObjectName(QString::fromUtf8("page_User"));
        label_4 = new QLabel(page_User);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(180, 30, 54, 16));
        stackedWidget->addWidget(page_User);
        page_downlowdLIst = new QWidget();
        page_downlowdLIst->setObjectName(QString::fromUtf8("page_downlowdLIst"));
        label_5 = new QLabel(page_downlowdLIst);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(190, 70, 54, 16));
        stackedWidget->addWidget(page_downlowdLIst);
        pageUpdateList = new QWidget();
        pageUpdateList->setObjectName(QString::fromUtf8("pageUpdateList"));
        label_2 = new QLabel(pageUpdateList);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(130, 50, 54, 16));
        stackedWidget->addWidget(pageUpdateList);
        page_shareList = new QWidget();
        page_shareList->setObjectName(QString::fromUtf8("page_shareList"));
        label_3 = new QLabel(page_shareList);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(220, 50, 54, 16));
        stackedWidget->addWidget(page_shareList);
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        stackedWidget->addWidget(page);

        verticalLayout_2->addWidget(stackedWidget);


        verticalLayout->addWidget(mainErea);


        retranslateUi(mainWindow);

        QMetaObject::connectSlotsByName(mainWindow);
    } // setupUi

    void retranslateUi(QWidget *mainWindow)
    {
        mainWindow->setWindowTitle(QCoreApplication::translate("mainWindow", "mainWindow", nullptr));
        label->setText(QCoreApplication::translate("mainWindow", "TextLabel", nullptr));
        label_4->setText(QCoreApplication::translate("mainWindow", "TextLabel", nullptr));
        label_5->setText(QCoreApplication::translate("mainWindow", "TextLabel", nullptr));
        label_2->setText(QCoreApplication::translate("mainWindow", "TextLabel", nullptr));
        label_3->setText(QCoreApplication::translate("mainWindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mainWindow: public Ui_mainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
