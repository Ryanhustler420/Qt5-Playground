#ifndef EXCEPTIONTHROW_H
#define EXCEPTIONTHROW_H

#include <QObject>

class ExceptionThrow : public QObject
{
    Q_OBJECT
public:
    explicit ExceptionThrow(QObject *parent = nullptr);
    ExceptionThrow(QString msg);

    const QString &getMsg() const;
    void setMsg(const QString &newMsg);

signals:

private:
    QString msg;

};

#endif // EXCEPTIONTHROW_H
