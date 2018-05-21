#ifndef MENUGUERREROS_H
#define MENUGUERREROS_H

#include "guerrero.h"
#include "civilizacion.h"

class MenuGuerreros
{
public:
    MenuGuerreros(Civilizacion* &civilizacion);
    void agregarGuerrero(Civilizacion* &civilizacion);
    void mostrarGuerreros(Civilizacion *&civilizacion);
    void buscar(Civilizacion *&civilizacion);
    void eliminar(Civilizacion *&civilizacion);
    void modificar(Civilizacion *&civilizacion);

private:
    void capturar(const string &mensaje, int min, int max, int &valor);
    void capturar(const string &mensaje, float min, float max, float &valor);
    void capturar(const string &mensaje, int min, int max, GuerreroTipo &valor);

    void buscarSalud(Civilizacion *&civilizacion, int tipo = 0);
    void buscarFuerza(Civilizacion *&civilizacion, int tipo = 0);
    void buscarClase(Civilizacion *&civilizacion);

    void eliminarID(Civilizacion *&civilizacion);
    void eliminarTipo(Civilizacion *&civilizacion);
    void eliminarSalud(Civilizacion *&civilizacion);

};

#endif // MENUGUERREROS_H
