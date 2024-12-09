QT += widgets
QT += gui
QT += qml quick
CONFIG += c++11

HEADERS += StatusKey.h
SOURCES += main.cpp StatusKey.cpp
RESOURCES = content.qrc
LIBS += -lSDL2
INCLUDEPATH += /usr/include/SDL2
TARGET = demo
