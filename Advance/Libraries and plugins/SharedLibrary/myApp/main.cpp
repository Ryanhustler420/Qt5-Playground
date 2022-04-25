#include <QCoreApplication>

// add this in here which will import the library that you have created
#include "../mylib/mylib_global.h"
#include "../mylib/mylib.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Mylib mylib;
    mylib.test();

    // some changes

    return a.exec();
}
