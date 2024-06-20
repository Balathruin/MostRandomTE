//
// Created by Ted on 12/05/2024
//

#include <string>
#include <unordered_map>
#include <fstream>
#include <vector>
#include <algorithm>
#include <array>
#include "GeneralFunctions.h"
#include "RaceFunctions.h"
#include "ListFunctions.h"

std::string checkRaceType(int RaceInteger)
{
    /** Returns a string based on race type. */

    switch(RaceInteger)
    {
        case 10: case 17: case 18: case 24: case 25: case 35: case 36: case 44: case 45: case 54: case 57:
        case 67: case 68: case 72: case 74: case 79: case 84: case 87: case 93: case 101: case 104: case 105:
        case 109: case 118: case 119: case 126: case 131: case 132: case 140: case 141: case 142: case 158:
        case 159: case 163: return "tollbooth";

        case 19: case 20: case 26: case 34: case 38: case 49: case 55: case 56: case 60: case 64: case 65:
        case 73: case 85: case 91: case 95: case 99: case 100: case 102: case 107: case 112: case 113:
        case 114: case 120: case 122: case 129: case 130: case 143: case 148: case 160: case 161:
        case 164: case 181: case 188: case 198: case 203: case 228: case 232: case 263:
        case 276: return "speedtrap";

        case 2: case 7: case 8: case 12: case 13: case 14: case 21: case 22: case 28: case 29: case 30:
        case 32: case 37: case 46: case 47: case 50: case 61: case 66: case 69: case 71: case 77: case 81:
        case 82: case 83: case 86: case 90: case 98: case 103: case 106: case 108: case 115: case 123: case 127:
        case 133: case 136: case 144: case 151: case 152: case 154: case 155: case 156: case 162: case 166:
        case 168: case 170: case 171: case 173: case 174: case 176: case 179: case 184: case 191: case 194:
        case 205: case 207: case 212: case 216: case 224: case 233: case 243: case 244: case 253: case 257:
        case 260: case 267: case 273: return "sprint";

        case 3: case 9: case 15: case 16: case 42: case 43: case 59: case 62: case 63: case 75: case 88:
        case 89: case 96: case 111: case 116: case 124: case 128: case 145: case 146: case 157: case 177:
        case 178: case 185: case 186: case 187: case 192: case 193: case 195: case 200: case 202: case 204:
        case 210: case 213: case 217: case 218: case 223: case 225: case 227: case 230: case 234: case 237:
        case 239: case 242: case 247: case 251: case 254: case 258: case 259: case 264: case 266: case 269:
        case 270: case 275: case 277: case 280: case 284: case 287: case 288: case 289: return "knockout";

        case 27: case 39: case 51: case 53: case 70: case 80: case 92: case 121: case 134: case 149:
        case 165: return "drag";

        //Circuits are the most common result
        default: return "circuit";
    }
}

int checkRaceStart(int raceInteger)
{
    /** Returns an integer that indicates the race start. 1 for wide starts and 2 for narrow
      * starts. If race is a tollbooth, returns 3. Used to decide which intros can be used.         */

    switch(raceInteger)
    {
        case 2: case 4: case 7: case 9: case 12: case 13: case 14: case 21: case 22: case 26: case 29: case 30:
        case 31: case 37: case 40: case 41: case 42: case 48: case 49: case 55: case 56: case 60: case 61:
        case 62: case 65: case 66: case 73: case 77: case 81: case 82: case 86: case 94: case 96: case 97:
        case 106: case 110: case 113: case 116: case 125: case 127: case 128: case 136: case 144: case 146:
        case 150: case 151: case 155: case 157: case 164: case 168: case 172: case 173: case 174: case 176:
        case 181: case 182: case 192: case 194: case 195: case 196: case 198: case 199: case 202: case 207:
        case 208: case 215: case 225: case 226: case 229: case 235: case 237: case 242: case 243: case 245:
        case 249: case 251: case 254: case 263: case 270: case 276: case 286: case 294: case 295:
        case 297: return 2;

        case 10: case 17: case 18: case 24: case 25: case 35: case 36: case 44: case 45: case 54: case 57:
        case 67: case 68: case 72: case 74: case 79: case 84: case 87: case 93: case 101: case 104: case 105:
        case 109: case 118: case 119: case 126: case 131: case 132: case 140: case 141: case 142: case 158:
        case 159: case 163: return 3;

        //Wide starts are most common
        default: return 1;
    }
}

