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
    int salud;
    float fuerza;
    float escudo;
    GuerreroTipo guerrero;

public:
    Guerrero();
    string getId() const;
    void setId(const string &value);
    int getSalud() const;
    void setSalud(int value);
    float getFuerza() const;
    void setFuerza(float value);
    float getEscudo() const;
    void setEscudo(float value);
    GuerreroTipo getGuerreroTipo() const;
    void setGuerrero(const GuerreroTipo &value);
    void setGuerrero(const string &tipo);
    string getGuerrero();

    friend ostream& operator <<(ostream &o, const Guerrero &g)
    {
        o << setw(5) << g.getId() <<
             setw(10) << g.getSalud() <<
             setw(10) << g.getSalud() <<
             setw(10) << g.getEscudo();

        o <<  setw(20) << right;
        GuerreroTipo tipo = g.getGuerreroTipo();
        if (tipo == GuerreroTipo::LANCERO) {
            o <<  "Lancero";
        }
        else if (tipo == GuerreroTipo::ARQUERO) {
            o << "Arquero";
        }
        else if (tipo == GuerreroTipo::PALADIN) {
            o << "Paladín";
        }
        else if (tipo == GuerreroTipo::GUERRERO_JAGUAR) {
            o << "Guerrero Jaguar";
        }



        return o;
    }

};

#endif // GUERRERO_H
