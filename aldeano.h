#ifndef ALDEANO_H
#define ALDEANO_H

#include <iostream>
using namespace std;

class Aldeano
{
private:
    string nombre;
    int edad;
    int salud;
    char genero;
public:
    Aldeano();
    string getNombre() const;
    void setNombre(const string &value);
    int getEdad() const;
    void setEdad(int value);
    int getSalud() const;
    void setSalud(int value);
    char getGenero() const;
    void setGenero(char value);
};

#endif // ALDEANO_H