int getSizeOfChildrenFieldForSprint(int raceInteger)
{
    switch(raceInteger)
    {
        case 267: return 36;
        case 155: return 30;
        case 47: return 29;
        case 154: return 26;
        case 14: case 156: case 162: case 243: return 25;
        case 21: case 81: case 98: case 253: case 273: return 24;
        case 103: case 108: case 115: case 168: return 23;
        case 50: case 152: case 171: case 260: return 22;
        case 77: case 82: case 133: case 151: case 257: return 21;
        case 32: case 106: case 144: return 20;
        case 28: case 37: case 66: case 166: return 19;
        case 12: case 46: case 61: case 69: case 86: case 244: return 18;
        case 29: case 30: case 90: return 17;
        case 22: case 212: return 15;
        case 8: case 127: case 136: case 170: case 216: return 14;
        case 83: case 191: return 13;
        case 179: case 224: return 12;
        case 184: case 194: case 207: return 11;
        case 123: case 205: return 10;
        case 174: case 176: return 9;

        //One of the most common results
        default: return 16;
    }
}

int returnNumberOfRaces(int variation, int originalNumberOfRaces)
{
    switch(variation)
    {
        case -4: return pickRandomNumber(originalNumberOfRaces, originalNumberOfRaces + 8);
        case -3:return pickRandomNumber(originalNumberOfRaces - 1, originalNumberOfRaces + 7);
        case -2: return pickRandomNumber(originalNumberOfRaces - 2, originalNumberOfRaces + 6);
        case -1: return pickRandomNumber(originalNumberOfRaces - 3, originalNumberOfRaces + 5);
        case 0: return pickRandomNumber(originalNumberOfRaces - 4, originalNumberOfRaces + 4);
        case 1: return pickRandomNumber(originalNumberOfRaces - 5, originalNumberOfRaces + 3);
        case 2: return pickRandomNumber(originalNumberOfRaces - 6, originalNumberOfRaces + 2);
        case 3: return pickRandomNumber(originalNumberOfRaces - 7, originalNumberOfRaces + 1);
        default: return pickRandomNumber(originalNumberOfRaces - 8, originalNumberOfRaces);
    }
}

std::pair<int, int> returnNumberOfBossRaces(int variation, int originalNumberOfBossRaces)
{
    int newVariation;
    int numberOfBossRaces;

    if ( originalNumberOfBossRaces == 2 )
    {
        switch(variation)
        {
            case -4: case -3: case -2: case -1: case 0: case 1: case 2: case 3:
                numberOfBossRaces = pickRandomNumber(originalNumberOfBossRaces, originalNumberOfBossRaces + 1);
                break;

            default: numberOfBossRaces = 2;
        }
    }

    else
    {
        switch(variation)
        {
            case -3: case -2: case -1: case 0: case 1: case 2: case 3: case 4:
                numberOfBossRaces = pickRandomNumber(originalNumberOfBossRaces - 1, originalNumberOfBossRaces);
                break;

            default: numberOfBossRaces = 3;
        }
    }

    newVariation = variation + (numberOfBossRaces - originalNumberOfBossRaces);

    return std::make_pair(newVariation, numberOfBossRaces);
}

