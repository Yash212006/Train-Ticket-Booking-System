#include "startup.h"
#include "database.h"
#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Database::setupDatabase();

    if (Database::checkLogged()){
        QVariantMap user = Database::getUserData();
        qDebug() << user["uid"] << " " << user["name"] << " " << user["phone"] << user["year"] << user["batch"] << user["logged_in"];

        MainWindow mainWindow;
        mainWindow.show();
        return app.exec();
    }
    else {
        Startup startupDialog;

        int startupResult = startupDialog.exec();
        if (startupResult == 1) { // User Registered or Logged In
            MainWindow mainWindow;
            mainWindow.show();
            return app.exec();
        } else {
            return 0;
        }
    }
}
