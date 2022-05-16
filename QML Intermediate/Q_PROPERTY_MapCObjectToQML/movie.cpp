#include "movie.h"
#include <QDebug>

Movie::Movie(QObject *parent) : QObject(parent),
    m_title("Moview Title"),
    m_mainCharacter("Main Character")
{

}

const QString &Movie::mainCharacter() const
{
    qDebug() << "Getting the main character";
    return m_mainCharacter;
}

void Movie::setMainCharacter(const QString &newMainCharacter)
{
    qDebug() << "Setting the main character";
    if (m_mainCharacter == newMainCharacter)
        return;
    m_mainCharacter = newMainCharacter;
    emit mainCharacterChange();
}

const QString &Movie::title() const
{
    qDebug() << "Getting the title";
    return m_title;
}

void Movie::setTitle(const QString &newTitle)
{
    qDebug() << "Setting the title";
    if (m_title == newTitle)
        return;
    m_title = newTitle;
    emit titleChanged();
}
