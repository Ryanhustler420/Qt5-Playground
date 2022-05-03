#ifndef SERIALIZECLASS_H
#define SERIALIZECLASS_H

#include <QDataStream>
#include <QObject>
#include <QDebug>
#include <QFile>
#include <QDir>

#include "models/jocker.h"

class SerializeClass : public QObject
{
    Q_OBJECT
public:
    explicit SerializeClass(QObject *parent = nullptr);

    bool saveFile(Jocker *t, QString path);
    bool loadFile(QString path);

signals:

};

#endif // SERIALIZECLASS_H
