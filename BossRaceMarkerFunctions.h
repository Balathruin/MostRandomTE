//
// Created by Ted on 20/06/2024
//

#ifndef MOSTRANDOM_BOSSRACEMARKERFUNCTIONS_H
#define MOSTRANDOM_BOSSRACEMARKERFUNCTIONS_H

void randomizeBossMarkers(std::ofstream&, const std::string&, const std::string&);

std::string createBossRace(std::ofstream&, const std::string&, int, int, int, int, int, const std::string&,
                           const std::string&, const std::string&, std::string);

#endif //MOSTRANDOM_BOSSRACEMARKERFUNCTIONS_H
