#include <QCoreApplication>
#include <QFuture>
#include <QtConcurrent>
#include "commandline.h"
#include "chat.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    CommandLine cli(&a,stdin);
    QFuture<void> future = QtConcurrent::run(&cli,&CommandLine::monitor);

    Chat chat;

    QObject::connect(&cli,&CommandLine::command,&chat,&Chat::command,Qt::QueuedConnection);

    qInfo() << "Enter your name to begin:";

    return a.exec();
}
