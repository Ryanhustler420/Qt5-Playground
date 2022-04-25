#include <QCoreApplication>
#include <QDebug>
#include "test.h"
#include "converter.h"

void writeJson(QString path) {
    test t;
    t.fill();
    converter::writeJson(&t, path);
}

void readJson(QString path) {
    test *t;
    t = converter::readJson(path);

    if (!t) {
        qInfo() << "Object not loaded";
        return;
    }

    qInfo() << "Name: " << t->name();
    foreach (QString key, t->map().keys()) {
        qInfo() << key << " : " << t->map().value(key);
    }
}

void writeXml(QString path) {
    test t;
    t.fill();
    converter::writeXml(&t, path);
}

void readXml(QString path) {
    test *t;
    t = converter::readXml(path);

    if (!t) {
        qInfo() << "Object not loaded";
        return;
    }

    qInfo() << "Name: " << t->name();
    foreach (QString key, t->map().keys()) {
        qInfo() << key << " : " << t->map().value(key);
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString json_path = "json_test.txt";
    QString xml_path = "xml_test.txt";

    writeJson(json_path);
    readJson(json_path);

    writeXml(xml_path);
    readXml(xml_path);

    return a.exec();
}
