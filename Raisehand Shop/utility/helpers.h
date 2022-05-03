#ifndef HELPERS_H
#define HELPERS_H

#include "parents/commonsuperclass.h"

#include <QTextCodec>
#include <QDateTime>

class Helpers : public CommonSuperClass
{
public:
    explicit Helpers(CommonSuperClass *parent = nullptr);
    void __init__();
    QDateTime getCurrentTime();
    QByteArray getASCII(int vals[], unsigned int size);
    QByteArray toBase64(QString value);
    QByteArray fromBase64(QByteArray value);

    QByteArray toHex(QString value);
    QByteArray fromHex(QByteArray value);

    QByteArray toUTF16(QString value);
    QByteArray fromUTF16(QByteArray value);

signals:
};

#endif // HELPERS_H
