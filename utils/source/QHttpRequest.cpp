//
// Created by tensei on 2024/9/7.
//

#include "../header/QHttpRequest.h"
QHttpRequest::QHttpRequest()
    : manager(new QNetworkAccessManager()), reply(nullptr) {
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
}
void QHttpRequest::setRequestUrl(const QString &url) {
    request.setUrl(QUrl(url));
}
void QHttpRequest::setRequestHeader(QNetworkRequest::KnownHeaders header, const QVariant &value) {
    request.setHeader(header, value);
}
QHttpRequest::~QHttpRequest() {
    delete manager;
}
void QHttpRequest::addRequestParameterInJson(const QString &key, const QJsonValue &value) {
    requestJson.insert(key, value);
}
void QHttpRequest::sendPostRequest() {
    requestDoc.setObject(requestJson);
    reply = manager->post(request, requestDoc.toJson());
}
QNetworkReply *QHttpRequest::getReply() const {
    return reply;
}
void QHttpRequest::setRequestJson(const QJsonObject &json) {
    requestJson = json;
}
void QHttpRequest::sendPostRequest(const QJsonObject &json) {
    requestJson = json;
    sendPostRequest();
}
void QHttpRequest::sendPostRequest(const QString &url, const QJsonObject &json) {
    setRequestUrl(url);
    sendPostRequest(json);
}