#include "../Include/Continente.h"
using namespace std;
Continente::Continente()
{
    nombre = ""; //continente vacio, sin nombre todavia
    bonificacion = 0;
}
Continente::Continente(string nombre)
{
    this->nombre = nombre; //guarda el nombre del continente
    if (nombre == "America del Sur" || nombre == "Australia") //estos dos dan 2 unidades de bono
    {
        bonificacion = 2;
    }
    else if (nombre == "Africa") //africa da 3 unidades de bono
    {
        bonificacion = 3;
    }
    else if (nombre == "America del Norte" || nombre == "Europa") //estos dos dan 5 unidades de bono
    {
        bonificacion = 5;
    }
    else
    {
        bonificacion = 7; //si no es ninguno de los anteriores entonces es asia y da 7
    }
}
void Continente::agregarTerritorio(const Territorio& territorio)
{
    territorios.push_back(territorio); //mete el territorio al final de la lista del continente
}
string Continente::consultarNombre() const
{
    return nombre;
}
list<Territorio>& Continente::consultarTerritorios()
{
    return territorios; //entrega la lista real, no una copia, para poder modificar los territorios
}
int Continente::consultarBonificacion() const
{
    return bonificacion;
}
bool Continente::contieneTerritorio(string codigo) const
{
    list<Territorio>::const_iterator it;
    for (it = territorios.begin(); it != territorios.end(); it++) //recorre todos los territorios
    {
        if (it->consultarCodigo() == codigo)
        {
            return true; //encontro uno con ese codigo
        }
    }
    return false; //ninguno tenia ese codigo
}
bool Continente::esControladoPor(string color) const
{
    list<Territorio>::const_iterator it;
    for (it = territorios.begin(); it != territorios.end(); it++)
    {
        if (it->consultarColorPropietario() != color) //si uno solo no es de ese color ya no esta controlado
        {
            return false;
        }
    }
    return true; //todos los territorios son de ese color
}
int Continente::contarTerritoriosDe(string color) const
{
    int contador = 0;
    list<Territorio>::const_iterator it;
    for (it = territorios.begin(); it != territorios.end(); it++)
    {
        if (it->consultarColorPropietario() == color)
        {
            contador = contador + 1; //suma uno cada vez que encuentra un territorio de ese color
        }
    }
    return contador;
}