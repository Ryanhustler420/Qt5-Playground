#ifndef TAG_H
#define TAG_H

#include "models/god/modelconventions.h"

class Tag : public ModelConventions<Tag>
{
    Q_OBJECT
public:
    explicit Tag(QObject *parent = nullptr);
    Tag(const QString &title);


private:
    QString title;

private:
    typedef struct FIELDS {
        QString title = "title";
    } _fields;

    _fields *fields;

signals:

    // ModelConventions interface
public:
    QList<QString> getAllFields();
    QString getPackageName();
    QList<Tag *> parseJSONArray(QJsonArray o) throw();
    Tag *parseJSONObject(QJsonObject o) throw();
    QList<Tag *> parseArrayString(QString o) throw();
    Tag *parseObjectString(QString o) throw();
    bool equal(Tag *o);

    const QString &getTitle() const;
    void setTitle(const QString &newTitle);
};

#endif // TAG_H
