//
// Created by Ted on 12/05/2024
//

#ifndef MOSTRANDOM_EVENTTRIGGERFUNCTIONS_H
#define MOSTRANDOM_EVENTTRIGGERFUNCTIONS_H

#include <unordered_map>

std::vector<std::string> getNewTriggerDetails(int);
bool hasTrigger(int);

void updateRaceTriggers(std::ofstream&, bool, const std::string&, const std::vector<std::pair<std::string, int>>&);

void createRaceTrigger(std::ofstream&, const std::string&, const std::string&, const std::string&,
        std::vector<std::string>, const std::string&);

#endif //MOSTRANDOM_EVENTTRIGGERFUNCTIONS_H
