/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *logoutButton;
    QSpacerItem *verticalSpacer;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(622, 374);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setStyleSheet(QString::fromUtf8("QLabel{\n"
"font-size:30px;\n"
"color:black;\n"
"font-weight: bold;\n"
"}"));
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_2->addWidget(label);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");

        verticalLayout_2->addWidget(label_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setMinimumSize(QSize(241, 41));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        pushButton->setFont(font);
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #3FA7D6;  /* Primary Button Color */\n"
"    color: black;  /* Text Color */\n"
"    border: 2px solid #252525;\n"
"    border-radius: 10px;\n"
"    padding: 6px 12px;\n"
"    font-weight:bold;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #2D89B5;  /* Slightly darker blue for hover effect */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #1F6E96;  /* Even darker blue for pressed state */\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"    background-color: #4A4F55;  /* Disabled Button Color */\n"
"    color: #7A828A;  /* Dimmed Text Color */\n"
"    border: 2px solid #383838;\n"
"}\n"
"\n"
"QPushButton[danger=\"true\"] {\n"
"    background-color: #D9534F;  /* Danger Button Color */\n"
"    color: #FFFAF0;\n"
"}\n"
"\n"
"QPushButton[danger=\"true\"]:hover {\n"
"    background-color: #B5423C;\n"
"}\n"
"\n"
"QPushButton[secondary=\"true\"] {\n"
"    background-color: #556B8D;  /* Secondary Button */\n"
"    color: #FFFAF0;\n"
"}\n"
"\n"
"QPushButto"
                        "n[secondary=\"true\"]:hover {\n"
"    background-color: #485A7A;\n"
"}"));

        verticalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setMinimumSize(QSize(241, 41));
        pushButton_2->setFont(font);
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #3FA7D6;  /* Primary Button Color */\n"
"    color: black;  /* Text Color */\n"
"    border: 2px solid #252525;\n"
"    border-radius: 10px;\n"
"    padding: 6px 12px;\n"
"    font-weight:bold;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #2D89B5;  /* Slightly darker blue for hover effect */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #1F6E96;  /* Even darker blue for pressed state */\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"    background-color: #4A4F55;  /* Disabled Button Color */\n"
"    color: #7A828A;  /* Dimmed Text Color */\n"
"    border: 2px solid #383838;\n"
"}\n"
"\n"
"QPushButton[danger=\"true\"] {\n"
"    background-color: #D9534F;  /* Danger Button Color */\n"
"    color: #FFFAF0;\n"
"}\n"
"\n"
"QPushButton[danger=\"true\"]:hover {\n"
"    background-color: #B5423C;\n"
"}\n"
"\n"
"QPushButton[secondary=\"true\"] {\n"
"    background-color: #556B8D;  /* Secondary Button */\n"
"    color: #FFFAF0;\n"
"}\n"
"\n"
"QPushButto"
                        "n[secondary=\"true\"]:hover {\n"
"    background-color: #485A7A;\n"
"}"));

        verticalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setMinimumSize(QSize(241, 41));
        pushButton_3->setFont(font);
        pushButton_3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #3FA7D6;  /* Primary Button Color */\n"
"    color: black;  /* Text Color */\n"
"    border: 2px solid #252525;\n"
"    border-radius: 10px;\n"
"    padding: 6px 12px;\n"
"    font-weight:bold;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #2D89B5;  /* Slightly darker blue for hover effect */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #1F6E96;  /* Even darker blue for pressed state */\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"    background-color: #4A4F55;  /* Disabled Button Color */\n"
"    color: #7A828A;  /* Dimmed Text Color */\n"
"    border: 2px solid #383838;\n"
"}\n"
"\n"
"QPushButton[danger=\"true\"] {\n"
"    background-color: #D9534F;  /* Danger Button Color */\n"
"    color: #FFFAF0;\n"
"}\n"
"\n"
"QPushButton[danger=\"true\"]:hover {\n"
"    background-color: #B5423C;\n"
"}\n"
"\n"
"QPushButton[secondary=\"true\"] {\n"
"    background-color: #556B8D;  /* Secondary Button */\n"
"    color: #FFFAF0;\n"
"}\n"
"\n"
"QPushButto"
                        "n[secondary=\"true\"]:hover {\n"
"    background-color: #485A7A;\n"
"}"));

        verticalLayout->addWidget(pushButton_3);

        logoutButton = new QPushButton(centralwidget);
        logoutButton->setObjectName("logoutButton");
        logoutButton->setMinimumSize(QSize(0, 41));
        logoutButton->setFont(font);
        logoutButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #3FA7D6;  /* Primary Button Color */\n"
"    color: black;  /* Text Color */\n"
"    border: 2px solid #252525;\n"
"    border-radius: 10px;\n"
"    padding: 6px 12px;\n"
"    font-weight:bold;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #2D89B5;  /* Slightly darker blue for hover effect */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #1F6E96;  /* Even darker blue for pressed state */\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"    background-color: #4A4F55;  /* Disabled Button Color */\n"
"    color: #7A828A;  /* Dimmed Text Color */\n"
"    border: 2px solid #383838;\n"
"}\n"
"\n"
"QPushButton[danger=\"true\"] {\n"
"    background-color: #D9534F;  /* Danger Button Color */\n"
"    color: #FFFAF0;\n"
"}\n"
"\n"
"QPushButton[danger=\"true\"]:hover {\n"
"    background-color: #B5423C;\n"
"}\n"
"\n"
"QPushButton[secondary=\"true\"] {\n"
"    background-color: #556B8D;  /* Secondary Button */\n"
"    color: #FFFAF0;\n"
"}\n"
"\n"
"QPushButto"
                        "n[secondary=\"true\"]:hover {\n"
"    background-color: #485A7A;\n"
"}"));

        verticalLayout->addWidget(logoutButton);


        horizontalLayout->addLayout(verticalLayout);


        verticalLayout_2->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 25, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout_2->addItem(verticalSpacer);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "  Welcome to Train Ticket Booking System", nullptr));
        label_2->setText(QString());
        pushButton->setText(QCoreApplication::translate("MainWindow", "Book Tickets", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "View Your Bookings", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Modify Bookings", nullptr));
        logoutButton->setText(QCoreApplication::translate("MainWindow", "Logout", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
