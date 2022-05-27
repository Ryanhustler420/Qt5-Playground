#ifndef ALLCOURSESPAGECONTROLLER_H
#define ALLCOURSESPAGECONTROLLER_H

#include "ipc/databridge.h"
#include "models/course.h"
#include "rx/signals.h"

#include "networking/apis.h"
#include "utility/xcodeclazzdb.h"

class AllCoursesPageController : public QObject
{
    Q_OBJECT
public:
    explicit AllCoursesPageController(QObject *parent = nullptr);

public:
    Q_INVOKABLE void hold(QString title, QString subtitle, QString duration, QString thumbnailUrl, QString imageContainer, QList<QString> features, int price, bool hasActive, int spaceLeft, int spaceFull, QString starts, QString ends);
    Q_INVOKABLE void loadCourses();

signals:
    void coursesLoaded(QVariantList courses);

private:
    Apis apis;
    XCodeClazzDB db;
};

#endif // ALLCOURSESPAGECONTROLLER_H
