#include "bookticketsecond.h"
#include "ui_bookticketsecond.h"
#include <QMessageBox>

bookticketsecond::bookticketsecond(int ticket, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::bookticketsecond)
{
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &bookticketsecond::onpushButtonClicked);
    this->ticket=ticket;
    counter=1;
}

bookticketsecond::~bookticketsecond() {
    delete ui;
}

void bookticketsecond::onpushButtonClicked() {
    QString name = ui->lineEdit->text();
    int id = ui->label->text().toInt();

    names[id] = name;
    ++counter;
    if (counter==this->ticket+1) {
        QMessageBox::information(this, "Info", "Passenger names got");
        for(auto i: names) {
            qDebug() << i;
        }
        this->accept();
    }
    ui->label->setText(QString::number(counter));
    ui->lineEdit->clear();
}

void bookticketsecond::keyPressEvent(QKeyEvent* event) {
    {
        if (event->key() == Qt::Key_Escape) {
            return;
        }
        QDialog::keyPressEvent(event);
    }
}
