#include <iostream>
#include "Interfaz.h"

using namespace std;

int main()
{
    string linea;
    vector<string> tokens;

    cout << "$ ";

    getline(cin, linea);

    tokens = separarTokens(linea);

    bool continuar = procesarComando(tokens);

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