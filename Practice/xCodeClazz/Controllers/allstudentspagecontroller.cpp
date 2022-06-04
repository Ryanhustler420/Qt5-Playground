#include "controllers/allstudentspagecontroller.h"

AllStudentsPageController::AllStudentsPageController(QObject *parent) : QObject(parent)
{
    // [signals] if any
}

void AllStudentsPageController::hold(QVariant o)
{

}

void AllStudentsPageController::loadStudents()
{
    if (!xdb.student_file() || xdb.getStudents().isEmpty()) {
        if (Manager::instance().getIsInternetPresent()) {
            emit showLoading(true);
            apis.getStudents([=](QByteArray response){
                QList<Student *> list = (new Student())->parseJSONArray(QJsonDocument::fromJson(response).object().value("students").toArray());

                QJsonArray arr;
                for (int var = 0; var < list.size(); ++var) arr.push_back(list.at(var)->getAsJson());

                xdb.saveStudents(arr);
                students.append(arr.toVariantList());

                emit studentsLoaded(arr.toVariantList());
                emit showLoading(false);
            }, [=](QByteArray error){
                qInfo() << error;
                emit showLoading(false);
            });
        } else {
            emit showLoading(false);
        }
    } else {
        if (Manager::instance().getIsInternetPresent()) {
            apis.getStudents([=](QByteArray response){
                QList<Student *> list = (new Student())->parseJSONArray(QJsonDocument::fromJson(response).object().value("students").toArray());

                QJsonArray arr;
                for (int var = 0; var < list.size(); ++var) arr.push_back(list.at(var)->getAsJson());

                xdb.saveStudents(arr);
            }, [=](QByteArray error){
                qInfo() << error;
            });
        } else {
        }
        students.append(xdb.getStudents().toVariantList());
        emit studentsLoaded(xdb.getStudents().toVariantList());
    }
}

