#ifndef PRODUCTREPOSITORYEXPIREDETAILS_H
#define PRODUCTREPOSITORYEXPIREDETAILS_H

#include <QObject>

class ProductRepositoryExpireDetails : public QObject
{
    Q_OBJECT
public:
    explicit ProductRepositoryExpireDetails(QObject *parent = nullptr);

private:
    bool isExpired;
    long daysLeft;
    long difference;

signals:

};

#endif // PRODUCTREPOSITORYEXPIREDETAILS_H
