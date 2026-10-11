#ifndef TROPA_H
#define TROPA_H
#include <string>
class Tropa {
private:
  std::string tipo;
  int cantidad;
public:
  Tropa();
  Tropa(std::string tipo, int cantidad);
  std::string consultarTipo() const;
  int consultarCantidad() const;
  int consultarValorUnitario() const;
  int consultarEquivalencia() const;
  void agregarFiguras(int n);
  void quitarFiguras(int n);
  bool estaVacia() const;
};
#endif