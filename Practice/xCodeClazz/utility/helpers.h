#ifndef HELPERS_H
#define HELPERS_H

#include "parents/commonsuperclass.h"
#include "shareable/constants.h"

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

    QString formatView(long value);
    QString capitalizeFirstCharOnly(const QString& capString);
    QString normalizeEmail(const QString& normalizeEmailAddress);

    qint64 getPassed(QString timeFrom, QString unitOfTime);
    bool isTimePassed(QString unitOFTime, QString timeFrom, qint64 isItCoverThis);
    QString getTimePassed(QString from);
    QString getDatePortionFromCreatedAt(QString createdAt);
    bool boolOf(int integer);
    bool urlContainsHttpKeyword(QString url);
    bool urlsContainsHttpKeyword(QList<QString> urls);
    void openUrlInBrowser(QString url);
    QString refineDecimal(double amount);
    QString refineDecimalAndGroup(double amount);
    bool hasOnlyNumericValue(QString v);
    // ShopExpireDetails isShopExpired(QString JSDate, int validityForDays);
    // ProductRepositoryExpireDetails isProductRepositoryExpired(QString JSDate, int validityForDays);
    // QString getPostFixForIndex(long index);
    QList<QString> getWeekDaysList() const;
    void copyTextToClipBoard(QString WhatIsThisFor, QString text);

signals:
};

#endif // HELPERS_H
