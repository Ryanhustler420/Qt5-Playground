#include "controllers/allrequestcallbackspage.h"

AllRequestCallbacksPage::AllRequestCallbacksPage(QObject *parent) : QObject(parent)
{
}

void AllRequestCallbacksPage::pass(QVariant o)
{

}

void AllRequestCallbacksPage::loadCallbackRequests()
{
    if (!xdb.callbackRequest_file() || xdb.getCallbackRequests().isEmpty()) {
        if (Manager::instance().getIsInternetPresent()) {
            emit showLoading(true);
            apis.getRequestCallbacks([=](QByteArray response){
                QList<CallbackRequest *> list = (new CallbackRequest())->parseJSONArray(QJsonDocument::fromJson(response).object().value("callbacks").toArray());

                QJsonArray arr;
                for (int var = 0; var < list.size(); ++var) {
                    if (list.at(var)->getALTcourse()) {
                        arr.push_back(list.at(var)->getAsJson());
                    }
                }

                xdb.saveCallbackRequests(arr);
                callbacks.append(arr.toVariantList());

                emit callbackRequestsLoaded(arr.toVariantList());
                emit showLoading(false);
            }, [=](QByteArray error){
                qInfo() << error;
                emit showLoading(false);
            });
        } else {
            emit showLoading(false);
        }
    } else {
        if (Manager::instance().getIsInternetPresent()) {
            apis.getRequestCallbacks([=](QByteArray response){
                QList<CallbackRequest *> list = (new CallbackRequest())->parseJSONArray(QJsonDocument::fromJson(response).object().value("callbacks").toArray());

                QJsonArray arr;
                for (int var = 0; var < list.size(); ++var) {
                    if (list.at(var)->getALTcourse()) {
                        arr.push_back(list.at(var)->getAsJson());
                    }
                }

                xdb.saveCallbackRequests(arr);

            }, [=](QByteArray error){
                qInfo() << error;
            });
        } else {
        }
        callbacks.append(xdb.getCallbackRequests().toVariantList());
        emit callbackRequestsLoaded(xdb.getCallbackRequests().toVariantList());
    }
}

void AllRequestCallbacksPage::addNewItem(QVariant object)
{
    callbacks.append(object);
    emit newItemAdded(object, callbacks);
}

void AllRequestCallbacksPage::removeItem(int currentIndx)
{
    if (currentIndx > -1) {
        QVariant v = callbacks.at(currentIndx);
        QString _id = v.toJsonObject().value("_id").toString();
        emit showLoading(true);
        apis.callbackRequestDelete(_id, [=](QByteArray response){
            QJsonObject o = QJsonDocument::fromJson(response).object();
            if (xdb.deleteCallbackRequest(_id)){
                callbacks.removeAt(currentIndx);
                emit showLoading(false);
                emit itemRemoved(currentIndx, callbacks);
            }
        }, [=](QByteArray error){
            emit showLoading(false);
            qInfo() << error;
        });
    }
}

void AllRequestCallbacksPage::acceptItem(int currentIndx)
{
    if (currentIndx > -1) {
        QVariant v = callbacks.at(currentIndx);
        QString _id = v.toJsonObject().value("_id").toString();
        emit showLoading(true);
        apis.callbackRequestDelete(_id, [=](QByteArray response){
            QJsonObject o = QJsonDocument::fromJson(response).object();
            if (xdb.deleteCallbackRequest(_id)){
                callbacks.removeAt(currentIndx);
                emit showLoading(false);
                emit itemRemoved(currentIndx, callbacks);
            }
        }, [=](QByteArray error){
            emit showLoading(false);
            qInfo() << error;
        });
    }
}

QVariant AllRequestCallbacksPage::get(int i)
{
    return callbacks.at(i);
}

void AllRequestCallbacksPage::removeAll()
{
    emit showLoading(true);
    apis.callbackRequestDeleteAll([=](QByteArray response){
        QJsonObject o = QJsonDocument::fromJson(response).object();
        if (xdb.deleteStudents()) {
            callbacks.clear();
            emit allItemRemoved();
            emit showLoading(false);
        }
    }, [=](QByteArray error){
        emit showLoading(false);
        qInfo() << error;
    });
}

void AllRequestCallbacksPage::listViewReachedBottom(QVariant o)
{
    emit listViewReached(o);
}

void AllRequestCallbacksPage::scrollViewReachedBottom(QVariant o)
{
    emit scrollViewReached(o);
}
