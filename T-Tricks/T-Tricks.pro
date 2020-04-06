TEMPLATE     = vcapp
TARGET       = T-Tricks
CONFIG      += warn_on qt debug_and_release windows console
HEADERS     += mainwindow.h gamewindow.h optionwindow.h
SOURCES     += mainwindow.cpp main.cpp gamewindow.cpp optionwindow.cpp
INCLUDEPATH += .
LIBS	      += 
QT += widgets