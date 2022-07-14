#include "jsonhelper.h"

JsonHelper::JsonHelper(CommonSuperClass *parent) : CommonSuperClass(parent)
{

}

QJsonArray JsonHelper::toJsonArray(QJsonObject jsonObject, QString key)
{
    return jsonObject.value(key).toArray();
}

QJsonArray JsonHelper::toJsonArray(QByteArray *byteArray, QString key)
{
    return JsonHelper::toJsonDocument(byteArray).object().value(key).toArray();
}

QJsonDocument JsonHelper::toJsonDocument(QByteArray *byteArray)
{
    return QJsonDocument::fromJson(*byteArray);
}

QJsonObject JsonHelper::toJsonObject(QJsonDocument jsonDocument, QString key)
{
    return jsonDocument.object().value(key).toObject();
}

QString JsonHelper::toString(QJsonDocument jsonDocument, QString key)
{
    return jsonDocument.object().value(key).toString();
}

QJsonObject JsonHelper::toJson(QString in)
{
    QJsonValue val(in);
    return val.toObject();
}

QJsonArray JsonHelper::toJsonArray(QList<QString> *arr)
{
    QJsonArray array;
    for (int var = 0; var < arr->size(); ++var) {
        array.push_back(arr->at(var));
    }
    return array;
}

QJsonDocument JsonHelper::createDummyJSON()
{
    // create main object for whole json data
    QJsonObject mainObject;

    // insert single datas first
    mainObject.insert("name", "Anjali Gupta");
    mainObject.insert("surname", "Gupta");
    mainObject.insert("age", 24);

    // create an object for inner object of main object
    QJsonObject address;
    address.insert("city", "Istanbul");
    address.insert("country", "TURKEY");
    // insert the inner json object inside main object
    mainObject.insert("address", address);

    // create a json array for main jsonobject
    QJsonArray phones;
    phones.push_back("0555555555");
    phones.push_back("01111111111");

    // we added JSON array into our main json object
    mainObject.insert("phone", phones);

    // lastly we created a JSON document and set mainObject as object of document
    QJsonDocument jsonDoc;
    jsonDoc.setObject(mainObject);

    return jsonDoc;
}

QString JsonHelper::parseDummpyJSON()
{
    QByteArray jsonData = "{\"name\": \"Burak Hamdi\", \"surname\": \"TUFAN\", \"age\": 26, \"address\": { \"city\": \"Istanbul\", \"country\": \"TURKEY\" }, \"phone\": [\"0555555555\", \"01111111111\"] }";

    // Assign the json text to a JSON object
    QJsonDocument jsonDocument = QJsonDocument::fromJson(jsonData);
    if(jsonDocument.isObject() == false) qDebug() << "It is not a JSON object";

    // Then get the main JSON object and get the datas in it
    QJsonObject object = jsonDocument.object();

    // Access the sibgle values
    QJsonValue name = object.value("name");
    QJsonValue surname = object.value("surname");
    QJsonValue age = object.value("age"); // this value is integer

    // Access the inner JSON object and its inside data. objects will be within { } curly braces
    QJsonObject address = object.value("address").toObject();
    QJsonValue addr_city = address.value("city");
    QJsonValue addr_country = address.value("country");

    // Access the array within the JSON object. arrays will be within [ ] squared braces
    QJsonArray phones = object.value("phone").toArray();
    qDebug() << "There are " + QString::number(phones.size()) + " items in phones array";
    QString phoneList = "";
    for(int i=0; i < phones.size(); i++ ) phoneList.append(phones.at(i).toString() + "\n");

    QString decodedData = "";

    decodedData.append("Name : " + name.toString() + "\n");
    decodedData.append("Surname : " + surname.toString() + "\n");
    decodedData.append("Age : " + QString::number(age.toInt()) + "\n");

    decodedData.append("Address : \n");
    decodedData.append("-City : " + addr_city.toString() + "\n");
    decodedData.append("-Country : " + addr_country.toString() + "\n");

    decodedData.append("Phones : \n" + phoneList + "\n");

    if(name.isString() == true) qDebug() << "name is a string";
    qDebug() << "Firstname : " + name.toString();

    return decodedData;
}
