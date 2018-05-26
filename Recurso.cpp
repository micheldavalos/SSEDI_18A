//
// Created by michel on 5/25/18.
//

#include "Recurso.h"
#include "civilizacion.h"

Recurso::Recurso()
{

}

const string &Recurso::getId() const {
    return id;
}

void Recurso::setId(const string &id) {
    Recurso::id = id;
}

size_t Recurso::getCantidad() const {
    return cantidad;
}

void Recurso::setCantidad(size_t cantidad) {
    Recurso::cantidad = cantidad;
}

RecursoTipo Recurso::getTipo() const {
    return tipo;
}

void Recurso::setTipo(RecursoTipo tipo) {
    Recurso::tipo = tipo;
}

void Recurso::setTipo(int tipo)
{
    if (tipo == 1) {
        Recurso::tipo = RecursoTipo::ORO;
    }
    else if (tipo == 2) {
        Recurso::tipo = RecursoTipo::MADERA;
    }
    else if (tipo == 3) {
        Recurso::tipo = RecursoTipo::PIEDRA;
    }
    else if (tipo == 4) {
        Recurso::tipo = RecursoTipo::COMIDA;
    }
}

string Recurso::getTipoString()
{
    string o;
    RecursoTipo tipo = Recurso::tipo;

    if (tipo == RecursoTipo::ORO) {
        o =  "Oro";
    }
    else if (tipo == RecursoTipo::MADERA) {
        o = "Madera";
    }
    else if (tipo == RecursoTipo::PIEDRA) {
        o = "Piedra";
    }
    else if (tipo == RecursoTipo::COMIDA) {
        o = "Comida";
    }

    return o;
}

void Recurso::setTipo(const string tipo)
{
    if (tipo == "Oro") {
        Recurso::tipo = RecursoTipo::ORO;
    }
    else if (tipo == "Madera") {
        Recurso::tipo = RecursoTipo::MADERA;
    }
    else if (tipo == "Piedra") {
        Recurso::tipo = RecursoTipo::PIEDRA;
    }
    else if (tipo == "Comida") {
        Recurso::tipo = RecursoTipo::COMIDA;
    }
}
