#include "widget.h"
#include "ui_widget.h"

#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // First Name
    QLabel * firstNameLabel = new QLabel("First Name", this);
    firstNameLabel->setMinimumSize(70, 15);
    firstNameLabel->move(10, 10);

    QLineEdit * firstNameLineEdit = new QLineEdit(this);
    firstNameLineEdit->setMinimumSize(200, 15);
    firstNameLineEdit->move(100, 10);

    // Last Name
    QLabel * lastNameLabel = new QLabel("Last Name", this);
    lastNameLabel->setMinimumSize(70, 15);
    lastNameLabel->move(10, 70);

    QLineEdit * lastNameLineEdit = new QLineEdit(this);
    lastNameLineEdit->setMinimumSize(200, 15);
    lastNameLineEdit->move(100, 70);

    // City
    QLabel * cityLabel = new QLabel("City", this);
    cityLabel->setMinimumSize(70, 15);
    cityLabel->move(10, 140);

    QLineEdit * cityLineEdit = new QLineEdit(this);
    cityLineEdit->setMinimumSize(200, 15);
    cityLineEdit->move(100, 140);

    // Button
    QFont buttonFont("Times", 20,QFont::Bold);
    QPushButton * button = new QPushButton("Grab Data", this);
    button->setFont(buttonFont);
    button->move(80, 200);

    connect(button, &QPushButton::clicked, [=](){
        QString firstName = firstNameLineEdit->text();
        QString lastName = lastNameLineEdit->text();
        QString city = cityLineEdit->text();

        if (!firstName.isEmpty() && !lastName.isEmpty() && !city.isEmpty()) {
            // If neither field is empty we fall here
            qDebug() << "First name is: " << firstName;
            qDebug() << "Last name is: " << lastName;
            qDebug() << "City is: " << city;
        } else {
            // Even if one field is empty please notify user
            qDebug() << "Every field is required";
        }

    });

    // Response to signals from QLineEdits

    // cursorPositionChanged
    connect(firstNameLineEdit, &QLineEdit::cursorPositionChanged, [=]() {
       qDebug() << "The current cursor position is : " << firstNameLineEdit->cursorPosition();
    });

    // editingFinished
    connect(firstNameLineEdit, &QLineEdit::editingFinished, [=]() {
       qDebug() << "Editing finished";
    });

    // returnPressed
    connect(firstNameLineEdit, &QLineEdit::returnPressed, [=]() {
       qDebug() << "Returned Pressed";
    });

    // selectionChanged
    connect(firstNameLineEdit, &QLineEdit::selectionChanged, [=]() {
       qDebug() << "Selection Changed";
    });

    // textChanged
    connect(firstNameLineEdit, &QLineEdit::textChanged, [=]() {
       qDebug() << "Text Changed to : " << firstNameLineEdit->text();
    });

    // textEdited
    connect(firstNameLineEdit, &QLineEdit::textEdited, [=]() {
       qDebug() << "Text Edited to : " << firstNameLineEdit->text();
    });

    // Changed text in QLineEdit programmatically
    lastNameLineEdit->setText("I am waiting for your last name");
    cityLineEdit->setPlaceholderText("dont forget to put city here");

}

Widget::~Widget()
{
    delete ui;
}

