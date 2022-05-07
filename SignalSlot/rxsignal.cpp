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
}

RxSignal::~RxSignal()
{
    delete ui;
}

void RxSignal::on_pushButton_clicked()
{
    BogusClass bc;
    bc.emitt();
    (new BogusClass())->emitt();
    emit Reactive::instance().signalTwo(QRandomGenerator::global()->bounded(1000));
}

void RxSignal::on_horizontalSlider_valueChanged(int value)
{
    emit Reactive::instance().signalTwo(value);
    ui->progressBar->setValue(value);
}
