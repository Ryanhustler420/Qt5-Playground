#ifndef ALLREQUESTCALLBACKSPAGE_H
#define ALLREQUESTCALLBACKSPAGE_H

#include <QDebug>
#include <QObject>
#include <QVariant>
#include <QVariantList>

#include "utility/jsonhelper.h"
#include "networking/apis.h"

class AllRequestCallbacksPage : public QObject
{
    Q_OBJECT
public:
    explicit AllRequestCallbacksPage(QObject *parent = nullptr);

    Q_INVOKABLE void hold(QVariant o);
    Q_INVOKABLE void loadCallbackRequests();

    Q_INVOKABLE void addNewItem(QVariant object);
    Q_INVOKABLE void removeItem(int currentIndx);
    Q_INVOKABLE QVariant get(int i);
    Q_INVOKABLE void removeAll();

signals:
    void holded(QVariant o);
    void callbackRequestsLoaded(QVariantList callbacks);

    void newItemsAdded(QVariantList objects);
    void newItemAdded(QVariant object, QVariantList objects);
    void itemRemoved(int currentIndex, QVariantList objects);
    void allItemRemoved();

private:
    QVariantList callbacks;
    Apis apis;

};

#endif // ALLREQUESTCALLBACKSPAGE_H
