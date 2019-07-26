/********************************************************************************
** Form generated from reading UI file 'analyser.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ANALYSER_H
#define UI_ANALYSER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Analyser
{
public:
    QAction *actionOpenImageFolder;
    QAction *actionOpenProcessedFolder;
    QAction *actionmodeToggle;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_2;
    QWidget *viewerWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_3;
    QLabel *liveTextLabel;
    QLabel *liveImagelabel;
    QVBoxLayout *verticalLayout_2;
    QLabel *detectionTextlabel;
    QLabel *imageLabel;
    QWidget *queueWidget;
    QVBoxLayout *verticalLayout;
    QLabel *queueTextLabel;
    QListWidget *queueList;
    QTabWidget *tabWidget;
    QWidget *systemTab;
    QHBoxLayout *horizontalLayout_3;
    QWidget *logTab;
    QHBoxLayout *horizontalLayout_4;
    QTableWidget *logTableWidget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Analyser)
    {
        if (Analyser->objectName().isEmpty())
            Analyser->setObjectName(QString::fromUtf8("Analyser"));
        Analyser->resize(1040, 761);
        actionOpenImageFolder = new QAction(Analyser);
        actionOpenImageFolder->setObjectName(QString::fromUtf8("actionOpenImageFolder"));
        actionOpenProcessedFolder = new QAction(Analyser);
        actionOpenProcessedFolder->setObjectName(QString::fromUtf8("actionOpenProcessedFolder"));
        actionmodeToggle = new QAction(Analyser);
        actionmodeToggle->setObjectName(QString::fromUtf8("actionmodeToggle"));
        actionmodeToggle->setCheckable(true);
        centralWidget = new QWidget(Analyser);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout_4 = new QVBoxLayout(centralWidget);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        viewerWidget = new QWidget(centralWidget);
        viewerWidget->setObjectName(QString::fromUtf8("viewerWidget"));
        viewerWidget->setMinimumSize(QSize(640, 400));
        viewerWidget->setSizeIncrement(QSize(0, 0));
        horizontalLayout = new QHBoxLayout(viewerWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        liveTextLabel = new QLabel(viewerWidget);
        liveTextLabel->setObjectName(QString::fromUtf8("liveTextLabel"));
        liveTextLabel->setMaximumSize(QSize(16777215, 20));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        liveTextLabel->setFont(font);
        liveTextLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(liveTextLabel);

        liveImagelabel = new QLabel(viewerWidget);
        liveImagelabel->setObjectName(QString::fromUtf8("liveImagelabel"));
        liveImagelabel->setMinimumSize(QSize(320, 240));
        liveImagelabel->setFrameShape(QFrame::Box);
        liveImagelabel->setFrameShadow(QFrame::Sunken);
        liveImagelabel->setLineWidth(3);
        liveImagelabel->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(liveImagelabel);


        horizontalLayout->addLayout(verticalLayout_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        detectionTextlabel = new QLabel(viewerWidget);
        detectionTextlabel->setObjectName(QString::fromUtf8("detectionTextlabel"));
        detectionTextlabel->setMaximumSize(QSize(16777215, 20));
        detectionTextlabel->setFont(font);
        detectionTextlabel->setTextFormat(Qt::AutoText);
        detectionTextlabel->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(detectionTextlabel);

        imageLabel = new QLabel(viewerWidget);
        imageLabel->setObjectName(QString::fromUtf8("imageLabel"));
        imageLabel->setMinimumSize(QSize(320, 240));
        imageLabel->setFrameShape(QFrame::Box);
        imageLabel->setFrameShadow(QFrame::Sunken);
        imageLabel->setLineWidth(3);
        imageLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(imageLabel);


        horizontalLayout->addLayout(verticalLayout_2);


        horizontalLayout_2->addWidget(viewerWidget);

        queueWidget = new QWidget(centralWidget);
        queueWidget->setObjectName(QString::fromUtf8("queueWidget"));
        queueWidget->setMinimumSize(QSize(300, 0));
        queueWidget->setMaximumSize(QSize(300, 16777215));
        verticalLayout = new QVBoxLayout(queueWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        queueTextLabel = new QLabel(queueWidget);
        queueTextLabel->setObjectName(QString::fromUtf8("queueTextLabel"));
        queueTextLabel->setMinimumSize(QSize(250, 23));
        queueTextLabel->setMaximumSize(QSize(16777215, 23));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        queueTextLabel->setFont(font1);
        queueTextLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(queueTextLabel);

        queueList = new QListWidget(queueWidget);
        queueList->setObjectName(QString::fromUtf8("queueList"));
        queueList->setMinimumSize(QSize(250, 0));
        queueList->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout->addWidget(queueList);


        horizontalLayout_2->addWidget(queueWidget);


        verticalLayout_4->addLayout(horizontalLayout_2);

        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        systemTab = new QWidget();
        systemTab->setObjectName(QString::fromUtf8("systemTab"));
        horizontalLayout_3 = new QHBoxLayout(systemTab);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        tabWidget->addTab(systemTab, QString());
        logTab = new QWidget();
        logTab->setObjectName(QString::fromUtf8("logTab"));
        horizontalLayout_4 = new QHBoxLayout(logTab);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        logTableWidget = new QTableWidget(logTab);
        if (logTableWidget->columnCount() < 2)
            logTableWidget->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        logTableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        logTableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        logTableWidget->setObjectName(QString::fromUtf8("logTableWidget"));

        horizontalLayout_4->addWidget(logTableWidget);

        tabWidget->addTab(logTab, QString());

        verticalLayout_4->addWidget(tabWidget);

        Analyser->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Analyser);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1040, 22));
        Analyser->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Analyser);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        Analyser->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Analyser);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Analyser->setStatusBar(statusBar);

        mainToolBar->addAction(actionOpenImageFolder);
        mainToolBar->addAction(actionOpenProcessedFolder);
        mainToolBar->addAction(actionmodeToggle);

        retranslateUi(Analyser);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Analyser);
    } // setupUi

    void retranslateUi(QMainWindow *Analyser)
    {
        Analyser->setWindowTitle(QApplication::translate("Analyser", "Analyser", nullptr));
        actionOpenImageFolder->setText(QApplication::translate("Analyser", "Images", nullptr));
        actionOpenProcessedFolder->setText(QApplication::translate("Analyser", "Processed", nullptr));
        actionmodeToggle->setText(QApplication::translate("Analyser", "Folder Mode", nullptr));
        liveTextLabel->setText(QApplication::translate("Analyser", "LIVE", nullptr));
        liveImagelabel->setText(QString());
        detectionTextlabel->setText(QApplication::translate("Analyser", "DETECTION", nullptr));
        imageLabel->setText(QString());
        queueTextLabel->setText(QApplication::translate("Analyser", "\353\214\200\352\270\260\354\227\264", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(systemTab), QApplication::translate("Analyser", "\354\213\234\354\212\244\355\205\234", nullptr));
        QTableWidgetItem *___qtablewidgetitem = logTableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("Analyser", "Time", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = logTableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("Analyser", "Log", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(logTab), QApplication::translate("Analyser", "\353\241\234\352\267\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Analyser: public Ui_Analyser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ANALYSER_H
