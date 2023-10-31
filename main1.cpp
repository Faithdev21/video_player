#include "mainwindow.h"
#include <QApplication>
#define MAINWINDOW_H

#include <gst/gst.h>
#include <QMainWindow>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    gst_init(&argc, &argv);
    MainWindow w;
    w.show();
    return a.exec();
}
