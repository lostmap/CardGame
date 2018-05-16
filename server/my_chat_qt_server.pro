QT -= gui
QT += network xml

CONFIG += c++11 console
CONFIG -= app_bundle

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.cpp \
    myserver.cpp \
    user.cpp \
    player.cpp \
    abstractcard.cpp \
    game.cpp \
    interlayer.cpp \
    entity.cpp \
    deck.cpp \
    field.cpp \
    party.cpp \
    property.cpp \
    entitywithproperty.cpp \
    entitywithbuff.cpp \
    entityspy.cpp \
    entityrollcall.cpp \
    cardfactory.cpp \
    entityfactory.cpp \
    entityrollcallfactory.cpp \
    entityspyfactory.cpp \
    entitywithbufffactory.cpp

HEADERS += \
    myserver.h \
    user.h \
    player.h \
    abstractcard.h \
    game.h \
    interlayer.h \
    entity.h \
    deck.h \
    field.h \
    party.h \
    property.h \
    define.h \
    entitywithproperty.h \
    entitywithbuff.h \
    entityspy.h \
    entityrollcall.h \
    cardfactory.h \
    entityfactory.h \
    entityrollcallfactory.h \
    entityspyfactory.h \
    entitywithbufffactory.h
