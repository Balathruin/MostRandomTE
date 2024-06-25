//
// Created by Ted on 12/05/2024
//

#ifndef MOSTRANDOM_GENERALFUNCTIONS_H
#define MOSTRANDOM_GENERALFUNCTIONS_H

std::vector<std::pair<std::string, bool>> promptUser(const std::vector<std::pair<std::string, bool>>&,
                                    const std::string&, int*);

std::vector<std::pair<std::string, bool>> promptUser(const std::vector<std::pair<std::string, bool>>&,
       const std::vector<std::pair<std::string, bool>>&, const std::string&, const std::string&, int*);

bool askQuestionAboutSettings(const std::string&);
bool checkForField(int, int);
int pickRandomNumber(int, int);

#endif //MOSTRANDOM_GENERALFUNCTIONS_H
