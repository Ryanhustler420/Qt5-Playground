#ifndef BOXSET_H
#define BOXSET_H

#include <QObject>
#include <QQmlContext>
#include <QGuiApplication>
#include <QQmlApplicationEngine>

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

#endif // BOXSET_H
