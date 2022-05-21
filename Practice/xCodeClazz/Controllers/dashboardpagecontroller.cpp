#include "controllers/dashboardpagecontroller.h"

DashboardPageController::DashboardPageController(QObject *parent) : QObject(parent)
{

}

void DashboardPageController::openCountState(QString name, QString count)
{
    qInfo() << name << count;
}
