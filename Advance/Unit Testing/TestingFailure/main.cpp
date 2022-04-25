#include <QCoreApplication>
#include <QTest>
#include "widget.h"

// Use some of the QTEST Macros
// https://doc.qt.io/qt-5/qtest.html
// https://doc.qt.io/qt-5/qtest-tutorial.html

// Update .Pro file:  QT += testlib

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Widget widget;
    widget.setAge(0);
    QTest::qExec(&widget);

    return a.exec();
}
