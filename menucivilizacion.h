#ifndef MENUCIVILIZACION_H
#define MENUCIVILIZACION_H

#include "menualdeanos.h"
#include "lista.h"

class MenuCivilizacion
{
    Lista<Civilizacion*> civilizaciones;
public:
    MenuCivilizacion();
    void agregarCivilizacion();
    void mostrar();
    void buscar();
    void eliminar();


};

#endif // MENUCIVILIZACION_H
