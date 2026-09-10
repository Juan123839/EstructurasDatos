#include <iostream>
#include <string>
#include <vector>
#include "Interfaz.h"
#include "../Include/Juego.h"

using namespace std;

int main()
{
    Juego juego;

    string linea;

    cout << "=======================================" << endl;
    cout << "              RISK" << endl;
    cout << "Bienvenido al sistema de apoyo de Risk" << endl;
    cout << "=======================================" << endl;
    cout << "Escriba 'ayuda' para ver los comandos disponibles" << endl;
    cout << endl;

    bool continuar = true;

    while(continuar)
    {
        cout << "$ ";

        getline(cin, linea);

        vector<string> tokens = separarTokens(linea);

        continuar = procesarComando(tokens, juego);
    }

    return 0;
}