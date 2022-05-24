#include "utility/xdb.h"

xDB::xDB(const QString &path)
{
    fs = new FileSystem(path);
}

bool xDB::save(QJsonDocument doc, const QString &file_name)
{
    return fs->write(doc.toJson(), file_name);
}

QJsonDocument xDB::get(const QString &file_name)
{
    return QJsonDocument::fromJson(fs->read(file_name));
}

bool xDB::remove(const QString &file_name)
{
    return fs->deleteFile(file_name);
}
