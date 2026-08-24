/**
 * @file Battle.cxx
 * @brief Implementación del Tipo Abstracto de Datos Battle.
 *
 * Curso: Estructuras de Datos
 * Autor: Alejandro Castro Martínez
 * Fecha: 12 de agosto de 2026
 */

#include "Battle.h"

#include <iostream>
#include <list>

// Construye la batalla con copias de los dos equipos participantes.
Battle::Battle(
    const std::string &trainerOneName,
    const Team &teamOne,
    const std::string &trainerTwoName,
    const Team &teamTwo) : firstTrainerName(trainerOneName),
                           secondTrainerName(trainerTwoName),
                           firstTeam(teamOne),
                           secondTeam(teamTwo),
                           winnerTeamName(""),
                           winnerTrainerName(""),
                           finished(false)
{
}

// Retorna el nombre del entrenador propietario del primer equipo.
const std::string &Battle::getFirstTrainerName() const
{
    return firstTrainerName;
}

// Retorna el nombre del entrenador propietario del segundo equipo.
const std::string &Battle::getSecondTrainerName() const
{
    return secondTrainerName;
}

// Retorna el primer equipo para consultar su estado durante la batalla.
const Team &Battle::getFirstTeam() const
{
    return firstTeam;
}

// Retorna el segundo equipo para consultar su estado durante la batalla.
const Team &Battle::getSecondTeam() const
{
    return secondTeam;
}

// Indica si la batalla ya fue ejecutada y finalizada.
bool Battle::isFinished() const
{
    return finished;
}

// Retorna el nombre del equipo ganador o una cadena vacía si aún no existe.
const std::string &Battle::getWinnerTeamName() const
{
    return winnerTeamName;
}

// Retorna el nombre del entrenador propietario del equipo ganador.
const std::string &Battle::getWinnerTrainerName() const
{
    return winnerTrainerName;
}

// Retorna el historial completo sin permitir que sea modificado externamente.
const std::deque<std::string> &Battle::getBattleHistory() const
{
    return battleHistory;
}

// Retorna la efectividad del tipo atacante frente al tipo defensor.
double Battle::getTypeMultiplier(
    PokemonType attackerType,
    PokemonType defenderType) const
{
    //TODO #05 (Analizar la efectividad entre los tipos de Pokemon)
    /*
     * Esta funcion se entrega completamente implementada y no debe ser
     * modificada.
     *
     * Analice cada una de sus condiciones e identifique como cambia el
     * multiplicador de acuerdo con el tipo del atacante y del defensor.
     *
     * En el reporte, construya un diagrama dirigido que incluya todos los
     * tipos utilizados por el simulador. Cada relacion debe indicar el
     * multiplicador que retorna la funcion. Incluya tambien una explicacion
     * para las combinaciones que no aparecen expresamente en las condiciones.
     *
     * Explique por que la relacion debe analizarse desde el tipo atacante
     * hacia el tipo defensor y por que invertir ambos tipos puede producir
     * un resultado diferente.
     *
     * Finalmente, describa como el valor retornado por esta funcion influye
     * en calculateDamage() y, posteriormente, en la salud del defensor.
     */

    if (attackerType == PokemonType::FIRE)
    {
        if (defenderType == PokemonType::GRASS)
        {
            return 2.0;
        }
        if (defenderType == PokemonType::WATER)
        {
            return 0.5;
        }
    }

    if (attackerType == PokemonType::WATER)
    {
        if (defenderType == PokemonType::FIRE ||
            defenderType == PokemonType::GROUND)
        {
            return 2.0;
        }
        if (defenderType == PokemonType::GRASS ||
            defenderType == PokemonType::ELECTRIC)
        {
            return 0.5;
        }
    }

    if (attackerType == PokemonType::GRASS)
    {
        if (defenderType == PokemonType::WATER ||
            defenderType == PokemonType::GROUND)
        {
            return 2.0;
        }
        if (defenderType == PokemonType::FIRE ||
            defenderType == PokemonType::FLYING)
        {
            return 0.5;
        }
    }

    if (attackerType == PokemonType::ELECTRIC)
    {
        if (defenderType == PokemonType::WATER ||
            defenderType == PokemonType::FLYING)
        {
            return 2.0;
        }
        if (defenderType == PokemonType::GROUND)
        {
            return 0.5;
        }
    }

    if (attackerType == PokemonType::GROUND)
    {
        if (defenderType == PokemonType::FIRE ||
            defenderType == PokemonType::ELECTRIC)
        {
            return 2.0;
        }
        if (defenderType == PokemonType::WATER ||
            defenderType == PokemonType::GRASS)
        {
            return 0.5;
        }
    }

    if (attackerType == PokemonType::FLYING)
    {
        if (defenderType == PokemonType::GRASS)
        {
            return 2.0;
        }
        if (defenderType == PokemonType::ELECTRIC)
        {
            return 0.5;
        }
    }

    return 1.0;
}

