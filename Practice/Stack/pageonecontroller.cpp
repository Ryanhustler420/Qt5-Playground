#include "pageonecontroller.h"

PageOneController::PageOneController(QObject *parent) : QObject(parent)
{

}

const QString &PageOneController::version() const
{
    return m_version;
}

void PageOneController::setVersion(const QString &newVersion)
{
    if (m_version == newVersion)
        return;
    m_version = newVersion;
    emit versionChanged(45);
}
