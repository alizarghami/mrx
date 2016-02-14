TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11

SOURCES += main.cpp \
    location.cpp \
    board.cpp \
    card.cpp \
    initcard.cpp \
    player.cpp \
    mrx.cpp \
    detective.cpp

HEADERS += \
    location.h \
    board.h \
    card.h \
    initcard.h \
    player.h \
    mrx.h \
    detective.h

OTHER_FILES += \
    testmap/player.xml \
    testmap/card.xml \
    testmap/board.xml \
    testmap/plan.xml

