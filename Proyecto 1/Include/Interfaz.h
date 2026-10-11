#ifndef INTERFAZ_H
#define INTERFAZ_H

#include <string>
#include <vector>
#include "Juego.h"

using namespace std;

vector<string> separarTokens(string linea);
bool procesarComando(vector<string> tokens, Juego& juego);
void mostrarAyuda(vector<string> tokens);
#endif