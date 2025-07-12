#ifndef BOOKTICKETSECOND_H
#define BOOKTICKETSECOND_H

#include <QObject>
#include <QDialog>
#include <QKeyEvent>

namespace Ui{
class bookticketsecond;
}

class bookticketsecond : public QDialog
{
    Q_OBJECT

public:
    explicit bookticketsecond(int tickets, QWidget *parent = nullptr);
    ~bookticketsecond();

protected:
    void keyPressEvent(QKeyEvent* event) override;

private slots:
    void onpushButtonClicked();

private:
    Ui::bookticketsecond *ui;
    int ticket;
    int counter;
    QMap<int, QString> names;
};

#endif // BOOKTICKETSECOND_H
