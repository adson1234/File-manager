#include "mainwindow.h"
#include "copyworker.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    if (a.arguments().count() > 1) {
        w.goTo(a.arguments().at(1));
    }
    w.show();


    return a.exec();
}
