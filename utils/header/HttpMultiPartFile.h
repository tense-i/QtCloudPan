//
// Created by tensei on 2024/9/18.
//

#ifndef QCLOUDOBJ_HTTPMULTIPARTFILE_H
#define QCLOUDOBJ_HTTPMULTIPARTFILE_H

#include <QFile>
#include <QHttpMultiPart>
#include <QHttpPart>
class HttpMultiPartFile {
public:
    HttpMultiPartFile();
    ~HttpMultiPartFile();

    void partFile(QFile *file);
    void partText();

private:
    QHttpMultiPart *multiPart;
    QHttpPart *httpPart;
    QFile *file;
    QString filePath;
};


#endif//QCLOUDOBJ_HTTPMULTIPARTFILE_H
