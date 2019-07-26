#include "detector.h"

extern "C" Mat image_to_mat(image im);
extern "C" image mat_to_image(Mat m);
extern char **getNames(char *datacfg);

Detector::Detector()
{
    //darknet 함수에 필요한 변수들 초기화
//    char *cfg = "yolov3-tiny-carbike.cfg";
//    char *weights = "yolov3-tiny-carbike.weights";

    char *cfg = "yolov3.cfg";
    char *weights = "yolov3.weights";

    m_net = load_network(cfg, weights, 0);
    m_alphabet = load_alphabet();
    set_batch_network(m_net, 1);

    m_layer = m_net->layers[m_net->n-2]; //gpu
//    m_layer = m_net->layers[m_net->n-1]; //cpu
//    m_layer = m_net->layers[m_net->n]; //tiny car bike

    m_names = getNames("coco.data");
    //darknet 함수에 필요한 변수들 초기화 끝.
}

Detector::~Detector()
{
    free_network(m_net);
    free_image(**m_alphabet);
}

void Detector::setListWidget(QListWidget *widget)
{
    m_listWidget = widget;
}

void Detector::setLiveImageLabel(QLabel *liveImageLabel)
{
    m_liveImageLabel = liveImageLabel;
}

void Detector::setImageLabel(QLabel *imageLabel)
{
    m_imageLabel = imageLabel;
}

void Detector::setDetector_mode(const QString &detector_mode)
{
    m_detector_mode = detector_mode;
}

void Detector::setProcess_stream_url(const QString &process_stream_url)
{
    m_process_stream_url = process_stream_url;
}

void Detector::setIs_stop_process(bool is_stop_process)
{
    m_is_stop_process = is_stop_process;
}

void Detector::run()
{
    StartProcess();
}

/**
 * @brief Detector::FolderWatch
 *  폴더를 직접 감시해서 처리하는 오리지널 방식 지금은 리스트를 읽는 방식을 사용중.(폴더를 읽어서 리스트에 포함시키는 타이머 따로 동작중)
 */
void Detector::FolderWatch()
{
    QDir directory("");
    QDir processedDir("Processed/");
    directory.mkdir("Processed");
    directory.mkdir("Images");
    directory.setPath("Images/");

    QFileInfoList file_infolist = directory.entryInfoList();

    foreach(QFileInfo info, file_infolist){ //
//        m_liveImageLabel->clear();
//        m_imageLabel->clear();
        if(info.isFile()){
            m_status = "검출중....";
//            emit sigDetectorStatus(m_status);
            QString local_filePath = QDir::cleanPath(QString::fromLocal8Bit(info.absoluteFilePath().toLocal8Bit().data()));
            QString extension = info.suffix();
            QFile file(local_filePath);
            extension = extension.toUpper();

            if(extension == QString::fromLocal8Bit("BMP") || extension == QString::fromLocal8Bit("JPG") ||
                    extension == QString::fromLocal8Bit("JPEG") || extension == QString::fromLocal8Bit("PNG")){

                cv::Mat frame_mat = cv::imread(local_filePath.toLocal8Bit().data());

                if(!frame_mat.empty()){
                    QPixmap livePixmap = QPixmap::fromImage(mat8ToImage(frame_mat));

                    frame_mat = TestDetector(m_names,frame_mat,0.25,0.5,nullptr); //디텍션
                    QPixmap detectionPixmap = QPixmap::fromImage(mat8ToImage(frame_mat));
                    m_liveImageLabel->setPixmap(livePixmap.scaled(m_liveImageLabel->width(),m_liveImageLabel->height(),Qt::KeepAspectRatio));
                    m_imageLabel->setPixmap(detectionPixmap.scaled(m_imageLabel->width(),m_imageLabel->height(),Qt::KeepAspectRatio));
                }

                file.rename(processedDir.path()+"/"+info.fileName());// 검출끝난 파일은 processed 폴더로 이동
                if(info.isFile())QFile::remove(local_filePath); // 파일명이 동일하거나 다른 이유로 이동이 안됐을 경우 삭제
            }
            else if(extension == QString::fromLocal8Bit("AVI") || extension == QString::fromLocal8Bit("MP4") ||
                     extension == QString::fromLocal8Bit("MPEG")){

                if(m_opencv_capture.open(local_filePath.toLocal8Bit().data())){
                    cv::Mat frame_mat;

                    while ( m_opencv_capture.isOpened()){
                        m_opencv_capture >> frame_mat;
                        if(frame_mat.empty()) break;
                        QPixmap livePixmap = QPixmap::fromImage(mat8ToImage(frame_mat));
                       frame_mat = TestDetector(m_names,frame_mat,0.25,0.5,nullptr); //디텍션
                        QPixmap detectionPixmap = QPixmap::fromImage(mat8ToImage(frame_mat));
                        m_liveImageLabel->setPixmap(livePixmap.scaled(m_liveImageLabel->width(),m_liveImageLabel->height(),Qt::KeepAspectRatio));
                        m_imageLabel->setPixmap(detectionPixmap.scaled(m_imageLabel->width(),m_imageLabel->height(),Qt::KeepAspectRatio));
                    }

                    m_opencv_capture.release();
                }

                file.rename(processedDir.path()+"/"+info.fileName());// 검출끝난 파일은 processed 폴더로 이동
                if(info.isFile())QFile::remove(local_filePath);//파일명이 동일하거나 다른 이유로 이동이 안됐을 경우 삭제
            }

            QThread::msleep(30);
        }
    }
    m_status="대기중....";
    //    emit sigDetectorStatus(m_status);
}
/**
 * @brief Detector::FileProcess
 *  대기리스트의 첫 파일을 처리하는 함수
 */
