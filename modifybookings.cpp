#include "modifybookings.h"
#include "ui_modifybookings.h"
#include <QMessageBox>
#include <QDebug>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QComboBox>
#include <QPushButton>
#include <QLineEdit>
#include <QFormLayout>
#include <QGroupBox>
#include <QPainter>
#include <QGraphicsDropShadowEffect>
#include <QFrame>
#include <QFont>

// List of cities to populate combo boxes
const QStringList cities = {
    "Mumbai", "Delhi", "Bangalore", "Hyderabad",
    "Chennai", "Kolkata", "Ahmedabad", "Pune",
    "Jaipur", "Lucknow"
};

// Custom widget to create a beautiful gradient background
class GradientBackground : public QWidget {
public:
    explicit GradientBackground(QWidget *parent = nullptr) : QWidget(parent) {}

protected:
    void paintEvent(QPaintEvent *event) override {
        Q_UNUSED(event);
        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing);

        // Create a subtle gradient background
        QLinearGradient gradient(0, 0, 0, height());
        gradient.setColorAt(0, QColor(235, 245, 251));
        gradient.setColorAt(1, QColor(240, 240, 245));

        painter.fillRect(rect(), gradient);

        // Add a subtle pattern or texture
        painter.setPen(QPen(QColor(200, 210, 230, 20), 1));
        for (int i = 0; i < height(); i += 20) {
            painter.drawLine(0, i, width(), i);
        }
    }
};

