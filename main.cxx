#include <iostream>
#include <string>
#include <vector>
#include "Interfaz.h"

using namespace std;

int main() {

    string linea;

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