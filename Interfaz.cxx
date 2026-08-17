#include "Interfaz.h"
#include <string>
#include <iostream>
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
bool procesarComando(vector<string> tokens) {

        if (tokens.empty()) {
            cout << "No se ingresaron palabras" << endl;
            return true;
        }
        if (tokens[0] == "salir") {
            if (tokens.size() > 1) {
                cout << "Error: El comando 'salir' no debe tener argumentos" << endl;
                return true;
            }
            return false;
        }
        if (tokens[0] == "estado_juego") {
            if (tokens.size() > 1) {
                cout << "Error: El comando 'estado_juego' no debe tener argumentos" << endl;
                return true;
            }
            cout << "Comando estado de juego: reconocido" << endl;
            return true;
        }

        if (tokens[0] == "atacar") {
            if (tokens.size() != 2) {
                cout << "Error de uso. Uso correcto: atacar nombre_jugador" << endl;
                return true;
            }
            cout << "Comando atacar: reconocido" << endl;
            return true;
        }
        if (tokens[0] == "costo_conquista") {
            if (tokens.size() != 3) {
                cout << "Error de uso. Uso correcto: costo_conquista nombre_jugador territorio" << endl;
                return true;
            }
            cout << "Comando costo_conquista: reconocido" << endl;
            return true;
        }
        if (tokens[0] == "inicializar") {
            if (tokens.size() != 2) {
                cout << "Error de uso. Uso correcto: inicializar archivo_inicio" << endl;
                return true;
            }
            cout << "Comando inicializar: reconocido" << endl;
            return true;
        }
        if (tokens[0] == "obtener_unidades") {
            if (tokens.size() != 2) {
                cout << "Error de uso. Uso correcto: obtener_unidades nombre_jugador" << endl;
                return true;
            }
            cout << "Comando obtener_unidades: reconocido" << endl;
            return true;
        }
        if (tokens[0] == "fortificar") {
            if (tokens.size() != 2) {
                cout << "Error de uso. Uso correcto: fortificar nombre_jugador" << endl;
                return true;
            }
            cout << "Comando fortificar: reconocido" << endl;
            return true;
        }
        if (tokens[0] == "guardar") {
            if (tokens.size() != 2) {
                cout << "Error de uso. Uso correcto: guardar nombre_archivo" << endl;
                return true ;
            }
            cout << "Comando guardar: reconocido" << endl;
            return true;
        }
        if (tokens[0] == "guardar_comprimido") {
            if (tokens.size() != 2) {
                cout << "Error de uso. Uso correcto: guardar_comprimido nombre_archivo" << endl;
                return true;
            }
            cout << "Comando guardar_comprimido: reconocido" << endl;
            return true;
        }
        if (tokens[0] == "conquista_mas_barata") {
            if (tokens.size() != 2) {
                cout << "Error de uso. Uso correcto: conquista_mas_barata nombre_jugador" << endl;
                return true;
            }
            cout << "Comando conquista_mas_barata: reconocido" << endl;
            return true;
        }
        if (tokens[0] == "ayuda") {
            mostrarAyuda(tokens);
            return true;
        }
        cout << "Error: El comando '" << tokens[0] << "' no es reconocido" << endl;
        return true;
}
void mostrarAyuda(vector<string> tokens) {
if (tokens.size() == 1) {
                cout << "========================================" << endl;
                cout << "          COMANDOS DISPONIBLES" << endl;
                cout << "========================================" << endl;
                cout << " inicializar archivo_inicio" << endl;
                cout << " estado_juego" << endl;
                cout << " atacar nombre_jugador" << endl;
                cout << " costo_conquista nombre_jugador territorio" << endl;
                cout << " obtener_unidades nombre_jugador" << endl;
                cout << " fortificar nombre_jugador" << endl;
                cout << " guardar nombre_archivo" << endl;
                cout << " guardar_comprimido nombre_archivo" << endl;
                cout << " conquista_mas_barata nombre_jugador" << endl;
                cout << " salir" << endl;
                cout << "Para obtener ayuda sobre un comando específico, escriba 'ayuda [comando]'" << endl;
                return;
            }
            if (tokens.size() > 2) {
                cout << "Error de uso. Uso correcto: ayuda [comando]" << endl;
                return;
            }
            if (tokens[1] == "atacar") {
                cout << "Uso: atacar nombre_jugador" << endl;
                cout << "Descripción: Permite al jugador indicado realizar su fase de ataque." << endl;
                return;
            }
            if (tokens[1] == "estado_juego") {
                cout << "Uso: estado_juego" << endl;
                cout << "Descripción: Muestra el estado actual del juego." << endl;
                return;
            } 
            if (tokens[1] == "costo_conquista") {
                cout << "Uso: costo_conquista nombre_jugador territorio" << endl;
                cout << "Descripción: Muestra el costo de conquista de un territorio para un jugador específico." << endl;
                return;
            }
            if (tokens[1] == "inicializar") {
                cout << "Uso: inicializar archivo_inicio" << endl;
                cout << "Descripción: Inicializa el juego con el archivo de inicio especificado." << endl;
                return;
            }
            if (tokens[1] == "salir") {
                cout << "Uso: salir" << endl;
                cout << "Descripción: Finaliza el programa." << endl;
                return;
            }
            if (tokens[1] == "obtener_unidades") {
                cout << "Uso: obtener_unidades nombre_jugador" << endl;
                cout << "Descripción: Permite al jugador indicado reclamar y ubicar las unidades correspondientes a su turno." << endl;
                return;
            }
            if (tokens[1] == "fortificar") {
                cout << "Uso: fortificar nombre_jugador" << endl;
                cout << "Descripción: Permite al jugador indicado realizar la fase de fortificación de su turno." << endl;
                return;
            }
            if (tokens[1] == "guardar") {
                cout << "Uso: guardar nombre_archivo" << endl;
                cout << "Descripción: Guarda el estado actual de la partida en un archivo de texto." << endl;
                return;
            }
            if (tokens[1] == "guardar_comprimido") {
                cout << "Uso: guardar_comprimido nombre_archivo" << endl;
                cout << "Descripción: Guarda el estado actual de la partida en un archivo comprimido." << endl;
                return;
            }
            if (tokens[1] == "conquista_mas_barata") {
                cout << "Uso: conquista_mas_barata nombre_jugador" << endl;
                cout << "Descripción: Busca la conquista de menor costo para el jugador indicado." << endl;
                return;
            }
            cout << "Error: No existe ayuda para el comando '" << tokens[1] << "'"<< endl;
}