//
// Created by tensei on 2024/9/7.
//

#include "../header/QHttpRequest.h"

const QString QHttpRequest::BASE_URL = "http://localhost:8080/cloudObj";

QHttpRequest::QHttpRequest()
    : manager(new QNetworkAccessManager()), reply(nullptr) {
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
}

void QHttpRequest::setRequestUrl(const QString &url) {
    request.setUrl(QUrl(QHttpRequest::BASE_URL + url));
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
void QHttpRequest::setHeader(const QByteArray &headerName, const QByteArray &value) {
    request.setRawHeader(headerName, value);
}
void QHttpRequest::setJWTToken(const QString &token) {
    setHeader("Authorization", token.toUtf8());
}
void QHttpRequest::sendGetRequest(const QString &url, QMap<QString, QJsonValue> params, const QString &token) {
    request.setUrl(QUrl(QHttpRequest::BASE_URL + url));
    qDebug() << request.url();

    if (!params.isEmpty()) {
        for (auto it = params.begin(); it != params.end(); ++it) {
            qDebug() << it.key() << it.value();
            addRequestParameterInJson(it.key(), it.value());
        }
    }
    setJWTToken(token);
    sendGetRequest();
}
void QHttpRequest::sendGetRequest() {
    requestDoc.setObject(requestJson);
    QVariant s = requestDoc.toVariant();
    qDebug() << s;
    reply = manager->get(request);
}


void QHttpRequest::sendPostRequest(const QString &url, QMap<QString, QJsonValue> params, const QString &token) {
    request.setUrl(QUrl(QHttpRequest::BASE_URL + url));
    if (!params.isEmpty()) {
        for (auto it = params.begin(); it != params.end(); ++it) {
            addRequestParameterInJson(it.key(), it.value());
        }
    }
    setJWTToken(token);
    sendPostRequest();
}
QJsonObject QHttpRequest::getResponseByJson() {
    QByteArray data = reply->readAll();
    QJsonDocument doc = QJsonDocument::fromJson(data);
    return doc.object();
}
void QHttpRequest::sendGetRequest(const QString &url, const QString &token) {
    request.setUrl(QUrl(QHttpRequest::BASE_URL + url));
    setJWTToken(token);
    sendGetRequest();
}
void QHttpRequest::sendPostRequest(const QString &url, const QString &token) {
    request.setUrl(QUrl(QHttpRequest::BASE_URL + url));
    setJWTToken(token);
    sendPostRequest();
}
void QHttpRequest::sendPostRequestOnMultiPart(QHttpMultiPart *multiPart) {
    reply = manager->post(request, multiPart);
}