modifybookings::modifybookings(QWidget *parent, const QString& uid)
    : QDialog(parent)
    , ui(new Ui::modifybookings)
    , userID(uid)
{
    ui->setupUi(this);

    // If no user ID was provided, get the currently logged-in user
    if (userID.isEmpty()) {
        QVariantMap user = Database::getUserData();
        userID = user["uid"].toString();
    }

    // Debug information
    qDebug() << "Opening modifybookings with userID:" << userID;

    // Create database instance
    db = new Database();

    // Remove default window frame and set frameless attribute
    setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);

    // Create main layout for the dialog
    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(0);

    // Create a custom widget to serve as the background
    GradientBackground* background = new GradientBackground(this);
    QVBoxLayout* backgroundLayout = new QVBoxLayout(background);
    backgroundLayout->setContentsMargins(20, 20, 20, 20);
    backgroundLayout->setSpacing(15);

    // Add a drop shadow effect to the entire dialog
    QGraphicsDropShadowEffect* dialogShadow = new QGraphicsDropShadowEffect;
    dialogShadow->setBlurRadius(15);
    dialogShadow->setColor(QColor(0, 0, 0, 80));
    dialogShadow->setOffset(0, 0);
    background->setGraphicsEffect(dialogShadow);

    // Create a header container with a different styling
    QWidget* headerContainer = new QWidget(background);
    headerContainer->setObjectName("headerContainer");
    headerContainer->setStyleSheet(
        "QWidget#headerContainer {"
        "  background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, "
        "  stop:0 #27ae60, stop:1 #2ecc71);"
        "  border-radius: 8px 8px 0px 0px;"
        "  color: white;"
        "  padding: 10px;"
        "}"
        );

    QVBoxLayout* headerLayout = new QVBoxLayout(headerContainer);

    // Add a title label with enhanced styling
    QLabel* titleLabel = new QLabel("Modify Your Bookings", headerContainer);
    QFont titleFont("Arial", 16, QFont::Bold);
    titleLabel->setFont(titleFont);
    titleLabel->setAlignment(Qt::AlignCenter);
    titleLabel->setStyleSheet("color: white; margin-bottom: 5px;");

    // User ID label with enhanced styling
    QLabel* useridLabel = new QLabel("Bookings for user ID: " + userID, headerContainer);
    QFont userIdFont("Arial", 11);
    useridLabel->setFont(userIdFont);
    useridLabel->setAlignment(Qt::AlignCenter);
    useridLabel->setStyleSheet("color: rgba(255, 255, 255, 0.9);");

    // Add title and user ID to the header layout
    headerLayout->addWidget(titleLabel);
    headerLayout->addWidget(useridLabel);

    // Create content container
    QWidget* contentContainer = new QWidget(background);
    contentContainer->setObjectName("contentContainer");
    contentContainer->setStyleSheet(
        "QWidget#contentContainer {"
        "  background-color: white;"
        "  border-radius: 0px 0px 8px 8px;"
        "  padding: 15px;"
        "}"
        );

    QVBoxLayout* contentLayout = new QVBoxLayout(contentContainer);
    contentLayout->setContentsMargins(20, 20, 20, 20);
    contentLayout->setSpacing(15);

    // Create a styled label for booking selection
    QLabel* selectLabel = new QLabel("Select booking to modify:", contentContainer);
    selectLabel->setStyleSheet("font-weight: bold; color: #2c3e50; font-size: 13px;");

    // Create a styled combo box for selecting bookings
    QComboBox* bookingsComboBox = new QComboBox(contentContainer);
    bookingsComboBox->setObjectName("bookingsComboBox");
    bookingsComboBox->setStyleSheet(
        "QComboBox {"
        "   background-color: #f8f9fa;"
        "   border: 1px solid #dfe4ea;"
        "   border-radius: 4px;"
        "   padding: 6px 12px;"
        "   min-height: 25px;"
        "   color: #2c3e50;"
        "}"
        "QComboBox:hover {"
        "   border: 1px solid #bdc3c7;"
        "}"
        "QComboBox:focus {"
        "   border: 1px solid #3498db;"
        "}"
        "QComboBox::drop-down {"
        "   subcontrol-origin: padding;"
        "   subcontrol-position: top right;"
        "   width: 20px;"
        "   border-left: 1px solid #dfe4ea;"
        "   border-top-right-radius: 3px;"
        "   border-bottom-right-radius: 3px;"
        "}"
        "QComboBox::down-arrow {"
        "   image: url(:/icons/dropdown.png);"
        "   width: 12px;"
        "   height: 12px;"
        "}"
        );

    contentLayout->addWidget(selectLabel);
    contentLayout->addWidget(bookingsComboBox);
    contentLayout->addSpacing(10);

    // Create a group box for booking details
    QGroupBox* detailsGroupBox = new QGroupBox("Booking Details", contentContainer);
    detailsGroupBox->setStyleSheet(
        "QGroupBox {"
        "   background-color: #f8f9fa;"
        "   border: 1px solid #e9ecef;"
        "   border-radius: 6px;"
        "   margin-top: 12px;"
        "   font-weight: bold;"
        "   color: #2c3e50;"
        "}"
        "QGroupBox::title {"
        "   subcontrol-origin: margin;"
        "   subcontrol-position: top left;"
        "   left: 10px;"
        "   padding: 0 5px 0 5px;"
        "}"
        );

    QVBoxLayout* groupBoxLayout = new QVBoxLayout(detailsGroupBox);
    groupBoxLayout->setContentsMargins(15, 20, 15, 15);
    groupBoxLayout->setSpacing(10);

    // Create a form layout for details inside the group box
    QFormLayout* detailsLayout = new QFormLayout();
    detailsLayout->setLabelAlignment(Qt::AlignRight | Qt::AlignVCenter);
    detailsLayout->setFormAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    detailsLayout->setSpacing(12);

    // Style for form labels
    QString labelStyle = "font-weight: bold; color: #34495e;";

    // Create styled form fields for editing
    QComboBox* departureComboBox = new QComboBox(detailsGroupBox);
    departureComboBox->setObjectName("departureComboBox");
    departureComboBox->addItems(cities);
    departureComboBox->setEditable(false);
    departureComboBox->setStyleSheet(bookingsComboBox->styleSheet());

    QComboBox* arrivalComboBox = new QComboBox(detailsGroupBox);
    arrivalComboBox->setObjectName("arrivalComboBox");
    arrivalComboBox->addItems(cities);
    arrivalComboBox->setEditable(false);
    arrivalComboBox->setStyleSheet(bookingsComboBox->styleSheet());

    QLineEdit* numTicketsEdit = new QLineEdit(detailsGroupBox);
    numTicketsEdit->setObjectName("numTicketsEdit");
    numTicketsEdit->setValidator(new QIntValidator(1, 999, this)); // Only allow numbers
    numTicketsEdit->setStyleSheet(
        "QLineEdit {"
        "   background-color: #f8f9fa;"
        "   border: 1px solid #dfe4ea;"
        "   border-radius: 4px;"
        "   padding: 6px 12px;"
        "   color: #2c3e50;"
        "}"
        "QLineEdit:hover {"
        "   border: 1px solid #bdc3c7;"
        "}"
        "QLineEdit:focus {"
        "   border: 1px solid #3498db;"
        "}"
        );

    // Add labels with styling
    QLabel* departureLabel = new QLabel("Departure:", detailsGroupBox);
    departureLabel->setStyleSheet(labelStyle);
    QLabel* arrivalLabel = new QLabel("Arrival:", detailsGroupBox);
    arrivalLabel->setStyleSheet(labelStyle);
    QLabel* numTicketsLabel = new QLabel("Number of Tickets:", detailsGroupBox);
    numTicketsLabel->setStyleSheet(labelStyle);

    // Add rows to the form layout
    detailsLayout->addRow(departureLabel, departureComboBox);
    detailsLayout->addRow(arrivalLabel, arrivalComboBox);
    detailsLayout->addRow(numTicketsLabel, numTicketsEdit);

    // Add the form layout to the group box
    groupBoxLayout->addLayout(detailsLayout);

    // Add group box to the content layout
    contentLayout->addWidget(detailsGroupBox);

    // Create a container for buttons
    QWidget* buttonContainer = new QWidget(contentContainer);
    QHBoxLayout* buttonsLayout = new QHBoxLayout(buttonContainer);
    buttonsLayout->setContentsMargins(0, 10, 0, 0);
    buttonsLayout->setSpacing(15);

    // Create styled buttons
    QPushButton* deleteButton = new QPushButton("Delete Booking", buttonContainer);
    deleteButton->setObjectName("deleteButton");
    deleteButton->setCursor(Qt::PointingHandCursor);
    deleteButton->setStyleSheet(
        "QPushButton {"
        "   background-color: #e74c3c;"
        "   color: white;"
        "   border: none;"
        "   padding: 8px 16px;"
        "   font-size: 13px;"
        "   font-weight: bold;"
        "   border-radius: 4px;"
        "}"
        "QPushButton:hover {"
        "   background-color: #c0392b;"
        "}"
        "QPushButton:pressed {"
        "   background-color: #a93226;"
        "}"
        "QPushButton:disabled {"
        "   background-color: #d1d8e0;"
        "   color: #7f8c8d;"
        "}"
        );

    QPushButton* saveButton = new QPushButton("Save Changes", buttonContainer);
    saveButton->setObjectName("saveButton");
    saveButton->setCursor(Qt::PointingHandCursor);
    saveButton->setStyleSheet(
        "QPushButton {"
        "   background-color: #27ae60;"
        "   color: white;"
        "   border: none;"
        "   padding: 8px 16px;"
        "   font-size: 13px;"
        "   font-weight: bold;"
        "   border-radius: 4px;"
        "}"
        "QPushButton:hover {"
        "   background-color: #219653;"
        "}"
        "QPushButton:pressed {"
        "   background-color: #1e8449;"
        "}"
        "QPushButton:disabled {"
        "   background-color: #d1d8e0;"
        "   color: #7f8c8d;"
        "}"
        );

    // Add cancel button to close the dialog
    QPushButton* cancelButton = new QPushButton("Cancel", buttonContainer);
    cancelButton->setCursor(Qt::PointingHandCursor);
    cancelButton->setStyleSheet(
        "QPushButton {"
        "   background-color: #95a5a6;"
        "   color: white;"
        "   border: none;"
        "   padding: 8px 16px;"
        "   font-size: 13px;"
        "   font-weight: bold;"
        "   border-radius: 4px;"
        "}"
        "QPushButton:hover {"
        "   background-color: #7f8c8d;"
        "}"
        "QPushButton:pressed {"
        "   background-color: #6c7a7a;"
        "}"
        );

    connect(cancelButton, &QPushButton::clicked, this, &QDialog::reject);

    // Add buttons to layout
    buttonsLayout->addWidget(deleteButton);
    buttonsLayout->addWidget(cancelButton);
    buttonsLayout->addWidget(saveButton);

    // Add button container to content layout
    contentLayout->addWidget(buttonContainer);
    contentLayout->addStretch();

    // Add the components to the background layout
    backgroundLayout->addWidget(headerContainer);
    backgroundLayout->addWidget(contentContainer);

    // Add the background to the main layout
    mainLayout->addWidget(background);

    // Setup connections
    connect(bookingsComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &modifybookings::onBookingSelected);
    connect(deleteButton, &QPushButton::clicked, this, &modifybookings::onDeleteClicked);
    connect(saveButton, &QPushButton::clicked, this, &modifybookings::onSaveChangesClicked);

    // Set dialog properties
    this->setMinimumSize(450, 450);
    this->setFixedSize(520, 580);
    this->setWindowTitle("Modify Bookings");

    // Load bookings data
    refreshBookingsList();
}

