#include "application/manager.h"
#include "views/widget.h"

#include <QApplication>

#include "database/sqlite3.h"
static const QString path = "C:/Users/Raisehand/Desktop/TheMusicDataBase.db";

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // This is required to write
    QString env = Manager::instance().getCurrentEnv();
    qInfo() << "The application is running on " << env << " mode.";
    //    Sqlite3 db(path);
    //    if (db.isOpen())
    //    {
    //        //if not exist create the database tables.
    //        db.createMusicListTable(db.tableNamesMusicList);
    //        db.createSettingsTable(db.tableNamesSettings);
    //        qInfo() << "Database has been opened for operation";

    //        QString lenghtToShow = "05:20";
    //        db.insertMusic(db.tableNamesMusicList, "Lipstick Lage Lu", "c:/Users/TimeMAchine/dumps", 320, lenghtToShow);
    //        db.updateMusicDuration(1, 320, lenghtToShow);
    //        db.readAllMusics(db.tableNamesMusicList);
    //        // db.dropTable(db.tableNamesMusicList);

    //        // need a way to cache the auth token and make network call
    //        // create some way to intereact with db and read the data (watch youtube video)

    //    }
    //    else
    //    {
    //        qDebug() << "Database could not be opened!";
    //    }
    Widget w;
    w.show();

    return a.exec();
}
