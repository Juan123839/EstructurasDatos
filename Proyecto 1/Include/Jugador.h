#ifndef JUGADOR_H
#define JUGADOR_H
#include <string>
#include <list>
#include "Carta.h"

class Jugador {
private:
    std::string nombre;
    std::string codigo;
    std::string color;
    std::list<std::string> territorios;
    std::list<Carta> cartas;
    int unidadesDisponibles;
public:
    Jugador();
    Jugador(std::string nombre, std::string codigo, std::string color);
    std::string consultarNombre() const;
    std::string consultarCodigo() const;
    std::string consultarColor() const;
    void agregarTerritorio(std::string codigoTerritorio);
    void quitarTerritorio(std::string codigoTerritorio);
    bool tieneTerritorio(std::string codigoTerritorio) const;
    std::list<std::string> consultarTerritorios() const;
    void agregarCarta(const Carta& carta);
    void quitarCarta(int id);
    std::list<Carta> consultarCartas() const;
    void agregarUnidades(int cantidad);
    void quitarUnidades(int cantidad);
    int consultarUnidadesDisponibles() const;
};
#endif