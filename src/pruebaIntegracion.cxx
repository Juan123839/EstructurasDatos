#include <iostream>
#include "Tablero.h"
#include "Mazo.h"

using namespace std;

int main()
{
    Tablero tablero;
    Mazo mazo;

    tablero.crearTablero();

    cout << "territorios creados: ";
    cout << tablero.consultarTerritorios().size() << endl;

    mazo.crearMazo(tablero);

    cout << "cartas disponibles: ";
    cout << mazo.contarCartasDisponibles() << endl;

    Carta carta1 = mazo.repartirCarta();

    cout << "carta repartida" << endl;
    cout << "id: " << carta1.consultarIdentificador() << endl;
    cout << "tipo: " << carta1.consultarTipo() << endl;
    cout << "territorio: " << carta1.consultarCodigoTerritorio() << endl;
    cout << "simbolo: " << carta1.consultarSimbolo() << endl;

    cout << "cartas restantes: ";
    cout << mazo.contarCartasDisponibles() << endl;

    return 0;
}