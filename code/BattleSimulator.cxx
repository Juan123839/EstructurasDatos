/**
 * @file BattleSimulator.cxx
 * @brief Implementación del Tipo Abstracto de Datos BattleSimulator.
 *
 * Curso: Estructuras de Datos
 * Autor: Alejandro Castro Martínez
 * Fecha: 12 de agosto de 2026
 */

#include "BattleSimulator.h"

#include <iomanip>
#include <iostream>

// Construye un simulador sin entrenadores, batallas ni resultados.
BattleSimulator::BattleSimulator() {
}

// Retorna la cantidad de entrenadores registrados.
unsigned int BattleSimulator::getTrainerCount() const {
    return trainerList.size();
}

// Retorna la cantidad de batallas conservadas en el historial.
unsigned int BattleSimulator::getBattleCount() const {
    return battleHistory.size();
}

// Determina si todavía no se han registrado entrenadores.
bool BattleSimulator::isEmpty() const {
    return trainerList.empty();
}

// Busca un entrenador y retorna su posición dentro del vector.
int BattleSimulator::findTrainer(const std::string& trainerName) const {

    std::vector<Trainer>::const_iterator trainerPosition =
        trainerList.begin();

    int position = 0;

    while (trainerPosition != trainerList.end()) {

        if (trainerPosition->getName() == trainerName) {
            return position;
        }

        ++trainerPosition;
        ++position;
    }

    return -1;
}

// Comprueba si ya existe un entrenador con el nombre recibido.
bool BattleSimulator::containsTrainer(
    const std::string& trainerName) const {

    return findTrainer(trainerName) != -1;
}

// Agrega un entrenador si no existe otro con el mismo nombre.
bool BattleSimulator::addTrainer(
    const Trainer& trainer) {

    if (containsTrainer(trainer.getName())) {
        return false;
    }

    trainerList.push_back(trainer);

    return true;
}

// Elimina un entrenador cuando su nombre se encuentra registrado.
bool BattleSimulator::removeTrainer(
    const std::string& trainerName) {

    int position = findTrainer(trainerName);

    if (position == -1) {
        return false;
    }

    std::vector<Trainer>::iterator trainerPosition =
        trainerList.begin();

    int currentPosition = 0;

    while (currentPosition < position) {

        ++trainerPosition;
        ++currentPosition;
    }

    trainerList.erase(trainerPosition);

    return true;
}

// Retorna una referencia que permite modificar el entrenador solicitado.
Trainer& BattleSimulator::getTrainer(
    int position) {

    return trainerList[position];
}

// Retorna una referencia constante para consultar el entrenador solicitado.
const Trainer& BattleSimulator::getTrainer(
    int position) const {

    return trainerList[position];
}

// Retorna una batalla del historial únicamente para consulta.
const Battle& BattleSimulator::getBattle(
    int position) const {

    return battleHistory[position];
}

// Retorna los resultados generados por la comparación más reciente.
const std::vector<TeamResult>& BattleSimulator::getComparisonResults() const {

    return comparisonResults;
}

// Busca el resultado correspondiente a un equipo y entrenador específicos.
int BattleSimulator::findComparisonResult(
    const std::string& trainerName,
    const std::string& teamName
) const {

    std::vector<TeamResult>::const_iterator resultPosition =
        comparisonResults.begin();

    int position = 0;

    while (resultPosition != comparisonResults.end()) {

        if (resultPosition->trainerName == trainerName &&
            resultPosition->teamName == teamName) {

            return position;
        }

        ++resultPosition;
        ++position;
    }

    return -1;
}
// Crea un resultado vacío para cada equipo de los dos entrenadores.
void BattleSimulator::initializeComparisonResults(
    const Trainer& firstTrainer,
    const Trainer& secondTrainer
) {

    comparisonResults.clear();

    int firstTeamPosition = 0;
    int firstTeamCount = firstTrainer.getTeamCount();

    while (firstTeamPosition < firstTeamCount) {

        TeamResult result;

        result.trainerName = firstTrainer.getName();
        result.teamName =
            firstTrainer.getTeam(firstTeamPosition).getName();

        result.battles = 0;
        result.victories = 0;
        result.winPercentage = 0.0;

        comparisonResults.push_back(result);

        ++firstTeamPosition;
    }


    int secondTeamPosition = 0;
    int secondTeamCount = secondTrainer.getTeamCount();

    while (secondTeamPosition < secondTeamCount) {

        TeamResult result;

        result.trainerName = secondTrainer.getName();
        result.teamName =
            secondTrainer.getTeam(secondTeamPosition).getName();

        result.battles = 0;
        result.victories = 0;
        result.winPercentage = 0.0;

        comparisonResults.push_back(result);

        ++secondTeamPosition;
    }
}


