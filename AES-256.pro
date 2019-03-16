#-------------------------------------------------
#
# Project created by QtCreator 2016-12-19T10:16:39
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AES-256
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    AES_algorithm.cpp

HEADERS  += mainwindow.h \
    AES-256.h \
    StdAfx.h

FORMS    += mainwindow.ui

RC_FILE = myico.rc

DISTFILES += \
    myico.rc
