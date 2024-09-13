//
// Created by tensei on 2024/9/9.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MyFileWidget.h" resolved

#include "myfilewidget.h"
#include "../../utils/header/FileInfo.h"
#include "../LoginDialog/header/LoginUserInfo.h"
#include "../utils/header/QHttpRequest.h"
#include "ui_MyFileWidget.h"

#include <QFileDialog>
#include <QGraphicsDropShadowEffect>
#include <QJsonArray>
#include <QMessageBox>


const QString ON_ASC = "asc";
const QString ON_DESC = "desc";
const QString NORMAL = "normal";

MyFileWidget::MyFileWidget(QWidget *parent) : QWidget(parent), ui(new Ui::MyFileWidget) {
    qDebug() << "MyFileWidget";
    ui->setupUi(this);

    // 去除自带的标题栏
    setWindowFlags(Qt::FramelessWindowHint);
    initListWidget();
    addMenu();

    // 设置为多选
    ui->listWidget->setSelectionMode(QAbstractItemView::ExtendedSelection);
}

MyFileWidget::~MyFileWidget() {
    delete ui;
}
void MyFileWidget::initListWidget() {
    userInfo = LoginUserInfo::getInstance();

    ui->listWidget->setViewMode(QListView::IconMode);
    ui->listWidget->setIconSize(QSize(80, 80));
    ui->listWidget->setGridSize(QSize(100, 120));

    // 设置列表的显示模式-自适应(自动调整大小)
    ui->listWidget->setResizeMode(QListView::Adjust);
    // 设置列表的显示模式-静态(不能拖动)
    ui->listWidget->setMovement(QListView::Static);
    ui->listWidget->setContextMenuPolicy(Qt::CustomContextMenu);

    connect(ui->listWidget, &QListWidget::customContextMenuRequested, this, &MyFileWidget::onRightMenu);
    connect(ui->listWidget, &QListWidget::itemClicked, this, [=](QListWidgetItem *item) {
        QString text = item->text();
        if (text == "上传文件") {
            // 上传文件
            //            uploadFile();
        } else if (text == "新建文件夹") {
            // 新建文件夹
            //            createFolder();
        } else if (text == "刷新") {
            // 刷新
            //            refresh();
        } else {
            // 打开文件
            //            openFile(text);
        }
    });
}
void MyFileWidget::onRightMenu(const QPoint &pos) {
    QListWidgetItem *item = ui->listWidget->itemAt(pos);
    if (item == NULL) {
        menuEmpty->exec(QCursor::pos());
    } else {
        if (item->text() == "上传文件") {
            return;
        }
        menuItem->exec(QCursor::pos());
    }
}
void MyFileWidget::addMenu() {
    // 点击item显示的菜单
    menuItem = new QMenu(this);
    actionDownload = new QAction("下载", this);
    actionDelete = new QAction("删除", this);
    actionProperty = new QAction("属性", this);
    actionShare = new QAction("分享", this);
    menuItem->addAction(actionDownload);
    menuItem->addAction(actionDelete);
    menuItem->addAction(actionProperty);
    menuItem->addAction(actionShare);

    // 空白处显示的菜单
    menuEmpty = new QMenu(this);
    actionAscOnDownload = new QAction("按下载量升序", this);
    actionDescOnDownload = new QAction("按下载量降序", this);
    actionRefresh = new QAction("刷新", this);
    actionUpload = new QAction("上传文件", this);
    menuEmpty->addAction(actionAscOnDownload);
    menuEmpty->addAction(actionDescOnDownload);
    menuEmpty->addAction(actionRefresh);
    menuEmpty->addAction(actionUpload);

    // 为菜单添加阴影效果
    auto *shadowEffect = new QGraphicsDropShadowEffect(this);
    shadowEffect->setBlurRadius(10.0);
    shadowEffect->setOffset(2.0, 2.0);
    shadowEffect->setColor(QColor(0, 0, 0, 128));// 设置阴影颜色和透明度
    menuEmpty->setGraphicsEffect(shadowEffect);
    menuItem->setGraphicsEffect(shadowEffect);
    // 绑定菜单的槽函数
    this->menuActions();
}

