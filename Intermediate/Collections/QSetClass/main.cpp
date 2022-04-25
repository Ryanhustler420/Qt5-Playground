#include <QCoreApplication>
#include <QSet>
#include <QDebug>
#include <QString>

// QSet<T> is one of Qt's generic container classes.
// It stores values in an "unspecified order" and provides very fast lookup of the values.

// It very fast, since it doesn't care about the orders

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QSet<QString> people;
    people << "Gaurav" << "Saurav" << "Mogli";

    people.insert("Googli");
    people.insert("Random Guy");

    // Notice this is out of order!
    for (QString person : people) {
        qInfo() << person;
    }

    // Very Fast, but not faster then QVector
    qInfo() << "Gaurav in collection: " << people.contains("Gaurav");

    return a.exec();
}
