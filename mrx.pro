TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11

DEFINES += NDEBUG

SOURCES += main.cpp \
    location.cpp \
    board.cpp \
    card.cpp \
    player.cpp \
    mrx.cpp \
    detective.cpp \
    pugi/pugixml.cpp \
    parser.cpp \
    plan.cpp \
    some.cpp

HEADERS += \
    location.h \
    board.h \
    card.h \
    player.h \
    mrx.h \
    detective.h \
    pugi/pugiconfig.hpp \
    pugi/pugixml.hpp \
    parser.h \
    plan.h \
    some.h

OTHER_FILES += \
    testmap/player.xml \
    testmap/card.xml \
    testmap/board.xml \
    testmap/plan.xml

