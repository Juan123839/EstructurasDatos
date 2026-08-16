#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main() {

    string linea;

    while (true) {
        cout << "$ ";
        getline(cin, linea);
        vector<string> tokens;
        string palabra = "";

        for (int i = 0; i < linea.size(); i++) {
            if (linea[i] == ' ') {
                if (!palabra.empty()) {
                    tokens.push_back(palabra);
                    palabra = "";
                }
            } else {
                palabra += linea[i];
            }
        }
        if (!palabra.empty()) {
            tokens.push_back(palabra);
        }
        if (tokens.empty()) {
            cout << "No se ingresaron palabras" << endl;
            continue;
        }
        if (tokens[0] == "salir") {
            if (tokens.size() > 1) {
                cout << "Error: El comando 'salir' no debe tener argumentos" << endl;
                continue;
            }
            break;
        }
        for (int i = 0; i < tokens.size(); i++) {
            cout << tokens[i] << endl;
        }

    }

    return 0;
}