//
// Created by michel on 5/26/18.
//

#ifndef SSEDI_18A_MENURECURSO_H
#define SSEDI_18A_MENURECURSO_H

#include "civilizacion.h"
#include "Captura.h"

class MenuRecurso {

private:

    void buscarRecursoCantidad(Civilizacion *&civilizacion, int tipo = 0);

    void buscarRecursoTipo(Civilizacion *&civilizacion);

public:

    MenuRecurso(Civilizacion *&civilizacion);

    void agregarRecurso(Civilizacion* &civilizacion);

    void mostrarRecurso(Civilizacion *&civilizacion);

    void buscar(Civilizacion *&civilizacion);

    void modificar(Civilizacion *&civilizacion);
};


#endif //SSEDI_18A_MENURECURSO_H
