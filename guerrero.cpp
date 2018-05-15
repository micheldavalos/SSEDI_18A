#include "guerrero.h"

string Guerrero::getId() const
{
    return id;
}

void Guerrero::setId(const string &value)
{
    id = value;
}

int Guerrero::getSalud() const
{
    return salud;
}

void Guerrero::setSalud(int value)
{
    salud = value;
}

float Guerrero::getFuerza() const
{
    return fuerza;
}

void Guerrero::setFuerza(float value)
{
    fuerza = value;
}

float Guerrero::getEscudo() const
{
    return escudo;
}

void Guerrero::setEscudo(float value)
{
    escudo = value;
}

GuerreroTipo Guerrero::getGuerrero() const
{
    return guerrero;
}

void Guerrero::setGuerrero(const GuerreroTipo &value)
{
    guerrero = value;
}

void Guerrero::setGuerrero(const string &tipo)
{
    if (tipo == "Lancero") {
        guerrero = GuerreroTipo::LANCERO;
    }
    else if (tipo == "Arquero" ) {
        guerrero = GuerreroTipo::ARQUERO;
    }
    else if (tipo == "Paladín") {
        guerrero = GuerreroTipo::PALADIN;
    }
    else if (tipo == "Guerrero Jaguar") {
        guerrero = GuerreroTipo::GUERRERO_JAGUAR;
    }
}

string Guerrero::getGuerrero()
{
    GuerreroTipo tipo = guerrero;
    string o;
    if (tipo == GuerreroTipo::LANCERO) {
        o =  "Lancero";
    }
    else if (tipo == GuerreroTipo::ARQUERO) {
        o = "Arquero";
    }
    else if (tipo == GuerreroTipo::PALADIN) {
        o = "Paladín";
    }
    else if (tipo == GuerreroTipo::GUERRERO_JAGUAR) {
        o = "Guerrero Jaguar";
    }

    return o;
}

Guerrero::Guerrero()
{

}
