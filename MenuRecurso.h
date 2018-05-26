//
// Created by michel on 5/26/18.
//

#ifndef SSEDI_18A_MENURECURSO_H
#define SSEDI_18A_MENURECURSO_H

#include "civilizacion.h"
#include "Captura.h"

class MenuRecurso {

public:
    MenuRecurso(Civilizacion *&civilizacion);

    void agregarRecurso(Civilizacion* &civilizacion);

    void mostrarRecurso(Civilizacion *&civilizacion);
};


#endif //SSEDI_18A_MENURECURSO_H
