#include "../Include/Tropa.h"
using namespace std;
Tropa::Tropa()
{
    tipo = ""; //tropa vacia, sin tipo todavia
    cantidad = 0;
}
Tropa::Tropa(string tipo, int cantidad)
{
    this->tipo = tipo; //guarda el tipo de figura, infanteria caballeria o artilleria
    this->cantidad = cantidad; //guarda cuantas figuras de ese tipo hay
}
string Tropa::consultarTipo() const
{
    return tipo;
}
int Tropa::consultarCantidad() const
{
    return cantidad;
}
int Tropa::consultarValorUnitario() const{
    if(tipo == "infanteria")
    {
        return 1;
    }
    if(tipo == "caballeria")
    {
        return 5;
    }
    if(tipo == "artilleria")
    {
        return 10;
    }
    return 0;
}
int Tropa::consultarEquivalencia() const
{
    return cantidad * consultarValorUnitario(); //multiplica cuantas figuras hay por lo que vale cada una
}
void Tropa::agregarFiguras(int n)
{
    if(n > 0)
    {
        cantidad = cantidad + n;
    }
}
void Tropa::quitarFiguras(int n)
{
    if(n <= cantidad)
    {
        cantidad = cantidad - n;
    }
}
bool Tropa::estaVacia() const
{
    return cantidad == 0;
}