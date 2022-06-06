#ifndef ALLSTUDENTSPAGECONTROLLER_H
#define ALLSTUDENTSPAGECONTROLLER_H

#include <QDebug>
#include <QObject>
#include <QVariant>
#include <QVariantList>

#include "utility/xcodeclazzdb.h"
#include "application/manager.h"
#include "utility/jsonhelper.h"
#include "networking/apis.h"
#include "models/student.h"
#include "rx/signals.h"

class AllStudentsPageController : public QObject
{
    Q_OBJECT
public:
    explicit AllStudentsPageController(QObject *parent = nullptr);

    Q_INVOKABLE void pass(QVariant o);
    Q_INVOKABLE void loadStudents();
    Q_INVOKABLE void listViewReachedBottom(QVariant o);
    Q_INVOKABLE void scrollViewReachedBottom(QVariant o);

signals:
    void showLoading(bool b);
    void listViewReached(QVariant o);
    void scrollViewReached(QVariant o);

signals:
    void passed(QVariant o);
    void studentsLoaded(QVariantList students);

private:
    QVariantList students;
    XCodeClazzDB xdb;
    Apis apis;

};

#endif // ALLSTUDENTSPAGECONTROLLER_H
