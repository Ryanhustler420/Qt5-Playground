#include "sqlite3.h"

Sqlite3::Sqlite3(CommonSuperClass *parent) : CommonSuperClass(parent)
{

}

Sqlite3::Sqlite3(const QString &path)
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName(path);
    allTables = new TablesAndColumns();

    if (!m_db.open())
        qDebug() << "Error: connection with database fail";
    else
        qDebug() << "Database: connection ok";
}

Sqlite3::~Sqlite3()
{
    if (m_db.isOpen())
        m_db.close();
}

bool Sqlite3::isOpen() const
{
    return m_db.isOpen();
}

void Sqlite3::readAllMusics(const QString &tableName)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM " + tableName);
    if (!query.exec()) {
        qInfo() << "Something went wrong";
    } else {
        // qInfo() << query.seek(63);

        while(query.next())  {
            QString value = query.value(allTables->_tableMusic.name).toString();
            if (!value.contains("SD")) {
                // continue;
                qInfo() << query.value(allTables->_tableMusic.name);
            }
        }
    }
}

bool Sqlite3::createMusicListTable(const QString &tableName)
{
    bool success = true;
    QSqlQuery query;
    query.prepare("CREATE TABLE " + tableName + "("
                  + allTables->_tableMusic.id       + " INTEGER PRIMARY KEY AUTOINCREMENT, "
                  + allTables->_tableMusic.name     + " TEXT, "
                  + allTables->_tableMusic.path     + " TEXT, "
                  + allTables->_tableMusic.lenghtAsSecond   + " INTEGER, "
                  + allTables->_tableMusic.lenghtToShow + " TEXT );");

    if (!query.exec())
    {
        qDebug() << "Music list table already created ";
        success = false;
    }
    return success;
}

bool Sqlite3::createSettingsTable(const QString &tableName)
{
    Q_UNUSED(tableName);
    return false;
}

bool Sqlite3::insertMusic(const QString &tableName, const QString &name, const QString &path, const int &lenghtAsSecond, const QString &lenghtToShow)
{
    bool success = false;
    if (!name.isEmpty())
    {
        QSqlQuery queryAdd;
        queryAdd.prepare("INSERT INTO " + tableName + " (name,path,lenghtAsSecond,lenghtToShow) VALUES (:name,:path,:lenghtAsSecond,:lenghtToShow)");
        queryAdd.bindValue(":name", quotesql(name));
        queryAdd.bindValue(":path", quotesql(path));
        queryAdd.bindValue(":lenghtAsSecond", lenghtAsSecond);
        queryAdd.bindValue(":lenghtToShow", quotesql(lenghtToShow));

        if(queryAdd.exec())
            success = true;
        else
            qDebug() << "record could not add: " << queryAdd.lastError();
    }
    else
        qDebug() << "Data is required to insert.";

    return success;
}

bool Sqlite3::removeMusic(const int &musicId)
{
    bool success = false;
    if (musicId > -1)
    {
        QSqlQuery queryDelete;
        queryDelete.prepare("DELETE FROM " + tableNamesMusicList + " WHERE id=" + QString::number(musicId) );
        success = queryDelete.exec();

        if(!success)
            qDebug() << "Record has been deleted: " << queryDelete.lastError();
    }
    else
        qDebug() << "Record has not been deleted";
    return success;
}

bool Sqlite3::updateMusicDuration(const int &musicId, const int &lenghtAsSecond, QString &lenghtToShow)
{
    bool success = false;
    if (musicId > -1)
    {
        QSqlQuery queryAdd;
        queryAdd.prepare("UPDATE " + tableNamesMusicList + " SET lenghtAsSecond=:lenghtAsSecond, lenghtToShow=:lenghtToShow where id=:id");
        queryAdd.bindValue(":lenghtAsSecond", quotesql(QString::number(lenghtAsSecond)));
        queryAdd.bindValue(":id", quotesql(QString::number(musicId)));
        queryAdd.bindValue(":lenghtToShow", quotesql(lenghtToShow));

        if(queryAdd.exec())
            success = true;
        else
            qDebug() << "Music could not be added: " << queryAdd.lastError();
    }
    else
        qDebug() << "Music ID is required to update...";
    return success;
}

bool Sqlite3::dropTable(const QString &tableName)
{
    QSqlQuery query;
    query.prepare("DROP TABLE " + tableName);
    return query.exec();
}
