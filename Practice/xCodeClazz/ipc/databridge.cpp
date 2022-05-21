#include "ipc/databridge.h"

DataBridge::DataBridge(QObject *parent) : OSingleton<DataBridge>(),
  course(new Course)
{

}

Course *DataBridge::getCourse()
{
    return course;
}

void DataBridge::setCourse(Course *newCourse)
{
    course->copy(newCourse);
}
