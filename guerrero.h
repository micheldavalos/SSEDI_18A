#ifndef GUERRERO_H
#define GUERRERO_H

#include <iostream>
#include <iomanip>
using namespace std;

enum class GuerreroTipo {LANCERO = 1,
                         ARQUERO,
                         PALADIN,
                         GUERRERO_JAGUAR};

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

    friend ostream& operator <<(ostream &o, const Guerrero &g)
    {
        o << setw(5) << g.getId() <<
             setw(10) << g.getSalud() <<
             setw(10) << g.getSalud() <<
             setw(10) << g.getEscudo();

        GuerreroTipo tipo = g.getGuerrero();
        if (tipo == GuerreroTipo::LANCERO) {
            o <<  setw(10)  << "Lancero";
        }
        else if (tipo == GuerreroTipo::ARQUERO) {
            o << setw(10) << "Arquero";
        }
        else if (tipo == GuerreroTipo::PALADIN) {
            o << setw(10) <<  "Paladín";
        }
        else if (tipo == GuerreroTipo::GUERRERO_JAGUAR) {
            o << setw(10) <<  "Guerrero Jaguar";
        }

        return o;
    }
};

#endif // GUERRERO_H
