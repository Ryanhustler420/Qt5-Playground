#ifndef TEST_H
#define TEST_H

#include <QObject>

class test : public QObject
{
    Q_OBJECT
//    Q_DISABLE_COPY(test)
public:
    explicit test(QObject *parent = nullptr);

signals:

};

#endif // TEST_H
