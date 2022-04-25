#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // common style shared between buttons
    QFont buttonFont("Times", 20, QFont::Bold);

    // Clicked Signal
    QPushButton * button = new QPushButton("Button1", this);
    button->setMinimumSize(200, 100);
    button->setFont(buttonFont);
    connect(button, &QPushButton::clicked, [=](){
        qDebug() << "Button Clicked";
    });

    // Clicked Pressed
    QPushButton * button2 = new QPushButton("Button1", this);
    button2->setMinimumSize(200, 100);
    button2->setFont(buttonFont);
    button2->move(205, 0);
    connect(button2, &QPushButton::pressed, [=](){
        qDebug() << "Button Pressed";
    });

    connect(button2, &QPushButton::released, [=](){
        qDebug() << "Button Released";
    });

}

Widget::~Widget()
{
    delete ui;
}

