#ifndef DASHBOARDPAGECONTROLLER_H
#define DASHBOARDPAGECONTROLLER_H

#include <QObject>
#include <QDebug>

class DashboardPageController : public QObject
{
    Q_OBJECT
public:
    explicit DashboardPageController(QObject *parent = nullptr);
    Q_INVOKABLE void openCountState(QString name, QString count);

signals:

};

#endif // DASHBOARDPAGECONTROLLER_H
