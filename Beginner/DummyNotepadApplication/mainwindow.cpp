#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include <QDebug>
#include <QMessageBox>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionQuit_triggered()
{
    statusBar()->showMessage("App is about to quit within 5 seconds");
    QTimer::singleShot(5000, this, SLOT(quitApp()));
}

void MainWindow::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}

void MainWindow::on_actionCut_triggered()
{
    ui->textEdit->cut();
}

void MainWindow::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}

void MainWindow::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}

void MainWindow::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}

void MainWindow::on_actionCheck_For_Update_triggered()
{
    statusBar()->showMessage("Checking for update \u2026", 6000);
}

void MainWindow::on_actionVersion_triggered()
{
    QMessageBox::about(this, "About", "This software is owned by ☺ Raisehand Software Private Limited, All rights reserverd 2018 - 2022");
}

void MainWindow::quitApp()
{
    QApplication::quit();
}