void convertBossRaceToRegularRace(std::ofstream& file, const std::string& raceName, int raceCashValue,
                                  int raceInteger, const std::array<std::string, 41>& opponentList,
                                  const std::string& raceType, const std::string& raceBin,
                                  const std::array<std::string, 6>& startingOpponentList)
{
    /** Called from randomizeRaces if a race chosen to be a regular race was originally
      * a boss race. Takes data for its lines from randomizeRaces as arguments.            */

    //This field is always present in boss races, no need to check
    file << std::string("delete_field gameplay ").append(raceName).append(" RivalBestTime").append("\n");

    //Boss races except for the last one have no cash value, so a random one is added
    if ( raceType != "drag" )
    {
        file << std::string("update_field gameplay ").append(raceName).append(" CashValue ")
        .append(std::to_string(pickRandomNumber(raceCashValue / 2, int(raceCashValue * 1.5))))
        .append("\n");
    }

    else
    {
        file << std::string("update_field gameplay ").append(raceName).append(" CashValue ")
        .append(std::to_string(pickRandomNumber(raceCashValue / 2, int(raceCashValue * 1.5))/4))
        .append("\n");
    }

    //Inconsistent fields are checked and deleted here
    if ( checkForField(raceInteger, 1) )
    { file << std::string("delete_field gameplay ").append(raceName).append(" BossRace").append("\n"); }

    if ( checkForField(raceInteger, 2) )
    { file << std::string("delete_field gameplay ").append(raceName).append(" IsMarkerRace").append("\n"); }

    if ( checkForField(raceInteger, 3) )
    {
        file << std::string("delete_field gameplay ").append(raceName)
        .append(" RewardsForWinner").append("\n");
    }

    if ( checkForField(raceInteger, 4) )
    {
        file << std::string("delete_field gameplay ").append(raceName)
        .append(" PostRaceActivity").append("\n");
    }

    //Resize opponents field and add regular opponents, including a safeguard for duplicate opponents
    std::vector<std::string> pickedOpponents;
    std::vector<std::string>::iterator opponentSearch;
    std::string pickedOpponent;

    file << std::string("resize_field gameplay ").append(raceName).append(" Opponents 3").append("\n");

    if ( raceBin != "race_bin_15" && raceBin != "race_bin_14" )
    {
        for ( int innerLoop = 0; innerLoop < 3; innerLoop++ )
        {
            pickedOpponent = opponentList[pickRandomNumber(0, (int)opponentList.size() - 1)];
            opponentSearch = std::find(pickedOpponents.begin(), pickedOpponents.end(), pickedOpponent);

            if ( opponentSearch == pickedOpponents.end() )
            {
                pickedOpponents.emplace_back(pickedOpponent);

                file << std::string("update_field gameplay ").append(raceName).append(" Opponents[")
                .append(std::to_string(innerLoop)).append("] ").append(pickedOpponent).append("\n");
            }

            else { innerLoop--; continue; }
        }
    }

    else
    {
        for ( int innerLoop = 0; innerLoop < 3; innerLoop++ )
        {
            pickedOpponent = startingOpponentList[pickRandomNumber(0, (int)startingOpponentList.size() - 1)];
            opponentSearch = std::find(pickedOpponents.begin(), pickedOpponents.end(), pickedOpponent);

            if ( opponentSearch == pickedOpponents.end() )
            {
                pickedOpponents.emplace_back(pickedOpponent);

                file << std::string("update_field gameplay ").append(raceName).append(" Opponents[")
                .append(std::to_string(innerLoop)).append("] ").append(pickedOpponent).append("\n");
            }

            else { innerLoop--; continue; }
        }
    }
}

void convertToPrologueRace(std::ofstream& file, const std::string& raceName, int raceInteger, int raceCashValue)
{
    /** This function is called from randomizePrologueRaces if the picked race is not originally
      * a prologue race. Takes arguments needed to print its lines and does not return values.      */

    //Add fields needed for prologue
    file << std::string("change_vault gameplay ").append(raceName).append(" gpcore").append("\n");

    if ( raceName != "race_bin_01/1_5_2_speedtraprace" )
    { file << std::string("add_field gameplay ").append(raceName).append(" DDayRace").append("\n"); }

    file << std::string("update_field gameplay ").append(raceName).append(" DDayRace True").append("\n");

    //Remove any boss fields, if present
    if ( checkForField(raceInteger, 1) )
    { file << std::string("delete_field gameplay ").append(raceName).append(" BossRace").append("\n"); }

    if ( checkForField(raceInteger, 2) )
    { file << std::string("delete_field gameplay ").append(raceName).append(" IsMarkerRace").append("\n"); }

    if ( checkForField(raceInteger, 3) )
    { file << std::string("delete_field gameplay ").append(raceName).append(" RewardsForWinner").append("\n"); }

    if ( !checkForField(raceInteger, 4) )
    { file << std::string("add_field gameplay ").append(raceName).append(" PostRaceActivity").append("\n"); }

    if ( checkForField(raceInteger, 5) )
    { file << std::string("delete_field gameplay ").append(raceName).append(" RivalBestTime").append("\n"); }

    //FMVs will be randomized, so this field is added
    if ( !checkForField(raceInteger, 10) )
    { file << std::string("add_field gameplay ").append(raceName).append(" IntroMovie").append("\n"); }

    //Cash reward is not randomized to avoid softlocking the game
    file << std::string("update_field gameplay ").append(raceName)
    .append(" CashValue ").append(std::to_string(raceCashValue)).append("\n");
}

