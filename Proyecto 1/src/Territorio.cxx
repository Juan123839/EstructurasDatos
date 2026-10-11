#include "../Include/Territorio.h"
using namespace std;
Territorio::Territorio()
{
    codigo = "";
    nombre = "";
    colorPropietario = "";
}
Territorio::Territorio(string codigo, string nombre)
{
    this->codigo = codigo; // asigna el codigo al territorio
    this->nombre = nombre; // asigna el nombre al territorio
    colorPropietario = ""; // inicia el territorio sin propietario
}
string Territorio::consultarCodigo() const
{
    return codigo;
}
string Territorio::consultarNombre() const
{
    return nombre;
}
bool Territorio::tienePropietario() const
{
    return colorPropietario != "";
}
string Territorio::consultarColorPropietario() const
{
    return colorPropietario;
}
void Territorio::asignarPropietario(string color)
{
    colorPropietario = color;
}
list<Tropa> Territorio::consultarTropas() const
{
    return tropas;
}
int Territorio::consultarUnidades() const
{
    int unidades = 0;
    for(Tropa tropa : tropas)
    {
        unidades = unidades + tropa.consultarCantidad();
    }
    return unidades;
}
void Territorio::agregarUnidades(int n)
{
    if(tropas.empty())
    {
        if(n > 0)
        {
            Tropa tropa("infanteria", n);
            tropas.push_back(tropa);
        }
    }
    else
    {
        if(n > 0)
        {
            tropas.front().agregarFiguras(n);
        }
        else if(n < 0)
        {
            tropas.front().quitarFiguras(-n);

            if(tropas.front().estaVacia())
            {
                tropas.clear();
            }
        }
    }
}
void Territorio::quitarUnidades(int n)
{
    if(!tropas.empty() && n > 0)
    {
        tropas.front().quitarFiguras(n);
    }
}
void Territorio::reagrupar()
{
}
void Territorio::agregarVecino(string codigoVecino)
{
    if(!esVecino(codigoVecino))
    {
        vecinos.push_back(codigoVecino);
    }
}
bool Territorio::esVecino(string codigoVecino) const
{
    for(string vecino : vecinos)
    {
        if(vecino == codigoVecino)
        {
            return true;
        }
    }
    return false;
}
list<string> Territorio::consultarVecinos() const
{
    return vecinos;
}