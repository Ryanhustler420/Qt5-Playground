#include "system.h"

System::System(QObject *parent) : QObject(parent)
{

}

QString System::getScreenSize()
{
    QScreen *s = QGuiApplication::primaryScreen();
    QRect r = s->geometry();
    return QString("%1 x %2").arg(r.width()).arg(r.height());
}
