#ifndef TEST_H
#define TEST_H

#include <QObject>
#include <QThread>
#include <QDebug>

class test : public QThread
{
    Q_OBJECT
public:
    explicit test(QObject *parent = nullptr);

signals:

public slots:
    void quit();

protected:
    void run();

private:
    bool ok;

};

#endif // TEST_H
