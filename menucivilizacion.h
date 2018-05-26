#ifndef MENUCIVILIZACION_H
#define MENUCIVILIZACION_H

#include "menualdeanos.h"
#include "menuguerreros.h"
#include "MenuRecurso.h"
#include "lista.h"
#include "mapa.h"

class MenuCivilizacion
{
    Lista<Civilizacion*> civilizaciones;
    Mapa<Civilizacion*> mapa;

    string coordenada(Civilizacion *&civilizacion);
public:
    MenuCivilizacion();
    void agregarCivilizacion();
    void mostrar();
    void buscar();
    void eliminar();
    void recuperar();
    void respaldar();
    void mostrarMapa();
};

#endif // MENUCIVILIZACION_H
