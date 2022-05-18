#ifndef TEST_H
#define TEST_H

#include <QObject>
#include <QTimer>
#include <QDateTime>
#include <QVariant>
#include <QDebug>

class Test : public QObject
{
    Q_OBJECT
public:
    explicit Test(QObject *parent = nullptr);

signals:
    void notice(QVariant data);

private slots:
    void timeout();

public slots:
    void start();
    void stop();

private:
    QTimer mTimer;
    QString mDisplay;

};

#endif // TEST_H
