//
// Created by Ted on 12/05/2024
//

#include <random>
#include <iostream>
#include "GeneralFunctions.h"
#include "XoshiroCpp.hpp"

/** Credit to Reputeless for the XoshiroCpp.hpp library, taken from
    https://github.com/Reputeless/Xoshiro-cpp and used under the MIT license.   */

std::vector<std::pair<std::string, bool>> promptUser(const std::vector<std::pair<std::string, bool>>& promptedForRaces,
                                                     const std::string& promptText, int* counterToIncrement)
{
    //Initialize vector
    std::vector<std::pair<std::string, bool>> returnVector;

    //Variables for user input
    std::string answer;
    bool answerGiven = false;

    std::cout << promptText;

    while ( !answerGiven )
    {
        std::cin >> answer;

        if ( answer == "Y" || answer == "y" )
        {
            //Sonny track expansion races
            for ( const std::pair<std::string, bool>& race : promptedForRaces )
            { returnVector.emplace_back(race); }

            *counterToIncrement += static_cast<int>(promptedForRaces.size());
            answerGiven = true;
        }

        else if ( answer == "N" || answer == "n" ) { answerGiven = true; }

        else { std::cout << "\nBad input. Try again >> "; }
    }

    return returnVector;
}

std::vector<std::pair<std::string, bool>> promptUser(const std::vector<std::pair<std::string, bool>>& promptedForRaces,
      const std::vector<std::pair<std::string, bool>>& promptedForExtraRaces, const std::string& promptText,
      const std::string& promptTextForExtras, int* counterToIncrement)
{
    //Initialize vector
    std::vector<std::pair<std::string, bool>> returnVector;

    //Variables for user input
    std::string answer;
    bool answerGiven = false;
    bool answerForExtraTracksGiven = false;

    std::cout << promptText;

    while ( !answerGiven )
    {
        std::cin >> answer;

        if ( answer == "Y" || answer == "y" )
        {
            for ( const std::pair<std::string, bool>& race : promptedForRaces )
            { returnVector.emplace_back(race); }

            *counterToIncrement += static_cast<int>(promptedForRaces.size());
            answerGiven = true;

            while ( !answerForExtraTracksGiven )
            {
                std::cout << promptTextForExtras;
                std::cin >> answer;

                if ( answer == "Y" || answer == "y" )
                {
                    for ( const std::pair<std::string, bool>& race : promptedForExtraRaces )
                    { returnVector.emplace_back(race); }

                    *counterToIncrement += static_cast<int>(promptedForExtraRaces.size());
                    answerForExtraTracksGiven = true;
                }

                else if ( answer == "N" || answer == "n" ) { answerForExtraTracksGiven = true; }

                else { std::cout << "\nBad input. Try again >> "; }
            }
        }

        else if ( answer == "N" || answer == "n" ) { answerGiven = true; }

        else { std::cout << "\nBad input. Try again >> "; }
    }

    return returnVector;
}

bool askQuestionAboutSettings(const std::string& prompt)
{
    //Variables
    std::string answer;
    bool questionAnswered = false;
    bool settingGiven;

    std::cout << prompt;

    while ( !questionAnswered )
    {
        std::cin >> answer;

        if ( answer == "Y" || answer == "y" )
        {
            settingGiven = true;
            questionAnswered = true;
        }

        else if ( answer == "N" || answer == "n" )
        {
            settingGiven = false;
            questionAnswered = true;
        }

        else { std::cout << "\nBad input. Try again >> "; }
    }

    return settingGiven;
}

