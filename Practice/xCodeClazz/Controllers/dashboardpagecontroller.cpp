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
    apis.uploadImages();

    emit loadedUserData(xdb.getLoginDetails());
}

void DashboardPageController::listViewReachedBottom(QVariant o)
{
    emit listViewReached(o);
    emit Signals::instance().applicationLoading(true);
}

void DashboardPageController::scrollViewReachedBottom(QVariant o)
{
    emit Signals::instance().applicationLoading(true);
    timer.wait_once(5000, [=](){
        emit Signals::instance().applicationLoading(false);
    });
    emit scrollViewReached(o);
}
