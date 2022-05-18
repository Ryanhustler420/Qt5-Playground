#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QDebug>

class Server : public QObject
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = nullptr);

signals:
    void response(QList<QString> v);

public slots:
    void fetchData();

};

#endif // SERVER_H
