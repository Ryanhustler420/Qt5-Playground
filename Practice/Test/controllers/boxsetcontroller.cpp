#include "controllers\boxsetcontroller.h"

BoxSetController::BoxSetController(QObject *parent) : QObject(parent)
{

}

int BoxSetController::get() const
{
    return m_get;
}

void BoxSetController::setGet(int newGet)
{
    qInfo() << newGet;
    if (m_get == newGet)
        return;
    m_get = newGet;
    emit getChanged(newGet);
}

const QString &BoxSetController::json() const
{
    return m_json;
}

void BoxSetController::setJson(const QString &newJson)
{
    if (m_json == newJson)
        return;
    m_json = newJson;
    emit jsonChanged(45, 5);
}
