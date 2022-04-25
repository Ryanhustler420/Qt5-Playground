#include "widget.h"
#include "ui_widget.h"
#include <QButtonGroup>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QButtonGroup * btnGroup = new QButtonGroup();
    btnGroup->addButton(ui->winCb);
    btnGroup->addButton(ui->macCb);
    btnGroup->addButton(ui->linuxCb);

    btnGroup->setExclusive(true);

}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_winCb_toggled(bool checked)
{
    if (checked) {
        qDebug() << "Windows Checked Box is Checked";
    } else {
        qDebug() << "Windows is no longer checked";
    }
}


void Widget::on_oneTbCb_toggled(bool checked)
{
    if (checked) {
        qDebug() << "One Tb HDD Checked Box is Checked";
    } else {
        qDebug() << "One Tb HDD is no longer checked";
    }
}


void Widget::on_samsungRb_toggled(bool checked)
{
    if (checked) {
        qDebug() << "Samsung Brand SSD Checked Box is Checked";
    } else {
        qDebug() << "Samsung Brand SSD is no longer checked";
    }
}


void Widget::on_grabDataBtn_clicked()
{
    if (ui->winCb->isChecked()) {
        qDebug() << "Windows Checked Box is Checked";
    } else {
        qDebug() << "Windows is no longer checked";
    }
}


void Widget::on_setDefaultStateBtn_clicked()
{
    // Exclusive
    if (ui->winCb->isChecked()) {
        ui->winCb->setChecked(false);
    } else {
        ui->winCb->setChecked(true);
    }

    // Non-Exclusive
    if (ui->oneTbCb->isChecked()) {
        ui->oneTbCb->setChecked(false);
    } else {
        ui->oneTbCb->setChecked(true);
    }
}

