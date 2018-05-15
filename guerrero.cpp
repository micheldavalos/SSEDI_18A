#include "guerrero.h"

string Guerrero::getId() const
{
    return id;
}

void Guerrero::setId(const string &value)
{
    id = value;
}

float Guerrero::getSalud() const
{
    return salud;
}

void Guerrero::setSalud(float value)
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

Guerrero::Guerrero()
{

}
