#include "../Include/Mazo.h"
#include "../Include/Continente.h"
#include "../Include/Tablero.h"
using namespace std;
#include <vector>
Mazo::Mazo(){
    grupos = 0;
}
void Mazo::crearMazo(Tablero& tablero){
    disponibles.clear();
    descartadas.clear();
    grupos = 0;
    // crea las cartas de los territorios
    list<Continente> continentes = tablero.consultarContinentes();
    for(Continente continente : continentes){
        list<Territorio> territorios = continente.consultarTerritorios();
        for(Territorio territorio : territorios){
            Carta carta(0, "territorio", territorio.consultarCodigo(), "infanteria");
            disponibles.push_back(carta);
        }
    }
    // agrega las cartas comodin
    Carta comodin1(43, "comodin", "", "");
    Carta comodin2(44, "comodin", "", "");
    disponibles.push_back(comodin1);
    disponibles.push_back(comodin2);
}
bool Mazo::estaVacio() const{
    return disponibles.empty();
}
int Mazo::contarCartasDisponibles() const{
    return disponibles.size();
}
Carta Mazo::repartirCarta(){
    Carta carta = disponibles.front();
    disponibles.pop_front();
    return carta;
}
void Mazo::descartarCartas(const list<Carta>& grupo){
    for(Carta carta : grupo){
        descartadas.push_back(carta);
    }
    grupos++;
}
int Mazo::consultarUnidadesPorIntercambio() const{
    if(grupos == 1){
        return 4;
    }else if(grupos == 2){
        return 6;
    }else if(grupos == 3){
        return 8;
    }else if(grupos == 4){
        return 10;
    }else if(grupos == 5){
        return 12;
    }else if(grupos == 6){
        return 15;
    }
    return 15 + ((grupos - 6) * 5);
}