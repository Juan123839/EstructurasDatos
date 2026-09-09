#include "../include/Mazo.h"

Mazo::Mazo(){

    cartasDisponibles.push_back(Carta("1.1", "infanteria"));
    cartasDisponibles.push_back(Carta("1.2", "caballeria"));
    cartasDisponibles.push_back(Carta("1.3", "artilleria"));
    cartasDisponibles.push_back(Carta("1.4", "infanteria"));
    cartasDisponibles.push_back(Carta("1.5", "caballeria"));
    cartasDisponibles.push_back(Carta("1.6", "artilleria"));
    cartasDisponibles.push_back(Carta("1.7", "infanteria"));
    cartasDisponibles.push_back(Carta("1.8", "caballeria"));
    cartasDisponibles.push_back(Carta("1.9", "artilleria"));

    cartasDisponibles.push_back(Carta("2.1", "infanteria"));
    cartasDisponibles.push_back(Carta("2.2", "caballeria"));
    cartasDisponibles.push_back(Carta("2.3", "artilleria"));
    cartasDisponibles.push_back(Carta("2.4", "infanteria"));

    cartasDisponibles.push_back(Carta("3.1", "caballeria"));
    cartasDisponibles.push_back(Carta("3.2", "artilleria"));
    cartasDisponibles.push_back(Carta("3.3", "infanteria"));
    cartasDisponibles.push_back(Carta("3.4", "caballeria"));
    cartasDisponibles.push_back(Carta("3.5", "artilleria"));
    cartasDisponibles.push_back(Carta("3.6", "infanteria"));
    cartasDisponibles.push_back(Carta("3.7", "caballeria"));

    cartasDisponibles.push_back(Carta("4.1", "artilleria"));
    cartasDisponibles.push_back(Carta("4.2", "infanteria"));
    cartasDisponibles.push_back(Carta("4.3", "caballeria"));
    cartasDisponibles.push_back(Carta("4.4", "artilleria"));
    cartasDisponibles.push_back(Carta("4.5", "infanteria"));
    cartasDisponibles.push_back(Carta("4.6", "caballeria"));

    cartasDisponibles.push_back(Carta("5.1", "artilleria"));
    cartasDisponibles.push_back(Carta("5.2", "infanteria"));
    cartasDisponibles.push_back(Carta("5.3", "caballeria"));
    cartasDisponibles.push_back(Carta("5.4", "artilleria"));
    cartasDisponibles.push_back(Carta("5.5", "infanteria"));
    cartasDisponibles.push_back(Carta("5.6", "caballeria"));
    cartasDisponibles.push_back(Carta("5.7", "artilleria"));
    cartasDisponibles.push_back(Carta("5.8", "infanteria"));
    cartasDisponibles.push_back(Carta("5.9", "caballeria"));
    cartasDisponibles.push_back(Carta("5.10", "artilleria"));
    cartasDisponibles.push_back(Carta("5.11", "infanteria"));
    cartasDisponibles.push_back(Carta("5.12", "caballeria"));

    cartasDisponibles.push_back(Carta("6.1", "artilleria"));
    cartasDisponibles.push_back(Carta("6.2", "infanteria"));
    cartasDisponibles.push_back(Carta("6.3", "caballeria"));
    cartasDisponibles.push_back(Carta("6.4", "artilleria"));

    cartasDisponibles.push_back(Carta("", "comodin"));
    cartasDisponibles.push_back(Carta("", "comodin"));

}

bool Mazo::estaVacio(){

    return cartasDisponibles.size() == 0;

}

int Mazo::contarCartasDisponibles(){

    return cartasDisponibles.size();

}

Carta Mazo::repartirCarta(){

    Carta carta = cartasDisponibles[0];

    cartasDisponibles.erase(cartasDisponibles.begin());

    return carta;

}

void Mazo::descartarCartas(vector<Carta> grupoCartas){

    for(int i = 0; i < grupoCartas.size(); i++){

        cartasDescartadas.push_back(grupoCartas[i]);

    }

}

int Mazo::contarGruposIntercambiados(){

    return cartasDescartadas.size() / 3;

}

int Mazo::consultarUnidadesPorIntercambio(){

    int grupos = contarGruposIntercambiados();

    if(grupos == 0){
        return 4;
    }

    if(grupos == 1){
        return 6;
    }

    if(grupos == 2){
        return 8;
    }

    if(grupos == 3){
        return 10;
    }

    if(grupos == 4){
        return 12;
    }

    if(grupos == 5){
        return 15;
    }

    return 15 + ((grupos - 5) * 5);

}