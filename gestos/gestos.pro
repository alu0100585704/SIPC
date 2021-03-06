#-------------------------------------------------
#
# Project created by QtCreator 2019-11-18T17:42:33
#
#-------------------------------------------------

QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


CONFIG += c++11
TARGET = gestos
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
#DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

unix:QMAKE_RPATHDIR += $ORIGIN/

CONFIG += c++11

unix::MOC_DIR = $$PWD/tmp/moc
win32::MOC_DIR = $$PWD/tmp/moc
mac::OBJECTS_DIR = $$PWD/tmp/o

unix::OBJECTS_DIR = $$PWD/tmp/o
win32::OBJECTS_DIR = $$PWD/tmp/o
mac::OBJECTS_DIR = $$PWD/tmp/o

unix::RCC_DIR = $$PWD/tmp/resources
mac::RCC_DIR = $$PWD/tmp/resources
win32::RCC_DIR = $$PWD/tmp/resources

 CONFIG(debug, debug|release) {
     unix: TARGET = $$join(TARGET,,,d)
     win32: TARGET = $$join(TARGET,,,d)
     mac: TARGET = $$join(TARGET,,,d)
 }


SOURCES += \
       src/cpp/main.cpp \
       src/cpp/mainwindow.cpp \
       src/cpp/HandGesture.cpp \
       src/cpp/MyBGSubtractorColor.cpp


HEADERS += \
    src/include/HandGesture.hpp \
    src/include/MyBGSubtractorColor.hpp \
    src/include/mainwindow.h

FORMS += \
        src/Forms/mainwindow.ui


QMAKE_CXXFLAGS  += -pthread
#QMAKE_CXXFLAGS  -= -fno-keep-inline-dllexport
#QMAKE_LFLAGS_RELEASE += -static-libgcc -static-libstdc++
#QMAKE_LFLAGS_RELEASE += -static-cyggcc_s-1.dll -static-cygstdc++-6.dll
#QMAKE_CXXFLAGS_EXCEPTIONS_ON -= -mthreads
#QMAKE_LFLAGS_EXCEPTIONS_ON -= -mthreads
#QMAKE_CXXFLAGS += -std=gnu++0x -pthread
QMAKE_CFLAGS += -std=gnu++0x -pthread
LIBS += -pthread


#QMAKE_CXXFLAGS += -g
#QMAKE_CFLAGS += -g

RESOURCES += \
    src/qrc/recursos.qrc


INCLUDEPATH += $$PWD/src/include
DEPENDPATH += $$PWD/src/include

win32: INCLUDEPATH += $$PWD/libs/mingwx64/opencv412/include
win32: DEPENDPATH += $$PWD/libs/mingwx64/opencv412/include

#win32: LIBS += -L$$PWD/libs/mingwx64/opencv412/dll.a/ -llibopencv_core.dll

win32: LIBS += $$PWD/libs/mingwx64/opencv412/dll/libopencv_core412.dll
win32: LIBS += $$PWD/libs/mingwx64/opencv412/dll/libopencv_highgui412.dll
win32: LIBS += $$PWD/libs/mingwx64/opencv412/dll/libopencv_imgcodecs412.dll
win32: LIBS += $$PWD/libs/mingwx64/opencv412/dll/libopencv_imgproc412.dll
win32: LIBS += $$PWD/libs/mingwx64/opencv412/dll/libopencv_features2d412.dll
win32: LIBS += $$PWD/libs/mingwx64/opencv412/dll/libopencv_calib3d412.dll
win32: LIBS += $$PWD/libs/mingwx64/opencv412/dll/libopencv_videoio412.dll


unix:!macx: INCLUDEPATH += $$PWD/libs/ubuntux64/opencv412/include
unix:!macx: DEPENDPATH += $$PWD/libs/ubuntux64/opencv412/include

unix:!macx: LIBS += $$PWD/libs/ubuntux64/opencv412/so/libopencv_core.so.4.1
unix:!macx: LIBS += $$PWD/libs/ubuntux64/opencv412/so/libopencv_highgui.so.4.1
unix:!macx: LIBS += $$PWD/libs/ubuntux64/opencv412/so/libopencv_imgcodecs.so.4.1
unix:!macx: LIBS += $$PWD/libs/ubuntux64/opencv412/so/libopencv_imgproc.so.4.1
unix:!macx: LIBS += $$PWD/libs/ubuntux64/opencv412/so/libopencv_features2d.so.4.1
unix:!macx: LIBS += $$PWD/libs/ubuntux64/opencv412/so/libopencv_calib3d.so.4.1
unix:!macx: LIBS += $$PWD/libs/ubuntux64/opencv412/so/libopencv_videoio.so.4.1




