#ifndef WIDGET_H
#define WIDGET_H

#include "utility/jsonhelper.h"
#include "networking/apis.h"

#include <QWidget>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT
public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_login_btn_clicked();
    void on_stocks_btn_clicked();

private:
    Ui::Widget *ui;
    Apis apis;
};
#endif // WIDGET_H
