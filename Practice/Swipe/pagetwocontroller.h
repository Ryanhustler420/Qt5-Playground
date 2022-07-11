#ifndef PAGETWOCONTROLLER_H
#define PAGETWOCONTROLLER_H

#include <QObject>
#include <QTimer>
#include <QDebug>

class PageTwoController : public QObject
{
    Q_OBJECT
public:
    explicit PageTwoController(QObject *parent = nullptr);
    ~PageTwoController();

    Q_INVOKABLE void schedule();
signals:

private:
    QTimer timer;

};

#endif // PAGETWOCONTROLLER_H
