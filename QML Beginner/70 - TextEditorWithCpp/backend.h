#ifndef BACKEND_H
#define BACKEND_H

#include <QCoreApplication>
#include <QTextStream>
#include <QObject>
#include <QDebug>
#include <QFile>

class Backend : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString path READ path WRITE setPath NOTIFY pathChanged)
    Q_PROPERTY(QString data READ data WRITE setData NOTIFY dataChanged)

public:
    explicit Backend(QObject *parent = nullptr);

    const QString &path() const;
    void setPath(const QString &newPath);

    const QString &data() const;
    void setData(const QString &newData);

signals:
    void pathChanged();
    void dataChanged();

private:
    QString m_path;
    QString m_data;

};

#endif // BACKEND_H
