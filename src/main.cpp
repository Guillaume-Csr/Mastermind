#include <QApplication>

#include "mainwindow.h"

//#include <QGlobal.h>
#include <QTime>

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    qsrand(QTime::currentTime().msec()); // Initialize qsrand with a seed value

    MainWindow mainWindow;
    mainWindow.setGeometry(200, 200, 550, 820);
    mainWindow.show();

    return app.exec();
}
