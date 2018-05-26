//
// Created by michel on 5/25/18.
//

#include "Recurso.h"

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

TipoRecurso Recurso::getTipo() const {
    return tipo;
}

void Recurso::setTipo(TipoRecurso tipo) {
    Recurso::tipo = tipo;
}

void Recurso::setTipo(int tipo)
{
    if (tipo == 1) {
        Recurso::tipo = TipoRecurso::ORO;
    }
    else if (tipo == 2) {
        Recurso::tipo = TipoRecurso::MADERA;
    }
    else if (tipo == 3) {
        Recurso::tipo = TipoRecurso::PIEDRA;
    }
    else if (tipo == 4) {
        Recurso::tipo = TipoRecurso::COMIDA;
    }
}
