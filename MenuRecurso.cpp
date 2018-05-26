//
// Created by michel on 5/26/18.
//

#include "MenuRecurso.h"

MenuRecurso::MenuRecurso()
{
    string op;

    while (true) {
        cout << "1) Agregar Recurso" << endl;
        cout << "2) Mostrar Recursos" << endl;
        cout << "3) Buscar Recurso" << endl;
        cout << "4) Modificar Recurso" << endl;
        cout << "0) Salir" << endl;
        getline(cin, op);

        if (op == "1") {
        }
        else if (op == "2") {
        }
        else if (op == "3") {
        }
        else if (op == "4") {
        }
        else {
            break;
        }

    }
}

void MenuRecurso::agregarRecurso(Civilizacion *&civilizacion)
{
    Recurso recurso;
    string temp;
    int cantidad;
    int tipo;

    // Id
    cout << "ID: ";
    getline(cin, temp);
    recurso.setId(temp);


    // Catidad
    Captura::capturar("Cantidad", 0, 500, cantidad);
    recurso.setCantidad(cantidad);

    // Tipo
    string msg = "Tipo de Recurso \n "
                 "1) Oro" "\n "
                 "2) Madera" "\n "
                 "3) Piedra" "\n "
                 "4) Comida "\n"
                 "(1 - 4): ";
    Captura::capturar(msg, 1, 4, tipo);




}

void MenuRecurso::mostrarRecurso(Civilizacion *&civlizacion)
{
    cout << setw(5) << "ID|" <<
         setw(10) << "Catidad|" <<
         setw(10) << "Tipo|";
//    for (int i = 0; i < civlizacion.; ++i) {
//        cout << civilizacion->getGuerrero(i);
//        cout << endl;
//    }
}
