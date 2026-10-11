#ifndef MAZO_H
#define MAZO_H
#include <list>
#include "Carta.h"
#include "Tablero.h"
class Mazo {
private:
  std::list<Carta> disponibles;
  std::list<Carta> descartadas;
  int grupos;
public:
  Mazo();
  void crearMazo(Tablero& tablero);
  bool estaVacio() const;
  int contarCartasDisponibles() const;
  Carta repartirCarta();
  void descartarCartas(const std::list<Carta>& grupo);
  int consultarUnidadesPorIntercambio() const;
};
#endif