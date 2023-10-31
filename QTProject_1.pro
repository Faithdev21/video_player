QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc


unix:!macx: LIBS += -lgstreamer-1.0
unix:!macx: LIBS += -lgstvideo-1.0
unix:!macx: LIBS += -lglib-2.0
unix:!macx: LIBS += -lgobject-2.0

INCLUDEPATH += /usr/include/gstreamer-1.0/
INCLUDEPATH += /usr/include/glib-2.0/
INCLUDEPATH += /usr/lib/x86_64-linux-gnu/glib-2.0/include
