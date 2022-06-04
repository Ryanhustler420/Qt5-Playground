#ifndef XDB_H
#define XDB_H

#include "utility/jsonhelper.h"
#include "utility/filesystem.h"

class xDB : public QObject
{
    Q_OBJECT
public:
    xDB(const QString &path);

    bool save(QJsonDocument doc, const QString &file_name);
    QJsonDocument get(const QString &file_name);
    bool remove(const QString &file_name);
    bool present(const QString &file_name);

signals:

private:
    FileSystem *fs;

};

#endif // XDB_H
