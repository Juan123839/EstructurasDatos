#include "../Include/Tablero.h"
using namespace std;
#include <stdexcept>
Tablero::Tablero(){
}
void Tablero::crearTablero(){
    continentes.clear();
    Continente americaNorte("America del Norte");    // crea los continentes
    Continente americaSur("America del Sur");
    Continente europa("Europa");
    Continente africa("Africa");
    Continente asia("Asia");
    Continente australia("Australia");

    Territorio alaska("AN1", "Alaska");// crea los territorios de america del norte
    Territorio noroeste("AN2", "Territorio del Noroeste");
    Territorio groenlandia("AN3", "Groenlandia");
    Territorio alberta("AN4", "Alberta");
    Territorio ontario("AN5", "Ontario");
    Territorio quebec("AN6", "Quebec");
    Territorio oeste("AN7", "Estados Unidos Occidental");
    Territorio este("AN8", "Estados Unidos Oriental");
    Territorio central("AN9", "America Central");
    americaNorte.agregarTerritorio(alaska);
    americaNorte.agregarTerritorio(noroeste);
    americaNorte.agregarTerritorio(groenlandia);
    americaNorte.agregarTerritorio(alberta);
    americaNorte.agregarTerritorio(ontario);
    americaNorte.agregarTerritorio(quebec);
    americaNorte.agregarTerritorio(oeste);
    americaNorte.agregarTerritorio(este);
    americaNorte.agregarTerritorio(central);
    
    Territorio venezuela("AS1", "Venezuela");// crea los territorios de america del sur
    Territorio brasil("AS2", "Brasil");
    Territorio peru("AS3", "Peru");
    Territorio argentina("AS4", "Argentina");
    americaSur.agregarTerritorio(venezuela);
    americaSur.agregarTerritorio(brasil);
    americaSur.agregarTerritorio(peru);
    americaSur.agregarTerritorio(argentina);
    
    Territorio islandia("EU1", "Islandia");// crea los territorios de europa
    Territorio escandinavia("EU2", "Escandinavia");
    Territorio ucrania("EU3", "Ucrania");
    Territorio granBretana("EU4", "Gran Bretana");
    Territorio europaOccidental("EU5", "Europa Occidental");
    Territorio europaNorte("EU6", "Europa del Norte");
    Territorio europaSur("EU7", "Europa del Sur");
    europa.agregarTerritorio(islandia);
    europa.agregarTerritorio(escandinavia);
    europa.agregarTerritorio(ucrania);
    europa.agregarTerritorio(granBretana);
    europa.agregarTerritorio(europaOccidental);
    europa.agregarTerritorio(europaNorte);
    europa.agregarTerritorio(europaSur);
    
    Territorio norteAfrica("AF1", "Africa del Norte");// crea los territorios de africa
    Territorio egipto("AF2", "Egipto");
    Territorio oriental("AF3", "Africa Oriental");
    Territorio congo("AF4", "Congo");
    Territorio surAfrica("AF5", "Africa del Sur");
    Territorio madagascar("AF6", "Madagascar");
    africa.agregarTerritorio(norteAfrica);
    africa.agregarTerritorio(egipto);
    africa.agregarTerritorio(oriental);
    africa.agregarTerritorio(congo);
    africa.agregarTerritorio(surAfrica);
    africa.agregarTerritorio(madagascar);
        
    Territorio ural("A1", "Ural");// crea los territorios de asia
    Territorio siberia("A2", "Siberia");
    Territorio yakutsk("A3", "Yakutsk");
    Territorio kamchatka("A4", "Kamchatka");
    Territorio japon("A5", "Japon");
    Territorio mongolia("A6", "Mongolia");
    Territorio china("A7", "China");
    Territorio india("A8", "India");
    Territorio medioOriente("A9", "Medio Oriente");
    Territorio afganistan("A10", "Afganistan");
    Territorio irkutsk("A11", "Irkutsk");
    Territorio siam("A12", "Siam");
    asia.agregarTerritorio(ural);
    asia.agregarTerritorio(siberia);
    asia.agregarTerritorio(yakutsk);
    asia.agregarTerritorio(kamchatka);
    asia.agregarTerritorio(japon);
    asia.agregarTerritorio(mongolia);
    asia.agregarTerritorio(china);
    asia.agregarTerritorio(india);
    asia.agregarTerritorio(medioOriente);
    asia.agregarTerritorio(afganistan);
    asia.agregarTerritorio(irkutsk);
    asia.agregarTerritorio(siam);
    
    Territorio indonesia("AU1", "Indonesia");// crea los territorios de australia
    Territorio nuevaGuinea("AU2", "Nueva Guinea");
    Territorio australiaOccidental("AU3", "Australia Occidental");
    Territorio australiaOriental("AU4", "Australia Oriental");
    australia.agregarTerritorio(indonesia);
    australia.agregarTerritorio(nuevaGuinea);
    australia.agregarTerritorio(australiaOccidental);
    australia.agregarTerritorio(australiaOriental);
    
    continentes.push_back(americaNorte);// agrega los continentes al tablero
    continentes.push_back(americaSur);
    continentes.push_back(europa);
    continentes.push_back(africa);
    continentes.push_back(asia);
    continentes.push_back(australia);
       
    conectarTerritorios("AN1", "AN2"); // conecta america del norte
    conectarTerritorios("AN1", "AN4");
    conectarTerritorios("AN1", "A4");
    conectarTerritorios("AN2", "AN3");
    conectarTerritorios("AN2", "AN4");
    conectarTerritorios("AN3", "AN6");
    conectarTerritorios("AN4", "AN5");
    conectarTerritorios("AN4", "AN7");
    conectarTerritorios("AN5", "AN6");
    conectarTerritorios("AN5", "AN7");
    conectarTerritorios("AN5", "AN8");
    conectarTerritorios("AN6", "AN8");
    conectarTerritorios("AN7", "AN8");
    conectarTerritorios("AN7", "AN9");
    conectarTerritorios("AN8", "AN9");
    
    conectarTerritorios("AS1", "AS2");// conecta america del sur
    conectarTerritorios("AS1", "AS3");
    conectarTerritorios("AS2", "AS3");
    conectarTerritorios("AS2", "AS4");
    conectarTerritorios("AS3", "AS4");
    
    conectarTerritorios("EU1", "EU2");// conecta europa
    conectarTerritorios("EU1", "AN3");
    conectarTerritorios("EU2", "EU3");
    conectarTerritorios("EU2", "EU6");
    conectarTerritorios("EU3", "EU6");
    conectarTerritorios("EU3", "EU7");
    conectarTerritorios("EU3", "A9");
    conectarTerritorios("EU4", "EU5");
    conectarTerritorios("EU4", "EU6");
    conectarTerritorios("EU5", "EU6");
    conectarTerritorios("EU5", "EU7");
    conectarTerritorios("EU7", "A9");
    
    conectarTerritorios("AF1", "AF2");// conecta africa
    conectarTerritorios("AF1", "AF3");
    conectarTerritorios("AF1", "EU7");
    conectarTerritorios("AF2", "AF3");
    conectarTerritorios("AF3", "AF4");
    conectarTerritorios("AF3", "AF5");
    conectarTerritorios("AF4", "AF5");
    conectarTerritorios("AF5", "AF6");
    conectarTerritorios("AF6", "AF3");
    
    conectarTerritorios("A1", "A2");// conecta asia
    conectarTerritorios("A1", "A10");
    conectarTerritorios("A2", "A3");
    conectarTerritorios("A2", "A11");
    conectarTerritorios("A3", "A4");
    conectarTerritorios("A3", "A11");
    conectarTerritorios("A4", "A5");
    conectarTerritorios("A4", "A6");
    conectarTerritorios("A5", "A6");
    conectarTerritorios("A6", "A7");
    conectarTerritorios("A7", "A8");
    conectarTerritorios("A7", "A10");
    conectarTerritorios("A8", "A9");
    conectarTerritorios("A8", "AU1");
    conectarTerritorios("A9", "A10");
    conectarTerritorios("A9", "EU3");
    conectarTerritorios("A11", "A12");
    conectarTerritorios("A12", "AU1");
    
    conectarTerritorios("AU1", "AU2");// conecta australia
    conectarTerritorios("AU2", "AU3");
    conectarTerritorios("AU2", "AU4");
    conectarTerritorios("AU3", "AU4");
}
list<Continente>& Tablero::consultarContinentes(){
    return continentes;
}
bool Tablero::existeTerritorio(string codigo) const{
    for(const Continente& continente : continentes){
        if(continente.contieneTerritorio(codigo)){
            return true;
        }
    }
    return false;
}
Territorio& Tablero::buscarTerritorio(string codigo){
    for(Continente& continente : continentes){
        list<Territorio>& territorios = continente.consultarTerritorios();
        for(Territorio& territorio : territorios){
            if(territorio.consultarCodigo() == codigo){
                return territorio;
            }
        }
    }
    throw runtime_error("Territorio no encontrado");
}
list<Territorio*> Tablero::consultarTerritorios(){
    list<Territorio*> resultado;
    for(Continente& continente : continentes){
        list<Territorio>& territorios = continente.consultarTerritorios();
        for(Territorio& territorio : territorios){
            resultado.push_back(&territorio);
        }
    }
    return resultado;
}
int Tablero::contarTerritoriosDe(string color) const{
    int contador = 0;
    for(const Continente& continente : continentes){
        contador += continente.contarTerritoriosDe(color);
    }
    return contador;
}
int Tablero::calcularBonificacionPorContinentes(string color) const{
    int bonificacion = 0;
    for(const Continente& continente : continentes){
        if(continente.esControladoPor(color)){
            bonificacion += continente.consultarBonificacion();
        }
    }
    return bonificacion;
}
bool Tablero::controlaTodoElTablero(string color) const{
    for(const Continente& continente : continentes){
        if(!continente.esControladoPor(color)){
            return false;
        }
    }
    return true;
}
void Tablero::conectarTerritorios(string codigo1, string codigo2)
{
    Territorio& territorio1 = buscarTerritorio(codigo1);
    Territorio& territorio2 = buscarTerritorio(codigo2);
    territorio1.agregarVecino(codigo2);
    territorio2.agregarVecino(codigo1);
}