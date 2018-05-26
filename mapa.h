#ifndef MAPA_H
#define MAPA_H


#include <vector>
using namespace std;

template <class T>
class Mapa
{
    vector< vector<T> > *matriz;
    int _filas;
    int _columnas;

public:
    Mapa();
    Mapa(int filas, int columnas);
    Mapa(int filas, int columnas, const T &dato);
    ~Mapa();

    vector<T> &operator[](int posicion);

    vector< vector<T> > &getMatriz();

    int sizeFila();
    int sizeColumna();
};
template <class T>
Mapa<T>::Mapa()
{
    matriz = new vector< vector<T> >(5, vector<T>(5, T()));
    _filas = _columnas = 5;
}

template<class T>
Mapa<T>::Mapa(int filas, int columnas)
{
    matriz = new vector< vector<T> >(filas, vector<T>(columnas, T()));
    _filas = filas;
    _columnas = columnas;
}

template<class T>
Mapa<T>::Mapa(int filas, int columnas, const T &dato)
{
    matriz = new vector< vector<T> >(filas, vector<T>(columnas, dato));
    _filas = filas;
    _columnas = columnas;
}

template<class T>
Mapa<T>::~Mapa()
{
    delete matriz;
}

template<class T>
vector<T> &Mapa<T>::operator[](int posicion)
{
    if (posicion > _filas) {
        throw out_of_range("Posición no válida");
    }

    return (*matriz)[posicion];
}

template<class T>
vector<vector<T> > &Mapa<T>::getMatriz()
{
    return *matriz;
}

template<class T>
int Mapa<T>::sizeFila() {
    return _filas;
}

template<class T>
int Mapa<T>::sizeColumna() {
    return _columnas;
}

#endif // MAPA_H
