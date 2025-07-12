/********************************************************************************
** Form generated from reading UI file 'bookticket.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOOKTICKET_H
#define UI_BOOKTICKET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_bookticket
{
public:
    QVBoxLayout *verticalLayout_4;
    QLabel *label_4;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QComboBox *comboBox;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QComboBox *comboBox_2;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_3;
    QCalendarWidget *calendarWidget;
    QSpacerItem *horizontalSpacer_3;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_3;
    QLineEdit *notickets;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_4;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *bookticket)
    {
        if (bookticket->objectName().isEmpty())
            bookticket->setObjectName("bookticket");
        bookticket->resize(640, 480);
        bookticket->setStyleSheet(QString::fromUtf8("QDialog{\n"
"                        background-image: url(:/resources/images/back.png);\n"
"                        background-repeat: no-repeat;\n"
"                        background-position: center;\n"
"                        background-attachment: fixed;\n"
"                        };"));
        verticalLayout_4 = new QVBoxLayout(bookticket);
        verticalLayout_4->setObjectName("verticalLayout_4");
        label_4 = new QLabel(bookticket);
        label_4->setObjectName("label_4");
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        label_4->setFont(font);
        label_4->setStyleSheet(QString::fromUtf8("color:black;"));

        verticalLayout_4->addWidget(label_4);

        verticalSpacer_3 = new QSpacerItem(20, 25, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout_4->addItem(verticalSpacer_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(bookticket);
        label->setObjectName("label");
        label->setMinimumSize(QSize(0, 41));
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color:black;"));

        verticalLayout->addWidget(label);

        comboBox = new QComboBox(bookticket);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setMinimumSize(QSize(0, 41));
        QFont font1;
        font1.setPointSize(12);
        comboBox->setFont(font1);

        verticalLayout->addWidget(comboBox);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        label_2 = new QLabel(bookticket);
        label_2->setObjectName("label_2");
        label_2->setMinimumSize(QSize(0, 41));
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("color:black;"));

        verticalLayout_2->addWidget(label_2);

        comboBox_2 = new QComboBox(bookticket);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName("comboBox_2");
        comboBox_2->setMinimumSize(QSize(0, 41));
        comboBox_2->setFont(font1);

        verticalLayout_2->addWidget(comboBox_2);


        horizontalLayout->addLayout(verticalLayout_2);


        verticalLayout_4->addLayout(horizontalLayout);

        verticalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout_4->addItem(verticalSpacer_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        calendarWidget = new QCalendarWidget(bookticket);
        calendarWidget->setObjectName("calendarWidget");

        horizontalLayout_3->addWidget(calendarWidget);

        horizontalSpacer_3 = new QSpacerItem(10, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        label_3 = new QLabel(bookticket);
        label_3->setObjectName("label_3");
        label_3->setMinimumSize(QSize(0, 41));
        label_3->setFont(font);
        label_3->setStyleSheet(QString::fromUtf8("color:black;"));

        verticalLayout_3->addWidget(label_3);

        notickets = new QLineEdit(bookticket);
        notickets->setObjectName("notickets");
        notickets->setMinimumSize(QSize(0, 41));
        notickets->setFont(font1);
        notickets->setMaxLength(2);

        verticalLayout_3->addWidget(notickets);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);


        horizontalLayout_3->addLayout(verticalLayout_3);


        verticalLayout_4->addLayout(horizontalLayout_3);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_4);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        pushButton = new QPushButton(bookticket);
        pushButton->setObjectName("pushButton");
        pushButton->setMinimumSize(QSize(121, 41));
        pushButton->setFont(font1);

        horizontalLayout_2->addWidget(pushButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout_4->addLayout(horizontalLayout_2);


        retranslateUi(bookticket);

        QMetaObject::connectSlotsByName(bookticket);
    } // setupUi

    void retranslateUi(QDialog *bookticket)
    {
        bookticket->setWindowTitle(QCoreApplication::translate("bookticket", "Dialog", nullptr));
        label_4->setText(QCoreApplication::translate("bookticket", "Book Ticket", nullptr));
        label->setText(QCoreApplication::translate("bookticket", "Enter Departure City", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("bookticket", "Mumbai", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("bookticket", "Delhi", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("bookticket", "Bangalore", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("bookticket", "Hyderabad", nullptr));
        comboBox->setItemText(4, QCoreApplication::translate("bookticket", "Chennai", nullptr));
        comboBox->setItemText(5, QCoreApplication::translate("bookticket", "Kolkata", nullptr));
        comboBox->setItemText(6, QCoreApplication::translate("bookticket", "Ahemdabad", nullptr));
        comboBox->setItemText(7, QCoreApplication::translate("bookticket", "Pune", nullptr));
        comboBox->setItemText(8, QCoreApplication::translate("bookticket", "Jaipur", nullptr));
        comboBox->setItemText(9, QCoreApplication::translate("bookticket", "Lucknow", nullptr));

        label_2->setText(QCoreApplication::translate("bookticket", "Enter Arrival City", nullptr));
        comboBox_2->setItemText(0, QCoreApplication::translate("bookticket", "Mumbai", nullptr));
        comboBox_2->setItemText(1, QCoreApplication::translate("bookticket", "Delhi", nullptr));
        comboBox_2->setItemText(2, QCoreApplication::translate("bookticket", "Bangalore", nullptr));
        comboBox_2->setItemText(3, QCoreApplication::translate("bookticket", "Hyderabad", nullptr));
        comboBox_2->setItemText(4, QCoreApplication::translate("bookticket", "Chennai", nullptr));
        comboBox_2->setItemText(5, QCoreApplication::translate("bookticket", "Kolkata", nullptr));
        comboBox_2->setItemText(6, QCoreApplication::translate("bookticket", "Ahmedabad", nullptr));
        comboBox_2->setItemText(7, QCoreApplication::translate("bookticket", "Pune", nullptr));
        comboBox_2->setItemText(8, QCoreApplication::translate("bookticket", "Jaipur", nullptr));
        comboBox_2->setItemText(9, QCoreApplication::translate("bookticket", "Lucknow", nullptr));

        label_3->setText(QCoreApplication::translate("bookticket", "Enter no of Passengers", nullptr));
        pushButton->setText(QCoreApplication::translate("bookticket", "Continue", nullptr));
    } // retranslateUi

};

namespace Ui {
    class bookticket: public Ui_bookticket {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOOKTICKET_H
