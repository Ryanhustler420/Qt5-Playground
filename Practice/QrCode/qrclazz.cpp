#include "qrclazz.h"

QrClazz::QrClazz(QObject *parent) : QObject(parent)
{
    // QZXing::registerQMLTypes(); // error
    // QZXing::registerQMLImageProvider(engine); // error
}

QString QrClazz::parseImage(QString image_path)
{
    QImage imageToDecode(image_path);
    QZXing decoder;

    // mandatory settings
    decoder.setDecoder( QZXing::DecoderFormat_QR_CODE | QZXing::DecoderFormat_EAN_13 );

    // optional settings
    // decoder.setSourceFilterType(QZXing::SourceFilter_ImageNormal | QZXing::SourceFilter_ImageInverted);
    decoder.setSourceFilterType(QZXing::SourceFilter_ImageNormal);
    decoder.setTryHarderBehaviour(QZXing::TryHarderBehaviour_ThoroughScanning | QZXing::TryHarderBehaviour_Rotate);

    // trigger decode
    return decoder.decodeImage(imageToDecode);
}

QImage QrClazz::convert(QString data)
{
    return QZXing::encodeData(data);
    // return QZXing::encodeData(data, QZXing::EncoderFormat_QR_CODE, QSize(500, 500), QZXing::EncodeErrorCorrectionLevel_H);
}
