#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QMenuBar>
#include <QDebug>
#include <QStatusBar>
#include <QAction>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Add central widget
    QPushButton * button = new QPushButton("Hello", this);
    setCentralWidget(button);

    // Declare Quit Action
    QAction * quitAction = new QAction("Quit");
    connect(quitAction, &QAction::triggered,[=]() {
        QApplication::quit();
    });

    // Add menus
    QMenu * files = menuBar()->addMenu("File");
    files->addAction(quitAction);

    menuBar()->addMenu("Edit");
    menuBar()->addMenu("View");
    menuBar()->addMenu("Build");
    menuBar()->addMenu("Settings");
    menuBar()->addMenu("Help");

    // Add status bar message
    statusBar()->showMessage("Uploading file...", 6000);
    // statusBar()->showMessage("Uploading file...");
    // statusBar()->clearMessage();

}

MainWindow::~MainWindow()
{
    delete ui;
}

QSize MainWindow::sizeHint() const
{
    return QSize(800, 500);
}

