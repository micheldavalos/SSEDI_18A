#ifndef LISTA_H
#define LISTA_H

#include <iostream>
#include <stdexcept>
using namespace std;

template <class T>
class Nodo2
{
    T dato;
    Nodo2<T> *sig;

public:
    Nodo2(const T &d, Nodo2<T> *s = nullptr)
    {
        dato = d;
        sig = s;
    }

    template <class>
    friend class Lista;
};

template <class T>
class Lista
{
    Nodo2<T> *raiz;

public:
    Lista();
    ~Lista();
    void inserar_inicio(const T &d);
    void insertar_final(const T &d);
    void insertar(const T &d, int posicion);

    void eliminar_inicio();
    void eliminar_final();
    void eliminar(int posicion);

    int tamano();

    T &operator[](int posicion);


    string to_string();

};
template <class T>
Lista<T>::Lista()
{
    raiz = nullptr;
}

template<class T>
Lista<T>::~Lista()
{
    Nodo2<T> *temp = raiz;

    while (temp != nullptr) {
        raiz = temp->sig; // raiz->sig
        delete temp;
        temp = raiz;
    }
}

template<class T>
void Lista<T>::inserar_inicio(const T &d)
{
    if (raiz == nullptr) {
        Nodo2<T> *nuevo = new Nodo2<T>(d);
        raiz = nuevo;
    }
    else {
        Nodo2<T> *nuevo = new Nodo2<T>(d);
        nuevo->sig = raiz;
        raiz = nuevo;
    }
}

template<class T>
void Lista<T>::insertar_final(const T &d)
{
    if (raiz == nullptr) {
        Nodo2<T> *nuevo = new Nodo2<T>(d);
        raiz = nuevo;
    }
    else {
        Nodo2<T> *temp = raiz;

        while (temp->sig != nullptr) {
            temp = temp->sig;
        }
        Nodo2<T> *nuevo = new Nodo2<T>(d);
        temp->sig = nuevo;
    }
}

template<class T>
void Lista<T>::insertar(const T &d, int posicion)
{
    if (posicion < 0 || raiz == nullptr) {
// lanzar excepcion
    }
    else {
        int i = 0;
        bool flag = false;
        Nodo2<T> *temp = raiz;

        while (temp != nullptr) {
            if (posicion == i) {
                Nodo2<T> *nuevo = new Nodo2<T>(d);

                nuevo->sig = temp->sig;
                temp->sig = nuevo;
                flag = true;
                break;
            }
            i++;
            temp = temp->sig;
        }
        if (!flag) {
            // la posicion no existe
        }
    }
}

template<class T>
void Lista<T>::eliminar_inicio()
{
    if (raiz == nullptr) {
        throw out_of_range("Lista Vacia");
    }
    else {
        Nodo2<T> *temp = raiz;
        raiz = raiz->sig;
        delete temp;
    }
}

template<class T>
void Lista<T>::eliminar_final()
{
    if (raiz == nullptr) {
        throw out_of_range("Lista Vacia");
    }
    else if (raiz->sig == nullptr) {
        eliminar_inicio();
    }
    else {
        Nodo2<T> *temp = raiz;

        while (temp->sig->sig != nullptr) {
            temp = temp->sig;
        }

        delete temp->sig;
        temp->sig = nullptr;
//        Nodo2<T> **temp = &raiz;

//        while ((*temp)->sig != nullptr) {
//            temp = &(*temp)->sig;
//        }

//        delete (*temp)->sig;
//        (*temp) = nullptr;
    }
}

template<class T>
void Lista<T>::eliminar(int posicion)
{
    if (raiz == nullptr || posicion >= tamano()) {
        throw out_of_range("Lista Vacia");
    }
    else if (posicion == 0) {
        eliminar_inicio();
    }
    else if (posicion == tamano() - 1) {
        eliminar_final();
    }
    else {
        Nodo2<T> *temp = raiz;
        int cont = 0;

        while (temp != nullptr) {
            if (cont++ == posicion - 1) {
                Nodo2<T> *t = temp->sig;
                temp->sig = temp->sig->sig;
                delete t;
                break;
            }
            temp = temp->sig;
        }
    }
}

template<class T>
int Lista<T>::tamano()
{
    Nodo2<T> *temp = raiz;
    int cont = 0;

    while (temp != nullptr) {
        cont++;
        temp = temp->sig;
    }

    return cont;
}

template<class T>
T &Lista<T>::operator[](int posicion)
{
    if (posicion < 0 || posicion >= tamano()) {
        throw out_of_range("Posicion no valida");
    }
    else {
        Nodo2<T> *temp = raiz;
        int cont = 0;

        while (temp != nullptr) {
            if (cont == posicion) {
                return temp->dato;
            }
            temp = temp->sig;
            cont++;
        }
    }
}

template<class T>
string Lista<T>::to_string()
{
    string lista = "[ ";
    Nodo2<T> *temp = raiz;

    while (temp != nullptr) {
        lista += temp->dato;
        temp = temp->sig; // el salto
        lista += ", ";
    }

    lista += " ]";

    return lista;
}
#endif // LISTA_H
