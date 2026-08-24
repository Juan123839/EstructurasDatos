/**
 * @file Team.cxx
 * @brief Implementación del Tipo Abstracto de Datos Team.
 *
 * Curso: Estructuras de Datos
 * Autor: Alejandro Castro Martínez
 * Fecha: 12 de agosto de 2026
 */

#include "Team.h"

#include <iostream>

// Inicializa el límite compartido por todos los equipos.
unsigned int Team::maxPokemon = 6;

// Construye un equipo vacío con el nombre recibido.
Team::Team(const std::string& teamName)
    : name(teamName) {
}

// Retorna el nombre que identifica al equipo.
const std::string& Team::getName() const {
    return name;
}

// Retorna la cantidad actual de Pokémon del equipo.
unsigned int Team::getPokemonCount() const {
    return static_cast<unsigned int>(pokemonList.size());
}

// Determina si la lista de Pokémon está vacía.
bool Team::isEmpty() const {
    return pokemonList.empty();
}

// Determina si el equipo alcanzó la cantidad máxima de Pokémon.
bool Team::isFull() const {
    return getPokemonCount() >= maxPokemon;
}

// Retorna el final de la lista para representar una búsqueda fallida.
std::list<Pokemon>::iterator Team::getNotFoundPosition() {
    return pokemonList.end();
}

// Retorna el final constante de la lista para búsquedas de solo consulta.
std::list<Pokemon>::const_iterator Team::getNotFoundPosition() const {
    return pokemonList.end();
}

// Busca un Pokémon y retorna un iterador que permite modificarlo.
std::list<Pokemon>::iterator Team::findPokemon(
    const std::string& pokemonName
) {
    std::list<Pokemon>::iterator pos = pokemonList.begin();//iterador

    while (pos != pokemonList.end()) { //recorrer todo
        if (pos->getName() == pokemonName) { //comparar
            return pos;
        }

        ++pos;
    }

    return getNotFoundPosition();
}

// Busca un Pokémon y retorna un iterador que solo permite consultarlo.
std::list<Pokemon>::const_iterator Team::findPokemon(
    const std::string& pokemonName
) const {

    std::list<Pokemon>::const_iterator pos = pokemonList.begin();

    while (pos != pokemonList.end()) { //recorrer
        if (pos->getName() == pokemonName) { //comparar
            return pos;
        }

        ++pos;
    }
    //la diferencia aca es que en TODO #1 es std::list<Pokemon>::iterator y en este es std::list<Pokemon>::const_iterator. Este const_iterador solo permite consultar mas no modificar. En cambio el anterior si permitia tanto consultar como modificar.

    return getNotFoundPosition();
}

// Comprueba si ya existe un Pokémon con el nombre recibido.
bool Team::containsPokemon(const std::string& pokemonName) const {
    return findPokemon(pokemonName) != getNotFoundPosition();
}

// Inserta un Pokémon en una posición válida de la lista.
bool Team::addPokemon(
    const Pokemon& pokemon,
    unsigned int position
) {
    if (isFull()) { //no este lleno
    return false;
    }
    if (containsPokemon(pokemon.getName())) {//no haya otro con el mismo name
        return false;
    }   
    if (position > getPokemonCount()) {//Comprobar posicion valida
        return false;
    }
    std::list<Pokemon>::iterator itpos1 = pokemonList.begin();//iterador
    unsigned int itposa = 0;

    while (itposa < position) { //avanza el iterador hasta donde se indique
        ++itpos1;
        ++itposa;
    }
    pokemonList.insert(itpos1, pokemon); //se inserta el pokemon en la posicion indicada
    return true;
}

// Elimina un Pokémon cuando su nombre se encuentra en el equipo.
bool Team::removePokemon(const std::string& pokemonName) {
    std::list<Pokemon>::iterator pokemonPosition = findPokemon(pokemonName);

    if (pokemonPosition == getNotFoundPosition()) {
        return false;
    }

    pokemonList.erase(pokemonPosition);
    return true;
}

// Extrae un Pokémon y lo inserta nuevamente en la posición solicitada.
bool Team::changePokemonPosition(
    const std::string& pokemonName,
    unsigned int newPosition
) {
    if (newPosition >= getPokemonCount()) {
        return false;
    }

    std::list<Pokemon>::iterator pokemonPosition = findPokemon(pokemonName);

    if (pokemonPosition == getNotFoundPosition()) {
        return false;
    }

    Pokemon pokemonToMove = *pokemonPosition;
    pokemonList.erase(pokemonPosition);

    std::list<Pokemon>::iterator insertionPosition = pokemonList.begin();
    unsigned int currentPosition = 0;

    while (currentPosition < newPosition) {
        ++insertionPosition;
        ++currentPosition;
    }

    pokemonList.insert(insertionPosition, pokemonToMove);
    return true;
}

// Restaura la salud de todos los Pokémon almacenados.
void Team::restoreTeam() {
    std::list<Pokemon>::iterator pokemonPosition = pokemonList.begin();

    while (pokemonPosition != pokemonList.end()) {
        pokemonPosition->restoreHealth();
        ++pokemonPosition;
    }
}

// Comprueba si no queda ningún Pokémon con puntos de salud.
bool Team::isDefeated() const {
    
    std::list<Pokemon>::const_iterator pos = getFirstAvailablePokemon();// busca el primer Pokemon que todavia tiene puntos de salud y puede combatir


    return pos == getNotFoundPosition(); // si no encuentra ninguno es xq todos estan debilitados o el equipo esta vacio
}

// Retorna el primer Pokémon ordenado que todavía conserva puntos de salud.
std::list<Pokemon>::iterator Team::getFirstAvailablePokemon() {
    std::list<Pokemon>::iterator pokemonPosition = pokemonList.begin();

    while (pokemonPosition != pokemonList.end()) {
        if (!pokemonPosition->isFainted()) {
            return pokemonPosition;
        }

        ++pokemonPosition;
    }

    return getNotFoundPosition();
}

// Retorna para consulta el primer Pokémon que conserva puntos de salud.
std::list<Pokemon>::const_iterator Team::getFirstAvailablePokemon() const {
    std::list<Pokemon>::const_iterator pokemonPosition = pokemonList.begin();

    while (pokemonPosition != pokemonList.end()) {
        if (!pokemonPosition->isFainted()) {
            return pokemonPosition;
        }

        ++pokemonPosition;
    }

    return getNotFoundPosition();
}

// Imprime el nombre del equipo y las tarjetas de sus Pokémon en orden.
void Team::print() const {
    std::cout << "==================================================\n";
    std::cout << "EQUIPO: " << name << '\n';
    std::cout << "Cantidad de Pokemon: " << getPokemonCount()
              << " / " << maxPokemon << '\n';
    std::cout << "==================================================\n";

    if (isEmpty()) {
        std::cout << "El equipo no contiene Pokemon.\n";
        return;
    }

    std::list<Pokemon>::const_iterator pokemonPosition = pokemonList.begin();
    unsigned int position = 0;

    while (pokemonPosition != pokemonList.end()) {
        std::cout << "\nPosicion " << position << '\n';
        pokemonPosition->print();

        ++pokemonPosition;
        ++position;
    }
}
