//
// Created by Ted on 12/05/2024
//

#include <string>
#include <vector>
#include <fstream>
#include "GeneralFunctions.h"
#include "EventTriggerFunctions.h"

std::vector<std::string> getNewTriggerDetails(int raceInteger)
{
    /** Returns a vector with details to create a race trigger for the given race.  */

    std::vector<std::string> details;

    switch(raceInteger)
    {
        //Sonny races
        case 1:
            details.emplace_back("/engage/engagetrigger_circuit_15_1_1");
            return details;

        case 2:
            details.emplace_back("/engage/engagetrigger_sprint_15_2_1");
            return details;

        case 3:
            details.emplace_back("/engage/engagetrigger_knockout_15_3_1");
            return details;

        case 4:
            details.emplace_back("/engage/engagetrigger_circuit_15_1_2");
            return details;

        case 5:
            details.reserve(4);
            details.emplace_back("/engage/engagetrigger_circuit_15_1_1_r");
            details.emplace_back("468.6606");
            details.emplace_back("4527.372");
            details.emplace_back("230.126");
            return details;

        //Taz races
        case 6:
            details.emplace_back("/engage/engagetrigger_circuit_14_1_1");
            return details;

        case 7:
            details.emplace_back("/engage/engagetrigger_sprint_14_2_1");
            return details;

        case 8:
            details.emplace_back("/engage/engagetrigger_sprint_14_2_2");
            return details;

        case 9:
            details.emplace_back("/engage/engagetrigger_knockout_14_3_1");
            return details;

        case 10:
            details.emplace_back("/engage/engagetrigger_tollbooth_14_4_1");
            return details;

        case 11:
            details.emplace_back("/engage/engagetrigger_circuit_14_1_2");
            return details;

        case 12:
            details.emplace_back("/engage/engagetrigger_sprint_14_2_4");
            return details;

        case 13:
            details.reserve(4);
            details.emplace_back("/engage/engagetrigger_sprint_14_2_1_r");
            details.emplace_back("607.507");
            details.emplace_back("4195.572");
            details.emplace_back("196.3516");
            return details;

        //Vic races
        case 14:
            details.emplace_back("/engage/engagetrigger_sprint_13_2_1");
            return details;

        case 15:
            details.emplace_back("/engage/engagetrigger_knockout_13_3_1");
            return details;

        case 16:
            details.emplace_back("/engage/engagetrigger_knockout_13_3_2");
            return details;

        case 17:
            details.emplace_back("/engage/engagetrigger_tollbooth_13_4_1");
            return details;

        case 18:
            details.emplace_back("/engage/engagetrigger_tollbooth_13_4_2");
            return details;

        case 19:
            details.emplace_back("/engage/engagetrigger_speedtrap_13_5_1");
            return details;

        case 20:
            details.emplace_back("/engage/engagetrigger_speedtrap_13_5_2");
            return details;

        case 21:
            details.emplace_back("/engage/engagetrigger_sprint_13_2_3");
            return details;

        case 22:
            details.reserve(4);
            details.emplace_back("/engage/engagetrigger_sprint_14_2_2_r");
            details.emplace_back("256.0559");
            details.emplace_back("2683.329");
            details.emplace_back("175.4757");
            return details;

        //Izzy races
        case 23:
            details.emplace_back("/engage/engagetrigger_circuit_12_1_1");
            return details;

        case 24:
            details.emplace_back("/engage/engagetrigger_tollbooth_12_4_1");
            return details;

        case 25:
            details.emplace_back("/engage/engagetrigger_tollbooth_12_4_2");
            return details;

        case 26:
            details.emplace_back("/engage/engagetrigger_speedtrap_12_5_1");
            return details;

        case 27:
            details.emplace_back("/engage/engagetrigger_drag_12_7_3");
            return details;

        case 28:
            details.emplace_back("/engage/engagetrigger_sprint_13_2_2_r");
            return details;

        case 29:
            details.emplace_back("/engage/engagetrigger_sprint_14_2_3_r");
            return details;

        case 30:
            details.emplace_back("/engage/engagetrigger_12_2_1_sprint");
            return details;

        case 31:
            details.reserve(4);
            details.emplace_back("/engage/engagetrigger_circuit_12_1_2");
            details.emplace_back("1466.443");
            details.emplace_back("3742.286");
            details.emplace_back("189.0587");
            return details;

        //Big Lou races
        case 32:
            details.emplace_back("/engage/engagetrigger_sprint_11_2_1");
            return details;

        case 33:
            details.emplace_back("/engage/engagetrigger_circuit_11_1_1");
            return details;

        case 34:
            details.emplace_back("/engage/engagetrigger_speedtrap_11_5_1");
            return details;

        case 35:
            details.emplace_back("/engage/engagetrigger_tollbooth_11_4_2");
            return details;

        case 36:
            details.emplace_back("/engage/engagetrigger_tollbooth_11_4_1");
            return details;

        case 37:
            details.emplace_back("/engage/12_2_1_r_engage");
            return details;

        case 38:
            details.emplace_back("/engage/engagetrigger_speedtrap_11_5_2");
            return details;

        case 39:
            details.emplace_back("/engage/11_7_1_engage");
            return details;

        case 40:
            details.emplace_back("/engage/engagetrigger_11_1_2");
            return details;

        case 41:
            details.reserve(4);
            details.emplace_back("/engage/engagetrigger_circuit_12_1_2_r");
            details.emplace_back("1498.094");
            details.emplace_back("3757.771");
            details.emplace_back("189.1756");
            return details;

        //Baron races
        case 42:
            details.emplace_back("/engage/10_3_1_engage");
            return details;

        case 43:
            details.emplace_back("/engage/10_3_2_engage");
            return details;

        case 44:
            details.emplace_back("/engage/10_4_2_engage");
            return details;

        case 45:
            details.emplace_back("/engage/10_4_1_engage");
            return details;

        case 46:
            details.emplace_back("/engage/11_2_1_r_engage");
            return details;

        case 47:
            details.emplace_back("/engage/10_2_2_engage");
            return details;

        case 48:
            details.emplace_back("/engage/11_1_2_r_engage");
            return details;

        case 49:
            details.emplace_back("/engage/11_5_1_r_engage");
            return details;

        case 50:
            details.emplace_back("/engage/10_2_1_engage");
            return details;

        case 51:
            details.reserve(4);
            details.emplace_back("/engage/engagetrigger_drag_10_7_3");
            details.emplace_back("3284.491");
            details.emplace_back("-159.4646");
            details.emplace_back("23.73438");
            return details;

        //Earl races
        case 52:
            details.emplace_back("/engage/9_1_1_engage");
            return details;

        case 53:
            details.emplace_back("/engage/9_7_1_engage");
            return details;

        case 54:
            details.emplace_back("/engage/9_4_1_engage");
            return details;

        case 55:
            details.emplace_back("/engage/9_5_1_engage");
            return details;

        case 56:
            details.emplace_back("/engage/9_5_2_engage");
            return details;

        case 57:
            details.emplace_back("/engage/9_4_2_engage");
            return details;

        case 58:
            details.emplace_back("/engage/12_1_1_r_engage");
            return details;

        case 59:
            details.emplace_back("/engage/9_3_1_engage");
            return details;

        case 60:
            details.emplace_back("/engage/9_5_3_engage");
            return details;

        case 61:
            details.reserve(4);
            details.emplace_back("/engage/9_2_1_engage");
            details.emplace_back("4065.047");
            details.emplace_back("2852.6");
            details.emplace_back("23.84376");
            return details;

        //Jewels races
        case 62:
            details.emplace_back("/engage/8_3_1_engage");
            return details;

        case 63:
            details.emplace_back("/engage/13_3_1_r_engage");
            return details;

        case 64:
            details.emplace_back("/engage/8_5_1_engage");
            return details;

        case 65:
            details.emplace_back("/engage/8_5_2_engage");
            return details;

        case 66:
            details.emplace_back("/engage/8_2_2_engage");
            return details;

        case 67:
            details.emplace_back("/engage/10_4_2_r_engage");
            return details;

        case 68:
            details.emplace_back("/engage/9_4_1_r_tollbooth");
            return details;

        case 69:
            details.emplace_back("/engage/8_2_1_engage");
            return details;

        case 70:
            details.reserve(4);
            details.emplace_back("/engage/engagetrigger_drag_8_7_5_engage");
            details.emplace_back("829.7195");
            details.emplace_back("4407.375");
            details.emplace_back("210.5586");
            return details;

        //Kaze races
        case 71:
            details.emplace_back("/engage/7_2_1_engage");
            return details;

        case 72:
            details.emplace_back("/engage/7_4_3_engage");
            return details;

        case 73:
            details.emplace_back("/engage/7_5_1_engage");
            return details;

        case 74:
            details.emplace_back("/engage/7_4_1_engage");
            return details;

        case 75:
            details.emplace_back("/engage/7_3_1_engage");
            return details;

        case 76:
            details.emplace_back("/engage/16_1_1_r_engage");
            return details;

        case 77:
            details.emplace_back("/engage/8_2_1_r_engage");
            return details;

        case 78:
            details.emplace_back("/engage/7_1_1_engage");
            return details;

        case 79:
            details.emplace_back("/engage/7_4_2_engage");
            return details;

        case 80:
            details.emplace_back("/engage/7_7_4_engage");
            return details;

        case 81:
            details.emplace_back("/engage/7_2_2_engage");
            return details;

        case 82:
            details.reserve(4);
            details.emplace_back("/engage/7_2_3_engage");
            details.emplace_back("330.1035");
            details.emplace_back("3110.219");
            details.emplace_back("188.2231");
            return details;

        //Ming races
        case 83:
            details.emplace_back("/engage/6_2_2_engage");
            return details;

        case 84:
            details.emplace_back("/engage/6_4_1_engage");
            return details;

        case 85:
            details.emplace_back("/engage/6_5_1_engage");
            return details;

        case 86:
            details.emplace_back("/engage/6_2_1_engage");
            return details;

        case 87:
            details.emplace_back("/engage/6_4_2_engage");
            return details;

        case 88:
            details.emplace_back("/engage/6_3_1_engage");
            return details;

        case 89:
            details.emplace_back("/engage/14_3_1_r_engage");
            return details;

        case 90:
            details.emplace_back("/engage/6_2_3_engage");
            return details;

        case 91:
            details.emplace_back("/engage/6_5_3_engage");
            return details;

        case 92:
            details.emplace_back("/engage/7_7_1_r_engage");
            return details;

        case 93:
            details.emplace_back("/engage/7_4_1_r_engage");
            return details;

        case 94:
            details.emplace_back("/engage/6_1_1_engage");
            return details;

        case 95:
            details.reserve(4);
            details.emplace_back("/engage/6_5_2_engage");
            details.emplace_back("3260.248");
            details.emplace_back("3315.301");
            details.emplace_back("29");
            return details;

        //Webster races
        case 96:
            details.emplace_back("/engage/5_3_1_engage");
            return details;

        case 97:
            details.emplace_back("/engage/5_1_1_engage");
            return details;

        case 98:
            details.emplace_back("/engage/5_2_1_engage");
            return details;

        case 99:
            details.emplace_back("/engage/5_5_1_engage");
            return details;

        case 100:
            details.emplace_back("/engage/5_5_2_engage");
            return details;

        case 101:
            details.emplace_back("/engage/5_4_1_engage");
            return details;

        case 102:
            details.emplace_back("/engage/5_5_3_engage");
            return details;

        case 103:
            details.emplace_back("/engage/5_2_3_engage");
            return details;

        case 104:
            details.emplace_back("/engage/6_4_1_r_engage");
            return details;

        case 105:
            details.emplace_back("/engage/7_4_2_r_engage");
            return details;

        case 106:
            details.emplace_back("/engage/5_2_2_engage");
            return details;

        case 107:
            details.reserve(4);
            details.emplace_back("/engage/5_5_4_engage");
            details.emplace_back("1032.555");
            details.emplace_back("2133.215");
            details.emplace_back("152.5");
            return details;

        case 108:
            details.reserve(4);
            details.emplace_back("/engage/5_2_1_r_engage");
            details.emplace_back("1032.555");
            details.emplace_back("2133.215");
            details.emplace_back("153");
            return details;

        //JV races
        case 109:
            details.emplace_back("/engage/4_4_1_engage");
            return details;

        case 110:
            details.emplace_back("/engage/4_1_1_engage");
            return details;

        case 111:
            details.emplace_back("/engage/4_3_1_engage");
            return details;

        case 112:
            details.emplace_back("/engage/4_5_3_engage");
            return details;

        case 113:
            details.emplace_back("/engage/4_5_1_engage");
            return details;

        case 114:
            details.emplace_back("/engage/5_5_2_r_engage");
            return details;

        case 115:
            details.emplace_back("/engage/7_2_2_r_engage");
            return details;

        case 116:
            details.emplace_back("/engage/6_3_1_r_engage");
            return details;

        case 117:
            details.emplace_back("/engage/9_1_1_r_engage");
            return details;

        case 118:
            details.emplace_back("/engage/5_4_1_r_engage");
            return details;

        case 119:
            details.emplace_back("/engage/7_4_3_r_engage");
            return details;

        case 120:
            details.emplace_back("/engage/4_5_2_engage");
            return details;

        case 121:
            details.reserve(4);
            details.emplace_back("/engage/4_7_4_engage");
            details.emplace_back("2133.399");
            details.emplace_back("1456.398");
            details.emplace_back("154.3223");
            return details;

        case 122:
            details.reserve(4);
            details.emplace_back("/engage/4_5_1_r_engage");
            details.emplace_back("996.0981");
            details.emplace_back("1721.142");
            details.emplace_back("153.9122");
            return details;

        //Ronnie races
        case 123:
            details.emplace_back("/engage/3_2_1_engage");
            return details;

        case 124:
            details.emplace_back("/engage/3_3_1_engage");
            return details;

        case 125:
            details.emplace_back("/engage/3_1_1_engage");
            return details;

        case 126:
            details.emplace_back("/engage/3_4_1_engage");
            return details;

        case 127:
            details.emplace_back("/engage/7_2_1_r_engage");
            return details;

        case 128:
            details.emplace_back("/engage/4_3_1_r_engage");
            return details;

        case 129:
            details.emplace_back("/engage/3_5_1_engage");
            return details;

        case 130:
            details.emplace_back("/engage/3_5_2_engage");
            return details;

        case 131:
            details.emplace_back("/engage/3_4_1_r_engage");
            return details;

        case 132:
            details.emplace_back("/engage/4_4_1_r_engage");
            return details;

        case 133:
            details.emplace_back("/engage/4_2_1_r_engage");
            return details;

        case 134:
            details.emplace_back("/engage/3_7_3_engage");
            return details;

        case 135:
            details.emplace_back("/engage/3_1_2_r_engage");
            return details;

        case 136:
            details.reserve(4);
            details.emplace_back("/engage/3_2_2_engage");
            details.emplace_back("4322.66");
            details.emplace_back("338.3622");
            details.emplace_back("34.65527");
            return details;

        case 137:
            details.reserve(4);
            details.emplace_back("/engage/3_1_2_engage");
            details.emplace_back("3090.032");
            details.emplace_back("267.1677");
            details.emplace_back("12.18066");
            return details;

        //Bull races
        case 138:
            details.emplace_back("/engage/2_1_1_circuit");
            return details;

        case 139:
            details.emplace_back("/engage/2_1_1_r_engage");
            return details;

        case 140:
            details.emplace_back("/engage/2_4_1_engage");
            return details;

        case 141:
            details.emplace_back("/engage/2_4_2_engage");
            return details;

        case 142:
            details.emplace_back("/engage/2_4_3_engage");
            return details;

        case 143:
            details.emplace_back("/engage/2_5_1_engage");
            return details;

        case 144:
            details.emplace_back("/engage/3_2_1_r_engage");
            return details;

        case 145:
            details.emplace_back("/engage/3_3_1_r_engage");
            return details;

        case 146:
            details.emplace_back("/engage/3_3_2_r_engage");
            return details;

        case 147:
            details.emplace_back("/engage/5_1_1_r_engage");
            return details;

        case 148:
            details.emplace_back("/engage/5_5_1_r_engage");
            return details;

        case 149:
            details.emplace_back("/engage/2_7_1_engage");
            return details;

        case 150:
            details.emplace_back("/engage/3_1_1_r_engage");
            return details;

        case 151:
            details.reserve(4);
            details.emplace_back("/engage/9_2_2_r_engage");
            details.emplace_back("2296.511");
            details.emplace_back("1446.748");
            details.emplace_back("147.9756");
            return details;

        case 152:
            details.reserve(4);
            details.emplace_back("/engage/2_2_1_engage");
            details.emplace_back("2420.7");
            details.emplace_back("444.816");
            details.emplace_back("94.24805");
            return details;

        //Razor races
        case 153:
            details.emplace_back("/engage/1_1_1_engage");
            return details;

        case 154:
            details.emplace_back("/engage/1_2_1_engage");
            return details;

        case 155:
            details.emplace_back("/engage/1_2_2_engage");
            return details;

        case 156:
            details.emplace_back("/engage/1_2_4_engage");
            return details;

        case 157:
            details.emplace_back("/engage/1_3_1_engage");
            return details;

        case 158:
            details.emplace_back("/engage/1_4_1_engage");
            return details;

        case 159:
            details.emplace_back("/engage/1_4_2_engage");
            return details;

        case 160:
            details.emplace_back("/engage/1_5_1_engage");
            return details;

        case 161:
            details.emplace_back("/engage/1_5_3_engage");
            return details;

        case 162:
            details.emplace_back("/engage/2_2_1_r_engage");
            return details;

        case 163:
            details.emplace_back("/engage/2_4_3_r_engage");
            return details;

        case 164:
            details.emplace_back("/engage/1_5_2_engage");
            return details;

        case 165:
            details.reserve(4);
            details.emplace_back("/engage/1_7_3_engage");
            details.emplace_back("1856.957");
            details.emplace_back("-408.0294");
            details.emplace_back("111.5947");
            return details;

        case 166:
            details.reserve(4);
            details.emplace_back("/engage/4_2_1_engage");
            details.emplace_back("1545.087");
            details.emplace_back("-705.7032");
            details.emplace_back("114.9922");
            return details;

        case 167:
            details.reserve(4);
            details.emplace_back("/engage/1_1_2_engage");
            details.emplace_back("1391.893");
            details.emplace_back("3704.417");
            details.emplace_back("194.6963");
            return details;

        case 168:
            details.reserve(4);
            details.emplace_back("/engage/1_2_3_engage");
            details.emplace_back("1571.265");
            details.emplace_back("3793.1");
            details.emplace_back("186.8916");
            return details;

        //Prologue races
        case 169:
            details.reserve(4);
            details.emplace_back("/engage/16_1_1_engage");
            details.emplace_back("1650.307");
            details.emplace_back("384.4418");
            details.emplace_back("93.79443");
            return details;

        case 170:
            details.reserve(4);
            details.emplace_back("/engage/16_2_2_engage");
            details.emplace_back("1043.669");
            details.emplace_back("104.663");
            details.emplace_back("101.4483");
            return details;

        case 171:
            details.reserve(4);
            details.emplace_back("/engage/16_2_3_engage");
            details.emplace_back("2818.152");
            details.emplace_back("615.9679");
            details.emplace_back("42.8418");
            return details;

        //Collectors edition races
        case 172:
            details.reserve(4);
            details.emplace_back("/engage/collectors_1_1_engage");
            details.emplace_back("2592.81");
            details.emplace_back("-324.4814");
            details.emplace_back("114.7715");
            return details;

        case 173:
            details.reserve(4);
            details.emplace_back("/engage/collectors_2_2_engage");
            details.emplace_back("1149.266");
            details.emplace_back("4408.48");
            details.emplace_back("213.8545");
            return details;

        case 174:
            details.reserve(4);
            details.emplace_back("/engage/collectors_2_1_engage");
            details.emplace_back("4347.913");
            details.emplace_back("204.7836");
            details.emplace_back("23.82129");
            return details;

        //Used for track expansion races
        default:
            return details;
    }
}

