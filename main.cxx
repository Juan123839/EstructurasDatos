#include <iostream>
#include <string>
#include <vector>
#include "Interfaz.h"

using namespace std;

int main() {

    string linea;
    cout << "=======================================" << endl;
    cout << "              RISK" << endl;
    cout << "Bienvenido al sistema de apoyo de Risk" << endl;
    cout << "=======================================" << endl;
    cout << "Escriba 'ayuda' para ver los comandos disponibles" << endl;
    cout << endl;

    while (true) {
        cout << "$ ";
        getline(cin, linea);
        vector<string> tokens = separarTokens(linea);
        if (!procesarComando(tokens)) {
            break;
        }  
               
    }
    

    return 0;
}