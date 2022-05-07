#include "rxsignal.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    RxSignal w;
    w.show();
    return a.exec();
}
