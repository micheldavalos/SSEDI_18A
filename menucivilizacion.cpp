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
        cout << "Aldeanos:     " << civilizaciones[i]->poblacion() << endl;
        cout << "Guerreros:    " << civilizaciones[i]->poblacionGuerreros() << endl << endl;
    }
}

void MenuCivilizacion::buscar()
{
    string nombre;
    cout << "Nombre de la Civilizacion: ";
    getline(cin, nombre);

    for (int i = 0; i < civilizaciones.tamano(); ++i) {
        if (civilizaciones[i]->getNombre() == nombre) {
            string op;

            do {
                cout << "1) Aldeanos" << endl
                     << "2) Guerreros" << endl
                     << "3) Recursos" << endl
                     << "0) Salir" << endl;

                getline(cin, op);

                if (op == "1") {
                    MenuAldeanos m(civilizaciones[i]);
                }
                else if (op == "2"){
                    MenuGuerreros m(civilizaciones[i]);
                }
                else if (op == "3") {
                    MenuRecurso m(civilizaciones[i]);
                }

            } while (op != "0");

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
            ifstream aldeanos(civilizaciones[i]->getNombre() + "_aldeanos.txt", ios::in);
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

            ifstream guerreros(civilizaciones[i]->getNombre() + "_guerreros.txt", ios::in);
            if (guerreros.is_open()) {
                string linea;
                Guerrero guerrero;

                while (!guerreros.eof()) {
                    getline(guerreros, linea);
                    if (guerreros.eof()) {
                        break;
                    }
                    guerrero.setId(linea);

                    getline(guerreros, linea);
                    guerrero.setSalud(stoi(linea));

                    getline(guerreros, linea);
                    guerrero.setFuerza(stof(linea));

                    getline(guerreros, linea);
                    guerrero.setEscudo(stof(linea));

                    getline(guerreros, linea);
                    guerrero.setGuerrero(linea);

                    civilizaciones[i]->agregarGuerrero(guerrero);
                }
            }
            guerreros.close();
        }
    }
    archivo.close();

}

void MenuCivilizacion::respaldar()
{
    ofstream archivo("civilizaciones.txt", ios::out);

    if (archivo.is_open()) {
        for (int i = 0; i < civilizaciones.tamano(); i++) {
            archivo << civilizaciones[i]->getNombre() << endl;

            ofstream aldeanos(civilizaciones[i]->getNombre() + "_aldeanos.txt", ios::out);
            if (aldeanos.is_open()) {

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
            }
            aldeanos.close();

            ofstream guerreros(civilizaciones[i]->getNombre() + "_guerreros.txt", ios::out);
            if (guerreros.is_open()) {
                for (int j = 0; j < civilizaciones[i]->poblacionGuerreros(); ++j) {
                    Guerrero &guerrero = civilizaciones[i]->getGuerrero(j);
                    guerreros << guerrero.getId() << endl;
                    guerreros << guerrero.getSalud() << endl;
                    guerreros << guerrero.getFuerza() << endl;
                    guerreros << guerrero.getEscudo() << endl;
                    guerreros << guerrero.getGuerrero() << endl;
                }
            }
            guerreros.close();
        }
    }
    archivo.close();
}
