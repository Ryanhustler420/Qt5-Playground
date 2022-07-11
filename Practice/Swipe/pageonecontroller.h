#ifndef PAGEONECONTROLLER_H
#define PAGEONECONTROLLER_H

#include <QObject>
#include <QTimer>
#include <QDebug>

class PageOneController : public QObject
{
    Q_OBJECT
public:
    explicit PageOneController(QObject *parent = nullptr);
    ~PageOneController();

    Q_INVOKABLE void schedule();
signals:

private:
    QTimer timer;

};

#endif // PAGEONECONTROLLER_H
