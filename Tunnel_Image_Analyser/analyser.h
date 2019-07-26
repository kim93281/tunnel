#ifndef ANALYSER_H
#define ANALYSER_H

#include <detector.h>

#include <QMainWindow>
#include <QFile>
#include <QTimer>
#include <QDesktopServices>
#include <QCloseEvent>
#include <QMessageBox>
#include <QUrl>

namespace Ui {
class Analyser;
}

class Analyser : public QMainWindow
{
    Q_OBJECT

public:
    explicit Analyser(QWidget *parent = nullptr);
    ~Analyser();

private:
    Ui::Analyser *ui;
    Detector *detector;
    void closeEvent(QCloseEvent *event);
private slots:
    void onDetectorStatus(const QString status);
    /**
     * @brief queueListUpdate 폴더를 추적해서 대기리스트를 갱신 하는 함수. 디텍션에 비해 부담이 적은 함수라고 생각해서 타이머로 집어넣었지만 추후 문제 발생시 쓰레드로 변경
     */
    void QueueListUpdate();
    void on_actionOpenImageFolder_triggered();
    void on_actionOpenProcessedFolder_triggered();
    void on_actionmodeToggle_toggled(bool arg1);

    void UpdateLogList(QString event,QTime time_stamp);
};

#endif // ANALYSER_H
