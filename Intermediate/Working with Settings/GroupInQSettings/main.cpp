#include <QCoreApplication>
#include <QDebug>
#include <QSettings>

void saveAge(QSettings *setting, QString group, QString name, int age) {
    // setting.beginGroup(group);
    // setting.setValue(name, age);
    // setting.endGroup();

    setting->beginGroup(group);
    setting->setValue(name, age);
    setting->endGroup();
}

int getAge(QSettings *setting, QString group, QString name) {
    setting->beginGroup(group);

    if (!setting->contains(name)) {
        qWarning() << "Does not contain" << name << " in " << group;
        setting->endGroup();
        return 0;
    }

    bool ok;
    int value = setting->value(name).toInt(&ok);
    setting->endGroup();

    if (!ok) {
        qWarning() << "Failed to convert to int";
        return 0;
    }

    return value;

}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QCoreApplication::setOrganizationDomain("www.raisehand.io");
    QCoreApplication::setOrganizationName("Raisehand");
    QCoreApplication::setApplicationName("Raisehand Shop Client");

    QSettings settings(QCoreApplication::organizationName(), QCoreApplication::applicationName());

    // Save the settings
    //    settings.setValue("test", 1234);

    // Read the settings back
    //    qInfo() << settings.value("test").toString();
    //    qInfo() << settings.value("test").toInt();

    saveAge(&settings, "people", "Saurav", 23);
    saveAge(&settings, "beer", "tuburge", 1);
    saveAge(&settings, "beer", "kingfisher", 12);

    qInfo() << "Kingfisher " << getAge(&settings, "beer", "kingfisher");
    qInfo() << "Beer " << getAge(&settings, "beer", "tuburge");

    return a.exec();
}
