#include "database.h"

bool Database::setupDatabase()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("train.db");

    if (!db.open()) {
        qDebug() << "Error opening database:" << db.lastError().text();
        return false;
    }

    QSqlQuery query;

    if (!query.exec("PRAGMA foreign_keys = ON")) {
        qDebug() << "Failed to enable foreign keys:" << query.lastError().text();
        return false;
    }

    // Create tables if it doesn't exist
    if (!query.exec("CREATE TABLE IF NOT EXISTS users ("
                    "uid TEXT PRIMARY KEY NOT NULL UNIQUE,"
                    "name TEXT NOT NULL,"
                    "phone TEXT NOT NULL UNIQUE,"
                    "year TEXT,"
                    "batch TEXT,"
                    "password TEXT NOT NULL,"
                    "logged_in INTEGER DEFAULT 0 CHECK (logged_in IN (0, 1)));")) {
        qDebug() << "Error creating users table:" << query.lastError().text();
        return false;
    }
    //query.exec("DROP TABLE bookings;");
    if (!query.exec(R"(CREATE TABLE IF NOT EXISTS bookings (
                        id INTEGER PRIMARY KEY AUTOINCREMENT,
                        uid TEXT NOT NULL,
                        num INTEGER NOT NULL,
                        departure TEXT,
                        arrival TEXT,
                        FOREIGN KEY (uid) REFERENCES users(uid) ON DELETE CASCADE
                    );)")) {
        qDebug() << "Error creating bookings table:" << query.lastError().text();
        return false;
    }

    qDebug() << "Database setup completed successfully.";
    return true;
}

bool Database::insertUser(const QString& uid, const QString& name, const QString& phone,
                          const QString& year, const QString& batch, const QString& password){
    // Only Calls when user registers
    QSqlQuery query;

    query.prepare("INSERT INTO users (uid, name, phone, year, batch, password, logged_in) "
                  "VALUES (:uid, :name, :phone, :year, :batch, :password, 1)");
    query.bindValue(":uid", uid);
    query.bindValue(":name", name);
    query.bindValue(":phone", phone);
    query.bindValue(":year", year);
    query.bindValue(":batch", batch);
    query.bindValue(":password", password);

    if (!query.exec()) {
        qDebug() << "Insert error:" << query.lastError().text();
        return false;
    }
    return true;
}

void Database::readData(){
    QSqlQuery query("SELECT * FROM users");

    while (query.next()) {
        std::string uid = query.value("uid").toString().toStdString();
        std::string name = query.value("name").toString().toStdString();
        std::string phone = query.value("phone").toString().toStdString();
        std::string year = query.value("year").toString().toStdString();
        std::string batch = query.value("batch").toString().toStdString();

        qDebug() << "uid:" << uid << "| Name:" << name << "| Phone:" << phone << "| Year:" << year << "| Batch:" << batch;
    }
}

QVariantMap Database::getUserData(const QString& uid, const QString& password) {
    QSqlQuery query;
    query.prepare("SELECT uid, password, email, logged_in FROM users WHERE uid = :uid AND password = :password");
    query.bindValue(":uid", uid);
    query.bindValue(":password", password);

    QVariantMap userData;

    if (query.exec()) {
        if (query.next()) {
            userData["uid"] = query.value("uid").toString();
            userData["password"] = query.value("password").toString();
            userData["email"] = query.value("email").toString();
            userData["logged_in"] = query.value("logged_in").toInt();
        } else {
            qDebug() << "No user found with uid: " << uid;
        }
    } else {
        qDebug() << "Query execution failed: " << query.lastError().text();
    }

    return userData;
}

