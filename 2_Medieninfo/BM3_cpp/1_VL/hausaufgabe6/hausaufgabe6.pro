TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    example6.cpp \
    qlib6.cpp

HEADERS += \
    queue6.h

DISTFILES += \
    koeln.txt \
    koeln.txt

data.path = $$OUT_PWD/

data.files += $$PWD/*.txt

INSTALLS += data
