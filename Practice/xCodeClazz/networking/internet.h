#ifndef INTERNET_H
#define INTERNET_H

#include "parents/commonsuperclass.h"

#include "rx/signals.h"
#include "utility/timer.h"
#include "shareable/constants.h"

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QEventLoop>

class Internet : public CommonSuperClass
{
    Q_OBJECT
public:
    explicit Internet(CommonSuperClass *parent = nullptr);

    void check_internet_connection_in_loop();
    void internetAvailable(std::function<void(bool)> response);

    bool getCheck_internet_connection_in_loop_is_running() const;
    void setCheck_internet_connection_in_loop_is_running(bool newCheck_internet_connection_in_loop_is_running);
signals:

private:
    bool check_internet_connection_in_loop_is_running = false;
    int wait_seconds_ms = 10000;
    Timer timer;

};

#endif // INTERNET_H
