#include <QCoreApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString build;

#ifdef QT_DEBUG
    build = "debug";
#else
    build = "release";
#endif

    qInfo() << "Current build: " << build;

    return a.exec();
}