void MyFileWidget::menuActions() {
    connect(actionDownload, &QAction::triggered, this, [=]() {
        // 下载
        downloadFiles();
    });
    connect(actionDelete, &QAction::triggered, this, [=]() {
        // 删除
    });
    connect(actionProperty, &QAction::triggered, this, [=]() {
        showFileInfo();
    });
    connect(actionShare, &QAction::triggered, this, [=]() {
        // 分享
        //        dealFile(FileOperation::SHARE);
        shareFiles();
    });
    connect(actionAscOnDownload, &QAction::triggered, this, [=]() {
        // 按下载量排序
        getMyFileList(FileOperation::DOWNLOAD_ON_ASC);
    });
    connect(actionDescOnDownload, &QAction::triggered, this, [=]() {
        // 按下载量排序
        getMyFileList(FileOperation::DOWNLOAD_ON_DESC);
    });
    connect(actionRefresh, &QAction::triggered, this, [=]() {
        // 刷新
        getMyFileList(FileOperation::REFRESH);
    });
    connect(actionUpload, &QAction::triggered, this, [=]() {
        // 上传文件
        //        uploadFile();
    });
}
void MyFileWidget::downloadFiles() {
    // 发送
    emit gotoTransform(TransformStatus::Download);

    QListWidgetItem *item = ui->listWidget->currentItem();
    if (item == nullptr) {
        return;
    }
    FileInfo *fileInfo = nullptr;

    int size = fileList.size();// 任务列表长度
    for (int i = 0; i < size; ++i) {
        fileInfo = fileList.at(i);
        if (fileInfo->fileName == item->text()) {
            QString filePath = QFileDialog::getSaveFileName(this, "请选择保存文件路径", fileInfo->fileName);

            if (filePath.isEmpty()) {
                return;
            }
            int res;
            break;
        }
    }
}
void MyFileWidget::getMyFileCount() {
    myFilesCount = 0;
    QHttpRequest *request = new QHttpRequest();
    QString url = "/myfiles/count";
    request->setRequestUrl(url);
    request->addRequestParameterInJson("username", userInfo->getUsername());
    request->addRequestParameterInJson("token", userInfo->getToken());
    request->setHeader("Authorization", userInfo->getToken().toUtf8());
    request->sendPostRequest();
    QNetworkReply *reply = request->getReply();
    connect(reply, &QNetworkReply::finished, this, [=] {
        QByteArray data = reply->readAll();
        QJsonDocument doc = QJsonDocument::fromJson(data);
        QJsonObject obj = doc.object();
        int code = obj.value("code").toInt();

        if (code == 1) {
            myFilesCount = obj.value("count").toInt();
            if (myFilesCount > 0) {
                getMyFileList(FileOperation::DOWNLOAD_ON_ASC);
            }
        } else if (code == 0) {
            // token验证失败
            QMessageBox::critical(this, "账号异常", "请重新登录");
            emit sig_LoginAgain();
            return;
        }

        reply->deleteLater();

        //        emit getMyFileCount();
    });
}
void MyFileWidget::uploadFile() {
    // undo
}
void MyFileWidget::getMyFileList(FileOperation operation) {

    QString strCmd;
    switch (operation) {
        case DOWNLOAD_ON_ASC:
            strCmd = ON_ASC;
            break;
        case DOWNLOAD_ON_DESC:
            strCmd = ON_DESC;
            break;
        case DOWNLOAD_NORMAL:
            strCmd = NORMAL;
            break;
        default:
            strCmd = NORMAL;
            break;
    }

    QHttpRequest *request = new QHttpRequest();
    QString url = QString("/myfiles/list/%1").arg(strCmd);
    request->setRequestUrl(url);
    request->addRequestParameterInJson("username", userInfo->getUsername());
    request->setJWTToken(userInfo->getToken());
    request->sendPostRequest();
    QNetworkReply *reply = request->getReply();
    connect(reply, &QNetworkReply::finished, this, [=] {
        QByteArray data = reply->readAll();
        QJsonDocument doc = QJsonDocument::fromJson(data);
        QJsonObject obj = doc.object();
        int code = obj.value("code").toInt();
        if (!code) {
            // token验证失败
            QMessageBox::critical(this, "账号异常", "请重新登录");
            emit sig_LoginAgain();
            return;
        }
        QJsonArray array = obj.value("list").toArray();
        int size = array.size();
        // 清空原有列表、重新获取数据渲染
        fileList.clear();
        for (int i = 0; i < size; ++i) {
            QJsonObject obj = array.at(i).toObject();
            FileInfo *fileInfo = new FileInfo();

            fileInfo->fileName = obj.value("fileName").toString();
            fileInfo->username = obj.value("username").toString();
            fileInfo->url = obj.value("url").toString();
            fileInfo->size = obj.value("size").toInt();
            fileInfo->filemd5 = obj.value("filemd5").toString();
            fileInfo->shareStatus = obj.value("shareStatus").toInt();
            fileInfo->pv = obj.value("pv").toInt();
            fileInfo->createTime = obj.value("createTime").toString();
            fileInfo->type = obj.value("type").toString();
            fileList.append(fileInfo);
        }
        // 渲染到界面
        showInListWidget(fileList);
        reply->deleteLater();
        //        emit getMyFileList();
    });
}


