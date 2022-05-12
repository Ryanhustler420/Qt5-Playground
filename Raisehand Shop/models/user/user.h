#ifndef USER_H
#define USER_H

#include "models/user/mycontributionofrepoproduct.h"
#include "models/user/repoproductmergerequest.h"
#include "models/user/repoaccesspasscode.h"
#include "models/god/modelconventions.h"
#include "models/user/signedbydevice.h"
#include "models/user/signedinvia.h"
#include "models/user/token.h"

class User : public ModelConventions<User>
{
    Q_OBJECT
public:
    explicit User(QObject *parent = nullptr);
    User(const QString &id, int actor, QList<int> *roles, const QString &email, const QString &password, const QString &name, const QString &dob, const QString &gender, const QString &phone, const QString &imageUrl, const QString &imageContainer, const QString &address, const QString &country, const QString &state, const QString &city, QList<Token> *tokens, bool hasShopInit, bool hasShop, bool hasProductRepositoryInit, bool hasProductRepository, QList<QString> *repoProductSeens, SignedInVia *signedInVia, QList<SignedByDevice> *signedInUserFrom, QList<RepoAccessPasscode> *repoAccessPasscodes, QList<RepoProductMergeRequest> *mergeRequests, QList<MyContributionOfRepoProduct> *myContributionOfRepoProducts, bool allowToCreateShopProfile, bool allowToCreateProductRepository, bool hasRequestedToJoinShop, bool hasRequestedToJoinRepository, bool createdAt, const QString &updatedAt);

private:
   QString _id;
   int actor;
   QList<int>* roles;
   QString email;
   QString password;
   QString name;
   QString dob;
   QString gender;
   QString phone;
   QString imageUrl;
   QString imageContainer;
   QString address;
   QString country;
   QString state;
   QString city;
   QList<Token>* tokens;
   bool hasShopInit;
   bool hasShop;
   bool hasProductRepositoryInit;
   bool hasProductRepository;
   QList<QString>* repoProductSeens;
   SignedInVia* signedInVia;
   QList<SignedByDevice>* signedInUserFrom;
   QList<RepoAccessPasscode>* repoAccessPasscodes;
   QList<RepoProductMergeRequest>* mergeRequests;
   QList<MyContributionOfRepoProduct>* myContributionOfRepoProducts;
   bool allowToCreateShopProfile;
   bool allowToCreateProductRepository;
   bool hasRequestedToJoinShop;
   bool hasRequestedToJoinRepository;
   bool createdAt;
   QString updatedAt;

private:
   typedef struct FIELDS {
       QString _id = "_id";
       QString actor = "actor";
       QString roles = "roles";
       QString email = "email";
       QString password = "password";
       QString name = "name";
       QString dob = "dob";
       QString gender = "gender";
       QString phone = "phone";
       QString imageUrl = "imageUrl";
       QString imageContainer = "imageContainer";
       QString address = "address";
       QString country = "country";
       QString state = "state";
       QString city = "city";
       QString tokens = "tokens";
       QString hasShopInit = "hasShopInit";
       QString hasShop = "hasShop";
       QString hasProductRepositoryInit = "hasProductRepositoryInit";
       QString hasProductRepository = "hasProductRepository";
       QString repoProductSeens = "repoProductSeens";
       QString signedInVia = "signedInVia";
       QString signedInUserFrom = "signedInUserFrom";
       QString repoAccessPasscodes = "repoAccessPasscodes";
       QString mergeRequests = "mergeRequests";
       QString myContributionOfRepoProducts = "myContributionOfRepoProducts";
       QString allowToCreateShopProfile = "allowToCreateShopProfile";
       QString allowToCreateProductRepository = "allowToCreateProductRepository";
       QString hasRequestedToJoinShop = "hasRequestedToJoinShop";
       QString hasRequestedToJoinRepository = "hasRequestedToJoinRepository";
       QString createdAt = "createdAt";
       QString updatedAt = "updatedAt";
   } _fields;

   _fields *fields;

signals:

    // ModelConventions interface
public:
    QList<QString> getAllFields();
    QString getPackageName();
    QList<User *> parseJSONArray(QJsonArray o) throw();
    User *parseJSONObject(QJsonObject o) throw();
    QList<User *> parseArrayString(QString o) throw();
    User *parseObjectString(QString o) throw();
    bool equal(User *o);

public:

    const QString &getId() const;
    void setId(const QString &newId);
    int getActor() const;
    void setActor(int newActor);
    QList<int> *getRoles() const;
    void setRoles(QList<int> *newRoles);
    const QString &getEmail() const;
    void setEmail(const QString &newEmail);
    const QString &getPassword() const;
    void setPassword(const QString &newPassword);
    const QString &getName() const;
    void setName(const QString &newName);
    const QString &getDob() const;
    void setDob(const QString &newDob);
    const QString &getGender() const;
    void setGender(const QString &newGender);
    const QString &getPhone() const;
    void setPhone(const QString &newPhone);
    const QString &getImageUrl() const;
    void setImageUrl(const QString &newImageUrl);
    const QString &getImageContainer() const;
    void setImageContainer(const QString &newImageContainer);
    const QString &getAddress() const;
    void setAddress(const QString &newAddress);
    const QString &getCountry() const;
    void setCountry(const QString &newCountry);
    const QString &getState() const;
    void setState(const QString &newState);
    const QString &getCity() const;
    void setCity(const QString &newCity);
    QList<Token> *getTokens() const;
    void setTokens(QList<Token> *newTokens);
    bool getHasShopInit() const;
    void setHasShopInit(bool newHasShopInit);
    bool getHasShop() const;
    void setHasShop(bool newHasShop);
    bool getHasProductRepositoryInit() const;
    void setHasProductRepositoryInit(bool newHasProductRepositoryInit);
    bool getHasProductRepository() const;
    void setHasProductRepository(bool newHasProductRepository);
    QList<QString> *getRepoProductSeens() const;
    void setRepoProductSeens(QList<QString> *newRepoProductSeens);
    SignedInVia *getSignedInVia() const;
    void setSignedInVia(SignedInVia *newSignedInVia);
    QList<SignedByDevice> *getSignedInUserFrom() const;
    void setSignedInUserFrom(QList<SignedByDevice> *newSignedInUserFrom);
    QList<RepoAccessPasscode> *getRepoAccessPasscodes() const;
    void setRepoAccessPasscodes(QList<RepoAccessPasscode> *newRepoAccessPasscodes);
    QList<RepoProductMergeRequest> *getMergeRequests() const;
    void setMergeRequests(QList<RepoProductMergeRequest> *newMergeRequests);
    QList<MyContributionOfRepoProduct> *getMyContributionOfRepoProducts() const;
    void setMyContributionOfRepoProducts(QList<MyContributionOfRepoProduct> *newMyContributionOfRepoProducts);
    bool getAllowToCreateShopProfile() const;
    void setAllowToCreateShopProfile(bool newAllowToCreateShopProfile);
    bool getAllowToCreateProductRepository() const;
    void setAllowToCreateProductRepository(bool newAllowToCreateProductRepository);
    bool getHasRequestedToJoinShop() const;
    void setHasRequestedToJoinShop(bool newHasRequestedToJoinShop);
    bool getHasRequestedToJoinRepository() const;
    void setHasRequestedToJoinRepository(bool newHasRequestedToJoinRepository);
    bool getCreatedAt() const;
    void setCreatedAt(bool newCreatedAt);
    const QString &getUpdatedAt() const;
    void setUpdatedAt(const QString &newUpdatedAt);

    bool hasManagementRole() const;
    static QString about(User o);
};

#endif // USER_H
