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
        if (tokens[0] == "obtener_unidades") {
            if (tokens.size() != 2) {
                cout << "Error de uso. Uso correcto: obtener_unidades nombre_jugador" << endl;
                continue;
            }
            cout << "Comando obtener_unidades: reconocido" << endl;
            continue;
        }
        if (tokens[0] == "fortificar") {
            if (tokens.size() != 2) {
                cout << "Error de uso. Uso correcto: fortificar nombre_jugador" << endl;
                continue;
            }
            cout << "Comando fortificar: reconocido" << endl;
            continue;
        }
        if (tokens[0] == "guardar") {
            if (tokens.size() != 2) {
                cout << "Error de uso. Uso correcto: guardar nombre_archivo" << endl;
                continue;
            }
            cout << "Comando guardar: reconocido" << endl;
            continue;
        }
        if (tokens[0] == "guardar_comprimido") {
            if (tokens.size() != 2) {
                cout << "Error de uso. Uso correcto: guardar_comprimido nombre_archivo" << endl;
                continue;
            }
            cout << "Comando guardar_comprimido: reconocido" << endl;
            continue;
        }
        if (tokens[0] == "conquista_mas_barata") {
            if (tokens.size() != 2) {
                cout << "Error de uso. Uso correcto: conquista_mas_barata nombre_jugador" << endl;
                continue;
            }
            cout << "Comando conquista_mas_barata: reconocido" << endl;
            continue;
        }
        if (tokens[0] == "ayuda") {
            if (tokens.size() == 1) {
                cout << "Comandos disponibles:" << endl;
                cout << "inicializar archivo_inicio" << endl;
                cout << "estado_juego" << endl;
                cout << "atacar nombre_jugador" << endl;
                cout << "costo_conquista nombre_jugador territorio" << endl;
                cout << "obtener_unidades nombre_jugador" << endl;
                cout << "fortificar nombre_jugador" << endl;
                cout << "guardar nombre_archivo" << endl;
                cout << "guardar_comprimido nombre_archivo" << endl;
                cout << "conquista_mas_barata nombre_jugador" << endl;
                cout << "salir" << endl;
                cout << "Para obtener ayuda sobre un comando específico, escriba 'ayuda [comando]'" << endl;
                continue;
            }
            if (tokens.size() > 2) {
                cout << "Error de uso. Uso correcto: ayuda [comando]" << endl;
                continue;
            }
            if (tokens[1] == "atacar") {
                cout << "Uso: atacar nombre_jugador" << endl;
                cout << "Descripción: Permite al jugador indicado realizar su fase de ataque." << endl;
                continue;
            }
            if (tokens[1] == "estado_juego") {
                cout << "Uso: estado_juego" << endl;
                cout << "Descripción: Muestra el estado actual del juego." << endl;
                continue;
            } 
            if (tokens[1] == "costo_conquista") {
                cout << "Uso: costo_conquista nombre_jugador territorio" << endl;
                cout << "Descripción: Muestra el costo de conquista de un territorio para un jugador específico." << endl;
                continue;
            }
            if (tokens[1] == "inicializar") {
                cout << "Uso: inicializar archivo_inicio" << endl;
                cout << "Descripción: Inicializa el juego con el archivo de inicio especificado." << endl;
                continue;
            }
            if (tokens[1] == "salir") {
                cout << "Uso: salir" << endl;
                cout << "Descripción: Finaliza el programa." << endl;
                continue;
            }
            if (tokens[1] == "obtener_unidades") {
                cout << "Uso: obtener_unidades nombre_jugador" << endl;
                cout << "Descripción: Permite al jugador indicado reclamar y ubicar las unidades correspondientes a su turno." << endl;
                continue;
            }
            if (tokens[1] == "fortificar") {
                cout << "Uso: fortificar nombre_jugador" << endl;
                cout << "Descripción: Permite al jugador indicado realizar la fase de fortificación de su turno." << endl;
                continue;
            }
            if (tokens[1] == "guardar") {
                cout << "Uso: guardar nombre_archivo" << endl;
                cout << "Descripción: Guarda el estado actual de la partida en un archivo de texto." << endl;
                continue;
            }
            if (tokens[1] == "guardar_comprimido") {
                cout << "Uso: guardar_comprimido nombre_archivo" << endl;
                cout << "Descripción: Guarda el estado actual de la partida en un archivo comprimido." << endl;
                continue;
            }
            if (tokens[1] == "conquista_mas_barata") {
                cout << "Uso: conquista_mas_barata nombre_jugador" << endl;
                cout << "Descripción: Busca la conquista de menor costo para el jugador indicado." << endl;
                continue;
            }
            cout << "Error: No existe ayuda para el comando '" << tokens[1] << "'"<< endl;
            continue;
        }
        
        cout << "Error: El comando '" << tokens[0] << "' no es reconocido" << endl;
    }
    

    return 0;
}