modifybookings::~modifybookings()
{
    delete ui;
    delete db;
}

void modifybookings::refreshBookingsList()
{
    // Clear previous data
    QComboBox* bookingsComboBox = findChild<QComboBox*>("bookingsComboBox");
    if (bookingsComboBox) {
        bookingsComboBox->clear();
    }
    bookingIDs.clear();

    // Get all bookings for this user
    bookingsList = db->viewBookings(userID);

    if (bookingsList.isEmpty()) {
        QMessageBox::information(this, "No Bookings", "You do not have any bookings to modify.");
        findChild<QPushButton*>("deleteButton")->setEnabled(false);
        findChild<QPushButton*>("saveButton")->setEnabled(false);
        return;
    }

    // Add booking items to combo box
    for (int i = 0; i < bookingsList.size(); ++i) {
        QVariantMap booking = bookingsList.at(i);
        QString displayText = QString("Booking #%1 - %2 to %3").arg(i + 1)
                                  .arg(booking["departure"].toString())
                                  .arg(booking["arrival"].toString());

        bookingsComboBox->addItem(displayText);

        // Store the booking ID
        if (booking.contains("id")) {
            bookingIDs.append(booking["id"].toInt());
        } else {
            // If no ID exists, use a placeholder
            bookingIDs.append(-1);
        }
    }

    // Set first booking as selected if available
    if (bookingsComboBox->count() > 0) {
        bookingsComboBox->setCurrentIndex(0);
        onBookingSelected(0);
    }
}

