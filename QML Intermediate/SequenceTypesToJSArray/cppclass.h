#ifndef CPPCLASS_H
#define CPPCLASS_H

#include <QObject>
#include <QVector>
#include <QDebug>

class CppClass : public QObject
{
    Q_OBJECT
public:
    explicit CppClass(QObject *parent = nullptr);

    Q_INVOKABLE void qmlArrayToCpp(QVector<QString> vactor);
    Q_INVOKABLE QVector<QString> retrieveStrings();

signals:

private:
    QVector<QString> mVector;

};

#endif // CPPCLASS_H
