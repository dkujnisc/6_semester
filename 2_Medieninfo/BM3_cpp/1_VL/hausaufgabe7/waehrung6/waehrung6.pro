TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    wlib6.cpp \
    wtablib6.cpp

HEADERS += \
    waehrung6.h \
    wtabelle6.h

DISTFILES += \
    waehrung.txt

data.path = $$OUT_PWD/

data.files += $$PWD/*.txt

INSTALLS += data
