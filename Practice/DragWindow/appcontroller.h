#ifndef APPCONTROLLER_H
#define APPCONTROLLER_H

#include <QDebug>
#include <QCursor>
#include <QObject>
#include <QVariant>

class AppController : public QObject
{
    Q_OBJECT
public:
    explicit AppController(QObject *parent = nullptr);
    Q_INVOKABLE QVariant getCursorPos();

};

#endif // APPCONTROLLER_H