bool hasTrigger(int raceInteger)
{
    /** Returns a bool based on whether a trigger node exists in vlted for
      * the race name provided. Uses race map to create an integer for checks.     */

    switch(raceInteger)
    {
        case 5: case 13: case 22: case 31: case 41: case 51: case 61: case 70: case 82: case 95:
        case 107: case 108: case 121: case 122: case 136: case 137: case 151: case 152: case 165:
        case 166: case 167: case 168: case 169: case 170: case 171: case 172: case 173:
        case 174: return false;

        default: return true;
    }
}

void updateRaceTriggers(std::ofstream& file, bool hasBossRaceTrigger, const std::string& raceBin,
                        const std::vector<std::pair<std::string, int>>& chosenTriggers)
{
    /** This function is called from randomizeRaces if a vlted trigger node needs its
      * fields updated. Takes only data needed to print the lines from randomizeRaces
      * as arguments.                                                                       */

    file << std::string("# updating race triggers for ").append(raceBin).append("\n");

    //Resize engage node fields before doing anything
    file << std::string("resize_field gameplay ").append(raceBin).append("/engage Children ")
    .append(std::to_string(chosenTriggers.size())).append("\n");

    file << std::string("resize_field gameplay ").append(raceBin).append("/engage RaceTriggers ")
    .append(std::to_string(chosenTriggers.size())).append("\n");

    for ( int triggerLoop = 0; triggerLoop < chosenTriggers.size(); triggerLoop++ )
    {
        //Change lines in race_bin engage node
        file << std::string("update_field gameplay ").append(raceBin)
        .append("/engage Children[").append(std::to_string(triggerLoop))
        .append("] ").append(chosenTriggers[triggerLoop].first).append("\n");

        file << std::string("update_field gameplay ").append(raceBin)
        .append("/engage RaceTriggers[").append(std::to_string(triggerLoop))
        .append("] ").append(chosenTriggers[triggerLoop].first).append("\n");

        //Change vault if race is originally from a different blacklist member
        if ( raceBin != chosenTriggers[triggerLoop].first.substr(0, 11) )
        {
            file << std::string("change_vault gameplay ").append(chosenTriggers[triggerLoop].first)
            .append(" ").append(raceBin).append("\n");
        }

        //Delete InitiallyUnlocked field for any regular races, if present
        if ( triggerLoop != chosenTriggers.size() - 1 || !hasBossRaceTrigger )
        {
            if ( checkForField(chosenTriggers[triggerLoop].second, 6) )
            {
                file << std::string("delete_field gameplay ").append(chosenTriggers[triggerLoop].first)
                .append(" InitiallyUnlocked").append("\n");
            }
        }
    }

    //If a trigger exists for the first boss race, make it hidden until requirements are met
    if ( hasBossRaceTrigger )
    {
        if ( !checkForField(chosenTriggers.back().second, 6) )
        {
            file << std::string("add_field gameplay ").append(chosenTriggers.back().first)
            .append(" InitiallyUnlocked").append("\n");
        }

        file << std::string("update_field gameplay ").append(chosenTriggers.back().first)
        .append(" InitiallyUnlocked False").append("\n");
    }

    file << std::string("\n");
}

