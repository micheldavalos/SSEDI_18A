//
// Created by michel on 5/26/18.
//

#include "MenuRecurso.h"

MenuRecurso::MenuRecurso(Civilizacion *&civilizacion)
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
            agregarRecurso(civilizacion);
        }
        else if (op == "2") {
            mostrarRecurso(civilizacion);
        }
        else if (op == "3") {
            buscar(civilizacion);
        }
        else if (op == "4") {
            modificar(civilizacion);
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
                 "4) Comida " "\n";
    Captura::capturar(msg, 1, 4, tipo);
    recurso.setTipo(tipo);

    civilizacion->agregarRecurso(recurso);

}

void MenuRecurso::mostrarRecurso(Civilizacion *&civilizacion)
{
    cout << setw(5) << "ID|" <<
         setw(10) << "Cantidad|" <<
         setw(10) << "Tipo|" << endl;

    for (int i = 0; i < civilizacion->cantidadRecursos(); ++i) {
        cout << civilizacion->getRecurso(i);
        cout << endl;
    }
}

void MenuRecurso::buscarRecursoCantidad(Civilizacion *&civilizacion, int tipo)
{
    int valor;
    Civilizacion *c = new Civilizacion;

    Captura::capturar("Ingresa el valor", 0, 500, valor);

    for (unsigned int i = 0; i < civilizacion->cantidadRecursos(); ++i) {

        if (tipo == 0 && civilizacion->getRecurso(i).getCantidad() >= valor) {
            c->agregarRecurso(civilizacion->getRecurso(i));
        }
        else if (tipo == 1 && civilizacion->getRecurso(i).getCantidad() < valor) {
            c->agregarRecurso(civilizacion->getRecurso(i));
        }
    }

    mostrarRecurso(c);

    delete c;
}

void MenuRecurso::buscar(Civilizacion *&civilizacion)
{
    string op;

    while (true) {
        cout << "1) Catidad >=" << endl;
        cout << "2) Cantidad <" << endl;
        cout << "3) Tipo >=" << endl;
        cout << "0) Salir" << endl;

        getline(cin, op);

        if (op == "1") {
            buscarRecursoCantidad(civilizacion);
        }
        else if (op == "2") {
            buscarRecursoCantidad(civilizacion, 1);
        }
        else if (op == "3") {
            buscarRecursoTipo(civilizacion);
        }
        else if (op == "0") {
            break;
        }
    }
}

void MenuRecurso::buscarRecursoTipo(Civilizacion *&civilizacion)
{
    Civilizacion *c = new Civilizacion;
    int tipo;

    string msg = "Tipo de Recurso \n "
                 "1) Oro" "\n "
                 "2) Madera" "\n "
                 "3) Piedra" "\n "
                 "4) Comida " "\n";
    Captura::capturar(msg, 1, 4, tipo);

    for (unsigned int i = 0; i < civilizacion->cantidadRecursos(); ++i) {

        if (civilizacion->getRecurso(i).getTipo() == tipo) {
            c->agregarRecurso(civilizacion->getRecurso(i));
        }
    }

    mostrarRecurso(c);

    delete c;


}

void MenuRecurso::modificar(Civilizacion *&civilizacion)
{
    string id;

    cout << "ID del Guerrero: ";
    getline(cin, id);

    for (int i = 0; i < civilizacion->cantidadRecursos(); ++i) {
        Recurso &recurso = civilizacion->getRecurso(i);

        if (id == recurso.getId()) {
            string op;

            while (true) {
                cout << "1) Modificar Cantidad" << endl;
                cout << "0) Salir" << endl;
                getline(cin, op);

                if (op == "1") {
                    int temp_int;
                    Captura::capturar("Cantidad", 0, 500, temp_int);
                    recurso.setCantidad(temp_int);

                    if (temp_int == 0) {
                        civilizacion->eliminar(i);
                        i = civilizacion->cantidadRecursos();

                        cout << "Recurso eliminado" << endl;

                        break;
                    }

                }
                else if (op == "0") {
                    break;
                }
            }
        }
    }
}
