#include "../include/Tablero.h"
#include <iostream>

Tablero::Tablero(){

    vector<string> vecinos;
    // AMERICA DEL NORTE

    vector<Territorio> americaNorte;

    // 1.1 Alaska
    vecinos.push_back("1.2");
    vecinos.push_back("1.6");
    vecinos.push_back("5.6");
    americaNorte.push_back(
        Territorio("1.1", "Alaska", vecinos));
    vecinos.clear();

    // 1.2 Alberta
    vecinos.push_back("1.1");
    vecinos.push_back("1.6");
    vecinos.push_back("1.7");
    vecinos.push_back("1.9");
    americaNorte.push_back(
        Territorio("1.2", "Alberta", vecinos));
    vecinos.clear();

    // 1.3 America Central
    vecinos.push_back("1.4");
    vecinos.push_back("1.9");
    vecinos.push_back("2.4");
    americaNorte.push_back(
        Territorio("1.3", "America Central", vecinos));
    vecinos.clear();

    // 1.4 Estados Unidos Orientales
    vecinos.push_back("1.3");
    vecinos.push_back("1.7");
    vecinos.push_back("1.8");
    vecinos.push_back("1.9");
    americaNorte.push_back(
        Territorio("1.4", "Estados Unidos Orientales", vecinos));
    vecinos.clear();

    // 1.5 Groenlandia
    vecinos.push_back("1.6");
    vecinos.push_back("1.7");
    vecinos.push_back("1.8");
    vecinos.push_back("3.2");
    americaNorte.push_back(
        Territorio("1.5", "Groenlandia", vecinos));
    vecinos.clear();

    // 1.6 Territorio Noroccidental
    vecinos.push_back("1.1");
    vecinos.push_back("1.2");
    vecinos.push_back("1.5");
    vecinos.push_back("1.7");
    americaNorte.push_back(
        Territorio("1.6", "Territorio Noroccidental", vecinos));
    vecinos.clear();

    // 1.7 Ontario
    vecinos.push_back("1.2");
    vecinos.push_back("1.4");
    vecinos.push_back("1.5");
    vecinos.push_back("1.6");
    vecinos.push_back("1.8");
    vecinos.push_back("1.9");
    americaNorte.push_back(
        Territorio("1.7", "Ontario", vecinos));
    vecinos.clear();

    // 1.8 Quebec
    vecinos.push_back("1.4");
    vecinos.push_back("1.5");
    vecinos.push_back("1.7");
    americaNorte.push_back(
        Territorio("1.8", "Quebec", vecinos));
    vecinos.clear();

    // 1.9 Estados Unidos Occidentales
    vecinos.push_back("1.2");
    vecinos.push_back("1.3");
    vecinos.push_back("1.4");
    vecinos.push_back("1.7");
    americaNorte.push_back(
        Territorio("1.9", "Estados Unidos Occidentales", vecinos));
    vecinos.clear();
    Continente continenteAmericaNorte(
        "America del Norte", americaNorte, 5);
    continentes.push_back(continenteAmericaNorte);

    // AMERICA DEL SUR

    vector<Territorio> americaSur;

    // 2.1 Argentina

    vecinos.push_back("2.2");
    vecinos.push_back("2.3");

    americaSur.push_back(
        Territorio("2.1", "Argentina", vecinos));

    vecinos.clear();

    // 2.2 Brasil

    vecinos.push_back("2.1");
    vecinos.push_back("2.3");
    vecinos.push_back("2.4");
    vecinos.push_back("4.5");

    americaSur.push_back(
        Territorio("2.2", "Brasil", vecinos));

    vecinos.clear();

    // 2.3 Peru

    vecinos.push_back("2.1");
    vecinos.push_back("2.2");
    vecinos.push_back("2.4");

    americaSur.push_back(
        Territorio("2.3", "Peru", vecinos));

    vecinos.clear();

    // 2.4 Venezuela

    vecinos.push_back("1.3");
    vecinos.push_back("2.2");
    vecinos.push_back("2.3");

    americaSur.push_back(
        Territorio("2.4", "Venezuela", vecinos));

    vecinos.clear();

    Continente continenteAmericaSur(
        "America del Sur", americaSur, 2);

    continentes.push_back(continenteAmericaSur);

    // EUROPA

    vector<Territorio> europa;

    // 3.1 Gran Bretana

    vecinos.push_back("3.2");
    vecinos.push_back("3.3");
    vecinos.push_back("3.4");
    vecinos.push_back("3.7");

    europa.push_back(
        Territorio("3.1", "Gran Bretana", vecinos));

    vecinos.clear();

    // 3.2 Islandia

    vecinos.push_back("1.5");
    vecinos.push_back("3.1");
    vecinos.push_back("3.4");

    europa.push_back(
        Territorio("3.2", "Islandia", vecinos));

    vecinos.clear();

    // 3.3 Europa del Norte

    vecinos.push_back("3.1");
    vecinos.push_back("3.4");
    vecinos.push_back("3.5");
    vecinos.push_back("3.6");
    vecinos.push_back("3.7");

    europa.push_back(
        Territorio("3.3", "Europa del Norte", vecinos));

    vecinos.clear();

    // 3.4 Escandinavia

    vecinos.push_back("3.1");
    vecinos.push_back("3.2");
    vecinos.push_back("3.3");
    vecinos.push_back("3.6");

    europa.push_back(
        Territorio("3.4", "Escandinavia", vecinos));

    vecinos.clear();

    // 3.5 Europa del Sur

    vecinos.push_back("3.3");
    vecinos.push_back("3.6");
    vecinos.push_back("3.7");
    vecinos.push_back("4.3");
    vecinos.push_back("4.5");
    vecinos.push_back("5.7");

    europa.push_back(
        Territorio("3.5", "Europa del Sur", vecinos));

    vecinos.clear();

    // 3.6 Ucrania

    vecinos.push_back("3.3");
    vecinos.push_back("3.4");
    vecinos.push_back("3.5");
    vecinos.push_back("5.1");
    vecinos.push_back("5.7");
    vecinos.push_back("5.11");

    europa.push_back(
        Territorio("3.6", "Ucrania", vecinos));

    vecinos.clear();

    // 3.7 Europa Occidental

    vecinos.push_back("3.1");
    vecinos.push_back("3.3");
    vecinos.push_back("3.5");
    vecinos.push_back("4.5");

    europa.push_back(
        Territorio("3.7", "Europa Occidental", vecinos));

    vecinos.clear();

    Continente continenteEuropa(
        "Europa", europa, 5);

    continentes.push_back(continenteEuropa);



    // AFRICA

    vector<Territorio> africa;

    // 4.1 Congo

    vecinos.push_back("4.2");
    vecinos.push_back("4.5");
    vecinos.push_back("4.6");

    africa.push_back(
        Territorio("4.1", "Congo", vecinos));

    vecinos.clear();

    // 4.2 Africa Oriental

    vecinos.push_back("4.1");
    vecinos.push_back("4.3");
    vecinos.push_back("4.4");
    vecinos.push_back("4.5");
    vecinos.push_back("4.6");
    vecinos.push_back("5.7");

    africa.push_back(
        Territorio("4.2", "Africa Oriental", vecinos));

    vecinos.clear();

    // 4.3 Egipto

    vecinos.push_back("3.5");
    vecinos.push_back("4.2");
    vecinos.push_back("4.5");
    vecinos.push_back("5.7");

    africa.push_back(
        Territorio("4.3", "Egipto", vecinos));

    vecinos.clear();

    // 4.4 Madagascar

    vecinos.push_back("4.2");
    vecinos.push_back("4.6");

    africa.push_back(
        Territorio("4.4", "Madagascar", vecinos));

    vecinos.clear();

    // 4.5 Africa del Norte

    vecinos.push_back("2.2");
    vecinos.push_back("3.5");
    vecinos.push_back("3.7");
    vecinos.push_back("4.1");
    vecinos.push_back("4.2");
    vecinos.push_back("4.3");

    africa.push_back(
        Territorio("4.5", "Africa del Norte", vecinos));

    vecinos.clear();

    // 4.6 Africa del Sur

    vecinos.push_back("4.1");
    vecinos.push_back("4.2");
    vecinos.push_back("4.4");

    africa.push_back(
        Territorio("4.6", "Africa del Sur", vecinos));

    vecinos.clear();

    Continente continenteAfrica(
        "Africa", africa, 3);

    continentes.push_back(continenteAfrica);



    // ASIA

    vector<Territorio> asia;

    // 5.1 Afghanistan

    vecinos.push_back("3.6");
    vecinos.push_back("5.2");
    vecinos.push_back("5.3");
    vecinos.push_back("5.7");
    vecinos.push_back("5.11");

    asia.push_back(
        Territorio("5.1", "Afghanistan", vecinos));

    vecinos.clear();

    // 5.2 China

    vecinos.push_back("5.1");
    vecinos.push_back("5.3");
    vecinos.push_back("5.8");
    vecinos.push_back("5.9");
    vecinos.push_back("5.10");
    vecinos.push_back("5.11");

    asia.push_back(
        Territorio("5.2", "China", vecinos));

    vecinos.clear();

    // 5.3 India

    vecinos.push_back("5.1");
    vecinos.push_back("5.2");
    vecinos.push_back("5.7");
    vecinos.push_back("5.9");

    asia.push_back(
        Territorio("5.3", "India", vecinos));

    vecinos.clear();

    // 5.4 Irkutsk

    vecinos.push_back("5.6");
    vecinos.push_back("5.8");
    vecinos.push_back("5.10");
    vecinos.push_back("5.12");

    asia.push_back(
        Territorio("5.4", "Irkutsk", vecinos));

    vecinos.clear();

    // 5.5 Japon

    vecinos.push_back("5.6");
    vecinos.push_back("5.8");

    asia.push_back(
        Territorio("5.5", "Japon", vecinos));

    vecinos.clear();

    // 5.6 Kamchatka

    vecinos.push_back("1.1");
    vecinos.push_back("5.4");
    vecinos.push_back("5.5");
    vecinos.push_back("5.8");
    vecinos.push_back("5.12");

    asia.push_back(
        Territorio("5.6", "Kamchatka", vecinos));

    vecinos.clear();

    // 5.7 Medio Oriente

    vecinos.push_back("3.5");
    vecinos.push_back("3.6");
    vecinos.push_back("4.2");
    vecinos.push_back("4.3");
    vecinos.push_back("5.1");
    vecinos.push_back("5.3");

    asia.push_back(
        Territorio("5.7", "Medio Oriente", vecinos));

    vecinos.clear();

    // 5.8 Mongolia

    vecinos.push_back("5.2");
    vecinos.push_back("5.4");
    vecinos.push_back("5.5");
    vecinos.push_back("5.6");
    vecinos.push_back("5.10");

    asia.push_back(
        Territorio("5.8", "Mongolia", vecinos));

    vecinos.clear();

    // 5.9 Siam

    vecinos.push_back("5.2");
    vecinos.push_back("5.3");
    vecinos.push_back("6.2");

    asia.push_back(
        Territorio("5.9", "Siam", vecinos));

    vecinos.clear();

    // 5.10 Siberia

    vecinos.push_back("5.2");
    vecinos.push_back("5.4");
    vecinos.push_back("5.8");
    vecinos.push_back("5.11");
    vecinos.push_back("5.12");

    asia.push_back(
        Territorio("5.10", "Siberia", vecinos));

    vecinos.clear();

    // 5.11 Ural

    vecinos.push_back("3.6");
    vecinos.push_back("5.1");
    vecinos.push_back("5.2");
    vecinos.push_back("5.10");

    asia.push_back(
        Territorio("5.11", "Ural", vecinos));

    vecinos.clear();

    // 5.12 Yakutsk

    vecinos.push_back("5.4");
    vecinos.push_back("5.6");
    vecinos.push_back("5.10");

    asia.push_back(
        Territorio("5.12", "Yakutsk", vecinos));

    vecinos.clear();

    Continente continenteAsia(
        "Asia", asia, 7);

    continentes.push_back(continenteAsia);



    // AUSTRALIA

    vector<Territorio> australia;

    // 6.1 Australia Oriental

    vecinos.push_back("6.3");
    vecinos.push_back("6.4");

    australia.push_back(
        Territorio("6.1", "Australia Oriental", vecinos));

    vecinos.clear();

    // 6.2 Indonesia

    vecinos.push_back("5.9");
    vecinos.push_back("6.3");
    vecinos.push_back("6.4");

    australia.push_back(
        Territorio("6.2", "Indonesia", vecinos));

    vecinos.clear();

    // 6.3 Nueva Guinea

    vecinos.push_back("6.1");
    vecinos.push_back("6.2");
    vecinos.push_back("6.4");

    australia.push_back(
        Territorio("6.3", "Nueva Guinea", vecinos));

    vecinos.clear();

    // 6.4 Australia Occidental

    vecinos.push_back("6.1");
    vecinos.push_back("6.2");
    vecinos.push_back("6.3");

    australia.push_back(
        Territorio("6.4", "Australia Occidental", vecinos));

    vecinos.clear();

    Continente continenteAustralia(
        "Australia", australia, 2);

    continentes.push_back(continenteAustralia);
}
vector<Continente> Tablero::consultarContinentes(){
    return continentes;
}

