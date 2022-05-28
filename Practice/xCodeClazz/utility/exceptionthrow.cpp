#include "utility/exceptionthrow.h"

ExceptionThrow::ExceptionThrow(QObject *parent) : QObject(parent)
{

}

ExceptionThrow::ExceptionThrow(QString msg)
{
    this->msg = msg;
}

const QString &ExceptionThrow::getMsg() const
{
    return msg;
}

void ExceptionThrow::setMsg(const QString &newMsg)
{
    msg = newMsg;
}