void convertKnockoutToCircuit(std::ofstream& file, const std::string& raceName, int raceInteger)
{
    if ( !checkForField(raceInteger, 13) )
    {
        file << std::string("add_field gameplay ").append(raceName)
        .append(" EventIconType").append("\n");
    }

    file << std::string("update_field gameplay ").append(raceName)
    .append(" EventIconType circuit").append("\n");

    if ( !checkForField(raceInteger, 14) )
    {
        file << std::string("add_field gameplay ").append(raceName)
        .append(" KnockoutsPerLap").append("\n");
    }

    file << std::string("update_field gameplay ").append(raceName)
    .append(" KnockoutsPerLap 0").append("\n");
}

void convertCircuitToKnockout(std::ofstream& file, const std::string& raceName, int raceInteger)
{
    if ( !checkForField(raceInteger, 13) )
    {
        file << std::string("add_field gameplay ").append(raceName)
        .append(" EventIconType").append("\n");
    }

    file << std::string("update_field gameplay ").append(raceName)
    .append(" EventIconType knockout").append("\n");

    if ( !checkForField(raceInteger, 14) )
    {
        file << std::string("add_field gameplay ").append(raceName)
        .append(" KnockoutsPerLap").append("\n");
    }

    file << std::string("update_field gameplay ").append(raceName)
    .append(" KnockoutsPerLap 1").append("\n");

    file << std::string("update_field gameplay ").append(raceName)
    .append(" NumLaps 3").append("\n");
}

void randomizeCircuitLaps(std::ofstream& file, const std::string& raceName, int median)
{
    if ( median != 1 )
    {
        file << std::string("update_field gameplay ").append(raceName).append(" NumLaps ")
        .append(std::to_string(pickRandomNumber(median - 1, median + 1))).append("\n");
    }

    else
    {
        file << std::string("update_field gameplay ").append(raceName).append(" NumLaps ")
        .append(std::to_string(pickRandomNumber(median, median + 1))).append("\n");
    }
}

void randomizeKOsAndCircuits(std::ofstream& file, const std::string& raceName, int raceInteger,
                             const std::string& raceType, const std::unordered_map<int, float>& distanceMap,
                             const std::unordered_map<int, float>& timeMap, int loop, int numberOfRaces)
{
    std::unordered_map<int, float>::const_iterator valueFloat;
    int median;
    float distancePerLap;
    bool convertedToCircuit = false;

    if ( !checkForField(raceInteger, 7) )
    { file << std::string("add_field gameplay ").append(raceName).append(" NumLaps").append("\n"); }

    valueFloat = distanceMap.find(raceInteger);

    if ( valueFloat != distanceMap.end() )
    {
        distancePerLap = valueFloat->second / 4;

        if ( distancePerLap < 2000 ) { median = 3; }
        else if ( distancePerLap > 2000 && distancePerLap < 4500 ) { median = 2; }
        else { median = 1; }
    }

    else
    {
        valueFloat = timeMap.find(raceInteger);

        if ( valueFloat->second < 60 ) { median = 3; }
        else if ( valueFloat->second > 60 && valueFloat->second < 200  ) { median = 2; }
        else { median = 1; }
    }

    //This block runs if a circuit is suitable to be converted into a lap knockout
    if ( median >= 2 && raceType == "circuit" )
    {
        //Boss races are not converted
        if ( loop < numberOfRaces && pickRandomNumber(0, 100) < 50 )
        { convertCircuitToKnockout(file, raceName, raceInteger); }

        else { randomizeCircuitLaps(file, raceName, median); }
    }

    //This block runs just if the race is a lap knockout
    else if ( raceType == "knockout" )
    {
        //Guaranteed conversion if a boss race
        if ( loop > numberOfRaces - 1 )
        {
            convertKnockoutToCircuit(file, raceName, raceInteger);
            convertedToCircuit = true;
        }

        //50% chance otherwise
        else
        {
            if ( pickRandomNumber(0, 100) < 50 )
            {
                convertKnockoutToCircuit(file, raceName, raceInteger);
                convertedToCircuit = true;
            }
        }

        if ( !convertedToCircuit )
        {
            file << std::string("update_field gameplay ").append(raceName)
            .append(" NumLaps 3").append("\n");
        }

        else { randomizeCircuitLaps(file, raceName, median); }
    }

    //This block runs if a circuit is not suitable for a lap knockout
    else { randomizeCircuitLaps(file, raceName, median); }
}

