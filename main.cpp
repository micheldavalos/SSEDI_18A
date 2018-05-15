#include <iostream>
#include "menucivilizacion.h"
using namespace std;

int main()
{

    MenuCivilizacion m;
    string op;

    while (true) {
        cout << "Civilizaciones" << endl;
        cout << "1) Agregar civilizacion" << endl;
        cout << "2) Buscar Civilizacion" << endl;
        cout << "3) Eliminar civilizacion" << endl;
        cout << "4) Mostrar Civilizaciones" << endl;
        cout << "5) Respaldar" << endl;
        cout << "6) Recuperar" << endl;
        cout << "0) Salir" << endl;

        getline(cin, op);

        if (op == "1") {
            m.agregarCivilizacion();
        }
        else if (op == "2") {
            m.buscar();
        }
        else if (op == "3") {
            m.eliminar();
        }
        else if (op == "4") {
            m.mostrar();
        }
        else if (op == "5") {
            m.respaldar();
        }
        else if (op == "6") {
            m.recuperar();
        }
        else if (op == "0") {
            break;
        }

    }

    return 0;
}
