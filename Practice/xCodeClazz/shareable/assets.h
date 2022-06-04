#ifndef ASSETS_H
#define ASSETS_H

#include <QObject>

class Assets : public QObject
{
    Q_OBJECT
public:
    explicit Assets(QObject *parent = nullptr);

    Q_INVOKABLE QString getEncodeSans_Black() { return "qrc:/assets/assets/encode-sans/EncodeSans-Black.ttf"; }
    Q_INVOKABLE QString getEncodeSans_Bold() { return "qrc:/assets/assets/encode-sans/EncodeSans-Bold.ttf"; }
    Q_INVOKABLE QString getEncodeSans_ExtraBold() { return "qrc:/assets/assets/encode-sans/EncodeSans-ExtraBold.ttf"; }
    Q_INVOKABLE QString getEncodeSans_ExtraLight() { return "qrc:/assets/assets/encode-sans/EncodeSans-ExtraLight.ttf"; }
    Q_INVOKABLE QString getEncodeSans_Light() { return "qrc:/assets/assets/encode-sans/EncodeSans-Light.ttf"; }
    Q_INVOKABLE QString getEncodeSans_Medium() { return "qrc:/assets/assets/encode-sans/EncodeSans-Medium.ttf"; }
    Q_INVOKABLE QString getEncodeSans_Regular() { return "qrc:/assets/assets/encode-sans/EncodeSans-Regular.ttf"; }
    Q_INVOKABLE QString getEncodeSans_SemiBold() { return "qrc:/assets/assets/encode-sans/EncodeSans-SemiBold.ttf"; }
    Q_INVOKABLE QString getEncodeSans_Thin() { return "qrc:/assets/assets/encode-sans/EncodeSans-Thin.ttf"; }

    Q_INVOKABLE QString getEncodeSansCondensed_Black() { return "qrc:/assets/assets/encode-sans/EncodeSansCondensed-Black.ttf"; }
    Q_INVOKABLE QString getEncodeSansCondensed_Bold() { return "qrc:/assets/assets/encode-sans/EncodeSansCondensed-Bold.ttf"; }
    Q_INVOKABLE QString getEncodeSansCondensed_ExtraBold() { return "qrc:/assets/assets/encode-sans/EncodeSansCondensed-ExtraBold.ttf"; }
    Q_INVOKABLE QString getEncodeSansCondensed_ExtraLight() { return "qrc:/assets/assets/encode-sans/EncodeSansCondensed-ExtraLight.ttf"; }
    Q_INVOKABLE QString getEncodeSansCondensed_Light() { return "qrc:/assets/assets/encode-sans/EncodeSansCondensed-Light.ttf"; }
    Q_INVOKABLE QString getEncodeSansCondensed_Medium() { return "qrc:/assets/assets/encode-sans/EncodeSansCondensed-Medium.ttf"; }
    Q_INVOKABLE QString getEncodeSansCondensed_Regular() { return "qrc:/assets/assets/encode-sans/EncodeSansCondensed-Regular.ttf"; }
    Q_INVOKABLE QString getEncodeSansCondensed_SemiBold() { return "qrc:/assets/assets/encode-sans/EncodeSansCondensed-SemiBold.ttf"; }
    Q_INVOKABLE QString getEncodeSansCondensed_Thin() { return "qrc:/assets/assets/encode-sans/EncodeSansCondensed-Thin.ttf"; }

    Q_INVOKABLE QString getEncodeSansExpanded_Black() { return "qrc:/assets/assets/encode-sans/EncodeSansExpanded-Black.ttf"; }
    Q_INVOKABLE QString getEncodeSansExpanded_Bold() { return "qrc:/assets/assets/encode-sans/EncodeSansExpanded-Bold.ttf"; }
    Q_INVOKABLE QString getEncodeSansExpanded_ExtraBold() { return "qrc:/assets/assets/encode-sans/EncodeSansExpanded-ExtraBold.ttf"; }
    Q_INVOKABLE QString getEncodeSansExpanded_ExtraLight() { return "qrc:/assets/assets/encode-sans/EncodeSansExpanded-ExtraLight.ttf"; }
    Q_INVOKABLE QString getEncodeSansExpanded_Light() { return "qrc:/assets/assets/encode-sans/EncodeSansExpanded-Light.ttf"; }
    Q_INVOKABLE QString getEncodeSansExpanded_Medium() { return "qrc:/assets/assets/encode-sans/EncodeSansExpanded-Medium.ttf"; }
    Q_INVOKABLE QString getEncodeSansExpanded_Regular() { return "qrc:/assets/assets/encode-sans/EncodeSansExpanded-Regular.ttf"; }
    Q_INVOKABLE QString getEncodeSansExpanded_SemiBold() { return "qrc:/assets/assets/encode-sans/EncodeSansExpanded-SemiBold.ttf"; }
    Q_INVOKABLE QString getEncodeSansExpanded_Thin() { return "qrc:/assets/assets/encode-sans/EncodeSansExpanded-Thin.ttf"; }

