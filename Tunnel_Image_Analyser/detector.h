#ifndef DETECTOR_H
#define DETECTOR_H

#include <opencv2/opencv.hpp>
#include <darknet.h>
#include <opencvhelper.h>
#include <filelistitem.h>

#include <QListWidget>
#include <QTemporaryFile>
#include <QMutex>
#include <vector>

#include <QThread>
#include <QDir>
#include <QLabel>
#include <QDebug>
#include <QTime>

using namespace std;
using namespace cv;

class Detector : public QThread
{
    Q_OBJECT
public:
    Detector();
    ~Detector();

    void setListWidget(QListWidget *value);
    void setLiveImageLabel(QLabel *liveImageLabel);
    void setImageLabel(QLabel *imageLabel);

    void setDetector_mode(const QString &detector_mode);
    void setProcess_stream_url(const QString &process_stream_url);
    void setIs_stop_process(bool is_stop_process);

    void StartProcess();
    void StopProcess();

private:
    QLabel *m_imageLabel; // 메인 윈도우 이미지출력 레이블 포인터
    QLabel *m_liveImageLabel;
    QString m_status = "대기중";
    QString m_detector_mode = "Folder Detect";
    QString m_process_stream_url = "";
    /**
     * @brief m_is_stop_process 스트림을 중간에 끊기위한 bool
     */
    bool m_is_stop_process=false;

    /**
     * @brief report_check_time 로그 타임스탬프
     */
    QTime report_check_time;
    QMap<QString, QTime> report_data;

    VideoCapture m_opencv_capture; // OpenCV 영상 연결 클래스
    QListWidget *m_listWidget = nullptr;

    //darknet 용 변수들 메모리 누수를 막기 위함
    image **m_alphabet;
    network *m_net;
    layer m_layer;
    char **m_names;
    //darknet 용 변수들 끝

    void run();
    void FolderWatch();
    void FileProcess();
    void StreamProcess();
    void ReconnectProcess();

    Mat TestDetector(char **names, Mat img, float thresh, float hier_thresh, char *outfile);
signals:
    void SigSendLog(QString event,QTime time_stamp);
};

#endif // DETECTOR_H
