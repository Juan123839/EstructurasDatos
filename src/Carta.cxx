#include "../include/Carta.h"

Carta::Carta(string territorio, string simbolo)
{
    this->territorio = territorio; //Se le atribute el valor del territorio a la carta
    this->simbolo = simbolo; // Lo mismo pero con simbolo
}
string Carta::consultarTerritorio()
{
    return territorio; //Devuelve solo el territorio
}
string Carta::consultarSimbolo()
{
    return simbolo;//Devuelve solo el simbolo
}
bool Carta::esComodin()
{
    return territorio == "";//En caso de que este vacio se toma como comodin
}
bool Carta::esIgual(Carta otraCarta)
{
    return territorio == otraCarta.consultarTerritorio() && simbolo == otraCarta.consultarSimbolo();
} //Comparacion entre dos cartas, en caso de que sea verdad devuelve true y si no pues false