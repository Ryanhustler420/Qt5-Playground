#include "threads.h"

Threads::Threads(CommonSuperClass *parent) : CommonSuperClass(parent)
{

}

void Threads::example()
{
    Timer *t = new Timer();
    QtConcurrent::run([=](){
        t->wait_once(5000, [=](){
            qInfo("Message");
        });
    });
}
