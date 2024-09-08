//
// Created by tensei on 2024/8/18.
//

#include "../header/DBUtils.h"
#include <QSqlDatabase>
#include <QSqlError>

#include <QSqlQuery>
#include <QSqlRecord>

DBUtils::DBUtils() {
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("qcloudobj");
    db.setUserName("root");
    db.setPassword("1352446");
}
DBUtils::DBUtils(const QString &DBName) {
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName(DBName);
    db.setUserName("root");
    db.setPassword("1352446");
}


DBUtils::~DBUtils() {
    if (db.isOpen()) {
        db.close();
    }
}
bool DBUtils::connect() {
    if (!db.open()) {
        qWarning() << "无法打开数据库:" << db.lastError().text();
        return false;
    }
    return true;
}
void DBUtils::close() {
    db.close();
}

/**
 * @brief
 * @param sql
 * @return
 */
QList<QList<QVariant>> DBUtils::query(const QString &sql) {
    if (!db.isOpen()) {
        this->connect();
    }
    QList<QList<QVariant>> result;
    QSqlQuery query(db);
    if (query.exec(sql)) {
        while (query.next()) {
            QList<QVariant> row;
            for (int i = 0; i < query.record().count(); i++) {
                row.append(query.value(i));
            }
            result.append(row);
        }
    }
    return result;
}
bool DBUtils::update(const QString &sql) {
    QSqlQuery query(db);
    return query.exec(sql);
}
bool DBUtils::insert(const QString &sql) {
    QSqlQuery query(db);
    return query.exec(sql);
}
bool DBUtils::del(const QString &sql) {
    QSqlQuery query(db);
    return query.exec(sql);
}

QString DBUtils::getLastError() {
    return db.lastError().text();
}
/**
 * 获取数据库连接
 * @return
 */
QSqlDatabase DBUtils::getDb(QString DBConnectionName) {
    // 检查是否已经存在一个连接
    if (QSqlDatabase::contains(DBConnectionName)) {
        QSqlDatabase db = QSqlDatabase::database(DBConnectionName);

        // 检查连接是否打开
        if (db.isOpen()) {
            return db;
        } else {
            // 尝试重新打开连接
            if (!db.open()) {
                qWarning() << "重新打开数据库连接失败:" << db.lastError().text();
            }
            return db;
        }
    } else {
        db = QSqlDatabase::addDatabase("QMYSQL");
        db.setHostName("localhost");
        db.setDatabaseName(DBConnectionName);
        db.setUserName("root");
        db.setPassword("1352446");
        // 打开数据库连接
        if (!db.open()) {
            qWarning() << "无法打开数据库:" << db.lastError().text();
        }
        return db;
    }
}