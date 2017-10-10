#-------------------------------------------------
#
# Project created by QtCreator 2017-10-09T19:36:40
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QTCalgen
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    simchinese.cpp \
    trachinese.cpp \
    english.cpp \
    FractionCalculate.cpp \
    Calculate.cpp \
    stdafx.cpp \
    Generate.cpp \
    simnum.cpp \
    tranum.cpp \
    engnum.cpp \
    global.cpp \
    memory.cpp

HEADERS  += mainwindow.h \
    simchinese.h \
    trachinese.h \
    english.h \
    fraction.h \
    FractionCalculate.h \
    stdafx.h \
    targetver.h \
    Calculate.h \
    Generate.h \
    simnum.h \
    tranum.h \
    engnum.h \
    global.h

FORMS    += mainwindow.ui \
    simchinese.ui \
    trachinese.ui \
    english.ui \
    simnum.ui \
    tranum.ui \
    engnum.ui
