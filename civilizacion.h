#ifndef CIVILIZACION_H
#define CIVILIZACION_H

#include "arreglo.h"
#include "listadoble.h"
#include "aldeano.h"
#include "guerrero.h"

class Civilizacion
{
private:
    string nombre;

    Arreglo<Aldeano> aldeanos;
    ListaDoble<Guerrero> guerreros;

    int buscarAldeano(const string &nombre);
public:
    Civilizacion();
    void agregarAldeano(const Aldeano &aldeano);
    bool eliminarAldeano(const string &nombre);
    int poblacion() const;
    string getNombre() const;
    void setNombre(const string &value);

    /*!
     * \brief agregar guerreros a la civilizacion
     * \param Guerrero: objeto de tipo guerrero
     * \return nada
     */
    void agregarGuerrero(const Guerrero &guerrero);

    Aldeano &operator[](int posicion)const;
};

#endif // CIVILIZACION_H
