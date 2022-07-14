#include "filesystembroadcaster.h"

FileSystemBroadcaster::FileSystemBroadcaster(QObject *parent) : QObject(parent)
{
    fsw.addPath(QDir::currentPath());
    fsw.addPath(QDir::currentPath() + QDir::separator() + "test.txt");

    connect(&fsw, &QFileSystemWatcher::fileChanged, this, &FileSystemBroadcaster::fileChanged);
    connect(&fsw, &QFileSystemWatcher::directoryChanged, this, &FileSystemBroadcaster::directoryChanged);
}

void FileSystemBroadcaster::fileChanged(const QString &path)
{
    qInfo() << "File changed: " << path;
    if (fsw.files().length()) {
        qInfo() << "Files that have changed:";
        foreach (QString file, fsw.files()) {
            qInfo() << file;
        }
    }
}

void FileSystemBroadcaster::directoryChanged(const QString &path)
{
    qInfo() << "Directory changed: " << path;
    if (fsw.directories().length()) {
        qInfo() << "Directories that have changed:";
        foreach (QString dir, fsw.directories()) {
            qInfo() << dir;
        }
    }
}
