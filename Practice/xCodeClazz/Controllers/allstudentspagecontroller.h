#ifndef ALLSTUDENTSPAGECONTROLLER_H
#define ALLSTUDENTSPAGECONTROLLER_H

#include <QObject>

class AllStudentsPageController : public QObject
{
    Q_OBJECT
public:
    explicit AllStudentsPageController(QObject *parent = nullptr);
    Q_INVOKABLE void getStudentsList();

signals:
    void studentList(QList<QString> list);

};

#endif // ALLSTUDENTSPAGECONTROLLER_H
