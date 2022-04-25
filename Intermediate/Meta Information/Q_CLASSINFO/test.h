#ifndef TEST_H
#define TEST_H

#include <QObject>

class test : public QObject
{
    Q_OBJECT
    Q_CLASSINFO("Author", "Gaurav Gupta")
    Q_CLASSINFO("Url", "www.gouravgupta.com")
public:
    explicit test(QObject *parent = nullptr);

signals:

};

#endif // TEST_H