void convertSprintToSpeedtrap(std::ofstream& file, int raceInteger, const std::string& raceName)
{
    //Get data for conversion
    std::vector<std::array<std::string, 4>> speedtrapLocations = getSpeedtrapCoordinatesForSprints(raceInteger);
    int sizeOfChildrenField = getSizeOfChildrenFieldForSprint(raceInteger);
    std::string speedtrapName;

    file << std::string("add_field gameplay ").append(raceName)
    .append(" SpeedTrapList").append("\n");

    file << std::string("resize_field gameplay ").append(raceName).append(" SpeedTrapList ")
    .append(std::to_string((int)speedtrapLocations.size())).append("\n");

    file << std::string("resize_field gameplay ").append(raceName)
    .append(" Children ").append(std::to_string((int)speedtrapLocations.size()
    + sizeOfChildrenField)).append("\n");

    if ( checkForField(raceInteger, 13) )
    {
        file << std::string("update_field gameplay ").append(raceName)
        .append(" EventIconType speedtrap").append("\n");
    }

    for ( int speedtrapLoop = 0; speedtrapLoop < (int)speedtrapLocations.size(); speedtrapLoop++ )
    {
        speedtrapName = raceName + "/speedtrap" + std::to_string(speedtrapLoop + 1);

        file << std::string("copy_node gameplay speedtrap_template speedtrap ")
        .append(speedtrapName).append("\n");

        if ( raceInteger < 169 || raceInteger > 174 )
        {
            file << std::string("change_vault gameplay ").append(speedtrapName).append(" ")
            .append(raceName.substr(12, (int)raceName.length() - 12)).append("\n");
        }

        else if ( raceInteger < 172 )
        {
            file << std::string("change_vault gameplay ").append(speedtrapName).append(" ")
            .append(raceName).append("\n");
        }

        else
        {
            file << std::string("change_vault gameplay ").append(speedtrapName).append(" ")
            .append(raceName.substr(20, (int)raceName.length() - 20)).append("\n");
        }

        file << std::string("update_field gameplay ").append(speedtrapName).append(" Name ")
        .append(speedtrapName).append("\n");

        file << std::string("update_field gameplay ").append(speedtrapName).append(" CollectionName ")
        .append(speedtrapName).append("\n");

        file << std::string("update_field gameplay ").append(speedtrapName).append(" Position X ")
        .append(speedtrapLocations[speedtrapLoop][0]).append("\n");

        file << std::string("update_field gameplay ").append(speedtrapName).append(" Position Y ")
        .append(speedtrapLocations[speedtrapLoop][1]).append("\n");

        file << std::string("update_field gameplay ").append(speedtrapName).append(" Position Z ")
        .append(speedtrapLocations[speedtrapLoop][2]).append("\n");

        if ( speedtrapLocations[speedtrapLoop][3] != "35" )
        {
            file << std::string("update_field gameplay ").append(speedtrapName).append(" Radius ")
            .append(speedtrapLocations[speedtrapLoop][3]).append("\n");
        }

        file << std::string("update_field gameplay ").append(raceName).append(" SpeedTrapList[")
        .append(std::to_string(speedtrapLoop)).append("] ").append(speedtrapName).append("\n");

        file << std::string("update_field gameplay ").append(raceName).append(" Children[")
        .append(std::to_string(sizeOfChildrenField + speedtrapLoop)).append("] ")
        .append(speedtrapName).append("\n");
    }

    file << std::string("copy_node gameplay ").append(raceName).append(" speedtraprace ").append(raceName)
    .append("_copy").append("\n");

    file << std::string("delete_node gameplay ").append(raceName).append("\n");

    file << std::string("rename_node gameplay ").append(raceName).append("_copy ")
    .append(raceName).append("\n");
}

