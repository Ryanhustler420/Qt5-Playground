#ifndef HOTKEYHANDLER_H
#define HOTKEYHANDLER_H

#include <QObject>
#include <QWidget>
#include <QShortcut>
#include <QKeySequence>
#include <QShortcutEvent>

#include <bits/stdc++.h>
#include <stdexcept>

using namespace std;
using namespace chrono;

class HotKeyHandler : public QObject
{
public:
    explicit HotKeyHandler(QObject *parent = nullptr, QWidget *widget = 0);
    ~HotKeyHandler();

signals:

public slots:
    void ctrl_plus_return_key(function<void(QString)> callback);
    void ctrl_plus_k_key(function<void(QString)> callback);

private:
    QWidget *widget;

};

#endif // HOTKEYHANDLER_H
