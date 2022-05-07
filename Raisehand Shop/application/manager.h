#ifndef MANAGER_H
#define MANAGER_H

#include "singleton/singleton.h"
#include <QUrl>

class Manager : public Singleton<Manager>
{

public:
    explicit Manager(QObject *parent = nullptr);
    QString name;

signals:

public:
    QString getCurrentEnv() const;
    QUrl getCurrentHostUrl() const;

private:
    QString env;
    QUrl *hostUrl;

};

#endif // MANAGER_H
