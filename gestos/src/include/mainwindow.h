#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/video/background_segm.hpp>
#include <MyBGSubtractorColor.hpp>
#include <HandGesture.hpp>
#include <stdio.h>
#include <string>
#include <iostream>
#include <QDebug>
#include <QMessageBox>
#include <QTimer>

namespace Ui {
class MainWindow;
}

using namespace cv;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:

    void on_iniciarCamara_clicked();

    void on_reconocerMano_clicked();

    void on_capturarMano_clicked();

    void on_salir_clicked();
    void reconocimiento();

private:
    void limpiar();

    Ui::MainWindow *ui;
    Mat frame_, bgmask_, out_frame_;
    VideoCapture *cap_;
    bool camaraIsOpen_;
    bool manoCapturada_;
    bool isReconociendo_;
    bool isCapturando_;
    bool  execHilo_;
    MyBGSubtractorColor *cuadrados_;
    QTimer * timerReconocimiento_;

};

#endif // MAINWINDOW_H
