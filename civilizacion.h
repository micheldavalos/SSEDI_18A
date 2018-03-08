#ifndef CIVILIZACION_H
#define CIVILIZACION_H

#include "arreglo.h"
#include "aldeano.h"

class Civilizacion
{
private:
    string nombre;
    Arreglo<Aldeano> aldeanos;
    int buscarAldeano(const string &nombre);
public:
    Civilizacion();
    void agregarAldeano(const Aldeano &aldeano);
    bool eliminarAldeano(const string &nombre);
    int poblacion() const;
    string getNombre() const;
    void setNombre(const string &value);

    Aldeano &operator[](int posicion)const;
};

#endif // CIVILIZACION_H
