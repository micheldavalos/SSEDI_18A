#include "menuguerreros.h"
#include <iomanip>

MenuGuerreros::MenuGuerreros(Civilizacion *&civilizacion)
{
    string op;

    while (true) {
        cout << "1) Agregar Guerrero" << endl;
        cout << "0) Salir" << endl;
        getline(cin, op);

        if (op == "1") {
            agregarGuerrero(civilizacion);
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
