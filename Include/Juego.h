#ifndef JUEGO_H
#define JUEGO_H
#include <string>
#include <list>
#include "Jugador.h"
#include "tablero.h"
#include "mazo.h"
class Juego {
private:
  std::list<Jugador> jugadores;
  Tablero tablero;
  Mazo mazo;
  std::string turnoActual;
public:
  Juego();
  bool estaInicializado() const;
  bool estaFinalizado() const;
  Jugador& consultarGanador();
  int inicializar(std::string archivoInicio);
  bool existeJugador(std::string nombre) const;
  Jugador& buscarJugador(std::string nombre);
  std::list<Jugador>& consultarJugadores();
  std::string consultarTurnoActual() const;
  Tablero& consultarTablero();
  int validarTurno(std::string nombre, std::string estadoEsperado) const;
  std::list<std::list<Carta> > buscarCombinacionesDeCartas(const Jugador& jugador) const;
  int intercambiarCartas(Jugador& jugador, const std::list<Carta>& grupo);
  bool entregarCarta(Jugador& jugador);
  void retirarJugador(Jugador& jugador, Jugador& conquistador);
  int obtenerUnidades(std::string nombre);
  std::list<int> resolverRondaDeAtaque(Territorio& origen, Territorio& destino);
  int atacar(std::string nombre);
  int fortificar(std::string nombre);
  void avanzarTurno();
  int consultarEstadoDelJuego() const;
};
#include "../src/Juego.cxx"


#endif