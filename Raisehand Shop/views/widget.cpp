#include "views/widget.h"
#include "ui_widget.h"

#include "utility/hotkeyhandler.h"
#include "oauths/googleoauth.h"
#include "utility/jsonhelper.h"
#include "rx/signals.h"

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
        emit Signals::instance().signalTwo(10);
    });

    Signals::instance().signalTwoReceiver([=](int a){
        qInfo() << a;
    });

    // login logout
    // service(such as db, file) -> provider(class) -> bridge(class singleton) -> client(classes who create the instances)

    // header intercepeor
    // it wiil be a class which will work as interceptor of all the reqest either going or comming...

    // basically copy the login from other software and make in cpp

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
    apis.login(ui->email_le->text(), ui->password_le->text(), [=](QByteArray response) {
        QString message = JsonHelper::toString(JsonHelper::toJsonDocument(&response), "message");
        ui->latest_msg_lbl->setText(message);
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

