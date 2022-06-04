#ifndef FONTS_H
#define FONTS_H

#include <QString>
#include <QObject>
#include <QDebug>

class Fonts: public QObject {

    Q_OBJECT
public:
    explicit Fonts(QObject *parent = nullptr);
    Q_INVOKABLE QString getEncode_sans_extra_light() { return "qrc:/assets/assets/encode-sans/EncodeSans-ExtraLight.ttf"; }
    Q_INVOKABLE void ss() {
        qInfo() << "sds";
    }

signals:

};

inline Fonts::Fonts(QObject *parent)
{
    Q_UNUSED(parent);
}

#endif // FONTS_H
