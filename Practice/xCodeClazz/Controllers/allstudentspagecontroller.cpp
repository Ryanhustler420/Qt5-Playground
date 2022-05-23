#include "controllers/allstudentspagecontroller.h"

AllStudentsPageController::AllStudentsPageController(QObject *parent) : QObject(parent)
{

}

void AllStudentsPageController::getStudentsList()
{
    QList<QString> mp;
    mp.append("{\"name\": \"world\"}");
    emit studentList(mp);
}
