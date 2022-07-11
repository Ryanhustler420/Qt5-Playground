#include "pagetwocontroller.h"

PageTwoController::PageTwoController(QObject *parent) : QObject(parent)
{
    if (parent) {
        qInfo() << "Loaded" << "PageTwoController";
    }
}

PageTwoController::~PageTwoController()
{
    qInfo() << "~" << this;
}

void PageTwoController::schedule()
{
    timer.singleShot(10000, [=](){
       qInfo() << "::PageTwoController" << this;
    });
}

