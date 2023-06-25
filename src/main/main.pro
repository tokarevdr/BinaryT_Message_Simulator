QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    abstractmessage.cpp \
    fake_sink.cpp \
    main.cpp \
    mainwindow.cpp \
    messagemanager.cpp \
    messages/coordinatespeedtimemessage.cpp \
    messages_fields/coordinates_speed_time_message_fields.cpp

HEADERS += \
    abstractmessage.h \
    fake_sink.h \
    i_message_fields.h \
    isink.h \
    mainwindow.h \
    messagemanager.h \
    messages/coordinatespeedtimemessage.h \
    messages_fields/coordinates_speed_time_message_fields.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
