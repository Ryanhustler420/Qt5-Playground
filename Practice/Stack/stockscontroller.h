#ifndef STOCKSCONTROLLER_H
#define STOCKSCONTROLLER_H

#include <QObject>

class StocksController : public QObject
{
    Q_OBJECT
public:
    explicit StocksController(QObject *parent = nullptr);

signals:

};

#endif // STOCKSCONTROLLER_H