bool checkForField(int raceInteger, int checkType)
{
    /** This function is hardcoded to check if a certain field exists
      * for a race or race trigger in vlted. Uses a map populated with the createMap
      * function and the race name string.
      *
      * Use checkType 1 for BossRace fields.
      * Use checkType 2 for IsMarkerRace fields.
      * Use checkType 3 for RewardsForWinner fields.
      * Use checkType 4 for PostRaceActivity fields.
      * Use checkType 5 for RivalBestTime fields.
      * Use checkType 6 for InitiallyUnlocked fields in the race trigger.
      * Use checkType 7 for NumLaps fields in knockouts and circuits.
      * Use checkType 8 for IntroNIS fields.
      * Use checkType 9 for TrafficLevel fields.
      * Use checkType 10 for IntroMovie fields.
      * Use checkType 11 for PlayerCarType fields.
      * Use checkType 12 for CopsInRace fields.
      * Use checkType 13 for EventIconType fields.
      * Use checkType 14 for KnockoutsPerLap fields.                                        */

    //Return bool based on whether BossRace field already exists in vlted for that race
    if ( checkType == 1 )
    {
        switch(raceInteger)
        {
            case 4: case 5: case 12: case 13: case 21: case 22: case 30: case 31: case 40: case 41: case 50:
            case 51: case 60: case 61: case 69: case 70: case 81: case 82: case 94: case 95: case 106: case 107:
            case 120: case 121: case 122: case 108: case 135: case 136: case 137: case 150: case 151: case 152:
            case 154: case 160: case 164: case 165: case 166: case 167: case 168: return true;

            //Most common result
            default: return false;
        }
    }

    //Return bool based on whether isMarkerRace field already exists in vlted for that race
    else if ( checkType == 2 )
    {
        switch(raceInteger)
        {
            case 2: case 4: case 5: case 11: case 13: case 22: case 30: case 31: case 40: case 41: case 51:
            case 61: case 70: case 82: case 95: case 108: case 121: case 122: case 137: case 152: return true;

            //Most common result
            default: return false;
        }
    }

    //Return bool based on whether RewardsForWinner field already exists in vlted for that race
    else if ( checkType == 3 )
    {
        switch(raceInteger)
        {
            case 5: case 13: case 22: case 31: case 41: case 51: case 61: case 70: case 82: case 95:
            case 108: case 122: case 137: case 152: case 171: return true;

            //Most common result
            default: return false;
        }
    }

    //Return bool based on whether PostRaceActivity field already exists in vlted for that race
    else if ( checkType == 4)
    {
        switch(raceInteger)
        {
            case 4: case 12: case 21: case 30: case 40: case 50: case 60: case 69: case 81: case 94:
            case 106: case 107: case 120: case 121: case 135: case 136: case 150: case 151: case 164:
            case 165: case 166: case 167: case 168: case 169: case 170: case 171: return true;

            //Most common result
            default: return false;
        }
    }

    //Return bool based on whether RivalBestTime field already exists in vlted for that race
    else if ( checkType == 5 )
    {
        switch(raceInteger)
        {
            case 4: case 5: case 12: case 13: case 21: case 22: case 30: case 31: case 40: case 41: case 50:
            case 51: case 60: case 61: case 69: case 70: case 81: case 82: case 94: case 95: case 106: case 107:
            case 108: case 120: case 121: case 122: case 135: case 136: case 137: case 150: case 151: case 152:
            case 164: case 165: case 166: case 167: case 168: return true;

            //Most common result
            default: return false;
        }
    }

    //Return bool based on whether InitiallyUnlocked field already exists in vlted for that race trigger
    else if ( checkType == 6 )
    {
        switch(raceInteger)
        {
            case 3: case 4: case 12: case 21: case 30: case 40: case 50: case 60: case 69: case 81: case 94:
            case 106: case 120: case 135: case 150: case 164: return true;

            //Most common result
            default: return false;
        }
    }

    //Return bool based on whether NumLaps field already exists in vlted for a circuit/lap knockout race
    else if ( checkType == 7 )
    {
        switch(raceInteger)
        {
            case 3: case 9: case 41: case 42: case 48: case 58: case 59: case 63: case 76: case 78: case 89:
            case 96: case 116: case 117: case 128: case 135: case 139: case 145: case 146: case 147: case 150:
            case 153: case 157: case 167: case 172: return false;

            //Most common result
            default: return true;
        }
    }

    //Return bool based on whether IntroNIS field exists in a race node.
    else if ( checkType == 8 )
    {
        switch(raceInteger)
        {
            case 26: case 48: case 66: case 116: case 122: case 125: case 144: case 151: case 155:
            case 168: case 173: return false;

            //Most common result
            default: return true;
        }
    }

    //Return bool based on whether TrafficLevel field exists in a race node.
    else if ( checkType == 9 )
    {
        switch(raceInteger)
        {
            case 39: case 51: case 58: case 59: case 70: case 80: case 92: case 98: case 105:  case 121: case 134:
            case 149: case 165: case 166: return false;

            //Most common result
            default: return true;
        }
    }

    //Return bool based on whether IntroMovie field exists in a race node.
    else if ( checkType == 10 )
    {
        switch(raceInteger)
        {
            case 2: case 20: case 44: case 47: case 83: case 88: case 95: case 110: case 111: case 164: case 169:
            case 170: case 171: return true;

            //Most common result
            default: return false;
        }
    }

    //Return bool based on whether PlayerCarType field exists in a race node.
    else if ( checkType == 11 )
    {
        switch(raceInteger)
        {
            case 169: case 170: case 171: return true;

            //Most common result
            default: return false;
        }
    }

    //Return bool based on whether CopsInRace field exists in a race node.
    else if ( checkType == 12 )
    {
        switch(raceInteger)
        {
            case 56: case 97: case 101: case 102: case 103: case 109: case 112: case 126: case 129: case 142:
            case 143: case 144: case 155: case 158: case 160: case 172: case 173: case 174: return false;

            //Most common result
            default: return true;
        }
    }

    //Return bool based on whether EventIconType field exists in a race node.
    else if ( checkType == 13 )
    {
        switch(raceInteger)
        {
            case 2: case 7: case 8: case 9: case 10: case 12: case 14: case 15: case 16: case 17: case 18:
            case 19: case 20: case 24: case 25: case 27: case 30: case 32: case 34: case 35: case 36: case 42:
            case 44: case 45: case 50: case 53: case 54: case 55: case 61: case 69: case 71: case 72: case 73:
            case 74: case 79: case 81: case 82: case 83: case 84: case 85: case 86: case 87: case 89: case 95:
            case 109: case 110: case 112: case 113: case 120: case 137: case 170: case 171: return true;

            //Most common result
            default: return false;
        }
    }

    //Return bool based on whether KnockoutsPerLap field exists in a race node.
    else
    {
        switch(raceInteger)
        {
            case 3: case 9: case 16: case 42: case 43: case 89: case 111: return true;

            //Most common result
            default: return false;
        }
    }
}

int pickRandomNumber(int startRange, int maxRange)
{
    /** Returns a random integer in the range given as arguments. */

    //Set up the number randomizer
    std::random_device rd;
    XoshiroCpp::Xoshiro256PlusPlus xoshiro(rd());
    std::uniform_int_distribution<int> dist(startRange, maxRange);

    //Generate and return number
    return dist(xoshiro);
}