void createRaceTrigger(std::ofstream& file, const std::string& raceName, const std::string& raceType,
                       const std::string& raceBin, std::vector<std::string> triggerDetails, const std::string& prefix)
{
    /** This function is called from randomizeRaces if a vlted trigger node needs to be
      * created for the race. Takes only data needed to print the lines from randomizeRaces
      * as arguments.                                                                           */

    //Write and update all lines needed for trigger node
    file << std::string("add_node gameplay engagetrigger_").append(raceType)
    .append(" ").append(prefix).append(triggerDetails[0])
    .append("\n");

    file << std::string("change_vault gameplay ").append(prefix)
    .append(triggerDetails[0]).append(" ").append(raceBin).append("\n");

    file << std::string("add_field gameplay ").append(prefix)
    .append(triggerDetails[0]).append(" Name").append("\n");

    file << std::string("update_field gameplay ").append(prefix)
    .append(triggerDetails[0]).append(" Name ").append(prefix)
    .append(triggerDetails[0]).append("\n");

    file << std::string("update_field gameplay ").append(prefix)
    .append(triggerDetails[0]).append(" CollectionName ").append(prefix)
    .append(triggerDetails[0]).append("\n");

    file << std::string("add_field gameplay ").append(prefix)
    .append(triggerDetails[0]).append(" TargetActivity").append("\n");

    file << std::string("update_field gameplay ").append(prefix)
    .append(triggerDetails[0]).append(" TargetActivity ").append(raceName).append("\n");

    file << std::string("add_field gameplay ").append(prefix)
    .append(triggerDetails[0]).append(" Template").append("\n");

    file << std::string("update_field gameplay ").append(prefix)
    .append(triggerDetails[0]).append(" Template False").append("\n");

    file << std::string("add_field gameplay ").append(prefix)
    .append(triggerDetails[0]).append(" Position").append("\n");

    file << std::string("update_field gameplay ").append(prefix)
    .append(triggerDetails[0]).append(" Position X ").append(triggerDetails[1]).append("\n");

    file << std::string("update_field gameplay ").append(prefix)
    .append(triggerDetails[0]).append(" Position Y ").append(triggerDetails[2]).append("\n");

    file << std::string("update_field gameplay ").append(prefix)
    .append(triggerDetails[0]).append(" Position Z ").append(triggerDetails[3]).append("\n");
}
