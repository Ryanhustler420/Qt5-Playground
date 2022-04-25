#include "test.h"

test::test(QObject *parent) : QObject(parent)
{

}

void test::fill()
{
    m_name = "test object";
    for (int var = 0; var < 10; ++var) {
        QString num = QString::number(var);
        QString key = "key: " + num;
        QString value = "This is item number: " + num;
        m_map.insert(key, value);
    }
}

QString test::name()
{
    return m_name;
}

void test::setName(QString value)
{
    m_name = value;
}

QMap<QString, QString> test::map()
{
    return m_map;
}

