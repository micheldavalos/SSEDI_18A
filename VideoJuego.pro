TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    aldeano.cpp \
    civilizacion.cpp \
    menualdeanos.cpp \
    menucivilizacion.cpp \
    guerrero.cpp \
    menuguerreros.cpp \
    Recurso.cpp \
    MenuRecurso.cpp

HEADERS += \
    aldeano.h \
    arreglo.h \
    civilizacion.h \
    menualdeanos.h \
    lista.h \
    menucivilizacion.h \
    guerrero.h \
    listadoble.h \
    menuguerreros.h \
    Recurso.h \
    MenuRecurso.h \
    colaprioridad.h