// Actualiza las batallas y victorias acumuladas por un equipo.
void BattleSimulator::registerTeamResult(
    const std::string& trainerName,
    const std::string& teamName,
    bool won
) {

    int resultPosition =
        findComparisonResult(trainerName, teamName);


    if (resultPosition == -1) {
        return;
    }


    comparisonResults[resultPosition].battles++;


    if (won) {

        comparisonResults[resultPosition].victories++;
    }
}


// Calcula el porcentaje de victorias de cada resultado almacenado.
void BattleSimulator::calculateWinPercentages() {

    std::vector<TeamResult>::iterator resultPosition =
        comparisonResults.begin();


    while (resultPosition != comparisonResults.end()) {

        if (resultPosition->battles == 0) {

            resultPosition->winPercentage = 0.0;

        } else {

            resultPosition->winPercentage =
                resultPosition->victories * 100.0 /
                resultPosition->battles;
        }

        ++resultPosition;
    }
}


// Ejecuta una batalla específica seleccionando entrenadores y equipos por nombre.
bool BattleSimulator::executeBattle(
    const std::string& firstTrainerName,
    const std::string& firstTeamName,
    const std::string& secondTrainerName,
    const std::string& secondTeamName
) {

    //TODO #08 (Buscar los participantes y ejecutar una batalla)
    /*
     * Ejecute una batalla entre los equipos indicados por los parametros.
     * Todos los entrenadores y equipos deben localizarse antes de construir
     * el objeto Battle.
     *
     * Siga estas etapas:
     *
     * 1. Busque las posiciones de ambos entrenadores mediante findTrainer().
     *    Si alguno no existe, retorne false sin crear ni almacenar una
     *    batalla.
     *
     * 2. Obtenga referencias constantes a los entrenadores encontrados.
     *
     * 3. Busque firstTeamName dentro del primer entrenador y secondTeamName
     *    dentro del segundo. Si alguno de los equipos no existe, retorne
     *    false.
     *
     * 4. Construya un objeto Battle utilizando:
     *    - El nombre del primer entrenador.
     *    - El primer equipo encontrado.
     *    - El nombre del segundo entrenador.
     *    - El segundo equipo encontrado.
     *
     *    Respete el orden de los parametros definido por el constructor de
     *    Battle. La batalla debe trabajar con copias de los equipos, por lo
     *    que la salud de los Pokemon originales no debe ser modificada.
     *
     * 5. Ejecute completamente la batalla mediante runBattle().
     *
     * 6. Agregue la batalla finalizada al final de battleHistory para
     *    conservar el orden cronologico de las batallas del simulador.
     *
     * Retorne true solamente cuando los participantes sean validos y la
     * batalla haya sido ejecutada y almacenada. No agregue elementos al
     * historial cuando algun entrenador o equipo no pueda encontrarse.
     */


    // Buscar los entrenadores participantes.
    int firstTrainerPosition =
        findTrainer(firstTrainerName);

    int secondTrainerPosition =
        findTrainer(secondTrainerName);


    if (firstTrainerPosition == -1 ||
        secondTrainerPosition == -1) {

        return false;
    }


    // Obtener los entrenadores encontrados.
    const Trainer& firstTrainer =
        trainerList[firstTrainerPosition];

    const Trainer& secondTrainer =
        trainerList[secondTrainerPosition];


    // Buscar los equipos dentro de cada entrenador.
    int firstTeamPosition =
        firstTrainer.findTeam(firstTeamName);

    int secondTeamPosition =
        secondTrainer.findTeam(secondTeamName);


    if (firstTeamPosition == -1 ||
        secondTeamPosition == -1) {

        return false;
    }


    // Obtener los equipos encontrados.
    const Team& firstTeam =
        firstTrainer.getTeam(firstTeamPosition);

    const Team& secondTeam =
        secondTrainer.getTeam(secondTeamPosition);



    // Crear la batalla utilizando copias de los equipos.
    Battle battle(
        firstTrainerName,
        firstTeam,
        secondTrainerName,
        secondTeam
    );


    // Ejecutar completamente la batalla.
    battle.runBattle();


    // Guardar la batalla en el historial.
    battleHistory.push_back(battle);


    return true;
}
// Enfrenta cada equipo del primer entrenador contra todos los del segundo.
bool BattleSimulator::compareTrainers(
    const std::string& firstTrainerName,
    const std::string& secondTrainerName
) {

    //TODO #09 (Comparar todos los equipos de dos entrenadores)
    /*
     * Compare los entrenadores ejecutando una batalla entre cada equipo del
     * primero y cada equipo del segundo. Utilice recorridos anidados para
     * construir el producto cartesiano de sus colecciones de equipos.
     *
     * Siga estas etapas:
     *
     * 1. Compruebe que los nombres recibidos sean diferentes. Un entrenador
     *    no puede compararse consigo mismo.
     *
     * 2. Busque ambos entrenadores mediante findTrainer(). Si alguno no
     *    existe, retorne false.
     *
     * 3. Obtenga referencias constantes a los entrenadores encontrados y
     *    compruebe que ambos tengan al menos un equipo. Si alguno no tiene
     *    equipos registrados, retorne false.
     *
     * 4. Inicialice comparisonResults mediante la operacion auxiliar
     *    initializeComparisonResults(). Esta operacion prepara un resultado
     *    con cero batallas y victorias para cada equipo participante.
     *
     * 5. Recorra todos los equipos del primer entrenador. Para cada uno,
     *    recorra completamente los equipos del segundo entrenador.
     *
     * 6. Para cada pareja de equipos:
     *    - Obtenga referencias constantes a ambos equipos.
     *    - Construya una batalla con los nombres de sus entrenadores y los
     *      equipos correspondientes.
     *    - Ejecute completamente la batalla.
     *
     * 7. Determine por separado si gano el primer equipo o el segundo. Para
     *    esto, consulte el estado final de las copias almacenadas en Battle.
     *    Un equipo gana cuando conserva Pokemon disponibles y su oponente
     *    esta derrotado. Es posible que una batalla termine sin ganador.
     *
     * 8. Registre el resultado de ambos equipos mediante registerTeamResult().
     *    Cada equipo debe aumentar su cantidad de batallas y solamente debe
     *    aumentar sus victorias cuando realmente haya ganado.
     *
     * 9. Agregue cada batalla ejecutada al final de battleHistory. Las
     *    batallas de comparaciones anteriores no deben eliminarse.
     *
     * 10. Cuando terminen ambos recorridos, calcule los porcentajes de
     *     victoria mediante calculateWinPercentages().
     *
     * Retorne true cuando la comparacion completa haya sido realizada.
     * Retorne false si los entrenadores son iguales, alguno no existe o
     * alguno no tiene equipos. Los resultados de la comparacion anterior
     * solamente deben reemplazarse despues de superar estas validaciones.
     */


    // Un entrenador no puede compararse consigo mismo.
    if (firstTrainerName == secondTrainerName) {

        return false;
    }


    // Buscar los entrenadores dentro del simulador.
    int firstTrainerPosition =
        findTrainer(firstTrainerName);

    int secondTrainerPosition =
        findTrainer(secondTrainerName);


    if (firstTrainerPosition == -1 ||
        secondTrainerPosition == -1) {

        return false;
    }


    // Obtener referencias constantes de los entrenadores.
    const Trainer& firstTrainer =
        trainerList[firstTrainerPosition];

    const Trainer& secondTrainer =
        trainerList[secondTrainerPosition];


    // Verificar que ambos entrenadores tengan equipos.
    if (firstTrainer.isEmpty() ||
        secondTrainer.isEmpty()) {

        return false;
    }


    // Preparar resultados de comparación.
    initializeComparisonResults(
        firstTrainer,
        secondTrainer
    );


    int firstTeamPosition = 0;


    while (firstTeamPosition < firstTrainer.getTeamCount()) {


        int secondTeamPosition = 0;


        while (secondTeamPosition < secondTrainer.getTeamCount()) {


            const Team& firstTeam =
                firstTrainer.getTeam(firstTeamPosition);


            const Team& secondTeam =
                secondTrainer.getTeam(secondTeamPosition);



            // Crear la batalla entre los dos equipos.
            Battle battle(
                firstTrainer.getName(),
                firstTeam,
                secondTrainer.getName(),
                secondTeam
            );


            // Ejecutar la batalla.
            battle.runBattle();



            bool firstTeamWon = false;
            bool secondTeamWon = false;


            // Revisar el resultado de la batalla.
            if (battle.getFirstTeam().isDefeated() &&
                !battle.getSecondTeam().isDefeated()) {

                secondTeamWon = true;

            } else if (battle.getSecondTeam().isDefeated() &&
                       !battle.getFirstTeam().isDefeated()) {

                firstTeamWon = true;
            }



            // Guardar resultados de ambos equipos.
            registerTeamResult(
                firstTrainer.getName(),
                firstTeam.getName(),
                firstTeamWon
            );


            registerTeamResult(
                secondTrainer.getName(),
                secondTeam.getName(),
                secondTeamWon
            );


            // Guardar la batalla realizada.
            battleHistory.push_back(battle);


            ++secondTeamPosition;
        }


        ++firstTeamPosition;
    }


    // Calcular porcentajes finales.
    calculateWinPercentages();


    return true;
}


