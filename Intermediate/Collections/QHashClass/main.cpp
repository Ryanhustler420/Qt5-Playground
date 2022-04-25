#include <QCoreApplication>

// QHash - QHash<Key, V> is one of Qt's generic container classes.
// It stores (key, value) pairs and provides very fast lookup of the value associated with a key.

// Works great with static info that wont change much

#include <QHash>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QHash<QString, int> ages;
    ages.insert("Gaurav", 23);
    ages.insert("Saurav", 25);
    ages.insert("Sangeeta", 21);
    ages.insert("Sarita", 28);
    ages.insert("Random", 18);

    qInfo() << "Gaurav is " << ages["Gaurav"] << " years old";

    qInfo() << "Total Size: " << ages.size();
    for (QString key : ages.keys()) {
           qInfo() << key << " = " << ages[key];
    }

    return a.exec();
}
