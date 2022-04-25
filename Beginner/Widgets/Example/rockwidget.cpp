#include "rockwidget.h"
#include <QLabel>
#include <QPushButton>
#include <QMessageBox>

RockWidget::RockWidget(QWidget *parent) : QWidget(parent)
{

    setWindowTitle("Raisehand Software :: Retailer");


    // Add a label to widget
    QFont email_font("Times", 10, QFont::Bold);
    QLabel *email_label = new QLabel("Email", this);
    email_label->setFont(email_font);

    // Add a style widget and move it around
    QFont password_font("Helvetica [Cronyx]", 12);
    QPalette password_palette;
    password_palette.setColor(QPalette::Window, Qt::yellow);
    password_palette.setColor(QPalette::WindowText, Qt::blue);

    QLabel *password_label = new QLabel(this);
    password_label->setAutoFillBackground(true);
    password_label->setText("Password");
    password_label->move(50, 50);
    password_label->setFont(password_font);
    password_label->setPalette(password_palette);

    // Add a button and connect to a slot
    QPushButton * button = new QPushButton(this);
    button->setText("Click Me");
    button->move(50, 80);

    connect(button, SIGNAL(clicked()), this, SLOT(buttonClicked()));

}

void RockWidget::buttonClicked()
{
    QMessageBox::information(this, "Message", "You clicked on login button");
}

QSize RockWidget::sizeHint() const
{
    return QSize(500, 500);
}