void modifybookings::onBookingSelected(int index)
{
    if (index < 0 || index >= bookingsList.size()) {
        return;
    }

    // Get the selected booking
    QVariantMap booking = bookingsList.at(index);

    // Update form fields
    QComboBox* departureComboBox = findChild<QComboBox*>("departureComboBox");
    QComboBox* arrivalComboBox = findChild<QComboBox*>("arrivalComboBox");
    QLineEdit* numTicketsEdit = findChild<QLineEdit*>("numTicketsEdit");

    if (departureComboBox && arrivalComboBox && numTicketsEdit) {
        // Set combo box selections
        int departureIndex = departureComboBox->findText(booking["departure"].toString());
        if (departureIndex >= 0) {
            departureComboBox->setCurrentIndex(departureIndex);
        }

        int arrivalIndex = arrivalComboBox->findText(booking["arrival"].toString());
        if (arrivalIndex >= 0) {
            arrivalComboBox->setCurrentIndex(arrivalIndex);
        }

        numTicketsEdit->setText(booking["num"].toString());
    }
}

void modifybookings::onDeleteClicked()
{
    QComboBox* bookingsComboBox = findChild<QComboBox*>("bookingsComboBox");
    int currentIndex = bookingsComboBox->currentIndex();

    if (currentIndex < 0 || currentIndex >= bookingIDs.size()) {
        return;
    }

    // Confirm deletion with styled message box
    QMessageBox msgBox;
    msgBox.setWindowTitle("Confirm Deletion");
    msgBox.setText("Are you sure you want to delete this booking?");
    msgBox.setIcon(QMessageBox::Question);
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::No);

    // Apply stylesheet to the message box
    msgBox.setStyleSheet(
        "QMessageBox {"
        "   background-color: #f8f9fa;"
        "   color: #2c3e50;"
        "}"
        "QMessageBox QLabel {"
        "   color: #2c3e50;"
        "   font-size: 13px;"
        "}"
        "QPushButton {"
        "   background-color: #3498db;"
        "   color: white;"
        "   border: none;"
        "   padding: 6px 14px;"
        "   font-size: 12px;"
        "   border-radius: 3px;"
        "   min-width: 80px;"
        "}"
        "QPushButton:hover {"
        "   background-color: #2980b9;"
        "}"
        "QPushButton:pressed {"
        "   background-color: #1f6aa5;"
        "}"
        );

    int reply = msgBox.exec();

    if (reply == QMessageBox::Yes) {
        // Get the booking ID
        int bookingID = bookingIDs.at(currentIndex);

        // If we don't have the ID yet, we need to query for it
        if (bookingID == -1) {
            QMessageBox::critical(this, "Error", "Unable to delete booking. Booking ID not available.");
            return;
        }

        // Delete the booking
        bool success = db->deleteBooking(bookingID);

        if (success) {
            // Success message box with styling
            QMessageBox successMsg;
            successMsg.setWindowTitle("Success");
            successMsg.setText("Booking deleted successfully!");
            successMsg.setIcon(QMessageBox::Information);
            successMsg.setStandardButtons(QMessageBox::Ok);
            successMsg.setStyleSheet(msgBox.styleSheet());
            successMsg.exec();

            refreshBookingsList();
        } else {
            // Error message box with styling
            QMessageBox errorMsg;
            errorMsg.setWindowTitle("Error");
            errorMsg.setText("Failed to delete booking. Please try again.");
            errorMsg.setIcon(QMessageBox::Critical);
            errorMsg.setStandardButtons(QMessageBox::Ok);
            errorMsg.setStyleSheet(msgBox.styleSheet());
            errorMsg.exec();
        }
    }
}

