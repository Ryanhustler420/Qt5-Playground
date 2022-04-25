#include "widget.h"
#include "ui_widget.h"
#include "customtablemodel.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    CustomTableModel * model = new CustomTableModel(this);
    ui->tableView->setModel(model);

    ui->tableView->verticalHeader()->hide();
    // ui->tableView->horizontalHeader()->hide();

}

Widget::~Widget()
{
    delete ui;
}

