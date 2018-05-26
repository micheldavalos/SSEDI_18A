#include "civilizacion.h"

string Civilizacion::getNombre() const
{
    return nombre;
}

void Civilizacion::setNombre(const string &value)
{
    nombre = value;
}

void Civilizacion::agregarGuerrero(const Guerrero &guerrero)
{
    guerreros.insertar_inicio(guerrero);
}

unsigned int Civilizacion::poblacionGuerreros() const
{
    return guerreros.getSize();
}

Guerrero &Civilizacion::getGuerrero(int posicion) const
{
    return guerreros[posicion];
}

void Civilizacion::eliminarGuerrero(int posicion)
{
    guerreros.eliminar(posicion);
}

Aldeano &Civilizacion::operator[](int posicion) const
{
    return aldeanos[posicion];
}

int Civilizacion::buscarAldeano(const string &nombre)
{
    int posicion = -1;

    for (int i = 0; i < aldeanos.longitud(); ++i) {
        if (aldeanos[i].getNombre() == nombre) {
            posicion = i;
        }
    }

    return posicion;
}

Civilizacion::Civilizacion()
{

}

void Civilizacion::agregarAldeano(const Aldeano &aldeano)
{
    aldeanos.insertar(aldeano);
}

bool Civilizacion::eliminarAldeano(const string &nombre)
{
    // Buscamos primero si existe el aldeano con el nombre a eliminar

    int posicion = buscarAldeano(nombre);

    // Si tengo una posicion valida, entoces sí existe el aldeano
    if (posicion > -1) {
        aldeanos.eliminar(posicion);
        return true;
    }

    return false;
}

int Civilizacion::poblacion() const
{
    return aldeanos.longitud();
}

void Civilizacion::agregarRecurso(Recurso &recurso)
{
    recursos.encolar(recurso);
}

size_t Civilizacion::recursosTotales() {
    size_t cont = 0;

    for (unsigned int i = 0; i < recursos.size(); ++i) {
        cont += recursos[i].getCantidad();
    }

    return cont;

}

Recurso &Civilizacion::getRecurso(int posicion)
{
    return recursos[posicion];
}

unsigned int Civilizacion::cantidadRecursos()
{
    return recursos.size();
}
