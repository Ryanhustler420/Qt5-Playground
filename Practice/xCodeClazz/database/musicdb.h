#ifndef MUSICDB_H
#define MUSICDB_H

#include "database/sqlite3.h"

static const QString path = "C:/Users/Raisehand/Desktop/musicdb.db";
class MusicDB : public Sqlite3
{
    Q_OBJECT
public:
    explicit MusicDB(CommonSuperClass *parent = nullptr);
    ~MusicDB();

    void readAllMusics(const QString &tableName);
    bool createMusicListTable(const QString &tableName);
    bool createSettingsTable(const QString &tableName);
    bool insertMusic(const QString &tableName,const QString &name, const QString &path, const int &lenghtAsSecond, const QString &lenghtToShow);
    bool removeMusic(const int &musicId);
    bool updateMusicDuration(const int &musicId , const int &lenghtAsSecond , const QString &lenghtToShow);

public:
    QString tableNamesMusicList = "tblMusicList";
    QString tableNamesSettings = "tblSettings";
    void dropMusicListTable();
    void dropNamesSettingsTable();

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
    // Sqlite3 interface
public:
    void init();
    void insertDummy();

private:
    TablesAndColumns *allTables;
};

#endif // MUSICDB_H
