#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QDebug>
#include <QTcpServer>
#include <QTcpSocket>
#include <QThreadPool>
#include <QThread>
#include "client.h"

class Server : public QTcpServer
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = nullptr);

signals:

public slots:
    void start(quint16 port);
    void quit();


    // QTcpServer interface
protected:
    // Not version friendly!!!
    virtual void incomingConnection(qintptr handle) Q_DECL_OVERRIDE;

private:
    QThreadPool pool;
};

#endif // SERVER_H
