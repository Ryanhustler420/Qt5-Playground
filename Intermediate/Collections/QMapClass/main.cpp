#include <QCoreApplication>

// The QMap class is a template class that provides a red-black-tree-based dictionary.

// QMap<Key, T> is one of Qt's generic container classes.
// It stores (key, value) pairs and provides fast lookup of the value associated with a key.

// Has fast look up

#include <QMap>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QMap<QString, int> ages;
    ages.insert("Gaurav", 546);
    ages.insert("Saurav", 546);
    ages.insert("Sangeeta", 546);
    ages.insert("Sarita", 546);

    // Ordered based on Red-Black-Tree, - a little slower
    qInfo() << "Gaurav is " << ages["Gaurav"] << " years old";
    qInfo() << "keys: " << ages.keys();
    for (QString key : ages.keys()) {
        qInfo() << key << " - " << ages[key];
    }

    return a.exec();
}