void modifybookings::onSaveChangesClicked()
{
    QComboBox* bookingsComboBox = findChild<QComboBox*>("bookingsComboBox");
    int currentIndex = bookingsComboBox->currentIndex();

    if (currentIndex < 0 || currentIndex >= bookingIDs.size()) {
        return;
    }

    // Get the booking ID
    int bookingID = bookingIDs.at(currentIndex);

    // If we don't have the ID yet, we need to query for it
    if (bookingID == -1) {
        QMessageBox::critical(this, "Error", "Unable to update booking. Booking ID not available.");
        return;
    }

    // Get updated values
    QComboBox* departureComboBox = findChild<QComboBox*>("departureComboBox");
    QComboBox* arrivalComboBox = findChild<QComboBox*>("arrivalComboBox");
    QLineEdit* numTicketsEdit = findChild<QLineEdit*>("numTicketsEdit");

    QString departure = departureComboBox->currentText();
    QString arrival = arrivalComboBox->currentText();
    QString numTicketsStr = numTicketsEdit->text();

    // Create styled message box for validation errors
    QMessageBox validationMsg;
    validationMsg.setWindowTitle("Validation Error");
    validationMsg.setIcon(QMessageBox::Warning);
    validationMsg.setStandardButtons(QMessageBox::Ok);
    validationMsg.setStyleSheet(
        "QMessageBox {"
        "   background-color: #f8f9fa;"
        "   color: #2c3e50;"
        "}"
        "QMessageBox QLabel {"
        "   color: #2c3e50;"
        "   font-size: 13px;"
        "}"
        "QPushButton {"
        "   background-color: #3498db;"
        "   color: white;"
        "   border: none;"
        "   padding: 6px 14px;"
        "   font-size: 12px;"
        "   border-radius: 3px;"
        "   min-width: 80px;"
        "}"
        "QPushButton:hover {"
        "   background-color: #2980b9;"
        "}"
        "QPushButton:pressed {"
        "   background-color: #1f6aa5;"
        "}"
        );

    // Validate inputs
    if (departure.isEmpty() || arrival.isEmpty() || numTicketsStr.isEmpty()) {
        validationMsg.setText("All fields must be filled.");
        validationMsg.exec();
        return;
    }

    // Check if departure and arrival are the same
    if (departure == arrival) {
        validationMsg.setText("Departure and arrival cities cannot be the same.");
        validationMsg.exec();
        return;
    }

    bool ok;
    int numTickets = numTicketsStr.toInt(&ok);
    if (!ok || numTickets <= 0) {
        validationMsg.setText("Number of tickets must be a positive number.");
        validationMsg.exec();
        return;
    }

    // Update booking in database
    bool success = db->updateBooking(bookingID, numTickets, departure, arrival);

    if (success) {
        // Success message box with styling
        QMessageBox successMsg;
        successMsg.setWindowTitle("Success");
        successMsg.setText("Booking updated successfully!");
        successMsg.setIcon(QMessageBox::Information);
        successMsg.setStandardButtons(QMessageBox::Ok);
        successMsg.setStyleSheet(validationMsg.styleSheet());
        successMsg.exec();

        refreshBookingsList();
    } else {
        // Error message box with styling
        QMessageBox errorMsg;
        errorMsg.setWindowTitle("Error");
        errorMsg.setText("Failed to update booking. Please try again.");
        errorMsg.setIcon(QMessageBox::Critical);
        errorMsg.setStandardButtons(QMessageBox::Ok);
        errorMsg.setStyleSheet(validationMsg.styleSheet());
        errorMsg.exec();
    }
}
