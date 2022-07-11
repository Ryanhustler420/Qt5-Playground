#ifndef APPLICATION_H
#define APPLICATION_H

#include <QObject>
#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <QQmlContext>

#include "pageonecontroller.h"
#include "pagetwocontroller.h"

class Application : public QObject
{
    Q_OBJECT
public:
    explicit Application(QObject *parent = nullptr);
    void start(QGuiApplication *);
    Q_INVOKABLE void pop();
    Q_INVOKABLE void pageOne();
    Q_INVOKABLE void pageTwo();

signals:
    void poped();
    void pushPageOne();
    void pushPageTwo();

private:
    QQmlApplicationEngine *engine;

};

#endif // APPLICATION_H
