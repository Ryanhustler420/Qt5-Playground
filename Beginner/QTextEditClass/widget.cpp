#include "widget.h"
#include "ui_widget.h"
#include <QTextEdit>
#include <QPushButton>
#include <QLabel>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setupUI();
    setFixedSize(400, 400);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::setupUI()
{
    QFont labelFont("Times", 10, QFont::Bold);
    QLabel * mLabel = new QLabel("This is my text", this);
    mLabel->setFont(labelFont);
    mLabel->move(100, 25);

    QTextEdit * textEdit = new QTextEdit(this);
    textEdit->move(70, 55);


    // TextChange
    connect(textEdit, &QTextEdit::textChanged, [=]() {
       qDebug() << "Text Changed";
    });

    // Copy, Cut, Paste
    QPushButton * copyBtn = new QPushButton("Copy", this);
    copyBtn->setMinimumSize(50, 25);
    copyBtn->move(10, 250);
    connect(copyBtn, &QPushButton::clicked, [=](){
       textEdit->copy();
    });

    QPushButton * cutBtn = new QPushButton("Cut", this);
    cutBtn->setMinimumSize(50, 25);
    cutBtn->move(110, 250);
    connect(cutBtn, &QPushButton::clicked, [=](){
       textEdit->cut();
    });

    QPushButton * pasteBtn = new QPushButton("Paste", this);
    pasteBtn->setMinimumSize(50, 25);
    pasteBtn->move(210, 250);
    connect(pasteBtn, &QPushButton::clicked, [=](){
       textEdit->paste();
    });

    // Undo Redo
    QPushButton * undoBtn = new QPushButton("Undo", this);
    undoBtn->setMinimumSize(50, 25);
    undoBtn->move(10, 280);
    connect(undoBtn, &QPushButton::clicked, [=](){
       textEdit->undo();
    });

    // Redo Redo
    QPushButton * redoBtn = new QPushButton("Redo", this);
    redoBtn->setMinimumSize(50, 25);
    redoBtn->move(110, 280);
    connect(redoBtn, &QPushButton::clicked, [=](){
       textEdit->redo();
    });

    // set text and html to the text edit
    QPushButton * plainTextBtn = new QPushButton("Plain Text", this);
    plainTextBtn->setMinimumSize(100, 25);
    plainTextBtn->move(10, 310);
    connect(plainTextBtn, &QPushButton::clicked, [=](){
       textEdit->setPlainText("dslkfhjkahdsfjhsdlkjhfalkjsdhflajkshdflahjksdfjklahsdlfhjasldkjhfaljkshdflajkhsdfklahjsdjkfhajklsdhfklajshdfklajhsdfjkhasljkdhfakljshdf");
    });


    QPushButton * htmlBtn = new QPushButton("Html", this);
    htmlBtn->setMinimumSize(100, 25);
    htmlBtn->move(120, 310);
    connect(htmlBtn, &QPushButton::clicked, [=](){
       textEdit->setHtml("<h1>This is simple <mark>marked</mark> text</h1>");
    });

    // Grab text and html
    QPushButton * grabTextBtn = new QPushButton("Grab Text", this);
    grabTextBtn->setMinimumSize(100, 25);
    grabTextBtn->move(10, 340);
    connect(grabTextBtn, &QPushButton::clicked, [=](){
       qDebug() << "This plain text inside the text edit is: " << textEdit->toPlainText();
    });

    QPushButton * grabHtmlBtn = new QPushButton("Grab Html", this);
    grabHtmlBtn->setMinimumSize(100, 25);
    grabHtmlBtn->move(120, 340);
    connect(grabHtmlBtn, &QPushButton::clicked, [=](){
       qDebug() << "This html inside the text edit is: " << textEdit->toHtml();
    });
}

