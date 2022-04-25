#ifndef INFODIALOG_H
#define INFODIALOG_H

#include <QDialog>

namespace Ui {
class InfoDialog;
}

class InfoDialog : public QDialog
{
    Q_OBJECT

public:
    explicit InfoDialog(QWidget *parent = nullptr);
    ~InfoDialog();

    const QString &getPosition() const;

    const QString &getOperating_system() const;

private slots:

    void on_okBtn_clicked();

    void on_cancelBtn_clicked();

private:
    QString position, operating_system;
    Ui::InfoDialog *ui;
};

#endif // INFODIALOG_H
