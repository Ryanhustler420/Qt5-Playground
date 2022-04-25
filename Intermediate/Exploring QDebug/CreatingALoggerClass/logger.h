#ifndef LOGGER_H
#define LOGGER_H

#include <QDateTime>
#include <QObject>
#include <QDebug>
#include <QFile>

#include <QDir>
#include <iostream>

class logger
{
public:
    logger();
    explicit logger(QObject *parent = nullptr);

    static bool logging;
    static QString filename;

    static void attach();
    static void handler(QtMsgType type, const QMessageLogContext &context, const QString &msg);

};

#endif // LOGGER_H
