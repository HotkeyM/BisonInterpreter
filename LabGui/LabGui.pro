#-------------------------------------------------
#
# Project created by QtCreator 2011-12-12T01:16:52
#
#-------------------------------------------------

QT       += core gui

TARGET = LabGui
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    lex.yy.cc \
    calc++-parser.tab.cc \
    bis.cpp \
    calc++-driver.cc \
    graphon.cpp \
    varmap.cpp \
    vmap.cpp

HEADERS  += mainwindow.h \
    stack.hh \
    position.hh \
    location.hh \
    calc++-parser.tab.hh \
    calc++-parser.hh \
    bis.h \
    calc++-driver.hh \
    graphon.h \
    varmap.h \
    vmap.h

FORMS    += mainwindow.ui




