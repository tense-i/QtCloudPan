//
// Created by tensei on 2024/9/9.
//

#ifndef QCLOUDOBJ_FILEINFO_H
#define QCLOUDOBJ_FILEINFO_H

#include <QString>

class FileInfo {

public:
    QString username;
    QString filemd5;
    QString createTime;
    QString fileName;
    int shareStatus;
    int pv;// 下载量
    QString url;
    int size;
    QString type;
};

class FileDownload {
public:
    QString filename;
    int pv;
};


#endif//QCLOUDOBJ_FILEINFO_H
