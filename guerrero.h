#ifndef GUERRERO_H
#define GUERRERO_H

#include <iostream>
using namespace std;

enum GuerreroTipo {LANCERO, ARQUERO, PALADIN, GUERRERO_JAGUAR};

class Guerrero
{
    string id;
    float salud;
    float fuerza;
    float escudo;
    GuerreroTipo guerrero;

public:
    Guerrero();
    string getId() const;
    void setId(const string &value);
    float getSalud() const;
    void setSalud(float value);
    float getFuerza() const;
    void setFuerza(float value);
    float getEscudo() const;
    void setEscudo(float value);
    GuerreroTipo getGuerrero() const;
    void setGuerrero(const GuerreroTipo &value);
};

#endif // GUERRERO_H
