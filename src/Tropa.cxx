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
int Tropa::consultarValorUnitario() const
{
    if (tipo == "infanteria") //una figura de infanteria vale 1 unidad
    {
        return 1;
    }
    if (tipo == "caballeria") //una figura de caballeria vale 5 unidades
    {
        return 5;
    }
    return 10; //si no es infanteria ni caballeria entonces es artilleria y vale 10
}
int Tropa::consultarEquivalencia() const
{
    return cantidad * consultarValorUnitario(); //multiplica cuantas figuras hay por lo que vale cada una
}
void Tropa::agregarFiguras(int n)
{
    cantidad = cantidad + n; //suma las figuras nuevas a las que ya habia
}
void Tropa::quitarFiguras(int n)
{
    cantidad = cantidad - n; //resta las figuras que se van
}
bool Tropa::estaVacia() const
{
    return cantidad == 0;
}