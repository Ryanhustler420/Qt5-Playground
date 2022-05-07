#ifndef BOGUSCLASS_H
#define BOGUSCLASS_H

#include <QObject>
#include "reactive.h"

class BogusClass : public QObject
{
    Q_OBJECT
public:
    explicit BogusClass(QObject *parent = nullptr);

    void emitt();

signals:

};

#endif // BOGUSCLASS_H