// Retorna todos los equipos que comparten el mayor porcentaje del entrenador.
std::vector<std::string> BattleSimulator::getBestTeams(
    const std::string& trainerName
) const {

    std::vector<std::string> bestTeams;

    double bestPercentage = -1.0;


    std::vector<TeamResult>::const_iterator resultPosition =
        comparisonResults.begin();


    while (resultPosition != comparisonResults.end()) {


        if (resultPosition->trainerName == trainerName &&
            resultPosition->winPercentage > bestPercentage) {

            bestPercentage =
                resultPosition->winPercentage;
        }


        ++resultPosition;
    }



    if (bestPercentage < 0.0) {

        return bestTeams;
    }



    resultPosition = comparisonResults.begin();


    while (resultPosition != comparisonResults.end()) {


        if (resultPosition->trainerName == trainerName &&
            resultPosition->winPercentage == bestPercentage) {

            bestTeams.push_back(
                resultPosition->teamName
            );
        }


        ++resultPosition;
    }


    return bestTeams;
}
// Imprime todos los entrenadores registrados en el simulador.
void BattleSimulator::printTrainers() const {

    std::cout << "==================================================\n";
    std::cout << "ENTRENADORES REGISTRADOS: "
              << getTrainerCount() << '\n';
    std::cout << "==================================================\n";


    if (isEmpty()) {

        std::cout << "No hay entrenadores registrados.\n";
        return;
    }


    std::vector<Trainer>::const_iterator trainerPosition =
        trainerList.begin();


    while (trainerPosition != trainerList.end()) {

        trainerPosition->print();

        std::cout << '\n';

        ++trainerPosition;
    }
}


