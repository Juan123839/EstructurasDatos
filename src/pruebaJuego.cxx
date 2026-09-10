#include <iostream>
#include "Juego.h"

using namespace std;

int main()
{
    Juego juego;

    juego.inicializar();

    cout << "Territorios: ";
    cout << juego.consultarTablero().consultarTerritorios().size() << endl;

    cout << "Cartas: ";
    cout << juego.consultarMazo().contarCartasDisponibles() << endl;

    return 0;
}