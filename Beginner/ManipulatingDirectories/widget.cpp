#include "widget.h"
#include "ui_widget.h"

#include <QFileDialog>
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


void Widget::on_chooseDirBtn_clicked()
{
    QString filename = QFileDialog::getExistingDirectory(this, "Choose Folder");
    if (filename.isEmpty()) {
        return;
    }
    ui->lineEdit->setText(filename);
}


void Widget::on_createDirBtn_clicked()
{
    // Create a directory is it already not present
    QString dirPath = ui->lineEdit->text();
    if (dirPath.isEmpty())
        return;

    QDir dir(dirPath);
    if (!dir.exists())
    {
        if (dir.mkpath(dirPath)) {
            QMessageBox::information(this, "Message", "Directory Created");
        }
    }
    else
    {
        QMessageBox::information(this, "Message", "Directory Already Exists");
    }

}

void Widget::on_dirExistBtn_clicked()
{
    // Checking if a directory exists
    QString dirPath = ui->lineEdit->text();
    if (dirPath.isEmpty())
        return;

    QDir dir(dirPath);
    if (dir.exists()) {
        QMessageBox::information(this, "Message", "Directory Exists");
    } else {
        QMessageBox::information(this, "Message", "Directory Not Exists");
    }

}

void Widget::on_dirOrFileBtn_clicked()
{

    QFileInfo fileInfo(ui->listWidget->currentItem()->text());
    if (fileInfo.isDir()) {
        QMessageBox::information(this, "Message", "This is a directory");
    } else if (fileInfo.isFile()) {
        QMessageBox::information(this, "Message", "This is a file");
    } else {
        QMessageBox::information(this, "Message", "Something else");
    }
}

void Widget::on_folderContentsBtn_clicked()
{
    ui->listWidget->clear();
    QString dirPath = ui->lineEdit->text();
    if (dirPath.isEmpty())
        return;

    QDir dir(dirPath);

    QList<QFileInfo> fileList = dir.entryInfoList();
    for (int var = 0; var < fileList.count(); ++var) {
        QString prefix;
//        if (fileList.at(var).isFile()) {
//            prefix = "FILE :";
//        }
//        if (fileList.at(var).isDir()) {
//            prefix = "DIRECTORY :";
//        }
        ui->listWidget->addItem(prefix + fileList.at(var).absoluteFilePath());
    }
}
