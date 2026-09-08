#ifndef JUGADOR_H
#define JUGADOR_H
#include <string>
#include <vector>
#include "Carta.h"

using namespace std;

class Jugador{
    private:
    string nombre;
    string color;
    vector<Carta> cartas; // nuestra baraja de cartas
    string fase; // fase en la que esta el jugador
    bool conquistoEnTurno; //
    public:
    Jugador(string nombre, string color);
    string consultarNombre();
    string consultarColor();
    string consultarFase();
    void avanzarFase();
    bool consultarConquistoEnTurno();
    void marcarConquista();
    void agregarCarta(Carta carta);
    void quitarCartas(vector<Carta> grupoCartas);
    vector<Carta> consultarCartas();
    int contarCartas();
};
#endif