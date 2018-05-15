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

private:
    void capturar(const string &mensaje, int min, int max, int &valor);
    void capturar(const string &mensaje, float min, float max, float &valor);
    void capturar(const string &mensaje, int min, int max, GuerreroTipo &valor);
};

#endif // MENUGUERREROS_H
