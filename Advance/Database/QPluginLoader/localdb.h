#ifndef LOCALDB_H
#define LOCALDB_H

#include <QDebug>
#include <QObject>
#include <QSqlError>
#include <QSqlDriver>
#include <QSqlDatabase>
#include <QSqlQuery>

const QString DRIVER("QSQLITE");

class LocalDB : public QObject
{
    Q_OBJECT
public:
    explicit LocalDB(QObject *parent = nullptr);

signals:

public:
    void DatabaseConnect();
    void DatabaseInit();
    void DatabasePopulate();
    void search();

};

#endif // LOCALDB_H
