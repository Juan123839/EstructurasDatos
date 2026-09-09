#ifndef MAZO_H
#define MAZO_H

#include <vector>
#include "Carta.h"

using namespace std;

class Mazo{

private:
    vector<Carta> cartasDisponibles;
    vector<Carta> cartasDescartadas;
public:
    Mazo();
    bool estaVacio();
    int contarCartasDisponibles();
    Carta repartirCarta();
    void descartarCartas(vector<Carta> grupoCartas);
    int contarGruposIntercambiados();
    int consultarUnidadesPorIntercambio();
};
#endif