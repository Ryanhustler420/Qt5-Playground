#ifndef PLAN_H
#define PLAN_H

#include "models/god/modelconventions.h"
#include "models/plans/endpoint.h"
#include "shareable/constants.h"

#include<iostream>
#include<algorithm>
using namespace std;

class Plan : public ModelConventions<Plan>
{
    Q_OBJECT
public:
    explicit Plan(QObject *parent = nullptr);
    Plan(const QString &PlanName, double OriginalAmount, double StrikeAmount, const QString &StrikeReason, const QString &CurrencySymbol, const QString &CurrencyCode, int InventoryLength, int ValidityForDays, double StripeFeeDeductedAmount, double StripeFeeDeductedPercentage, double TotalAmount, QList<QString> *Features, EndPoint *Hit);

private:
    QString PlanName;
    double OriginalAmount;
    double StrikeAmount;
    QString StrikeReason;
    QString CurrencySymbol;
    QString CurrencyCode;
    int InventoryLength;
    int ValidityForDays;
    double StripeFeeDeductedAmount;
    double StripeFeeDeductedPercentage;
    double TotalAmount;
    QList<QString> *Features;
    EndPoint *Hit;

private:
    typedef struct FIELDS {
        QString PlanName = "PlanName";
        QString OriginalAmount = "OriginalAmount";

        QString StrikeAmount = "StrikeAmount";
        QString StrikeReason = "StrikeReason";
        QString CurrencySymbol = "CurrencySymbol";
        QString CurrencyCode = "CurrencyCode";
        QString InventoryLength = "InventoryLength";
        QString ValidityForDays = "ValidityForDays";
        QString StripeFeeDeductedAmount = "StripeFeeDeductedAmount";
        QString StripeFeeDeductedPercentage = "StripeFeeDeductedPercentage";
        QString TotalAmount = "TotalAmount";
        QString Features = "Features";
        QString Hit = "Hit";
    } _fields;

    _fields *fields;

signals:

    // ModelConventions interface
public:
    QList<QString> getAllFields();
    QString getPackageName();
    QList<Plan *> parseJSONArray(QJsonArray o) throw();
    Plan *parseJSONObject(QJsonObject o) throw();
    QList<Plan *> parseArrayString(QString o) throw();
    Plan *parseObjectString(QString o) throw();
    bool equal(Plan *o);

    const QString &getPlanName() const;
    void setPlanName(const QString &newPlanName);
    double getOriginalAmount() const;
    void setOriginalAmount(double newOriginalAmount);
    double getStrikeAmount() const;
    void setStrikeAmount(double newStrikeAmount);
    const QString &getStrikeReason() const;
    void setStrikeReason(const QString &newStrikeReason);
    const QString &getCurrencySymbol() const;
    void setCurrencySymbol(const QString &newCurrencySymbol);
    const QString &getCurrencyCode() const;
    void setCurrencyCode(const QString &newCurrencyCode);
    int getInventoryLength() const;
    void setInventoryLength(int newInventoryLength);
    int getValidityForDays() const;
    void setValidityForDays(int newValidityForDays);
    double getStripeFeeDeductedAmount() const;
    void setStripeFeeDeductedAmount(double newStripeFeeDeductedAmount);
    double getStripeFeeDeductedPercentage() const;
    void setStripeFeeDeductedPercentage(double newStripeFeeDeductedPercentage);
    double getTotalAmount() const;
    void setTotalAmount(double newTotalAmount);
    QList<QString> *getFeatures() const;
    void setFeatures(QList<QString> *newFeatures);
    EndPoint *getHit() const;
    void setHit(EndPoint *newHit);

    double getAmountAfterStrike();
    double chargeStripeFee();
    QString getFormattedSaveAmountInPercentage();
    bool hasStrikeAmount();
    QString getFormattedPriceWithValidity(bool isMonthlyPrice);
    QString getFormattedStrikeAmount();
    QString getPerfectTerms(int days);
    bool isInternational();
    bool isNational();
    bool isLocal();
    bool isGold();
    bool isSilver();
    bool isOnion();
};

#endif // PLAN_H
