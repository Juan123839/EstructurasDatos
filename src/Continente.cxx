#include "../include/Continente.h"

Continente::Continente(string nombre, vector<Territorio> territorios, int bonificacion){
    this->nombre = nombre;
    this->territorios = territorios;
    this->bonificacion = bonificacion;
}
string Continente::consultarNombre(){
    return nombre;
}
vector<Territorio> Continente::consultarTerritorios(){
    return territorios;
}
int Continente::consultarBonificacion(){
    return bonificacion;
}

bool Continente::contieneTerritorio(string codigo){
    for (int i = 0; i < territorios.size(); i++){
        if (territorios[i].consultarCodigo() == codigo){
            return true;
        }
    }
    return false;
}
Territorio& Continente::buscarTerritorio(string codigo){
    for (size_t i = 0; i < territorios.size(); i++){
        if (territorios[i].consultarCodigo() == codigo){
            return territorios[i];
        }
    }
    return territorios[0];
}

int Continente::contarTerritoriosDeJugador(string color){
    int contador = 0;
    for (size_t i = 0; i < territorios.size(); i++){
        if (territorios[i].consultarColorPropietario() == color){
            contador++;
        }
    }
    return contador;
}

bool Continente::esControladoPor(string color){
    return contarTerritoriosDeJugador(color) == (int)territorios.size();
}