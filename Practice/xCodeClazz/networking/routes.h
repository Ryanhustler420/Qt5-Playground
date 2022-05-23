#ifndef ROUTES_H
#define ROUTES_H

#include "parents/commonsuperclass.h"
#include "application/manager.h"

#include <QNetworkAccessManager>

static QString const host = Manager::instance().getCurrentHostUrl().url();

class Routes : public CommonSuperClass
{
public:
    explicit Routes(CommonSuperClass *parent = nullptr);
    // Routes() :           host("http://localhost:3002/")           {}; // https://stackoverflow.com/a/11594963

signals:

public:
    typedef struct URLS {
        QUrl *POST_API_SHOP_USERS_CREATE = new QUrl(host + "/api/shop/users/create");
        QUrl *POST_API_SHOP_USERS_CREATE_OAUTH_GOOGLE_LOGIN_OR_SIGNUP_START = new QUrl(host + "/api/shop/users/create/oauth/google/login-or-signup-start");
        QUrl *POST_API_SHOP_USERS_CREATE_OAUTH_GOOGLE_SIGNUP_COMPLETE = new QUrl(host + "/api/shop/users/create/oauth/google/signup-complete");
        QUrl *POST_API_SHOP_USER_LOGIN = new QUrl(host + "/api/shop/user/login");
        QUrl *POST_API_SHOP_USER_LOGGED_IN_DEVICE = new QUrl(host + "/api/shop/user/loggedInDevice");
        QUrl *GET_API_SHOP_USER_CURRENT_USER = new QUrl(host + "/api/shop/user/currentUser");
        QUrl *POST_API_SHOP_USER_LOGOUT = new QUrl(host + "/api/shop/user/logout");
        QUrl *POST_API_SHOP_USER_RECHARGE_COUPON_ID = new QUrl(host + "/api/shop/user/rechargeCouponId");
        QUrl *POST_API_SHOP_USER_RECHARGE_COUPON_CODE = new QUrl(host + "/api/shop/user/rechargeCouponCode");
        QUrl *POST_API_SHOP_USER_SUBSCRIBE_RECHARGE_COUPON = new QUrl(host + "/api/shop/user/subscribeRechargeCoupon");
        QUrl *GET_API_SHOP_USER_ALL_NOTIFICATIONS = new QUrl(host + "/api/shop/user/allNotifications");
        QUrl *POST_API_SHOP_USER_DELETE_OLDER_NOTIFICATIONS = new QUrl(host + "/api/shop/user/deleteOlderNotifications");
        QUrl *GET_API_SHOP_USER_LOGGED_IN_DEVICES = new QUrl(host + "/api/shop/user/loggedInDevices");
        QUrl *POST_API_SHOP_JOIN_REQUEST = new QUrl(host + "/api/shop/joinRequest");
        QUrl *POST_API_SHOP_SHOPS_POPULATED_SHOP = new QUrl(host + "/api/shop/shops/populated/shop");
        QUrl *POST_API_SHOP_SHOPS_CREATE = new QUrl(host + "/api/shop/shops/create");
        QUrl *POST_API_SHOP_SHOP_UPDATE = new QUrl(host + "/api/shop/shop/update");
        QUrl *POST_API_SHOP_PAYMENT_PRICES = new QUrl(host + "/api/shop/payment/prices");
        QUrl *POST_API_SHOP_PAYMENT_GENERATE_PAYTM_CHECKSUM = new QUrl(host + "/api/shop/payment/paytm/checksum");
        QUrl *POST_API_SHOP_PAYMENT_CHARGE_SILVER_PLAN = new QUrl(host + "/api/shop/payment/chargeSilverPlan");
        QUrl *POST_API_SHOP_PAYMENT_CHARGE_GOLD_PLAN = new QUrl(host + "/api/shop/payment/chargeGoldPlan");
        QUrl *POST_API_SHOP_PAYMENT_CHARGE_ONION_PLAN = new QUrl(host + "/api/shop/payment/chargeOnionPlan");
        QUrl *POST_API_SHOP_PAYMENTS_SAVE_PAYMENT_DETAILS = new QUrl(host + "/api/shop/payments/savePaymentDetails");
        QUrl *POST_API_SHOP_PAYMENTS_PAYMENTS_HISTORY = new QUrl(host + "/api/shop/payments/paymentsHistory");
        QUrl *POST_API_SHOP_BYPASS_PAYMENTS_SAVE_PAYMENT_DETAILS = new QUrl(host + "/api/shop/bypass/payments/savePaymentDetails");
        QUrl *POST_API_SHOP_SHOP_STATE = new QUrl(host + "/api/shop/shop/state");
        QUrl *POST_API_SHOP_SHOP_NOTICE_BOARD = new QUrl(host + "/api/shop/shop/noticeBoard");
        QUrl *POST_API_SHOP_SHOP_PRODUCT_UPDATE = new QUrl(host + "/api/shop/shopProduct/update");
        QUrl *POST_API_SHOP_SHOP_ALL_TOUCHED_REPO_PRODUCTS = new QUrl(host + "/api/shop/shop/allTouchedRepoProducts");
        QUrl *POST_API_SHOP_SHOP_PRODUCTS_IMPORT = new QUrl(host + "/api/shop/shopProducts/import");
        QUrl *POST_API_SHOP_SHOP_PRODUCTS_PARTIAL_OWNER_SEARCH_IN_STOCK = new QUrl(host + "/api/shop/shopProducts/partial/owner/searchInStock");
        QUrl *POST_API_SHOP_SHOP_PRODUCTS_PARTIAL_OWNER_WITH_IDS = new QUrl(host + "/api/shop/shopProducts/partial/owner/withIds");
        QUrl *POST_API_SHOP_SHOP_PRODUCTS_SHOP_PRODUCT = new QUrl(host + "/api/shop/shopProducts/shopProduct");
        QUrl *POST_API_SHOP_SHOP_ALL_SHOP_PRODUCTS_IDS = new QUrl(host + "/api/shop/shop/allShopProductIds");
        QUrl *POST_API_SHOP_SHOP_PRODUCT_OFFER = new QUrl(host + "/api/shop/shopProduct/offer");
        QUrl *POST_API_SHOP_SHOP_PRODUCT_VISIBILITY = new QUrl(host + "/api/shop/shopProduct/visibility");
        QUrl *POST_API_SHOP_SHOP_PRODUCT_PUSH_SHOWCASE = new QUrl(host + "/api/shop/shopProduct/pushShowcase");
        QUrl *POST_API_SHOP_SHOP_PRODUCT_REMOVE_SHOWCASE = new QUrl(host + "/api/shop/shopProduct/removeShowcase");
        QUrl *POST_API_SHOP_SHOP_DEACTIVATE = new QUrl(host + "/api/shop/shop/deactivate");
        QUrl *POST_API_SHOP_SHOP_PRODUCT_DELETE = new QUrl(host + "/api/shop/shopProduct/delete");
        QUrl *POST_API_WORKER_SHOP_STATE_CHECK = new QUrl(host + "/api/worker/shop/stateCheck");
        QUrl *POST_API_WORKER_SHOP_STATE_REFRESH_SHOWCASE = new QUrl(host + "/api/worker/shop/refreshShowcase");
        QUrl *POST_API_WORKER_SHOP_BALANCE_IDS = new QUrl(host + "/api/worker/shop/balanceIds");
        QUrl *POST_API_WORKER_SHOP_PRODUCTS_IMPORT_MASS = new QUrl(host + "/api/worker/shopProducts/import/mass");
        QUrl *POST_API_WORKER_SHOP_PRODUCT_DELETE_MULTIPLE = new QUrl(host + "/api/worker/shopProduct/delete_multiple");
        QUrl *POST_API_WORKER_SHOP_PRODUCT_VISIBILITY_MULTIPLE = new QUrl(host + "/api/worker/shopProduct/visibility_multiple");
        QUrl *POST_API_WORKER_SHOP_ALL_SHOP_PRODUCT_AND_REPO_PRODUCT_IDS = new QUrl(host + "/api/worker/shop/allShopProductAndRepoProductIds");
        QUrl *POST_API_SHOP_SHOP_IB_RECEIVED = new QUrl(host + "/api/shop/shop/ib_received");
        QUrl *POST_API_SHOP_SHOP_UPDATE_STOCKS = new QUrl(host + "/api/shop/shop/updateStocks");
        QUrl *POST_API_SHOP_SHOP_LEFT_HAND = new QUrl(host + "/api/shop/shop/lefthand");
        QUrl *POST_API_SHOP_SHOP_PRODUCTS_IMPORT_VIA_QR = new QUrl(host + "/api/shop/shopProducts/importViaQR");
        QUrl *POST_API_COMMON_USER_UPDATE = new QUrl(host + "/api/common/user/update");
        QUrl *POST_API_COMMON_USER_RESET_PASSWORD_REQUEST = new QUrl(host + "/api/common/user/resetPasswordRequest");
        QUrl *POST_API_COMMON_USER_REPORT_BUG = new QUrl(host + "/api/common/user/reportBug");
        QUrl *GET_API_HELPER_COUNTERS_ALL = new QUrl(host + "/api/helper/counters/all");
        QUrl *GET_API_HELPER_SI_UNITS_ALL = new QUrl(host + "/api/helper/siUnits/all");
        QUrl *GET_API_HELPER_COUNTRIES_ALL = new QUrl(host + "/api/helper/countries/all");
        QUrl *GET_API_HELPER_CURRENCIES_ALL = new QUrl(host + "/api/helper/currencies/all");
        QUrl *GET_API_HELPER_CATEGORIES_ALL = new QUrl(host + "/api/helper/categories/all");
        QUrl *GET_API_HELPER_SECRET_KEYS_ALL = new QUrl(host + "/api/helper/secretKeys/all");
        QUrl *GET_API_HELPER_SERVICES_ALL = new QUrl(host + "/api/helper/services/all");
        QUrl *GET_API_HELPER_PAYMENT_METHODS_ALL = new QUrl(host + "/api/helper/paymentMethods/all");
        QUrl *GET_API_HELPER_ONBOARDED_COMPANIES_ALL = new QUrl(host + "/api/helper/onboarded_companies/all");
        QUrl *POST_API_ENV_V3_REPO_PRODUCTS_PARTIAL_GUEST_SEARCH = new QUrl(host + "/api/env/v3/repoProducts/partial/guestSearch");
        QUrl *POST_API_ENV_REPO_PRODUCTS_REPO_PRODUCT = new QUrl(host + "/api/env/repoProducts/repoProduct");
        // QUrl *POST_API_ENV_REPO_PRODUCT_SEE = new QUrl(host + "/api/env/repoProduct/see");
        QUrl *POST_API_ENV_REPO_PRODUCTS_PARTIAL_SEARCH_INSIDE = new QUrl(host + "/api/env/repoProducts/partial/searchInside");
        QUrl *POST_API_ENV_REPO_PRODUCTS_PARTIAL_WITH_IDS = new QUrl(host + "/api/env/repoProducts/partial/withIds");
        QUrl *POST_API_ENV_PRODUCT_REPOSITORY_ALL_REPO_PRODUCT_IDS = new QUrl(host + "/api/env/productRepository/allRepoProductIds");
        QUrl *POST_API_ENV_PRODUCT_REPOSITORIES_PARTIAL_SEARCH = new QUrl(host + "/api/env/productRepositories/partial/search");
    } urls;