void convertSpeedtrapToSprint(std::ofstream& file, int raceInteger, const std::string& raceName)
{
    //Variables for conversion
    std::string lastUpdateIndex;
    std::vector<std::string> speedtraps = getListOfRaceSpeedtraps(raceInteger);
    std::vector<std::pair<std::string, std::string>> childrenFieldUpdates =
            getListOfChildrenFieldUpdatesForSpeedtraps(raceInteger);

    file << std::string("delete_field gameplay ").append(raceName)
    .append(" SpeedTrapList").append("\n");

    for ( const std::string& speedtrap : speedtraps )
    { file << std::string("delete_node gameplay ").append(speedtrap).append("\n"); }

    if ( checkForField(raceInteger, 13) )
    {
        file << std::string("update_field gameplay ").append(raceName)
        .append(" EventIconType p2p").append("\n");
    }

    for ( const std::pair<std::string, std::string>& updatePair : childrenFieldUpdates )
    {
        if ( !updatePair.first.empty() )
        {
            file << std::string("update_field gameplay ").append(raceName).append(" Children[")
            .append(updatePair.second).append("] ").append(updatePair.first).append("\n");
        }

        lastUpdateIndex = updatePair.second;
    }

    file << std::string("resize_field gameplay ").append(raceName).append(" Children ")
    .append(std::to_string(std::stoi(lastUpdateIndex) + 1)).append("\n");

    file << std::string("copy_node gameplay ").append(raceName).append(" p2p ").append(raceName)
    .append("_copy").append("\n");

    file << std::string("delete_node gameplay ").append(raceName).append("\n");

    file << std::string("rename_node gameplay ").append(raceName).append("_copy ")
    .append(raceName).append("\n");
}

void randomizeSprintsAndSpeedtraps(std::ofstream& file, const std::string& raceType, int raceInteger,
                                   const std::string& raceName)
{
    if ( raceType == "sprint" )
    {
        if ( pickRandomNumber(0, 100) < 50 )
        { convertSprintToSpeedtrap(file, raceInteger, raceName); }
    }

    else
    {
        if ( pickRandomNumber(0, 100) < 50 )
        { convertSpeedtrapToSprint(file, raceInteger, raceName); }
    }
}

void removeUnnecessaryPrologueRaceFields(std::ofstream& file, const std::string& raceName)
{
    /** Called from either randomizePrologueRaces or randomizeRaces. Removes detrimental fields
      * from a given prologue race. Only takes arguments to print lines and returns no value.      */

    file << std::string("delete_field gameplay ").append(raceName).append(" ChanceOfRain").append("\n");
    file << std::string("delete_field gameplay ").append(raceName).append(" CatchUpSpread").append("\n");
    file << std::string("delete_field gameplay ").append(raceName).append(" CatchUpSkill").append("\n");

    //This field is only present on these races
    if ( raceName == "16_2_2_sprint" || raceName == "16_2_3_sprint")
    {
        file << std::string("delete_field gameplay ").append(raceName).append(" CatchUpDerivative").append("\n");
    }

    file << std::string("delete_field gameplay ").append(raceName).append(" DifficultyLevel").append("\n");
}

