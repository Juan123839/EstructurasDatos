#include "../Include/Juego.h"
#include <stdexcept>
using namespace std;
#include <fstream>
#include <sstream>

Juego::Juego()
{
    turnoActual = 0;
    fase = "inicio";
    finalizado = false;
}

void Juego::inicializar()
{
    tablero.crearTablero();
    mazo.crearMazo(tablero);
    jugadores.clear();
    turnoActual = 0;
    fase = "inicio";
    finalizado = false;
}

void Juego::agregarJugador(Jugador jugador)
{
    jugadores.push_back(jugador);
}

list<Jugador>& Juego::consultarJugadores()
{
    return jugadores;
}

Tablero& Juego::consultarTablero()
{
    return tablero;
}

Mazo& Juego::consultarMazo()
{
    return mazo;
}

Jugador& Juego::consultarJugadorActual()
{
    if(jugadores.empty())
    {
        throw runtime_error("No hay jugadores registrados");
    }
    list<Jugador>::iterator it = jugadores.begin();
    for(int i = 0; i < turnoActual; i++)
    {
        it++;
    }
    return *it;
}

void Juego::cambiarTurno()
{
    if(jugadores.empty())
    {
        return;
    }
    turnoActual++;
    if(turnoActual >= jugadores.size())
    {
        turnoActual = 0;
    }
}

string Juego::consultarFase() const
{
    return fase;
}

void Juego::cambiarFase(string nuevaFase)
{
    fase = nuevaFase;
}

bool Juego::estaFinalizado() const
{
    return finalizado;
}

void Juego::finalizarJuego()
{
    finalizado = true;
}