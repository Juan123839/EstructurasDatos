#include <iostream>
#include "Jugador.h"
#include "Carta.h"
#include "Tablero.h"

using namespace std;

int main()
{
    Tablero tablero;
    tablero.crearTablero();

    Jugador jugador("David", "1", "rojo");

    jugador.agregarTerritorio("AN1");

    list<string> territorios = jugador.consultarTerritorios();

    for(string codigo : territorios)
    {
        Territorio& territorio = tablero.buscarTerritorio(codigo);

        cout << "codigo: " << codigo << endl;
        cout << "nombre: " << territorio.consultarNombre() << endl;
    }

    return 0;
}