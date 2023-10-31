#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "mainwindow.h"

#include <gst/gst.h>
#include <QMainWindow>
#include <ui_mainwindow.h>
#include <gst/video/video.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_openAction_triggered();
    void on_saveAction_triggered();
    void on_saveAsAction_triggered();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    GstElement *m_pipeline = nullptr;
    GstElement *m_sink = nullptr;

    // QWidget interface
protected:
    virtual void showEvent(QShowEvent *event) override;
};
#endif // MAINWINDOW_H


