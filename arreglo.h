#ifndef ARREGLO_H
#define ARREGLO_H

#include <iostream>
#include <stdexcept>
using namespace std;

template <class T>
class Arreglo
{
    T *arreglo;
    const static int MAX = 5;
    int indice;
    int tam;
public:
    Arreglo();
    Arreglo(const Arreglo<T> &a);
    ~Arreglo();
    void insertar(const T &dato);
    void insertar_inicio(const T &dato);
    void insertar(const T &dato, int posicion);

    void eliminar_ultimo();
    void eliminar_inicio();
    void eliminar(int posicion);

    T &operator[](int posicion)const;
    int longitud()const;
    int tamanio()const;
};

template <class T>
Arreglo<T>::Arreglo()
{
    arreglo = new T[MAX];
    tam = MAX;
    indice = 0;
}
template <class T>
Arreglo<T>::Arreglo(const Arreglo<T> &a)
{
    tam = a.tamanio();
    indice = a.longitud();
    arreglo = new T[tam];

    for (int i = 0; i < indice; ++i) {
        arreglo[i] = a[i];
    }
}
template <class T>
Arreglo<T>::~Arreglo()
{
    delete []arreglo;
}
template <class T>
void Arreglo<T>::insertar(const T &dato)
{
    if (indice < tam) {
        arreglo[indice++] = dato;
    }
    else {
        T *temp = new T[tam+5];
        for(int i = 0; i < indice; i++) {
            temp[i] = arreglo[i];
        }
        delete []arreglo;
        arreglo = temp;
        tam = tam + 5;
        arreglo[indice++] = dato;
    }
}
template <class T>
void Arreglo<T>::insertar_inicio(const T &dato)
{
    if (indice == tam) {
        T *temp = new T[tam+5];
        for(int i = 0; i < indice; i++) {
            temp[i] = arreglo[i];
        }
        delete []arreglo;
        arreglo = temp;
        tam = tam + 5;
    }
    for (int i = indice; i > 0; i--) {
        arreglo[i] = arreglo[i-1];
    }
    arreglo[0] = dato;
    indice++;
}
template <class T>
void Arreglo<T>::insertar(const T &dato, int posicion)
{
    if (posicion == 0) {
        insertar_inicio(dato);
    }
    else if (posicion == indice) {
        insertar(dato);
    }
    else if (posicion > 0 && posicion < indice) {
        if (indice == tam) {
            T *temp = new T[tam+5];
            for(int i = 0; i < indice; i++) {
                temp[i] = arreglo[i];
            }
            delete []arreglo;
            arreglo = temp;
            tam = tam + 5;
        }
        for (int i = indice; i > posicion ; i--) {
            arreglo[i] = arreglo[i-1];
        }
        arreglo[posicion] = dato;
        indice++;
    }
    else {
        throw out_of_range("Posicion no Valida");
    }

}
template <class T>
void Arreglo<T>::eliminar_ultimo()
{
    if (indice == 0) {
        throw out_of_range("Arreglo vacio");
    }
    indice--;
}
template <class T>
void Arreglo<T>::eliminar_inicio()
{
    if (indice == 0) {
        throw out_of_range("Arreglo vacio");
    }
    for (int i = 0; i < indice - 1; ++i) {
        arreglo[i] = arreglo[i+1];
    }
    indice--;
}

template <class T>
void Arreglo<T>::eliminar(int posicion)
{
    if (posicion < 0 || posicion >= indice) {
        throw out_of_range("Posicion no valida");
    }

    for (int i = posicion; i < indice - 1; ++i) {
        arreglo[i] = arreglo[i+1];
    }
    indice--;
}

template <class T>
T &Arreglo<T>::operator[](int posicion) const
{
    if (posicion < 0 || posicion >= indice) {
        throw out_of_range("No existe la posicion");
    }
    return arreglo[posicion];
}
template <class T>
int Arreglo<T>::longitud() const
{
    return indice;
}
template <class T>
int Arreglo<T>::tamanio() const
{
    return tam;
}

#endif // ARREGLO_H
