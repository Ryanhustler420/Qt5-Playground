#include "system.h"

System::System(QObject *parent) : QObject(parent)
{
    ws = new widget_size_chart();
    fs = new font_size_chart();
}

QString System::getScreenSize()
{
    QScreen *s = QGuiApplication::primaryScreen();
    QRect r = s->geometry();
    return QString("%1 x %2").arg(r.width()).arg(r.height());
}

void System::setWindowSize(QString height, QString width)
{
    emit windowSizeChanged(height, width);
}

void System::changeH1FontSize(int val)
{
    emit h1FontSizeChanged(h1FontSize, val);
}

void System::changeH2FontSize(int val)
{
    emit h2FontSizeChanged(h2FontSize, val);
}

void System::changeWidgetSize(int val)
{
    emit widgetSizeChanged(val, val);
}
