QT       += core gui
QT       += network
QT       += serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    balance.cpp \
    depositbalance.cpp \
    enviroment.cpp \
    main.cpp \
    mainmenu.cpp \
    mainwindow.cpp \
    transactions.cpp \
    withdrawbalance.cpp

HEADERS += \
    balance.h \
    depositbalance.h \
    enviroment.h \
    mainmenu.h \
    mainwindow.h \
    transactions.h \
    withdrawbalance.h

FORMS += \
    balance.ui \
    depositbalance.ui \
    mainmenu.ui \
    mainwindow.ui \
    transactions.ui \
    withdrawbalance.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32: LIBS += -L$$PWD/RFIDD/build/debug/ -lRFIDD

INCLUDEPATH += $$PWD/RFIDD
DEPENDPATH += $$PWD/RFIDD
