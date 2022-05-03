#ifndef SPIDER_H
#define SPIDER_H

#include <QObject>
#include <QDebug>
#include <QMap>
#include <QDataStream>

class Spider : public QObject
{
    Q_OBJECT
public:
    explicit Spider(QObject *parent = nullptr);

    void fill();
    QString name();
    void setName(QString value);
    QMap<QString, QString> map();
    void setMap(QMap<QString, QString> map);

    friend QDataStream& operator <<(QDataStream &stream, const Spider &t) {
        stream << t.m_name;
        stream << t.m_map;
        return stream;
    }

    friend QDataStream& operator >>(QDataStream &stream, Spider &t) {
        stream >> t.m_name;
        stream >> t.m_map;
        return stream;
    }

signals:

private:
    QString m_name;
    QMap<QString, QString> m_map;

};

#endif // SPIDER_H
