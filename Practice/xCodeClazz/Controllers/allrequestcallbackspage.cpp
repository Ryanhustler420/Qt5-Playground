#include "controllers/allrequestcallbackspage.h"

AllRequestCallbacksPage::AllRequestCallbacksPage(QObject *parent) : QObject(parent)
{
}

void AllRequestCallbacksPage::hold(QVariant o)
{

}

void AllRequestCallbacksPage::loadCallbackRequests()
{
    if (xdb.getCallbackRequests().isEmpty()) {
        if (Manager::instance().getIsInternetPresent()) {
            emit showLoading(true);
            apis.getRequestCallbacks([=](QByteArray response){
                QList<CallbackRequest *> list = (new CallbackRequest())->parseJSONArray(QJsonDocument::fromJson(response).object().value("callbacks").toArray());

                QJsonArray arr;
                for (int var = 0; var < list.size(); ++var) arr.push_back(list.at(var)->getAsJson());

                // update the local file
                xdb.saveCallbackRequests(arr);

                emit callbackRequestsLoaded(arr.toVariantList());
                emit showLoading(false);
            }, [=](QByteArray error){
                qInfo() << error;
                emit showLoading(false);
            });
        } else {
            qInfo() << "No internet connection";
            emit showLoading(false);
        }
    } else {
        if (Manager::instance().getIsInternetPresent()) {
            apis.getRequestCallbacks([=](QByteArray response){
                QList<CallbackRequest *> list = (new CallbackRequest())->parseJSONArray(QJsonDocument::fromJson(response).object().value("callbacks").toArray());

                QJsonArray arr;
                for (int var = 0; var < list.size(); ++var) arr.push_back(list.at(var)->getAsJson());

                // update the local file
                xdb.saveCallbackRequests(arr);

            }, [=](QByteArray error){
                qInfo() << error;
            });
        } else {
            qInfo() << "No internet connection";
        }
        // render those and fetch new request
        emit callbackRequestsLoaded(xdb.getCallbackRequests().toVariantList());
    }

    // wire delete and accept callback
    // show loading / hide loading when operation performed
    // clean the code as well
    // task to be done,
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
