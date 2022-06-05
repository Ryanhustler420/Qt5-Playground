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
    Q_INVOKABLE void pass(QVariant o);
    Q_INVOKABLE void loadCourses();
    Q_INVOKABLE void createNewCourse(QJsonObject o);

signals:
    void showLoading(bool b);

signals:
    void passed(QVariant o);
    void coursesLoaded(QVariantList courses);
    void newCourseCreated(QJsonObject course);

private:
    Apis apis;
    LocalCache lc;
    XCodeClazzDB xdb;
};

#endif // ALLCOURSESPAGECONTROLLER_H
