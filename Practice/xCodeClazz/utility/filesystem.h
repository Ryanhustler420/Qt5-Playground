#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include "parents/commonsuperclass.h"

#include <QRandomGenerator>
#include <QFileInfoList>
#include <QStorageInfo>
#include <QDataStream>
#include <QFileInfo>
#include <QLockFile>
#include <QDateTime>
#include <QIODevice>
#include <QBuffer>
#include <QFile>
#include <QDir>

class FileSystem : public CommonSuperClass
{
public:
    explicit FileSystem(CommonSuperClass *parent = nullptr);
    FileSystem(const QString &currentPath);

    QFileInfoList getFilesInfo(const QString &path);
    QList<QStorageInfo> getSystemStorageDetails();
    QFileInfo getFileInfo(const QString &path);
    QList<QFileInfo> getFilesInsideDir(QDir dir);
    QChar path_separator();

    QString getCurrentPath();
    QString getCurrentPath(const QString &file_name);
    void setCurrentPath(const QString &path);

    QDir *getDir(const QString &path);

    bool write(QByteArray data, const QString &file_name);
    bool append(QByteArray data, const QString &file_name);

    bool deleteFile(const QString &file_name);
    QByteArray read(const QString &file_name);
    QByteArray readSmallFile(const QString &file_name);
    QByteArray readBytes(const QString &file_name, int bytesToRead);

    bool writeDataStream(QByteArray &data, QString &file_name);
    QByteArray readDataStream(QString &file_name);

    bool writeTextStream(QByteArray &data, QString &file_name);
    QByteArray readTextStream(QString &file_name);

    QByteArray readFromBuffer();
    bool writeIntoBuffer(const QByteArray &data);

    void deadLock(const QString &file_name, std::function<void (bool hasLocked)> callback);
    bool fileExist(const QString &file_name);
    QFile* getFile(const QString &file_name, QIODevice::OpenModeFlag io);
    QFile* getFile(const QString &file_name, QIODevice::OpenMode io);

    bool createDir(const QString &path);
    bool renameDir(const QString &path, const QString &newName);
    bool removeDir(const QString &path, bool recursiveDelete);
    bool existDir(const QString &path, bool createNew);

signals:

private:
    bool put (const QString &file_name, QByteArray data, QIODevice::OpenMode mode);
    QBuffer buffer;
    QString currentPath;
};

#endif // FILESYSTEM_H
