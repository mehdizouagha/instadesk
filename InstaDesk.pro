QT       += core gui
QT+=sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    activity_log.cpp \
    categories.cpp \
    connexion.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    user_preferences.cpp

HEADERS += \
    activity_log.h \
    categories.h \
    connexion.h \
    login.h \
    mainwindow.h \
    user_preferences.h

FORMS += \
    login.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
