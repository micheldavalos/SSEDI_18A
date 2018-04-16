#include "menucivilizacion.h"

MenuCivilizacion::MenuCivilizacion()
{

}

void MenuCivilizacion::agregarCivilizacion()
{
    string nombre;
    Civilizacion *c = new Civilizacion;

    cout << "Nombre de la civilizacion: ";
    getline(cin, nombre);

    c->setNombre(nombre);

    civilizaciones.inserar_inicio(c);
}

void MenuCivilizacion::mostrar()
{
    for (int i = 0; i < civilizaciones.tamano(); ++i) {
        cout << "Civilizacion: " << civilizaciones[i]->getNombre() << endl;
        cout << "Poblacion:    " << civilizaciones[i]->poblacion() << endl << endl;
    }
}

void MenuCivilizacion::buscar()
{
    string nombre;
    cout << "Nombre de la Civilizacion: ";
    getline(cin, nombre);

    for (int i = 0; i < civilizaciones.tamano(); ++i) {
        if (civilizaciones[i]->getNombre() == nombre) {
            MenuAldeanos m(civilizaciones[i]);
            break;
        }
    }
}

void MenuCivilizacion::eliminar()
{
    string nombre;

    cout << "Nombre de la Civilizacion: ";
    getline(cin, nombre);

    for (int i = 0; i < civilizaciones.tamano(); ++i) {
        if (civilizaciones[i]->getNombre() == nombre) {
            civilizaciones.eliminar(i);
        }
    }
}
