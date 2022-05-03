#ifndef MANAGER_H
#define MANAGER_H

#include "parents/commonsuperclass.h"
#include "singleton/singleton.h"

#include <QUrl>

class Manager : public CommonSuperClass
{
    static Manager *createInstance();

public:
    explicit Manager(CommonSuperClass *parent = nullptr);

    QString name;
    static Manager* instance();

signals:

public:
    QString getCurrentEnv() const;
    QUrl getCurrentHostUrl() const;

private:
    QString env;
    QUrl *hostUrl;

};

#endif // MANAGER_H
