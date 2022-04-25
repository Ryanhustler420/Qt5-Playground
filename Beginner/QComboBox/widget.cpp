#include "widget.h"
#include "ui_widget.h"

#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // Add planets to this combobox
    ui->comboBox->addItem("Earth");
    ui->comboBox->addItem("Venus");
    ui->comboBox->addItem("Mars");
    ui->comboBox->addItem("Pluton");
    ui->comboBox->addItem("Saturn");

    // Make the combobox editale
    ui->comboBox->setEditable(true);

}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_captureValBtn_clicked()
{
    qDebug() << "The currently selected item in the combo is : " << ui->comboBox->currentText() << " and the index is : " << QString::number(ui->comboBox->currentIndex());
}

void Widget::on_setValBtn_clicked()
{
    ui->comboBox->setCurrentIndex(3);
}

void Widget::on_getValBtn_clicked()
{
    qDebug() << "The combboboxcurrently has " << QString::number(ui->comboBox->count()) << " items. They are :";
    for (int var = 0; var < ui->comboBox->count(); ++var) {
        qDebug() << "Index " << QString::number(var) << " : " << ui->comboBox->itemText(var);
    }
}
