#include "analyser.h"
#include "ui_analyser.h"

Analyser::Analyser(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Analyser)
{
    ui->setupUi(this);

    // 스타일 시트 불러오기
    QFile File(":/qdarkstyle/style.qss");
    File.open(QFile::ReadOnly);
    QString StyleSheet = QLatin1String(File.readAll());
    this->setStyleSheet(StyleSheet);

    detector = new Detector();
    detector->setLiveImageLabel(ui->liveImagelabel);
    detector->setImageLabel(ui->imageLabel);
    detector->setListWidget(ui->queueList);
    detector->setProcess_stream_url("InputRtspPath");
    detector->start();

    connect(detector,SIGNAL(SigSendLog(QString,QTime)),this,SLOT(UpdateLogList(QString, QTime)));

    QTimer *folderWatch = new QTimer(this);
    connect(folderWatch,SIGNAL(timeout()),this,SLOT(QueueListUpdate()));
    folderWatch->start(30);
}

Analyser::~Analyser()
{
    delete ui;
}

void Analyser::closeEvent(QCloseEvent *event)
{
    event->ignore();

    if(QMessageBox::Yes == QMessageBox::question(this,"종료.","종료하시겠습니까?",QMessageBox::No|QMessageBox::Yes)){
        event->accept();
    }
}

void Analyser::onDetectorStatus(const QString status)
{
}

void Analyser::QueueListUpdate()
{
    QDir directory("");
    QDir processedDir("Processed/");
    directory.mkdir("Processed");
    directory.mkdir("Images");
    directory.setPath("Images/");
    QFileInfoList file_infolist = directory.entryInfoList();

    int list_count = ui->queueList->count();
    int file_existence_check[list_count]; // 파일 존재 여부 체크용 : 0 = 존재 하지 않음 1 = 존재 함
    //초기화
    for(int i = 0; i<list_count;i++) file_existence_check[i] = 0;

    foreach(QFileInfo info, file_infolist){
        QString local_filePath = QDir::cleanPath(QString::fromLocal8Bit(info.absoluteFilePath().toLocal8Bit().data()));
        QString extension = info.suffix();
        extension = extension.toUpper();//
        if(extension == QString::fromLocal8Bit("BMP") || extension == QString::fromLocal8Bit("JPG")
                || extension == QString::fromLocal8Bit("JPEG") || extension == QString::fromLocal8Bit("PNG")
                || extension == QString::fromLocal8Bit("AVI") || extension == QString::fromLocal8Bit("MP4")
                || extension == QString::fromLocal8Bit("MPEG")){

            bool duplicate_check = true;
            for(int i = 0;i<ui->queueList->count();i++){ //
                if(info.filePath() == ui->queueList->item(i)->data(1)){  // 중복 여부 체크
                    file_existence_check[i] = 1; //존재 여부 체크
                    if(duplicate_check == true) {duplicate_check = false;
                    }
                }
            }

            // 중복파일이 없다면 리스트에 추가
            if(duplicate_check){
                QListWidgetItem *item = new QListWidgetItem(ui->queueList);
                item->setData(1,info.filePath());
                ui->queueList->addItem (item);
                FileListItem *theItem = new FileListItem;
                theItem->setThumbnail(info);
                theItem->setfileNameLabel(info);
                item->setSizeHint (theItem->sizeHint ());
                ui->queueList->setItemWidget (item, theItem);
            }
        }
    }
    for(int i = list_count-1 ; i >=0 ;i--) if(file_existence_check[i] == 0)
    {
        delete ui->queueList->takeItem(i);  // 존재하지 않은 파일 삭제
    }
}

void Analyser::on_actionOpenImageFolder_triggered()
{
    QDir processedDir("Images/");
    QDesktopServices::openUrl(processedDir.path());
    qDebug()<<"ImageFolder";
}

void Analyser::on_actionOpenProcessedFolder_triggered()
{
    QDir processedDir("Processed/");
    QDesktopServices::openUrl(processedDir.path());
    qDebug()<<"Processed";
}

void Analyser::on_actionmodeToggle_toggled(bool arg1)
{
    if(arg1){
        ui->actionmodeToggle->setText("Stream Mode");
        detector->setDetector_mode("Stream Detect");
        detector->StopProcess();
        ui->queueWidget->hide();
    }
    else{
        ui->actionmodeToggle->setText("Folder Mode");
        detector->setDetector_mode("Folder Detect");
        detector->StopProcess();
        ui->queueWidget->show();
    }
}

void Analyser::UpdateLogList(QString event, QTime time_stamp)
{
    ui->logTableWidget->insertRow(ui->logTableWidget->rowCount());
    ui->logTableWidget->setItem(ui->logTableWidget->rowCount()-1,0,new QTableWidgetItem(time_stamp.toString()));
    ui->logTableWidget->setItem(ui->logTableWidget->rowCount()-1,1,new QTableWidgetItem(event));
}
