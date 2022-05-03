#ifndef FILESYSTEMBROADCASTER_H
#define FILESYSTEMBROADCASTER_H

#include <QObject>
#include <QFileSystemWatcher>
#include <QDebug>
#include <QDir>

class FileSystemBroadcaster : public QObject
{
    Q_OBJECT
public:
    explicit FileSystemBroadcaster(QObject *parent = nullptr);

    void fileChanged(const QString &path);
    void directoryChanged(const QString &path);

private:
    QFileSystemWatcher fsw;

signals:

};

#endif // FILESYSTEMBROADCASTER_H