void Detector::FileProcess()
{
    QDir directory("");
    QDir processed_dir("Processed/");
    directory.mkdir("Processed");
    directory.mkdir("Images");
    directory.setPath("Images/");

    if(m_listWidget->count()>0){
            QFile file(m_listWidget->item(0)->data(1).toString());
            QFileInfo info = file;

            QString extension = info.suffix();
            extension = extension.toUpper();

            if(extension == QString::fromLocal8Bit("BMP") || extension == QString::fromLocal8Bit("JPG") ||
                    extension == QString::fromLocal8Bit("JPEG") || extension == QString::fromLocal8Bit("PNG")){

                cv::Mat frame_mat = cv::imread(m_listWidget->item(0)->data(1).toString().toStdString());

                if(!frame_mat.empty()){
                    QPixmap livePixmap = QPixmap::fromImage(mat8ToImage(frame_mat));

                    frame_mat = TestDetector(m_names,frame_mat,0.25,0.5,nullptr); //디텍션
                    QPixmap detectionPixmap = QPixmap::fromImage(mat8ToImage(frame_mat));
                    m_liveImageLabel->setPixmap(livePixmap.scaled(m_liveImageLabel->width(),m_liveImageLabel->height(),Qt::KeepAspectRatio));
                    m_imageLabel->setPixmap(detectionPixmap.scaled(m_imageLabel->width(),m_imageLabel->height(),Qt::KeepAspectRatio));
                }

                file.rename(processed_dir.path()+"/"+info.fileName());// 검출끝난 파일은 processed 폴더로 이동
                if(info.isFile())QFile::remove(m_listWidget->item(0)->data(1).toString()); // 파일명이 동일하거나 다른 이유로 이동이 안됐을 경우 삭제
            }
            else if(extension == QString::fromLocal8Bit("AVI") || extension == QString::fromLocal8Bit("MP4") ||
                     extension == QString::fromLocal8Bit("MPEG")){

                if(m_opencv_capture.open(m_listWidget->item(0)->data(1).toString().toStdString())){
                    cv::Mat frame_mat;

                    while ( m_opencv_capture.isOpened()){
                        m_opencv_capture >> frame_mat;
                        if(frame_mat.empty()) break;
                        QPixmap livePixmap = QPixmap::fromImage(mat8ToImage(frame_mat));
                       frame_mat = TestDetector(m_names,frame_mat,0.25,0.5,nullptr); //디텍션
                        QPixmap detectionPixmap = QPixmap::fromImage(mat8ToImage(frame_mat));
                        m_liveImageLabel->setPixmap(livePixmap.scaled(m_liveImageLabel->width(),m_liveImageLabel->height(),Qt::KeepAspectRatio));
                        m_imageLabel->setPixmap(detectionPixmap.scaled(m_imageLabel->width(),m_imageLabel->height(),Qt::KeepAspectRatio));
                    }

                    m_opencv_capture.release();
                }

                file.rename(processed_dir.path()+"/"+info.fileName());// 검출끝난 파일은 processed 폴더로 이동
                if(info.isFile())QFile::remove(m_listWidget->item(0)->data(1).toString());//파일명이 동일하거나 다른 이유로 이동이 안됐을 경우 삭제
            }

            QThread::msleep(30);
    }
}

