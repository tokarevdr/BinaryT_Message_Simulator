QT       += core gui serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    messagemodel.cpp \
    messages/abstractmessage.cpp \
    messages/coordinatespeedtimemessage.cpp \
    messages/messagefactory.cpp \
    messages/mockmessage.cpp \
    sinks/fake_sink.cpp \
    sinks/filesink.cpp \
    utilities/bin16.cpp \
    utilities/bin32.cpp \
    view/bin16_message_field_delegate.cpp \
    view/bin32_message_field_delegate.cpp \
    view/double_message_field_delegate.cpp \
    view/float_message_field_delegate.cpp \
    view/mainwindow.cpp \
    view/messagesinkdialog.cpp \
    view/uint16_message_field_delegate.cpp \
    view/uint32_message_field_delegate.cpp

HEADERS += \
    messagemodel.h \
    messages/abstractmessage.h \
    messages/coordinatespeedtimemessage.h \
    messages/messagefactory.h \
    messages/mockmessage.h \
    sinks/fake_sink.h \
    sinks/filesink.h \
    sinks/isink.h \
    utilities/bin16.h \
    utilities/bin32.h \
    view/bin16_message_field_delegate.h \
    view/bin32_message_field_delegate.h \
    view/double_message_field_delegate.h \
    view/float_message_field_delegate.h \
    view/mainwindow.h \
    view/messagesinkdialog.h \
    view/uint16_message_field_delegate.h \
    view/uint32_message_field_delegate.h

FORMS += \
    view/mainwindow.ui \
    view/messagesinkdialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
