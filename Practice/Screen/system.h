#ifndef SYSTEM_H
#define SYSTEM_H

#include <QRect>
#include <QDebug>
#include <QObject>
#include <QScreen>
#include <QGuiApplication>

class System : public QObject
{
    Q_OBJECT
public:
    explicit System(QObject *parent = nullptr);

    typedef struct WIDGET_SIZE_CHART { int S1900_786 = 1; } widget_size_chart;
    typedef struct FONT_SIZE_CHART { int S1900_786 = 1; } font_size_chart;

    Q_INVOKABLE     QString     getScreenSize();
    Q_INVOKABLE     void        setWindowSize(QString height, QString width);

signals:
    void    h1FontSizeChanged   (int oldSize, int newSize);
    void    h2FontSizeChanged   (int oldSize, int newSize);

    void    widgetSizeChanged   (int oldSize, int newSize);
    void    windowSizeChanged   (QString height, QString width);

public:
    int h1FontSize = 10;        // default
    Q_INVOKABLE     int         getH1FontSize() { return h1FontSize; };
    Q_INVOKABLE     void        changeH1FontSize(int val);

    int h2FontSize = 10;        // default
    Q_INVOKABLE     int         getH2FontSize() { return h2FontSize; };
    Q_INVOKABLE     void        changeH2FontSize(int val);

    int widgetSize = 10;        // default
    Q_INVOKABLE     int         getWidgetSize() { return widgetSize; };
    Q_INVOKABLE     void        changeWidgetSize(int val);

private:
    widget_size_chart *ws;
    font_size_chart *fs;

};

#endif // SYSTEM_H
