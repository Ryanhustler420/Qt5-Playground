#ifndef SERVER_H
#define SERVER_H

#include <QAbstractSocket>
#include <QTcpSocket>
#include <QTcpServer>
#include <QObject>
#include <QDebug>

class Server : public QObject
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = nullptr);

signals:

public slots:
    void start();
    void quit();
    void newConnection();
    void disconnected();
    void readyRead();

private:
    QTcpServer server;

};

#endif // SERVER_H
