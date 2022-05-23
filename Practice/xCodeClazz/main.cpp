#include "application.h"
#include "database/sqlite3.h"
#include "application/manager.h"

#include <QIcon>
static const QString path = "C:/Users/Raisehand/Desktop/TheMusicDataBase.db";

// ****************************************
// https://stackoverflow.com/questions/8834147/c-signal-to-qml-slot-in-qt
// ****************************************

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);
    app.setWindowIcon(QIcon(":/images/favicon.ico"));

    // Setting up the env configs
    QString env = Manager::instance().getCurrentEnv();
    qInfo() << "The application is running on " << env << " mode.";

    // This is required to write
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

    // App kicks in
    Application application;
    application.boot(app);

    return app.exec();
}
