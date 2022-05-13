#ifndef SHOPEXPIREDETAILS_H
#define SHOPEXPIREDETAILS_H

#include <QObject>

class ShopExpireDetails : public QObject
{
    Q_OBJECT
public:
    explicit ShopExpireDetails(QObject *parent = nullptr);

signals:

public:
    bool isExpired;
    long daysLeft;
    long difference;

};

#endif // SHOPEXPIREDETAILS_H
