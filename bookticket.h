#ifndef BOOKTICKET_H
#define BOOKTICKET_H

#include <QDialog>
#include <QKeyEvent>

namespace Ui {
class bookticket;
}

class bookticket : public QDialog
{
    Q_OBJECT

public:
    explicit bookticket(QWidget *parent = nullptr);
    ~bookticket();

private slots:
    void on_pushButton_clicked();

    void on_calendarWidget_clicked(const QDate &date);

protected:
    void keyPressEvent(QKeyEvent* event) override;

private:
    Ui::bookticket *ui;
};

#endif // BOOKTICKET_H