// Calcula el daño y garantiza que cada ataque cause al menos un punto.
int Battle::calculateDamage(
    const Pokemon &attacker,
    const Pokemon &defender) const
{
    double typeMultiplier = getTypeMultiplier(
        attacker.getType(),
        defender.getType());

    double calculatedDamage =
        attacker.getAttack() * typeMultiplier - defender.getDefense() / 2.0;

    int damage = static_cast<int>(calculatedDamage);

    if (damage < 1)
    {
        damage = 1;
    }

    return damage;
}

// Ejecuta un ataque y registra el ataque y un posible debilitamiento.
void Battle::executeAttack(
    Pokemon &attacker,
    Pokemon &defender)
{
    int damage = calculateDamage(attacker, defender); //funcion de calcular el daño
    defender.receiveDamage(damage); //se aplica el daño al defensor
    battleHistory.push_back( //Registra el ataque al historial
        attacker.getName() + " ataco a " +
        defender.getName() + " causando " +
        std::to_string(damage) + " damage."
    );
    if (defender.isFainted()) { // se comprueba si el defensor quedo debilitado
        battleHistory.push_back(
            defender.getName() + " fue debilitado"
        );
    }
    //TODO #06 (Ejecutar y registrar el ataque de un Pokemon)
    /*
     * Aplique el daño calculado al defensor mediante la operacion publica
     * correspondiente del TAD Pokemon. El atacante no debe ser modificado.
     */
}

// Ejecuta rondas hasta que uno de los equipos no tenga Pokémon disponibles.
bool Battle::runBattle()
{
    //TODO #07 (Ejecutar completamente una batalla entre dos equipos)
    /*
     * Ejecute la batalla completa utilizando las operaciones disponibles en
     * Team, Pokemon y Battle. No implemente nuevamente la busqueda de Pokemon
     * ni el calculo del daño.
     *
     * Siga estas etapas:
     *
     * 1. Verifique si la batalla ya fue finalizada. En ese caso, no debe
     *    ejecutarse nuevamente y la funcion debe retornar false.
     *
     * 2. Compruebe el estado inicial de ambos equipos:
     *    - Si los dos estan derrotados, registre que la batalla termino sin
     *      ganador, marque la batalla como finalizada y retorne true.
     *    - Si solamente uno esta derrotado, asigne como ganador al equipo
     *      contrario y a su entrenador. Registre el ganador, marque la
     *      batalla como finalizada y retorne true.
     *
     * 3. Mientras ambos equipos tengan Pokemon disponibles:
     *    - Obtenga un iterador modificable al primer Pokemon disponible de
     *      cada equipo.
     *    - Compare sus velocidades para decidir el orden de ataque.
     *    - Si las velocidades son iguales, el Pokemon del primer equipo debe
     *      atacar primero.
     *    - Ejecute el primer ataque utilizando executeAttack().
     *    - Permita el contraataque solamente si el Pokemon que recibio el
     *      primer ataque no fue debilitado.
     *
     * 4. Al comenzar una nueva iteracion, vuelva a solicitar el primer
     *    Pokemon disponible de cada equipo. De esta forma, un Pokemon
     *    debilitado sera reemplazado por el siguiente integrante disponible.
     *
     * 5. Cuando uno de los equipos quede derrotado:
     *    - Asigne el nombre del equipo ganador.
     *    - Asigne el nombre de su entrenador.
     *    - Registre ambos nombres al final de battleHistory.
     *    - Marque la batalla como finalizada.
     *
     * La funcion debe retornar true cuando la batalla sea ejecutada y
     * finalizada, incluso cuando termine sin ganador. Solamente debe retornar
     * false cuando se intente ejecutar una batalla que ya habia finalizado.
     *
     * Todos los acontecimientos deben almacenarse cronologicamente. No
     * modifique directamente la salud de los Pokemon en esta funcion; cada
     * ataque debe realizarse mediante executeAttack().
     */

    return true;
}
// Restaura los equipos y elimina toda la información de la ejecución anterior.
void Battle::resetBattle()
{
    firstTeam.restoreTeam();
    secondTeam.restoreTeam();
    battleHistory.clear();
    winnerTeamName.clear();
    winnerTrainerName.clear();
    finished = false;
}

// Imprime los eventos almacenados en el orden en que ocurrieron.
void Battle::printBattleHistory() const
{
    std::cout << "==================================================\n";
    std::cout << "BATALLA: " << firstTeam.getName()
              << " VS " << secondTeam.getName() << '\n';
    std::cout << "==================================================\n";

    if (battleHistory.empty())
    {
        std::cout << "La batalla todavía no ha sido ejecutada.\n";
        return;
    }

    std::deque<std::string>::const_iterator eventPosition =
        battleHistory.begin();

    while (eventPosition != battleHistory.end())
    {
        std::cout << *eventPosition << '\n';
        ++eventPosition;
    }
}
