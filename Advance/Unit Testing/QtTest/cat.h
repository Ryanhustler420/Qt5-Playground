#ifndef CAT_H
#define CAT_H

#include <QObject>
#include <QDebug>
#include <QtTest/QtTest>
#include <QTest>

class Cat : public QObject
{
    Q_OBJECT
public:
    explicit Cat(QObject *parent = nullptr);

signals:

private slots:
    void meow();
    void sleep();
    void speak(QString value); // did not call due to parem!

};

#endif // CAT_H
