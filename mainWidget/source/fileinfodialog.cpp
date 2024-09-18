//
// Created by tensei on 2024/9/18.
//

// You may need to build the project (run Qt uic code generator) to get "ui_FileInfoDialog.h" resolved

#include "fileinfodialog.h"
#include "../../utils/header/QHttpRequest.h"
#include "ui_FileInfoDialog.h"
FileInfoDialog::FileInfoDialog(QWidget *parent) : QDialog(parent), ui(new Ui::FileInfoDialog) {
    ui->setupUi(this);
}

FileInfoDialog::~FileInfoDialog() {
    delete ui;
}
void FileInfoDialog::setFileInfo(FileInfo *fileInfo) {
    qDebug() << "setFileInfo";
    ui->labFileName->setText(fileInfo->fileName);
    ui->labFileDownloadTilme->setText(fileInfo->createTime);
    ui->labFIlePV->setText(QString::number(fileInfo->pv));
    // 字节转为MB
    int64_t size = fileInfo->size;
    if (size < 1024 * 1024) {
        ui->labFileSize->setText(QString::number(size / 1024) + "KB");
    } else {
        ui->labFileSize->setText(QString::number(fileInfo->size / 1024 / 1024) + "MB");
    }
    ui->labFileType->setText(fileInfo->type);
    ui->labFileShareStatus->setText(fileInfo->shareStatus == 1 ? "已分享" : "未分享");
    QString url = QString("<a href=\"%1\">%2</a>").arg(QHttpRequest::BASE_URL).arg(fileInfo->fileName);
    qDebug() << url;
    ui->labFileDownloadURL->setText(url);
}
