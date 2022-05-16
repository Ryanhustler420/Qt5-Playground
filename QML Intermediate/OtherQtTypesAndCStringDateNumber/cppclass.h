#ifndef CPPCLASS_H
#define CPPCLASS_H

#include <QObject>
#include <QDateTime>
#include <QDebug>
#include <QTime>

class CppClass : public QObject
{
    Q_OBJECT
public:
    explicit CppClass(QObject *parent = nullptr);

signals:
    void sendDateTime(QDateTime datetimeparem);
    void sendTime(QTime timeparem);

public slots:
    void cppSlot();
    void timeSlot(QTime time);
    void dateTimeSlot(QDateTime dateTime);

};

#endif // CPPCLASS_H
