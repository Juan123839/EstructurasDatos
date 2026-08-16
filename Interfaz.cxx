#include "Interfaz.h"
using namespace std;

vector<string> separarTokens(string linea) {
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
    return tokens;
}