#ifndef TABLERO_H
#define TABLERO_H
#include <string>
#include <list>
#include "Continente.h"
class Tablero {
private:
  std::list<Continente> continentes;
public:
  Tablero();
  void crearTablero();
  std::list<Continente>& consultarContinentes();
  bool existeTerritorio(std::string codigo) const;
  Territorio& buscarTerritorio(std::string codigo);
  std::list<Territorio*> consultarTerritorios();
  int contarTerritoriosDe(std::string color) const;
  int calcularBonificacionPorContinentes(std::string color) const;
  bool controlaTodoElTablero(std::string color) const;
  void conectarTerritorios(std::string codigo1, std::string codigo2);
};
#include "../src/Tablero.cxx"
#endif