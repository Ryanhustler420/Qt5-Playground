#include "widget.h"

Widget::Widget(QWidget *parent) : QWidget(parent)
{

}

void Widget::testAge_data()
{
    qInfo() << "Generating data...";

    QTest::addColumn<QString>("name");
    QTest::addColumn<int>("age");

    QTest::addRow("Invalid") << "Bob" << 190;
    QTest::addRow("Old") << "Gaurav" << 23;
    QTest::addRow("Young") << "Sangeeta" << 25;
    QTest::addRow("Underage") << "Kacchu" << 15;
    QTest::addRow("Retired") << "Grandma" << 90;

    qInfo() << "Data generated...";
}

void Widget::testAge()
{
    // Get the row data
    QFETCH(QString, name);
    QFETCH(int, age);

    qInfo() << "Testing age" << name << " is " << age;

    if (age < 1 || age > 100) QFAIL("Invalid Age!");
    if (age < 21) QFAIL("Must be an adult!");
    if (age > 40) QWARN("Getting old!");
    if (age > 65) qInfo() << "This person is retired";
}
