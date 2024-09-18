/********************************************************************************
** Form generated from reading UI file 'fileinfodialog.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILEINFODIALOG_H
#define UI_FILEINFODIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FileInfoDialog
{
public:
    QGridLayout *gridLayout;
    QLabel *labFileShareStatus;
    QLabel *labFileName;
    QLabel *label_7;
    QLabel *label_3;
    QLabel *label;
    QLabel *labFileType;
    QLabel *labFileDownloadTilme;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *labFileDownloadURL;
    QLabel *labFIlePV;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *labFileSize;

    void setupUi(QWidget *FileInfoDialog)
    {
        if (FileInfoDialog->objectName().isEmpty())
            FileInfoDialog->setObjectName(QString::fromUtf8("FileInfoDialog"));
        FileInfoDialog->resize(490, 333);
        gridLayout = new QGridLayout(FileInfoDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        labFileShareStatus = new QLabel(FileInfoDialog);
        labFileShareStatus->setObjectName(QString::fromUtf8("labFileShareStatus"));

        gridLayout->addWidget(labFileShareStatus, 5, 1, 1, 1);

        labFileName = new QLabel(FileInfoDialog);
        labFileName->setObjectName(QString::fromUtf8("labFileName"));

        gridLayout->addWidget(labFileName, 0, 1, 1, 1);

        label_7 = new QLabel(FileInfoDialog);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 6, 0, 1, 1);

        label_3 = new QLabel(FileInfoDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        label = new QLabel(FileInfoDialog);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        labFileType = new QLabel(FileInfoDialog);
        labFileType->setObjectName(QString::fromUtf8("labFileType"));

        gridLayout->addWidget(labFileType, 2, 1, 1, 1);

        labFileDownloadTilme = new QLabel(FileInfoDialog);
        labFileDownloadTilme->setObjectName(QString::fromUtf8("labFileDownloadTilme"));

        gridLayout->addWidget(labFileDownloadTilme, 3, 1, 1, 1);

        label_5 = new QLabel(FileInfoDialog);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        label_6 = new QLabel(FileInfoDialog);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 5, 0, 1, 1);

        labFileDownloadURL = new QLabel(FileInfoDialog);
        labFileDownloadURL->setObjectName(QString::fromUtf8("labFileDownloadURL"));

        gridLayout->addWidget(labFileDownloadURL, 6, 1, 1, 1);

        labFIlePV = new QLabel(FileInfoDialog);
        labFIlePV->setObjectName(QString::fromUtf8("labFIlePV"));

        gridLayout->addWidget(labFIlePV, 4, 1, 1, 1);

        label_2 = new QLabel(FileInfoDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label_4 = new QLabel(FileInfoDialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        labFileSize = new QLabel(FileInfoDialog);
        labFileSize->setObjectName(QString::fromUtf8("labFileSize"));

        gridLayout->addWidget(labFileSize, 1, 1, 1, 1);


        retranslateUi(FileInfoDialog);

        QMetaObject::connectSlotsByName(FileInfoDialog);
    } // setupUi

    void retranslateUi(QWidget *FileInfoDialog)
    {
        FileInfoDialog->setWindowTitle(QCoreApplication::translate("FileInfoDialog", "FileInfoDialog", nullptr));
        labFileShareStatus->setText(QString());
        labFileName->setText(QString());
        label_7->setText(QCoreApplication::translate("FileInfoDialog", "\344\270\213\350\275\275\345\234\260\345\235\200\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("FileInfoDialog", "\346\226\207\344\273\266\347\261\273\345\236\213\357\274\232", nullptr));
        label->setText(QCoreApplication::translate("FileInfoDialog", "\346\226\207\344\273\266\345\220\215\357\274\232", nullptr));
        labFileType->setText(QString());
        labFileDownloadTilme->setText(QString());
        label_5->setText(QCoreApplication::translate("FileInfoDialog", "\344\270\213\350\275\275\351\207\217\357\274\232", nullptr));
        label_6->setText(QCoreApplication::translate("FileInfoDialog", "\345\210\206\344\272\253\347\212\266\346\200\201\357\274\232", nullptr));
        labFileDownloadURL->setText(QString());
        labFIlePV->setText(QString());
        label_2->setText(QCoreApplication::translate("FileInfoDialog", "\346\226\207\344\273\266\345\244\247\345\260\217\357\274\232", nullptr));
        label_4->setText(QCoreApplication::translate("FileInfoDialog", "\345\210\233\345\273\272\346\227\266\351\227\264\357\274\232", nullptr));
        labFileSize->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class FileInfoDialog: public Ui_FileInfoDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILEINFODIALOG_H
