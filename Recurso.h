//
// Created by michel on 5/25/18.
//

#ifndef SSEDI_18A_RECURSO_H
#define SSEDI_18A_RECURSO_H

#include <iostream>
using namespace std;

enum class TipoRecurso {ORO, MADERA, PIEDRA, COMIDA};

class Recurso {

private:
    string id;
    size_t cantidad;
    TipoRecurso tipo;

public:

    Recurso();

    const string &getId() const;

    void setId(const string &id);

    size_t getCantidad() const;

    void setCantidad(size_t cantidad);

    TipoRecurso getTipo() const;

    void setTipo(TipoRecurso tipo);


};


#endif //SSEDI_18A_RECURSO_H