QVariantMap Database::getUserData(){
    QSqlQuery query;
    query.prepare("SELECT uid, name, phone, year, batch, logged_in FROM users WHERE logged_in=1");

    QVariantMap userData;

    if (query.exec()) {
        if (query.next()) {
            userData["uid"] = query.value("uid").toString();
            userData["name"] = query.value("name").toString();
            userData["phone"] = query.value("phone").toString();
            userData["year"] = query.value("year").toString();
            userData["batch"] = query.value("batch").toString();
            userData["logged_in"] = query.value("logged_in").toInt();
        } else {
            qDebug() << "No user logged in";
        }
    } else {
        qDebug() << "Query execution failed: " << query.lastError().text();
    }

    return userData;
}

QVariantMap Database::getUserData(const QString& uid) {
    QSqlQuery query;
    query.prepare("SELECT uid, name, phone, year, batch, logged_in FROM users WHERE uid = :uid");
    query.bindValue(":uid", uid);

    QVariantMap userData;

    if (query.exec()) {
        if (query.next()) {
            userData["uid"] = query.value("uid").toString();
            userData["name"] = query.value("name").toString();
            userData["phone"] = query.value("phone").toString();
            userData["year"] = query.value("year").toString();
            userData["batch"] = query.value("batch").toString();
            userData["logged_in"] = query.value("logged_in").toInt();
        } else {
            qDebug() << "No user found with uid: " << uid;
        }
    } else {
        qDebug() << "Query execution failed: " << query.lastError().text();
    }

    return userData;
}

bool Database::uidValid(const QString& uid){
    QSqlQuery query;
    query.prepare("SELECT 1 FROM users WHERE uid = :uid LIMIT 1");
    query.bindValue(":uid", uid);

    if (!query.exec() || !query.next()) {
        return false;  // User does not exist
    }
    return true;
}

bool Database::uidValid(const QString& uid, const QString& password) {
    QSqlQuery query;

    query.prepare("SELECT 1 FROM users WHERE uid = :uid AND password = :password LIMIT 1");
    query.bindValue(":uid", uid);
    query.bindValue(":password", password);

    return query.exec() && query.next();
}

bool Database::changePassword(const QString& uid, const QString& password){
    QSqlQuery query;

    // Check if the user exists before updating the password
    query.prepare("SELECT 1 FROM users WHERE uid = :uid LIMIT 1");
    query.bindValue(":uid", uid);

    if (!query.exec() || !query.next()) {
        qDebug() << "User does not exist or query failed:" << query.lastError().text();
        return false;
    }

    // Update password for the user
    query.prepare("UPDATE users SET password = :newPassword WHERE uid = :uid");
    query.bindValue(":newPassword", password);  // Consider hashing before storing
    query.bindValue(":uid", uid);

    if (!query.exec()) {
        qDebug() << "Failed to update password:" << query.lastError().text();
        return false;
    }

    return query.numRowsAffected() > 0;  // True if the password was updated
}

bool Database::logout(){
    QSqlQuery query;

    // Update all users to logged_out (logged_in = 0)
    if (!query.exec("UPDATE users SET logged_in = 0")) {
        qDebug() << "Failed to log out users:" << query.lastError().text();
        return false;
    }

    return query.numRowsAffected() > 0;
}

void Database::setUserLoggedIn(const QString& uid) {
    QSqlQuery query;

    if (!query.exec("UPDATE users SET logged_in = 0")) { // Safeguard condition
        qDebug() << "Failed to reset logged_in status for all users:" << query.lastError().text();
        return;
    }

    // Step 2: Set logged_in = 1 for the specific user
    query.prepare("UPDATE users SET logged_in = 1 WHERE uid = :uid");
    query.bindValue(":uid", uid);

    if (query.exec()) {
        qDebug() << "Set the current user to logged_in=1";
        return;
    }
    else {
        qDebug() << "Failed to update logged_in status for user:" << uid << "Error:" << query.lastError().text();
        return;
    }
}

bool Database::checkLogged(){
    QSqlQuery query("SELECT * FROM users WHERE logged_in = 1");

    if (query.exec()) {
        if (query.next()) {
            return true;
        }
    } else {
        qDebug() << "Query execution failed:" << query.lastError().text();
    }

    return false;
}

