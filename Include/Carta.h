#ifndef CARTA_H
#define CARTA_H
#include <string>
class Carta {
private:
  int id;
  std::string tipo;
  std::string codigoTerritorio;
  std::string simbolo;
public:
  Carta();
  Carta(int id, std::string tipo, std::string codigoTerritorio, std::string simbolo);
  int consultarIdentificador() const;
  std::string consultarTipo() const;
  bool tieneTerritorio() const;
  std::string consultarCodigoTerritorio() const;
  std::string consultarSimbolo() const;
  bool esIgual(const Carta& otra) const;
};
#endif