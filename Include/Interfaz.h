#ifndef INTERFAZ_H
#define INTERFAZ_H

#include <string>
#include <vector>

using namespace std;

vector<string> separarTokens(string linea);

bool procesarComando(vector<string> tokens);

void mostrarAyuda(vector<string> tokens);
#endif