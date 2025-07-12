#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "database.h"

#include <QMessageBox>
#include <QPixmap>

QString main_button_css = R"(
QPushButton {
    background-color: #3FA7D6;  /* Primary Button Color */
    color: black;  /* Text Color */
    border: 2px solid #252525;
    border-radius: 10px;
    padding: 6px 12px;
    font-weight:bold;
}

QPushButton:hover {
    background-color: #2D89B5;  /* Slightly darker blue for hover effect */
}

QPushButton:pressed {
    background-color: #1F6E96;  /* Even darker blue for pressed state */
}

QPushButton:disabled {
    background-color: #4A4F55;  /* Disabled Button Color */
    color: #7A828A;  /* Dimmed Text Color */
    border: 2px solid #383838;
}

QPushButton[danger="true"] {
    background-color: #D9534F;  /* Danger Button Color */
    color: #FFFAF0;
}

QPushButton[danger="true"]:hover {
    background-color: #B5423C;
}

QPushButton[secondary="true"] {
    background-color: #556B8D;  /* Secondary Button */
    color: #FFFAF0;
}

QPushButton[secondary="true"]:hover {
    background-color: #485A7A;
}
)";

QString main_window_css = R"(
QWidget {
    background-image: url(:/resources/images/back.png);
    background-repeat: no-repeat;
    background-position: center;
    background-attachment: fixed;
    background-color: #121212;
    color: #E0E0E0;
    font-family: 'Segoe UI', sans-serif;
}

/* QLabel */
QLabel {
    color:black;
    background:transparent;
}

/* QLineEdit */
QLineEdit {
    background-color: rgba(30, 30, 30, 0.8);
    color: #FFFFFF;
    border: 1px solid #3A3A3A;
    border-radius: 4px;
    padding: 4px;
}

/* QPushButton */
QPushButton {
    background-color: #3FA7D6;  /* Primary Button Color */
    color: black;  /* Text Color */
    border: 2px solid #252525;
    border-radius: 10px;
    padding: 6px 12px;
    font-weight:bold;
}

QPushButton:hover {
    background-color: #2D89B5;  /* Slightly darker blue for hover effect */
}

QPushButton:pressed {
    background-color: #1F6E96;  /* Even darker blue for pressed state */
}

QPushButton:disabled {
    background-color: #4A4F55;  /* Disabled Button Color */
    color: #7A828A;  /* Dimmed Text Color */
    border: 2px solid #383838;
}

QPushButton[danger="true"] {
    background-color: #D9534F;  /* Danger Button Color */
    color: #FFFAF0;
}

QPushButton[danger="true"]:hover {
    background-color: #B5423C;
}

QPushButton[secondary="true"] {
    background-color: #556B8D;  /* Secondary Button */
    color: #FFFAF0;
}

QPushButton[secondary="true"]:hover {
    background-color: #485A7A;
}

/* QComboBox */
QComboBox {
    background-color: rgba(30, 30, 30, 0.8);
    color: #FFFFFF;
    border: 1px solid #3A3A3A;
    padding: 4px;
    border-radius: 4px;
}
QComboBox QAbstractItemView {
    background-color: rgba(42, 42, 42, 0.95);
    color: #FFFFFF;
    selection-background-color: #444444;
}

/* QCheckBox */
QCheckBox {
    color: #E0E0E0;
    background: transparent;
}
QCheckBox::indicator {
    border: 1px solid #3A3A3A;
    background: rgba(30, 30, 30, 0.8);
}
QCheckBox::indicator:checked {
    background: #2D88FF;
}

/* QRadioButton */
QRadioButton {
    color: #E0E0E0;
    background: transparent;
}
QRadioButton::indicator:checked {
    background: #2D88FF;
}

/* QScrollBar */
QScrollBar:vertical, QScrollBar:horizontal {
    background: transparent;
    border: none;
    width: 12px;
}
QScrollBar::handle {
    background: #444444;
    border-radius: 6px;
}
QScrollBar::handle:hover {
    background: #555555;
}
QScrollBar::add-line, QScrollBar::sub-line {
    background: none;
}

/* QTabWidget */
QTabWidget::pane {
    border: 1px solid #3A3A3A;
    background: transparent;
}
QTabBar::tab {
    background: rgba(42, 42, 42, 0.8);
    color: #E0E0E0;
    padding: 6px;
    border: 1px solid #3A3A3A;
}
QTabBar::tab:selected {
    background: rgba(68, 68, 68, 0.9);
}

/* QMenuBar and QMenu */
QMenuBar {
    background-color: rgba(30, 30, 30, 0.8);
    color: #E0E0E0;
}
QMenuBar::item:selected {
    background-color: rgba(45, 45, 45, 0.8);
}
QMenu {
    background-color: rgba(42, 42, 42, 0.95);
    color: #FFFFFF;
    border: 1px solid #3A3A3A;
}
QMenu::item:selected {
    background-color: rgba(60, 60, 60, 0.9);
}

/* QStatusBar */
QStatusBar {
    background-color: rgba(30, 30, 30, 0.8);
    color: #E0E0E0;
    border-top: 1px solid #3A3A3A;
}
)";


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
  //  QPixmap pix(":/resources/images/123.jpg");
   // ui->label_2->setPixmap(pix.scaled(271,271,Qt::KeepAspectRatio));
    this->setStyleSheet("QMainWindow {"
                        "background-image: url(:/resources/images/back.png);"
                        "background-repeat: no-repeat;"
                        "background-position: center;"
                        "background-attachment: fixed;"
                        "}");
    // ui->pushButton->setStyleSheet(main_button_css);
    // ui->pushButton_2->setStyleSheet(main_button_css);
    // ui->pushButton_3->setStyleSheet(main_button_css);
    // ui->logoutButton->setStyleSheet(main_button_css);

    connect(ui->logoutButton, &QPushButton::clicked, this, &MainWindow::logoutFunction);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::logoutFunction() {
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Logout", "Are you sure you want to logout?",
                                  QMessageBox::Yes | QMessageBox::No, QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        if (Database::logout()) {
            qDebug() << "Logout Done";
        } else {
            qDebug() << "No users were logged out (maybe none were logged in).";
        }
        close();
    } else {
        qDebug() << "Logout Aborted";
    }
}

void MainWindow::on_pushButton_clicked()
{
    book = new bookticket(this);
    book->show();

}


void MainWindow::on_pushButton_2_clicked()
{

    QVariantMap user = Database::getUserData();

    QString currentUserID = user["uid"].toString(); // Replace with the actual user ID
    viewbookings* bookingsDialog = new viewbookings(this, currentUserID);
    bookingsDialog->exec();
}




void MainWindow::on_pushButton_3_clicked()
{
    modify = new modifybookings(this);
    modify->show();
}

