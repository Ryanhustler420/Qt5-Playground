#include "networking/internet.h"

Internet::Internet(CommonSuperClass *parent) : CommonSuperClass(parent)
{

}

void Internet::check_internet_connection_in_loop()
{
    if (getCheck_internet_connection_in_loop_is_running()) {
        timer.wait_once(wait_seconds_ms, [=](){
            internetAvailable([=](bool b){
                emit Signals::instance().internetStatusRefreshed(b);
                check_internet_connection_in_loop();
            });
        });
    }
}

void Internet::internetAvailable(std::function<void (bool)> response)
{
    QNetworkAccessManager *man = new QNetworkAccessManager();
    QNetworkRequest req(QUrl(unsecure_dns_live.toLatin1()));
    QNetworkReply *reply = man->get(req);
    QEventLoop loop;

    connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
    loop.exec();

    if (reply->bytesAvailable()) response(true); else response(false);
}

bool Internet::getCheck_internet_connection_in_loop_is_running() const
{
    return check_internet_connection_in_loop_is_running;
}

void Internet::setCheck_internet_connection_in_loop_is_running(bool newCheck_internet_connection_in_loop_is_running)
{
    check_internet_connection_in_loop_is_running = newCheck_internet_connection_in_loop_is_running;
}
