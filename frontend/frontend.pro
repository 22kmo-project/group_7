QT       += core gui
QT +=network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    balancewindow.cpp \
    clientwindow.cpp \
    depositwindow.cpp \
    drawwindow.cpp \
    main.cpp \
    mainwindow.cpp \
    myurl.cpp \
    transactionwindow.cpp \
    transferwindow.cpp
    
HEADERS += \
    balancewindow.h \
    clientwindow.h \
    depositwindow.h \
    drawwindow.h \
    mainwindow.h \
    myurl.h \
    transactionwindow.h \
    transferwindow.h
    
FORMS += \
    balancewindow.ui \
    clientwindow.ui \
    depositwindow.ui \
    drawwindow.ui \
    mainwindow.ui \
    transactionwindow.ui \
    transferwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
