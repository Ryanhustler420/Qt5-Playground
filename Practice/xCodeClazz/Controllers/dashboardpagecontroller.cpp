#include "controllers/dashboardpagecontroller.h"

DashboardPageController::DashboardPageController(QObject *parent) : QObject(parent)
{

}

void DashboardPageController::openCountState(QString name, QString count)
{
    qInfo() << name << count;
}

void DashboardPageController::logout()
{
    xdb.deleteLoginDetails();
    emit logedout();
}

void DashboardPageController::loadUserData()
{
    emit loadedUserData(xdb.getLoginDetails());
}
