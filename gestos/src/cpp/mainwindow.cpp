#include "mainwindow.h"
#include "ui_mainwindow.h"
#define POLLING_INTERVAL 10


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    isReconociendo_=false;
    camaraIsOpen_=false;
    manoCapturada_=false;
    isCapturando_=false;
    cap_=NULL;
    cuadrados_=NULL;
    execHilo_=false;

    timerReconocimiento_ = new QTimer(this);
    connect(timerReconocimiento_,SIGNAL(timeout()),this,SLOT(reconocimiento()));


}

MainWindow::~MainWindow()
{


    delete ui;

}

void MainWindow::on_salir_clicked()
{

    delete timerReconocimiento_;
 limpiar();
 qApp->exit();

}

void MainWindow::limpiar()
{


    if (isReconociendo_)
          timerReconocimiento_->stop();


    destroyAllWindows();

    if (cap_ != NULL)
        delete cap_;


    if (cuadrados_ != NULL)
            delete cuadrados_;

    isReconociendo_=false;
    camaraIsOpen_=false;
    manoCapturada_=false;
    cap_=NULL;
    cuadrados_=NULL;
    isCapturando_=false;
    execHilo_=false;
}

void MainWindow::on_iniciarCamara_clicked()
{
    limpiar();

        cap_= new VideoCapture();


    cap_->open(0);

    if (!cap_->isOpened())
    {
            QMessageBox::warning(nullptr,"Atenci贸n",QString("No se puede abrir la c醡ara"));
            camaraIsOpen_=false;
    }

    else
    {
        int cont = 0;
        while (frame_.empty()&& cont < 2000 ) {
                *cap_ >> frame_;
                ++cont;
        }
        if (cont >= 2000)
        {
            QMessageBox::warning(nullptr,"Atenci贸n",QString("No se ha podido leer un frame v醠ido"));
            camaraIsOpen_=false;
         }

        else {
            // creamos el objeto para la substracci髇 de fondo

                        cuadrados_= new MyBGSubtractorColor(*cap_);
                        camaraIsOpen_=true;
                }
    }

}


void MainWindow::on_capturarMano_clicked()
{
    // iniciamos el proceso de obtenci髇 del modelo del fondo
if (!isCapturando_)
 {
    if (!camaraIsOpen_)
            QMessageBox::warning(nullptr,"Atenci贸n",QString("Primero debe de Iniciar la Camara"));
    else if ((camaraIsOpen_) && (!manoCapturada_))
    {
        isCapturando_=true;
        cuadrados_->LearnModel();
        manoCapturada_=true;
        isCapturando_=false;

    } else
        QMessageBox::warning(nullptr,"Atenci贸n",QString("Ya tiene una mano capturada. Pinche Iniciar Camara si quiere otra nueva."));
 }
else
        QMessageBox::warning(nullptr,"Atenci贸n",QString("Ya estas capturando una mano"));

}

void MainWindow::on_reconocerMano_clicked()
{
    if ((manoCapturada_) && (!isReconociendo_))
      {
        isReconociendo_=true;
        // Creamos las ventanas que vamos a usar en la aplicaci髇
        namedWindow("Reconocimiento");
        namedWindow("Fondo");
        timerReconocimiento_->start(POLLING_INTERVAL);
        //QTimer::singleShot(POLLING_INTERVAL,this,&MainWindow::reconocimiento);

       }
    else
              QMessageBox::warning(nullptr,"Atenci贸n",QString("Primero debe Capturar la mano o Ya esta reconociendo una"));
}

void MainWindow::reconocimiento()
{
execHilo_=true;
    *cap_ >> frame_;
    flip(frame_, frame_, 1);

    if (frame_.empty())
         QMessageBox::warning(nullptr,"Atenci贸n",QString("Leido frame vacio"));


    int c = cv::waitKey(40);

    if ((char)c == 'q')
            limpiar();

      else    {
         // obtenemos la m醩cara del fondo con el frame actual

         // CODIGO 2.1
         // limpiar la m醩cara del fondo de ruido
         //...
         cuadrados_->ObtainBGMask(frame_, bgmask_);
         imshow("Fondo", bgmask_);


         // deteccion de las caracter韘ticas de la mano

                 // mostramos el resultado de la sobstracci髇 de fondo

                 // mostramos el resultado del reconocimento de gestos

         imshow("Reconocimiento", frame_);
         //QTimer::singleShot(POLLING_INTERVAL,this,&MainWindow::reconocimiento);

     }
   execHilo_=false;

}

//void MainWindow::iniciar(void)
//{
//Mat frame, bgmask, out_frame;

//VideoCapture cap;
 //cap.open(0);

//if (!cap.isOpened())
//{
//    printf("\nNo se puede abrir la c醡ara\n");
//    return -1;
//}
//    int cont = 0;
//    while (frame.empty()&& cont < 2000 ) {

//            cap >> frame;
//            ++cont;
//    }
//    if (cont >= 2000) {
//            printf("No se ha podido leer un frame v醠ido\n");
//            exit(-1);
//    }


    // creamos el objeto para la substracci髇 de fondo
//MyBGSubtractorColor cuadrados(cap);
// creamos el objeto para el reconocimiento de gestos

// iniciamos el proceso de obtenci髇 del modelo del fondo
//cuadrados.LearnModel();

    // Creamos las ventanas que vamos a usar en la aplicaci髇
//    namedWindow("Reconocimiento");
//    namedWindow("Fondo");

//for (;;)
//{
//    cap >> frame;
//    flip(frame, frame, 1);
//    if (frame.empty())
//    {
//        printf("Le韉o frame vac韔\n");
//        continue;
//    }
////		int c = cvWaitKey(40);
//            int c = cv::waitKey(40);

//    if ((char)c == 'q') break;

//    // obtenemos la m醩cara del fondo con el frame actual

//    // CODIGO 2.1
//    // limpiar la m醩cara del fondo de ruido
//    //...
//    cuadrados.ObtainBGMask(frame, bgmask);
//    imshow("Fondo", bgmask);


//    // deteccion de las caracter韘ticas de la mano

//            // mostramos el resultado de la sobstracci髇 de fondo

//            // mostramos el resultado del reconocimento de gestos

//    imshow("Reconocimiento", frame);


//}

//destroyWindow("Reconocimiento");
//destroyWindow("Fondo");
//destroyWindow("Trackbars");
//cap.release();
//a.exec();
//return 0;
//}



