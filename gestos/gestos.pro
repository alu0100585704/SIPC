#-------------------------------------------------
#
# Project created by QtCreator 2019-11-18T17:42:33
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = gestos
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
       ../proyecto/main.cpp \
        mainwindow.cpp \
    ../proyecto/HandGesture.cpp \
    ../proyecto/MyBGSubtractorColor.cpp


HEADERS += \
        mainwindow.h \
    ../proyecto/HandGesture.hpp \
    ../proyecto/MyBGSubtractorColor.hpp

FORMS += \
        mainwindow.ui

INCLUDEPATH += $$PWD/libs/mingw64/opencv
DEPENDPATH += $$PWD/libs/mingw64/opencv



LIBS += $$PWD/libs/mingw64/opencv/libopencv_core412.dll
LIBS += $$PWD/libs/mingw64/opencv/libopencv_highgui412.dll
LIBS += $$PWD/libs/mingw64/opencv/libopencv_imgcodecs412.dll
LIBS += $$PWD/libs/mingw64/opencv/libopencv_imgproc412.dll
LIBS += $$PWD/libs/mingw64/opencv/libopencv_features2d412.dll
LIBS += $$PWD/libs/mingw64/opencv/libopencv_calib3d412.dll
LIBS += $$PWD/libs/mingw64/opencv/libopencv_videoio412.dll
