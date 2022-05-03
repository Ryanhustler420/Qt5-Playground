#include "jocker.h"

Jocker::Jocker(QObject *parent) : QObject(parent)
{

}

void Jocker::fill()
{
    m_name = "Jocker object";
    for (int var = 0; var < 10; ++var) {
        QString num = QString::number(var);
        QString key = "key: " + num;
        QString value = "This is item number: " + num;
        m_map.insert(key, value);
    }
}

QString Jocker::name()
{
    return m_name;
}

void Jocker::setName(QString value)
{
    m_name = value;
}

QMap<QString, QString> Jocker::map()
{
    return m_map;
}
