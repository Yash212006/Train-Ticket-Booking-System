#ifndef VIEWBOOKINGS_H
#define VIEWBOOKINGS_H
#include <QDialog>
#include <QVariantMap>
#include <QList>
#include "database.h"
#include <QScrollArea>

namespace Ui {
class viewbookings;
}

class viewbookings : public QDialog
{
    Q_OBJECT
public:
    explicit viewbookings(QWidget *parent = nullptr, const QString& uid = "");
    ~viewbookings();

private:
    Ui::viewbookings *ui;
    Database* db;
    QString userID;
    QScrollArea *scrollArea;
};
#endif // VIEWBOOKINGS_H
