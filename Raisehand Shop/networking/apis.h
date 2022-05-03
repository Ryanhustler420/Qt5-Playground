#ifndef APIS_H
#define APIS_H

#include "parents/commonsuperclass.h"
#include "networking/network.h"
#include "networking/routes.h"
#include <functional>

class Apis : public CommonSuperClass
{
public:
    explicit Apis(CommonSuperClass *parent = nullptr);

public:
    void login(QString email, QString password, std::function<void(QByteArray)> response, std::function<void(QByteArray)> error);
    void getMyStockIds(QString s_id, std::function<void(QByteArray)> response, std::function<void(QByteArray)> error);
    void attachHeader(QNetworkRequest &netRequest);

signals:

private:
    Routes routes;
    Network *mNetwork;
    QNetworkAccessManager *mNetMan;

public:
    typedef struct HEADER_KEYS {
        QString raisehand_access_platform_names_array = "raisehand_access_platform_names_array";
        QString raisehand_route_caller_appname = "raisehand_route_caller_appname";
        QString raisehand_server_version = "raisehand_server_version";
        QString raisehand_app_version = "raisehand_app_version";
        QString raisehand_auth_token = "raisehand_auth_token";
    } raw_headers;

    struct Enums {
        raw_headers _raw_headers;
    };

private:
    Enums *enums;

};

#endif // APIS_H
