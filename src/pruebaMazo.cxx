#include <iostream>
#include "Mazo.h"
#include "Tablero.h"
using namespace std;
int main(){
    Tablero tablero;
    tablero.crearTablero();
    Mazo mazo;
    mazo.crearMazo(tablero);
    cout << "Territorios: " << tablero.consultarTerritorios().size() << endl;
    cout << "Cartas disponibles: " << mazo.contarCartasDisponibles() << endl;
    Carta carta = mazo.repartirCarta();
    cout << "Carta repartida correctamente" << endl;
    cout << "Cartas restantes: " << mazo.contarCartasDisponibles() << endl;
    return 0;
}