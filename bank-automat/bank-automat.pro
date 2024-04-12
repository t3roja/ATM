QT       += core gui
QT += network
QT += sql


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    balance.cpp \
    cardreader.cpp \

    image.cpp \
    loggedin.cpp \
    main.cpp \
    mainwindow.cpp \
    network.cpp \

    otheramount.cpp \
    pinreader.cpp \
    takemoney.cpp \
    transactions.cpp

HEADERS += \
    balance.h \
    cardreader.h \

    image.h \
    loggedin.h \
    mainwindow.h \
    network.h \

    otheramount.h \
    pinreader.h \
    takemoney.h \
    transactions.h

FORMS += \
    balance.ui \
    cardreader.ui \
    loggedin.ui \
    mainwindow.ui \
    otheramount.ui \
    pinreader.ui \
    takemoney.ui \
    transactions.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
