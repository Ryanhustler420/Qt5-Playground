#include "filesystem.h"

FileSystem::FileSystem(CommonSuperClass *parent) : CommonSuperClass(parent)
{

}

void FileSystem::qBuffer()
{

    QBuffer buffer;

    if(buffer.open(QIODevice::ReadWrite)) {
        QByteArray data("Hello World");
        buffer.write(data);
        // File and device access you may need to flush the data to the device
        // buffer.flush();

        // Move to the first position
        buffer.seek(0);
        qInfo() << buffer.readAll();

        // ALWAYS close your device:
        buffer.close();
    } else {
        qInfo() << "Could not open buffer";
    }

}

void FileSystem::listFileDetails(QString path)
{
    QDir *dir = getDir(path);
    qInfo() << dir->absolutePath();

    QFileInfoList dirs = dir->entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot);
    QFileInfoList files = dir->entryInfoList(QDir::Files);

    foreach (QFileInfo fi, dirs) { qInfo() << fi.fileName(); }
    foreach (QFileInfo fi, files) {
        qInfo() << "..Name: " << fi.fileName();
        qInfo() << "...Size: " << fi.size();
        qInfo() << "...Created: " << fi.birthTime();
        qInfo() << "...Modified: " << fi.lastModified();
    }

    foreach (QFileInfo fi, files) { listFileDetails(fi.absoluteFilePath()); }
}

bool FileSystem::createFileDataStream(QString path)
{
    QFile *file = getFile(path, QIODevice::WriteOnly);
    if (!file) return false;

    QDataStream stream(file);
    stream << "Random Number: "; // shifting the data into stream
    stream << QRandomGenerator::global()->bounded(1000); // shifting the data into stream
    file->close(); // we are not starting/closing stream because it doesn't have ending...
    return true;
}

void FileSystem::readFileDataStream(QString path)
{
    QFile *file = getFile(path, QIODevice::ReadOnly);
    if (!file) return;

    QDataStream stream(file);
    QString banner;
    stream >> banner; // reading from stream
    qint32 num;
    stream >> num; // reading from stream
    file->close();
}

bool FileSystem::createFileTextStream(QString path)
{
    QFile *file = getFile(path, QIODevice::WriteOnly);
    if (!file) return false;

    QTextStream stream(file);
    QString banner = "Random Number:\r\n";
    stream << banner; // shifting the data into stream;
    qint32 num = QRandomGenerator::global()->bounded(1000);
    stream << num << "\r\n";
    file->close(); // we are not starting/closing stream because it doesn't have ending...
    return true;
}

void FileSystem::readFileTextStream(QString path)
{
    QFile *file = getFile(path, QIODevice::ReadOnly);
    if (!file) return;

    QTextStream stream(file);
    QString banner;
    stream >> banner; // reading from stream
    QString num;
    stream >> num; // reading from stream
    file->close();
}

bool FileSystem::put(QString path, QByteArray data, QIODevice::OpenMode mode)
{
    QFile *file = getFile(path, mode);
    if (!file) return false;

    qint64 bytes = file->write(data);
    if (!bytes) qWarning() << file->errorString() ;
    else qInfo() << "Wrote " << bytes << " to the file";
    file->flush(); // not really needed, but for making sure
    file->close();
    return true;
}

void FileSystem::write(QString path, QByteArray data)
{
    if (put(path, data, QIODevice::WriteOnly)) qInfo() << "Data written to file";
    else qWarning() << "Failed to write to file:";
}

bool FileSystem::write2(QString path, QByteArray data)
{
    QFile *file = getFile(path, QIODevice::WriteOnly);
    if (!file) return false;

    qint64 bytes = file->write(data);
    // file.flush();
    file->close();
    return bytes ? true : false;
}

void FileSystem::append(QString path, QByteArray data)
{
    if (put(path, data, QIODevice::Append)) qInfo() << "Data appended to file";
    else qWarning() << "Failed to appended to file:";

    //    QString path = QDir::currentPath() + QDir::separator() + "test.txt";
    //    qInfo() << "Path: " << path;

    //    QByteArray data("Hello Gaurav\r\n");
    //    for (int var = 0; var < 5; ++var) {
    //        QString num = QString::number(var);
    //        num.append(" ");

    //        QByteArray line(num.toLatin1() + data);
    //        // write(path, line);
    //        append(path, line);
    //    }
}

bool FileSystem::createFile2(QString path)
{
    QByteArray data;
    data.append(QString::number(1));
    data.append("Hello World\r\n");
    return write2(path, data);
}

void FileSystem::readSmallFile(QString path)
{
    if (!fileExist(path)) return;

    QFile *file = getFile(path, QIODevice::ReadOnly);
    if (!file) return;

    qInfo() << file->readAll(); // best for small size file like 1Mb or 4Mb; dont do this for large file. else it will take hell lot of memory
}

