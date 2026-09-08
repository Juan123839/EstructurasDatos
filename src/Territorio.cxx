#include "../include/Territorio.h"
Territorio::Territorio(string codigo, string nombre, vector<string> vecinos)
{
    this->codigo = codigo; //Asigna codigo al territorio
    this->nombre = nombre; //Asigna nombre al territorio
    this->vecinos = vecinos; //Asigna los territorios vecinos al territorio
    colorPropietario = ""; //Asigna el color del propt del territorio, en este caso es vacio xq no tiene a nadie
    unidades = 0; //se comienza con 0 unidades en cada territorio
}
string Territorio::consultarCodigo(){
    return codigo;
}
string Territorio::consultarNombre(){
    return nombre;
}
string Territorio::consultarColorPropietario(){
    return colorPropietario;
}
int Territorio::consultarUnidades(){
    return unidades;
}
void Territorio::asignarPropietario(string color){
    colorPropietario = color;
}
void Territorio::agregarUnidades(int cantidad){
    unidades = unidades + cantidad;
}
void Territorio::quitarUnidades(int cantidad){
    unidades = unidades - cantidad;
}
bool Territorio::esVecino(string codigoVecino){
    for (int i = 0; i < vecinos.size(); i++){
        if (vecinos[i] == codigoVecino){
            return true;
        }
    }
    return false;
}
