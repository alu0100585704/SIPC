#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <utility>
//#include <pair>
using namespace std;
#define POLLING_INTERVAL 100


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    cap_=NULL;
    cuadrados_=NULL;
    reiniciarHIGHGUI_=false;
    isReconociendo_=false;
    ui->capturarMano->setDisabled(true);
    ui->reconocerMano->setDisabled(true);
    ui->checkBox->setDisabled(true);

}

MainWindow::~MainWindow()
{

    limpiar();
    delete ui;

}

void MainWindow::on_salir_clicked()
{
    if (isReconociendo_)
    {
          reiniciarHIGHGUI_=true;
          cuadrados_->reiniciarHIGHGUI_=true;
    }
  else
    qApp->quit();

}

void MainWindow::limpiar()
{

    ui->iniciarCamara->setDisabled(false);
    ui->capturarMano->setDisabled(true);
    ui->reconocerMano->setDisabled(true);
    ui->salir->setDisabled(false);
    ui->salir->setText("Salir");
    ui->checkBox->setDisabled(true);
    reiniciarHIGHGUI_=false;
    isReconociendo_=false;

    destroyAllWindows();

    if (cap_ != nullptr)
        delete cap_;


    if (cuadrados_ != nullptr)
            delete cuadrados_;

    cap_=nullptr;
    cuadrados_=nullptr;
    ui->iniciarCamara->setText("Reiniciar Camara");
}

void MainWindow::on_iniciarCamara_clicked()
{

        limpiar();

            cap_= new VideoCapture();


        cap_->open(0);

        if (!cap_->isOpened())
                QMessageBox::warning(nullptr,"Atenci√≥n",QString("No se puede abrir la c·mara"));

        else
        {
            int cont = 0;
            while (frame_.empty()&& cont < 2000 ) {
                    *cap_ >> frame_;
                    ++cont;
            }
            if (cont >= 2000)
                QMessageBox::warning(nullptr,"Atenci√≥n",QString("No se ha podido leer un frame v·lido"));

            else {
                // creamos el objeto para la substracciÛn de fondo
                            cuadrados_= new MyBGSubtractorColor(*cap_);
                            ui->capturarMano->setDisabled(false);
                    }
        }



}


void MainWindow::on_capturarMano_clicked()
{
    ui->iniciarCamara->setDisabled(true);
    ui->salir->setDisabled(false);
    ui->salir->setText("Cerrar");
    ui->capturarMano->setDisabled(true);
    isReconociendo_=true;
    bool reiniciar=cuadrados_->LearnModel();

    if (reiniciar)
    {
        isReconociendo_=false;
        reiniciarHIGHGUI_=false;
        cuadrados_->reiniciarHIGHGUI_=false;
        limpiar();
    }
    else {
            ui->iniciarCamara->setDisabled(false);
            ui->reconocerMano->setDisabled(false);
            ui->salir->setDisabled(false);
            ui->salir->setText("Salir");
    }


}

void MainWindow::on_reconocerMano_clicked()
{

    ui->iniciarCamara->setDisabled(true);
    ui->capturarMano->setDisabled(true);
    ui->reconocerMano->setDisabled(true);
    ui->salir->setDisabled(false);
    ui->salir->setText("Cerrar");
    ui->checkBox->setDisabled(false);
    isReconociendo_=true;
int c;
    do {

        *cap_ >> frame_;
        flip(frame_, frame_, 1);

        if (frame_.empty())
             QMessageBox::warning(nullptr,"Atenci√≥n",QString("Leido frame vacio"));


         c = cv::waitKey(40);
        // obtenemos la m·scara del fondo con el frame actual

             // CODIGO 2.1
             // limpiar la m·scara del fondo de ruido
             //...
             cuadrados_->ObtainBGMask(frame_, bgmask_);
             HandGesture mano;
             mano.distancia_mano=cuadrados_->distancia_mano;

             pair<int,int> gesto;
             gesto=mano.FeaturesDetection(bgmask_, frame_);


             // deteccion de las caracterÌsticas de la mano

                     // mostramos el resultado de la sobstracciÛn de fondo

                       // mostramos el resultado del reconocimento de gestos             

            switch (gesto.first)
            {
                case 0:
                putText(frame_,"0 Dedos",Point(30,30),FONT_HERSHEY_COMPLEX,1,Scalar(255),1);
                    break;
                case 1:
                putText(frame_,"1 Dedo",Point(30,30),FONT_HERSHEY_COMPLEX,1,Scalar(255),1);
                    break;
                case 2:
            putText(frame_,"2 Dedos",Point(30,30),FONT_HERSHEY_COMPLEX,1,Scalar(255),1);
                break;
            case 3:
            putText(frame_,"3 Dedos",Point(30,30),FONT_HERSHEY_COMPLEX,1,Scalar(255),1);
                break;
            case 4:
            putText(frame_,"4 Dedos",Point(30,30),FONT_HERSHEY_COMPLEX,1,Scalar(255),1);
                break;
            case 5:
            putText(frame_,"5 Dedos",Point(30,30),FONT_HERSHEY_COMPLEX,1,Scalar(255),1);
                break;

                default:
                    break;
             }
            switch (gesto.second)
            {
                case 0:
                    break;
                case 1:
                    break;
                default:
                    break;
             }

            imshow("Fondo", bgmask_);

             imshow("Reconocimiento", frame_);

    }  while (((char)c != 'q') && (!reiniciarHIGHGUI_));

isReconociendo_=false;
reiniciarHIGHGUI_=false;
limpiar();

}


void MainWindow::closeEvent(QCloseEvent *event)
{
    if (isReconociendo_)
        {
             reiniciarHIGHGUI_=true;
             event->ignore();
        }

    else
       event->accept();
}

void MainWindow::on_checkBox_stateChanged(int arg1)
{

        if (arg1==2)
             cuadrados_->max_samples=cuadrados_->max_samples+1;

        else if (arg1==0)
            cuadrados_->max_samples=cuadrados_->max_samples-1;

}
