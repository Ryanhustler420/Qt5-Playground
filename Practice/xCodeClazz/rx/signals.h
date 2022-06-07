#ifndef SIGNALS_H
#define SIGNALS_H

#include "singleton/singleton_obj.h"
#include "utility/jsonhelper.h"
#include <functional>
#include <QObject>

class Signals : public OSingleton<Signals>
{
    Q_OBJECT
public:
    explicit Signals(QWidget *parent = nullptr);

    // application
signals:
    void applicationLoading(bool b);
    void internetStatusRefreshed(bool b);
public slots:
    void onApplicationLoading(std::function<void (bool b)> callback);
    void onInternetStatusRefresh(std::function<void (bool b)> callback);

    // login
signals:
    void googleOAuthCodeReceive(QString code);
public slots:
    void onGoogleOAuthCodeReceive(std::function<void(QString code)> callback);

    // course
signals:
    void deleteCourse(QJsonObject o);
public slots:
    void onCourseDeleted(std::function<void(QJsonObject o)> callback);

};

#endif // SIGNALS_H
