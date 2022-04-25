#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QDebug>
#include <QTest>

class Widget : public QWidget
{
    Q_OBJECT
public:
    explicit Widget(QWidget *parent = nullptr);

signals:

private slots:
    void testAge_data();
    void testAge();

};

#endif // WIDGET_H
