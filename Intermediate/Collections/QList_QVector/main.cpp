#include <QCoreApplication>
#include <QVector>
#include <QList>
#include <QDebug>

template<class T>
void fill(T &container) {
    for (int var = 0; var < 5; ++var) {
        container.append(var);
    }
}

template<class T>
void display(T &container) {
    for (int var = 0; var < container.length(); ++var) {
        if (var > 0) {
            auto current = reinterpret_cast<std::uintptr_t>(&container.at(var));
            auto previous = reinterpret_cast<std::uintptr_t>(&container.at(var - 1));
            auto distance = current - previous;
            qInfo() << var << "At: " << current << " Previous: " << previous << " Distance: " << distance;
        } else {
            qInfo() << var << &container.at(var) << "Distance: 0";
        }
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QVector<int> vect = QVector<int>();
    QList<int> list = QList<int>();

    fill(vect);
    fill(list);

    // Best in performace, because data kept in continues block, even if you got the first data ref. rest will be easy to find.
    qInfo() << "Int takes " << sizeof (int) << " bytes of ram";
    qInfo() << "QVector uses continous locations in memory!";
    display(vect);
    qInfo("");

    // Cpu intensive, because data spared all across the ram, and cpu needs to find that
    qInfo() << "QList uses what ever it can find in memory";
    display(list);
    qInfo("");

    return a.exec();
}














