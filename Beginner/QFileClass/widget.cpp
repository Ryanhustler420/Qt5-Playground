#include "widget.h"
#include "ui_widget.h"

#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_writeBtn_clicked()
{
    // Save the file
    QString filename = QFileDialog::getSaveFileName(this, "Save As");
    if(filename.isEmpty())
        return;

    QFile file(filename);
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append))
        return;

    QTextStream out(&file);

    out << ui->textEdit->toPlainText() << "\n";

    file.close();
}

void Widget::on_readBtn_clicked()
{

    QString fileContent;

    // Read from the file
    QString filename = QFileDialog::getOpenFileName(this, "Open File");
    if (filename.isEmpty())
        return;

    QFile file(filename);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QTextStream in(&file);

    QString line = in.readLine();
    while(!line.isNull()) {
        fileContent.append(line);
        line = in.readLine();
    }

    file.close();

    ui->textEdit->clear();
    ui->textEdit->setPlainText(fileContent);

}

void Widget::on_selectFileBtn_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, "Choose File");
    if(filename.isEmpty())
        return;

    ui->sourceLineEdit->setText(filename);
}


void Widget::on_copyBtn_clicked()
{
    QString srcFileName = ui->sourceLineEdit->text();
    QString desFileName = ui->destinationLineEdit->text();

    if (srcFileName.isEmpty() || desFileName.isEmpty())
        return;

    QFile file(srcFileName);
    if (file.copy(desFileName)) {
        QMessageBox::information(this, "Success", "Copied Successfully");
    } else {
        QMessageBox::warning(this, "Failuer", "Copied Failed");
    }

}

