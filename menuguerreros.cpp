#include "menuguerreros.h"
#include <iomanip>

MenuGuerreros::MenuGuerreros(Civilizacion *&civilizacion)
{
    string op;

    while (true) {
        cout << "1) Agregar Guerrero" << endl;
        cout << "2) Mostrar Guereros" << endl;
        cout << "3) Buscar Guerreros" << endl;
        cout << "4) Eliminar Guerreros" << endl;
        cout << "0) Salir" << endl;
        getline(cin, op);

        if (op == "1") {
            agregarGuerrero(civilizacion);
        }
        else if (op == "2") {
            mostrarGuerreros(civilizacion);
        }
        else if (op == "3") {
            buscar(civilizacion);
        }
        else if (op == "4") {
            eliminar(civilizacion);
        }
        else {
            break;
        }

    }
}

void MenuGuerreros::agregarGuerrero(Civilizacion *&civilizacion)
{
    Guerrero g;
    string temp;
    int temp_int;
    float temp_float;

    // ID
    cout << "ID: ";
    getline(cin, temp);
    g.setId(temp);

    // Salud
    capturar("Salud", 0, 100, temp_int);
    g.setSalud(temp_int);

    // Fuerza
    capturar("Fuerza", 0.0, 60.0, temp_float);
    g.setFuerza(temp_float);

    // Escudo
    capturar("Escudo", 0.0, 30.0, temp_float);
    g.setEscudo(temp_float);

    // Tipo
    string msg = "Tipo de Guerrero \n "
                 "1) Lancero" "\n "
                 "2) Arquero" "\n "
                 "3) Paladín" "\n "
                 "4) Guerrero Jaguar" "\n"
                 "(1 - 4): ";
    GuerreroTipo tipo;
    capturar(msg, 1, 4, tipo);
    g.setGuerrero(tipo);

    civilizacion->agregarGuerrero(g);
}

void MenuGuerreros::mostrarGuerreros(Civilizacion *&civilizacion)
{
    cout << setw(5) << "ID|" <<
            setw(10) << "Salud|" <<
            setw(10) << "Fuerza|" <<
            setw(10) << "Escudo|" <<
            setw(20) << "Tipo|" << endl;
    for (int i = 0; i < civilizacion->poblacionGuerreros(); ++i) {
        cout << civilizacion->getGuerrero(i);
        cout << endl;
    }
}

void MenuGuerreros::buscar(Civilizacion *&civilizacion)
{
    string op;

    while (true) {
        cout << "1) Salud >=" << endl;
        cout << "2) Salud <" << endl;
        cout << "3) Fuerza >=" << endl;
        cout << "4) Fuerza <" << endl;
        cout << "5) Clase" << endl;
        cout << "0) Salir" << endl;
        getline(cin, op);

        if (op == "1") {
            buscarSalud(civilizacion);
        }
        else if (op == "2") {
            buscarSalud(civilizacion, 1);
        }
        else if (op == "3") {
            buscarFuerza(civilizacion);
        }
        else if (op == "4") {
            buscarFuerza(civilizacion, 1);
        }
        else if (op == "5") {
            buscarClase(civilizacion);
        }
        else if (op == "0") {
            break;
        }
    }
}

void MenuGuerreros::eliminar(Civilizacion *&civilizacion)
{
    string op;

    while (true) {
        cout << "1) ID" << endl;
        cout << "2) Tipo" << endl;
        cout << "3) Salud <" << endl;
        cout << "0) Salir" << endl;
        getline(cin, op);

        if (op == "1") {

        }
        else if (op == "2") {

        }
        else if (op == "3") {

        }
        else if (op == "0") {
            break;
        }
    }
}

void MenuGuerreros::capturar(const string &mensaje, float min, float max, float &valor)
{
    string temp;
    bool flag = false;
    do {
        cout << fixed << setprecision(2) << mensaje << " " << min << " - " << max << ": ";
        getline(cin, temp);
        try {
            valor = stof(temp);
            valor >= min && valor <= max ? flag = false : flag = true;

            if (flag) {
                cout << "Valores no validos" << endl;
            }

        } catch (...) {
            flag = true;
            cout << "Ocurrio un error" << endl;
        }
    } while (flag);
}

