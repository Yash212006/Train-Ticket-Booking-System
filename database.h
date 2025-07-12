#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QString>
#include <QVariantMap>
#include <QString>
#include <QComboBox>
#include <QDate>

class Database {
public:
    static bool setupDatabase();
    static void checkDrivers();
    static void readData();

    static bool insertUser(const QString& uid, const QString& name, const QString& phone,
                           const QString& year, const QString& batch, const QString& password);

    static QVariantMap getUserData(const QString& uid, const QString& password); // Obsolete (won't be used for security reasons)
    static QVariantMap getUserData(const QString& uid); // Get data with just username given
    static QVariantMap getUserData(); // Get data of user having logged_in=1

    static bool uidValid(const QString& uid, const QString& password); // Login page User Validation
    static bool uidValid(const QString& uid);

    static bool changePassword(const QString& uid, const QString& newPassword);

    static bool logout();

    static void setUserLoggedIn(const QString& uid);
    static bool checkLogged();

    static bool insertBooking(const QString& uid, int num, const QString& departure, const QString& arrival);
    static QList<QVariantMap> viewBookings(const QString& uid);
    static bool fixBookingsTable();
    static bool deleteBooking(int bookingId);
    static bool updateBooking(int bookingId, int num, const QString& departure, const QString& arrival);
};

#endif // DATABASE_H
