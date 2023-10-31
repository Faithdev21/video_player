#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMainWindow>
#include <QMenu>
#include <QAction>
#include <QDir>
#include <QDesktopServices>
#include <QApplication>
#include <QFileDialog>
#include <QDebug>
#include <gst/gst.h>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->actionOpen, &QAction::triggered, this, &MainWindow::on_openAction_triggered);
    connect(ui->actionSave, &QAction::triggered, this, &MainWindow::on_saveAction_triggered);
    connect(ui->actionSave_as, &QAction::triggered, this, &MainWindow::on_saveAsAction_triggered);
    GError *err = nullptr;
    m_pipeline = gst_parse_launch("videotestsrc  ! videoconvert ! glimagesink name=sink",&err);
    m_sink = gst_bin_get_by_name(GST_BIN(m_pipeline), "sink");
}

void MainWindow::on_openAction_triggered() {
    QString currentDir = QDir::currentPath();
    QDesktopServices::openUrl(QUrl::fromLocalFile(currentDir));
}

void MainWindow::on_saveAction_triggered() {
    QString filePath = QFileDialog::getSaveFileName(this, tr("Save File"), QDir::currentPath());
    if (!filePath.isEmpty()) {
        QFile file(filePath);
        if (file.open(QIODevice::WriteOnly)) {
            QTextStream out(&file);
            out << "Contents of the file to save";
            file.close();
        }
    } else {
        on_saveAsAction_triggered();
    }
}

void MainWindow::on_saveAsAction_triggered() {
    QString filePath = QFileDialog::getSaveFileName(this, tr("Save File"), QDir::currentPath());
    if (!filePath.isEmpty()) {
        QFile file(filePath);
        if (file.open(QIODevice::WriteOnly)) {
            QTextStream out(&file);
            out << "Contents of the file to save";
            file.close();
        }
    }
}

MainWindow::~MainWindow()
{
    gst_object_unref(G_OBJECT(m_sink));
    gst_object_unref(G_OBJECT(m_pipeline));
    delete ui;
}


void MainWindow::showEvent(QShowEvent *event)
{
    auto win_id = ui->widget->winId();
    gst_video_overlay_set_window_handle(GST_VIDEO_OVERLAY(m_sink), win_id);
    //gst_element_set_state(m_pipeline, GST_STATE_PLAYING);
}

void MainWindow::on_pushButton_clicked()
{
    gst_element_set_state(m_pipeline, GST_STATE_PLAYING);
}

