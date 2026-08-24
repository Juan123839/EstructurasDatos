/**
 * @file main.cxx
 * @brief Programa principal del simulador de batallas Pokemon.
 *
 * El programa carga los entrenadores desde un archivo de texto y luego
 * ejecuta las batallas y comparaciones indicadas en un segundo archivo.
 *
 * Curso: Estructuras de Datos
 * Autor: Alejandro Castro Martinez
 * Fecha: 13 de agosto de 2026
 */

#include "BattleSimulator.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

/**
 * @brief Convierte el nombre de un tipo en su valor PokemonType.
 *
 * Se asume que el tipo almacenado en el archivo esta correctamente escrito.
 *
 * @param typeName Nombre del tipo en ingles.
 * @return Tipo de Pokemon correspondiente.
 */
PokemonType stringToPokemonType(const std::string &typeName)
{
    if (typeName == "FIRE")
    {
        return PokemonType::FIRE;
    }

    if (typeName == "WATER")
    {
        return PokemonType::WATER;
    }

    if (typeName == "GRASS")
    {
        return PokemonType::GRASS;
    }

    if (typeName == "ELECTRIC")
    {
        return PokemonType::ELECTRIC;
    }

    if (typeName == "GROUND")
    {
        return PokemonType::GROUND;
    }

    return PokemonType::FLYING;
}

/**
 * @brief Lee los Pokemon pertenecientes a un equipo.
 *
 * La lectura finaliza cuando se encuentra la instruccion END_TEAM.
 *
 * @param inputFile Archivo de entrenadores que se esta procesando.
 * @param team Equipo donde se almacenaran los Pokemon.
 * @return true si el equipo fue leido completamente; false si ocurrio un error.
 */
bool loadTeam(std::ifstream &inputFile, Team &team)
{
    std::string line;

    while (getline(inputFile, line))
    {
        if (line.empty())
        {
            continue;
        }

        std::istringstream lineStream(line);
        std::string instruction;

        lineStream >> instruction;

        if (instruction == "END_TEAM")
        {
            return true;
        }

        if (instruction != "POKEMON")
        {
            std::cerr << "Error: se esperaba POKEMON o END_TEAM.\n";
            return false;
        }

        std::string pokemonName;
        std::string typeName;
        int maximumHealth;
        int attack;
        int defense;
        int speed;

        if (!(lineStream >> pokemonName >> typeName >> maximumHealth >> attack >> defense >> speed))
        {
            std::cerr
                << "Error: no fue posible leer los datos del Pokemon.\n";
            return false;
        }

        Pokemon pokemon(
            pokemonName,
            stringToPokemonType(typeName),
            maximumHealth,
            attack,
            defense,
            speed);

        unsigned int position = team.getPokemonCount();

        if (!team.addPokemon(pokemon, position))
        {
            std::cerr
                << "Error: no fue posible agregar el Pokemon "
                << pokemonName << " al equipo "
                << team.getName() << ".\n";
            return false;
        }
    }

    std::cerr
        << "Error: no se encontro END_TEAM para el equipo "
        << team.getName() << ".\n";
    return false;
}

/**
 * @brief Lee los equipos pertenecientes a un entrenador.
 *
 * La lectura finaliza cuando se encuentra la instruccion END_TRAINER.
 *
 * @param inputFile Archivo de entrenadores que se esta procesando.
 * @param trainer Entrenador donde se almacenaran los equipos.
 * @return true si el entrenador fue leido completamente; false si hay error.
 */
bool loadTrainer(std::ifstream &inputFile, Trainer &trainer)
{
    std::string line;

    while (getline(inputFile, line))
    {
        if (line.empty())
        {
            continue;
        }

        std::istringstream lineStream(line);
        std::string instruction;

        lineStream >> instruction;

        if (instruction == "END_TRAINER")
        {
            return true;
        }

        if (instruction != "TEAM")
        {
            std::cerr << "Error: se esperaba TEAM o END_TRAINER.\n";
            return false;
        }

        std::string teamName;

        if (!(lineStream >> teamName))
        {
            std::cerr
                << "Error: no fue posible leer el nombre del equipo.\n";
            return false;
        }

        Team team(teamName);

        if (!loadTeam(inputFile, team))
        {
            return false;
        }

        if (!trainer.addTeam(team))
        {
            std::cerr
                << "Error: no fue posible agregar el equipo "
                << teamName << " al entrenador "
                << trainer.getName() << ".\n";
            return false;
        }
    }

    std::cerr
        << "Error: no se encontro END_TRAINER para el entrenador "
        << trainer.getName() << ".\n";
    return false;
}

