#include <QtGui/QApplication>
#include "./GUI/MainWindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QApplication::setQuitOnLastWindowClosed(false);
    MainWindow w;
    w.show();

    return a.exec();
}
