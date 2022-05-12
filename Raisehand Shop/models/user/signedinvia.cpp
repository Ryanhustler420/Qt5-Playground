#include "models/user/signedinvia.h"

SignedInVia::SignedInVia(const QString &method, bool signupCompleted)
{
    this->method = method;
    this->signupCompleted = signupCompleted;

    this->className = "SignedInVia";
    this->fields = new _fields();
    this->sign_in_methods = new _signed_in_methods();
}

bool SignedInVia::getSignupCompleted() const
{
    return signupCompleted;
}

void SignedInVia::setSignupCompleted(bool newSignupCompleted)
{
    signupCompleted = newSignupCompleted;
}

const QString &SignedInVia::getMethod() const
{
    return method;
}

void SignedInVia::setMethod(const QString &newMethod)
{
    method = newMethod;
}

QList<QString> SignedInVia::getAllFields()
{

}

QString SignedInVia::getPackageName()
{
    return this->className;
}

QList<SignedInVia *> SignedInVia::parseJSONArray(QJsonArray o) throw()
{

}

SignedInVia *SignedInVia::parseJSONObject(QJsonObject o) throw()
{

}

QList<SignedInVia *> SignedInVia::parseArrayString(QString o) throw()
{

}

SignedInVia *SignedInVia::parseObjectString(QString o) throw()
{

}

bool SignedInVia::equal(SignedInVia *o)
{
    return o == this;
}
