#ifndef QRCLAZZ_H
#define QRCLAZZ_H

#include <QObject>
#include <QImage>

#include "QZXing.h"
#include "QZXing"

class QrClazz : public QObject
{
    Q_OBJECT
public:
    explicit QrClazz(QObject *parent = nullptr);
    Q_INVOKABLE QString parseImage(QString image_path);
    Q_INVOKABLE QImage convert(QString data);

signals:

};

#endif // QRCLAZZ_H
