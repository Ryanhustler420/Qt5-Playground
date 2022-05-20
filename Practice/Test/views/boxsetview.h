#ifndef BOXSETVIEW_H
#define BOXSETVIEW_H

#include <QObject>
#include <QQmlContext>
#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "controllers\boxsetcontroller.h"

class BoxSet : public QObject
{
    Q_OBJECT
public:
    explicit BoxSet(QObject *parent = nullptr);
    void init(QGuiApplication *base);

signals:

private:
    QQmlApplicationEngine engine;

};

#endif // BOXSETVIEW_H
