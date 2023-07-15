QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    abstractmessage.cpp \
    fake_sink.cpp \
    fields/messagefieldsfactory.cpp \
    fields/mockmessagefields.cpp \
    message_field_table_widget.cpp \
    main.cpp \
    message_fields_model.cpp \
    messagemanager.cpp \
    messages/coordinatespeedtimemessage.cpp \
    messages/mockmessage.cpp \
    utilities/bin16.cpp \
    utilities/bin32.cpp \
    view/double_message_field_table_widget_delegate.cpp \
    view/float_message_field_table_widget_delegate.cpp \
    view/mainwindow.cpp \
    view/uint16_message_field_table_widget_delegate.cpp

HEADERS += \
    abstractmessage.h \
    fake_sink.h \
    fields/imessagefields.h \
    fields/messagefieldsfactory.h \
    fields/mockmessagefields.h \
    message_field_table_widget.h \
    isink.h \
    message_fields_model.h \
    messagemanager.h \
    messages/messagetype.h \
    messages/coordinatespeedtimemessage.h \
    messages/mockmessage.h \
    utilities/bin16.h \
    utilities/bin32.h \
    view/double_message_field_table_widget_delegate.h \
    view/float_message_field_table_widget_delegate.h \
    view/mainwindow.h \
    view/uint16_message_field_table_widget_delegate.h

FORMS += \
    view/mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
