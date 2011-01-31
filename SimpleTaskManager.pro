#-------------------------------------------------
#
# Project created by QtCreator 2011-01-28T00:02:47
#
#-------------------------------------------------

QT       += core gui

TARGET = SimpleTaskManager
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    TaskDialog.cpp \
    Task.cpp

HEADERS  += mainwindow.h \
    TaskDialog.h \
    Task.h

FORMS    += mainwindow.ui \
    TaskDialog.ui

OTHER_FILES +=

RESOURCES += \
    resources.qrc
