#ifndef SIGNALS_H
#define SIGNALS_H

#include "singleton/singleton_obj.h"
#include <functional>
#include <QObject>

class Signals : public OSingleton<Signals>
{
    Q_OBJECT
public:
    explicit Signals(QWidget *parent = nullptr);

signals:
    void deleteCourse();
    void googleOAuthCodeReceive(QString code);

public slots:
    void onDeleteCourse(std::function<void ()> callback);
    void onGoogleOAuthCodeReceive(std::function<void(QString code)> callback);

};

#endif // SIGNALS_H
