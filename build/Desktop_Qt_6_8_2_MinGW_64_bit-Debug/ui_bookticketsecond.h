/********************************************************************************
** Form generated from reading UI file 'bookticketsecond.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOOKTICKETSECOND_H
#define UI_BOOKTICKETSECOND_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_bookticketsecond
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;

    void setupUi(QDialog *bookticketsecond)
    {
        if (bookticketsecond->objectName().isEmpty())
            bookticketsecond->setObjectName("bookticketsecond");
        bookticketsecond->resize(400, 159);
        bookticketsecond->setMinimumSize(QSize(400, 159));
        bookticketsecond->setMaximumSize(QSize(16777215, 16777215));
        verticalLayout = new QVBoxLayout(bookticketsecond);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(bookticketsecond);
        label->setObjectName("label");
        label->setMinimumSize(QSize(51, 0));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color:black;"));
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(bookticketsecond);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setMinimumSize(QSize(0, 41));
        QFont font1;
        font1.setPointSize(12);
        lineEdit->setFont(font1);

        horizontalLayout->addWidget(lineEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        pushButton = new QPushButton(bookticketsecond);
        pushButton->setObjectName("pushButton");
        pushButton->setMinimumSize(QSize(121, 41));
        pushButton->setFont(font1);

        horizontalLayout_2->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(bookticketsecond);

        QMetaObject::connectSlotsByName(bookticketsecond);
    } // setupUi

    void retranslateUi(QDialog *bookticketsecond)
    {
        bookticketsecond->setWindowTitle(QCoreApplication::translate("bookticketsecond", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("bookticketsecond", "1", nullptr));
        lineEdit->setPlaceholderText(QCoreApplication::translate("bookticketsecond", "Enter passenger name", nullptr));
        pushButton->setText(QCoreApplication::translate("bookticketsecond", "Confirm", nullptr));
    } // retranslateUi

};

namespace Ui {
    class bookticketsecond: public Ui_bookticketsecond {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOOKTICKETSECOND_H
