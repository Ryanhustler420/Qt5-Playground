#ifndef MOVIE_H
#define MOVIE_H

#include <QObject>

class Movie : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString mainCharacter READ mainCharacter WRITE setMainCharacter NOTIFY mainCharacterChange)
    Q_PROPERTY(QString title READ title WRITE setTitle NOTIFY titleChanged)
public:
    explicit Movie(QObject *parent = nullptr);

    const QString &mainCharacter() const;
    void setMainCharacter(const QString &newMainCharacter);

    const QString &title() const;
    void setTitle(const QString &newTitle);

signals:
    void mainCharacterChange();
    void titleChanged();

private:
    QString m_mainCharacter;
    QString m_title;

};

#endif // MOVIE_H
