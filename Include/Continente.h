#ifndef CONTINENTE_H
#define CONTINENTE_H
#include <string>
#include <list>
#include "Territorio.h"
class Continente {
private:
  std::string nombre;
  std::list<Territorio> territorios;
  int bonificacion;
public:
  Continente();
  Continente(std::string nombre);
  void agregarTerritorio(const Territorio& territorio);
  std::string consultarNombre() const;
  std::list<Territorio>& consultarTerritorios();
  int consultarBonificacion() const;
  bool contieneTerritorio(std::string codigo) const;
  bool esControladoPor(std::string color) const;
  int contarTerritoriosDe(std::string color) const;
};
#include "../src/Continente.cxx"
#endif