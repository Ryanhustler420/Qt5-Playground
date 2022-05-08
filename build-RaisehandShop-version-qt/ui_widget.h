/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QLineEdit *email_le;
    QLineEdit *password_le;
    QPushButton *login_btn;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *latest_msg_lbl;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *stocks_btn;
    QListWidget *stocks_list_list_widget;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(467, 355);
        horizontalLayout_4 = new QHBoxLayout(Widget);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox = new QGroupBox(Widget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        email_le = new QLineEdit(groupBox);
        email_le->setObjectName(QString::fromUtf8("email_le"));

        horizontalLayout->addWidget(email_le);

        password_le = new QLineEdit(groupBox);
        password_le->setObjectName(QString::fromUtf8("password_le"));
        password_le->setInputMethodHints(Qt::ImhHiddenText|Qt::ImhNoAutoUppercase|Qt::ImhNoPredictiveText|Qt::ImhSensitiveData);
        password_le->setEchoMode(QLineEdit::Password);

        horizontalLayout->addWidget(password_le);

        login_btn = new QPushButton(groupBox);
        login_btn->setObjectName(QString::fromUtf8("login_btn"));

        horizontalLayout->addWidget(login_btn);


        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(Widget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        horizontalLayout_3 = new QHBoxLayout(groupBox_2);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        latest_msg_lbl = new QLabel(groupBox_2);
        latest_msg_lbl->setObjectName(QString::fromUtf8("latest_msg_lbl"));
        latest_msg_lbl->setWordWrap(true);

        horizontalLayout_3->addWidget(latest_msg_lbl);


        verticalLayout->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(Widget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        verticalLayout_2 = new QVBoxLayout(groupBox_3);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(288, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        stocks_btn = new QPushButton(groupBox_3);
        stocks_btn->setObjectName(QString::fromUtf8("stocks_btn"));

        horizontalLayout_2->addWidget(stocks_btn);


        verticalLayout_2->addLayout(horizontalLayout_2);

        stocks_list_list_widget = new QListWidget(groupBox_3);
        stocks_list_list_widget->setObjectName(QString::fromUtf8("stocks_list_list_widget"));

        verticalLayout_2->addWidget(stocks_list_list_widget);


        verticalLayout->addWidget(groupBox_3);


        horizontalLayout_4->addLayout(verticalLayout);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", nullptr));
        groupBox->setTitle(QApplication::translate("Widget", "Login Area", nullptr));
        email_le->setPlaceholderText(QApplication::translate("Widget", "Email", nullptr));
        password_le->setText(QString());
        password_le->setPlaceholderText(QApplication::translate("Widget", "Password", nullptr));
        login_btn->setText(QApplication::translate("Widget", "Login", nullptr));
        groupBox_2->setTitle(QApplication::translate("Widget", "Message", nullptr));
        latest_msg_lbl->setText(QApplication::translate("Widget", "You are not logged in...\342\230\272", nullptr));
        groupBox_3->setTitle(QApplication::translate("Widget", "My Stocks", nullptr));
        stocks_btn->setText(QApplication::translate("Widget", "Get Stocks", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
