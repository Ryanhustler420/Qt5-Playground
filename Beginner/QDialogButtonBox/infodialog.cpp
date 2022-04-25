#include "infodialog.h"
#include "ui_infodialog.h"
#include <QDebug>

InfoDialog::InfoDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InfoDialog)
{
    ui->setupUi(this);
}

InfoDialog::~InfoDialog()
{
    delete ui;
}

void InfoDialog::on_buttonBox_clicked(QAbstractButton *button)
{
    QDialogButtonBox::StandardButton stdBtn = ui->buttonBox->standardButton(button);
    if (stdBtn == QDialogButtonBox::Ok) {
        accept();
        qDebug() << "OK Button clicked";
    }
    if (stdBtn == QDialogButtonBox::SaveAll) {
        qDebug() << "SaveAll Button clicked";
    }
    if (stdBtn == QDialogButtonBox::Open) {
        qDebug() << "Open Button clicked";
    }
    if (stdBtn == QDialogButtonBox::No) {
        reject();
        qDebug() << "No Button clicked";
    }
    if (stdBtn == QDialogButtonBox::Cancel) {
        reject();
        qDebug() << "Cancel Button clicked";
    }
}
