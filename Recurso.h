//
// Created by michel on 5/25/18.
//

#ifndef SSEDI_18A_RECURSO_H
#define SSEDI_18A_RECURSO_H

#include <iostream>
#include <iomanip>

using namespace std;

enum class RecursoTipo {ORO, MADERA, PIEDRA, COMIDA};

class Recurso {

private:
    string id;
    size_t cantidad;
    RecursoTipo tipo;

public:

    Recurso();

    const string &getId() const;

    void setId(const string &id);

    size_t getCantidad() const;

    void setCantidad(size_t cantidad);

    RecursoTipo getTipo() const;

    void setTipo(RecursoTipo tipo);

    void setTipo(int tipo);


    bool operator<(const Recurso &recurso)
    {
        return cantidad < recurso.cantidad;
    }

    friend ostream& operator <<(ostream &o, const Recurso &g)
    {
        o << setw(5) << g.getId() <<
          setw(10) << g.getCantidad();

        o <<  setw(10) << right;
        RecursoTipo tipo = g.getTipo();
        
        if (tipo == RecursoTipo::ORO) {
            o <<  "Oro";
        }
        else if (tipo == RecursoTipo::MADERA) {
            o << "Madera";
        }
        else if (tipo == RecursoTipo::PIEDRA) {
            o << "Piedra";
        }
        else if (tipo == RecursoTipo::COMIDA) {
            o << "Comida";
        }

        return o;
    }

};


#endif //SSEDI_18A_RECURSO_H
