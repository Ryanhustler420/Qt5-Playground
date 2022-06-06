#ifndef SINGLECOURSEPAGECONTROLLER_H
#define SINGLECOURSEPAGECONTROLLER_H

#include <QDebug>
#include <QObject>
#include <QVariant>
#include <QVariantList>

#include "utility/xcodeclazzdb.h"
#include "database/localcache.h"
#include "application/manager.h"
#include "utility/jsonhelper.h"
#include "networking/apis.h"
#include "models/course.h"
#include "rx/signals.h"

class SingleCoursePageController : public QObject
{
    Q_OBJECT
public:
    explicit SingleCoursePageController(QObject *parent = nullptr);

    Q_INVOKABLE void pass(QVariant o);
    Q_INVOKABLE void loadCourse();
    Q_INVOKABLE void deleteCourse(QJsonObject o);
    Q_INVOKABLE void listViewReachedBottom(QVariant o);
    Q_INVOKABLE void scrollViewReachedBottom(QVariant o);

signals:
    void showLoading(bool b);
    void listViewReached(QVariant o);
    void scrollViewReached(QVariant o);

signals:
    void passed(QVariant o);
    void courseLoaded(QVariant o);
    void courseDeleted(QJsonObject o);

private:
    Apis apis;
    LocalCache lc;
    XCodeClazzDB xdb;

};

#endif // SINGLECOURSEPAGECONTROLLER_H
