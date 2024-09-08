/********************************************************************************
** Form generated from reading UI file 'titlewidget.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TITLEWIDGET_H
#define UI_TITLEWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TitleWidget
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *labLog;
    QLabel *labTitle;
    QSpacerItem *horizontalSpacer;
    QToolButton *toolBtnMin;
    QToolButton *toolBtnMax;
    QToolButton *toolBtnClose;

    void setupUi(QWidget *TitleWidget)
    {
        if (TitleWidget->objectName().isEmpty())
            TitleWidget->setObjectName(QString::fromUtf8("TitleWidget"));
        TitleWidget->resize(478, 82);
        TitleWidget->setStyleSheet(QString::fromUtf8(" padding: 0px;                   /* \347\247\273\351\231\244\345\206\205\350\276\271\350\267\235 */\n"
"    margin: 0px;                    /* \347\247\273\351\231\244\345\244\226\350\276\271\350\267\235 */"));
        horizontalLayout = new QHBoxLayout(TitleWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        labLog = new QLabel(TitleWidget);
        labLog->setObjectName(QString::fromUtf8("labLog"));
        labLog->setPixmap(QPixmap(QString::fromUtf8(":/icon/logo.png")));

        horizontalLayout->addWidget(labLog);

        labTitle = new QLabel(TitleWidget);
        labTitle->setObjectName(QString::fromUtf8("labTitle"));

        horizontalLayout->addWidget(labTitle);

        horizontalSpacer = new QSpacerItem(255, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        toolBtnMin = new QToolButton(TitleWidget);
        toolBtnMin->setObjectName(QString::fromUtf8("toolBtnMin"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icon/zuixiaohua_1.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolBtnMin->setIcon(icon);

        horizontalLayout->addWidget(toolBtnMin);

        toolBtnMax = new QToolButton(TitleWidget);
        toolBtnMax->setObjectName(QString::fromUtf8("toolBtnMax"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icon/zuidahua_1.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolBtnMax->setIcon(icon1);

        horizontalLayout->addWidget(toolBtnMax);

        toolBtnClose = new QToolButton(TitleWidget);
        toolBtnClose->setObjectName(QString::fromUtf8("toolBtnClose"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icon/guanbi.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolBtnClose->setIcon(icon2);

        horizontalLayout->addWidget(toolBtnClose);


        retranslateUi(TitleWidget);

        QMetaObject::connectSlotsByName(TitleWidget);
    } // setupUi

    void retranslateUi(QWidget *TitleWidget)
    {
        TitleWidget->setWindowTitle(QCoreApplication::translate("TitleWidget", "TitleWidget", nullptr));
        labLog->setText(QString());
        labTitle->setText(QCoreApplication::translate("TitleWidget", "CloudPan", nullptr));
        toolBtnMin->setText(QString());
        toolBtnMax->setText(QString());
        toolBtnClose->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class TitleWidget: public Ui_TitleWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TITLEWIDGET_H
