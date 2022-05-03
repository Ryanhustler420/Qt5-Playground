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
    Sqlite3(const QString &path);
    ~Sqlite3();

    bool isOpen() const;
    void readAllMusics(const QString &tableName);
    bool createMusicListTable(const QString &tableName);
    bool createSettingsTable(const QString &tableName);
    bool insertMusic(const QString &tableName,const QString &name, const QString &path, const int &lenghtAsSecond, const QString &lenghtToShow);
    bool removeMusic(const int &musicId);
    bool updateMusicDuration(const int &musicId , const int &lenghtAsSecond , QString &lenghtToShow);

    bool dropTable(const QString &tableName);

private:
    QString quotesql(const QString& s) {
        return QString("'") + s + QString("'");
    }

public:
    QString tableNamesMusicList = "tblMusicList";
    QString tableNamesSettings = "tblSettings";

    typedef struct TABLE {
        QString id = "id";
        QString current_index = "current_index";
        QString selected_index = "selected_index";
        QString repeatSingle = "repeatSingle";
        QString repeatAll = "repeatAll";
        QString shuffle = "shuffle";
        QString volume = "volume";
    } table_settings ;

    typedef struct MUSIC {
        QString id = "id";
        QString name = "name";
        QString path = "path";
        QString lenghtToShow = "lenghtToShow";
        QString lenghtAsSecond = "lenghtAsSecond";
    } table_music;

    /**
     * @brief List of table and column names which created above
     */
    struct TablesAndColumns {
        table_settings _tableSettings;
        table_music _tableMusic;
    };

signals:

private:
    QSqlDatabase m_db;
    TablesAndColumns *allTables;
};

#endif // SQLITE3_H
