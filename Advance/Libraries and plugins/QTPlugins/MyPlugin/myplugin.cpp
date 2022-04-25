#include "myplugin.h"

MyPlugin::MyPlugin(QObject *parent)
    : QGenericPlugin(parent)
{
}

QObject *MyPlugin::create(const QString &name, const QString &spec)
{
    Q_UNUSED(name);
    Q_UNUSED(spec);
    return new MyPlugin;
}

void MyPlugin::test()
{
    qInfo() << "This is a test inside of plugin:";
}

#if QT_VERSION < 0x50000
Q_EXPORT_PLUGIN2(MyPlugin, MyPlugin)
#endif // QT_VERSION < 0x50000
