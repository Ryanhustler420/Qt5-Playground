#include "widget.h"
#include "ui_widget.h"
#include <QVBoxLayout>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // Created the layout
//    QVBoxLayout * layout = new QVBoxLayout();

    // Add widget to the layout
//    layout->addWidget(ui->oneBtn);
//    layout->addWidget(ui->twoBtn);
//    layout->addWidget(ui->threeBtn);
//    layout->addWidget(ui->fourBtn);
//    layout->addWidget(ui->fiveBtn);

    // Set the layout to the widget
//    setLayout(layout);

}

Widget::~Widget()
{
    delete ui;
}

