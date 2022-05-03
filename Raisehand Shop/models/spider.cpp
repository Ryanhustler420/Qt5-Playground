#include "spider.h"

Spider::Spider(QObject *parent) : QObject(parent)
{

}

void Spider::fill()
{
    m_name = "Spider object";
    for (int var = 0; var < 10; ++var) {
        QString num = QString::number(var);
        QString key = "key: " + num;
        QString value = "This is item number: " + num;
        m_map.insert(key, value);
    }
}

QString Spider::name()
{
    return m_name;
}

void Spider::setName(QString value)
{
    m_name = value;
}

QMap<QString, QString> Spider::map()
{
    return m_map;
}

void Spider::setMap(QMap<QString, QString> map)
{
    m_map = map;
}
