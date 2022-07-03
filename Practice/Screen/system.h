#ifndef SYSTEM_H
#define SYSTEM_H

#include <QRect>
#include <QObject>
#include <QScreen>
#include <QGuiApplication>

class System : public QObject
{
    Q_OBJECT
public:
    explicit System(QObject *parent = nullptr);

    Q_INVOKABLE QString getScreenSize();

signals:

};

#endif // SYSTEM_H
