#ifndef SIGNEDINVIA_H
#define SIGNEDINVIA_H

#include "models/god/modelconventions.h"

class SignedInVia : public ModelConventions<SignedInVia>
{
    Q_OBJECT
public:
    typedef struct SIGNED_IN_METHODS {
        QString RAISEHAND = "RAISEHAND";
        QString GOOGLE_OAUTH = "GOOGLE_OAUTH";
    } _signed_in_methods;

    _signed_in_methods *sign_in_methods;

public:
    explicit SignedInVia(QObject *parent = nullptr);
    SignedInVia(const QString &method, bool signupCompleted);

private:
    QString method;
    bool signupCompleted;

private:
    typedef struct FIELDS {
        QString method = "method";
        QString signupCompleted = "signupCompleted";
    } _fields;

    _fields *fields;

signals:

    // ModelConventions interface
public:
    QList<QString> getAllFields();
    QString getPackageName();
    QList<SignedInVia *> parseJSONArray(QJsonArray o) throw();
    SignedInVia *parseJSONObject(QJsonObject o) throw();
    QList<SignedInVia *> parseArrayString(QString o) throw();
    SignedInVia *parseObjectString(QString o) throw();
    bool equal(SignedInVia *o);

public:
    const QString &getMethod() const;
    void setMethod(const QString &newMethod);
    bool getSignupCompleted() const;
    void setSignupCompleted(bool newSignupCompleted);
};

#endif // SIGNEDINVIA_H
