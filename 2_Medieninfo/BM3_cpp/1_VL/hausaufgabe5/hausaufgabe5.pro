TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    wlib.cpp \
    wtablib.cpp

HEADERS += \
    waehrung.h \
    wtabelle.h

data.path = $$OUT_PWD/

data.files += $$PWD/*.dat

data.files += $$PWD/*.xml

data.files += $$PWD/*.dtd

data.files += $$PWD/*.txt

INSTALLS += data

DISTFILES += \
    waehrung.txt
