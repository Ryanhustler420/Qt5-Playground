#ifndef SQLITE3_H
#define SQLITE3_H

#include "parents/commonsuperclass.h"

#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QSqlDatabase>
#include <QSqlQueryModel>

// NOTE: If you want to change anything in the table. first drop existing table else you won't be able to modify anything
// An error message "paramiter count mismatch" will trigger. that simply means you have not droped your old table schema, that's schema missmatch nothing else

class Sqlite3 : public CommonSuperClass
{
public:
    explicit Sqlite3(CommonSuperClass *parent = nullptr);

    bool isOpen() const
    {
        return m_db.isOpen();
    };
    bool dropTable(const QString &tableName)
    {
        QSqlQuery query;
        query.prepare("DROP TABLE " + tableName);
        return query.exec();
    };
    QString quotesql(const QString& s)
    {
        return QString("'") + s + QString("'");
    };
    virtual void init() = 0;
    virtual void insertDummy() = 0;

signals:

protected:
    QSqlDatabase m_db;
};

#endif // SQLITE3_H
