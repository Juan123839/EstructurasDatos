#include <iostream>
#include "Interfaz.h"
#include "Juego.h"

using namespace std;

int main()
{
    Juego juego;

    string linea;
    vector<string> tokens;

    cout << "$ ";

    getline(cin, linea);

    tokens = separarTokens(linea);

    bool continuar = procesarComando(tokens, juego);

    if(continuar)
    {
        cout << "comando procesado" << endl;
    }
    else
    {
        cout << "juego terminado" << endl;
    }

    return 0;
}