    Q_INVOKABLE QString getEncodeSansSemiCondensed_Black() { return "qrc:/assets/assets/encode-sans/EncodeSansSemiCondensed-Black.ttf"; }
    Q_INVOKABLE QString getEncodeSansSemiCondensed_Bold() { return "qrc:/assets/assets/encode-sans/EncodeSansSemiCondensed-Bold.ttf"; }
    Q_INVOKABLE QString getEncodeSansSemiCondensed_ExtraBold() { return "qrc:/assets/assets/encode-sans/EncodeSansSemiCondensed-ExtraBold.ttf"; }
    Q_INVOKABLE QString getEncodeSansSemiCondensed_ExtraLight() { return "qrc:/assets/assets/encode-sans/EncodeSansSemiCondensed-ExtraLight.ttf"; }
    Q_INVOKABLE QString getEncodeSansSemiCondensed_Light() { return "qrc:/assets/assets/encode-sans/EncodeSansSemiCondensed-Light.ttf"; }
    Q_INVOKABLE QString getEncodeSansSemiCondensed_Medium() { return "qrc:/assets/assets/encode-sans/EncodeSansSemiCondensed-Medium.ttf"; }
    Q_INVOKABLE QString getEncodeSansSemiCondensed_Regular() { return "qrc:/assets/assets/encode-sans/EncodeSansSemiCondensed-Regular.ttf"; }
    Q_INVOKABLE QString getEncodeSansSemiCondensed_SemiBold() { return "qrc:/assets/assets/encode-sans/EncodeSansSemiCondensed-SemiBold.ttf"; }
    Q_INVOKABLE QString getEncodeSansSemiCondensed_Thin() { return "qrc:/assets/assets/encode-sans/EncodeSansSemiCondensed-Thin.ttf"; }

    Q_INVOKABLE QString getEncodeSansSemiExpanded_Black() { return "qrc:/assets/assets/encode-sans/EncodeSansSemiExpanded-Black.ttf"; }
    Q_INVOKABLE QString getEncodeSansSemiExpanded_Bold() { return "qrc:/assets/assets/encode-sans/EncodeSansSemiExpanded-Bold.ttf"; }
    Q_INVOKABLE QString getEncodeSansSemiExpanded_ExtraBold() { return "qrc:/assets/assets/encode-sans/EncodeSansSemiExpanded-ExtraBold.ttf"; }
    Q_INVOKABLE QString getEncodeSansSemiExpanded_ExtraLight() { return "qrc:/assets/assets/encode-sans/EncodeSansSemiExpanded-ExtraLight.ttf"; }
    Q_INVOKABLE QString getEncodeSansSemiExpanded_Light() { return "qrc:/assets/assets/encode-sans/EncodeSansSemiExpanded-Light.ttf"; }
    Q_INVOKABLE QString getEncodeSansSemiExpanded_Medium() { return "qrc:/assets/assets/encode-sans/EncodeSansSemiExpanded-Medium.ttf"; }
    Q_INVOKABLE QString getEncodeSansSemiExpanded_Regular() { return "qrc:/assets/assets/encode-sans/EncodeSansSemiExpanded-Regular.ttf"; }
    Q_INVOKABLE QString getEncodeSansSemiExpanded_SemiBold() { return "qrc:/assets/assets/encode-sans/EncodeSansSemiExpanded-SemiBold.ttf"; }
    Q_INVOKABLE QString getEncodeSansSemiExpanded_Thin() { return "qrc:/assets/assets/encode-sans/EncodeSansSemiExpanded-Thin.ttf"; }

signals:

};

#endif // ASSETS_H
