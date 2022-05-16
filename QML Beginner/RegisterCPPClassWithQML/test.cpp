#include "test.h"

Test::Test(QObject *parent) : QObject(parent)
{

}

void Test::work(QVariant data)
{
    bool ok;
    int numIn = data.toInt(&ok);
    int numOut = 0;

    if (!ok) {
        qWarning() << "Not a valid number";
    } else {
        int numRandam = QRandomGenerator::global()->bounded(100);
        numOut = numIn * numRandam;
        qInfo() << "In: " << numIn;
        qInfo() << "Random: " << numRandam;
        qInfo() << "Out: " << numOut;
    }

    emit status(QVariant(numOut));
}
