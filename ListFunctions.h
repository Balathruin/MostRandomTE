//
// Created by Ted on 11/05/2024
//

#ifndef MOSTRANDOM_LISTFUNCTIONS_H
#define MOSTRANDOM_LISTFUNCTIONS_H

#include <unordered_map>

std::vector<std::pair<std::string, bool>> populateRacesCustomizable(int*, int*, int*, int*, int*, int*, int*,
                                          int*, int*, int*, int*, int*, int*, int*, int*, bool);

std::unordered_map<std::string, int> createRaceMap();
std::unordered_map<int, float> createDistanceMap();
std::unordered_map<int, float> createTimeMap();
std::vector<std::pair<std::string, std::string>> getListOfChildrenFieldUpdatesForSpeedtraps(int);
std::vector<std::array<std::string, 4>> getSpeedtrapCoordinatesForSprints(int);
std::vector<std::string> getListOfRaceSpeedtraps(int);
std::vector<std::array<float, 4>> getFreeRoamZoneCoordinates();
std::vector<std::array<float, 4>> getFreeRoamZoneRespawnCoordinates();
std::vector<std::string> getListOfFreeRoamZones();
std::array<std::string, 41> getListOfRegularOpponents();
std::array<std::string, 18> getListOfScriptedOpponents();
std::array<std::string, 6> getListOfStartingOpponents();
std::array<std::string, 73> getListOfPresetCars();
std::array<std::string, 69> getListOfEngineSounds();
std::array<std::string, 46> getListOfCars();
std::array<std::string, 12> getListOfFMVs();
std::array<std::string, 43> getListOfMilestoneSpawnPoints();

#endif //MOSTRANDOM_LISTFUNCTIONS_H
