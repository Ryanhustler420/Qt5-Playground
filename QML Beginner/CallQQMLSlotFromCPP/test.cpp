#include "test.h"

Test::Test(QObject *parent) : QObject(parent)
{
    connect(&mTimer, &QTimer::timeout, this, &Test::timeout);
    mTimer.setInterval(1000);
    mDisplay = "Starting";
    qInfo() << mDisplay;
    emit notice(QVariant(mDisplay));
}

void Test::timeout()
{
    mDisplay = QDateTime::currentDateTime().toString();
    qInfo() << mDisplay;
    emit notice(QVariant(mDisplay));
}

void Test::start()
{
    mDisplay = "Starting...";
    qInfo() << mDisplay;
    emit notice(QVariant(mDisplay));
    mTimer.start();
}

void Test::stop()
{
    mTimer.stop();
    mDisplay = "Stopping...";
    qInfo() << mDisplay;
    emit notice(QVariant(mDisplay));
}
