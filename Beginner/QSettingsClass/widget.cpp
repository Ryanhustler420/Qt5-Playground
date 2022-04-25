#include "widget.h"
#include "ui_widget.h"
#include <QColorDialog>
#include <QSettings>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    int totalBtns = 9;
    for (int var = 0; var < totalBtns; ++var) {
        colorList.append(Qt::black);
    }
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_oneBtn_clicked()
{
    updateBtnBg(ui->oneBtn, 0);
}

void Widget::on_twoBtn_clicked()
{
    updateBtnBg(ui->twoBtn, 1);
}

void Widget::on_threeBtn_clicked()
{
    updateBtnBg(ui->threeBtn, 2);
}

void Widget::on_fourBtn_clicked()
{
    updateBtnBg(ui->fourBtn, 3);
}

void Widget::on_fiveBtn_clicked()
{
    updateBtnBg(ui->fiveBtn, 4);
}

void Widget::on_sixBtn_clicked()
{
    updateBtnBg(ui->sixBtn, 5);
}

void Widget::on_sevenBtn_clicked()
{
    updateBtnBg(ui->sevenBtn, 6);
}

void Widget::on_eightBtn_clicked()
{
    updateBtnBg(ui->eightBtn, 7);
}

void Widget::on_nineBtn_clicked()
{
    updateBtnBg(ui->nineBtn, 8);
}

void Widget::on_loadBtn_clicked()
{
    setLoadedColor("button1", 0, ui->oneBtn);
    setLoadedColor("button2", 1, ui->twoBtn);
    setLoadedColor("button3", 2, ui->threeBtn);
    setLoadedColor("button4", 3, ui->fourBtn);
    setLoadedColor("button5", 4, ui->fiveBtn);
    setLoadedColor("button6", 5, ui->sixBtn);
    setLoadedColor("button7", 6, ui->sevenBtn);
    setLoadedColor("button8", 7, ui->eightBtn);
    setLoadedColor("button9", 8, ui->nineBtn);
}

void Widget::on_saveBtn_clicked()
{
    saveColor("button1", colorList[0]);
    saveColor("button2", colorList[1]);
    saveColor("button3", colorList[2]);
    saveColor("button4", colorList[3]);
    saveColor("button5", colorList[4]);
    saveColor("button6", colorList[5]);
    saveColor("button7", colorList[6]);
    saveColor("button8", colorList[7]);
    saveColor("button9", colorList[8]);
}

void Widget::updateBtnBg(QPushButton *qPushBtn, int indexOnList = 0)
{
    QColor color = QColorDialog::getColor(colorList[indexOnList], this, "Choose Bankground Color");
    if (color.isValid()) {
        // Save the color in the list in memory
        colorList[indexOnList] = color;

        // Set background color on the button
        QString css = QString("background-color : %1").arg(color.name());
        qPushBtn->setStyleSheet(css);
    }
}

void Widget::saveColor(QString key, QColor color)
{
    int red = color.red();
    int green = color.green();
    int blue = color.blue();

    QSettings settings("Raisehand", "SettingsDemo");
    settings.beginGroup("ButtonColor");

    settings.setValue(key + "r", red);
    settings.setValue(key + "g", green);
    settings.setValue(key + "b", blue);

    settings.endGroup();
}

QColor Widget::loadColor(QString key)
{
    int red, green, blue;

    QSettings settings("Raisehand", "SettingsDemo");
    settings.beginGroup("ButtonColor");

    red = settings.value(key+"r", QVariant(0)).toInt();
    blue = settings.value(key+"b", QVariant(0)).toInt();
    green = settings.value(key+"g", QVariant(0)).toInt();

    settings.endGroup();

    return QColor(red, green, blue);
}

void Widget::setLoadedColor(QString key, int indexOnList, QPushButton *qPushBtn)
{
    QColor color = loadColor(key);
    colorList[indexOnList] = color;

    QString css = QString("background-color : %1").arg(color.name());
    qPushBtn->setStyleSheet(css);
}
