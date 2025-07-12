#ifndef MODIFYBOOKINGS_H
#define MODIFYBOOKINGS_H

#include <QDialog>
#include <QString>
#include "database.h"

namespace Ui {
class modifybookings;
}

class modifybookings : public QDialog
{
    Q_OBJECT

public:
    explicit modifybookings(QWidget *parent = nullptr, const QString& uid = QString());
    ~modifybookings();

private slots:
    void onBookingSelected(int index);
    void onDeleteClicked();
    void onSaveChangesClicked();
    void refreshBookingsList();

private:
    Ui::modifybookings *ui;
    QString userID;
    Database *db;
    QList<QVariantMap> bookingsList;
    QList<int> bookingIDs; // Store the booking IDs for reference
};

#endif // MODIFYBOOKINGS_H
