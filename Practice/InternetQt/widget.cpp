#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    Logger::setPath("C:", "virus.txt");
    Logger::attach();
    Logger::logging = true;
    Logger::dirty_console = false;
}

Widget::~Widget()
{
    delete ui;
}

