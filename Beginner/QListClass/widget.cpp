#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QList>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // Declare the list
    QList<QString> stringList;

    stringList << "I am" << " loving " << " Qt";
    // ["I am", " loving ", " Qt"]

    stringList.append(" a ");
    stringList.append(" lot !");

    // Get the data from the list
    qDebug() << stringList[0];
    qDebug() << stringList[1];
    qDebug() << stringList[2];
    qDebug() << stringList[3];

    qDebug() << "Total Elements in list: " << stringList.length();

    // Looping through the list of string

    for (int i=0; i<stringList.count(); i++ ) {
        // qDebug() << "The element at index " << i << " is " << stringList.at(i);
        qDebug() << "The element at index " << QString::number(i) << " is " << stringList.at(i);
    }








}

Widget::~Widget()
{
    delete ui;
}

