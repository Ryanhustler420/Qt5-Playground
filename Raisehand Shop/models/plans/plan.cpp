#include "models/plans/plan.h"

Plan::Plan(const QString &PlanName, double OriginalAmount, double StrikeAmount, const QString &StrikeReason, const QString &CurrencySymbol, const QString &CurrencyCode, int InventoryLength, int ValidityForDays, double StripeFeeDeductedAmount, double StripeFeeDeductedPercentage, double TotalAmount, QList<QString> *Features, EndPoint *Hit)
{
    this->PlanName = PlanName;
    this->OriginalAmount = OriginalAmount;
    this->StrikeAmount = StrikeAmount;
    this->StrikeReason = StrikeReason;
    this->CurrencySymbol = CurrencySymbol;
    this->CurrencyCode = CurrencyCode;
    this->InventoryLength = InventoryLength;
    this->ValidityForDays = ValidityForDays;
    this->StripeFeeDeductedAmount = StripeFeeDeductedAmount;
    this->StripeFeeDeductedPercentage = StripeFeeDeductedPercentage;
    this->TotalAmount = TotalAmount;
    this->Features = Features;
    this->Hit = Hit;

    this->className = "Plan";
    this->fields = new _fields();
}

EndPoint *Plan::getHit() const
{
    return Hit;
}

void Plan::setHit(EndPoint *newHit)
{
    Hit = newHit;
}

QList<QString> *Plan::getFeatures() const
{
    return Features != nullptr ? Features : new QList<QString>();
}

void Plan::setFeatures(QList<QString> *newFeatures)
{
    Features = newFeatures;
}

double Plan::getTotalAmount() const
{
    return TotalAmount;
}

void Plan::setTotalAmount(double newTotalAmount)
{
    TotalAmount = newTotalAmount;
}

double Plan::getStripeFeeDeductedPercentage() const
{
    return StripeFeeDeductedPercentage;
}

void Plan::setStripeFeeDeductedPercentage(double newStripeFeeDeductedPercentage)
{
    StripeFeeDeductedPercentage = newStripeFeeDeductedPercentage;
}

double Plan::getStripeFeeDeductedAmount() const
{
    return StripeFeeDeductedAmount;
}

void Plan::setStripeFeeDeductedAmount(double newStripeFeeDeductedAmount)
{
    StripeFeeDeductedAmount = newStripeFeeDeductedAmount;
}

int Plan::getValidityForDays() const
{
    return ValidityForDays;
}

void Plan::setValidityForDays(int newValidityForDays)
{
    ValidityForDays = newValidityForDays;
}

int Plan::getInventoryLength() const
{
    return InventoryLength;
}

void Plan::setInventoryLength(int newInventoryLength)
{
    InventoryLength = newInventoryLength;
}

const QString &Plan::getCurrencyCode() const
{
    return CurrencyCode;
}

void Plan::setCurrencyCode(const QString &newCurrencyCode)
{
    CurrencyCode = newCurrencyCode;
}

const QString &Plan::getCurrencySymbol() const
{
    return CurrencySymbol;
}

void Plan::setCurrencySymbol(const QString &newCurrencySymbol)
{
    CurrencySymbol = newCurrencySymbol;
}

const QString &Plan::getStrikeReason() const
{
    return StrikeReason;
}

void Plan::setStrikeReason(const QString &newStrikeReason)
{
    StrikeReason = newStrikeReason;
}

double Plan::getStrikeAmount() const
{
    return StrikeAmount;
}

void Plan::setStrikeAmount(double newStrikeAmount)
{
    StrikeAmount = newStrikeAmount;
}

double Plan::getOriginalAmount() const
{
    return OriginalAmount;
}

void Plan::setOriginalAmount(double newOriginalAmount)
{
    OriginalAmount = newOriginalAmount;
}

const QString &Plan::getPlanName() const
{
    return PlanName;
}

void Plan::setPlanName(const QString &newPlanName)
{
    PlanName = newPlanName;
}

QList<QString> Plan::getAllFields()
{

}

QString Plan::getPackageName()
{
    return this->className;
}

QList<Plan *> Plan::parseJSONArray(QJsonArray o) throw()
{

}

Plan *Plan::parseJSONObject(QJsonObject o) throw()
{

}

QList<Plan *> Plan::parseArrayString(QString o) throw()
{

}

Plan *Plan::parseObjectString(QString o) throw()
{

}

bool Plan::equal(Plan *o)
{
    return o == this;
}

/* Helper Methods */

double Plan::getAmountAfterStrike() {
    double v = getOriginalAmount() - getStrikeAmount() + chargeStripeFee();
    return std::max(v, (double) 0);
}

double Plan::chargeStripeFee() {
    double newAmount = getOriginalAmount() - getStrikeAmount();
    return (newAmount * getStripeFeeDeductedPercentage()) / 100;
}

QString Plan::getFormattedSaveAmountInPercentage() {
    double v = (getStrikeAmount() / getOriginalAmount()) * 100;
    return QString::number(v); // QString("%1%2").arg(helper.refineDecimalAndGroup(v)).arg("%");
}

bool Plan::hasStrikeAmount() {
    return getStrikeAmount() > 0;
}

QString Plan::getFormattedPriceWithValidity(bool isMonthlyPrice) {
    QString precise = ""; // helper.refineDecimalAndGroup(getOriginalAmount() - getStrikeAmount()); // $25/month
    return isMonthlyPrice ?
                QString("%1%2/-").arg(getCurrencySymbol()).arg(precise) :
                QString("%1%2/%3").arg(getCurrencySymbol()).arg(precise).arg(getPerfectTerms(getValidityForDays()));
}

QString Plan::getFormattedStrikeAmount() {
    return QString(""); // QString("%1%2").arg(getCurrencySymbol()).arg(helper.refineDecimalAndGroup(getOriginalAmount())); // $25
    // return QString("- %1%2 (%3*)").arg(_plan.getSymbol()).arg(_plan.getStrike()).arg(_plan.getStrikeReason());
}

QString Plan::getPerfectTerms(int days) {
    if (days == 60) {
        return "2 months";
    } else if (days == 90) {
        return "3 months";
    } else if (days == 120) {
        return "4 months";
    } else if (days == 150) {
        return "5 months";
    } else if (days == 180) {
        return "half yearly";
    } else if (days == 210) {
        return "7 months";
    } else if (days == 240) {
        return "8 months";
    } else if (days == 270) {
        return "9 months";
    } else if (days == 300) {
        return "10 months";
    } else if (days == 330) {
        return "11 months";
    } else if (days == 365) {
        return "year";
    } else {
        return "month";
    }
}

bool Plan::isInternational() {
    return getPlanName().compare(INTERNATIONAL);
}

bool Plan::isNational() {
    return getPlanName().compare(NATIONAL);
}

bool Plan::isLocal() {
    return getPlanName().compare(LOCAL);
}

bool Plan::isGold() {
    return getPlanName().compare(GOLD);
}

bool Plan::isSilver() {
    return getPlanName().compare(SILVER);
}

bool Plan::isOnion() {
    return getPlanName().compare(ONION);
}
