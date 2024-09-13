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
    static const QString BASE_URL;
    void setHeader(const QByteArray &headerName, const QByteArray &value);
    void setJWTToken(const QString &token);
    void setRequestUrl(const QString &url);
    void addRequestParameterInJson(const QString &key, const QJsonValue &value);
    void sendPostRequest(const QString &url, QMap<QString, QJsonValue> params, const QString &token);
    void sendGetRequest(const QString &url, QMap<QString, QJsonValue> params, const QString &token);
    void sendGetRequest(const QString &url, const QString &token);
    void sendGetRequest(const QString &url);
    void sendGetRequest();
    void sendPostRequest(const QString &url, const QString &token);
    void sendPostRequest(const QString &url);
    void sendPostRequest(const QString &url, QMap<QString, QVariant> params);
    void setRequestJson(const QJsonObject &json);
    void sendPostRequest();
    void sendPostRequest(const QJsonObject &json);
    void sendPostRequest(const QString &url, const QJsonObject &json);
    QJsonObject getResponseByJson();

    QNetworkReply *getReply() const;

public:
    static const int TOKEN_EXPIRED = 401;
    static const int SUCCESS = 1;
    static const int FAILED = 0;
    

private:
    QJsonObject requestJson;
    QJsonDocument requestDoc;
    QNetworkAccessManager *manager;
    QNetworkRequest request;
    QNetworkReply *reply;
};


#endif//QCLOUDOBJ_QHTTPREQUEST_H
