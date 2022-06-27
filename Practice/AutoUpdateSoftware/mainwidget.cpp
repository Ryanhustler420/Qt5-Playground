#include "mainwidget.h"
#include "ui_mainwidget.h"

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWidget)
{
    ui->setupUi(this);
    QString url = "https://raisehand.herokuapp.com/updates.json";

    QSimpleUpdater::getInstance()->setNotifyOnUpdate (url, true);
    QSimpleUpdater::getInstance()->setNotifyOnFinish (url, false);
    QSimpleUpdater::getInstance()->setDownloaderEnabled (url, true);
    QSimpleUpdater::getInstance()->checkForUpdates (url);
}

MainWidget::~MainWidget()
{
    delete ui;
}

