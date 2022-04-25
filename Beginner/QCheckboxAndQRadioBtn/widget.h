#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

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
    void on_winCb_toggled(bool checked);

    void on_oneTbCb_toggled(bool checked);

    void on_samsungRb_toggled(bool checked);

    void on_grabDataBtn_clicked();

    void on_setDefaultStateBtn_clicked();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
