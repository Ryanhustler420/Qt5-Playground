#include "filesystem.h"

FileSystem::FileSystem(CommonSuperClass *parent) : CommonSuperClass(parent)
{

}

FileSystem::FileSystem(const QString &currentPath) : currentPath(currentPath)
{

}

QFileInfoList FileSystem::getFilesInfo(const QString &path)
{
    return getFilesInsideDir(*getDir(path));
}

QList<QStorageInfo> FileSystem::getSystemStorageDetails()
{
    // getDir(QStorageInfo::root())->entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot)
    return QStorageInfo::mountedVolumes();
}

QFileInfo FileSystem::getFileInfo(const QString &path)
{
    QFile f(path);
    QFileInfo i(f);
    return i;
}

QList<QFileInfo> FileSystem::getFilesInsideDir(QDir dir)
{
    return dir.entryInfoList(QDir::Files);
}

QDir *FileSystem::getDir(const QString &path)
{
    return new QDir(path);
}

bool FileSystem::write(QByteArray data, const QString &file_name)
{
    return put(file_name, data, QIODevice::WriteOnly);
}

bool FileSystem::append(QByteArray data, const QString &file_name)
{
    return put(file_name, data, QIODevice::Append);
}

bool FileSystem::deleteFile(const QString &file_name)
{
    QFile f(getCurrentPath(file_name));
    return f.remove();
}

QByteArray FileSystem::read(const QString &file_name)
{
    // best with text files.
    if (!fileExist(file_name)) return nullptr;
    QFile *file = getFile(file_name, QIODevice::ReadOnly);
    if (!file) return nullptr;
    QByteArray response;
    while(!file->atEnd()) {
        QString line(file->readLine());
        response += line.trimmed();
    }
    return response;
}

QByteArray FileSystem::readBytes(const QString &file_name, int bytesToRead)
{
    // the file is actually a buffer in system, called file buffer, because it has a starting and an ending point and data in between
    // while stream has not end point, like river

    // best with larger file or structs
    if (!fileExist(file_name)) return nullptr;
    QFile *file = getFile(file_name, QIODevice::ReadOnly);
    if (!file) return nullptr;
    QByteArray response;
    while(!file->atEnd()) response += file->read(bytesToRead);
    return response;
}

bool FileSystem::writeDataStream(QByteArray &data, QString &file_name)
{
    QFile *file = getFile(file_name, QIODevice::WriteOnly);
    if (!file) return false;

    QDataStream stream(file);
    stream << data; // shifting the data into stream
    // stream << QRandomGenerator::global()->bounded(1000); // shifting more data into stream
    file->close(); // we are not starting/closing stream because it doesn't have ending...
    return true;
}

QByteArray FileSystem::readDataStream(QString &file_name)
{
    QFile *file = getFile(file_name, QIODevice::ReadOnly);
    if (!file) return nullptr;

    QDataStream stream(file);
    QByteArray response;
    stream >> response; // reading from stream
    // qint32 num;
    // stream >> num; // reading from stream
    file->close();
    return response;
}

bool FileSystem::writeTextStream(QByteArray &data, QString &file_name)
{
    QFile *file = getFile(file_name, QIODevice::WriteOnly);
    if (!file) return false;

    QTextStream stream(file);
    stream << data; // shifting the data into stream;
    // qint32 num = QRandomGenerator::global()->bounded(1000);
    // stream << num << "\r\n";
    file->close(); // we are not starting/closing stream because it doesn't have ending...
    return true;
}

QByteArray FileSystem::readTextStream(QString &file_name)
{
    QFile *file = getFile(file_name, QIODevice::ReadOnly);
    if (!file) return nullptr;

    QTextStream stream(file);
    QByteArray response;
    stream >> response; // reading from stream
    // QString num;
    // stream >> num; // reading from stream
    file->close();
    return response;
}

QByteArray FileSystem::readFromBuffer()
{
    // Move to the first position
    buffer.seek(0);
    QByteArray response = buffer.readAll();
    // ALWAYS close your device:
    buffer.close();
    return response;
}

bool FileSystem::writeIntoBuffer(const QByteArray &data)
{
    if(buffer.open(QIODevice::ReadWrite)) {
        // File and device access you may need to flush the data to the device
        buffer.write(data);
        return true;
    } else {
        qInfo() << "Could not open buffer";
        return false;
    }
}

void FileSystem::deadLock(const QString &file_name, std::function<void (bool hasLocked)> callback)
{
    QFile *file = getFile(file_name, QIODevice::WriteOnly);
    QLockFile *lock = new QLockFile(file->fileName() + "-lock");

    // Automatically unlock the file.. after 30000 i.e 30 seconds
    // lock->setStaleLockTime(30000);

    // https://doc.qt.io/qt-5/qmutex.html
    qint64 pid;
    QString host, application;
    bool isAlreadyLocked = lock->getLockInfo(&pid, &host, &application);
    if (isAlreadyLocked) {
        callback(false);
    } else {
        lock->tryLock();
        // lock->lock();
        callback(true);
    }
}

bool FileSystem::fileExist(const QString &file_name)
{
    QFile file(getCurrentPath(file_name));
    return file.exists();
}

QFile *FileSystem::getFile(const QString &file_name, QIODevice::OpenModeFlag io)
{
    QFile *file = new QFile(getCurrentPath(file_name));
    if (!file->open(io)) {
        qWarning() << file->errorString();
        return nullptr;
    }
    return file;
}

QFile *FileSystem::getFile(const QString &file_name, QIODevice::OpenMode io)
{
    QFile *file = new QFile(getCurrentPath(file_name));
    if (!file->open(io)) {
        qWarning() << file->errorString();
        return nullptr;
    }
    return file;
}

bool FileSystem::createDir(const QString &path)
{
    return existDir(path, true);
}

bool FileSystem::renameDir(const QString &path, const QString &newName)
{
    if (!existDir(path, false)) return false;
    QDir* dir = getDir(path);
    int pos = path.lastIndexOf(path_separator());
    QString parent = path.mid(0, pos);
    QString newPath = parent + path_separator() + newName;
    return dir->rename(path, newPath);
}

bool FileSystem::removeDir(const QString &path, bool recursiveDelete)
{
    return existDir(path, false) ? (recursiveDelete ? getDir(path)->removeRecursively() /* Danger Opt.*/ : false) : false;
}

bool FileSystem::existDir(const QString &path, bool createNew)
{
    QDir dir(path);
    return dir.exists() ? true : (createNew ? dir.mkdir(path) : false);
}

QByteArray FileSystem::readSmallFile(const QString &file_name)
{
    // best for small size file like 1Mb or 4Mb; dont do this for large file. else it will take hell lot of memory
    if (!fileExist(file_name)) return nullptr;
    QFile *file = getFile(file_name, QIODevice::ReadOnly);
    if (!file) return nullptr;
    return file->readAll();
}

bool FileSystem::put(const QString &file_name, QByteArray data, QIODevice::OpenMode mode)
{
    QFile *file = getFile(file_name, mode);
    if (!file) return false;

    qint64 bytes = file->write(data);
    if (!bytes) {
        qWarning() << file->errorString();
        return false;
    }
    file->flush();
    file->close();
    return true;
}

QChar FileSystem::path_separator()
{
    return QDir::separator();
}

QString FileSystem::getCurrentPath()
{
    return currentPath;
}

QString FileSystem::getCurrentPath(const QString &file_name)
{
    return getCurrentPath() + path_separator() + file_name;
}
