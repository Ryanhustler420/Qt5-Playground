#include "controllers/allrequestcallbackspage.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>

AllRequestCallbacksPage::AllRequestCallbacksPage(QObject *parent) : QObject(parent)
{

}

void AllRequestCallbacksPage::ready()
{
    QVariantList l;
    l.append(QVariant("{ \"course\": \"Python Code For Beginner\", \"name\": \"Sikha Jha\", \"school\": \"KPS Kadma\", \"phone\": \"xxxxxxxxxx\" }"));
    l.append(QVariant("{ \"course\": \"C++ Code For Beginner\", \"name\": \"Vikram Pradhan\", \"school\": \"KPS Gamharia\", \"phone\": \"xxxxxxxxxx\" }"));
    l.append(QVariant("{ \"course\": \"Java Code For Beginne\", \"name\": \"Anjali Gupta\", \"school\": \"DAV Adityapur\", \"phone\": \"xxxxxxxxxx\" }"));
    l.append(QVariant("{ \"course\": \"NodeJs Code For Beginner\", \"name\": \"Mahesh Gupta\", \"school\": \"Xavier Gamharia\", \"phone\": \"xxxxxxxxxx\" }"));
    emit newItemsAdded(l);
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