    struct Enums {
        urls _urls;
    };

    Enums *enums;

public:
    QUrl get_host_url() const;
    QUrl post_api_shop_create() const;
    QUrl post_api_shop_users_create_oauth_google_login_or_signup_start() const;
    QUrl post_api_shop_users_create_oauth_google_signup_complete() const;
    QUrl post_api_shop_user_login() const;
    QUrl post_api_shop_user_logged_in_device() const;
    QUrl get_api_shop_user_current_user() const;
    QUrl post_api_shop_user_logout() const;
    QUrl post_api_shop_user_recharge_coupon_id() const;
    QUrl post_api_shop_user_recharge_coupon_code() const;
    QUrl post_api_shop_user_subscribe_recharge_coupon() const;
    QUrl get_api_shop_user_all_notifications() const;
    QUrl post_api_shop_user_delete_older_notifications() const;
    QUrl get_api_shop_user_logged_in_devices() const;
    QUrl post_api_shop_join_request() const;
    QUrl post_api_shop_shops_populated_shop() const;
    QUrl post_api_shop_shops_create() const;
    QUrl post_api_shop_shop_update() const;
    QUrl post_api_shop_payment_prices() const;
    QUrl post_api_shop_payment_generate_paytm_checksum() const;
    QUrl post_api_shop_payment_charge_silver_plan() const;
    QUrl post_api_shop_payment_charge_gold_plan() const;
    QUrl post_api_shop_payment_charge_onion_plan() const;
    QUrl post_api_shop_payments_save_payment_details() const;
    QUrl post_api_shop_payments_payments_history() const;
    QUrl post_api_shop_bypass_payments_save_payment_details() const;
    QUrl post_api_shop_shop_state() const;
    QUrl post_api_shop_shop_notice_board() const;
    QUrl post_api_shop_shop_product_update() const;
    QUrl post_api_shop_shop_all_touched_repo_products() const;
    QUrl post_api_shop_shop_products_import() const;
    QUrl post_api_shop_shop_products_partial_owner_search_in_stock() const;
    QUrl post_api_shop_shop_products_partial_owner_with_ids() const;
    QUrl post_api_shop_shop_products_shop_product() const;
    QUrl post_api_shop_shop_all_shop_products_ids() const;
    QUrl post_api_shop_shop_product_offer() const;
    QUrl post_api_shop_shop_product_visibility() const;
    QUrl post_api_shop_shop_product_push_showcase() const;
    QUrl post_api_shop_shop_product_remove_showcase() const;
    QUrl post_api_shop_shop_deactivate() const;
    QUrl post_api_shop_shop_product_delete() const;
    QUrl post_api_worker_shop_state_check() const;
    QUrl post_api_worker_shop_state_refresh_showcase() const;
    QUrl post_api_worker_shop_balance_ids() const;
    QUrl post_api_worker_shop_products_import_mass() const;
    QUrl post_api_worker_shop_product_delete_multiple() const;
    QUrl post_api_worker_shop_product_visibility_multiple() const;
    QUrl post_api_worker_shop_all_shop_product_and_repo_product_ids() const;
    QUrl post_api_shop_shop_ib_received() const;
    QUrl post_api_shop_shop_update_stocks() const;
    QUrl post_api_shop_shop_left_hand() const;
    QUrl post_api_shop_shop_products_import_via_qr() const;
    QUrl post_api_common_user_update() const;
    QUrl post_api_common_user_reset_password_request() const;
    QUrl post_api_common_user_report_bug() const;
    QUrl get_api_helper_counters_all() const;
    QUrl get_api_helper_si_units_all() const;
    QUrl get_api_helper_counteries_all() const;
    QUrl get_api_helper_currencies_all() const;
    QUrl get_api_helper_categories_all() const;
    QUrl get_api_helper_secret_keys_all() const;
    QUrl get_api_helper_services_all() const;
    QUrl get_api_helper_payment_methods_all() const;
    QUrl get_api_helper_onboarded_companies_all() const;
    QUrl post_api_env_v3_repo_products_partial_guest_search() const;
    QUrl post_api_env_repo_products_repo_product() const;
    // QUrl post_api_env_repo_product_see() const;
    QUrl post_api_env_repo_products_partial_search_inside() const;
    QUrl post_api_env_repo_products_partial_with_ids() const;
    QUrl post_api_env_product_repository_all_repo_product_ids() const;
    QUrl post_api_env_product_repositories_partial_search() const;
};

#endif // ROUTES_H
