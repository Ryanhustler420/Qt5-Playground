#include "propertywrapper.h"

PropertyWrapper::PropertyWrapper(QObject *parent) : QObject(parent),
    m_firstName("Gaurav"),
    m_lastName("Gupta"),
    m_timer(new QTimer(this)),
    m_random_number(0)
{
    // Initialize
    srand(time(NULL));

    QStringList list;
    list << "Gaurav" << "Saurav" << "Sangeeta" << "Sarita" << "Vinod" << "Sunita" << "Promod" << "Babita";

    connect(m_timer, &QTimer::timeout, [=](){
        m_random_number = rand() % (list.size());
        setFirstName(list[m_random_number]);
    });

    m_timer->start(3000);
}

const QString &PropertyWrapper::firstName() const
{
    return m_firstName;
}

void PropertyWrapper::setFirstName(const QString &newFirstName)
{
    if (m_firstName == newFirstName)
        return;
    m_firstName = newFirstName;
    emit firstNameChanged();
}

const QString &PropertyWrapper::lastName() const
{
    return m_lastName;
}

void PropertyWrapper::setLastName(const QString &newLastName)
{
    if (m_lastName == newLastName)
        return;
    m_lastName = newLastName;
    emit lastNameChanged();
}
