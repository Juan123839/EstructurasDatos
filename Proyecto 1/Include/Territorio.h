#ifndef TERRITORIO_H
#define TERRITORIO_H
#include <string>
#include <list>
#include "Tropa.h"
class Territorio {
private:
  std::string codigo;
  std::string nombre;
  std::string colorPropietario;
  std::list<Tropa> tropas;
  std::list<std::string> vecinos;
public:
  Territorio();
  Territorio(std::string codigo, std::string nombre);
  std::string consultarCodigo() const;
  std::string consultarNombre() const;
  bool tienePropietario() const;
  std::string consultarColorPropietario() const;
  void asignarPropietario(std::string color);
  std::list<Tropa> consultarTropas() const;
  int consultarUnidades() const;
  void agregarUnidades(int n);
  void quitarUnidades(int n);
  void reagrupar();
  void agregarVecino(std::string codigoVecino);
  bool esVecino(std::string codigoVecino) const;
  std::list<std::string> consultarVecinos() const;
};
#endif