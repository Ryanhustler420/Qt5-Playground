#include "localdb.h"

LocalDB::LocalDB(QObject *parent) : QObject(parent)
{
    this->DatabaseConnect();
    this->DatabaseInit();
    this->DatabasePopulate();
}

void LocalDB::DatabaseConnect()
{
    if(QSqlDatabase::isDriverAvailable(DRIVER))
    {
        QSqlDatabase db = QSqlDatabase::addDatabase(DRIVER);
        db.setDatabaseName(":memory:");
        if(!db.open())
            qWarning() << "DatabaseConnect - ERROR: " << db.lastError().text();
    }
    else
    {
        qWarning() << "DatabaseConnect - ERROR: no driver " << DRIVER << " available";
    }
}

void LocalDB::DatabaseInit()
{
    QSqlQuery query("CREATE TABLE people (id INTEGER PRIMARY KEY, name TEXT)");
    if(!query.isActive())
        qWarning() << "DatabaseInit - ERROR: " << query.lastError().text();
}

void LocalDB::DatabasePopulate()
{
    QSqlQuery query;

    if(!query.exec("INSERT INTO people(name) VALUES('Eddie Guerrero')"))
        qWarning() << "DatabasePopulate - ERROR: " << query.lastError().text();
    if(!query.exec("INSERT INTO people(name) VALUES('Gordon Ramsay')"))
        qWarning() << "DatabasePopulate - ERROR: " << query.lastError().text();
    if(!query.exec("INSERT INTO people(name) VALUES('Alan Sugar')"))
        qWarning() << "DatabasePopulate - ERROR: " << query.lastError().text();
    if(!query.exec("INSERT INTO people(name) VALUES('Dana Scully')"))
        qWarning() << "DatabasePopulate - ERROR: " << query.lastError().text();
    if(!query.exec("INSERT INTO people(name) VALUES('Lila	Wolfe')"))
        qWarning() << "DatabasePopulate - ERROR: " << query.lastError().text();
    if(!query.exec("INSERT INTO people(name) VALUES('Ashley Williams')"))
        qWarning() << "DatabasePopulate - ERROR: " << query.lastError().text();
    if(!query.exec("INSERT INTO people(name) VALUES('Karen Bryant')"))
        qWarning() << "DatabasePopulate - ERROR: " << query.lastError().text();
    if(!query.exec("INSERT INTO people(name) VALUES('Jon Snow')"))
        qWarning() << "DatabasePopulate - ERROR: " << query.lastError().text();
    if(!query.exec("INSERT INTO people(name) VALUES('Linus Torvalds')"))
        qWarning() << "DatabasePopulate - ERROR: " << query.lastError().text();
    if(!query.exec("INSERT INTO people(name) VALUES('Hayley Moore')"))
        qWarning() << "DatabasePopulate - ERROR: " << query.lastError().text();
}

void LocalDB::search()
{
    QSqlQuery query;
    query.prepare("SELECT name FROM people WHERE id = ?");
    query.addBindValue(1);

    if(!query.exec())
        qWarning() << "OnSearchClicked - ERROR: " << query.lastError().text();

    if(query.first())
        qInfo() << query.value(0).toString();
    else
        qInfo("person not found");
}
