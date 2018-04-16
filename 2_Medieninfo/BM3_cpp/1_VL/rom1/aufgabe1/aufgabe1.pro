TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    ../example1.cpp \
    ../romlib1.cpp

data.path = $$OUT_PWD/

data.files += $$PWD/*.dat

data.files += $$PWD/*.xml

data.files += $$PWD/*.dtd

INSTALLS += data

HEADERS += \
    ../rom1.h
