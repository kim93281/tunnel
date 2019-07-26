/********************************************************************************
** Form generated from reading UI file 'filelistitem.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILELISTITEM_H
#define UI_FILELISTITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FileListItem
{
public:
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *thumbnailLabel;
    QLabel *fileNameLabel;

    void setupUi(QWidget *FileListItem)
    {
        if (FileListItem->objectName().isEmpty())
            FileListItem->setObjectName(QString::fromUtf8("FileListItem"));
        FileListItem->resize(443, 79);
        horizontalLayout_2 = new QHBoxLayout(FileListItem);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 5, 5, 5);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        thumbnailLabel = new QLabel(FileListItem);
        thumbnailLabel->setObjectName(QString::fromUtf8("thumbnailLabel"));
        thumbnailLabel->setMinimumSize(QSize(80, 45));
        thumbnailLabel->setMaximumSize(QSize(80, 45));
        thumbnailLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(thumbnailLabel);

        fileNameLabel = new QLabel(FileListItem);
        fileNameLabel->setObjectName(QString::fromUtf8("fileNameLabel"));

        horizontalLayout->addWidget(fileNameLabel);


        horizontalLayout_2->addLayout(horizontalLayout);


        retranslateUi(FileListItem);

        QMetaObject::connectSlotsByName(FileListItem);
    } // setupUi

    void retranslateUi(QWidget *FileListItem)
    {
        FileListItem->setWindowTitle(QApplication::translate("FileListItem", "Form", nullptr));
        thumbnailLabel->setText(QString());
        fileNameLabel->setText(QApplication::translate("FileListItem", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FileListItem: public Ui_FileListItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILELISTITEM_H
