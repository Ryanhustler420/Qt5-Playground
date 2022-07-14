#include "helpers.h"

Helpers::Helpers(CommonSuperClass *parent) : CommonSuperClass(parent)
{

}

void Helpers::__init__()
{
    qInfo() << __TIME__;
    qInfo() << __DATE__;
    qInfo() << __TIMESTAMP__;
}

QDateTime Helpers::getCurrentTime()
{
    return QDateTime::currentDateTime();
}

QByteArray Helpers::getASCII(int vals[], unsigned int size)
{
    QByteArray data;
    for (unsigned int var = 0; var < size; ++var) {
        data.append(vals[var]);
    }
    return data;
}

QByteArray Helpers::toBase64(QString value)
{
    // value.toUtf8().toBase64();
    return value.toLatin1().toBase64();
}

QByteArray Helpers::fromBase64(QByteArray value)
{
    return value.fromBase64(value);
}

QByteArray Helpers::toHex(QString value)
{
    // value.toUtf8().toHex();
    return value.toLatin1().toHex();
}

QByteArray Helpers::fromHex(QByteArray value)
{
    return value.fromHex(value);
}

QByteArray Helpers::toUTF16(QString value)
{
    return QTextCodec::codecForName("UTF-16")->fromUnicode(value);
}

QByteArray Helpers::fromUTF16(QByteArray value)
{
    return QTextCodec::codecForName("UTF-16")->toUnicode(value).toLatin1();
}

// https://stackoverflow.com/a/14353740
QString Helpers::formatView(long value)
{
    return QLocale(QLocale::English).toString((int) value);
}

// https://stackoverflow.com/a/41276585
QString Helpers::capitalizeFirstCharOnly(const QString& capString)
{
    QStringList parts = capString.split(' ', QString::SkipEmptyParts);
    for (int i = 0; i < parts.size(); ++i)
        parts[i].replace(0, 1, parts[i][0].toUpper());
    return parts.join(" ");
}

QString Helpers::normalizeEmail(const QString &normalizeEmailAddress)
{
    if (normalizeEmailAddress == nullptr || normalizeEmailAddress.compare(""))
        return "";
    return normalizeEmailAddress.trimmed().toLower();
}

