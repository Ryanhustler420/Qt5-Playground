#include "controllers/allrequestcallbackspage.h"

AllRequestCallbacksPage::AllRequestCallbacksPage(QObject *parent) : QObject(parent)
{
}

void AllRequestCallbacksPage::hold(QVariant o)
{

}

void AllRequestCallbacksPage::loadCallbackRequests()
{
    apis.getRequestCallbacks([=](QByteArray response){
        CallbackRequest *c = new CallbackRequest();
        QList<CallbackRequest *> list = c->parseJSONArray(QJsonDocument::fromJson(response).object().value("callbacks").toArray());
        QVariantList m_list = c->parseJSONArrayToVariantList(QJsonDocument::fromJson(response).object().value("callbacks").toArray());
        emit callbackRequestsLoaded(m_list);
    }, [=](QByteArray error){
        qInfo() << error;
    });
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
