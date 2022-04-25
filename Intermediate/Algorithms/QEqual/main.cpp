#include <QCoreApplication>
#include <QVector>
#include <QDebug>
#include <QRandomGenerator>

void randoms(QVector<int> *list, int max) {
    list->reserve(max);

    for (int var = 0; var < max; ++var) {
        int value = QRandomGenerator::global()->bounded(100);
        list->append(value);
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QVector<int> list1;
    randoms(&list1, 10);

    QVector<int> list2;
    randoms(&list2, 10);

    qInfo() << list1;
    qInfo() << list2;

    // qInfo() << "Equal: " << qEqual(list1.begin(), list1.end(), list2.begin()); // depriciated
    // qCopy(list1.begin(), list1.end(), list2.begin()); // depricated
    // qInfo() << "Equal: " << qEqual(list1.begin(), list1.end(), list2.begin()); // depriciated

    qInfo() << "Equal: " << std::equal(list1.begin(), list1.end(), list2.begin()); // find
    std::copy(list1.begin(), list1.end(), list2.begin()); // fine
    qInfo() << "Equal: " << std::equal(list1.begin(), list1.end(), list2.begin()); // find

    return a.exec();
}
