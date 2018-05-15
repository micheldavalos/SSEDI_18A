#ifndef LISTADOBLE_H
#define LISTADOBLE_H

#include <iostream>
#include <stdexcept>
using namespace std;

template <class T>
class Nodo
{
    T dato;
    Nodo<T> *sig;
    Nodo<T> *ant;
public:
    Nodo(const T &d)
    {
        dato = d;
        sig = nullptr;
        ant = nullptr;
    }

    template <class>
    friend class ListaDoble;
};

template <class T>
class ListaDoble
{
    Nodo<T> *primero;
    Nodo<T> *ultimo;
    unsigned int size;
public:
    ListaDoble();
    bool vacia();
    void insertar_inicio(const T &dato);
    void insertar_final(const T &dato);
    void insertar(const T &dato, int posicion);

    void eliminar_inicio();
    void eliminar_final();
    void eliminar(int posicion);

    T& operator[](int posicion) const;
    unsigned int getSize() const;
};
template <class T>
ListaDoble<T>::ListaDoble()
{
    primero = ultimo = nullptr;
    size = 0;
}
template <class T>
unsigned int ListaDoble<T>::getSize() const
{
    return size;
}

template<class T>
bool ListaDoble<T>::vacia()
{
    return primero == nullptr;
}

template<class T>
void ListaDoble<T>::insertar_inicio(const T &dato)
{
    if (vacia()) {
        Nodo<T> *nuevo = new Nodo<T>(dato);
        primero = nuevo;
        ultimo  = nuevo;
    }
    else {
        Nodo<T> *nuevo = new Nodo<T>(dato);
        nuevo->sig = primero;
        primero->ant = nuevo;
        primero = nuevo;
    }

    size++;
}

template<class T>
void ListaDoble<T>::insertar_final(const T &dato)
{
    if (vacia()) {
        Nodo<T> *nuevo = new Nodo<T>(dato);
        primero = nuevo;
        ultimo  = nuevo;
    }
    else {
        Nodo<T> *nuevo = new Nodo<T>(dato);
        nuevo->ant = ultimo;
        ultimo->sig = nuevo;
        ultimo = nuevo;
    }
    size++;
}

template<class T>
void ListaDoble<T>::insertar(const T &dato, int posicion)
{
    if (posicion < 0 || posicion >= size) {
        throw out_of_range("Posicion no valida");
    }
    else {
        if (posicion == 0) {
            insertar_inicio(dato);
        }
        else {
            Nodo<T> *nuevo = new Nodo<T>(dato);
            Nodo<T> *temp = primero;
            unsigned int contador = 0;

            while (temp != nullptr) {
                if (contador++ == posicion) {
                    nuevo->ant = temp->ant;
                    nuevo->sig = temp;
                    temp->ant->sig = nuevo;
                    temp->ant = nuevo;
                    size++;
                    break;
                }
                temp = temp->sig;
            }
        }
    }
}

template<class T>
void ListaDoble<T>::eliminar_inicio()
{
    if (vacia()) {
        throw out_of_range("Lista Vacia");
    }
    if (primero == ultimo) {
        delete primero;
        primero = ultimo = nullptr;
    }
    else {
        Nodo<T> *temp = primero;
        temp->sig->ant = nullptr;
        primero = primero->sig;
        delete temp;
    }
    size--;
}

template<class T>
void ListaDoble<T>::eliminar_final()
{
    if (vacia()) {
        throw out_of_range("Lista Vacia");
    }
    if (primero == ultimo) {
        delete primero;
        primero = ultimo = nullptr;
    }
    else {
        Nodo<T> *temp = ultimo;
        temp->ant->sig = nullptr;
        ultimo = temp->ant;
        delete temp;
    }
    size--;
}

template<class T>
void ListaDoble<T>::eliminar(int posicion)
{
    if (vacia()) {
        throw out_of_range("Lista Vacia");
    }
    if (posicion < 0 || posicion >= size) {
        throw out_of_range("Posicion no valida");
    }

    if (posicion == 0) {
        eliminar_inicio();
    }
    else if (posicion == size - 1) {
        eliminar_final();
    }
    else {
        Nodo<T> *temp = primero;
        int contador = 0;

        while (temp != nullptr) {
            if (contador++ == posicion) {
                temp->ant->sig = temp->sig;
                temp->sig->ant = temp->ant;
                delete temp;
                size--;
            }
            temp = temp->sig;
        }
    }
}

template<class T>
T &ListaDoble<T>::operator[](int posicion) const
{
    if (posicion < 0 || posicion >= size) {
        throw out_of_range("Posicion no valida");
    }

    Nodo<T> *temp = primero;
    unsigned int contador = 0;

    while (temp != nullptr) {
        if (contador++ == posicion) {
            return temp->dato;
        }
        temp = temp->sig;
    }
}

#endif // LISTADOBLE_H
