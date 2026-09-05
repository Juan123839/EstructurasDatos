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
                cout << "Error de uso. Uso correcto: inicializar archivo_inicio.txt" << endl;
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
                cout << "COMANDOS DISPONIBLES" << endl;
                cout << " inicializar archivo_inicio" << endl;
                cout << " estado_juego" << endl;
                cout << " atacar nombre_jugador" << endl;
                cout << " costo_conquista nombre_jugador territorio" << endl;
                cout << " obtener_unidades nombre_jugador" << endl;
                cout << " fortificar nombre_jugador" << endl;
                cout << " guardar nombre_archivo" << endl;
                cout << " guardar_comprimido nombre_archivo" << endl;
                cout << " conquista_mas_barata nombre_jugador" << endl;
                cout << "ayuda [comando]" << endl;
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
                cout << "Descripcion: Realiza las operaciones descritas dentro del turno del jugador nombre_jugador correspondientes al ataque" << endl;
                cout << "El comando debe preguntar primero la configuracion del ataque, es decir, desde cual territorio quiere atacar que contiene actualmente unidades del jugador y hacia cual territorio dirigira el ataque" << endl;
                cout << "Luego debe verificar las condiciones del ataque e informar los valores obtenidos con los dados y la cantidad de unidades que se ganan o pierden" << endl;
                cout << "Este proceso se repite hasta que alguno de los dos territorios se quede sin unidades o hasta que el atacante decida detenerse" << endl;
                cout << "En este comando es clave utilizar una interfaz adecuada que sea facil de seguir para los jugadores en pantalla" << endl;
                cout << "Posibles salidas:" << endl;
                cout << "- Juego no inicializado: Esta partida no ha sido inicializada correctamente" << endl;
                cout << "- Juego terminado: Esta partida ya tuvo un ganador" << endl;
                cout << "- Jugador no valido: El jugador nombre_jugador no forma parte de esta partida" << endl;
                cout << "- Jugador fuera de turno: No es el turno del jugador nombre_jugador" << endl;
                cout << "- Jugador no ha ubicado unidades: El jugador nombre_jugador no ha ejecutado el comando obtener_unidades" << endl;
                cout << "- Comando correcto: El jugador nombre_jugador ha terminado de atacar" << endl;
                return;
            }
            if (tokens[1] == "estado_juego") {
                cout << "Uso: estado_juego" << endl;
                cout << "Descripcion: Presenta en pantalla un resumen de la situacion actual del juego" << endl;
                cout << "Se debe indicar el numero de jugadores, los nombres y colores de cada uno, el jugador con el turno actual y la lista de territorios" << endl;
                cout << "Tambien se debe indicar el color del jugador que controla cada territorio y la cantidad de unidades ubicadas en cada uno" << endl;
                cout << "Posibles salidas:" << endl;
                cout << "- Juego no inicializado: Esta partida no ha sido inicializada correctamente" << endl;
                cout << "- Juego terminado: Esta partida ya tuvo un ganador" << endl;
                return;
            }
           if (tokens[1] == "costo_conquista") {
                cout << "Uso: costo_conquista nombre_jugador territorio" << endl;
                cout << "Descripcion: Calcula el costo y la secuencia de territorios que deben ser conquistados para lograr controlar el territorio indicado por el usuario" << endl;
                cout << "El territorio desde donde debe atacar debe ser aquel que el jugador tenga controlado mas cerca al dado por el usuario" << endl;
                cout << "Esta informacion se analiza desde el punto de vista del jugador nombre_jugador" << endl;
                cout << "Posibles salidas:" << endl;
                cout << "- Juego no inicializado: Esta partida no ha sido inicializada correctamente" << endl;
                cout << "- Juego terminado: Esta partida ya tuvo un ganador" << endl;
                cout << "- Comando correcto: Para conquistar el territorio territorio, nombre_jugador debe atacar desde territorio_1 pasando por los territorios territorio_2, territorio_3 hasta territorio_m" << endl;
                cout << "Debe conquistar n unidades de ejercito" << endl;
                return;
            }
            if (tokens[1] == "inicializar") {
                cout << "Uso: inicializar archivo_inicio" << endl;
                cout << "Descripcion: Inicializa el juego con los datos contenidos en el archivo identificado por archivo_inicio" << endl;
                cout << "El archivo debe contener la informacion de jugadores, colores, territorios y unidades ocupadas" << endl;
                cout << "El comando puede inicializar el juego desde un archivo normal generado por guardar o desde un archivo binario con datos comprimidos generado por guardar_comprimido" << endl;
                cout << "Posibles salidas:" << endl;
                cout << "- Archivo vacio: archivo_inicio no contiene informacion" << endl;
                cout << "- Archivo erroneo: archivo_inicio no se encuentra o no puede leerse" << endl;
                cout << "- Archivo sin formato: archivo_inicio no contiene informacion en el formato esperado" << endl;
                cout << "- Juego en curso: El juego ya ha sido inicializado" << endl;
                cout << "- Comando correcto: El juego se ha inicializado correctamente" << endl;
                cout << "Durante la lectura se valida que los colores de los territorios correspondan a los jugadores definidos, que las unidades sean correctas y que todos los territorios tengan unidades asignadas" << endl;
                return;
            }
           if (tokens[1] == "salir") {
                cout << "Uso: salir" << endl;
                cout << "Descripcion: Termina la ejecucion de la aplicacion" << endl;
                cout << "Posibles salidas:" << endl;
                cout << "- No tiene salida por pantalla" << endl;
                return;
            }
            if (tokens[1] == "obtener_unidades") {
                cout << "Uso: obtener_unidades nombre_jugador" << endl;
                cout << "Descripcion: Realiza las operaciones descritas dentro del turno del jugador nombre_jugador correspondientes a la obtencion de nuevas unidades" << endl;
                cout << "El comando debe informar al jugador cuantas unidades adicionales puede reclamar para su turno" << endl;
                cout << "Luego debe preguntarle donde desea ubicar estas unidades y en que cantidad" << endl;
                cout << "El jugador puede asignar las unidades adicionales a los territorios que le pertenecen" << endl;
                cout << "En este comando es clave utilizar una interfaz adecuada que sea facil de seguir para los jugadores en pantalla" << endl;
                cout << "Posibles salidas:" << endl;
                cout << "- Juego no inicializado: Esta partida no ha sido inicializada correctamente" << endl;
                cout << "- Juego terminado: Esta partida ya tuvo un ganador" << endl;
                cout << "- Jugador no valido: El jugador nombre_jugador no forma parte de esta partida" << endl;
                cout << "- Jugador fuera de turno: No es el turno del jugador nombre_jugador" << endl;
                cout << "- Comando correcto: El jugador nombre_jugador ha terminado de reclamar y ubicar sus unidades" << endl;
                return;
            }
            if (tokens[1] == "fortificar") {
                cout << "Uso: fortificar nombre_jugador" << endl;
                cout << "Descripcion: Realiza las operaciones descritas dentro del turno del jugador nombre_jugador correspondientes a la fortificacion" << endl;
                cout << "El comando debe preguntar al jugador los territorios vecinos que desea seleccionar para la fortificacion, asi como la cantidad de unidades que desea trasladar de un territorio a otro" << endl;
                cout << "Luego debe verificar las condiciones de la fortificacion y realizar el traslado de unidades seleccionado por el jugador" << endl;
                cout << "En este comando es clave utilizar una interfaz adecuada que sea facil de seguir para los jugadores en pantalla" << endl;
                cout << "Posibles salidas:" << endl;
                cout << "- Juego no inicializado: Esta partida no ha sido inicializada correctamente" << endl;
                cout << "- Juego terminado: Esta partida ya tuvo un ganador" << endl;
                cout << "- Jugador no valido: El jugador nombre_jugador no forma parte de esta partida" << endl;
                cout << "- Jugador fuera de turno: No es el turno del jugador nombre_jugador" << endl;
                cout << "- Jugador no ha atacado: El jugador nombre_jugador no ha ejecutado el comando atacar" << endl;
                cout << "- Comando correcto: El jugador nombre_jugador ha terminado de fortificar su posicion" << endl;
                return;
            }
            if (tokens[1] == "guardar") {
                cout << "Uso: guardar nombre_archivo" << endl;
                cout << "Descripcion: El estado actual del juego es guardado en un archivo de texto, con el mismo formato del archivo usado para la inicializacion del juego" << endl;
                cout << "Este comando guarda un archivo de texto plano, sin codificacion" << endl;
                cout << "Posibles salidas:" << endl;
                cout << "- Juego no inicializado: Esta partida no ha sido inicializada correctamente" << endl;
                cout << "- Comando correcto: La partida ha sido guardada correctamente" << endl;
                cout << "- Error al guardar: La partida no ha sido guardada correctamente" << endl;
                return;
            }
            if (tokens[1] == "guardar_comprimido") {
                cout << "Uso: guardar_comprimido nombre_archivo" << endl;
                cout << "Descripcion: El estado actual del juego es guardado en un archivo binario con extension .bin con la misma informacion que se almacenaria en un archivo de texto normal" << endl;
                cout << "El archivo es comprimido utilizando la codificacion de Huffman en el formato descrito en el proyecto" << endl;
                cout << "Posibles salidas:" << endl;
                cout << "- Juego no inicializado: Esta partida no ha sido inicializada correctamente" << endl;
                cout << "- Comando correcto: La partida ha sido codificada y guardada correctamente" << endl;
                cout << "- Error al codificar y/o guardar: La partida no ha sido codificada ni guardada correctamente" << endl;
                return;
            }
            if (tokens[1] == "conquista_mas_barata") {
                cout << "Uso: conquista_mas_barata nombre_jugador" << endl;
                cout << "Descripcion: Determina los territorios posibles cuya conquista implique un menor numero de unidades de ejercito perdidas" << endl;
                cout << "Esta informacion se analiza desde el punto de vista del jugador nombre_jugador" << endl;
                cout << "Posibles salidas:" << endl;
                cout << "- Juego no inicializado: Esta partida no ha sido inicializada correctamente" << endl;
                cout << "- Juego terminado: Esta partida ya tuvo un ganador" << endl;
                cout << "- Comando correcto: La conquista mas barata es ganar sobre el territorio territorio_1 desde el territorio territorio_2" << endl;
                cout << "Para conquistar el territorio territorio_1, debe atacar desde territorio_2 pasando por los territorios territorio_3, territorio_4 hasta territorio_m" << endl;
                cout << "Debe conquistar n unidades de ejercito" << endl;
                return; 
            }
            if (tokens[1] == "ayuda") {
                 cout << "Uso: ayuda [comando]" << endl;
                  cout << "Descripcion: Muestra los comandos disponibles o la ayuda de un comando especifico" << endl;
                 return;
            }
            cout << "Error: No existe ayuda para el comando '" << tokens[1] << "'"<< endl;
            return;
}