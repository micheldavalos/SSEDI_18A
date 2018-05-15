#include "menuguerreros.h"

MenuGuerreros::MenuGuerreros(Civilizacion *&civilizacion)
{
    string op;

    while (true) {
        cout << "1) Agregar Guerrero" << endl;

        getline(cin, op);

        if (op == "1") {
            agregarGuerrero(civilizacion);
        }

    }
}

void MenuGuerreros::agregarGuerrero(Civilizacion *&civilizacion)
{
    Guerrero g;
    string temp;
    int temp_int;
    float temp_float;
    bool flag = false;

    cout << "ID: ";
    getline(cin, temp);
    g.setId(temp);

    do {
        cout << "Salud (0 - 100): ";
        getline(cin, temp);
        try {
            temp_int = stoi(temp);
            temp_int >= 0 && temp_int <= 100 ? flag = false : flag = true;

            if (flag) {
                cout << "Valores no validos" << endl;
            }
        } catch (...) {
            flag = true;
            cout << "Ocurrio un error" << endl;
        }
    } while (flag);


}
