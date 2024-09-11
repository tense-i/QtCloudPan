//
// Created by tensei on 2024/9/9.
//

#ifndef QCLOUDOBJ_MYFILEWIDGET_H
#define QCLOUDOBJ_MYFILEWIDGET_H

#include <QAction>
#include <QMenu>

#include "../../utils/header/FileInfo.h"
#include <QWidget>
class LoginUserInfo;

QT_BEGIN_NAMESPACE
namespace Ui {
    class MyFileWidget;
}
QT_END_NAMESPACE

class MyFileWidget : public QWidget {
    Q_OBJECT

    using FileList = QList<FileInfo *>;

public:
    explicit MyFileWidget(QWidget *parent = nullptr);
    ~MyFileWidget() override;
    void uploadFile();
    void reflushListWidget();

private:
    void initListWidget();
    void addMenu();
    void menuActions();
    void downloadFiles();


private slots:
    void onRightMenu(const QPoint &pos);

    void showInListWidget(FileList &fileList);

private:
    Ui::MyFileWidget *ui;
    enum FileOperation {
        DOWNLOAD_ON_ASC,
        DOWNLOAD_ON_DESC,
        REFRESH,
        DELETE,
        UPLOAD,
        DOWNLOAD,
        SHARE,
        PROPERTY,
        DOWNLOAD_NORMAL
    };
    enum TransformStatus {
        Upload,
        Download,
        Record
    };

    LoginUserInfo *userInfo;
    FileList fileList;// 任务列表
    QStringList fileTypeList;
    int myFilesCount;

    QMenu *menuItem;
    QMenu *menuEmpty;

    QAction *actionAscOnDownload;
    QAction *actionDescOnDownload;
    QAction *actionRefresh;
    QAction *actionDelete;
    QAction *actionUpload;
    QAction *actionDownload;
    QAction *actionShare;
    QAction *actionProperty;

signals:
    void sig_LoginAgain();
    void gotoTransform(TransformStatus status);

public:
    void getMyFileCount();
    void getMyFileList(FileOperation operation);
};


#endif//QCLOUDOBJ_MYFILEWIDGET_H
