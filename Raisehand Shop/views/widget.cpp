#include "views/widget.h"
#include "ui_widget.h"

#include "utility/hotkeyhandler.h"
#include "oauths/googleoauth.h"

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
    apis.login(ui->email_le->text(), ui->password_le->text(), [=](QByteArray response) {
        //        QString message = JsonHelper::toString(JsonHelper::toJsonDocument(&response), "message");
//        ui->latest_msg_lbl->setText(message);
    }, [=](QByteArray error){ ui->latest_msg_lbl->setText(error); });
}

void Widget::on_stocks_btn_clicked()
{
    apis.getMyStockIds("61232989fe2e480016701465", [=](QByteArray response){
        QJsonObject object = JsonHelper::toJsonObject(JsonHelper::toJsonDocument(&response), "document");
        QJsonArray array = JsonHelper::toJsonArray(object, "shopProducts");
        for (int var = 0; var < array.size(); ++var)
            ui->stocks_list_list_widget->addItem(array.at(var).toString());
    }, [=](QByteArray error){ ui->latest_msg_lbl->setText(error); });
}

