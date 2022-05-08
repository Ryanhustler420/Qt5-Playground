#ifndef MANAGER_H
#define MANAGER_H

#include "singleton/singleton_obj.h"
#include <QUrl>

class Manager : public OSingleton<Manager>
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
