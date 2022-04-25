#include <QCoreApplication>
#include <QFileInfoList>
#include <QFileInfo>
#include <QDateTime>
#include <QDebug>
#include <QDir>

void list (QString path) {
    qInfo() << "Listing: " << path;

    QDir dir(path);
    qInfo() << dir.absolutePath();

    QFileInfoList dirs = dir.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot);
    QFileInfoList files = dir.entryInfoList(QDir::Files);

    foreach (QFileInfo fi, dirs) {
        qInfo() << fi.fileName();
    }

    foreach (QFileInfo fi, files) {
        qInfo() << "..Name: " << fi.fileName();
        qInfo() << "...Size: " << fi.size();
        qInfo() << "...Created: " << fi.birthTime();
        qInfo() << "...Modified: " << fi.lastModified();
    }

    foreach (QFileInfo fi, files) {
        list(fi.absoluteFilePath());
    }

}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    list(QDir::tempPath());

    return a.exec();
}