void Detector::StreamProcess()
{
    cv::Mat frame_mat;
    bool is_stream_open = false;
    is_stream_open = m_opencv_capture.open(m_process_stream_url.toStdString());

    if(!is_stream_open){
        ReconnectProcess();
    }
    else{
        int wait_lock = 10; // SKIP 10 FRAME4
        while ( m_opencv_capture.isOpened())
        {
            if(m_is_stop_process) break;
            //if(m_ivm_settings.m_camera_reconnect_interval_frame > 108000) break;
            bool is_read = m_opencv_capture.read(frame_mat);
            //m_opencv_capture >> frame_mat;
            //            if(!is_read) break;
            //            if(frame_mat.empty()) break;

            QPixmap livePixmap = QPixmap::fromImage(mat8ToImage(frame_mat));
            frame_mat = TestDetector(m_names,frame_mat,0.25,0.5,nullptr); //디텍션
            QPixmap detectionPixmap = QPixmap::fromImage(mat8ToImage(frame_mat));
            m_liveImageLabel->setPixmap(livePixmap.scaled(m_liveImageLabel->width(),m_liveImageLabel->height(),Qt::KeepAspectRatio));
            m_imageLabel->setPixmap(detectionPixmap.scaled(m_imageLabel->width(),m_imageLabel->height(),Qt::KeepAspectRatio));

        }
        if(!m_is_stop_process){
            ReconnectProcess();
        }

    }
}

void Detector::StartProcess()
{

    while(1){

        m_is_stop_process = false;
        if(m_detector_mode == "Folder Detect"){
//            qDebug()<<"folder process working";
            FileProcess();
        }
        else if(m_detector_mode == "Stream Detect"){
//            qDebug()<<"stream process working";
            StreamProcess();
        }
    }
}

void Detector::ReconnectProcess()
{
    qDebug() << "reconnection process ...";


    StopProcess();

    QThread::usleep(2000);

    StartProcess();
}

void Detector::StopProcess()
{
    report_check_time.restart();
    emit SigSendLog("Stop process",report_check_time);

    m_is_stop_process = true;

    if(m_detector_mode == "Stream Detect"){
        if(m_opencv_capture.isOpened()){
            m_opencv_capture.release();
        }
    }
}

/**
 * @brief Detector::test_detector 기존 다크넷을 Mat 으로 반환하도록 변경하고 현재 리눅스 환경에 돌아가게 하기위해 변경한 함수. 방식은 건들지않음.
 * @param names 검출이름
 * @param img 원본이미지
 * @param thresh
 * @param hier_thresh
 * @param outfile
 * @return 결과이미지
 */
Mat Detector::TestDetector(char **names, Mat img, float thresh, float hier_thresh, char *outfile)
{
    srand(2222222);
    double time;
    char buff[256];
    char *input = buff;
    float nms=.45;
    image im;
    image sized;

    im = mat_to_image(img);
    sized = letterbox_image(im, m_net->w, m_net->h);

//    for (int i=0;i<m_net->n;i++) {

//        qDebug()<<"net n"<<":"<<m_net->layers[m_net->n-1].classes;

//    }
    float *X = sized.data;
    time=what_time_is_it_now();
    network_predict(m_net, X);
    printf("%s: Predicted in %f seconds.\n", input, what_time_is_it_now()-time);
    int nboxes = 0;
    detection *dets = get_network_boxes(m_net, im.w, im.h, thresh, hier_thresh, 0, 1, &nboxes);

    //printf("%d\n", nboxes);
    //if (nms) do_nms_obj(boxes, probs, l.w*l.h*l.n, l.classes, nms);
    if (nms) do_nms_sort(dets, nboxes, m_layer.classes, nms);
    draw_detections(im, dets, nboxes, thresh, names, m_alphabet, m_layer.classes);
    free_detections(dets, nboxes);

    Mat m_mat = image_to_mat(im);
    free_image(im);
    free_image(sized);

    return m_mat;
}
