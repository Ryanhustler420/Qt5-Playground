#include <QCoreApplication>
#include <QDebug>
#include <QLoggingCategory>

// Declare a loggin category
Q_DECLARE_LOGGING_CATEGORY(network);
Q_LOGGING_CATEGORY(network, "network"); // macros

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qInfo() << "test";
    qInfo(network) << "test";

    // turn it off
    QLoggingCategory::setFilterRules("network.debug=false");

    // will not log
    qDebug(network) << "kitty";

    if (!network().isDebugEnabled()) {
        // turn it on
        QLoggingCategory::setFilterRules("network.debug=true");
        qDebug(network) << "we turned it back!";
    }

    qDebug(network) << "yes!";

    return a.exec();
}
