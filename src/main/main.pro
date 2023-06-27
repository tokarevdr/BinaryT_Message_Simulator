QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    abstractmessage.cpp \
    fake_sink.cpp \
    gui/double_message_field_table_widget_delegate.cpp \
    gui/float_message_field_table_widget_delegate.cpp \
    gui/uint16_message_field_table_widget_delegate.cpp \
    message_field_table_widget.cpp \
    main.cpp \
    gui/mainwindow.cpp \
    messagemanager.cpp \
    messages/coordinatespeedtimemessage.cpp

HEADERS += \
    abstractmessage.h \
    fake_sink.h \
    gui/double_message_field_table_widget_delegate.h \
    gui/float_message_field_table_widget_delegate.h \
    gui/mainwindow.h \
    gui/uint16_message_field_table_widget_delegate.h \
    message_field_table_widget.h \
    isink.h \
    messagemanager.h \
    messages/coordinatespeedtimemessage.h

FORMS += \
    gui/mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
