#ifndef APPLICATION_H
#define APPLICATION_H

#include <iostream>
#include <string>

#include <QObject>
#include <QDebug>
#include <QList>
#include <QUrl>

class Application : public QObject
{
    Q_OBJECT
public:
    explicit Application(QObject *parent = nullptr);

    Q_INVOKABLE void takeFiles(QList<QUrl> files);

signals:
    void correctFileImported(QList<QUrl> files);

};

#endif // APPLICATION_H
