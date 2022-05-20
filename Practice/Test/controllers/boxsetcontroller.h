#ifndef BOXSETCONTROLLER_H
#define BOXSETCONTROLLER_H

#include <QDebug>
#include <QObject>
#include <QJsonObject>

class BoxSetController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int get READ get WRITE setGet NOTIFY getChanged(int a))
    Q_PROPERTY(QString json READ json WRITE setJson NOTIFY jsonChanged(int v1, double v2));
public:
    explicit BoxSetController(QObject *parent = nullptr);

    int get() const;
    Q_INVOKABLE void setGet(int newGet);

    const QString &json() const;
    Q_INVOKABLE void setJson(const QString &newJson);

signals:
    void getChanged(int a);
    void jsonChanged(int v1, double v2);

private:
    int m_get;
    QString m_json;
};

#endif // BOXSETCONTROLLER_H