bool Tablero::existeTerritorio(string codigo){
    for(int i = 0; i < continentes.size(); i++){
        if(continentes[i].contieneTerritorio(codigo)){
            return true;
        }
    }
    return false;
}

Territorio& Tablero::buscarTerritorio(string codigo){
    for(int i = 0; i < continentes.size(); i++){
        if(continentes[i].contieneTerritorio(codigo)){
            return continentes[i].buscarTerritorio(codigo);
        }
    }
    return continentes[0].buscarTerritorio(codigo);
}

void Tablero::asignarOcupacionInicial(string codigo, string color, int unidades){
    Territorio& territorio = buscarTerritorio(codigo);
    territorio.asignarPropietario(color);
    territorio.agregarUnidades(unidades);
}

int Tablero::contarTerritoriosDeJugador(string color){
    int contador = 0;

    for(int i = 0; i < continentes.size(); i++){
        contador += continentes[i].contarTerritoriosDeJugador(color);
    }

    return contador;
}

int Tablero::calcularBonificacionPorContinentes(string color){
    int bonificacion = 0;

    for(int i = 0; i < continentes.size(); i++){
        if(continentes[i].esControladoPor(color)){
            bonificacion += continentes[i].consultarBonificacion();
        }
    }

    return bonificacion;
}

bool Tablero::controlaTodoElTablero(string color){
    return contarTerritoriosDeJugador(color) == 42;
}

void Tablero::mostrarTerritorios(){
    for(int i = 0; i < continentes.size(); i++){

        vector<Territorio> territorios = continentes[i].consultarTerritorios();

        for(int j = 0; j < territorios.size(); j++){
            cout << "Codigo: " << territorios[j].consultarCodigo() << endl;
            cout << "Nombre: " << territorios[j].consultarNombre() << endl;
            cout << "Propietario: " << territorios[j].consultarColorPropietario() << endl;
            cout << "Unidades: " << territorios[j].consultarUnidades() << endl;
            cout << endl;
        }
    }
}