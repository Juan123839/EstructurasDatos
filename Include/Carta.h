#ifndef CARTA_H
#define CARTA_H

#include <string>

using namespace std;

class Carta {

private:
    string tipo;
    string territorioAsociado;
    string simbolo;

public:
    Carta(string tipo, string territorioAsociado, string simbolo);
    string consultarTipo();
    string consultarTerritorioAsociado();
    string consultarSimbolo();
    bool esIgual(Carta otraCarta);
};

#endif