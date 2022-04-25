#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QItemSelection>
#include <QStandardItemModel>

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
    void selectionChangedSlot(const QItemSelection &oldSelection, const QItemSelection &newSelection);

private:
    Ui::Widget *ui;
    QStandardItemModel * model;
};
#endif // WIDGET_H
