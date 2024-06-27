//
// Created by Ted on 12/05/2024
//

#ifndef MOSTRANDOM_RACEFUNCTIONS_H
#define MOSTRANDOM_RACEFUNCTIONS_H

std::string checkRaceType(int);
int checkRaceStart(int);
int getSizeOfChildrenFieldForSprint(int);
int returnNumberOfRaces(int, int);
std::pair<int, int> returnNumberOfBossRaces(int, int);

void convertBossRaceToRegularRace(std::ofstream&, const std::string&, int, int, const std::array<std::string, 41>&,
                                  const std::string&, const std::string&, const std::array<std::string, 6>&);

void convertToPrologueRace(std::ofstream&, const std::string&, int, int);
void convertKnockoutToCircuit(std::ofstream&, const std::string&, int);
void convertCircuitToKnockout(std::ofstream&, const std::string&, int, bool);
void randomizeCircuitLaps(std::ofstream&, const std::string&, int);

void randomizeKOsAndCircuits(std::ofstream&, const std::string&, int, const std::string&,
          const std::unordered_map<int, float>&, const std::unordered_map<int, float>&, int, int, bool, bool);

void convertSprintToSpeedtrap(std::ofstream&, int, const std::string&);
void convertSpeedtrapToSprint(std::ofstream&, int, const std::string&);
void randomizeSprintsAndSpeedtraps(std::ofstream&, const std::string&, int, const std::string&, bool);
void removeUnnecessaryPrologueRaceFields(std::ofstream&, const std::string&);
void convertPrologueRaceToRegularRace(std::ofstream&, const std::string&);

void updateRegularRace(std::ofstream&, const std::string&, const std::string&, int, const std::string&, int,
                       const std::array<std::string, 41>&, const std::array<std::string, 6>&);

void randomizeRaceIntro(std::ofstream&, const std::string&, int, bool);

void randomizeGeneralFields(std::ofstream&, const std::string&, const std::unordered_map<int, float>&,
                            const std::unordered_map<int, float>&, int, const std::string&, int, int, int,
                            bool, bool, bool, bool, bool);

#endif //MOSTRANDOM_RACEFUNCTIONS_H
