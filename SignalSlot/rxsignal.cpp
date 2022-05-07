#include "rxsignal.h"
#include "ui_rxsignal.h"

#include <QRandomGenerator>
#include "bogusclass.h"

RxSignal::RxSignal(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::RxSignal)
{
    ui->setupUi(this);

    Reactive::instance().signalTwoReceiver([=](int a) {
        ui->label->setText(QString::number(a));
    });

    // we need to make a pattern here first

    // s class will be singleton
    // the connect will live inside that singleton
    // some utility methods will go there i.e public onces

    // make two class to see if things are working as expected
    // maybe make two different dialog to see the things are working as expected.
}

RxSignal::~RxSignal()
{
    delete ui;
}

void RxSignal::on_pushButton_clicked()
{
    BogusClass bc;
    bc.emitt();
    emit Reactive::instance().signalTwo(QRandomGenerator::global()->bounded(1000));
}
