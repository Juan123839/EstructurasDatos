#include "../Include/Carta.h"


Carta::Carta(string tipo, string territorioAsociado, string simbolo)
{
    this->tipo = tipo;
    this->territorioAsociado = territorioAsociado;
    this->simbolo = simbolo;
}

string Carta::consultarTipo()
{
    return tipo;
}

string Carta::consultarTerritorioAsociado()
{
    return territorioAsociado;
}

string Carta::consultarSimbolo()
{
    return simbolo;
}

bool Carta::esIgual(Carta otraCarta)
{
    return tipo == otraCarta.consultarTipo() && territorioAsociado == otraCarta.consultarTerritorioAsociado() &&
        simbolo == otraCarta.consultarSimbolo();
}