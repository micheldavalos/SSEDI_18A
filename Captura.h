//
// Created by michel on 5/26/18.
//

#ifndef SSEDI_18A_CAPTURA_H
#define SSEDI_18A_CAPTURA_H

#include <iostream>
using namespace std;

class Captura
{
public:
    static void capturar(const string &mensaje, int min, int max, int &valor)
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

};


#endif //SSEDI_18A_CAPTURA_H
