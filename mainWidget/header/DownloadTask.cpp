//
// Created by tensei on 2024/9/9.
//

#include "DownloadTask.h"

DownloadTask *DownloadTask::instance = new DownloadTask();

int DownloadTask::appendDownloadTask(FileInfo *fileInfo, QString filePath, bool isShareTask) {
    return 0;
}
DownloadFileInfo *DownloadTask::takeTask() {
    DownloadFileInfo *temp = nullptr;
    if (downloadTaskList.size() > 0) {
        temp = downloadTaskList.takeFirst();
    }

    return temp;
}
DownloadTask *DownloadTask::getInstance() {
    return instance;
}
bool DownloadTask::isEmpty() {
    return downloadTaskList.isEmpty();
}
void DownloadTask::delDownloadTask() {
    if (downloadTaskList.size() > 0) {
        downloadTaskList.removeFirst();
    }
}