/**
 * @brief Carga todos los entrenadores desde un archivo de texto.
 *
 * @param fileName Nombre del archivo de entrenadores.
 * @param simulator Simulador donde se almacenaran los entrenadores.
 * @return true si el archivo fue procesado; false en caso de error.
 */
bool loadTrainers(
    const std::string &fileName,
    BattleSimulator &simulator)
{
    std::ifstream inputFile(fileName);

    if (!inputFile.is_open())
    {
        std::cerr
            << "Error: no fue posible abrir el archivo "
            << fileName << ".\n";
        return false;
    }

    std::string line;

    while (getline(inputFile, line))
    {
        if (line.empty())
        {
            continue;
        }

        std::istringstream lineStream(line);
        std::string instruction;
        std::string trainerName;

        lineStream >> instruction;

        if (instruction != "TRAINER")
        {
            std::cerr << "Error: se esperaba la instruccion TRAINER.\n";
            return false;
        }

        if (!(lineStream >> trainerName))
        {
            std::cerr
                << "Error: no fue posible leer el nombre del entrenador.\n";
            return false;
        }

        Trainer trainer(trainerName);

        if (!loadTrainer(inputFile, trainer))
        {
            return false;
        }

        if (!simulator.addTrainer(trainer))
        {
            std::cerr
                << "Error: no fue posible agregar el entrenador "
                << trainerName << ".\n";
            return false;
        }
    }

    inputFile.close();
    return true;
}

/**
 * @brief Ejecuta una instruccion BATTLE e imprime su desarrollo.
 *
 * @param lineStream Linea desde donde se leen los nombres.
 * @param simulator Simulador que ejecutara la batalla.
 * @return true si la batalla fue ejecutada; false en caso contrario.
 */
bool executeBattleInstruction(
    std::istringstream &lineStream,
    BattleSimulator &simulator)
{
    std::string firstTrainerName;
    std::string firstTeamName;
    std::string secondTrainerName;
    std::string secondTeamName;

    if (!(lineStream >> firstTrainerName >> firstTeamName >> secondTrainerName >> secondTeamName))
    {
        std::cerr
            << "Error: no fue posible leer la instruccion BATTLE.\n";
        return false;
    }

    if (!simulator.executeBattle(
            firstTrainerName,
            firstTeamName,
            secondTrainerName,
            secondTeamName))
    {
        std::cerr
            << "Error: no fue posible ejecutar la batalla entre "
            << firstTeamName << " y " << secondTeamName << ".\n";
        return false;
    }

    unsigned int lastBattlePosition = simulator.getBattleCount() - 1;

    simulator.getBattle(lastBattlePosition).printBattleHistory();
    return true;
}

/**
 * @brief Imprime los mejores equipos de un entrenador.
 *
 * @param simulator Simulador que contiene los resultados.
 * @param trainerName Nombre del entrenador consultado.
 */
void printBestTeams(
    const BattleSimulator &simulator,
    const std::string &trainerName)
{
    std::vector<std::string> bestTeams =
        simulator.getBestTeams(trainerName);

    std::cout << "\nMejores equipos de " << trainerName << ":\n";

    std::vector<std::string>::const_iterator position = bestTeams.begin();

    while (position != bestTeams.end())
    {
        std::cout << "- " << *position << '\n';
        ++position;
    }
}

/**
 * @brief Ejecuta una instruccion COMPARE e imprime sus resultados.
 *
 * @param lineStream Linea desde donde se leen los entrenadores.
 * @param simulator Simulador que realizara la comparacion.
 * @return true si la comparacion fue ejecutada; false en caso contrario.
 */
