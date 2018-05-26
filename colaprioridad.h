#ifndef COLAPRIORIDAD_H
#define COLAPRIORIDAD_H

#include "listadoble.h"

template <class T>
class ColaPrioridad
{
    ListaDoble<T> colaPrioridad;
public:
    ColaPrioridad();
    bool vacia();
    void encolar(T &dato);
    T desencolar();

    T &operator[](unsigned int posicion);

    unsigned int size();

    void eliminar(int posicion);
};

template <class T>
ColaPrioridad<T>::ColaPrioridad()
{

}

template<class T>
bool ColaPrioridad<T>::vacia()
{
    return colaPrioridad.vacia();
}

template<class T>
void ColaPrioridad<T>::encolar(T &dato)
{
    if (colaPrioridad.vacia()) {
        colaPrioridad.insertar_inicio(dato);
    }
    else {
        int i;
        for (i = 0; i < colaPrioridad.getSize(); ++i) {
            if (dato < colaPrioridad[i]) {
                colaPrioridad.insertar(dato, i);
                break;
            }
        }

        if (i == colaPrioridad.getSize()) {
            colaPrioridad.insertar_final(dato);
        }
    }
}

template<class T>
T ColaPrioridad<T>::desencolar()
{
    if (colaPrioridad.vacia()) {
        throw out_of_range("Cola de Prioridad Vacia");
    }
    T copia = colaPrioridad[0];
    colaPrioridad.eliminar_inicio();

    return copia;
}

template<class T>
unsigned int ColaPrioridad<T>::size()
{
    return colaPrioridad.getSize();
}

template<class T>
T &ColaPrioridad<T>::operator[](unsigned int posicion)
{
    return colaPrioridad[posicion];
}

template<class T>
void ColaPrioridad<T>::eliminar(int posicion)
{
    colaPrioridad.eliminar(posicion);
}

#endif // COLAPRIORIDAD_H
