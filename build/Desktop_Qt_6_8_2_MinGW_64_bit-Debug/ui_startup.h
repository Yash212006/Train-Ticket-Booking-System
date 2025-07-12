/********************************************************************************
** Form generated from reading UI file 'startup.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STARTUP_H
#define UI_STARTUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "clickablelabel.h"

QT_BEGIN_NAMESPACE

class Ui_Startup
{
public:
    QVBoxLayout *verticalLayout;
    QStackedWidget *stack;
    QWidget *page;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer;
    QLabel *label;
    QLabel *label_2;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *register_startup;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *login_startup;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer_3;
    QWidget *page_2;
    QVBoxLayout *verticalLayout_4;
    QSpacerItem *verticalSpacer_4;
    QLabel *label_3;
    QLabel *label_4;
    QSpacerItem *verticalSpacer_5;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_6;
    QVBoxLayout *verticalLayout_3;
    QLineEdit *uid_register;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *nfield_register;
    QLineEdit *pnfield_register;
    QHBoxLayout *horizontalLayout_8;
    QLineEdit *yfield_register;
    QLineEdit *bfield_register;
    QHBoxLayout *horizontalLayout_6;
    QLineEdit *pfield_register;
    QLineEdit *cpfield_register;
    QHBoxLayout *r_direct_l_layout;
    ClickableLabel *r_direct_l;
    QSpacerItem *horizontalSpacer_7;
    QLabel *error_register;
    QPushButton *register_button;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *verticalSpacer_6;
    QWidget *page_3;
    QVBoxLayout *verticalLayout_6;
    QSpacerItem *verticalSpacer_7;
    QLabel *label_7;
    QLabel *label_8;
    QSpacerItem *verticalSpacer_8;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_9;
    QVBoxLayout *verticalLayout_5;
    QLineEdit *uid_login;
    QLineEdit *pfield_login;
    QSpacerItem *verticalSpacer_9;
    QHBoxLayout *l_direct_r_layout;
    ClickableLabel *l_direct_r;
    QSpacerItem *horizontalSpacer_8;
    ClickableLabel *l_direct_f;
    QLabel *error_login;
    QSpacerItem *verticalSpacer_10;
    QPushButton *login_button;
    QSpacerItem *horizontalSpacer_10;
    QSpacerItem *verticalSpacer_11;
    QWidget *page_4;
    QVBoxLayout *verticalLayout_8;
    QSpacerItem *verticalSpacer_12;
    QLabel *label_12;
    QSpacerItem *verticalSpacer_13;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_12;
    QVBoxLayout *verticalLayout_7;
    QLineEdit *uid_reset;
    QLineEdit *pfield_reset;
    QLineEdit *cpfield_reset;
    QSpacerItem *verticalSpacer_14;
    QHBoxLayout *r_direct_reg_layout;
    ClickableLabel *r_direct_reg;
    QSpacerItem *horizontalSpacer_13;
    QLabel *error_reset;
    QSpacerItem *verticalSpacer_15;
    QPushButton *reset_button;
    QSpacerItem *horizontalSpacer_11;
    QSpacerItem *verticalSpacer_16;

    void setupUi(QDialog *Startup)
    {
        if (Startup->objectName().isEmpty())
            Startup->setObjectName("Startup");
        Startup->resize(508, 560);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Startup->sizePolicy().hasHeightForWidth());
        Startup->setSizePolicy(sizePolicy);
        Startup->setMinimumSize(QSize(508, 560));
        Startup->setMaximumSize(QSize(508, 560));
        Startup->setCursor(QCursor(Qt::CursorShape::ArrowCursor));
        verticalLayout = new QVBoxLayout(Startup);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        stack = new QStackedWidget(Startup);
        stack->setObjectName("stack");
        sizePolicy.setHeightForWidth(stack->sizePolicy().hasHeightForWidth());
        stack->setSizePolicy(sizePolicy);
        stack->setMinimumSize(QSize(490, 560));
        stack->setMaximumSize(QSize(1000, 560));
        stack->setCursor(QCursor(Qt::CursorShape::ArrowCursor));
        stack->setStyleSheet(QString::fromUtf8("b"));
        page = new QWidget();
        page->setObjectName("page");
        verticalLayout_2 = new QVBoxLayout(page);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalSpacer = new QSpacerItem(20, 90, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        label = new QLabel(page);
        label->setObjectName("label");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setMinimumSize(QSize(400, 61));
        label->setMaximumSize(QSize(16777215, 61));
        QFont font;
        font.setPointSize(36);
        label->setFont(font);
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_2->addWidget(label);

        label_2 = new QLabel(page);
        label_2->setObjectName("label_2");
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);
        label_2->setMinimumSize(QSize(400, 41));
        label_2->setMaximumSize(QSize(16777215, 41));
        QFont font1;
        font1.setPointSize(16);
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_2->addWidget(label_2);

        verticalSpacer_2 = new QSpacerItem(20, 91, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        register_startup = new QPushButton(page);
        register_startup->setObjectName("register_startup");
        sizePolicy.setHeightForWidth(register_startup->sizePolicy().hasHeightForWidth());
        register_startup->setSizePolicy(sizePolicy);
        register_startup->setMinimumSize(QSize(341, 51));
        register_startup->setMaximumSize(QSize(341, 51));
        QFont font2;
        font2.setPointSize(18);
        font2.setBold(false);
        register_startup->setFont(font2);
        register_startup->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));

        horizontalLayout->addWidget(register_startup);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        login_startup = new QPushButton(page);
        login_startup->setObjectName("login_startup");
        sizePolicy.setHeightForWidth(login_startup->sizePolicy().hasHeightForWidth());
        login_startup->setSizePolicy(sizePolicy);
        login_startup->setMinimumSize(QSize(341, 51));
        login_startup->setMaximumSize(QSize(341, 51));
        login_startup->setFont(font2);
        login_startup->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));

        horizontalLayout_2->addWidget(login_startup);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);


        verticalLayout_2->addLayout(horizontalLayout_2);

        verticalSpacer_3 = new QSpacerItem(20, 90, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);

        stack->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        verticalLayout_4 = new QVBoxLayout(page_2);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalSpacer_4 = new QSpacerItem(20, 89, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_4);

        label_3 = new QLabel(page_2);
        label_3->setObjectName("label_3");
        QFont font3;
        font3.setPointSize(28);
        label_3->setFont(font3);
        label_3->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_4->addWidget(label_3);

        label_4 = new QLabel(page_2);
        label_4->setObjectName("label_4");
        QFont font4;
        font4.setPointSize(14);
        label_4->setFont(font4);
        label_4->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_4->addWidget(label_4);

        verticalSpacer_5 = new QSpacerItem(20, 89, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_5);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        uid_register = new QLineEdit(page_2);
        uid_register->setObjectName("uid_register");
        uid_register->setMinimumSize(QSize(341, 51));

        verticalLayout_3->addWidget(uid_register);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        nfield_register = new QLineEdit(page_2);
        nfield_register->setObjectName("nfield_register");
        nfield_register->setMinimumSize(QSize(101, 51));

        horizontalLayout_4->addWidget(nfield_register);

        pnfield_register = new QLineEdit(page_2);
        pnfield_register->setObjectName("pnfield_register");
        pnfield_register->setMinimumSize(QSize(101, 51));
        pnfield_register->setMaxLength(10);

        horizontalLayout_4->addWidget(pnfield_register);


        verticalLayout_3->addLayout(horizontalLayout_4);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        yfield_register = new QLineEdit(page_2);
        yfield_register->setObjectName("yfield_register");
        yfield_register->setMinimumSize(QSize(101, 51));
        yfield_register->setMaxLength(4);

        horizontalLayout_8->addWidget(yfield_register);

        bfield_register = new QLineEdit(page_2);
        bfield_register->setObjectName("bfield_register");
        bfield_register->setMinimumSize(QSize(101, 51));

        horizontalLayout_8->addWidget(bfield_register);


        verticalLayout_3->addLayout(horizontalLayout_8);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        pfield_register = new QLineEdit(page_2);
        pfield_register->setObjectName("pfield_register");
        pfield_register->setMinimumSize(QSize(101, 51));

        horizontalLayout_6->addWidget(pfield_register);

        cpfield_register = new QLineEdit(page_2);
        cpfield_register->setObjectName("cpfield_register");
        cpfield_register->setMinimumSize(QSize(101, 51));

        horizontalLayout_6->addWidget(cpfield_register);


        verticalLayout_3->addLayout(horizontalLayout_6);

        r_direct_l_layout = new QHBoxLayout();
        r_direct_l_layout->setObjectName("r_direct_l_layout");
        r_direct_l = new ClickableLabel(page_2);
        r_direct_l->setObjectName("r_direct_l");
        r_direct_l->setFont(font4);
        r_direct_l->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));

        r_direct_l_layout->addWidget(r_direct_l);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        r_direct_l_layout->addItem(horizontalSpacer_7);


        verticalLayout_3->addLayout(r_direct_l_layout);

        error_register = new QLabel(page_2);
        error_register->setObjectName("error_register");
        error_register->setMinimumSize(QSize(0, 31));
        QFont font5;
        font5.setPointSize(12);
        error_register->setFont(font5);
        error_register->setStyleSheet(QString::fromUtf8("color:#D9534F;"));

        verticalLayout_3->addWidget(error_register);

        register_button = new QPushButton(page_2);
        register_button->setObjectName("register_button");
        register_button->setMinimumSize(QSize(341, 51));
        QFont font6;
        font6.setPointSize(18);
        register_button->setFont(font6);
        register_button->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));

        verticalLayout_3->addWidget(register_button);


        horizontalLayout_3->addLayout(verticalLayout_3);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);


        verticalLayout_4->addLayout(horizontalLayout_3);

        verticalSpacer_6 = new QSpacerItem(20, 89, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_6);

        stack->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName("page_3");
        verticalLayout_6 = new QVBoxLayout(page_3);
        verticalLayout_6->setObjectName("verticalLayout_6");
        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_6->addItem(verticalSpacer_7);

        label_7 = new QLabel(page_3);
        label_7->setObjectName("label_7");
        label_7->setFont(font3);
        label_7->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_6->addWidget(label_7);

        label_8 = new QLabel(page_3);
        label_8->setObjectName("label_8");
        label_8->setFont(font4);
        label_8->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_6->addWidget(label_8);

        verticalSpacer_8 = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_6->addItem(verticalSpacer_8);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_9);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        uid_login = new QLineEdit(page_3);
        uid_login->setObjectName("uid_login");
        uid_login->setMinimumSize(QSize(341, 51));

        verticalLayout_5->addWidget(uid_login);

        pfield_login = new QLineEdit(page_3);
        pfield_login->setObjectName("pfield_login");
        pfield_login->setMinimumSize(QSize(341, 51));

        verticalLayout_5->addWidget(pfield_login);

        verticalSpacer_9 = new QSpacerItem(20, 10, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout_5->addItem(verticalSpacer_9);

        l_direct_r_layout = new QHBoxLayout();
        l_direct_r_layout->setObjectName("l_direct_r_layout");
        l_direct_r = new ClickableLabel(page_3);
        l_direct_r->setObjectName("l_direct_r");
        l_direct_r->setFont(font4);
        l_direct_r->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));

        l_direct_r_layout->addWidget(l_direct_r);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        l_direct_r_layout->addItem(horizontalSpacer_8);

        l_direct_f = new ClickableLabel(page_3);
        l_direct_f->setObjectName("l_direct_f");
        l_direct_f->setFont(font4);
        l_direct_f->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));

        l_direct_r_layout->addWidget(l_direct_f);


        verticalLayout_5->addLayout(l_direct_r_layout);

        error_login = new QLabel(page_3);
        error_login->setObjectName("error_login");
        error_login->setMinimumSize(QSize(0, 31));
        error_login->setFont(font5);
        error_login->setStyleSheet(QString::fromUtf8("color:#D9534F;"));

        verticalLayout_5->addWidget(error_login);

        verticalSpacer_10 = new QSpacerItem(20, 10, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout_5->addItem(verticalSpacer_10);

        login_button = new QPushButton(page_3);
        login_button->setObjectName("login_button");
        login_button->setMinimumSize(QSize(341, 51));
        login_button->setFont(font6);
        login_button->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));

        verticalLayout_5->addWidget(login_button);


        horizontalLayout_5->addLayout(verticalLayout_5);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_10);


        verticalLayout_6->addLayout(horizontalLayout_5);

        verticalSpacer_11 = new QSpacerItem(20, 76, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_6->addItem(verticalSpacer_11);

        stack->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName("page_4");
        verticalLayout_8 = new QVBoxLayout(page_4);
        verticalLayout_8->setObjectName("verticalLayout_8");
        verticalSpacer_12 = new QSpacerItem(20, 75, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_8->addItem(verticalSpacer_12);

        label_12 = new QLabel(page_4);
        label_12->setObjectName("label_12");
        label_12->setFont(font3);
        label_12->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_8->addWidget(label_12);

        verticalSpacer_13 = new QSpacerItem(20, 74, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_8->addItem(verticalSpacer_13);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_12);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName("verticalLayout_7");
        uid_reset = new QLineEdit(page_4);
        uid_reset->setObjectName("uid_reset");
        uid_reset->setMinimumSize(QSize(341, 51));

        verticalLayout_7->addWidget(uid_reset);

        pfield_reset = new QLineEdit(page_4);
        pfield_reset->setObjectName("pfield_reset");
        pfield_reset->setMinimumSize(QSize(341, 51));

        verticalLayout_7->addWidget(pfield_reset);

        cpfield_reset = new QLineEdit(page_4);
        cpfield_reset->setObjectName("cpfield_reset");
        cpfield_reset->setMinimumSize(QSize(341, 51));

        verticalLayout_7->addWidget(cpfield_reset);

        verticalSpacer_14 = new QSpacerItem(20, 10, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout_7->addItem(verticalSpacer_14);

        r_direct_reg_layout = new QHBoxLayout();
        r_direct_reg_layout->setObjectName("r_direct_reg_layout");
        r_direct_reg = new ClickableLabel(page_4);
        r_direct_reg->setObjectName("r_direct_reg");
        r_direct_reg->setFont(font4);
        r_direct_reg->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));

        r_direct_reg_layout->addWidget(r_direct_reg);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        r_direct_reg_layout->addItem(horizontalSpacer_13);


        verticalLayout_7->addLayout(r_direct_reg_layout);

        error_reset = new QLabel(page_4);
        error_reset->setObjectName("error_reset");
        error_reset->setMinimumSize(QSize(0, 31));
        error_reset->setFont(font5);
        error_reset->setStyleSheet(QString::fromUtf8("color:#D9534F;"));

        verticalLayout_7->addWidget(error_reset);

        verticalSpacer_15 = new QSpacerItem(20, 10, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout_7->addItem(verticalSpacer_15);

        reset_button = new QPushButton(page_4);
        reset_button->setObjectName("reset_button");
        reset_button->setMinimumSize(QSize(341, 51));
        reset_button->setFont(font6);
        reset_button->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));

        verticalLayout_7->addWidget(reset_button);


        horizontalLayout_7->addLayout(verticalLayout_7);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_11);


        verticalLayout_8->addLayout(horizontalLayout_7);

        verticalSpacer_16 = new QSpacerItem(20, 75, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_8->addItem(verticalSpacer_16);

        stack->addWidget(page_4);

        verticalLayout->addWidget(stack);


        retranslateUi(Startup);

        stack->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(Startup);
    } // setupUi

    void retranslateUi(QDialog *Startup)
    {
        Startup->setWindowTitle(QCoreApplication::translate("Startup", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Startup", "Welcome", nullptr));
        label_2->setText(QCoreApplication::translate("Startup", "Login or register a new account", nullptr));
        register_startup->setText(QCoreApplication::translate("Startup", "Register", nullptr));
        login_startup->setText(QCoreApplication::translate("Startup", "Login", nullptr));
        label_3->setText(QCoreApplication::translate("Startup", "Register", nullptr));
        label_4->setText(QCoreApplication::translate("Startup", "Register a new account", nullptr));
        uid_register->setText(QString());
        uid_register->setPlaceholderText(QCoreApplication::translate("Startup", "Adhaar Number", nullptr));
        nfield_register->setPlaceholderText(QCoreApplication::translate("Startup", "Name", nullptr));
        pnfield_register->setPlaceholderText(QCoreApplication::translate("Startup", "Phone Number", nullptr));
        yfield_register->setPlaceholderText(QCoreApplication::translate("Startup", "Year of Birth", nullptr));
        bfield_register->setPlaceholderText(QCoreApplication::translate("Startup", "Batch", nullptr));
        pfield_register->setPlaceholderText(QCoreApplication::translate("Startup", "Password", nullptr));
        cpfield_register->setPlaceholderText(QCoreApplication::translate("Startup", "Confirm Password", nullptr));
        r_direct_l->setText(QCoreApplication::translate("Startup", "<u>Login Instead?</u>", nullptr));
        error_register->setText(QString());
        register_button->setText(QCoreApplication::translate("Startup", "Register", nullptr));
        label_7->setText(QCoreApplication::translate("Startup", "Login", nullptr));
        label_8->setText(QCoreApplication::translate("Startup", "Log in to your existing account", nullptr));
        uid_login->setPlaceholderText(QCoreApplication::translate("Startup", "Adhaar Number", nullptr));
        pfield_login->setPlaceholderText(QCoreApplication::translate("Startup", "Password", nullptr));
        l_direct_r->setText(QCoreApplication::translate("Startup", "<u>Register Instead?", nullptr));
        l_direct_f->setText(QCoreApplication::translate("Startup", "<u>Forgot Password?", nullptr));
        error_login->setText(QString());
        login_button->setText(QCoreApplication::translate("Startup", "Login", nullptr));
        label_12->setText(QCoreApplication::translate("Startup", "Reset Password", nullptr));
        uid_reset->setPlaceholderText(QCoreApplication::translate("Startup", "Enrollment Number", nullptr));
        pfield_reset->setPlaceholderText(QCoreApplication::translate("Startup", "Password", nullptr));
        cpfield_reset->setPlaceholderText(QCoreApplication::translate("Startup", "Confirm Password", nullptr));
        r_direct_reg->setText(QCoreApplication::translate("Startup", "<u>Register Instead?", nullptr));
        error_reset->setText(QString());
        reset_button->setText(QCoreApplication::translate("Startup", "Reset", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Startup: public Ui_Startup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTUP_H