void FileSystem::readLargeFileByLines(QString path)
{
    if (!fileExist(path)) return;

    QFile *file = getFile(path, QIODevice::ReadOnly);
    if (!file) return;

    while(!file->atEnd()) {
        QString line(file->readLine());
        qInfo() << "Read: " << line.trimmed(); // best with text files.
    }
}

void FileSystem::readLargeFileByBytes(QString path)
{
    // the file is actually a buffer in system, called file buffer, because it has a starting and an ending point and data in between
    // while stream has not end point, like river
    if (!fileExist(path)) return;

    QFile *file = getFile(path, QIODevice::ReadOnly);
    if (!file) return;

    while(!file->atEnd()) qInfo() << "Read: " << file->read(5); // best with larger file or structs
}

void FileSystem::printFilesInsideDir(QDir dir)
{
    foreach (QFileInfo fi, dir.entryInfoList()) qInfo() << fi.fileName();
}

bool FileSystem::createDir(QString path)
{
    return dirExist(path, true);
}

bool FileSystem::rename(QString path, QString name)
{
    if (!dirExist(path)) return false;

    QDir* dir = getDir(path);

    int pos = path.lastIndexOf(QDir::separator());
    QString parent = path.mid(0, pos);
    QString newPath = parent + QDir::separator() + name;

    qInfo() << "Absolute: " << dir->absolutePath();
    qInfo() << "Parent: " << parent;
    qInfo() << "New: " << newPath;

    return dir->rename(path, newPath);
}

bool FileSystem::remove(QString path)
{
    return dirRemoved(path, true);
}

void FileSystem::qLock()
{
    QString path = getCurrentPath("test.txt");

    QFile *file = getFile(path, QIODevice::WriteOnly);
    QLockFile *lock = createLockFile(file);

    // automatically unlock the file.. after 30000 i.e 30 seconds
    lock->setStaleLockTime(30000);

    if (lock->tryLock()) {
        if (file) {
            // Took over 30 seconds here, auto unlock
            QByteArray data;
            file->write(data);
            file->close();
        }
        // comment this out and run to see what happen
        lock->unlock();
    } else {
        qInfo() << "Could not lock the file:";
        qint64 pid;
        QString host, application;
        if (lock->getLockInfo(&pid, &host, &application)) {
            qInfo() << "The file is locked by:";
            qInfo() << "Pid: " << pid;
            qInfo() << "Host: " << host;
            qInfo() << "Application: " << application;
        } else qInfo() << "File is locked, but can't get the info:";
    }
}

void FileSystem::qStorageInfo()
{
    foreach (QStorageInfo storage, QStorageInfo::mountedVolumes()) {
        qInfo() << "Name: " << storage.displayName();
        qInfo() << "Type: " << storage.fileSystemType();
        qInfo() << "Total: " << storage.bytesTotal() / 1000 / 1000 << " MB";
        qInfo() << "Available: " << storage.bytesAvailable() / 1000 / 1000 << " MB";
        qInfo() << "Device: " << storage.device();
        qInfo() << "Root: " << storage.isRoot();
        qInfo() << endl;
    }

    QStorageInfo root = QStorageInfo::root();
    foreach (QFileInfo fi, getDir(root.rootPath())->entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot)) {
        qInfo() << fi.filePath();
    }
}

// *********************************************
// *************    HELPER     *****************
// *********************************************

QLockFile *FileSystem::createLockFile(QFile* file)
{
    QLockFile *lock = new QLockFile(file->fileName() + "-lock");
    return lock;
}

QString FileSystem::getCurrentPath()
{
    return QDir::currentPath() + QDir::separator();
}

QString FileSystem::getCurrentPath(QString filename)
{
    return getCurrentPath() + filename;
}

QFile* FileSystem::getFile(QString path, QIODevice::OpenMode io) {
    QFile *file = new QFile(path);
    if (!file->open(io)) {
        qWarning() << file->errorString();
        return nullptr;
    }
    return file;
}

QDir *FileSystem::getDir(QString path)
{
    QDir *dir = new QDir(path);
    return dir;
}

bool FileSystem::fileExist(QString path)
{
    QFile file(path);
    return file.exists();
}

bool FileSystem::dirExist(QString path)
{
    QDir dir(path);
    return dir.exists();
}

bool FileSystem::dirExist(QString path, bool createNew)
{
    QDir dir(path);
    return dir.exists() ? true : (createNew ? dir.mkdir(path) : false);
}

bool FileSystem::dirRemoved(QString path, bool recursiveDelete)
{
    return dirExist(path) ? (recursiveDelete ? getDir(path)->removeRecursively() /* Danger Opt.*/ : false) : false;
}

QFile *FileSystem::getFile(QString path, QIODevice::OpenModeFlag io)
{
    QFile *file = new QFile(path);
    if (!file->open(io)) {
        qWarning() << file->errorString();
        return nullptr;
    }
    return file;
}
