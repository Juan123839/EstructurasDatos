#ifndef JUEGO_H
#define JUEGO_H

#include <string>
#include <list>
#include "Jugador.h"
#include "Tablero.h"
#include "Mazo.h"

class Juego {
private:
    std::list<Jugador> jugadores;
    Tablero tablero;
    Mazo mazo;
    int turnoActual;
    std::string fase;
    bool finalizado;

public:
    Juego();
    void inicializar();
    void agregarJugador(Jugador jugador);
    std::list<Jugador>& consultarJugadores();
    Tablero& consultarTablero();
    Mazo& consultarMazo();
    Jugador& consultarJugadorActual();
    void cambiarTurno();
    std::string consultarFase() const;
    void cambiarFase(std::string nuevaFase);
    bool estaFinalizado() const;
    void finalizarJuego();
};
#endif