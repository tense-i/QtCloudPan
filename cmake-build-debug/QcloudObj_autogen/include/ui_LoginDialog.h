/********************************************************************************
** Form generated from reading UI file 'logindialog.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDIALOG_H
#define UI_LOGINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "titlewidget.h"

QT_BEGIN_NAMESPACE

class Ui_LoginDialog
{
public:
    QVBoxLayout *verticalLayout_5;
    TitleWidget *titleBarWidget;
    QStackedWidget *stackedWidget;
    QWidget *login;
    QVBoxLayout *verticalLayout_6;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_3;
    QWidget *loginWidget;
    QVBoxLayout *verticalLayout_2;
    QLabel *labTitel;
    QWidget *userInfoWidget;
    QGridLayout *gridLayout;
    QLineEdit *editPasswd;
    QLabel *labPasswd;
    QLabel *labUsername;
    QLineEdit *editUsername;
    QLabel *labTip;
    QWidget *ckWidget;
    QHBoxLayout *horizontalLayout;
    QCheckBox *ckboxSavePasswd;
    QToolButton *toRegitsePage;
    QWidget *submitWidget;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QToolButton *toolBtnLogin;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer_4;
    QWidget *regist;
    QVBoxLayout *verticalLayout_4;
    QSpacerItem *verticalSpacer_8;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_13;
    QWidget *widget;
    QVBoxLayout *verticalLayout_3;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_6;
    QLabel *label;
    QSpacerItem *horizontalSpacer_7;
    QWidget *widget_2;
    QGridLayout *gridLayout_2;
    QLabel *labTip_rg;
    QLineEdit *editUsername_rg;
    QLabel *labPasswd_rg;
    QLabel *labEmail;
    QLineEdit *editConfirmPasswd;
    QLabel *labUserName_rg;
    QLineEdit *editPasswd_rg;
    QLineEdit *editEmail;
    QLabel *labConfirmPasswd;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *btnRegister;
    QSpacerItem *horizontalSpacer_5;
    QToolButton *toLoginPage;
    QSpacerItem *horizontalSpacer_9;
    QSpacerItem *horizontalSpacer_12;
    QSpacerItem *verticalSpacer_7;
    QWidget *set;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_10;
    QFrame *frame_2;
    QGridLayout *gridLayout_4;
    QFrame *frame;
    QGridLayout *gridLayout_3;
    QLabel *label_3;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit;
    QSpacerItem *horizontalSpacer_11;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QDialog *LoginDialog)
    {
        if (LoginDialog->objectName().isEmpty())
            LoginDialog->setObjectName(QString::fromUtf8("LoginDialog"));
        LoginDialog->resize(486, 515);
        LoginDialog->setMinimumSize(QSize(40, 40));
        LoginDialog->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_5 = new QVBoxLayout(LoginDialog);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        titleBarWidget = new TitleWidget(LoginDialog);
        titleBarWidget->setObjectName(QString::fromUtf8("titleBarWidget"));

        verticalLayout_5->addWidget(titleBarWidget);

        stackedWidget = new QStackedWidget(LoginDialog);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        login = new QWidget();
        login->setObjectName(QString::fromUtf8("login"));
        verticalLayout_6 = new QVBoxLayout(login);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalSpacer_3 = new QSpacerItem(20, 42, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer_3);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        loginWidget = new QWidget(login);
        loginWidget->setObjectName(QString::fromUtf8("loginWidget"));
        verticalLayout_2 = new QVBoxLayout(loginWidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        labTitel = new QLabel(loginWidget);
        labTitel->setObjectName(QString::fromUtf8("labTitel"));

        verticalLayout_2->addWidget(labTitel);

        userInfoWidget = new QWidget(loginWidget);
        userInfoWidget->setObjectName(QString::fromUtf8("userInfoWidget"));
        gridLayout = new QGridLayout(userInfoWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        editPasswd = new QLineEdit(userInfoWidget);
        editPasswd->setObjectName(QString::fromUtf8("editPasswd"));

        gridLayout->addWidget(editPasswd, 2, 1, 1, 1);

        labPasswd = new QLabel(userInfoWidget);
        labPasswd->setObjectName(QString::fromUtf8("labPasswd"));

        gridLayout->addWidget(labPasswd, 2, 0, 1, 1);

        labUsername = new QLabel(userInfoWidget);
        labUsername->setObjectName(QString::fromUtf8("labUsername"));

        gridLayout->addWidget(labUsername, 1, 0, 1, 1);

        editUsername = new QLineEdit(userInfoWidget);
        editUsername->setObjectName(QString::fromUtf8("editUsername"));

        gridLayout->addWidget(editUsername, 1, 1, 1, 1);

        labTip = new QLabel(userInfoWidget);
        labTip->setObjectName(QString::fromUtf8("labTip"));

        gridLayout->addWidget(labTip, 0, 1, 1, 1);


        verticalLayout_2->addWidget(userInfoWidget);

        ckWidget = new QWidget(loginWidget);
        ckWidget->setObjectName(QString::fromUtf8("ckWidget"));
        horizontalLayout = new QHBoxLayout(ckWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        ckboxSavePasswd = new QCheckBox(ckWidget);
        ckboxSavePasswd->setObjectName(QString::fromUtf8("ckboxSavePasswd"));

        horizontalLayout->addWidget(ckboxSavePasswd);

        toRegitsePage = new QToolButton(ckWidget);
        toRegitsePage->setObjectName(QString::fromUtf8("toRegitsePage"));

        horizontalLayout->addWidget(toRegitsePage);


        verticalLayout_2->addWidget(ckWidget);

        submitWidget = new QWidget(loginWidget);
        submitWidget->setObjectName(QString::fromUtf8("submitWidget"));
        horizontalLayout_2 = new QHBoxLayout(submitWidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(75, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        toolBtnLogin = new QToolButton(submitWidget);
        toolBtnLogin->setObjectName(QString::fromUtf8("toolBtnLogin"));

        horizontalLayout_2->addWidget(toolBtnLogin);

        horizontalSpacer_2 = new QSpacerItem(74, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout_2->addWidget(submitWidget);


        horizontalLayout_3->addWidget(loginWidget);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);


        verticalLayout_6->addLayout(horizontalLayout_3);

        verticalSpacer_4 = new QSpacerItem(20, 41, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer_4);

        stackedWidget->addWidget(login);
        regist = new QWidget();
        regist->setObjectName(QString::fromUtf8("regist"));
        verticalLayout_4 = new QVBoxLayout(regist);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalSpacer_8 = new QSpacerItem(20, 98, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_8);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_13);

        widget = new QWidget(regist);
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout_3 = new QVBoxLayout(widget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        widget_4 = new QWidget(widget);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        horizontalLayout_4 = new QHBoxLayout(widget_4);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer_6 = new QSpacerItem(3, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_6);

        label = new QLabel(widget_4);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_4->addWidget(label);

        horizontalSpacer_7 = new QSpacerItem(54, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_7);


        verticalLayout_3->addWidget(widget_4);

        widget_2 = new QWidget(widget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        gridLayout_2 = new QGridLayout(widget_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        labTip_rg = new QLabel(widget_2);
        labTip_rg->setObjectName(QString::fromUtf8("labTip_rg"));

        gridLayout_2->addWidget(labTip_rg, 0, 0, 1, 2);

        editUsername_rg = new QLineEdit(widget_2);
        editUsername_rg->setObjectName(QString::fromUtf8("editUsername_rg"));

        gridLayout_2->addWidget(editUsername_rg, 1, 1, 1, 1);

        labPasswd_rg = new QLabel(widget_2);
        labPasswd_rg->setObjectName(QString::fromUtf8("labPasswd_rg"));

        gridLayout_2->addWidget(labPasswd_rg, 2, 0, 1, 1);

        labEmail = new QLabel(widget_2);
        labEmail->setObjectName(QString::fromUtf8("labEmail"));

        gridLayout_2->addWidget(labEmail, 4, 0, 1, 1);

        editConfirmPasswd = new QLineEdit(widget_2);
        editConfirmPasswd->setObjectName(QString::fromUtf8("editConfirmPasswd"));

        gridLayout_2->addWidget(editConfirmPasswd, 3, 1, 1, 1);

        labUserName_rg = new QLabel(widget_2);
        labUserName_rg->setObjectName(QString::fromUtf8("labUserName_rg"));

        gridLayout_2->addWidget(labUserName_rg, 1, 0, 1, 1);

        editPasswd_rg = new QLineEdit(widget_2);
        editPasswd_rg->setObjectName(QString::fromUtf8("editPasswd_rg"));

        gridLayout_2->addWidget(editPasswd_rg, 2, 1, 1, 1);

        editEmail = new QLineEdit(widget_2);
        editEmail->setObjectName(QString::fromUtf8("editEmail"));

        gridLayout_2->addWidget(editEmail, 4, 1, 1, 1);

        labConfirmPasswd = new QLabel(widget_2);
        labConfirmPasswd->setObjectName(QString::fromUtf8("labConfirmPasswd"));

        gridLayout_2->addWidget(labConfirmPasswd, 3, 0, 1, 1);


        verticalLayout_3->addWidget(widget_2);

        widget_3 = new QWidget(widget);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        horizontalLayout_5 = new QHBoxLayout(widget_3);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalSpacer_8 = new QSpacerItem(0, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_8);

        btnRegister = new QPushButton(widget_3);
        btnRegister->setObjectName(QString::fromUtf8("btnRegister"));

        horizontalLayout_5->addWidget(btnRegister);

        horizontalSpacer_5 = new QSpacerItem(1, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_5);

        toLoginPage = new QToolButton(widget_3);
        toLoginPage->setObjectName(QString::fromUtf8("toLoginPage"));

        horizontalLayout_5->addWidget(toLoginPage);

        horizontalSpacer_9 = new QSpacerItem(0, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_9);


        verticalLayout_3->addWidget(widget_3);


        horizontalLayout_7->addWidget(widget);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_12);


        verticalLayout_4->addLayout(horizontalLayout_7);

        verticalSpacer_7 = new QSpacerItem(20, 98, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_7);

        stackedWidget->addWidget(regist);
        set = new QWidget();
        set->setObjectName(QString::fromUtf8("set"));
        verticalLayout = new QVBoxLayout(set);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer = new QSpacerItem(20, 95, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_10);

        frame_2 = new QFrame(set);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayout_4 = new QGridLayout(frame_2);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        frame = new QFrame(frame_2);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_3 = new QGridLayout(frame);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_3 = new QLabel(frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_3->addWidget(label_3, 1, 0, 1, 1);

        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_3->addWidget(label_2, 0, 0, 1, 1);

        lineEdit_2 = new QLineEdit(frame);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        gridLayout_3->addWidget(lineEdit_2, 1, 1, 1, 1);

        lineEdit = new QLineEdit(frame);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout_3->addWidget(lineEdit, 0, 1, 1, 1);


        gridLayout_4->addWidget(frame, 0, 0, 1, 1);


        horizontalLayout_6->addWidget(frame_2);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_11);


        verticalLayout->addLayout(horizontalLayout_6);

        verticalSpacer_2 = new QSpacerItem(20, 95, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        stackedWidget->addWidget(set);

        verticalLayout_5->addWidget(stackedWidget);


        retranslateUi(LoginDialog);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(LoginDialog);
    } // setupUi

    void retranslateUi(QDialog *LoginDialog)
    {
        LoginDialog->setWindowTitle(QCoreApplication::translate("LoginDialog", "LoginDialog", nullptr));
        labTitel->setText(QCoreApplication::translate("LoginDialog", "\347\224\250\346\210\267\347\231\273\345\275\225", nullptr));
        labPasswd->setText(QCoreApplication::translate("LoginDialog", "\345\257\206\347\240\201", nullptr));
        labUsername->setText(QCoreApplication::translate("LoginDialog", "\347\224\250\346\210\267\345\220\215", nullptr));
        labTip->setText(QString());
        ckboxSavePasswd->setText(QCoreApplication::translate("LoginDialog", "\350\256\260\344\275\217\345\257\206\347\240\201", nullptr));
        toRegitsePage->setText(QCoreApplication::translate("LoginDialog", "\347\253\213\345\215\263\346\263\250\345\206\214", nullptr));
        toolBtnLogin->setText(QCoreApplication::translate("LoginDialog", "\347\231\273\345\275\225", nullptr));
        label->setText(QCoreApplication::translate("LoginDialog", "\347\224\250\346\210\267\346\263\250\345\206\214", nullptr));
        labTip_rg->setText(QString());
        labPasswd_rg->setText(QCoreApplication::translate("LoginDialog", "\345\257\206\347\240\201", nullptr));
        labEmail->setText(QCoreApplication::translate("LoginDialog", "\351\202\256\347\256\261", nullptr));
        labUserName_rg->setText(QCoreApplication::translate("LoginDialog", "\347\224\250\346\210\267\345\220\215", nullptr));
        labConfirmPasswd->setText(QCoreApplication::translate("LoginDialog", "\347\241\256\350\256\244\345\257\206\347\240\201", nullptr));
        btnRegister->setText(QCoreApplication::translate("LoginDialog", "\346\263\250\345\206\214", nullptr));
        toLoginPage->setText(QCoreApplication::translate("LoginDialog", "\347\253\213\345\215\263\347\231\273\345\275\225", nullptr));
        label_3->setText(QCoreApplication::translate("LoginDialog", "TextLabel", nullptr));
        label_2->setText(QCoreApplication::translate("LoginDialog", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginDialog: public Ui_LoginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDIALOG_H
