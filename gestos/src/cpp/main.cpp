#include <QCoreApplication>
#include <QApplication>
#include <mainwindow.h>
using namespace std;
using namespace cv;



int main(int argc, char** argv)
{
    QCoreApplication::setApplicationName("Grupo Maquinas");
    QCoreApplication::setOrganizationDomain("SIPC: Reconocimiento Gestos");
    QCoreApplication::setOrganizationName("SIPC");

    QApplication a(argc, argv);
    MainWindow w;


    w.setWindowIcon(QIcon(":/Recursos/Images/RMpixel ico 64x64.png"));
    w.setWindowTitle("SIPC: Reconocimiento Gestos");
    w.show();


 return a.exec();
}

