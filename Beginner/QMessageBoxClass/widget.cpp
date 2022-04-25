#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>
#include <QMessageBox>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);


    QPushButton * button = new QPushButton(this);
    button->setText("Click Me");
    button->move(200, 200);

    connect(button, &QPushButton::clicked, [=]() {
       /*
       QMessageBox message;
       // message.setMaximumSize(300, 200);
       // message.setMinimumSize(300, 200);
       message.setWindowTitle("Message Title");
       message.setText("Something Happened");
       message.setInformativeText("Do you want to do something about it ?");
       message.setIcon(QMessageBox::Critical);
       message.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
       message.setDefaultButton(QMessageBox::Cancel);
       int ret = message.exec();
       */

        /*
            // Critical Message
            int ret = QMessageBox::critical(this, "Message Title", "Something happened. Do you want to do something about it ?", QMessageBox::Ok | QMessageBox::Cancel);
        */

        // int ret = QMessageBox::question(this, "Message Title", "Something happened. Do you want to do something about it ?", QMessageBox::Ok | QMessageBox::Cancel);

        int ret = QMessageBox::warning(this, "Message Title", "Something happened. Do you want to do something about it ?", QMessageBox::Ok | QMessageBox::Cancel);
        if (ret == QMessageBox::Ok) {
            qDebug() << "You clicked OK";
        }
        if (ret == QMessageBox::Cancel) {
            qDebug() << "You clicked Cancel";
        }

    });

}

Widget::~Widget()
{
    delete ui;
}

