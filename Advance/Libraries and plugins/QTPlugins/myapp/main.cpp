#include <QCoreApplication>
#include <QGenericPlugin>
#include <QGenericPluginFactory>
#include <QDebug>

#include "../MyPlugin/ITest.h"

// If you "can not find -GL" - sudo apt-get install libgl-dev
// https://doc.qt.io/qt-5/qgenericpluginfactory.html
// https://doc.qt.io/qt-5/plugins-howto.html
// https://doc.qt.io/qt-5/qtwidgets-tools-styleplugin-example.html

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qInfo() << "Loading MyPlugin";
    QObject * plugin = QGenericPluginFactory::create("myplugin", "Stuff here");
    qInfo() << plugin;

    if (plugin)
    {
        iTest * myplugin = qobject_cast<iTest*>(plugin);
        if(myplugin)
        {
            myplugin->test();
        }
        else
        {
           qInfo() << "Could not cast myplugin";
        }
    }
    else
    {
       qInfo() << "Could not load MyPlugin";
    }

    return a.exec();
}
