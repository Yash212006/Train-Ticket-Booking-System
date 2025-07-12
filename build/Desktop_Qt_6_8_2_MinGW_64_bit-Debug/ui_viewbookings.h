/********************************************************************************
** Form generated from reading UI file 'viewbookings.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEWBOOKINGS_H
#define UI_VIEWBOOKINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_viewbookings
{
public:

    void setupUi(QDialog *viewbookings)
    {
        if (viewbookings->objectName().isEmpty())
            viewbookings->setObjectName("viewbookings");
        viewbookings->resize(640, 480);

        retranslateUi(viewbookings);

        QMetaObject::connectSlotsByName(viewbookings);
    } // setupUi

    void retranslateUi(QDialog *viewbookings)
    {
        viewbookings->setWindowTitle(QCoreApplication::translate("viewbookings", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class viewbookings: public Ui_viewbookings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEWBOOKINGS_H
