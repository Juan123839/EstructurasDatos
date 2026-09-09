#include "../Include/Carta.h"
using namespace std;
Carta::Carta()
{
    id = 0; //la carta vacia no tiene numero todavia
    tipo = "";
    codigoTerritorio = "";
    simbolo = "";
}
Carta::Carta(int id, string tipo, string codigoTerritorio, string simbolo)
{
    this->id = id; //guarda el numero de la carta, esto es lo que la hace unica
    this->tipo = tipo; //guarda si la carta es de territorio o comodin
    this->codigoTerritorio = codigoTerritorio; //guarda el codigo del territorio dibujado en la carta
    this->simbolo = simbolo; //guarda el dibujo de la carta, infanteria caballeria artilleria o comodin
}
int Carta::consultarIdentificador() const
{
    return id;
}
string Carta::consultarTipo() const
{
    return tipo;
}
bool Carta::tieneTerritorio() const
{
    return tipo == "territorio"; //solo las cartas de territorio tienen un territorio dibujado
}
string Carta::consultarCodigoTerritorio() const
{
    return codigoTerritorio;
}
string Carta::consultarSimbolo() const
{
    return simbolo;
}
bool Carta::esIgual(const Carta& otra) const
{
    return id == otra.consultarIdentificador(); //dos cartas son la misma si tienen el mismo numero
}

 