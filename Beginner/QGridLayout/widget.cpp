#include "widget.h"
#include "ui_widget.h"
#include <QGridLayout>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QGridLayout * layout = new QGridLayout();

    // First Row
    layout->addWidget(ui->OneBtn, 0 , 0);
    layout->addWidget(ui->TwoBtn, 0 , 1);
    layout->addWidget(ui->ThreeBtn, 0 , 2, 2, 1);

    // Second Row
    layout->addWidget(ui->FourBtn, 1 , 0);
    layout->addWidget(ui->FiveBtn, 1 , 1);

    // Third Row
    layout->addWidget(ui->SevenBtn, 2 , 0, 1, 2);
    layout->addWidget(ui->NineBtn, 2 , 2);

    // Setting the layout
    setLayout(layout);
}

Widget::~Widget()
{
    delete ui;
}

