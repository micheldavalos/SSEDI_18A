#ifndef MENUGUERREROS_H
#define MENUGUERREROS_H

#include "guerrero.h"
#include "civilizacion.h"

class MenuGuerreros
{
public:
    MenuGuerreros(Civilizacion* &civilizacion);
    void agregarGuerrero(Civilizacion* &civilizacion);
};

#endif // MENUGUERREROS_H
