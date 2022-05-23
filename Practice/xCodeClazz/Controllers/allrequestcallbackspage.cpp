#include "controllers/allrequestcallbackspage.h"

#include <QJsonDocument>
#include <QJsonObject>

AllRequestCallbacksPage::AllRequestCallbacksPage(QObject *parent) : QObject(parent)
{

}

void AllRequestCallbacksPage::addNewItem(QVariant object)
{
    callbacks.append(object);
    emit newItemAdded(object, callbacks);
}

void AllRequestCallbacksPage::removeItem(int currentIndx)
{
    if (currentIndx > -1) {
        callbacks.removeAt(currentIndx);
        emit itemRemoved(currentIndx, callbacks);
    }
}

QVariant AllRequestCallbacksPage::get(int i)
{
    return callbacks.at(i);
}

void AllRequestCallbacksPage::removeAll()
{
    callbacks.clear();
    emit allItemRemoved();
}

QVariantList AllRequestCallbacksPage::getAll()
{
    return callbacks;
}