void convertPrologueRaceToRegularRace(std::ofstream& file, const std::string& raceName)
{
    /** Called from randomizeRaces. Removes the essential fields form prologue
      * races. Only takes arguments for printing lines and has no return values.    */

    file << std::string("delete_field gameplay ").append(raceName).append(" DDayRace").append("\n");
    file << std::string("delete_field gameplay ").append(raceName).append(" PlayerCarType").append("\n");

    //Call separate function for rest of the fields
    removeUnnecessaryPrologueRaceFields(file, raceName);
}

void updateRegularRace(std::ofstream& file, const std::string& raceName, const std::string& raceType,
                       int raceCashValue, const std::string& raceBin, int raceInteger,
                       const std::array<std::string, 41>& opponentList,
                       const std::array<std::string, 6>& startingOpponentList)
{
    /** Called from randomizeRaces if an originally regular race is chosen to be a regular
      * race. takes details needed from randomizeRaces to print its lines as arguments.        */

    //Replace regular opponents with ones for the current blacklist member, if race was from a different one
    if ( raceType != "tollbooth" )
    {
        if ( raceName.substr(0, 2) == "16" && raceName != "16_1_1_circuit" )
        { file << std::string("resize_field gameplay ").append(raceName).append(" Opponents 3").append("\n"); }

        std::vector<std::string> pickedOpponents;
        std::vector<std::string>::iterator opponentSearch;
        std::string pickedOpponent;

        if ( raceBin != "race_bin_15" && raceBin != "race_bin_14" )
        {
            for ( int innerLoop = 0; innerLoop < 3; innerLoop++ )
            {
                pickedOpponent = opponentList[pickRandomNumber(0, (int)opponentList.size() - 1)];
                opponentSearch = std::find(pickedOpponents.begin(), pickedOpponents.end(), pickedOpponent);

                if ( opponentSearch == pickedOpponents.end() )
                {
                    pickedOpponents.emplace_back(pickedOpponent);

                    file << std::string("update_field gameplay ").append(raceName).append(" Opponents[")
                    .append(std::to_string(innerLoop)).append("] ")
                    .append(opponentList[pickRandomNumber(0, (int)opponentList.size() - 1)])
                    .append("\n");
                }

                else { innerLoop--; continue; }
            }
        }

        else
        {
            for ( int innerLoop = 0; innerLoop < 3; innerLoop++ )
            {
                pickedOpponent = startingOpponentList[pickRandomNumber(0, (int)startingOpponentList.size() - 1)];
                opponentSearch = std::find(pickedOpponents.begin(), pickedOpponents.end(), pickedOpponent);

                if ( opponentSearch == pickedOpponents.end() )
                {
                    pickedOpponents.emplace_back(pickedOpponent);

                    file << std::string("update_field gameplay ").append(raceName).append(" Opponents[")
                    .append(std::to_string(innerLoop)).append("] ").append(pickedOpponent).append("\n");
                }

                else { innerLoop--; continue; }
            }
        }
    }

    //Randomize cash value for race
    if ( raceType != "drag" )
    {
        file << std::string("update_field gameplay ").append(raceName).append(" CashValue ")
        .append(std::to_string(pickRandomNumber(raceCashValue / 2, int(raceCashValue * 1.5))))
        .append("\n");
    }

    else
    {
        file << std::string("update_field gameplay ").append(raceName).append(" CashValue ")
        .append(std::to_string(pickRandomNumber(raceCashValue / 2, int(raceCashValue * 1.5))/4))
        .append("\n");
    }

    if ( checkForField(raceInteger, 4) )
    {
        file << std::string("delete_field gameplay ").append(raceName)
        .append(" PostRaceActivity").append("\n");
    }
}

