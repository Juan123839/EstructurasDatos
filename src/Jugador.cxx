#include "../Include/Jugador.h"
using namespace std;
Jugador::Jugador()
{
    nombre = ""; //jugador vacio, sin nombre todavia
    color = "";
    estado = "espera";
    conquisto = false;
}
Jugador::Jugador(string nombre, string color)
{
    this->nombre = nombre; //guarda el nombre del jugador
    this->color = color; //guarda el color del jugador
    estado = "espera"; //todo jugador nuevo empieza en espera
    conquisto = false; //al empezar no ha conquistado nada en este turno
}
string Jugador::consultarNombre() const
{
    return nombre;
}
string Jugador::consultarColor() const
{
    return color;
}
string Jugador::consultarEstado() const
{
    return estado;
}
void Jugador::cambiarEstado(string nuevoEstado)
{
    estado = nuevoEstado; //cambia la etapa del turno en la que esta el jugador
}
bool Jugador::consultarConquistaEnTurno() const
{
    return conquisto;
}
void Jugador::registrarConquistaEnTurno(bool valor)
{
    conquisto = valor;
}
bool Jugador::tieneCarta(const Carta& carta) const
{
    list<Carta>::const_iterator it;
    for (it = cartas.begin(); it != cartas.end(); it++) //recorre toda la mano
    {
        if (it->esIgual(carta))
        {
            return true; //encontro esa carta en la mano
        }
    }
    return false; //esa carta no esta en la mano
}
void Jugador::agregarCarta(const Carta& carta)
{
    cartas.push_back(carta); //mete la carta al final de la mano
}
void Jugador::quitarCartas(const list<Carta>& grupo)
{
    list<Carta>::const_iterator itGrupo;
    for (itGrupo = grupo.begin(); itGrupo != grupo.end(); itGrupo++) //recorre cada carta que hay que quitar
    {
        list<Carta>::iterator itMano;
        for (itMano = cartas.begin(); itMano != cartas.end(); itMano++) //busca esa carta en la mano
        {
            if (itMano->esIgual(*itGrupo))
            {
                cartas.erase(itMano); //la saca de la mano
                break;
            }
        }
    }
}
list<Carta> Jugador::consultarCartas() const
{
    return cartas;
}
int Jugador::contarCartas() const
{
    return cartas.size();
}


