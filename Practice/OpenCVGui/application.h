#ifndef APPLICATION_H
#define APPLICATION_H

#include <QObject>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

class Application : public QObject
{
    Q_OBJECT
public:
    explicit Application(QObject *parent = nullptr);

    Q_INVOKABLE void load(QString imagePath);

signals:

};

#endif // APPLICATION_H
