QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bookticketsecond.cpp \
    clickablelabel.cpp \
    database.cpp \
    main.cpp \
    mainwindow.cpp \
    modifybookings.cpp \
    startup.cpp \
    bookticket.cpp \
    viewbookings.cpp

HEADERS += \
    bookticketsecond.h \
    clickablelabel.h \
    database.h \
    mainwindow.h \
    modifybookings.h \
    startup.h \
    bookticket.h \
    viewbookings.h

FORMS += \
    modifybookings.ui \
    startup.ui \
    mainwindow.ui \
    bookticket.ui \
    bookticketsecond.ui \
    viewbookings.ui

RESOURCES += \
    Resouces.qrc

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
