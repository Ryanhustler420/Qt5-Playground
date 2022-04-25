#include "infodialog.h"
#include "ui_infodialog.h"

InfoDialog::InfoDialog(QWidget *parent) :
    QDialog(parent, Qt::WindowSystemMenuHint | Qt::WindowTitleHint),
    ui(new Ui::InfoDialog)
{
    ui->setupUi(this);
}

InfoDialog::~InfoDialog()
{
    delete ui;
}

void InfoDialog::on_okBtn_clicked()
{
    // Collect information
    QString userPosition = ui->positionLineEdit->text();
    if (!userPosition.isEmpty()) {
        position = userPosition;

        if (ui->windowsRb->isChecked()) {
            operating_system = "Windows";
        }

        if (ui->macRb->isChecked()) {
            operating_system = "Mac";
        }

        if (ui->linuxRb->isChecked()) {
            operating_system = "Linux";
        }
    }

    // Accept & Close Dialog
    accept();
}

void InfoDialog::on_cancelBtn_clicked()
{
    // Reject & Close Dialog
    reject();
}

const QString &InfoDialog::getOperating_system() const
{
    return operating_system;
}

const QString &InfoDialog::getPosition() const
{
    return position;
}
