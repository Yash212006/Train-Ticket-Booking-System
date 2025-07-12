#include "viewbookings.h"
#include "ui_viewbookings.h"
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDebug>
#include <QScrollArea>
#include <QFont>
#include <QPalette>
#include <QGraphicsDropShadowEffect>
#include <QPainter>
#include <QPushButton>  // Added for QPushButton
#include <QWidget>

// Custom widget to create a beautiful gradient background
class GradientBackground : public QWidget {
public:
    explicit GradientBackground(QWidget *parent = nullptr) : QWidget(parent) {}

protected:
    void paintEvent(QPaintEvent *event) override {
        Q_UNUSED(event);  // Fixed the unused parameter error
        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing);

        // Create a subtle gradient background
        QLinearGradient gradient(0, 0, 0, height());
        gradient.setColorAt(0, QColor(235, 245, 251));
        gradient.setColorAt(1, QColor(240, 240, 245));

        painter.fillRect(rect(), gradient);

        // Optional: Add a subtle pattern or texture
        painter.setPen(QPen(QColor(200, 210, 230, 20), 1));
        for (int i = 0; i < height(); i += 20) {
            painter.drawLine(0, i, width(), i);
        }
    }
};

viewbookings::viewbookings(QWidget *parent, const QString& uid)
    : QDialog(parent)
    , ui(new Ui::viewbookings)
    , userID(uid)
{
    ui->setupUi(this);
    QVariantMap user = Database::getUserData();
    // Debug information
    qDebug() << "Opening viewbookings with userID:" << userID;
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
        "  stop:0 #3498db, stop:1 #2980b9);"
        "  border-radius: 8px 8px 0px 0px;"
        "  color: white;"
        "  padding: 10px;"
        "}"
        );

    QVBoxLayout* headerLayout = new QVBoxLayout(headerContainer);

    // Add a title label with enhanced styling
    QLabel* titleLabel = new QLabel("Your Bookings", headerContainer);
    QFont titleFont("Arial", 16, QFont::Bold);
    titleLabel->setFont(titleFont);
    titleLabel->setAlignment(Qt::AlignCenter);
    titleLabel->setStyleSheet("color: white; margin-bottom: 5px;");

    // User ID label with enhanced styling
    QLabel* userid = new QLabel("Bookings for user ID: " + user["uid"].toString(), headerContainer);
    QFont userIdFont("Arial", 11);
    userid->setFont(userIdFont);
    userid->setAlignment(Qt::AlignCenter);
    userid->setStyleSheet("color: rgba(255, 255, 255, 0.9);");

    // Add title and user ID to the header layout
    headerLayout->addWidget(titleLabel);
    headerLayout->addWidget(userid);

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
    contentLayout->setContentsMargins(15, 15, 15, 15);

    // Create a scroll area with styling
    QScrollArea* scrollArea = new QScrollArea(contentContainer);
    scrollArea->setWidgetResizable(true);
    scrollArea->setFrameShape(QFrame::NoFrame);
    scrollArea->setStyleSheet("QScrollArea { background-color: transparent; border: none; }");

    // Create a widget to hold all the bookings
    QWidget* scrollWidget = new QWidget();
    scrollWidget->setStyleSheet("background-color: transparent;");
    QVBoxLayout* scrollLayout = new QVBoxLayout(scrollWidget);
    scrollLayout->setSpacing(15);

    // Load and display the booking information if userID is provided
    if (!userID.isEmpty()) {
        // Get all bookings for this user
        QList<QVariantMap> bookingsList = db->viewBookings(userID);
        qDebug() << "Number of bookings found:" << bookingsList.size();
        if (bookingsList.isEmpty()) {
            // No bookings found - styled message
            QLabel* noBookingLabel = new QLabel("No bookings found for this user.", scrollWidget);
            noBookingLabel->setAlignment(Qt::AlignCenter);
            noBookingLabel->setStyleSheet("color: #7f8c8d; font-size: 14px; padding: 20px; font-style: italic;");
            scrollLayout->addWidget(noBookingLabel);
            qDebug() << "No bookings found for user:" << userID;
        } else {
            // Display each booking in a separate styled card
            for (int i = 0; i < bookingsList.size(); ++i) {
                QVariantMap booking = bookingsList.at(i);

                // Create a container widget for the booking card
                QWidget* bookingCard = new QWidget(scrollWidget);
                bookingCard->setObjectName("bookingCard");
                bookingCard->setStyleSheet(
                    "QWidget#bookingCard {"
                    "  background-color: #f8f9fa;"
                    "  border-radius: 8px;"
                    "  border: 1px solid #e9ecef;"
                    "}"
                    );

                // Add shadow effect to cards
                QGraphicsDropShadowEffect* cardShadow = new QGraphicsDropShadowEffect;
                cardShadow->setBlurRadius(10);
                cardShadow->setColor(QColor(0, 0, 0, 30));
                cardShadow->setOffset(0, 2);
                bookingCard->setGraphicsEffect(cardShadow);

                QVBoxLayout* cardLayout = new QVBoxLayout(bookingCard);

                // Booking header with gradient background
                QWidget* headerWidget = new QWidget(bookingCard);
                headerWidget->setObjectName("cardHeader");
                headerWidget->setStyleSheet(
                    "QWidget#cardHeader {"
                    "  background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, "
                    "  stop:0 #3498db, stop:1 #2980b9);"
                    "  border-radius: 7px 7px 0px 0px;"
                    "  padding: 5px;"
                    "}"
                    );
                QHBoxLayout* headerWidgetLayout = new QHBoxLayout(headerWidget);
                headerWidgetLayout->setContentsMargins(10, 5, 10, 5);

                QLabel* headerLabel = new QLabel(QString("Booking #%1").arg(i + 1), headerWidget);
                headerLabel->setStyleSheet("font-weight: bold; font-size: 14px; color: white;");
                headerWidgetLayout->addWidget(headerLabel);

                // Booking details with more structured layout
                QWidget* detailsWidget = new QWidget(bookingCard);
                QVBoxLayout* detailsLayout = new QVBoxLayout(detailsWidget);
                detailsLayout->setContentsMargins(15, 15, 15, 15);

                QStringList detailItems = {
                    QString("<b>No. of Tickets:</b> %1").arg(booking["num"].toString()),
                    QString("<b>Departure:</b> %1").arg(booking["departure"].toString()),
                    QString("<b>Arrival:</b> %1").arg(booking["arrival"].toString())
                };

                for (const QString& item : detailItems) {
                    QLabel* detailLabel = new QLabel(item, detailsWidget);
                    detailLabel->setTextFormat(Qt::RichText);
                    detailLabel->setStyleSheet("color: #34495e; font-size: 13px; padding: 3px 0;");
                    detailsLayout->addWidget(detailLabel);
                }

                // Add elements to card layout
                cardLayout->addWidget(headerWidget);
                cardLayout->addWidget(detailsWidget);
                cardLayout->setContentsMargins(0, 0, 0, 0);
                cardLayout->setSpacing(0);

                // Add the booking card to the scroll layout
                scrollLayout->addWidget(bookingCard);

                // Debug output
                qDebug() << "Added booking" << i+1 << "to display:" << booking["num"].toString();
            }
        }
    } else {
        // No user ID provided - styled error message
        QLabel* errorLabel = new QLabel("Error: No user ID provided.", scrollWidget);
        errorLabel->setAlignment(Qt::AlignCenter);
        errorLabel->setStyleSheet("color: #e74c3c; font-size: 14px; font-weight: bold; padding: 20px;");
        scrollLayout->addWidget(errorLabel);
        qDebug() << "No user ID provided to viewbookings";
    }

    // Add a stretcher at the end to push everything up
    scrollLayout->addStretch();

    // Set the scroll widget as the scroll area's widget
    scrollArea->setWidget(scrollWidget);

    // Style the scrollbars
    scrollArea->setStyleSheet(scrollArea->styleSheet() +
                              "QScrollBar:vertical {"
                              "   border: none;"
                              "   background: #f0f0f0;"
                              "   width: 8px;"
                              "   margin: 0px;"
                              "}"
                              "QScrollBar::handle:vertical {"
                              "   background: #bdc3c7;"
                              "   min-height: 20px;"
                              "   border-radius: 4px;"
                              "}"
                              "QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical {"
                              "   border: none;"
                              "   background: none;"
                              "}"
                              "QScrollBar::up-arrow:vertical, QScrollBar::down-arrow:vertical {"
                              "   border: none;"
                              "   background: none;"
                              "}"
                              "QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical {"
                              "   background: none;"
                              "}"
                              );

    // Add the scroll area to the content layout
    contentLayout->addWidget(scrollArea);

    // Add close button at the bottom
    QWidget* buttonContainer = new QWidget(background);
    buttonContainer->setStyleSheet("background-color: transparent;");
    QHBoxLayout* buttonLayout = new QHBoxLayout(buttonContainer);
    buttonLayout->setContentsMargins(0, 10, 0, 5);

    // Fixed QPushButton declaration
    QPushButton* closeButton = new QPushButton("Close", buttonContainer);
    closeButton->setCursor(Qt::PointingHandCursor);
    closeButton->setStyleSheet(
        "QPushButton {"
        "   background-color: #3498db;"
        "   color: white;"
        "   border: none;"
        "   padding: 8px 16px;"
        "   font-size: 13px;"
        "   font-weight: bold;"
        "   border-radius: 4px;"
        "}"
        "QPushButton:hover {"
        "   background-color: #2980b9;"
        "}"
        "QPushButton:pressed {"
        "   background-color: #1f6aa5;"
        "}"
        );

    connect(closeButton, &QPushButton::clicked, this, &QDialog::accept);

    buttonLayout->addStretch();
    buttonLayout->addWidget(closeButton);
    buttonLayout->addStretch();

    // Add all components to the background layout
    backgroundLayout->addWidget(headerContainer);
    backgroundLayout->addWidget(contentContainer);
    backgroundLayout->addWidget(buttonContainer);

    // Add the background to the main layout
    mainLayout->addWidget(background);

    // Set dialog size
    this->setMinimumSize(450, 350);
    this->setFixedSize(520, 620);
}

viewbookings::~viewbookings()
{
    delete ui;
    delete db;
}
