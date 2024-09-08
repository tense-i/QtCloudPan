//
// Created by tensei on 2024/9/7.
//

#ifndef QCLOUDOBJ_QHTTPREQUEST_H
#define QCLOUDOBJ_QHTTPREQUEST_H

#include <QJsonDocument>
#include <QJsonObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QUrl>


/**
 * @brief QHttpRequest 封装Qt网络请求
 *
 */
class QHttpRequest {
public:
    QHttpRequest();
    ~QHttpRequest();
    void setRequestUrl(const QString &url);
    void setRequestHeader(QNetworkRequest::KnownHeaders header, const QVariant &value);
    void addRequestParameterInJson(const QString &key, const QJsonValue &value);

    void setRequestJson(const QJsonObject &json);
    void sendPostRequest();
    void sendPostRequest(const QJsonObject &json);
    void sendPostRequest(const QString &url, const QJsonObject &json);

    QNetworkReply *getReply() const;


private:
    QJsonObject requestJson;
    QJsonDocument requestDoc;
    QNetworkAccessManager *manager;
    QNetworkRequest request;
    QNetworkReply *reply;
};


#endif//QCLOUDOBJ_QHTTPREQUEST_H
