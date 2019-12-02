#include <QCoreApplication>
#include <QApplication>
#include <mainwindow.h>
using namespace std;
using namespace cv;



int main(int argc, char** argv)
{
    QCoreApplication::setApplicationName("Grupo Maquinas");
    QCoreApplication::setOrganizationDomain("Los mejores");
    QCoreApplication::setOrganizationName("RMPixel");

    QApplication a(argc, argv);
    MainWindow w;


    w.setWindowIcon(QIcon(":/Recursos/Images/RMpixel ico 64x64.png"));
    w.setWindowTitle("Los mejores");
    w.show();

 return a.exec();
}

