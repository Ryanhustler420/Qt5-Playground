#include <QCoreApplication>
#include <QDebug>
#include <QScopedPointer>
#include "test.h"

// The QScopedPointer class stores a pointer to a dynamically allocated object,
// and deletes it upon destruction!!!

// QScopedPointer - as the class/object goes out of the scope, the pointer which hold it will automatically deleted.

void useit(test * obj) {
       if (!obj) return;
       qInfo() << "Using " << obj;
}

void useit(QScopedPointer<test> &mypointer) {
        qInfo() << "Using " << mypointer.data();
}

// NOTE: always use QScopePointer in special scope / function / class (method) . please don't use it in main, it might not clean the data from heap.
void doStuff() {
    // test *t =new test(); // dangling pointer!!!

    // This will only live inside this function scope, if the function done. it will wiped out from memory
    QScopedPointer<test> mypointer(new test()); // a pointer to a new test class

    useit(mypointer.data()); // good
    useit(mypointer); // bad i.e sending outside the scope

    //pointer is automatically delete!
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    for (int var = 0; var < 100; ++var) {
        doStuff();
    }

    return a.exec();
}
