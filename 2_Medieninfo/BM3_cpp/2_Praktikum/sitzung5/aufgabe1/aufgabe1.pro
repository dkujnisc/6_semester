TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    wlib6.cpp \
    wtablib6.cpp \
    example6.cpp

DISTFILES += \
    waehrung.txt

HEADERS += \
    waehrung6.h \
    wtabelle6.h

data.path = $$OUT_PWD/

data.files += $$PWD/*.dat

data.files += $$PWD/*.xml

data.files += $$PWD/*.dtd

data.files += $$PWD/*.txt

INSTALLS += data
