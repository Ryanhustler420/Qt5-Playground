#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QList>
#include <QColor>
#include <QPushButton>

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
    void on_oneBtn_clicked();

    void on_twoBtn_clicked();

    void on_threeBtn_clicked();

    void on_fourBtn_clicked();

    void on_fiveBtn_clicked();

    void on_sixBtn_clicked();

    void on_sevenBtn_clicked();

    void on_eightBtn_clicked();

    void on_nineBtn_clicked();

    void on_loadBtn_clicked();

    void on_saveBtn_clicked();

    void updateBtnBg(QPushButton* qPushBtn, int indexOnList);

private:
    Ui::Widget *ui;
    QList<QColor> colorList;

    void saveColor(QString key, QColor color);
    QColor loadColor(QString key);

    void setLoadedColor(QString key, int indexOnList, QPushButton* qPushBtn);
};
#endif // WIDGET_H
