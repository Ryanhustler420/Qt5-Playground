#include "utility/hotkeyhandler.h"

HotKeyHandler::HotKeyHandler(QObject *parent, QWidget *widget) : QObject(parent)
{
    this->widget = widget;
}

HotKeyHandler::~HotKeyHandler()
{
    this->widget->deleteLater();
    this->widget = nullptr;
}

void HotKeyHandler::ctrl_plus_return_key(function<void(QString)> callback)
{
    QShortcut *shortcut = new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_Return), widget);
    QObject::connect(shortcut, &QShortcut::activated, this, [=]() {callback("ctrl+return");});
}

void HotKeyHandler::ctrl_plus_k_key(function<void(QString)> callback)
{
    QShortcut *shortcut = new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_K), widget);
    QObject::connect(shortcut, &QShortcut::activated, this, [=]() {callback("ctrl+k");});
}
