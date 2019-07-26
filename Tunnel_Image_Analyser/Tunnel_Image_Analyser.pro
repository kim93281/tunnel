#-------------------------------------------------
#
# Project created by QtCreator 2019-07-25T15:39:30
#
#-------------------------------------------------

QT       += core gui
QT += multimedia
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Tunnel_Image_Analyser
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        detector.cpp \
        filelistitem.cpp \
        getnames.cpp \
        main.cpp \
        analyser.cpp \
        opencvhelper.cpp

HEADERS += \
        analyser.h \
        detector.h \
        filelistitem.h \
        opencvhelper.h

FORMS += \
        analyser.ui \
        filelistitem.ui

#opencv
LIBS += `pkg-config --libs opencv`

#darknet
LIBS += -L$$PWD/../../darknet/ -ldarknet

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Style/style.qrc

INCLUDEPATH += $$PWD/../../darknet/ \
     $$PWD/../../darknet/include \
     $$PWD/../../darknet/src \
     $$PWD/../../darknet/examples
DEPENDPATH += $$PWD/../../darknet
