#include "widget.h"
#include "ui_widget.h"
#include <QHBoxLayout>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // Defined the layout
//    QHBoxLayout * layout = new QHBoxLayout();

    // Add things to the layout
//    layout->addWidget(ui->oneBtn);
//    layout->addWidget(ui->twoBtn);
//    layout->addWidget(ui->threeBtn);
//    layout->addWidget(ui->fourBtn);
//    layout->addWidget(ui->fiveBtn);

    // set layout to widget
//    setLayout(layout);

    // We need to place the buttons in organise way using ui tools
    // example [layout horizontal] || [layout vertical]

}

Widget::~Widget()
{
    delete ui;
}



