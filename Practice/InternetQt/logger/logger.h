#ifndef LOGGER_H
#define LOGGER_H

#include <QDateTime>
#include <QObject>
#include <QDebug>
#include <QFile>

#include <QDir>
#include <iostream>

// #include <QLoggingCategory>
// Declare a loggin category
// Q_DECLARE_LOGGING_CATEGORY(network);
// Q_LOGGING_CATEGORY(network, "network"); // macros
// ;use this like, qInfo(network), qDebug(network) << "yes!";, qDebug(network) << "kitty";

class Logger : public QObject
{
public:
    Logger();
    explicit Logger(QObject *parent = nullptr);

    static void attach();
    static void handler(QtMsgType type, const QMessageLogContext &context, const QString &msg);

    static void setPath(QString path, QString name);
    static QString getPath();

public:
    static bool logging;
    static bool dirty_console;
private:
    static QString filename;
    static QString filepath;

};

#endif // LOGGER_H
