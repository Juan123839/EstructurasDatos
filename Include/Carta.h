#ifndef CARTA_H
#define CARTA_H

#include <string>

using namespace std;

class Carta {

private:
    string territorio;
    string simbolo;
public:
    Carta(string territorio, string simbolo);
    string consultarTerritorio();
    string consultarSimbolo();
    bool esComodin();
    bool esIgual(Carta otraCarta);
};

#endif