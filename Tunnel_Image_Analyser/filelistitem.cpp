#include "filelistitem.h"
#include "ui_filelistitem.h"

FileListItem::FileListItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FileListItem)
{
    ui->setupUi(this);

    QFile File(":/qdarkstyle/style.qss");
    File.open(QFile::ReadOnly);
    QString StyleSheet = QLatin1String(File.readAll());
    this->setStyleSheet(StyleSheet);
}

FileListItem::~FileListItem()
{
    delete ui;
}

void FileListItem::setThumbnail(QFileInfo info)
{
    QString local_filePath = QDir::cleanPath(QString::fromLocal8Bit(info.absoluteFilePath().toLocal8Bit().data()));
    QString extension = info.suffix();
    extension = extension.toUpper();


    if(extension == QString::fromLocal8Bit("BMP") || extension == QString::fromLocal8Bit("JPG") ||
            extension == QString::fromLocal8Bit("JPEG") || extension == QString::fromLocal8Bit("PNG")){

        cv::Mat frame_mat = cv::imread(local_filePath.toLocal8Bit().data());

        if(!frame_mat.empty()){
            QPixmap pixmap = QPixmap::fromImage(mat8ToImage(frame_mat));
            ui->thumbnailLabel->setPixmap(pixmap.scaled(ui->thumbnailLabel->width(),ui->thumbnailLabel->height(),Qt::KeepAspectRatio));
        }
    }
    else if(extension == QString::fromLocal8Bit("AVI") || extension == QString::fromLocal8Bit("MP4") ||
             extension == QString::fromLocal8Bit("MPEG")){
        cv::VideoCapture opencv_capture;

        if(opencv_capture.open(local_filePath.toLocal8Bit().data())){
            cv::Mat frame_mat;

            if(opencv_capture.isOpened()){
                opencv_capture >> frame_mat;
                QPixmap pixmap = QPixmap::fromImage(mat8ToImage(frame_mat));
                ui->thumbnailLabel->setPixmap(pixmap.scaled(ui->thumbnailLabel->width(),ui->thumbnailLabel->height(),Qt::KeepAspectRatio));
            }

            opencv_capture.release();
        }
    }
}

void FileListItem::setfileNameLabel(QFileInfo info)
{
    ui->fileNameLabel->setText(info.fileName());
}
