#include "bookticket.h"
#include "ui_bookticket.h"
#include "database.h"
#include "bookticketsecond.h"
#include <QMessageBox>
#include <QString>
#include <QDateTime>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QIntValidator>
#include <QKeyEvent>

// Global date variable
QDate currentDate = QDate::currentDate();

/**
 * @brief BookTicket Constructor
 * Sets up the UI and configures initial widget properties
 */
bookticket::bookticket(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::bookticket)
{
    ui->setupUi(this);

    // Configure calendar to hide vertical headers for cleaner look
    ui->calendarWidget->setVerticalHeaderFormat(QCalendarWidget::NoVerticalHeader);

    // Set validators to ensure only integers can be entered for ticket count
    ui->notickets->setValidator(new QIntValidator(1, 100, ui->notickets));

    // Set window title and style
    this->setWindowTitle("Book Your Tickets");

    // Set placeholder texts for better user guidance
    ui->notickets->setPlaceholderText("Enter number of tickets");

    // Style the confirm button
    ui->pushButton->setStyleSheet(
        "QPushButton {"
        "    background-color: #4CAF50;"
        "    color: white;"
        "    border-radius: 4px;"
        "    padding: 6px 12px;"
        "    font-weight: bold;"
        "}"
        "QPushButton:hover {"
        "    background-color: #45a049;"
        "}"
        "QPushButton:pressed {"
        "    background-color: #3d8b40;"
        "}"
        );
}

/**
 * @brief Destructor - Clean up UI resources
 */
bookticket::~bookticket()
{
    delete ui;
}

/**
 * @brief Handle booking confirmation when user clicks the button
 * Validates cities, processes booking and updates database
 */
void bookticket::on_pushButton_clicked()
{
    // Validate that departure and arrival cities are different
    if(ui->comboBox->currentText() == ui->comboBox_2->currentText()) {
        QMessageBox::warning(
            this,
            "Invalid Selection",
            "Departure and arrival cities cannot be the same."
            );
        return;
    }

    // Get number of tickets requested
    int tickets = ui->notickets->text().toInt();

    // Validate ticket count
    if(tickets <= 0) {
        QMessageBox::warning(this, "Invalid Input", "Please enter a valid number of tickets.");
        return;
    }

    // Get current user data from database
    QVariantMap user = Database::getUserData();

    // Open second booking dialog to continue process
    bookticketsecond* bookingDetailsDialog = new bookticketsecond(tickets, this);

    if(bookingDetailsDialog->exec() == QDialog::Accepted) {
        // Insert booking into database
        if(Database::insertBooking(
                user["uid"].toString(),
                tickets,
                ui->comboBox->currentText(),
                ui->comboBox_2->currentText())) {

            QMessageBox::information(
                this,
                "Booking Successful",
                QString("You have successfully booked %1 ticket(s) from %2 to %3.")
                    .arg(tickets)
                    .arg(ui->comboBox->currentText())
                    .arg(ui->comboBox_2->currentText())
                );

            qDebug() << "Booking inserted successfully";

            // Close dialog after successful booking
            accept();
        } else {
            QMessageBox::critical(this, "Error", "Failed to complete booking. Please try again.");
        }
    }

    // Clean up
    delete bookingDetailsDialog;
}

/**
 * @brief Calendar date selection handler
 * Validates that selected dates are in the future
 */
void bookticket::on_calendarWidget_clicked(const QDate &date)
{
    if(date <= currentDate) {
        QMessageBox::warning(
            this,
            "Invalid Date",
            "Please select a future date for your journey."
            );
    } else {
        // Update selected date display or other UI elements
        ui->calendarWidget->setSelectedDate(date);

        // Optional: Display selected date in a label
        // ui->dateLabel->setText(date.toString("dd-MM-yyyy"));
    }
}

/**
 * @brief Override key press events to handle special cases
 * Currently prevents dialog closure when Escape is pressed
 */
void bookticket::keyPressEvent(QKeyEvent* event)
{
    if (event->key() == Qt::Key_Escape) {
        // Prevent dialog from closing on Escape key
        return;
    }

    // Pass other key events to parent implementation
    QDialog::keyPressEvent(event);
}
