#ifndef CONTINENTE_H
#define CONTINENTE_H

#include <string>
#include <vector>
#include "Territorio.h"

using namespace std;

class Continente{

private:
    string nombre;
    vector<Territorio> territorios;
    int bonificacion;
public:
    Continente(string nombre, vector<Territorio> territorios, int bonificacion);
    string consultarNombre();
    vector<Territorio> consultarTerritorios();
    int consultarBonificacion();
    bool contieneTerritorio(string codigo);
    Territorio& buscarTerritorio(string codigo);
    int contarTerritoriosDeJugador(string color);
    bool esControladoPor(string color);
};
#endif