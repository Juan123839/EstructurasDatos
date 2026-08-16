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
        if (tokens[0] == "estado_juego") {
            if (tokens.size() > 1) {
                cout << "Error: El comando 'estado_juego' no debe tener argumentos" << endl;
                continue;
            }
            cout << "Comando estado de juego: reconocido" << endl;
            continue;
        }

        if (tokens[0] == "atacar") {
            if (tokens.size() != 2) {
                cout << "Error de uso. Uso correcto: atacar nombre_jugador" << endl;
                continue;
            }
            cout << "Comando atacar: reconocido" << endl;
            continue;
        }
        if (tokens[0] == "costo_conquista") {
            if (tokens.size() != 3) {
                cout << "Error de uso. Uso correcto: costo_conquista nombre_jugador territorio" << endl;
                continue;
            }
            cout << "Comando costo_conquista: reconocido" << endl;
            continue;
        }
        if (tokens[0] == "inicializar") {
            if (tokens.size() != 2) {
                cout << "Error de uso. Uso correcto: inicializar archivo_inicio" << endl;
                continue;
            }
            cout << "Comando inicializar: reconocido" << endl;
            continue;
        }
        if (tokens[0] == "ayuda") {
            if (tokens.size() != 1) {
                cout << "Error de uso. Uso correcto: ayuda" << endl;
                continue;
            }
            cout << "Comandos disponibles:" << endl;
            cout << "inicializar archivo_inicio" << endl;
            cout << "estado_juego" << endl;
            cout << "atacar nombre_jugador" << endl;
            cout << "costo_conquista nombre_jugador territorio" << endl;
            cout << "salir" << endl;
            continue;
        }
        
        cout << "Error: El comando '" << tokens[0] << "' no es reconocido" << endl;
    }
    

    return 0;
}