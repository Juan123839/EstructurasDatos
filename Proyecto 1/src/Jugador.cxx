#include "../Include/Jugador.h"
using namespace std;

Jugador::Jugador()
{
    nombre = "";
    codigo = "";
    color = "";
    unidadesDisponibles = 0;
}

Jugador::Jugador(string nombre, string codigo, string color)
{
    this->nombre = nombre; //guarda el nombre del jugador
    this->codigo = codigo; //guarda el codigo del jugador
    this->color = color; //guarda el color del jugador
    unidadesDisponibles = 0;
}

string Jugador::consultarNombre() const
{
    return nombre;
}

string Jugador::consultarCodigo() const
{
    return codigo;
}

string Jugador::consultarColor() const
{
    return color;
}

void Jugador::agregarTerritorio(string codigoTerritorio)
{
    territorios.push_back(codigoTerritorio);
}

void Jugador::quitarTerritorio(string codigoTerritorio)
{
    territorios.remove(codigoTerritorio);
}

bool Jugador::tieneTerritorio(string codigoTerritorio) const
{
    for(string territorio : territorios)
    {
        if(territorio == codigoTerritorio)
        {
            return true;
        }
    }
    return false;
}

list<string> Jugador::consultarTerritorios() const
{
    return territorios;
}

void Jugador::agregarCarta(const Carta& carta)
{
    cartas.push_back(carta);
}

void Jugador::quitarCarta(int id)
{
    for(list<Carta>::iterator it = cartas.begin(); it != cartas.end(); it++)
    {
        if(it->consultarIdentificador() == id)
        {
            cartas.erase(it);
            return;
        }
    }
}

list<Carta> Jugador::consultarCartas() const
{
    return cartas;
}

void Jugador::agregarUnidades(int cantidad)
{
    if(cantidad > 0)
    {
        unidadesDisponibles = unidadesDisponibles + cantidad;
    }
}

void Jugador::quitarUnidades(int cantidad)
{
    if(cantidad <= unidadesDisponibles)
    {
        unidadesDisponibles = unidadesDisponibles - cantidad;
    }
}

int Jugador::consultarUnidadesDisponibles() const
{
    return unidadesDisponibles;
}