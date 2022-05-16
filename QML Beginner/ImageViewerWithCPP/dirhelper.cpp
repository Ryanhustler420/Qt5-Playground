#include "dirhelper.h"

DirHelper::DirHelper(QObject *parent) : QObject(parent)
{

}

QString DirHelper::path()
{
    return dir.path();
}

void DirHelper::setPath(QString value)
{
    dir.setPath(value);
}

QStringList DirHelper::files()
{
    QFileInfoList list = dir.entryInfoList(QDir::AllEntries | QDir::NoDotAndDotDot | QDir::Files);
    QStringList fileList;
    for (QFileInfo info: list) {
        fileList.append(info.filePath());
    }
    return fileList;
}
