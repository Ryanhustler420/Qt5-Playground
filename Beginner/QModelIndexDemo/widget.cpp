#include "widget.h"
#include "ui_widget.h"

#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    model = new QFileSystemModel(this);
    parentIndex = model->setRootPath("C:/Program Files");
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    int rowCount = model->rowCount(parentIndex);
    qDebug() << QString::number(rowCount);

    for (int var = 0; var < rowCount; ++var) {
        QModelIndex index = model->index(var, 0, parentIndex);
        QString data = model->data(index, Qt::DisplayRole).toString();
        qDebug() <<  "Data item [ " << QString::number(var) << " ] " << data;
    }

}
