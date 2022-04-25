#include "widget.h"
#include "ui_widget.h"
#include "infodialog.h"

#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_provideInfoBtn_clicked()
{
    InfoDialog * dialog = new InfoDialog(this);

    /*
    // Show the dialog model
    int rec = dialog->exec();

    if (rec == QDialog::Accepted) {
        QString position = dialog->getPosition();
        QString operating_sys = dialog->getOperating_system();

        qDebug() << "Position is: " << position << " and operating system is: " << operating_sys;

        ui->infoLabel->setText("Your position is: " + position + " and your operating system is: " + operating_sys);
    }

    if (rec == QDialog::Rejected) {
        qDebug() << "Dialog Rejected";
    }
    */

    // show the dialog non model
    connect(dialog, &InfoDialog::accepted, [=]() {
        QString position = dialog->getPosition();
        QString operating_sys = dialog->getOperating_system();

        qDebug() << "Position is: " << position << " and operating system is: " << operating_sys;
        ui->infoLabel->setText("Your position is: " + position + " and your operating system is: " + operating_sys);
    });
    connect(dialog, &InfoDialog::rejected, [=]() {
        qDebug() << "Dialog Rejected";
    });

    // show the dialog
    dialog->show();
    dialog->raise();
    dialog->activateWindow();

}
