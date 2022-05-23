#ifndef ALLREQUESTCALLBACKSPAGE_H
#define ALLREQUESTCALLBACKSPAGE_H

#include <QDebug>
#include <QObject>
#include <QVariant>
#include <QVariantList>

class AllRequestCallbacksPage : public QObject
{
    Q_OBJECT
public:
    explicit AllRequestCallbacksPage(QObject *parent = nullptr);

    Q_INVOKABLE void addNewItem(QVariant object);
    Q_INVOKABLE void removeItem(int currentIndx);
    Q_INVOKABLE QVariant get(int i);

    Q_INVOKABLE void removeAll();
    Q_INVOKABLE QVariantList getAll();

signals:
    void newItemAdded(QVariant object, QVariantList objects);
    void itemRemoved(int currentIndex, QVariantList objects);
    void allItemRemoved();

private:
    QVariantList callbacks;

};

#endif // ALLREQUESTCALLBACKSPAGE_H
