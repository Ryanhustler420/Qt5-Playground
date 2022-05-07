#ifndef RXSIGNAL_H
#define RXSIGNAL_H

#include <QWidget>
#include "reactive.h"

QT_BEGIN_NAMESPACE
namespace Ui { class RxSignal; }
QT_END_NAMESPACE

class RxSignal : public QWidget
{
    Q_OBJECT

public:
    RxSignal(QWidget *parent = nullptr);
    ~RxSignal();

private slots:
    void on_pushButton_clicked();

private:
    Ui::RxSignal *ui;
};
#endif // RXSIGNAL_H
