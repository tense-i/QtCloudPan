//
// Created by tensei on 2024/9/18.
//

#ifndef QCLOUDOBJ_FILEINFODIALOG_H
#define QCLOUDOBJ_FILEINFODIALOG_H

#include "../../utils/header/FileInfo.h"
#include <QDialog>
#include <QWidget>
QT_BEGIN_NAMESPACE
namespace Ui {
    class FileInfoDialog;
}
QT_END_NAMESPACE

class FileInfoDialog : public QDialog {
    Q_OBJECT

public:
    explicit FileInfoDialog(QWidget *parent = nullptr);
    void setFileInfo(FileInfo *fileinfo);
    ~FileInfoDialog() override;

private:
    Ui::FileInfoDialog *ui;
};


#endif//QCLOUDOBJ_FILEINFODIALOG_H
