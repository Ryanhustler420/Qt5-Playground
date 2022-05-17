#include "cppclass.h"

CppClass::CppClass(QObject *parent) : QObject(parent),
    qmlRootObject(nullptr)
{

}

void CppClass::passFromQmlToCpp(QVariantList list /* array */, QVariantMap map /* object */)
{
    qDebug() << "Receiving variant list and map from QML";
    qDebug() << "List :";
    for (int var = 0; var < list.size(); ++var) {
        qDebug() << "List item :" << list.at(var).toString();
    }

    qDebug() << "Map :";
    for (int var = 0; var < map.keys().size(); ++var) {
        qDebug() << "Map item: "<< map[map.keys().at(var)].toString();
    }
}

QVariantList CppClass::getVariantListFromCpp()
{
    QVariantList list;
    list << 123.3 << QColor(Qt::cyan) << "Qt is great" << 10;
    return list;
}

QVariantMap CppClass::getVariantMapFromCpp()
{
    QVariantMap map;
    map.insert("movie", "Game of Thrones");
    map.insert("names", "John Snow");
    map.insert("role", "Main Chracter");
    map.insert("release", QDate(2011, 4, 17));
    return map;
}

void CppClass::setQmlRootObject(QObject *newQmlRootObject)
{
    qmlRootObject = newQmlRootObject;
}

void CppClass::triggerJsCall()
{
    QVariantList list;
    list << 123.3 << QColor(Qt::cyan) << "Qt is great" << 10;

    QVariantMap map;
    map.insert("movie", "Game of Thrones");
    map.insert("names", "John Snow");
    map.insert("role", "Main Chracter");
    map.insert("release", QDate(2011, 4, 17));

    QMetaObject::invokeMethod(qmlRootObject, "arrayObjectFunc", Q_ARG(QVariant, QVariant::fromValue(list)), Q_ARG(QVariant, QVariant::fromValue(map)));
}
