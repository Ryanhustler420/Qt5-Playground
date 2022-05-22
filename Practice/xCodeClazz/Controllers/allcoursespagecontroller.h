#ifndef ALLCOURSESPAGECONTROLLER_H
#define ALLCOURSESPAGECONTROLLER_H

#include "ipc/databridge.h"
#include "models/course.h"
#include "rx/signals.h"

class AllCoursesPageController : public QObject
{
    Q_OBJECT
public:
    explicit AllCoursesPageController(QObject *parent = nullptr);

public:
    Q_INVOKABLE void hold(QString title, QString subtitle, QString duration, QString thumbnailUrl, QString imageContainer, QList<QString> features, int price, bool hasActive, int spaceLeft, int spaceFull, QString starts, QString ends);

signals:

};

#endif // ALLCOURSESPAGECONTROLLER_H
