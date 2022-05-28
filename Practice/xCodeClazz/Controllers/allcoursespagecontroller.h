#ifndef ALLCOURSESPAGECONTROLLER_H
#define ALLCOURSESPAGECONTROLLER_H

#include "utility/xcodeclazzdb.h"
#include "database/localcache.h"
#include "networking/apis.h"
#include "models/course.h"
#include "rx/signals.h"

class AllCoursesPageController : public QObject
{
    Q_OBJECT
public:
    explicit AllCoursesPageController(QObject *parent = nullptr);

public:
    Q_INVOKABLE void hold(QVariant o);
    Q_INVOKABLE void loadCourses();

signals:
    void holded(QVariant o);
    void coursesLoaded(QVariantList courses);

private:
    Apis apis;
    LocalCache lc;
    XCodeClazzDB db;
};

#endif // ALLCOURSESPAGECONTROLLER_H
