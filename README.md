# Train Ticket Booking System

A comprehensive train ticket booking system built using C++ and Qt Widgets, providing a user-friendly graphical interface for booking and managing train reservations.

## Table of Contents
- [Features](#features)
- [Screenshots](#screenshots)
- [Prerequisites](#prerequisites)
- [Installation](#installation)
- [Usage](#usage)
- [Project Structure](#project-structure)
- [Technologies Used](#technologies-used)
- [Contributing](#contributing)
- [License](#license)
- [Contact](#contact)

## Features

### Core Functionality
- **User Authentication**: Secure login and registration system
- **Train Search**: Search for available trains by source, destination, and date
- **Seat Selection**: Interactive seat selection with real-time availability
- **Booking Management**: Book tickets with passenger details
- **Ticket Generation**: Generate and print booking confirmations
- **Payment Processing**: Secure payment gateway integration
- **Booking History**: View past bookings and travel history
- **Cancellation**: Cancel bookings with refund processing

### User Interface
- **Modern GUI**: Clean and intuitive Qt-based interface
- **Responsive Design**: Adaptive layout for different screen sizes
- **User-Friendly Navigation**: Easy-to-use menu system
- **Real-time Updates**: Live seat availability and booking status

### Admin Features
- **Train Management**: Add, modify, and delete train schedules
- **Route Management**: Manage train routes and stations
- **Booking Analytics**: View booking statistics and reports
- **User Management**: Manage user accounts and permissions

## Screenshots

*Add screenshots of your application here to showcase the user interface*

## Prerequisites

Before running this application, ensure you have the following installed:

- **C++ Compiler**: GCC 7.3+ or MSVC 2017+
- **Qt Framework**: Qt 5.12+ or Qt 6.x
- **CMake**: Version 3.16+ (if using CMake build system)
- **Database**: SQLite (included) or MySQL/PostgreSQL (optional)

### System Requirements
- **Operating System**: Windows 10+, macOS 10.14+, or Linux (Ubuntu 18.04+)
- **RAM**: Minimum 4GB, Recommended 8GB
- **Storage**: 500MB free space
- **Display**: 1024x768 minimum resolution

## Installation

### Method 1: Using Qt Creator (Recommended)
1. **Clone the repository**:
   ```bash
   git clone https://github.com/Yash212006/Train-Ticket-Booking-System.git
   cd Train-Ticket-Booking-System
   ```

2. **Open Qt Creator**:
   - Launch Qt Creator
   - Open the project file (`*.pro` or `CMakeLists.txt`)
   - Configure the project with your Qt kit

3. **Build and Run**:
   - Click the "Build" button or press `Ctrl+B`
   - Click "Run" or press `Ctrl+R` to launch the application

### Method 2: Command Line Build
1. **Clone and navigate**:
   ```bash
   git clone https://github.com/Yash212006/Train-Ticket-Booking-System.git
   cd Train-Ticket-Booking-System
   ```

2. **Create build directory**:
   ```bash
   mkdir build
   cd build
   ```

3. **Configure and build**:
   ```bash
   # If using qmake
   qmake ..
   make
   
   # If using CMake
   cmake ..
   make
   ```

4. **Run the application**:
   ```bash
   ./TrainBookingSystem
   ```

## Usage


1. **Registration/Login**:
   - Create a new account or login with existing credentials
   - Complete profile information

2. **Search Trains**:
   - Enter source and destination stations
   - Select travel date
   - Choose preferred class (1AC, 2AC, 3AC, Sleeper, etc.)

3. **Book Tickets**:
   - Select desired train from search results
   - Choose seats from the seat map
   - Enter passenger details
   - Proceed to payment

4. **Manage Bookings**:
   - View booking history
   - Download/Print tickets
   - Cancel bookings if needed


## Project Structure

```
Train-Ticket-Booking-System/
├── src/
│   ├── main.cpp                 # Application entry point
│   ├── mainwindow.cpp/.h        # Main window implementation
│   ├── authentication/
│   │   ├── login.cpp/.h         # Login functionality
│   │   └── register.cpp/.h      # Registration functionality
│   ├── booking/
│   │   ├── searchtrains.cpp/.h  # Train search functionality
│   │   ├── seatselection.cpp/.h # Seat selection interface
│   │   └── booking.cpp/.h       # Booking management
│   ├── admin/
│   │   ├── adminpanel.cpp/.h    # Admin dashboard
│   │   └── trainmanagement.cpp/.h # Train management
│   └── database/
│       ├── databasemanager.cpp/.h # Database operations
│       └── models/              # Data models
├── ui/
│   ├── mainwindow.ui            # Main window UI file
│   ├── login.ui                 # Login dialog UI
│   └── booking.ui               # Booking interface UI
├── resources/
│   ├── images/                  # Application icons and images
│   ├── stylesheets/             # CSS stylesheets
│   └── database/                # Database schema files
├── docs/                        # Documentation
├── tests/                       # Unit tests
├── CMakeLists.txt               # CMake build configuration
├── TrainBookingSystem.pro       # Qt project file
└── README.md                    # This file
```

## Technologies Used

- **Programming Language**: C++17
- **GUI Framework**: Qt Widgets
- **Database**: SQLite (default) / MySQL / PostgreSQL
- **Build System**: CMake / qmake
- **Version Control**: Git
- **IDE**: Qt Creator (recommended)

### Key Qt Modules
- Qt Widgets (GUI components)
- Qt SQL (Database connectivity)
- Qt Network (Network operations)
- Qt PrintSupport (Ticket printing)
- Qt Charts (Analytics visualization)


## Contributing

We welcome contributions to improve the Train Ticket Booking System! Here's how you can help:

1. **Fork the repository**
2. **Create a feature branch**:
   ```bash
   git checkout -b feature/your-feature-name
   ```
3. **Make your changes and commit**:
   ```bash
   git commit -m "Add your feature description"
   ```
4. **Push to your branch**:
   ```bash
   git push origin feature/your-feature-name
   ```
5. **Create a Pull Request**

### Coding Standards
- Follow Qt coding conventions
- Use meaningful variable and function names
- Add comments for complex logic
- Ensure proper error handling
- Write unit tests for new features


## Contact

**Developer**: Yash
**GitHub**: [@Yash212006](https://github.com/Yash212006)
**Project Repository**: [Train-Ticket-Booking-System](https://github.com/Yash212006/Train-Ticket-Booking-System)

For bug reports and feature requests, please open an issue on GitHub.

---

### Support

If you find this project helpful, please consider:
- ⭐ Starring the repository
- 🍴 Forking the project
- 📝 Contributing to the codebase
- 📢 Sharing with others

**Happy Coding!** 🚂✨
