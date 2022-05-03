#ifndef COMMONSUPERCLASS_H
#define COMMONSUPERCLASS_H

#include <QMetaClassInfo>
#include <QMetaProperty>
#include <QMetaObject>
#include <QMetaMethod>
#include <QVariant>
#include <QObject>
#include <QDebug>

#define PIE = 3.14;
#define plus(a, b) a + b
#define AUTHOR = "Raisehand Software Private Limited";

class CommonSuperClass : public QObject
{
    Q_OBJECT
    Q_CLASSINFO("Url", "www.raisehand.software")
    Q_CLASSINFO("Author", "Raisehand Software Private Limited")
public:
    explicit CommonSuperClass(QObject *parent = nullptr);
    void listClassInfo(QObject * obj);
    void listProperties(QObject *obj);
    void listMethod(QObject *obj);
    void listChildren(QObject *obj);
    void modifyProperty(QObject *parent, QString name, QVariant value);

signals:

};

#endif // COMMONSUPERCLASS_H
