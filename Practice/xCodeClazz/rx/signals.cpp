#include "rx/signals.h"

Signals::Signals(QWidget *parent) : OSingleton<Signals>()
{
    Q_UNUSED(parent);
}

void Signals::onDeleteCourse(std::function<void ()> callback)
{
    connect(this, &Signals::deleteCourse, this, [=](){ callback(); });
}
