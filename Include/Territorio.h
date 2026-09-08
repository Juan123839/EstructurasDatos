#ifndef TERRITORIO_H
#define TERRITORIO_H
#include <string>
#include <vector>

using namespace std;

class Territorio{
    private:
    string codigo;
    string nombre;
    string colorPropietario;
    int unidades;
    vector<string> vecinos;

    public:
    Territorio(string codigo, string nombre,vector<string> vecinos);
    string consultarCodigo();
    string consultarNombre();
    string consultarColorPropietario();
    int consultarUnidades();
    void asignarPropietario(string color);
    void agregarUnidades(int cantidad);
    void quitarUnidades(int cantidad);
    bool esVecino(string codigoVecino);
    vector<string> consultarVecinos();
};
#endif