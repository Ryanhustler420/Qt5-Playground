#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <QString>
#include <application/manager.h>

static const QString DEV = "dev";
static const QString PROD = "prod";

static const QString rootNode = Manager::instance().getCurrentEnv(); // "prod" || "dev" when running on localHost
static const QString appVersionName = Manager::instance().getAppVersionName(); // example "15" (string)
static const QString serverVersionCode = Manager::instance().getServerVersionCode(); // example 1 (int)
static const int appVersionCode = Manager::instance().getVersionCode(); // example 15 (int)

static bool isProd() { return rootNode.compare(rootNode); }

static const QString tld_dns = "xcodeclazz.com";
static const QString tld_dns_sandbox = "xcodeclazz.surge.sh";

static const QString tld_localhost = "localhost:3002";
static const QString tld_localhost_sandbox = "localhost:3002";
static const QString TLD = isProd() ? tld_dns : tld_localhost;

static const QString secure_dns_live = "http://" + tld_dns;
static const QString secure_dns_sandbox = "https://" + tld_dns_sandbox;

static const QString unsecure_dns_live = "http://" + tld_dns;
static const QString unsecure_dns_sandbox = "http://" + tld_dns_sandbox;
static const QString unsecure_localhost_sandbox = "http://" + tld_localhost_sandbox;

static const QString pokeSite = "https://www.cplusplus.com";

/* CHANGE BASED ON PROJECT */

static const QString APP_NAME = "xcodeclazz";
static const QString PACKAGE_NAME = "com.xcodeclazz.xcodeclazz";
static const QString PROJECT_NAME = "xcodeclazz_qt_desktop_xcodeclazz";
static const QString PACKAGE_NAME_FOR_LOCAL_STORAGE = "COM.XCODECLAZZ.XCODECLAZZ_";

// Stripe (payment charging...)
static const QString STRIPE_PK = isProd() ? "Values.STRIPE_LIVE_PK" : "Values.STRIPE_TEST_PK";
static const QString PAYTM_MID = isProd() ? "Values.PAYTM_PROD_MID" : "Values.PAYTM_TEST_MID";
static const QString PAYTM_HOST = isProd() ? "Values.PAYTM_PROD_HOST" : "Values.PAYTM_TEST_HOST";
static const QString PAYTM_HOSTNAME = isProd() ? "Values.PAYTM_PROD_HOSTNAME" : "Values.PAYTM_TEST_HOSTNAME";
static const QString PAYTM_CALLBACK = isProd() ? "Values.PAYTM_PROD_CALLBACK" : "Values.PAYTM_TEST_CALLBACK";

static const QString PLATFORM_ANDROID = "android";
static const QString REPOSITORY_TYPE = "NORMAL";

// time format
static const QString COMPLETE_TIME_FORMAT = "yyyy-MM-dd'T'HH:mm:ss";
static const QString RESULT_NOT_FOUND = "Shoot: No Match Found";

// Delayed
static const long DELAY_MILLISECOND_MEDIUM = 2000;
static const long DELAY_MILLISECOND_SMALL = 1000;
static const long DELAY_MILLISECOND_LONG = 10000;
static const long DELAY_MILLISECOND_TINY = 500;
static const long DELAY_MILLISECOND = 3000;

// REGEX EXPRESSION
static const QString REGEX_ONLY_NUMBER = "^[0-9]*$";
static const QString NUMBER_AND_DECIMAL_REGEX = "^\\d*\\.\\d+|\\d+\\.\\d*$";
static const QString PASSWORD_REGEX = "(?=.*[a-z])(?=.*[A-Z])(?=.*[\\d])(?=.*[~`!@#\\$%\\^&\\*\\(\\)\\-_\\+=\\{\\}\\[\\]\\|\\;:\"<>,./\\?]).{8,}";

// genders
static const QString All = "All";
static const QString Male = "Male";
static const QString Other = "Other";
static const QString Female = "Female";

static const QString SYMBOL_INR = "₹"; // "\u20B9";

static const QString CURRENCY = "currency";
static const QString EMPTY_STRING = "";

static const QString IMAGE_EXTENSION = ".jpg";
static const QString NO_IMAGE_PLACEHOLDER_URL = "v1608273379/placeholders/d4hvycei5ymlp0gtxdvd.jpg";
static const QString DEFAULT_USER_AVATAR_PLACEHOLDER_URL = "v1617597744/placeholders/bs31ctfmkv59ekurxi5a.png";

static QString getEnv() {
    return isProd() ? PROD : DEV;
}

#endif // CONSTANTS_H
