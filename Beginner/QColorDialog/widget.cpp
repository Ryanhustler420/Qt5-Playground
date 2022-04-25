#include "widget.h"
#include "ui_widget.h"

#include <QColorDialog>
#include <QDebug>
#include <QFontDialog>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->label->setAutoFillBackground(true);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_textColorBtn_clicked()
{
    QPalette palette = ui->label->palette();

    QColor color = palette.color(QPalette::WindowText);
    QColor chosenColor = QColorDialog::getColor(color, this, "Choose text color");

    if (chosenColor.isValid()) {
        palette.setColor(QPalette::WindowText, chosenColor);

        ui->label->setPalette(palette);

        qDebug() << "User choosen a valid color";
    } else {
        qDebug() << "User choosen invalid color";
    }
}

void Widget::on_backgroundBtn_clicked()
{
    QPalette palette = ui->label->palette();

    QColor color = palette.color(QPalette::Window);
    QColor chosenColor = QColorDialog::getColor(color, this, "Choose background color");

    if (chosenColor.isValid()) {
        palette.setColor(QPalette::Window, chosenColor);

        ui->label->setPalette(palette);

        qDebug() << "User choosen a valid color";
    } else {
        qDebug() << "User choosen invalid color";
    }
}

void Widget::on_fontBtn_clicked()
{
    bool ok;
    QFont font = QFontDialog::getFont(
                    &ok, QFont("Helvetica [Cronyx]", 10), this);
    if (ok) {
        ui->label->setFont(font);
    } else {
        // the user canceled the dialog; font is set to the initial
        // value, in this case Helvetica [Cronyx], 10
    }
}
