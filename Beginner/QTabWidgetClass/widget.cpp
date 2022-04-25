#include "widget.h"
#include "ui_widget.h"

#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // Declare the widget
    QWidget * widget = new QWidget(this);

    // Declare te layout for the widget
    QVBoxLayout * layout = new QVBoxLayout();

    layout->addWidget(new QPushButton("Button 1", this));
    layout->addWidget(new QPushButton("Button 2", this));
    layout->addWidget(new QPushButton("Button 3", this));

    QPushButton * button4 = new QPushButton("Button 4", this);
    connect(button4, &QPushButton::clicked, [=](){
       qDebug() << "Button 4 Clicked From Our Newly Created Tab";
    });

    layout->addWidget(button4);
    layout->addSpacerItem(new QSpacerItem(100, 200));

    // Set the layout to widget
    widget->setLayout(layout);

    // Add the widget to the layout
    // ui->tabWidget->addTab(widget, "Tab 4");

    // insert the tab
    ui->tabWidget->insertTab(1, widget, "Tab 4");

}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_tabOneBtn_clicked()
{
    qDebug() << "Tab 1 Btn Clicked";
}

