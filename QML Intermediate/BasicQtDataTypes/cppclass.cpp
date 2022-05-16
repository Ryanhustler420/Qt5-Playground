#include <QDebug>
#include "cppclass.h"

CppClass::CppClass(QObject *parent) : QObject(parent)
{

}

void CppClass::cppSlot()
{
    qDebug() << "cppSlot called";
    emit sendInt(123);
    emit sendDouble(123.45);
    emit sendBoolRealFloat(true,34.12,456.2);
    emit sendStringUrl("String from C++",QUrl("http://www.raisehand.software"));

    emit sendColorFont(QColor(123,20,30),QFont("Times", 20, QFont::Bold));

    //emit sendDate(QDate (1995, 5, 17));
    emit sendDate(QDate::currentDate());

    emit sendPoint(QPoint(100,200),QPointF(45.54,87.34));

    emit sendSize(QSize(200,500),QSizeF(200.45,500.45));
    emit sendRect(QRect(100,100,300,300),QRectF(105.5,105.5,200.4,200.4));

}

void CppClass::receivePoint(QPoint point)
{
    qDebug() << "Received point from QML :" << point ;
}

void CppClass::receiveRect(QRectF rect)
{
    qDebug() << "Received rect from QML :" << rect ;
}
