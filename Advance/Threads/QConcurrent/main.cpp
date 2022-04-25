#include <QCoreApplication>

#include <QDebug>
#include <QtConcurrent/QtConcurrent>

// Qt Concurrent
// Add QT += concurrent in .pro file

int do_map (int value) {
    qInfo() << "Do stuff: " << value;
    int num = value * 10;

    return num;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QList<int> values;
    for (int var = 0; var < 9; ++var) {
        values << var;
    }

    qInfo() << "Starting blocked";
    QList<int> updated = QtConcurrent::blockingMapped(values, &do_map);

    qInfo() << updated;
    qInfo() << "Finished";

    return a.exec();
}
