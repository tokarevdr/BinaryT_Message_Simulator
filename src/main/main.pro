QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    fake_sink.cpp \
    main.cpp \
    messagemodel.cpp \
    messages/abstractmessage.cpp \
    messages/coordinatespeedtimemessage.cpp \
    messages/messagefactory.cpp \
    messages/mockmessage.cpp \
    utilities/bin16.cpp \
    utilities/bin32.cpp \
    view/bin16_message_field_delegate.cpp \
    view/bin32_message_field_delegate.cpp \
    view/double_message_field_delegate.cpp \
    view/float_message_field_delegate.cpp \
    view/mainwindow.cpp \
    view/uint16_message_field_delegate.cpp \
    view/uint32_message_field_delegate.cpp

HEADERS += \
    fake_sink.h \
    isink.h \
    messagemodel.h \
    messages/abstractmessage.h \
    messages/coordinatespeedtimemessage.h \
    messages/messagefactory.h \
    messages/mockmessage.h \
    utilities/bin16.h \
    utilities/bin32.h \
    view/bin16_message_field_delegate.h \
    view/bin32_message_field_delegate.h \
    view/double_message_field_delegate.h \
    view/float_message_field_delegate.h \
    view/mainwindow.h \
    view/uint16_message_field_delegate.h \
    view/uint32_message_field_delegate.h

FORMS += \
    view/mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
