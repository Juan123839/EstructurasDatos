#include <iostream>
#include "Juego.h"
#include "Jugador.h"

using namespace std;

int main()
{
    Juego juego;

    juego.inicializar();

    Jugador jugador1("David", "1", "rojo");
    Jugador jugador2("Juan", "2", "azul");

    juego.agregarJugador(jugador1);
    juego.agregarJugador(jugador2);

    cout << "Cantidad de jugadores: "
         << juego.consultarJugadores().size()
         << endl;

    for(Jugador jugador : juego.consultarJugadores())
    {
        cout << "Nombre: "
             << jugador.consultarNombre()
             << endl;

        cout << "Color: "
             << jugador.consultarColor()
             << endl;
    }

    return 0;
}