void MenuGuerreros::capturar(const string &mensaje, int min, int max, GuerreroTipo &valor)
{
    string temp;
    int temp_int;
    bool flag = false;
    do {
        cout << mensaje;
        getline(cin, temp);
        try {
            temp_int = stoi(temp);
            temp_int >= min && temp_int <= max ? flag = false : flag = true;

            if (flag) {
                cout << "Valores no validos" << endl;
            }
            else {
                if (temp_int == 1) {
                    valor = GuerreroTipo::LANCERO;
                }
                else if (temp_int == 2) {
                    valor = GuerreroTipo::ARQUERO;
                }
                else if (temp_int == 3) {
                    valor = GuerreroTipo::PALADIN;
                }
                else if (temp_int == 4) {
                    valor = GuerreroTipo::GUERRERO_JAGUAR;
                }
            }

        } catch (...) {
            flag = true;
            cout << "Ocurrio un error" << endl;
        }
    } while (flag);
}

void MenuGuerreros::buscarSalud(Civilizacion *&civilizacion, int tipo)
{
    int valor;
    Civilizacion *c = new Civilizacion;

    capturar("Ingresa el valor", 0, 100, valor);

    for (unsigned int i = 0; i < civilizacion->poblacionGuerreros(); ++i) {

        if (tipo == 0 && civilizacion->getGuerrero(i).getSalud() >= valor) {
            c->agregarGuerrero(civilizacion->getGuerrero(i));
        }
        else if (tipo == 1 && civilizacion->getGuerrero(i).getSalud() < valor) {
            c->agregarGuerrero(civilizacion->getGuerrero(i));
        }
    }

    mostrarGuerreros(c);

    delete c;
}

void MenuGuerreros::buscarFuerza(Civilizacion *&civilizacion, int tipo)
{
    float valor;
    Civilizacion *c = new Civilizacion;

    capturar("Ingresa el valor", 0.0, 60.0, valor);

    for (unsigned int i = 0; i < civilizacion->poblacionGuerreros(); ++i) {

        if (tipo == 0 && civilizacion->getGuerrero(i).getFuerza() >= valor) {
            c->agregarGuerrero(civilizacion->getGuerrero(i));
        }
        else if (tipo == 1 && civilizacion->getGuerrero(i).getFuerza() < valor) {
            c->agregarGuerrero(civilizacion->getGuerrero(i));
        }
    }

    mostrarGuerreros(c);

    delete c;
}

void MenuGuerreros::buscarClase(Civilizacion *&civilizacion)
{
    Civilizacion *c = new Civilizacion;
    // Tipo
    string msg = "Tipo de Guerrero \n "
                 "1) Lancero" "\n "
                 "2) Arquero" "\n "
                 "3) Paladín" "\n "
                 "4) Guerrero Jaguar" "\n"
                 "(1 - 4): ";
    GuerreroTipo valor;
    capturar(msg, 1, 4, valor);

    for (unsigned int i = 0; i < civilizacion->poblacionGuerreros(); ++i) {
        if (civilizacion->getGuerrero(i).getGuerreroTipo() == valor) {
            c->agregarGuerrero(civilizacion->getGuerrero(i));
        }

    }

    mostrarGuerreros(c);

    delete c;
}


void MenuGuerreros::capturar(const string &mensaje, int min, int max, int &valor)
{
    string temp;
    bool flag = false;
    do {
        cout << mensaje << " " << min << " - " << max << ": ";
        getline(cin, temp);
        try {
            valor = stoi(temp);
            valor >= min && valor <= max ? flag = false : flag = true;

            if (flag) {
                cout << "Valores no validos" << endl;
            }

        } catch (...) {
            flag = true;
            cout << "Ocurrio un error" << endl;
        }
    } while (flag);
}
