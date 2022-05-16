#ifndef PROPERTYWRAPPER_H
#define PROPERTYWRAPPER_H

#include <QObject>
#include <QTimer>

class PropertyWrapper : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString firstName READ firstName WRITE setFirstName NOTIFY firstNameChanged)
    Q_PROPERTY(QString lastName READ lastName WRITE setLastName NOTIFY lastNameChanged)
public:
    explicit PropertyWrapper(QObject *parent = nullptr);

    const QString &firstName() const;
    void setFirstName(const QString &newFirstName);

    const QString &lastName() const;
    void setLastName(const QString &newLastName);

signals:

    void firstNameChanged();
    void lastNameChanged();

private:
    QString m_firstName;
    QString m_lastName;

    QTimer * m_timer;
    int m_random_number;
};

#endif // PROPERTYWRAPPER_H
