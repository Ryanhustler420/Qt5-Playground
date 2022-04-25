1#include "widget.h"
#include "ui_widget.h"

#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->listWidget->addItem("Samsung Galaxy J7 Nxt Cover");
    ui->listWidget->addItem("Rotacap Inheler 400mg Big");
    ui->listWidget->addItem("Dolo 650 Tablet | Micro India Ltd");
    ui->listWidget->addItem("Oppo v3 Cutting Mobile @7000/- Only");

    // byDefault list widget allow to select one item at a time
    // allow multiple selection to list widget
    ui->listWidget->setSelectionMode(QAbstractItemView::MultiSelection);

}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_addItemBtn_clicked()
{
    ui->listWidget->addItem("New Item Added");
}


void Widget::on_deleteItemBtn_clicked()
{
    ui->listWidget->takeItem(ui->listWidget->currentRow());
}

void Widget::on_selectedItemsBtn_clicked()
{
    // get the list of selected items
    QList<QListWidgetItem *> list = ui->listWidget->selectedItems();
    for (int var = 0; var < list.count(); ++var) {
        qDebug() << "Selected item: " << list.at(var)->text() << " , row number id: " << ui->listWidget->row(list.at(var));
    }
}

