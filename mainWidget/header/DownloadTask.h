//
// Created by tensei on 2024/9/9.
//

#ifndef QCLOUDOBJ_DOWNLOADTASK_H
#define QCLOUDOBJ_DOWNLOADTASK_H

#include "../utils/header/FileInfo.h"
#include <QFile>

class FileDataProgress;
// 下载文件信息类
class DownloadFileInfo {
public:
    QFile *file;
    QString username;
    QString filemd5;
    QString fileName;
    QString filePath;
    bool isShareTask;
    FileDataProgress *fdp;
};
// 上传任务列表类、单例模式
class DownloadTask {
private:
    QList<DownloadFileInfo *> downloadTaskList;
    static DownloadTask *instance;

private:
    DownloadTask() = default;
    ~DownloadTask() = default;

public:
    static DownloadTask *getInstance();

    bool isEmpty();

    DownloadFileInfo *takeTask();

    int appendDownloadTask(FileInfo *fileInfo, QString filePath, bool isShareTask = false);

    void delDownloadTask();

    void clearList();
};


#endif//QCLOUDOBJ_DOWNLOADTASK_H
