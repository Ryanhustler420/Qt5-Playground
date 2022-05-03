#ifndef SERIALIZEQOBJECT_H
#define SERIALIZEQOBJECT_H

#include <QDataStream>
#include <QObject>
#include <QDebug>
#include <QFile>

class SerializeQObject : public QObject
{
    Q_OBJECT
public:
    explicit SerializeQObject(QObject *parent = nullptr);

    bool saveFile(QString path);
    bool readFile(QString path);

signals:

};

#endif // SERIALIZEQOBJECT_H
