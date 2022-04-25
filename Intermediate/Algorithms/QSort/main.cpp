#include <QCoreApplication>
#include <QVector>
#include <QDebug>
#include <QRandomGenerator>

// qSort

void randoms(QVector<int> *list, int max) {
    list->reserve(max);
    for (int var = 0; var < max; ++var) {
        int value = QRandomGenerator::global()->bounded(1000);
        list->append(value);
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QVector<int> list;
    randoms(&list, 10);

    qInfo() << "Unsorted: " << list;

    // qSort(list); // depriciated dont use it

    std::sort(list.begin(), list.end());
    qInfo() << "Sorted: " << list;

    return a.exec();
}
