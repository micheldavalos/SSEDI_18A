#ifndef CIVILIZACION_H
#define CIVILIZACION_H

#include "arreglo.h"
#include "listadoble.h"
#include "aldeano.h"
#include "guerrero.h"
#include "Recurso.h"
#include "colaprioridad.h"

class Civilizacion
{
private:
    string nombre;

    Arreglo<Aldeano> aldeanos;
    ListaDoble<Guerrero> guerreros;
    ColaPrioridad<Recurso> recursos;

    int buscarAldeano(const string &nombre);
public:
    Civilizacion();
    void agregarAldeano(const Aldeano &aldeano);
    bool eliminarAldeano(const string &nombre);
    int poblacion() const;
    string getNombre() const;
    void setNombre(const string &value);

    // Guerrero
    void agregarGuerrero(const Guerrero &guerrero);
    unsigned int poblacionGuerreros() const;
    Guerrero& getGuerrero(int posicion) const;
    void eliminarGuerrero(int posicion);

    // Recurso
    void agregarRecurso(Recurso &recurso);
    size_t recursosTotales();
    unsigned int cantidadRecursos();
    Recurso &getRecurso(int posicion);
    void eliminar(int posicion);


    Aldeano &operator[](int posicion)const;
};

#endif // CIVILIZACION_H
