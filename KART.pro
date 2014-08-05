#-------------------------------------------------
#
# Project created by QtCreator 2014-06-29T10:12:36
#
#-------------------------------------------------

QT      += core gui
QT      += webkitwidgets
QT      += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = KART
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
        launchrace.cpp \
        ASixTimer.cpp \
        sixTimer.cpp \
        sixLapTimer.cpp

HEADERS  += mainwindow.h \
            launchrace.h \
            ASixTimer.h \
            sixTimer.h \
            sixLapTimer.h

FORMS    += mainwindow.ui \
            launchrace.ui
