//
// Created by tensei on 2024/9/18.
//

#include "../header/HttpMultiPartFile.h"
HttpMultiPartFile::HttpMultiPartFile()
    : multiPart(new QHttpMultiPart(QHttpMultiPart::FormDataType)), httpPart(new QHttpPart), file(new QFile) {
}
void HttpMultiPartFile::partFile(QFile *file) {
    httpPart->setHeader(QNetworkRequest::ContentTypeHeader, QVariant("application/octet-stream"));
    httpPart->setHeader(QNetworkRequest::ContentDispositionHeader, QVariant("form-data; name=\"file\"; filename=\"" + file->fileName() + "\""));

    httpPart->setBodyDevice(file);
    multiPart->append(*httpPart);
}