// Imprime la tabla de resultados de la comparación más reciente.
void BattleSimulator::printComparisonResults() const {

    std::cout << "==============================================================\n";
    std::cout << "RESULTADOS DE LA COMPARACION\n";
    std::cout << "==============================================================\n";


    if (comparisonResults.empty()) {

        std::cout
            << "No hay resultados de comparación disponibles.\n";

        return;
    }


    std::cout << std::left
              << std::setw(15) << "Entrenador"
              << std::setw(20) << "Equipo"
              << std::setw(10) << "Batallas"
              << std::setw(11) << "Victorias"
              << "Porcentaje\n";


    std::cout << "--------------------------------------------------------------\n";


    std::vector<TeamResult>::const_iterator resultPosition =
        comparisonResults.begin();


    while (resultPosition != comparisonResults.end()) {


        std::cout << std::left
                  << std::setw(15)
                  << resultPosition->trainerName

                  << std::setw(20)
                  << resultPosition->teamName

                  << std::setw(10)
                  << resultPosition->battles

                  << std::setw(11)
                  << resultPosition->victories

                  << std::fixed
                  << std::setprecision(2)
                  << resultPosition->winPercentage
                  << " %\n";


        ++resultPosition;
    }
}


// Imprime todas las batallas almacenadas en orden cronológico.
void BattleSimulator::printBattleHistory() const {


    std::cout << "==================================================\n";
    std::cout << "HISTORIAL DE BATALLAS: "
              << getBattleCount()
              << '\n';

    std::cout << "==================================================\n";


    if (battleHistory.empty()) {

        std::cout << "No hay batallas registradas.\n";

        return;
    }


    std::deque<Battle>::const_iterator battlePosition =
        battleHistory.begin();


    int position = 0;


    while (battlePosition != battleHistory.end()) {


        std::cout << "\nBatalla "
                  << position
                  << '\n';


        battlePosition->printBattleHistory();


        ++battlePosition;
        ++position;
    }
}