void MyFileWidget::showInListWidget(MyFileWidget::FileList &fileList) {
    ui->listWidget->clear();// 清除列表
    ui->listWidget->update();
    for (int i = 0; i < fileList.size(); ++i) {
        FileInfo *fileInfo = fileList.at(i);
        QListWidgetItem *item = new QListWidgetItem(ui->listWidget);
        QString iconPath = QString(":/icon/%1.png").arg(fileInfo->type);
        item->setIcon(QIcon(iconPath));
        item->setText(fileInfo->fileName);
        ui->listWidget->addItem(item);
    }

    addUploadItem();
}
void MyFileWidget::reflushListWidget() {
    getMyFileList(FileOperation::REFRESH);
}
void MyFileWidget::addUploadItem() {
    QListWidgetItem *item = new QListWidgetItem(ui->listWidget);
    item->setIcon(QIcon(":/icon/upload.png"));
    item->setText("上传文件");
    ui->listWidget->addItem(item);
}
void MyFileWidget::shareFiles() {
    QListWidgetItem *item = ui->listWidget->currentItem();
    if (item == nullptr) {
        return;
    }
    FileInfo *fileInfo = nullptr;
    int size = fileList.size();
    for (int i = 0; i < size; ++i) {
        fileInfo = fileList.at(i);
        if (fileInfo->fileName == item->text()) {
            break;
        }
    }
    QHttpRequest *request = new QHttpRequest();
    QString url = "/sharefile";
    request->setRequestUrl(url);
    request->addRequestParameterInJson("username", userInfo->getUsername());
    request->addRequestParameterInJson("fileName", fileInfo->fileName);
    request->addRequestParameterInJson("filemd5", fileInfo->filemd5);
    request->setJWTToken(userInfo->getToken());
    request->sendPostRequest();
    QNetworkReply *reply = request->getReply();
    connect(reply, &QNetworkReply::finished, this, [=] {
        QByteArray data = reply->readAll();
        QJsonDocument doc = QJsonDocument::fromJson(data);
        QJsonObject obj = doc.object();
        int code = obj.value("code").toInt();
        if (code == 0) {
            QMessageBox::critical(this, "分享失败", "分享失败");
            return;
        }
        int shareStatus = obj.value("shareStatus").toInt();
        if (shareStatus == ShareFlileStatus::Shared) {
            QMessageBox::information(this, "分享成功", "分享成功");
        } else if (shareStatus == ShareFlileStatus::CancelShare) {
            QMessageBox::critical(this, "分享失败", "分享失败");
        } else if (shareStatus == ShareFlileStatus::SharedByOthers) {
            QMessageBox::information(this, "分享失败", "文件已被分享");
        }
        reply->deleteLater();
    });
}

