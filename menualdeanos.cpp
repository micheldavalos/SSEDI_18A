#include "menualdeanos.h"
#include <sstream>

MenuAldeanos::MenuAldeanos(Civilizacion *&civilizacion)
{
//    Civilizacion c;
    c = civilizacion;
    string op;

    while (true) {
        cout << "1) Nombre de la Civilizacion" << endl;
        cout << "2) Agregar Aldeano" << endl;
        cout << "3) Eliminar Aldeano" << endl;
        cout << "4) Resumen" << endl;
        cout << "0) Salir" << endl;
        getline(cin, op);

        if (op == "1") {
            nombreCivilizacion(c);
        }
        else if (op == "2") {
            agregarAldeano(c);
        }
        else if (op == "3") {
            eliminarAldeano(c);
        }
        else if (op == "4") {
            resumen(c);
        }
        else if (op == "0") {
            break;
        }
        else {
            cout << "Opcion no válida" << endl;
        }
    }

}

void MenuAldeanos::nombreCivilizacion(Civilizacion *&civilizacion)
{
    string nombre;

    cout << "Nombre para la civilizacion: ";
    getline(cin, nombre);

    civilizacion->setNombre(nombre);
}

void MenuAldeanos::agregarAldeano(Civilizacion *&civilizacion)
{
    Aldeano aldeano;
    string nombre;
    char genero;
    int edad;
    int salud;
    stringstream ss;

    cout << "Nombre del Aldeano: ";
    getline(cin, nombre);
    aldeano.setNombre(nombre);

    cout << "Edad del Aldeano:   ";
    getline(cin, nombre);
    ss << nombre;
    ss >> edad;
    ss.clear();
    aldeano.setEdad(edad);

    cout << "Género del Aldeano: ";
    getline(cin, nombre);
    ss << nombre;
    ss >> genero;
    ss.clear();
    aldeano.setGenero(genero);

    cout << "Salud del Aldeano:  ";
    getline(cin, nombre);
    ss << nombre;
    ss >> salud;
    aldeano.setSalud(salud);

    civilizacion->agregarAldeano(aldeano);
}

void MenuAldeanos::eliminarAldeano(Civilizacion *&civilizacion)
{
    string nombre;

    cout << "Nombre del Aldeano: ";
    getline(cin, nombre);

    if (civilizacion->eliminarAldeano(nombre)) {
        cout << "Se eliminó al Aldeano " << nombre << endl;
    }
    else {
        cout << "No existe el Aldeano " << nombre << endl;
    }

}

void MenuAldeanos::resumen(Civilizacion *&civilizacion)
{
    cout << "Civilizacion: " << civilizacion->getNombre() << endl;
    cout << "Poblacion:    " << civilizacion->poblacion() << " aldeanos" << endl;

    for (int i = 0; i < civilizacion->poblacion(); ++i) {
        const Aldeano &aldeano = (*civilizacion)[i];
        cout << "Aldeano " << i << " :" << endl;
        cout << "\t" << "Nombre: " << aldeano.getNombre() << endl;
        cout << "\t" << "Edad:   " << aldeano.getEdad() << endl;
        cout << "\t" << "Género: " << aldeano.getGenero() << endl;
        cout << "\t" << "Salud:  " << aldeano.getSalud() << endl;
        cout << endl;
    }

}
