#include "widget.h"
#include "ui_widget.h"

#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->label->setAutoFillBackground(true);

    // Retrieve The Palette for the label
    QPalette palette = ui->label->palette();

    // Modify the palette with our changes
    palette.setColor(QPalette::Window, Qt::blue);
    palette.setColor(QPalette::WindowText, Qt::red);

    // Reset the palette to the widget
    ui->label->setPalette(palette);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_activeBtn_clicked()
{

    QPalette::ColorGroup activeButtonColorGroup = ui->activeBtn->palette().currentColorGroup();
    QPalette::ColorGroup disabledButtonColorGroup = ui->disabledBtn->palette().currentColorGroup();

    qDebug() << "  Active button color group : " << activeButtonColorGroup;
    qDebug() << "  Active button color group : " << disabledButtonColorGroup;

}