bool Database::insertBooking(const QString& uid, int num, const QString& departure, const QString& arrival) {
    QSqlQuery query;
    query.prepare("INSERT INTO bookings (uid, num, departure, arrival) "
                  "VALUES (:uid, :num, :departure, :arrival)");
    query.bindValue(":uid", uid);
    query.bindValue(":num", num);
    query.bindValue(":departure", departure);
    query.bindValue(":arrival", arrival);

    if (!query.exec()) {
        qDebug() << "Booking Insert error:" << query.lastError().text();
        return false;
    }
    return true;
}

QList<QVariantMap> Database::viewBookings(const QString& uid) {
    QSqlQuery query;
    query.prepare("SELECT id, uid, num, departure, arrival FROM bookings WHERE uid = :uid");
    query.bindValue(":uid", uid);
    QList<QVariantMap> bookingsList;

    if (query.exec()) {
        int count = 0;
        while (query.next()) {
            count++;
            QVariantMap bookingData;
            bookingData["id"] = query.value("id").toInt();
            bookingData["uid"] = query.value("uid").toString();
            bookingData["num"] = query.value("num").toString();
            bookingData["departure"] = query.value("departure").toString();
            bookingData["arrival"] = query.value("arrival").toString();
            bookingsList.append(bookingData);
            qDebug() << "Retrieved booking" << count << "with ID:" << bookingData["id"].toInt();
        }
        qDebug() << "Total bookings found for user" << uid << ":" << count;
    } else {
        qDebug() << "Query execution failed: " << query.lastError().text();
    }

    return bookingsList;
}
bool Database::fixBookingsTable() {
    QSqlQuery query;

    // Create a temporary table with the correct structure
    if (!query.exec("CREATE TABLE temp_bookings ("
                    "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                    "uid TEXT, "
                    "num TEXT, "
                    "departure TEXT, "
                    "arrival TEXT)")) {
        qDebug() << "Failed to create temporary table:" << query.lastError().text();
        return false;
    }

    // Copy existing data to the temporary table
    if (!query.exec("INSERT INTO temp_bookings (uid, num, departure, arrival) "
                    "SELECT uid, num, departure, arrival FROM bookings")) {
        qDebug() << "Failed to copy data:" << query.lastError().text();
        return false;
    }

    // Drop the old table
    if (!query.exec("DROP TABLE bookings")) {
        qDebug() << "Failed to drop old table:" << query.lastError().text();
        return false;
    }

    // Rename the temporary table to the original name
    if (!query.exec("ALTER TABLE temp_bookings RENAME TO bookings")) {
        qDebug() << "Failed to rename table:" << query.lastError().text();
        return false;
    }

    qDebug() << "Bookings table structure fixed successfully";
    return true;
}
bool Database::deleteBooking(int bookingId) {
    QSqlQuery query;
    query.prepare("DELETE FROM bookings WHERE id = :id");
    query.bindValue(":id", bookingId);

    if (!query.exec()) {
        qDebug() << "Error deleting booking:" << query.lastError().text();
        return false;
    }
    return query.numRowsAffected() > 0;
}

bool Database::updateBooking(int bookingId, int num, const QString& departure, const QString& arrival) {
    QSqlQuery query;
    query.prepare("UPDATE bookings SET num = :num, departure = :departure, arrival = :arrival WHERE id = :id");
    query.bindValue(":num", num);
    query.bindValue(":departure", departure);
    query.bindValue(":arrival", arrival);
    query.bindValue(":id", bookingId);

    if (!query.exec()) {
        qDebug() << "Error updating booking:" << query.lastError().text();
        return false;
    }
    return query.numRowsAffected() > 0;
}


void Database::checkDrivers() {
    qDebug() << "Available drivers:" << QSqlDatabase::drivers();
}