void MyFileWidget::getShareFiles() {
}

void MyFileWidget::getShareFile(FileInfo *fileInfo) {
    QHttpRequest *request = new QHttpRequest();
    QString url = "/shareFiles";
    request->sendGetRequest();
}
void MyFileWidget::showFileInfo() {
    QListWidgetItem *item = ui->listWidget->currentItem();
    if (item == nullptr) {
        return;
    }
    FileInfo *fileInfo = nullptr;
    int size = fileList.size();
    for (int i = 0; i < size; ++i) {
        fileInfo = fileList.at(i);
        if (fileInfo->fileName == item->text()) {
            break;
        }
    }

    QString info = QString("文件名：%1\n文件大小：%2\n文件类型：%3\n创建时间：%4\n下载量：%5\n分享状态：%6")
                           .arg(fileInfo->fileName)
                           .arg(fileInfo->size)
                           .arg(fileInfo->type)
                           .arg(fileInfo->createTime)
                           .arg(fileInfo->pv)
                           .arg(fileInfo->shareStatus);
    QMessageBox::information(this, "文件信息", info);
}
void MyFileWidget::deleteFiles() {
    QList<QListWidgetItem *> selectedItems = ui->listWidget->selectedItems();
    if (selectedItems.isEmpty()) {
        return;
    }

    QStringList fileNames;
    std::for_each(selectedItems.begin(), selectedItems.end(), [&](QListWidgetItem *item) {
        fileNames.append(item->text());
    });

    QHttpRequest *request = new QHttpRequest();
    QString url = "/deletefiles";
    request->addRequestParameterInJson("username", userInfo->getUsername());
    request->addRequestParameterInJson("fileNames", QJsonArray::fromStringList(fileNames));
    request->sendPostRequest(url, userInfo->getToken());
    QNetworkReply *reply = request->getReply();
    connect(reply, &QNetworkReply::finished, this, [=] {
        QByteArray data = reply->readAll();
        QJsonDocument doc = QJsonDocument::fromJson(data);
        QJsonObject obj = doc.object();
        int code = obj.value("code").toInt();
        if (code == QHttpRequest::FAILED) {
            QMessageBox::critical(this, "删除失败", "请求错误");
            return;
        }
        int deleteStatus = obj.value("deleteStatus").toInt();
        if (deleteStatus == 1) {
            QMessageBox::information(this, "删除成功", "删除成功");
        } else if (deleteStatus == 0) {
            QMessageBox::critical(this, "删除失败", "删除失败");
        }

        reply->deleteLater();
    });
}
void MyFileWidget::deleteFile(FileInfo *fileInfo) {

    QHttpRequest *request = new QHttpRequest();
    QString url = "/deletefile";
    request->setRequestUrl(url);
    request->addRequestParameterInJson("username", userInfo->getUsername());
    request->addRequestParameterInJson("fileName", fileInfo->fileName);
    request->addRequestParameterInJson("filemd5", fileInfo->filemd5);
    request->setJWTToken(userInfo->getToken());
    request->sendPostRequest();
    QNetworkReply *reply = request->getReply();
    connect(reply, &QNetworkReply::finished, this, [=] {
        QByteArray data = reply->readAll();
        QJsonDocument doc = QJsonDocument::fromJson(data);
        QJsonObject obj = doc.object();
        int code = obj.value("code").toInt();
        if (code == 0) {
            QMessageBox::critical(this, "删除失败", "删除失败");
            return;
        }
        int shareStatus = obj.value("shareStatus").toInt();
        if (shareStatus == ShareFlileStatus::Shared) {
            QMessageBox::information(this, "删除成功", "删除成功");
        } else if (shareStatus == ShareFlileStatus::CancelShare) {
            QMessageBox::critical(this, "删除失败", "删除失败");
        } else if (shareStatus == ShareFlileStatus::SharedByOthers) {
            QMessageBox::information(this, "删除失败", "文件已被分享");
        }
        reply->deleteLater();
    });
}
