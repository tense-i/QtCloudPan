//
// Created by tensei on 2024/8/18.
//

#ifndef QCLOUDOBJ_DBUTILS_H
#define QCLOUDOBJ_DBUTILS_H


#include <QSqlDatabase>
/**
 * 数据库工具类、封装MySQL数据库操作
 */
class DBUtils {
private:
    QSqlDatabase db;

public:
    /**
     * 构造函数
     */
    DBUtils();


    DBUtils(const QString &DBConnectionName);
    /**
     * 析构函数
     */
    ~DBUtils();

    /**
     * 连接数据库
     * @return 是否连接成功
     */
    bool connect();

    /**
     * 断开数据库
     */
    void close();

    /**
     * 查询数据库
     * @param sql 查询语句
     * @return 查询结果
     */
    QList<QList<QVariant>> query(const QString &sql);

    /**
     * 更新数据库
     * @param sql 更新语句
     * @return 是否更新成功
     */
    bool update(const QString &sql);

    /**
     * 插入数据库
     * @param sql 插入语句
     * @return 是否插入成功
     */
    bool insert(const QString &sql);

    /**
     * 删除数据库
     * @param sql 删除语句
     * @return 是否删除成功
     */
    bool del(const QString &sql);

    /**
     * 获取数据库连接
     * @return 数据库连接
     */
    QSqlDatabase getDb(QString DBConnectionName);

    /**
     * 获取最后一次错误
     */
    QString getLastError();
};


#endif//QCLOUDOBJ_DBUTILS_H
