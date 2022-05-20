#ifndef PAGEONECONTROLLER_H
#define PAGEONECONTROLLER_H

#include <QObject>

class PageOneController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString version READ version WRITE setVersion NOTIFY versionChanged(int response))
public:
    explicit PageOneController(QObject *parent = nullptr);

    const QString &version() const;
    Q_INVOKABLE void setVersion(const QString &newVersion);

signals:
    void versionChanged(int response);

private:
    QString m_version;

};

#endif // PAGEONECONTROLLER_H
