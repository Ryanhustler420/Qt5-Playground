#include "application.h"

Application::Application(QObject *parent) : QObject(parent)
{

}

void Application::takeFiles(QList<QUrl> files)
{
    std::string fn = files.at(0).path().toStdString();
    if (fn.substr(fn.find_last_of(".") + 1) == "jpg") {
        emit correctFileImported(files);
        qInfo() << "Yes";
    } else {
        qInfo() << "No";
    }
}
