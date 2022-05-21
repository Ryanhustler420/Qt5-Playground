#ifndef DATABRIDGE_H
#define DATABRIDGE_H

#include "singleton/singleton_obj.h"
#include "models/course.h"

class DataBridge : public OSingleton<DataBridge>
{
    Q_OBJECT
public:
    explicit DataBridge(QObject *parent = nullptr);

    Course *getCourse();
    void setCourse(Course *newCourse);

signals:

private:
    Course* course;

};

#endif // DATABRIDGE_H
