/********************************************************************************
** Form generated from reading UI file 'topbtngroup.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOPBTNGROUP_H
#define UI_TOPBTNGROUP_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TopBtnGroup
{
public:
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout;
    QToolButton *btnUser;
    QSpacerItem *horizontalSpacer_2;
    QToolButton *btnFile;
    QSpacerItem *horizontalSpacer_3;
    QToolButton *btnShareList;
    QSpacerItem *horizontalSpacer_4;
    QToolButton *btnDownlowdList;
    QSpacerItem *horizontalSpacer_5;
    QToolButton *btnUpdateList;
    QSpacerItem *horizontalSpacer_6;
    QToolButton *btnSwitchUser;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout;
    QGroupBox *toolBtnGroup;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QWidget *widget;
    QToolButton *btnHint;
    QToolButton *btnMax;
    QToolButton *btnClose;
    QGroupBox *groupBox_2;

    void setupUi(QWidget *TopBtnGroup)
    {
        if (TopBtnGroup->objectName().isEmpty())
            TopBtnGroup->setObjectName(QString::fromUtf8("TopBtnGroup"));
        TopBtnGroup->resize(567, 141);
        horizontalLayout_3 = new QHBoxLayout(TopBtnGroup);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        btnUser = new QToolButton(TopBtnGroup);
        btnUser->setObjectName(QString::fromUtf8("btnUser"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icon/title_user.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnUser->setIcon(icon);
        btnUser->setIconSize(QSize(32, 32));
        btnUser->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout->addWidget(btnUser);

        horizontalSpacer_2 = new QSpacerItem(17, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        btnFile = new QToolButton(TopBtnGroup);
        btnFile->setObjectName(QString::fromUtf8("btnFile"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icon/title_file.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnFile->setIcon(icon1);
        btnFile->setIconSize(QSize(32, 32));
        btnFile->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout->addWidget(btnFile);

        horizontalSpacer_3 = new QSpacerItem(17, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        btnShareList = new QToolButton(TopBtnGroup);
        btnShareList->setObjectName(QString::fromUtf8("btnShareList"));
        btnShareList->setIcon(icon1);
        btnShareList->setIconSize(QSize(32, 32));
        btnShareList->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout->addWidget(btnShareList);

        horizontalSpacer_4 = new QSpacerItem(13, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        btnDownlowdList = new QToolButton(TopBtnGroup);
        btnDownlowdList->setObjectName(QString::fromUtf8("btnDownlowdList"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icon/title_hot.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnDownlowdList->setIcon(icon2);
        btnDownlowdList->setIconSize(QSize(32, 32));
        btnDownlowdList->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout->addWidget(btnDownlowdList);

        horizontalSpacer_5 = new QSpacerItem(13, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        btnUpdateList = new QToolButton(TopBtnGroup);
        btnUpdateList->setObjectName(QString::fromUtf8("btnUpdateList"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icon/title_data.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnUpdateList->setIcon(icon3);
        btnUpdateList->setIconSize(QSize(32, 32));
        btnUpdateList->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout->addWidget(btnUpdateList);

        horizontalSpacer_6 = new QSpacerItem(13, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_6);

        btnSwitchUser = new QToolButton(TopBtnGroup);
        btnSwitchUser->setObjectName(QString::fromUtf8("btnSwitchUser"));
        btnSwitchUser->setIcon(icon3);
        btnSwitchUser->setIconSize(QSize(32, 32));
        btnSwitchUser->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout->addWidget(btnSwitchUser);


        horizontalLayout_3->addLayout(horizontalLayout);

        horizontalSpacer = new QSpacerItem(47, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        toolBtnGroup = new QGroupBox(TopBtnGroup);
        toolBtnGroup->setObjectName(QString::fromUtf8("toolBtnGroup"));
        verticalLayout_2 = new QVBoxLayout(toolBtnGroup);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        widget = new QWidget(toolBtnGroup);
        widget->setObjectName(QString::fromUtf8("widget"));

        horizontalLayout_2->addWidget(widget);

        btnHint = new QToolButton(toolBtnGroup);
        btnHint->setObjectName(QString::fromUtf8("btnHint"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icon/zuixiaohua_1.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnHint->setIcon(icon4);

        horizontalLayout_2->addWidget(btnHint);

        btnMax = new QToolButton(toolBtnGroup);
        btnMax->setObjectName(QString::fromUtf8("btnMax"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/icon/zuidahua_1.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnMax->setIcon(icon5);

        horizontalLayout_2->addWidget(btnMax);

        btnClose = new QToolButton(toolBtnGroup);
        btnClose->setObjectName(QString::fromUtf8("btnClose"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/icon/guanbi.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnClose->setIcon(icon6);

        horizontalLayout_2->addWidget(btnClose);


        verticalLayout_2->addLayout(horizontalLayout_2);

        groupBox_2 = new QGroupBox(toolBtnGroup);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setMinimumSize(QSize(56, 56));

        verticalLayout_2->addWidget(groupBox_2);


        verticalLayout->addWidget(toolBtnGroup);


        horizontalLayout_3->addLayout(verticalLayout);


        retranslateUi(TopBtnGroup);

        QMetaObject::connectSlotsByName(TopBtnGroup);
    } // setupUi

    void retranslateUi(QWidget *TopBtnGroup)
    {
        TopBtnGroup->setWindowTitle(QCoreApplication::translate("TopBtnGroup", "TopBtnGroup", nullptr));
        btnUser->setText(QCoreApplication::translate("TopBtnGroup", "vico", nullptr));
        btnFile->setText(QCoreApplication::translate("TopBtnGroup", "\346\210\221\347\232\204\346\226\207\344\273\266", nullptr));
        btnShareList->setText(QCoreApplication::translate("TopBtnGroup", "\345\205\261\344\272\253\345\210\227\350\241\250", nullptr));
        btnDownlowdList->setText(QCoreApplication::translate("TopBtnGroup", "\344\270\213\350\275\275\346\246\234", nullptr));
        btnUpdateList->setText(QCoreApplication::translate("TopBtnGroup", "\344\274\240\350\276\223 \345\210\227\350\241\250", nullptr));
        btnSwitchUser->setText(QCoreApplication::translate("TopBtnGroup", "\345\210\207\346\215\242\347\224\250\346\210\267", nullptr));
        toolBtnGroup->setTitle(QString());
        btnHint->setText(QCoreApplication::translate("TopBtnGroup", "...", nullptr));
        btnMax->setText(QCoreApplication::translate("TopBtnGroup", "...", nullptr));
        btnClose->setText(QCoreApplication::translate("TopBtnGroup", "...", nullptr));
        groupBox_2->setTitle(QString());
    } // retranslateUi

};

namespace Ui {
    class TopBtnGroup: public Ui_TopBtnGroup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOPBTNGROUP_H
