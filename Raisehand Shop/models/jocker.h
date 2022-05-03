#ifndef JOCKER_H
#define JOCKER_H

#include <QDataStream>
#include <QObject>
#include <QDebug>
#include <QMap>

class Jocker : public QObject
{
    Q_OBJECT
public:
    explicit Jocker(QObject *parent = nullptr);

    void fill();
    QString name();
    void setName(QString value);
    QMap<QString, QString> map();

    friend QDataStream& operator <<(QDataStream &stream, const Jocker &t) {
        stream << t.m_name;
        stream << t.m_map;
        return stream;
    }

    friend QDataStream& operator >>(QDataStream &stream, Jocker &t) {
        stream >> t.m_name;
        stream >> t.m_map;
        return stream;
    }

signals:

private:
    QString m_name;
    QMap<QString, QString> m_map;

};

#endif // JOCKER_H
