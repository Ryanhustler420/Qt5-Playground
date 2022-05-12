#include "models\user\user.h"

User::User(const QString &id, int actor, QList<int> *roles, const QString &email, const QString &password, const QString &name, const QString &dob, const QString &gender, const QString &phone, const QString &imageUrl, const QString &imageContainer, const QString &address, const QString &country, const QString &state, const QString &city, QList<Token> *tokens, bool hasShopInit, bool hasShop, bool hasProductRepositoryInit, bool hasProductRepository, QList<QString> *repoProductSeens, SignedInVia *signedInVia, QList<SignedByDevice> *signedInUserFrom, QList<RepoAccessPasscode> *repoAccessPasscodes, QList<RepoProductMergeRequest> *mergeRequests, QList<MyContributionOfRepoProduct> *myContributionOfRepoProducts, bool allowToCreateShopProfile, bool allowToCreateProductRepository, bool hasRequestedToJoinShop, bool hasRequestedToJoinRepository, bool createdAt, const QString &updatedAt)
{
    this->_id = id;
    this->actor = actor;
    this->roles = roles;
    this->email = email;
    this->password = password;
    this->name = name;
    this->dob = dob;
    this->gender = gender;
    this->phone = phone;
    this->imageUrl = imageUrl;
    this->imageContainer = imageContainer;
    this->address = address;
    this->country = country;
    this->state = state;
    this->city = city;
    this->tokens = tokens;
    this->hasShopInit = hasShopInit;
    this->hasShop = hasShop;
    this->hasProductRepositoryInit = hasProductRepositoryInit;
    this->hasProductRepository = hasProductRepository;
    this->repoProductSeens = repoProductSeens;
    this->signedInVia = signedInVia;
    this->signedInUserFrom = signedInUserFrom;
    this->repoAccessPasscodes = repoAccessPasscodes;
    this->mergeRequests = mergeRequests;
    this->myContributionOfRepoProducts = myContributionOfRepoProducts;
    this->allowToCreateShopProfile = allowToCreateShopProfile;
    this->allowToCreateProductRepository = allowToCreateProductRepository;
    this->hasRequestedToJoinShop = hasRequestedToJoinShop;
    this->hasRequestedToJoinRepository = hasRequestedToJoinRepository;
    this->createdAt = createdAt;
    this->updatedAt = updatedAt;
    this->className = "User";
    this->fields = new _fields();
}

const QString &User::getUpdatedAt() const
{
    return updatedAt;
}

void User::setUpdatedAt(const QString &newUpdatedAt)
{
    updatedAt = newUpdatedAt;
}

bool User::getCreatedAt() const
{
    return createdAt;
}

void User::setCreatedAt(bool newCreatedAt)
{
    createdAt = newCreatedAt;
}

bool User::getHasRequestedToJoinRepository() const
{
    return hasRequestedToJoinRepository;
}

void User::setHasRequestedToJoinRepository(bool newHasRequestedToJoinRepository)
{
    hasRequestedToJoinRepository = newHasRequestedToJoinRepository;
}

bool User::getHasRequestedToJoinShop() const
{
    return hasRequestedToJoinShop;
}

void User::setHasRequestedToJoinShop(bool newHasRequestedToJoinShop)
{
    hasRequestedToJoinShop = newHasRequestedToJoinShop;
}

bool User::getAllowToCreateProductRepository() const
{
    return allowToCreateProductRepository;
}

void User::setAllowToCreateProductRepository(bool newAllowToCreateProductRepository)
{
    allowToCreateProductRepository = newAllowToCreateProductRepository;
}

bool User::getAllowToCreateShopProfile() const
{
    return allowToCreateShopProfile;
}

void User::setAllowToCreateShopProfile(bool newAllowToCreateShopProfile)
{
    allowToCreateShopProfile = newAllowToCreateShopProfile;
}

QList<MyContributionOfRepoProduct> *User::getMyContributionOfRepoProducts() const
{
    return myContributionOfRepoProducts;
}

void User::setMyContributionOfRepoProducts(QList<MyContributionOfRepoProduct> *newMyContributionOfRepoProducts)
{
    myContributionOfRepoProducts = newMyContributionOfRepoProducts;
}

QList<RepoProductMergeRequest> *User::getMergeRequests() const
{
    return mergeRequests;
}

void User::setMergeRequests(QList<RepoProductMergeRequest> *newMergeRequests)
{
    mergeRequests = newMergeRequests;
}

QList<RepoAccessPasscode> *User::getRepoAccessPasscodes() const
{
    return repoAccessPasscodes;
}

void User::setRepoAccessPasscodes(QList<RepoAccessPasscode> *newRepoAccessPasscodes)
{
    repoAccessPasscodes = newRepoAccessPasscodes;
}

