#include "pageonecontroller.h"

PageOneController::PageOneController(QObject *parent) : QObject(parent)
{
    if (parent) {
        qInfo() << "Loaded" << "PageOneController";
    }
}

PageOneController::~PageOneController()
{
    qInfo() << "~" << this;
}

void PageOneController::schedule()
{
    timer.singleShot(10000, [=](){
       qInfo() << "::PageOneController" << this;
    });
}
