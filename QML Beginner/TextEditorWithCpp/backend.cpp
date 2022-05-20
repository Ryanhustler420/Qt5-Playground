#include "backend.h"

Backend::Backend(QObject *parent) : QObject(parent)
{
    m_path = QCoreApplication::applicationDirPath();
    m_path.append("/file.txt");
}

const QString &Backend::path() const
{
    return m_path;
}

void Backend::setPath(const QString &newPath)
{
    qInfo() << newPath;
    if (m_path == newPath)
        return;
    m_path = newPath;
    m_path.remove("file:///");
    emit pathChanged();
}

const QString &Backend::data() const
{
    QFile file(m_path);
    if (!file.open(QIODevice::ReadOnly)) {
        qWarning () << "could not read file";
        return "";
    }

    QTextStream stream(&file);
    QString value = stream.readAll();
    file.close();
    return value;
}

void Backend::setData(const QString &newData)
{
    QFile file(m_path);
    if (!file.open(QIODevice::WriteOnly)) {
        qWarning () << "could not write file";
        return;
    }
    QTextStream stream(&file);
    stream << newData;
    stream.flush();
    file.close();
    emit dataChanged();
}
