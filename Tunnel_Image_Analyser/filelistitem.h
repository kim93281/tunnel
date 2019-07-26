#ifndef FILELISTITEM_H
#define FILELISTITEM_H

#include <opencv2/opencv.hpp>
#include <opencvhelper.h>

#include <QWidget>
#include <QFile>
#include <QDir>

namespace Ui {
class FileListItem;
}

class FileListItem : public QWidget
{
    Q_OBJECT

public:
    explicit FileListItem(QWidget *parent = nullptr);
    ~FileListItem();
    void setThumbnail(QFileInfo info);
    void setfileNameLabel(QFileInfo info);
private:
    Ui::FileListItem *ui;
};

#endif // FILELISTITEM_H
