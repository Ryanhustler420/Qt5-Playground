#include "views/widget.h"
#include "ui_widget.h"

#include "utility/hotkeyhandler.h"
#include "oauths/googleoauth.h"
#include "utility/jsonhelper.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    HotKeyHandler *hk = new HotKeyHandler(this, this);

    hk->ctrl_plus_return_key([=](QString str) {
        ui->login_btn->setEnabled(false);
        qInfo() << str;
    });

    hk->ctrl_plus_k_key([=](QString str) {
        ui->login_btn->setEnabled(true);
        qInfo() << str;
    });

    // login logout
    // service(such as db, file) -> provider(class) -> bridge(class singleton) -> client(classes who create the instances)

    // header intercepeor
    // it wiil be a class which will work as interceptor of all the reqest either going or comming...

    // basically copy the login from other software and make in cpp

    // create docs
    // create pipe line
    // create our programming flow pattern

    // merge the downloaded data
    // prepare all the laptop for dataset downloading
    // modify the craweler to fetch more data
    // split data set

    // 1 lakh on each computer

    // Constant Class
    // RaisehandCloudinary
    // Image Manupulator <plugin>
    // Models
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_login_btn_clicked()
{

    GoogleOAuth g;
    g.click();
//    apis.login(ui->email_le->text(), ui->password_le->text(), [=](QByteArray response) {
//        //        QString message = JsonHelper::toString(JsonHelper::toJsonDocument(&response), "message");
////        ui->latest_msg_lbl->setText(message);
//    }, [=](QByteArray error){ ui->latest_msg_lbl->setText(error); });

}

void Widget::on_stocks_btn_clicked()
{
        apis.exchangeGoogleOAuthCode("4%2F0AX4XfWg4hiYZtL_Hp2FFL5ZK4-ka4gSCponQAb90alT6JeSBWxSXUTWkdAhDr0OMlmiLMQ", [=](QByteArray response){
            QJsonDocument doc = JsonHelper::toJsonDocument(&response);
            QString access_token = JsonHelper::toString(doc, "access_token");
            QString token_type = JsonHelper::toString(doc, "token_type");
            QString id_token = JsonHelper::toString(doc, "id_token");
            apis.exchangeGoogleAccessTokenForUserInfo(token_type, access_token, [=](QByteArray response) {
                qInfo() << JsonHelper::toJsonDocument(&response);
            }, [=](QByteArray error) {
                qWarning() << error;
            });
        }, [=](QByteArray error){
            ui->latest_msg_lbl->setText(error);
        });

//    apis.getMyStockIds("61232989fe2e480016701465", [=](QByteArray response){
//        QJsonObject object = JsonHelper::toJsonObject(JsonHelper::toJsonDocument(&response), "document");
//        QJsonArray array = JsonHelper::toJsonArray(object, "shopProducts");
//        for (int var = 0; var < array.size(); ++var)
//            ui->stocks_list_list_widget->addItem(array.at(var).toString());
//    }, [=](QByteArray error){ ui->latest_msg_lbl->setText(error); });
}