QList<SignedByDevice> *User::getSignedInUserFrom() const
{
    return signedInUserFrom;
}

void User::setSignedInUserFrom(QList<SignedByDevice> *newSignedInUserFrom)
{
    signedInUserFrom = newSignedInUserFrom;
}

SignedInVia *User::getSignedInVia() const
{
    return signedInVia;
}

void User::setSignedInVia(SignedInVia *newSignedInVia)
{
    signedInVia = newSignedInVia;
}

QList<QString> *User::getRepoProductSeens() const
{
    return repoProductSeens;
}

void User::setRepoProductSeens(QList<QString> *newRepoProductSeens)
{
    repoProductSeens = newRepoProductSeens;
}

bool User::getHasProductRepository() const
{
    return hasProductRepository;
}

void User::setHasProductRepository(bool newHasProductRepository)
{
    hasProductRepository = newHasProductRepository;
}

bool User::getHasProductRepositoryInit() const
{
    return hasProductRepositoryInit;
}

void User::setHasProductRepositoryInit(bool newHasProductRepositoryInit)
{
    hasProductRepositoryInit = newHasProductRepositoryInit;
}

bool User::getHasShop() const
{
    return hasShop;
}

void User::setHasShop(bool newHasShop)
{
    hasShop = newHasShop;
}

bool User::getHasShopInit() const
{
    return hasShopInit;
}

void User::setHasShopInit(bool newHasShopInit)
{
    hasShopInit = newHasShopInit;
}

QList<Token> *User::getTokens() const
{
    return tokens;
}

void User::setTokens(QList<Token> *newTokens)
{
    tokens = newTokens;
}

const QString &User::getCity() const
{
    return city;
}

void User::setCity(const QString &newCity)
{
    city = newCity;
}

const QString &User::getState() const
{
    return state;
}

void User::setState(const QString &newState)
{
    state = newState;
}

const QString &User::getCountry() const
{
    return country;
}

void User::setCountry(const QString &newCountry)
{
    country = newCountry;
}

const QString &User::getAddress() const
{
    return address;
}

void User::setAddress(const QString &newAddress)
{
    address = newAddress;
}

const QString &User::getImageContainer() const
{
    return imageContainer;
}

void User::setImageContainer(const QString &newImageContainer)
{
    imageContainer = newImageContainer;
}

const QString &User::getImageUrl() const
{
    return imageUrl;
}

void User::setImageUrl(const QString &newImageUrl)
{
    imageUrl = newImageUrl;
}

const QString &User::getPhone() const
{
    return phone;
}

void User::setPhone(const QString &newPhone)
{
    phone = newPhone;
}

const QString &User::getGender() const
{
    return gender;
}

void User::setGender(const QString &newGender)
{
    gender = newGender;
}

const QString &User::getDob() const
{
    return dob;
}

void User::setDob(const QString &newDob)
{
    dob = newDob;
}

const QString &User::getName() const
{
    return name;
}

void User::setName(const QString &newName)
{
    name = newName;
}

const QString &User::getPassword() const
{
    return password;
}

void User::setPassword(const QString &newPassword)
{
    password = newPassword;
}

const QString &User::getEmail() const
{
    return email;
}

void User::setEmail(const QString &newEmail)
{
    email = newEmail;
}

QList<int> *User::getRoles() const
{
    return roles;
}

void User::setRoles(QList<int> *newRoles)
{
    roles = newRoles;
}

int User::getActor() const
{
    return actor;
}

void User::setActor(int newActor)
{
    actor = newActor;
}

const QString &User::getId() const
{
    return _id;
}

void User::setId(const QString &newId)
{
    _id = newId;
}

QList<QString> User::getAllFields()
{

}

QString User::getPackageName()
{
    return this->className;
}

QList<User *> User::parseJSONArray(QJsonArray o) throw()
{

}

User *User::parseJSONObject(QJsonObject o) throw()
{

}

QList<User *> User::parseArrayString(QString o) throw()
{

}

User *User::parseObjectString(QString o) throw()
{

}

bool User::equal(User *o)
{
    return o == this;
}


bool User::hasManagementRole() const
{
    for (int var = 0; var < getRoles()->size(); ++var) {
        if (getRoles()->at(var) == 1) {
            return true;
        }
    }
    return false;
}

QString User::about(User o)
{
    QByteArray d;
    d
            .append("User ").append(o.getName())
            .append(" who has email: ").append(o.getEmail())
            .append(", phone: ").append(o.getPhone())
            .append(", address: ").append(o.getAddress())
            .append(", checkout ").append(o.getGender().compare(Female) ? "her" : "his")
            .append(" avatar: ").append(o.getImageUrl());
    return d;
}
