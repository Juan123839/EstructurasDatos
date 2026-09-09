#include "../include/Jugador.h"

Jugador::Jugador(string nombre, string color)
{
    this->nombre = nombre; //Se le asigna el nombre al jugador
    this->color = color; //Se le asigna el color al jugador
    fase = "obtencion"; //Se le asigna la fase inicial de obtencion
    conquistoEnTurno = false; //Se le asigna el valor inicial de conquista o sea false
}
string Jugador::consultarNombre(){
    return nombre;
}
string Jugador::consultarColor(){
    return color;
}
string Jugador::consultarFase(){
    return fase;
}

void Jugador::avanzarFase(){
    if(fase == "obtencion"){
        fase = "ataque";
    }else if(fase == "ataque"){
        fase = "fortificacion";
    }else if(fase == "fortificacion"){
        fase = "obtencion";
        conquistoEnTurno = false;
    }
}
bool Jugador::consultarConquistoEnTurno(){
    return conquistoEnTurno;
}
void Jugador::marcarConquista(){
    conquistoEnTurno = true;
}
void Jugador::agregarCarta(Carta carta){
    cartas.push_back(carta);
}
void Jugador::quitarCartas(vector<Carta> grupoCartas){
    for (int i = 0; i < grupoCartas.size(); i++){
        for (int j = 0; j < cartas.size(); j++){
            if (cartas[j].esIgual(grupoCartas[i])) {
                cartas.erase(cartas.begin() + j);
                break;
            }
        }
    }
}
vector<Carta> Jugador::consultarCartas()
{
    return cartas;
}
int Jugador::contarCartas(){
    return cartas.size();
}