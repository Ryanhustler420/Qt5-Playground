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

static bool isProd() { return rootNode.compare(PROD); }

static const QString tld_dns = "raisehand.software";
static const QString tld_dns_sandbox = tld_dns + "/sandbox";

static const QString tld_localhost = "10.0.2.2:3002";
static const QString tld_localhost_sandbox = tld_localhost + "/sandbox";
static const QString TLD = isProd() ? tld_dns : tld_localhost;

static const QString secure_dns_live = "https://" + tld_dns;
static const QString secure_dns_sandbox = "https://" + tld_dns_sandbox;
static const QString secure_dns_live_fake = "https://shop." + tld_dns;

static const QString unsecure_dns_live = "http://" + tld_dns;
static const QString unsecure_dns_sandbox = "http://" + tld_dns_sandbox;
static const QString unsecure_localhost_sandbox = "http://" + tld_localhost + "/sandbox";

/* CHANGE BASED ON PROJECT */

static const QString APP_NAME = "shop";
static const QString PROJECT_NAME = "raisehand_shop";
static const QString PACKAGE_NAME = "io.raisehand.raisehandshop";
static const QString PACKAGE_NAME_FOR_LOCAL_STORAGE = "IO.RAISEHAND.RAISEHAND_SHOP_";

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

static const QString SNAPSHOT_SEPARATOR = ""; // could be -
static const QString TOAST_RESULT_NOT_FOUND = "Shoot: No Match Found";

// Delayed
static const long DELAY_MILLISECOND_MEDIUM = 2000;
static const long DELAY_MILLISECOND_SMALL = 1000;
static const long DELAY_MILLISECOND_LONG = 10000;
static const long DELAY_MILLISECOND_TINY = 500;
static const long DELAY_MILLISECOND = 3000;

static const int PRODUCT_UPDATE_SIGNAL_CODE = 0xbf;
static const int PRODUCT_SINGLE_VIEW_CODE = 0xba;
static const int USER_PROFILE_UPDATE = 0xaa;
static const int SIGNED_UP_COMPLETED = 0xab;
static const int SIBLING_CREATED = 0xbc;
static const int PRODUCT_UPDATE = 0xbd;
static const int BAKE_CODE = 0xab;

// Repo expire offset days
static const int MARGIN_DAY_BEFORE_EXPIRE_REPOSITORY = 5;
// shop expire offset days
static const int MARGIN_DAY_BEFORE_EXPIRE_SHOP = 5;
// DURATION
static const int AUTO_MERGE_REQUEST_DELETE_AFTER_DAYS = 30;
static const int AUTO_NOTIFICATION_DELETE_AFTER_DAYS = 10;

// REGEX EXPRESSION
static const QString REGEX_ONLY_NUMBER = "^[0-9]*$";
static const QString NUMBER_AND_DECIMAL_REGEX = "^\\d*\\.\\d+|\\d+\\.\\d*$";
static const QString PASSWORD_REGEX = "(?=.*[a-z])(?=.*[A-Z])(?=.*[\\d])(?=.*[~`!@#\\$%\\^&\\*\\(\\)\\-_\\+=\\{\\}\\[\\]\\|\\;:\"<>,./\\?]).{8,}";

// genders
static const QString All = "All";
static const QString Male = "Male";
static const QString Other = "Other";
static const QString Female = "Female";

// Product (Repository) coverage constant
static const QString INTERNATIONAL = "INTERNATIONAL";
static const QString NATIONAL = "NATIONAL";
static const QString LOCAL = "LOCAL";

// Shop coverage constant
static const QString SILVER = "SILVER";
static const QString ONION = "ONION";
static const QString GOLD = "GOLD";

static const QString SYMBOL_INR = "₹"; // "\u20B9";
static const QString SYMBOL_EUR = "€";
static const QString SYMBOL_JPY = "¥";
static const QString SYMBOL_RUB = "₽";
static const QString SYMBOL_USD = "$";

static const QString CURRENCY = "currency";
static const QString NOT_MENTIONED = "Not Mentioned";

// Stock Capacity
static const int INFINITY = -1; // meaning unlimited product insertion...
static const int LIMITED_INVENTORY_CAPACITY = 100;

// chip input delimiter
static const QString DELIMITER_DOUBLE_SLASH = "//";
static const QString DELIMITER_SINGLE_DOT = ".";

static const QString IMAGE_EXTENSION = ".jpg";
static const QString NO_IMAGE_PLACEHOLDER_URL = "v1608273379/placeholders/d4hvycei5ymlp0gtxdvd.jpg";
static const QString DEFAULT_USER_AVATAR_PLACEHOLDER_URL = "v1617597744/placeholders/bs31ctfmkv59ekurxi5a.png";
static const QString PRODUCT_NAMING_CONVENTION_PLACEHOLDER_URL = "v1616381978/placeholders/ybsjyls8uowrqi76fedg.png";
static const QString PRODUCT_CREATION_BEST_PRACTICES_PLACEHOLDER_URL = "v1616383572/placeholders/gfk0zzcsec3cnzbfmrfk.png";

// Offer counter based on membership tier
static const int SILVER_NOTICE_CHAR_COUNT = 80;
static const int GOLD_NOTICE_CHAR_COUNT = 120;
static const int ONION_NOTICE_CHAR_COUNT = 200;

static const int SILVER_PRODUCT_OFFER_CHAR_COUNT = 80;
static const int GOLD_PRODUCT_OFFER_CHAR_CHAR_COUNT = 120;
static const int ONION_PRODUCT_OFFER_CHAR_COUNT = 200;

static const int SILVER_TIER_SERVICES_CAPACITY = 2;
static const int GOLD_TIER_SERVICES_CAPACITY = 4;
static const int ONION_TIER_SERVICES_CAPACITY = 4;

static const int SILVER_TIER_SHOWCASE_CAPACITY = 2;
static const int GOLD_TIER_SHOWCASE_CAPACITY = 4;
static const int ONION_TIER_SHOWCASE_CAPACITY = 4;

// Product Quality Condition State
static const QString NEW = "new";
static const QString USED = "used";
static const QString REFURBISHED = "refurbished";

static const QString DEFAULT_PAYMENT = "Cash";
static const QString DEFAULT_SERVICE = "No-Service";

static const QString products = "products";
static const QString bakedInside = "bakedInside";
static const QString Underground = "Underground";
static const QString Surface = "Surface";

static const QString MASTER = "MASTER";
static const QString NORMAL = "NORMAL";

static const QString SIGNED = "Signed";
static const QString NOT_SIGNED = "Not Signed";

static const QString EMPTY_STRING = "";

static const QString getShopRefundPolicyPageUrl(bool isEmulator) {
    return isProd() ? secure_dns_live + "/shop/refund" : (isEmulator ? unsecure_localhost_sandbox : secure_dns_sandbox) + "/shop/refund";
}

static const QString getShopPolicyPageUrl(bool isEmulator) {
    return isProd() ? secure_dns_live + "/shop/policy" : (isEmulator ? unsecure_localhost_sandbox : secure_dns_sandbox) + "/shop/policy";
}

static const QString getShopTermsPageUrl(bool isEmulator) {
    return isProd() ? secure_dns_live + "/shop/terms" : (isEmulator ? unsecure_localhost_sandbox : secure_dns_sandbox) + "/shop/terms";
}

static int getFlavourNumber(QString flavour) throw(QString) {
    if (flavour == nullptr) throw("flavour not found!");
    return flavour.compare(Underground) ? 0 : 1;
}

static QString getEnv() {
    return isProd() ? PROD : DEV;
}

#endif // CONSTANTS_H
