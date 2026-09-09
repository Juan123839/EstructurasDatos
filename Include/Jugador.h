#ifndef JUGADOR_H
#define JUGADOR_H
#include <string>
#include <list>
#include "Carta.h"
class Jugador {
private:
  std::string nombre;
  std::string color;
  std::list<Carta> cartas;
  std::string estado;
  bool conquisto;
public:
  Jugador();
  Jugador(std::string nombre, std::string color);
  std::string consultarNombre() const;
  std::string consultarColor() const;
  std::string consultarEstado() const;
  void cambiarEstado(std::string nuevoEstado);
  bool consultarConquistaEnTurno() const;
  void registrarConquistaEnTurno(bool valor);
  bool tieneCarta(const Carta& carta) const;
  void agregarCarta(const Carta& carta);
  void quitarCartas(const std::list<Carta>& grupo);
  std::list<Carta> consultarCartas() const;
  int contarCartas() const;
};
#include "../src/Jugador.cxx"
#endif