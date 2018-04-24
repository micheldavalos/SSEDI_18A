#include "menucivilizacion.h"
#include <fstream>

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

void MenuCivilizacion::recuperar()
{
    ifstream archivo("civilizaciones.txt", ios::in);

    if (archivo.is_open()) {
        while (!archivo.eof()) {
            string linea;

            getline(archivo, linea);
            if (archivo.eof()) {
                break;
            }

            Civilizacion *civ = new Civilizacion();
            civ->setNombre(linea);

            civilizaciones.inserar_inicio(civ);
        }

        for (int i = 0; i < civilizaciones.tamano(); ++i) {
            ifstream aldeanos(civilizaciones[i]->getNombre() + ".txt", ios::in);

            if (aldeanos.is_open()) {
                string linea;
                Aldeano aldeano;

                while (!aldeanos.eof()) {
                    getline(aldeanos, linea);
                    if (aldeanos.eof()) {
                        break;
                    }
                    aldeano.setNombre(linea);

                    getline(aldeanos, linea);
                    aldeano.setEdad(stoi(linea));

                    getline(aldeanos, linea);
                    aldeano.setGenero(linea[0]);

                    getline(aldeanos, linea);
                    aldeano.setSalud(stoi(linea));

                    civilizaciones[i]->agregarAldeano(aldeano);
                }

            }
            aldeanos.close();
        }
    }
    archivo.close();

}

void MenuCivilizacion::respaldar()
{
    ofstream archivo("civilizaciones.txt", ios::out);

     for (int i = 0; i < civilizaciones.tamano(); i++) {
      archivo << civilizaciones[i]->getNombre() << endl;
      ofstream aldeanos(civilizaciones[i]->getNombre() + ".txt", ios::out);
      for (int j = 0; j < civilizaciones[i]->poblacion(); j++) {
       // obtengo el puntero de civilizacion
       Civilizacion *c = civilizaciones[i];
       // salto a la civilizacion y obtengo la referencia (no hace copia)
       // del aldeano "j"
       Aldeano &aldeano = (*c)[j];
       aldeanos << aldeano.getNombre() << endl;
       aldeanos << aldeano.getEdad()   << endl;
       aldeanos << aldeano.getGenero() << endl;
       aldeanos << aldeano.getSalud()  << endl;
      }
      aldeanos.close();
     }
     archivo.close();
}
