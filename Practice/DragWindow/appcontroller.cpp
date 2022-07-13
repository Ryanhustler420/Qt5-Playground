#include "appcontroller.h"

AppController::AppController(QObject *parent) : QObject(parent)
{
}

QVariant AppController::getCursorPos()
{
    return QVariant(QCursor::pos());
}