void randomizeRaceIntro(std::ofstream& file, const std::string& raceName, int raceInteger, bool isBossRace)
{
    /** This function is called from randomizeRaces for any non-tollbooth race. Relies on
      * checkRaceStart to know which intros to choose. Takes details needed to print its lines
      * from randomizeRaces.                                                                        */

    //Universal variable
    std::string pickedIntro;

    //Check if field for intro exists in vlted race node
    if ( !checkForField(raceInteger, 8) )
    { file << std::string("add_field gameplay ").append(raceName).append(" IntroNIS").append("\n"); }

    //Run function to see how much space there is at race start
    int raceStart = checkRaceStart(raceInteger);

    if ( !isBossRace )
    {
        //Choose a start based on how wide the starting line is, except for tollbooths
        if ( raceStart == 1 )
        {
            switch(pickRandomNumber(1, 7))
            {
                case 1: pickedIntro = "GenericStart"; break;
                case 2: pickedIntro = "IntroNis01"; break;
                case 3: pickedIntro = "IntroNis03"; break;
                case 4: pickedIntro = "IntroNis04"; break;
                case 5: pickedIntro = "IntroNis06"; break;
                case 6: pickedIntro = "IntroNis07"; break;
                default: pickedIntro = "IntroNis08";
            }
        }

        else if ( raceStart == 2 )
        {
            switch(pickRandomNumber(1, 2))
            {
                case 1: pickedIntro = "IntroNis04"; break;
                default: pickedIntro = "IntroNis06";
            }
        }
    }

    else
    {
        if ( raceStart == 1 )
        {
            switch(pickRandomNumber(1, 9))
            {
                case 1: pickedIntro = "GenericStart"; break;
                case 2: pickedIntro = "IntroNis01"; break;
                case 3: pickedIntro = "IntroNis02"; break;
                case 4: pickedIntro = "IntroNis03"; break;
                case 5: pickedIntro = "IntroNis04"; break;
                case 6: pickedIntro = "IntroNis05"; break;
                case 7: pickedIntro = "IntroNis06"; break;
                case 8: pickedIntro = "IntroNis07"; break;
                default: pickedIntro = "IntroNis08";
            }
        }

        else if ( raceStart == 2 )
        {
            switch(pickRandomNumber(1, 4))
            {
                case 1: pickedIntro = "IntroNis02"; break;
                case 2: pickedIntro = "IntroNis04"; break;
                case 3: pickedIntro = "IntroNis05"; break;
                default: pickedIntro = "IntroNis06";
            }
        }
    }

    //Write chosen intro to the file
    file << std::string("update_field gameplay ").append(raceName).append(" IntroNIS ")
    .append(pickedIntro).append("\n");
}

void randomizeGeneralFields(std::ofstream& file, const std::string& raceName,
                            const std::unordered_map<int, float>& distanceMap,
                            const std::unordered_map<int, float>& timeMap,
                            int numberOfRaces, const std::string& raceType, int raceInteger,
                            int loop, int copChance)
{
    /** Called from randomizeRaces and randomizePrologue races, this function randomizes fields
      * that most races have and don't have a place with other functions. Only takes arguments needed
      * for its lines and returns no value.                                                                  */

    //Decide if race should have cops or not
    if ( !checkForField(raceInteger, 12) )
    {
        file << std::string("add_field gameplay ").append(raceName)
        .append(" CopsInRace").append("\n");
    }

    if ( pickRandomNumber(0, 100) < copChance )
    {
        file << std::string("update_field gameplay ").append(raceName)
        .append(" CopsInRace True").append("\n");
    }

    else
    {
        file << std::string("update_field gameplay ").append(raceName)
        .append(" CopsInRace False").append("\n");
    }

    //If not a drag, randomize traffic
    if ( raceType != "drag" )
    {
        if ( !checkForField(raceInteger, 9 ) )
        {
            file << std::string("add_field gameplay ").append(raceName)
            .append(" TrafficLevel").append("\n");
        }

        file << std::string("update_field gameplay ").append(raceName).append(" TrafficLevel ")
        .append(std::to_string(pickRandomNumber(0, 100))).append("\n");
    }

    //Roll for converting one race type to a different, similar one
    if ( raceType == "circuit" || raceType == "knockout" )
    { randomizeKOsAndCircuits(file, raceName, raceInteger, raceType, distanceMap, timeMap, loop, numberOfRaces); }

    else if ( raceType == "sprint" || raceType == "speedtrap" )
    { randomizeSprintsAndSpeedtraps(file, raceType, raceInteger, raceName); }
}
