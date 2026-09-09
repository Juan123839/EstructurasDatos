#ifndef TABLERO_H
#define TABLERO_H

#include <string>
#include <vector>
#include "Continente.h"

using namespace std;

class Tablero{

private:
    vector<Continente> continentes;
public:
    Tablero();
    vector<Continente> consultarContinentes();
    bool existeTerritorio(string codigo);
    Territorio& buscarTerritorio(string codigo);
    void asignarOcupacionInicial(string codigo, string color, int unidades);
    int contarTerritoriosDeJugador(string color);
    int calcularBonificacionPorContinentes(string color);
    bool controlaTodoElTablero(string color);
    void mostrarTerritorios();
};
#endif