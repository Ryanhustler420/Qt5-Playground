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

    void qBuffer();
    void qDataStream();
    void qDir();
    void qLock();
    void qStorageInfo();

private:
    void listFileDetails (QString path);

    bool createFileDataStream(QString path);
    void readFileDataStream(QString path);

    bool createFileTextStream(QString path);
    void readFileTextStream(QString path);

    QString getCurrentPath();
    QString getCurrentPath(QString filename);

    bool put (QString path, QByteArray data, QIODevice::OpenMode mode);
    void write(QString path, QByteArray data);
    bool write2(QString path, QByteArray data);
    void append(QString path, QByteArray data);

    bool createFile2(QString path);
    void readSmallFile(QString path);
    void readLargeFileByLines(QString path);
    void readLargeFileByBytes(QString path);

    void printFilesInsideDir(QDir dir);
    bool createDir(QString path);
    bool rename(QString path, QString name);
    bool remove(QString path);

    QLockFile * createLockFile(QFile* path);
    QFile* getFile(QString path, QIODevice::OpenModeFlag io);
    QFile* getFile(QString path, QIODevice::OpenMode io);

    QDir* getDir(QString path);

    bool fileExist(QString path);
    bool dirExist(QString path);
    bool dirExist(QString path, bool createNew);
    bool dirRemoved(QString path, bool recursiveDelete);

signals:

};

#endif // FILESYSTEM_H