bool executeComparisonInstruction(
    std::istringstream &lineStream,
    BattleSimulator &simulator)
{
    std::string firstTrainerName;
    std::string secondTrainerName;

    if (!(lineStream >> firstTrainerName >> secondTrainerName))
    {
        std::cerr
            << "Error: no fue posible leer la instruccion COMPARE.\n";
        return false;
    }

    if (!simulator.compareTrainers(
            firstTrainerName,
            secondTrainerName))
    {
        std::cerr
            << "Error: no fue posible comparar a "
            << firstTrainerName << " y " << secondTrainerName << ".\n";
        return false;
    }

    std::cout << '\n';
    simulator.printComparisonResults();
    printBestTeams(simulator, firstTrainerName);
    printBestTeams(simulator, secondTrainerName);
    return true;
}



/**
 * @brief Ejecuta una instruccion PRINT e imprime los entrenadores guardados.
 *
 * @param lineStream Linea desde donde se leen los entrenadores.
 * @param simulator Simulador que realizara la comparacion.
 * @return true si la comparacion fue ejecutada; false en caso contrario.
 */
bool executePrintInstruction(
    std::istringstream &lineStream,
    BattleSimulator &simulator)
{
    simulator.printTrainers();
    std::cout << '\n';
    return true;
}

/**
 * @brief Procesa las operaciones almacenadas en un archivo.
 *
 * La lectura se detiene inmediatamente si una operacion no puede ejecutarse.
 *
 * @param fileName Nombre del archivo de operaciones.
 * @param simulator Simulador que ejecutara las instrucciones.
 * @return true si todas fueron ejecutadas; false si ocurrio un error.
 */
bool executeOperations(
    const std::string &fileName,
    BattleSimulator &simulator)
{
    std::ifstream inputFile(fileName);

    if (!inputFile.is_open())
    {
        std::cerr
            << "Error: no fue posible abrir el archivo "
            << fileName << ".\n";
        return false;
    }

    std::string line;

    while (getline(inputFile, line))
    {
        if (line.empty())
        {
            continue;
        }

        std::istringstream lineStream(line);
        std::string instruction;

        lineStream >> instruction;

        if (instruction == "BATTLE")
        {
            if (!executeBattleInstruction(lineStream, simulator))
            {
                return false;
            }
        }
        else if (instruction == "COMPARE")
        {
            if (!executeComparisonInstruction(lineStream, simulator))
            {
                return false;
            }
        }
        else if (instruction == "PRINT")
        {
            if (!executePrintInstruction(lineStream, simulator))
            {
                return false;
            }
        }
        else
        {
            std::cerr
                << "Error: instruccion desconocida: "
                << instruction << ".\n";
            return false;
        }
    }

    inputFile.close();
    return true;
}

/**
 * @brief Imprime un resumen de todas las batallas ejecutadas.
 *
 * Muestra los entrenadores, los equipos enfrentados y el ganador.
 *
 * @param simulator Simulador que contiene el historial.
 */
void printExecutedBattles(const BattleSimulator &simulator)
{
    std::cout << "\n==================================================\n";
    std::cout << "BATALLAS EJECUTADAS\n";
    std::cout << "==================================================\n";
    std::cout << "Se ejecutaron "
              << simulator.getBattleCount()
              << " batallas.\n\n";

    unsigned int position = 0;

    while (position < simulator.getBattleCount())
    {
        const Battle &battle = simulator.getBattle(position);

        std::cout << position + 1 << ". "
                  << battle.getFirstTrainerName()
                  << " - "
                  << battle.getFirstTeam().getName()
                  << " vs "
                  << battle.getSecondTrainerName()
                  << " - "
                  << battle.getSecondTeam().getName()
                  << " - Ganador: "
                  << battle.getWinnerTrainerName()
                  << " - "
                  << battle.getWinnerTeamName()
                  << '\n';

        ++position;
    }
}

/**
 * @brief Funcion principal del simulador.
 *
 * @return 0 si finaliza correctamente; 1 si ocurre un error.
 */
int main()
{
    BattleSimulator simulator;

    if (!loadTrainers("trainers.txt", simulator))
    {
        return 1;
    }

    bool operationsCompleted =
        executeOperations("operations.txt", simulator);

    /*
     * El resumen tambien se imprime cuando ocurre un error, mostrando las
     * batallas que alcanzaron a ejecutarse antes de detener la lectura.
     */
    printExecutedBattles(simulator);

    if (!operationsCompleted)
    {
        return 1;
    }

    return 0;
}
