#include <memory>
#include <random>
#include <fstream>
#include <unordered_map>
#include <utility>
#include <array>
#include <thread>
#include <iomanip>
#include <iostream>
#include "ListFunctions.h"
#include "EventTriggerFunctions.h"
#include "GeneralFunctions.h"
#include "RaceFunctions.h"
#include "BossRaceMarkerFunctions.h"
#include "PursuitFunctions.h"
#include "FreeRoamFunctions.h"
#include "NodeConversionFunctions.h"

int getSizeOfChildrenFieldForChapters(const std::string& raceBin, int numberOfOriginalRaces)
{
    if ( raceBin == "race_bin_15" ) { return 13 + (numberOfOriginalRaces - 6); }
    else if ( raceBin == "race_bin_14" ) { return 15 + (numberOfOriginalRaces - 6); }
    else if ( raceBin == "race_bin_13" || raceBin == "race_bin_08" ) { return 16 + (numberOfOriginalRaces - 7); }
    else if ( raceBin == "race_bin_12" ) { return 17 + (numberOfOriginalRaces - 7); }

    else if ( raceBin == "race_bin_11" || raceBin == "race_bin_10" || raceBin == "race_bin_09" )
    { return 18 + (numberOfOriginalRaces - 8); }

    else if ( raceBin == "race_bin_07" ) { return 20 + (numberOfOriginalRaces - 10); }
    else if ( raceBin == "race_bin_06" ) { return 21 + (numberOfOriginalRaces - 11); }
    else if ( raceBin == "race_bin_05" ) { return 21 + (numberOfOriginalRaces - 10); }
    else if ( raceBin == "race_bin_04" ) { return 22 + (numberOfOriginalRaces - 11); }
    else if ( raceBin == "race_bin_03" || raceBin == "race_bin_02" ) { return 22 + (numberOfOriginalRaces - 12); }
    else { return 24 + (numberOfOriginalRaces - 11); }
}

std::vector<std::string> updateNumberOfChapterRaces(std::ofstream& file, int numberOfRaces, int numberOfOriginalRaces,
                                int numberOfBossRaces, int numberOfOriginalBossRaces,
                                const std::string& raceBin, std::vector<std::string> bossIndexes)
{
    std::vector<int> possibleMinimumRaceWins;
    float numberOfRacesFloat;
    numberOfRacesFloat = (float)numberOfRaces;

    file << std::string("# changing number of races for ").append(raceBin).append("\n");

    if ( numberOfRaces != numberOfOriginalRaces || numberOfBossRaces != numberOfOriginalBossRaces
         || raceBin == "race_bin_15" )
    {
        if ( raceBin != "race_bin_15" )
        {
            file << std::string("resize_field gameplay ").append(raceBin).append(" Children ")
            .append(std::to_string((numberOfBossRaces - numberOfOriginalBossRaces) +
            (numberOfRaces - numberOfOriginalRaces) + getSizeOfChildrenFieldForChapters
            (raceBin, numberOfOriginalRaces))).append("\n");
        }

        else
        {
            file << std::string("resize_field gameplay ").append(raceBin).append(" Children ")
            .append(std::to_string((numberOfBossRaces - numberOfOriginalBossRaces) +
            (numberOfRaces - numberOfOriginalRaces) + getSizeOfChildrenFieldForChapters
            (raceBin, numberOfOriginalRaces) + 3 )).append("\n");
        }

        if ( numberOfRaces != numberOfOriginalRaces || raceBin == "race_bin_15" )
        {
            file << std::string("resize_field gameplay ").append(raceBin).append(" WorldRaces ")
            .append(std::to_string(numberOfRaces)).append("\n");
        }

        if ( numberOfBossRaces != numberOfOriginalBossRaces )
        {
            file << std::string("resize_field gameplay ").append(raceBin).append(" BossRaces ")
            .append(std::to_string(numberOfBossRaces)).append("\n");
        }

        int differenceBetweenWouldBeChildrenFieldSizeAndOriginalSize =
                (numberOfRaces - numberOfOriginalRaces) + (numberOfBossRaces - numberOfOriginalBossRaces);

        if ( differenceBetweenWouldBeChildrenFieldSizeAndOriginalSize > 0 )
        {
            for ( int loop = 0; loop < differenceBetweenWouldBeChildrenFieldSizeAndOriginalSize; loop++ )
            { bossIndexes.push_back(std::to_string(std::stoi(bossIndexes.back()) + 1)); }
        }

        else if ( differenceBetweenWouldBeChildrenFieldSizeAndOriginalSize < 0)
        {
            for ( int loop = 0; loop > differenceBetweenWouldBeChildrenFieldSizeAndOriginalSize; loop-- )
            { bossIndexes.erase(bossIndexes.begin() + (int)bossIndexes.size()); }
        }
    }

    if ( numberOfRaces != 1 )
    {
        for ( int loop = 0; loop < numberOfRaces; loop++ )
        {
            if ( ((float)loop + 1) / numberOfRacesFloat >= 0.25 && ((float)loop + 1) / numberOfRacesFloat <= 0.50 )
            { possibleMinimumRaceWins.emplace_back(loop + 1); }
        }
    }

    else { possibleMinimumRaceWins.emplace_back(1); }

    file << std::string("update_field gameplay ").append(raceBin).append(" RequiredRacesWon ")
    .append(std::to_string(possibleMinimumRaceWins[pickRandomNumber(0,
    (int)possibleMinimumRaceWins.size() - 1)])).append("\n\n");

    return bossIndexes;
}

void randomizeOpponents(const std::array<std::string, 41>& regularOpponentList,
                        const std::array<std::string, 18>& scriptedOpponentList,
                        const std::array<std::string, 6>& startingOpponentList,
                        const std::array<std::string, 35>& aiCarList)
{
    //Variables
    std::ofstream file;
    file.open("TERandomized.nfsms", std::ios_base::app);
    int newSkillLevel;
    int averageSkillLevel = 30;
    double averageSkillLevelFloat = 30;
    std::vector<std::string> fullOpponentList;

    //These value are used for the scripted Razor opponents
    float prologueRazorPerformanceField = static_cast<float>(pickRandomNumber(0, 10))/10;
    int prologueRazorSkillLevelField = pickRandomNumber(0, 35);

    fullOpponentList.reserve(scriptedOpponentList.size());
    for ( const std::string& opponent : scriptedOpponentList ) { fullOpponentList.emplace_back(opponent); }

    fullOpponentList.reserve(regularOpponentList.size());
    for ( const std::string& opponent : regularOpponentList ) { fullOpponentList.emplace_back(opponent); }

    fullOpponentList.reserve(startingOpponentList.size());
    for ( const std::string& opponent : startingOpponentList ) { fullOpponentList.emplace_back(opponent); }

    file << std::string("# AI difficulty and cars for opponents are randomized here").append("\n");

    for ( int loop = 0; loop < fullOpponentList.size(); loop++ )
    {
        //Change vault to gpcore for non-scripted opponents, which is accessible from all races
        if ( loop < 3 || loop > 17 )
        {
            file << std::string("change_vault gameplay ").append(fullOpponentList[loop])
            .append(" gpcore").append("\n");
        }

        //Set skill level based on current average
        if ( averageSkillLevel < 35 ) { newSkillLevel = pickRandomNumber(0, 35 + averageSkillLevel ); }
        else if ( averageSkillLevel > 65 ) { newSkillLevel = pickRandomNumber(averageSkillLevel - 35, 100); }
        else { newSkillLevel = pickRandomNumber(averageSkillLevel - 35, averageSkillLevel + 35); }

        file << std::string("update_field gameplay ").append(fullOpponentList[loop]).append(" SkillLevel ")
        .append(std::to_string(newSkillLevel)).append("\n");

        //Add performance scaling field to opponents who don't have it
        if ( loop < 3 || (loop > 17 && loop < 20) )
        {
            file << std::string("add_field gameplay ").append(fullOpponentList[loop])
            .append(" 0xb1ece070").append("\n");
        }

        //All opponents except the starting ones have this field randomized
        if (  loop != 3 && loop != 4 && loop < 59 )
        {
            file << std::string("update_field gameplay ").append(fullOpponentList[loop]).append(" 0xb1ece070 ");
            file << std::setprecision(2) << static_cast<float>(pickRandomNumber(0, 10))/10;
            file << std::string("\n");
        }

        //All boss opponent cars remain preset, but the exact car is randomized
        if ( loop < 20 )
        {
            file << std::string("update_field gameplay ").append(fullOpponentList[loop])
            .append(" PresetRide ").append(aiCarList[pickRandomNumber(0, (int)aiCarList.size() - 1)])
            .append("\n");
        }

        //Pool of opponents for regular races have a set chance of using fixed cars
        else
        {
            if ( loop < 59 && pickRandomNumber(0, 100) < 50 )
            {
                file << std::string("add_field gameplay ").append(fullOpponentList[loop])
                .append(" PresetRide").append("\n");

                file << std::string("update_field gameplay ").append(fullOpponentList[loop])
                .append(" PresetRide ").append(aiCarList[pickRandomNumber(0, (int) aiCarList.size() - 1)])
                .append("\n");
            }
        }

        //Check for points in loop where skill should be increased or decreased
        if ( loop != 3 && loop != 17 && loop != 19 )
        {
            if ( loop < 20 )
            {
                averageSkillLevelFloat = averageSkillLevelFloat + 6.20;
                averageSkillLevel = (int)round(averageSkillLevelFloat);
            }

            else
            {
                averageSkillLevelFloat = averageSkillLevelFloat - 2.11;
                averageSkillLevel = (int)round(averageSkillLevelFloat);
            }
        }

        //Check for points where average skill should be reset
        else
        {
            if ( loop == 3 )
            {
                averageSkillLevelFloat = 0;
                averageSkillLevel = 0;
            }

            else if ( loop == 17 )
            {
                averageSkillLevelFloat = 42;
                averageSkillLevel = 42;
            }

            else
            {
                averageSkillLevelFloat = 100;
                averageSkillLevel = 100;
            }
        }
    }

    //Modify prologue Razor opponent values while maintaining consistency
    file << std::string("update_field gameplay 16_2_1_d_day_intro/opponent SkillLevel ")
    .append(std::to_string(prologueRazorSkillLevelField)).append("\n");

    file << std::string("add_field gameplay 16_2_1_d_day_intro/opponent 0xb1ece070").append("\n");

    file << std::string("update_field gameplay 16_2_1_d_day_intro/opponent 0xb1ece070 ")
    .append(std::to_string(prologueRazorPerformanceField)).append("\n");

    file << std::string("update_field gameplay 16_1_0_partial_dday/razor SkillLevel ")
    .append(std::to_string(prologueRazorSkillLevelField)).append("\n");

    file << std::string("add_field gameplay 16_1_0_partial_dday/razor 0xb1ece070").append("\n");

    file << std::string("update_field gameplay 16_1_0_partial_dday/razor 0xb1ece070 ")
    .append(std::to_string(prologueRazorPerformanceField)).append("\n");

    //Tweak a few unnecessary fields for prologue opponents
    file << std::string("delete_field gameplay 16_1_1_circuit/opponent ForceStartPosition").append("\n");
    file << std::string("delete_field gameplay 16_1_1_circuit/opponent Children").append("\n");
    file << std::string("delete_field gameplay 16_2_1_d_day_intro/opponent ForceStartPosition").append("\n");
    file << std::string("delete_field gameplay 16_2_2_sprint/ronnie_mccrae ForceStartPosition").append("\n");
    file << std::string("delete_field gameplay 16_2_2_sprint/ronnie_mccrae Children").append("\n");
    file << std::string("delete_field gameplay 16_2_3_sprint/toru_sato Children").append("\n\n");

    file.close();
}

std::vector<std::pair<std::string, bool>> randomizePrologueRaces(int numberOfRaces,
                          std::vector<std::pair<std::string, bool>> races, int raceCashValue,
                          const std::unordered_map<std::string, int>& raceMap,
                          const std::array<std::string, 41>& opponentList, std::array<std::string, 73> carList,
                          const std::unordered_map<int, float>& distanceMap,
                          const std::unordered_map<int, float>& timeMap,
                          const std::array<std::string, 35>& aiCarList, bool allKnockoutsConvertedToCircuits,
                          bool allSpeedtrapsConvertedToSprints, bool maximumTrafficDensity,
                          bool copsOnAllTrackExpansionRaces)
{
    //Initial variables
    std::ofstream file;
    std::ofstream& fileReference = file;
    int pickedRace;
    std::unordered_map<std::string, int>::const_iterator raceInteger;
    std::string raceName;
    std::string fullRaceName;
    std::string raceType;
    std::string emptyPostRaceActivityField;
    std::string pickedMarker;
    int copChance = pickRandomNumber(0, 75);
    const std::string& pickedRazorCar = aiCarList[pickRandomNumber(0, (int)aiCarList.size() - 1)];
    std::string pickedPlayerCar = carList[pickRandomNumber(0, (int)carList.size() - 1)];
    const std::string& pickedRogCar = aiCarList[pickRandomNumber(0, (int)aiCarList.size() - 1)];
    std::array<std::string, 12> fmvs = getListOfFMVs();

    file.open("TERandomized.nfsms", std::ios_base::app);

    //Prologue Razor races and final chase are set to the chosen car
    file << std::string("# set car for events not in the pool and randomize scripted opponents").append("\n");

    file << std::string("update_field gameplay 16_1_0_partial_dday PlayerCarType ")
    .append(pickedPlayerCar).append("\n");

    file << std::string("update_field gameplay 16_2_1_d_day_intro PlayerCarType ")
    .append(pickedPlayerCar).append("\n");

    file << std::string("add_field gameplay 16_1_0_partial_dday PlayerCarPerformance").append("\n");
    file << std::string("update_field gameplay 16_1_0_partial_dday PlayerCarPerformance 0.5").append("\n");

    file << std::string("add_field gameplay 16_2_1_d_day_intro PlayerCarPerformance").append("\n");
    file << std::string("update_field gameplay 16_2_1_d_day_intro PlayerCarPerformance 0.5").append("\n");

    file << std::string("update_field gameplay race_bin_01/epic_pursuit PlayerCarType ")
    .append(pickedPlayerCar).append("\n");

    file << std::string("add_field gameplay race_bin_01/epic_pursuit PlayerCarPerformance").append("\n");
    file << std::string("update_field gameplay race_bin_01/epic_pursuit PlayerCarPerformance 1").append("\n");

    //Use same car for all prologue Razor nodes and randomize Rogs car
    file << std::string("update_field gameplay 16_2_1_d_day_intro/opponent PresetRide ")
    .append(pickedRazorCar).append("\n");

    file << std::string("update_field gameplay 16_1_0_partial_dday/razor PresetRide ")
    .append(pickedRazorCar).append("\n");

    file << std::string("update_field gameplay 16_nis_rog_razor/razor PresetRide ")
    .append(pickedRazorCar).append("\n");

    file << std::string("update_field gameplay 16_nis_rog_razor/rog PresetRide ")
    .append(pickedRogCar).append("\n");

    file << std::string("update_field gameplay 16_nis_rog_razor/rog PresetRide ")
    .append(pickedRogCar).append("\n");

    file << std::string("update_field gameplay 16_1_1_circuit/opponent PresetRide ")
    .append(pickedRogCar).append("\n");

    file << std::string("update_field gameplay race_bin_01/razor_callahan PresetRide ")
    .append(pickedPlayerCar).append("\n\n");

    for ( int loop = 0; loop < numberOfRaces; loop++ )
    {
        //Writes a comment that says which race node was chosen and as which race in the text file
        file << std::string("# prologue, race ").append(std::to_string(loop + 1)).append("\n");

        //Pick race at random and retrieve its integer from raceMap
        pickedRace = pickRandomNumber(0, races.size() - 1); // NOLINT(cppcoreguidelines-narrowing-conversions)
        raceName = races[pickedRace].first;
        raceInteger = raceMap.find(raceName);

        //Race type is used both for naming triggers and knowing which fields to randomize later
        raceType = checkRaceType(raceInteger->second);

        //Updates vault for race if originally from a blacklist member
        if ( raceName.substr(0, 2) != "16" )
        {
            convertToPrologueRace(fileReference, raceName, raceInteger->second, raceCashValue);

            if ( raceInteger->second < 172 )
            {
                //If vanilla race with trigger, delete it
                if ( hasTrigger(raceInteger->second) )
                {
                    std::vector<std::string> triggerDetails = getNewTriggerDetails(raceInteger->second);

                    file << std::string("delete_node gameplay ").append(raceName.substr(0, 11))
                    .append(triggerDetails[0]).append("\n");
                }
            }
        }

        else { removeUnnecessaryPrologueRaceFields(fileReference, raceName); }

        //Deal with PostRaceActivity fields and opponents depending on current cycle
        switch(loop)
        {
            case 0:
                file << std::string("update_field gameplay 16_1_0_partial_dday PostRaceActivity ")
                .append(raceName).append("\n");

                emptyPostRaceActivityField = raceName;

                if ( raceType != "tollbooth" )
                {
                    if ( !races[pickedRace].second )
                    {
                        file << std::string("resize_field gameplay ").append(raceName)
                        .append(" Opponents 1").append("\n");
                    }

                    file << std::string("update_field gameplay ").append(raceName)
                    .append(" Opponents[0] 16_2_2_sprint/ronnie_mccrae").append("\n");
                }

                break;

            case 1:
                file << std::string("update_field gameplay ").append(emptyPostRaceActivityField)
                .append(" PostRaceActivity ").append(raceName).append("\n");

                emptyPostRaceActivityField = raceName;

                if ( raceType != "tollbooth" )
                {
                    if ( !races[pickedRace].second && raceName != "16_2_3_sprint" && raceName != "16_2_2_sprint" )
                    {
                        file << std::string("resize_field gameplay ").append(raceName)
                        .append(" Opponents 1").append("\n");
                    }

                    file << std::string("update_field gameplay ").append(raceName)
                    .append(" Opponents[0] 16_2_3_sprint/toru_sato").append("\n");
                }

                break;

            default:
                file << std::string("update_field gameplay ").append(emptyPostRaceActivityField)
                .append(" PostRaceActivity ").append(raceName).append("\n");

                file << std::string("update_field gameplay ").append(raceName)
                .append(" PostRaceActivity 16_nis_rog_razor").append("\n");

                if ( raceType != "tollbooth" )
                {
                    if ( races[pickedRace].second || raceName == "16_2_3_sprint" || raceName == "16_2_2_sprint" )
                    {
                        file << std::string("resize_field gameplay ").append(raceName)
                        .append(" Opponents 3").append("\n");
                    }

                    for ( int opponentLoop = 0; opponentLoop < 2; opponentLoop++ )
                    {
                        file << std::string("update_field gameplay ").append(raceName).append(" Opponents[")
                        .append(std::to_string(opponentLoop)).append("] ")
                        .append(opponentList[pickRandomNumber(0, (int)opponentList.size() - 1)])
                        .append("\n");
                    }

                    file << std::string("update_field gameplay ").append(raceName)
                    .append(" Opponents[2] 16_1_1_circuit/opponent").append("\n");
                }
        }

        //FMVs are randomized here
        file << std::string("update_field gameplay ").append(raceName).append(" IntroMovie ")
        .append(fmvs[pickRandomNumber(0, (int)fmvs.size() - 1)]).append("\n");

        //Function responsible for intros is called for any non-tollbooth race
        if ( raceType != "tollbooth" && raceName != "16_1_1_circuit" )
        {
            switch(loop)
            {
                case 0: case 1:
                    randomizeRaceIntro(fileReference, raceName, raceInteger->second, true);
                    break;

                default:
                    randomizeRaceIntro(fileReference, raceName, raceInteger->second, false);
            }
        }

        randomizeGeneralFields(fileReference, raceName, distanceMap, timeMap, numberOfRaces, raceType,
            raceInteger->second, loop, copChance, allKnockoutsConvertedToCircuits, allSpeedtrapsConvertedToSprints,
            maximumTrafficDensity, copsOnAllTrackExpansionRaces);

        //M3 is changed for a random preset car
        if ( !checkForField(raceInteger->second, 11) )
        { file << std::string("add_field gameplay ").append(raceName).append(" PlayerCarType").append("\n"); }

        file << std::string("update_field gameplay ").append(raceName)
        .append(" PlayerCarType ").append(pickedPlayerCar).append("\n");

        //Car performance is reduced in prologue
        file << std::string("add_field gameplay ").append(raceName).append(" PlayerCarPerformance")
        .append("\n");

        file << std::string("update_field gameplay ").append(raceName).append(" PlayerCarPerformance 0.5")
        .append("\n\n");

        //Check for a single Big Lou race that has a misspelled Name field and correct it
        if ( raceName == "race_bin_11/11_2_1_sprint" )
        { file << std::string("update_field gameplay race_bin_11/11_2_1_sprint Name race_bin_11/11_2_1_sprint\n"); }

        //Remove processed race from pool
        races.erase(races.begin() + pickedRace);
    }

    file << std::string("# FMVs for prologue Razor races").append("\n");

    //FMVs for races outside randomized ones are processed here
    file << std::string("update_field gameplay 16_1_0_partial_dday").append(" IntroMovie ")
    .append(fmvs[pickRandomNumber(0, (int)fmvs.size() - 1)]).append("\n");

    file << std::string("update_field gameplay 16_2_1_d_day_intro").append(" OutroMovie ")
    .append(fmvs[pickRandomNumber(0, (int)fmvs.size() - 1)]).append("\n\n");

    file.close();

    //All done
    return races;
}

std::vector<std::pair<std::string, bool>> randomizeRaces(std::ofstream& file,
                          int numberOfRaces, int numberOfBossRaces, int bossRaceCashValue, const std::string& raceBin,
                          const std::string& bossOpponentString, std::vector<std::pair<std::string, bool>> races,
                          int raceCashValue, const std::unordered_map<std::string, int>& raceMap,
                          const std::array<std::string, 41>& opponentList, const std::vector<std::string>& bossIndexes,
                          const std::unordered_map<int, float>& distanceMap,
                          const std::unordered_map<int, float>& timeMap,
                          const std::array<std::string, 6>& startingOpponentList,
                          bool allKnockoutsConvertedToCircuits, bool allSpeedtrapsConvertedToSprints,
                          bool maximumTrafficDensity, bool copsOnAllTrackExpansionRaces)
{
    //Initial variables
    int pickedRace;
    std::unordered_map<std::string, int>::const_iterator raceInteger;
    int bossRaceCounter = 0;
    std::string raceName;
    std::string raceType;
    std::string emptyPostRaceActivityField;
    int copChance = pickRandomNumber(0, 75);
    std::vector<std::pair<std::string, int>> chosenTriggers;
    std::vector<std::string> triggerDetails;
    bool hasBossRaceTrigger = false;
    std::string prefix;

    for ( int loop = 0; loop < numberOfRaces + numberOfBossRaces; loop++ )
    {
        //Writes a comment that says which race node was chosen and as which race in the text file
        file << std::string("# ").append(raceBin).append(", race ")
        .append(std::to_string(loop + 1)).append("\n");

        //Pick race at random and retrieve its integer from raceMap
        pickedRace = pickRandomNumber(0, races.size() - 1); // NOLINT(cppcoreguidelines-narrowing-conversions)
        raceName = races[pickedRace].first;
        raceInteger = raceMap.find(raceName);

        //Race type is used both for naming triggers and knowing which fields to randomize later
        raceType = checkRaceType(raceInteger->second);

        //Set prefix for modifying triggers
        if ( raceName.substr(0, 2) == "16" ) { prefix = raceName; }
        else { prefix = raceName.substr(0, 11); }

        //Remove prologue fields, if originally prologue race
        if ( raceName.substr(0, 2) == "16" ) { convertPrologueRaceToRegularRace(file, raceName); }

        //Check for a single Razor race that has a DDayRace field and remove it
        if ( raceName == "race_bin_01/1_5_2_speedtraprace" )
        { file << std::string("delete_field gameplay race_bin_01/1_5_2_speedtraprace DDayRace\n"); }

        //Check for a single Big Lou race that has a misspelled Name field and correct it
        if ( raceName == "race_bin_11/11_2_1_sprint" )
        { file << std::string("update_field gameplay race_bin_11/11_2_1_sprint Name race_bin_11/11_2_1_sprint\n"); }

        //Updates vault for race if originally from different blacklist member
        if ( raceBin != raceName.substr(0, 11) )
        {
            file << std::string("change_vault gameplay ").append(raceName).append(" ").append(raceBin)
            .append("\n");
        }

        //If regular race or first boss race, update or create race triggers. Skip this block if Track Expansion race
        if ( raceInteger->second < 175 )
        {
            //Get trigger data first
            triggerDetails = getNewTriggerDetails(raceInteger->second);

            if ( loop < numberOfRaces + 1 )
            {
                //If it is a vanilla race with a trigger, create prefix and add to vector
                //with race integer for engage node updates
                if ( hasTrigger(raceInteger->second) )
                {
                    chosenTriggers.emplace_back(prefix + triggerDetails[0], raceInteger->second );
                    if ( loop == numberOfRaces ) { hasBossRaceTrigger = true; }
                }

                //If it is a vanilla race without a trigger, create one and do the same as above
                else
                {
                    createRaceTrigger(file, raceName, raceType, raceBin, triggerDetails, prefix);
                    chosenTriggers.emplace_back(prefix + triggerDetails[0], raceInteger->second );
                    if ( loop == numberOfRaces ) { hasBossRaceTrigger = true; }
                }
            }

            //If a boss race past the first, delete the trigger
            else
            {
                //Track expansion races do not have triggers
                if ( raceInteger->second > 174 ) {}

                else if ( hasTrigger(raceInteger->second) )
                {
                    file << std::string("delete_node gameplay ").append(prefix)
                    .append(triggerDetails[0]).append("\n");
                }
            }
        }

        //If originally a boss race, convert to regular race
        if ( races[pickedRace].second && loop < numberOfRaces )
        {
            convertBossRaceToRegularRace(file, raceName, raceCashValue, raceInteger->second, opponentList,
                                         raceType, raceBin, startingOpponentList);
        }

        //Boss races are handled here
        else if ( loop >= numberOfRaces && loop < numberOfBossRaces + numberOfRaces )
        {
            emptyPostRaceActivityField = createBossRace(file, raceName, bossRaceCashValue, numberOfRaces,
                                            numberOfBossRaces, loop, raceInteger->second, raceType,
                                            bossOpponentString, raceBin, emptyPostRaceActivityField);
        }

        //If a race was a regular race and is selected to be a regular race, update some fields
        else
        {
            updateRegularRace(file, raceName, raceType, raceCashValue,
                            raceBin, raceInteger->second, opponentList, startingOpponentList);
        }

        //Randomize race intro after conversion
        if ( raceType != "tollbooth" && raceName != "16_1_1_circuit" )
        {
            if ( loop < numberOfRaces )
            { randomizeRaceIntro(file, raceName, raceInteger->second, false); }

            else { randomizeRaceIntro(file, raceName, raceInteger->second, true); }
        }

        //Replace a few necessary fields with the current race
        if ( loop < numberOfRaces )
        {
            file << std::string("update_field gameplay ").append(raceBin).append(" WorldRaces[")
            .append(std::to_string(loop)).append("] ").append(raceName).append("\n");
        }

        else
        {
            file << std::string("update_field gameplay ").append(raceBin).append(" BossRaces[")
            .append(std::to_string(bossRaceCounter)).append("] ").append(raceName).append("\n");
            bossRaceCounter++;
        }

        file << std::string("update_field gameplay ").append(raceBin).append(" Children[")
        .append(bossIndexes[loop]).append("] ").append(raceName).append("\n");

        if ( checkForField(raceInteger->second, 10) )
        { file << std::string("delete_field gameplay ").append(raceName).append(" IntroMovie").append("\n"); }

        randomizeGeneralFields(file, raceName, distanceMap, timeMap, numberOfRaces, raceType, raceInteger->second,
            loop, copChance, allKnockoutsConvertedToCircuits, allSpeedtrapsConvertedToSprints,
            maximumTrafficDensity, copsOnAllTrackExpansionRaces);

        //A single newline character for any other function that writes to the file
        file << std::string("\n");

        //Remove processed race from pool
        races.erase(races.begin() + pickedRace);
    }

    //Use vector with triggers and race integers to update race bin engage node
    updateRaceTriggers(file, hasBossRaceTrigger, raceBin, chosenTriggers);

    //Return modified races vector for future function calls
    return races;
}

void updatePursuitRequirements(std::ofstream& file, int totalMilestones, int minimumBounty, const std::string& raceBin)
{
    std::vector<int> possibleMinimumMilestones;
    float numberOfMilestonesFloat;
    numberOfMilestonesFloat = (float)totalMilestones;

    file << std::string("# changing number of milestones and bounty for ").append(raceBin).append("\n");

    file << std::string("update_field gameplay ").append(raceBin).append(" RequiredBounty ")
    .append(std::to_string(minimumBounty)).append("\n");

    for ( int loop = 0; loop < totalMilestones; loop++ )
    {
        if ( ((float)loop + 1) / numberOfMilestonesFloat >= 0.40 &&
        ((float)loop + 1) / numberOfMilestonesFloat <= 0.80 )
        { possibleMinimumMilestones.emplace_back(loop + 1); }
    }

    file << std::string("update_field gameplay ").append(raceBin).append(" RequiredChallenges ")
    .append(std::to_string(possibleMinimumMilestones[pickRandomNumber(0,
    (int)possibleMinimumMilestones.size() - 1)])).append("\n\n");
}

std::vector<std::pair<std::string, bool>> randomizePrologue(int numberOfRaces, int raceCashValue,
                 std::vector<std::pair<std::string, bool>> races, const std::unordered_map<std::string, int>& raceMap,
                 const std::array<std::string, 41>& opponentList, const std::array<std::string, 73>& carList,
                 const std::unordered_map<int, float>& distanceMap, const std::unordered_map<int, float>& timeMap,
                 const std::array<std::string, 35>& aiCarList, bool allKnockoutsConvertedToCircuits,
                 bool allSpeedtrapsConvertedToSprints, bool maximumTrafficDensity, bool copsOnAllTrackExpansionRaces)
{
    //Main function for prologue
    races = randomizePrologueRaces(numberOfRaces, races, raceCashValue, raceMap, opponentList,
                carList, distanceMap, timeMap, aiCarList, allKnockoutsConvertedToCircuits,
                allSpeedtrapsConvertedToSprints, maximumTrafficDensity, copsOnAllTrackExpansionRaces);

    return races;
}

std::vector<std::pair<std::string, bool>> randomizeChapter(int regularRaces, int originalNumberOfRaces,
             int bossRaces, int originalNumberOfBossRaces, std::vector<std::pair<std::string, bool>> races,
             const std::unordered_map<std::string, int>& raceMap, const std::array<std::string, 41>& opponentList,
             const std::unordered_map<int, float>& distanceMap, const std::unordered_map<int, float>& timeMap,
             const std::string& raceBin, int raceCashValue, int bossRaceCashValue,
             const std::string& bossOpponentString, const std::array<std::string, 6>& startingOpponentList,
             int heatLevel, int minimumBounty, int bountyGap, std::vector<std::string> bossIndexes,
             bool allKnockoutsConvertedToCircuits, bool allSpeedtrapsConvertedToSprints, bool maximumTrafficDensity,
             bool copsOnAllTrackExpansionRaces)
{
    std::ofstream file;
    std::ofstream& fileReference = file;
    int chapterMilestones;
    int chapterSpeedtraps;

    file.open("TERandomized.nfsms", std::ios_base::app);

    bossIndexes = updateNumberOfChapterRaces(fileReference, regularRaces,
           originalNumberOfRaces, bossRaces,
           originalNumberOfBossRaces, raceBin, bossIndexes);

    //Main function that modifies all races for the blacklist member
    races = randomizeRaces(fileReference, regularRaces, bossRaces,
           bossRaceCashValue, raceBin, bossOpponentString, races, raceCashValue, raceMap, opponentList,
           bossIndexes, distanceMap, timeMap, startingOpponentList, allKnockoutsConvertedToCircuits,
           allSpeedtrapsConvertedToSprints, maximumTrafficDensity, copsOnAllTrackExpansionRaces);

    //Milestones are randomized next
    randomizeMilestones(fileReference, heatLevel, bountyGap, raceBin);
    chapterMilestones = 4;

    //Speedtraps are next
    chapterSpeedtraps = randomizeSpeedtraps(fileReference, bountyGap, raceBin);

    //Change pursuit requirements based on last two function calls
    updatePursuitRequirements(fileReference, chapterSpeedtraps + chapterMilestones,
           minimumBounty, raceBin);

    //All done
    file.close();
    return races;
}

int main()
{
    //Integers for pre-randomization numbers of races.....
    int originalNumberOfSonnyRaces = 6;
    int originalNumberOfTazRaces = 6;
    int originalNumberOfVicRaces = 7;
    int originalNumberOfIzzyRaces = 7;
    int originalNumberOfBigLouRaces = 8;
    int originalNumberOfBaronRaces = 8;
    int originalNumberOfEarlRaces = 8;
    int originalNumberOfJewelsRaces = 7;
    int originalNumberOfKazeRaces = 10;
    int originalNumberOfMingRaces = 11;
    int originalNumberOfWebsterRaces = 10;
    int originalNumberOfJVRaces = 11;
    int originalNumberOfRonnieRaces = 12;
    int originalNumberOfBullRaces = 12;
    int originalNumberOfRazorRaces = 11;

    //.....and their respective pointers
    int* originalNumberOfSonnyRacesPtr = &originalNumberOfSonnyRaces;
    int* originalNumberOfTazRacesPtr = &originalNumberOfTazRaces;
    int* originalNumberOfVicRacesPtr = &originalNumberOfVicRaces;
    int* originalNumberOfIzzyRacesPtr = &originalNumberOfIzzyRaces;
    int* originalNumberOfBigLouRacesPtr = &originalNumberOfBigLouRaces;
    int* originalNumberOfBaronRacesPtr = &originalNumberOfBaronRaces;
    int* originalNumberOfEarlRacesPtr = &originalNumberOfEarlRaces;
    int* originalNumberOfJewelsRacesPtr = &originalNumberOfJewelsRaces;
    int* originalNumberOfKazeRacesPtr = &originalNumberOfKazeRaces;
    int* originalNumberOfMingRacesPtr = &originalNumberOfMingRaces;
    int* originalNumberOfWebsterRacesPtr = &originalNumberOfWebsterRaces;
    int* originalNumberOfJVRacesPtr = &originalNumberOfJVRaces;
    int* originalNumberOfRonnieRacesPtr = &originalNumberOfRonnieRaces;
    int* originalNumberOfBullRacesPtr = &originalNumberOfBullRaces;
    int* originalNumberOfRazorRacesPtr = &originalNumberOfRazorRaces;

    //Track expansion custom install option variables
    bool allKnockoutsConvertedToCircuits;
    bool allSpeedtrapsConvertedToSprints;
    bool maximumTrafficDensity;
    bool copsOnAllTrackExpansionRaces;

    //Start menu used to decide which races are added to the pool
    std::string answer;
    std::vector<std::pair<std::string, bool>> races;
    bool answerGiven = false;

    std::cout << "Welcome to the Track Expansion v0.6.2 randomizer!" << std::endl;
    std::cout << "Choose an option:" << std::endl;
    std::cout << "1: Easy install script" << std::endl;
    std::cout << "2: Custom install script" << std::endl;
    std::cout << "3: Instructions" << std::endl;
    std::cout << "4: Exit" << std::endl << std::endl;
    std::cout << ">> ";

    while ( !answerGiven )
    {
        std::cin >> answer;

        if ( answer == "1" )
        {
            //Races are added first
            races = populateRacesCustomizable(originalNumberOfSonnyRacesPtr, originalNumberOfTazRacesPtr,
                originalNumberOfVicRacesPtr, originalNumberOfIzzyRacesPtr, originalNumberOfBigLouRacesPtr,
                originalNumberOfBaronRacesPtr, originalNumberOfEarlRacesPtr, originalNumberOfJewelsRacesPtr,
                originalNumberOfKazeRacesPtr, originalNumberOfMingRacesPtr, originalNumberOfWebsterRacesPtr,
                originalNumberOfJVRacesPtr, originalNumberOfRonnieRacesPtr, originalNumberOfBullRacesPtr,
                originalNumberOfRazorRacesPtr, true);

            answerGiven = true;
        }

        else if ( answer == "2" )
        {
            races = populateRacesCustomizable(originalNumberOfSonnyRacesPtr, originalNumberOfTazRacesPtr,
                originalNumberOfVicRacesPtr, originalNumberOfIzzyRacesPtr, originalNumberOfBigLouRacesPtr,
                originalNumberOfBaronRacesPtr, originalNumberOfEarlRacesPtr, originalNumberOfJewelsRacesPtr,
                originalNumberOfKazeRacesPtr, originalNumberOfMingRacesPtr, originalNumberOfWebsterRacesPtr,
                originalNumberOfJVRacesPtr, originalNumberOfRonnieRacesPtr, originalNumberOfBullRacesPtr,
                originalNumberOfRazorRacesPtr, false);

            //Questions are asked about Track Expansion settings when the mod was installed
            allKnockoutsConvertedToCircuits =
                    askQuestionAboutSettings("\nAll knockouts converted to circuits? Y/N\n >> ");

            allSpeedtrapsConvertedToSprints =
                    askQuestionAboutSettings("\nAll speedtraps converted to sprints? Y/N\n >> ");

            maximumTrafficDensity =
                    askQuestionAboutSettings("\nTraffic density set to maximum? Y/N\n >> ");

            copsOnAllTrackExpansionRaces =
                    askQuestionAboutSettings("\nCops enabled on all races? Y/N\n >> ");

            answerGiven = true;
        }

        else if ( answer == "3" )
        {
            std::cout << "\nIf you used the easy install script from Track Expansion, use option 1 to" << std::endl;
            std::cout << "generate a script. There will be no prompts for the easy install." << std::endl;
            std::cout << std::endl;

            std::cout << "If you used the custom install of Track Expansion, use option 2 to" << std::endl;
            std::cout << "generate a script. You will be asked which track packages were installed," << std::endl;
            std::cout << "then what options were used. You will only be asked about extra tracks for a" << std::endl;
            std::cout << "boss if the answer to the base tracks was yes. All vanilla races will be" << std::endl;
            std::cout << "randomized, if any of the options for the Track Expansion tracks were enabled" << std::endl;
            std::cout << "they will take priority over the randomizer. If all the track packages and" << std::endl;
            std::cout << "options match the installation, the generated script will be compatible." << std::endl;
            std::cout << std::endl;

            std::cout << "The script will be created as TERandomized.nfsms. If a file with the same name" << std::endl;
            std::cout << "is in the same directory, this program will add to it. Make sure you have moved" << std::endl;
            std::cout << "out or deleted any old scripts before running the program. After the program" << std::endl;
            std::cout << "is finished running, import the generated script into vlted. There should be" << std::endl;
            std::cout << "no errors." << std::endl;
            std::cout << std::endl;

            std::cout << "Select another option >> ";
        }

        else if ( answer == "4" ) { return 0; }

        else { std::cout << "\nBad input. Try again >> "; }
    }

    //Remaining lists are created here
    std::unordered_map<std::string, int> raceMap = createRaceMap();
    std::unordered_map<int, float> distanceMap = createDistanceMap();
    std::unordered_map<int, float> timeMap = createTimeMap();
    std::array<std::string, 73> carList = getListOfPlayerCars();
    std::array<std::string, 35> aiCarList = getListOfAICars();
    std::array<std::string, 41> opponentList = getListOfRegularOpponents();
    std::array<std::string, 18> scriptedOpponentList = getListOfScriptedOpponents();
    std::array<std::string, 6> startingOpponentList = getListOfStartingOpponents();
    std::array<std::string, 46> cars = getListOfCars();
    std::array<std::string, 69> engineSounds = getListOfEngineSounds();

    //Boss index vectors, decided by number of races after user input
    std::vector<std::string> sonnyIndexes;
    std::vector<std::string> tazIndexes;
    std::vector<std::string> vicIndexes;
    std::vector<std::string> izzyIndexes;
    std::vector<std::string> bigLouIndexes;
    std::vector<std::string> baronIndexes;
    std::vector<std::string> earlIndexes;
    std::vector<std::string> jewelsIndexes;
    std::vector<std::string> kazeIndexes;
    std::vector<std::string> mingIndexes;
    std::vector<std::string> websterIndexes;
    std::vector<std::string> jvIndexes;
    std::vector<std::string> ronnieIndexes;
    std::vector<std::string> bullIndexes;
    std::vector<std::string> razorIndexes;

    switch(*originalNumberOfSonnyRacesPtr)
    {
        case 6: sonnyIndexes = { "1", "2", "3", "4", "7", "13", "14", "15" }; break;
        default: sonnyIndexes = { "1", "2", "3", "4", "7", "13", "14", "15", "16", "17", "18" };
    }

    switch(*originalNumberOfTazRacesPtr)
    {
        case 6: tazIndexes = { "1", "2", "3", "4", "5", "6", "7", "9" }; break;
        default: tazIndexes = { "1", "2", "3", "4", "5", "6", "7", "9", "15", "16", "17", "18" };
    }

    switch(*originalNumberOfVicRacesPtr)
    {
        case 7: vicIndexes = { "1", "2", "3", "4", "5", "6", "7", "11", "12" }; break;
        case 11: vicIndexes = { "1", "2", "3", "4", "5", "6", "7", "11", "12", "16", "17", "18", "19" }; break;
        default: vicIndexes = { "1", "2", "3", "4", "5", "6", "7", "11", "12", "16", "17", "18", "19", "20" };
    }

    switch(*originalNumberOfIzzyRacesPtr)
    {
        case 7: izzyIndexes = { "1", "2", "3", "4", "5", "6", "10", "11", "12" }; break;
        case 14: izzyIndexes =
              { "1", "2", "3", "4", "5", "6", "10", "11", "12", "17", "18", "19", "20", "21", "22", "23" }; break;
        default: izzyIndexes =
              { "1", "2", "3", "4", "5", "6", "10", "11", "12", "17", "18", "19", "20", "21", "22", "23", "24" };
    }

    switch(*originalNumberOfBigLouRacesPtr)
    {
        case 8: bigLouIndexes = { "1", "2", "3", "4", "5", "6", "9", "10", "11", "15" }; break;
        default: bigLouIndexes =
              { "1", "2", "3", "4", "5", "6", "9", "10", "11", "15", "18", "19", "20", "21", "22", "23", "24", "25" };
    }

    switch(*originalNumberOfBaronRacesPtr)
    {
        case 8: baronIndexes = { "1", "2", "3", "4", "5", "9", "10", "11", "12", "16" }; break;
        case 14: baronIndexes =
              { "1", "2", "3", "4", "5", "9", "10", "11", "12", "16", "18", "19", "20", "21", "22", "23" }; break;
        default: baronIndexes =
              { "1", "2", "3", "4", "5", "9", "10", "11", "12", "16", "18", "19", "20", "21", "22", "23", "24", "25" };
    }

    switch(*originalNumberOfEarlRacesPtr)
    {
        case 8: earlIndexes = { "1", "2", "3", "4", "5", "7", "8", "9", "15", "16" }; break;
        default: earlIndexes =
              { "1", "2", "3", "4", "5", "7", "8", "9", "15", "16", "18", "19", "20", "21", "22", "23", "24", "25" };
    }

    switch(*originalNumberOfJewelsRacesPtr)
    {
        case 7: jewelsIndexes = { "1", "3", "6", "7", "8", "9", "13", "14", "15" }; break;
        case 14: jewelsIndexes =
              { "1", "3", "6", "7", "8", "9", "13", "14", "15", "16", "17", "18", "19", "20", "21", "22" }; break;
        default: jewelsIndexes =
              { "1", "3", "6", "7", "8", "9", "13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "23" };
    }

    switch(*originalNumberOfKazeRacesPtr)
    {
        case 10: kazeIndexes = { "1", "2", "3", "4", "5", "6", "7", "9", "12", "13", "14", "18" }; break;
        case 18: kazeIndexes =
              { "1", "2", "3", "4", "5", "6", "7", "9", "12", "13", "14", "18", "20", "21", "22",
                "23", "24", "25", "26", "27" }; break;
        default: kazeIndexes =
              { "1", "2", "3", "4", "5", "6", "7", "9", "12", "13", "14", "18", "20", "21", "22",
                "23", "24", "25", "26", "27", "28" };
    }

    switch(*originalNumberOfMingRacesPtr)
    {
        case 11: mingIndexes = { "1", "2", "3", "4", "5", "6", "7", "8", "12", "13", "14", "15", "16" }; break;
        case 20: mingIndexes =
              { "1", "2", "3", "4", "5", "6", "7", "8", "12", "13", "14", "15", "16", "21", "22",
                "23", "24", "25", "26", "27", "28", "29" }; break;
        default: mingIndexes =
              { "1", "2", "3", "4", "5", "6", "7", "8", "12", "13", "14", "15", "16", "21", "22",
                "23", "24", "25", "26", "27", "28", "29", "30" };
    }

    switch(*originalNumberOfWebsterRacesPtr)
    {
        case 10: websterIndexes = { "2", "3", "4", "5", "6", "7", "10", "11", "12", "13", "14", "15", "16" }; break;
        default: websterIndexes =
              { "2", "3", "4", "5", "6", "7", "10", "11", "12", "13", "14", "15", "16", "21", "22", "23", "24", "25",
                "26", "27", "28", "29", "30", "31" };
    }

    switch(*originalNumberOfJVRacesPtr)
    {
        case 11: jvIndexes = { "1", "2", "3", "4", "5", "6", "10", "11", "12", "13", "14", "15", "16", "20" }; break;
        default: jvIndexes =
              { "1", "2", "3", "4", "5", "6", "10", "11", "12", "13", "14", "15", "16", "20", "22", "23", "24", "25",
                "26", "27", "28", "29", "30", "31", "32" };
    }

    switch(*originalNumberOfRonnieRacesPtr)
    {
        case 12: ronnieIndexes = { "1", "3", "4", "5", "8", "9", "10", "11", "12",
                                   "13", "14", "15", "19", "20", "21" }; break;
        default: ronnieIndexes =
              { "1", "3", "4", "5", "8", "9", "10", "11", "12", "13", "14", "15", "19", "20", "21", "22", "23", "24",
                "25", "26", "27", "28", "29", "30", "31" };
    }

    switch(*originalNumberOfBullRacesPtr)
    {
        case 12: bullIndexes = { "2", "3", "4", "7", "8", "9", "10", "11", "12",
                                 "13", "14", "15", "16", "17", "21" }; break;
        default: bullIndexes =
              { "2", "3", "4", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", "17", "21", "22", "23", "24",
                "25", "26", "27", "28", "29", "30", "31", "32" };
    }

    switch(*originalNumberOfRazorRacesPtr)
    {
        case 11: razorIndexes = { "2", "3", "4", "5", "6", "7", "10", "11", "12",
                                  "13", "14", "15", "16", "20", "21", "23" }; break;
        default: razorIndexes =
              { "2", "3", "4", "5", "6", "7", "10", "11", "12", "13", "14", "15", "16", "20", "21", "23", "24", "25",
                "26", "27", "28", "29", "30", "31", "32", "33" };
    }

    //Variables for deciding number of races
    int numberOfRacesForBoss = returnNumberOfRaces(0, *originalNumberOfSonnyRacesPtr);
    int currentRaceVariation = numberOfRacesForBoss - *originalNumberOfSonnyRacesPtr;
    std::pair<int, int> bossRacesResult = returnNumberOfBossRaces(currentRaceVariation, 2);

    int numberOfBossRacesForBoss = bossRacesResult.second;
    currentRaceVariation = bossRacesResult.first;

    //Variables for pursuits
    int currentMinimumBounty = pickRandomNumber(20000, 40000);
    int previousMinimumBounty = currentMinimumBounty;
    int bountyGap = currentMinimumBounty;

    //Randomize all regular opponents from this function
    randomizeOpponents(opponentList, scriptedOpponentList, startingOpponentList, aiCarList);

    //Have all boroughs unlocked from start
    randomizeFreeRoam();

    //Change a few fields to make Black Edition races usable in career
    convertCollectorsEditionRaces();

    //Copy a single speedtrap node to use for race speedtraps
    createSpeedtrapTemplate();

    //Delete all milestones, keep only one of each type as a template
    resetMilestones();

    //Delete all but one of each marker type to use as templates
    resetPerformanceMarkers();
    resetVisualMarkers();
    resetRandomMarkers();

    //Prologue
    races = randomizePrologue(3, 10000, races, raceMap,
                opponentList, carList, distanceMap, timeMap, aiCarList, allKnockoutsConvertedToCircuits,
                allSpeedtrapsConvertedToSprints, maximumTrafficDensity, copsOnAllTrackExpansionRaces);

    //Sonny
    races = randomizeChapter(numberOfRacesForBoss, *originalNumberOfSonnyRacesPtr,
        numberOfBossRacesForBoss, 2, races, raceMap, opponentList, distanceMap, timeMap,
        "race_bin_15", 1500, 5000, "race_bin_15/tony_ho",
        startingOpponentList, 1, currentMinimumBounty, bountyGap, sonnyIndexes,
        allKnockoutsConvertedToCircuits, allSpeedtrapsConvertedToSprints, maximumTrafficDensity,
        copsOnAllTrackExpansionRaces);

    numberOfRacesForBoss = returnNumberOfRaces(currentRaceVariation, *originalNumberOfTazRacesPtr);
    currentRaceVariation = currentRaceVariation + (numberOfRacesForBoss - *originalNumberOfTazRacesPtr);
    bossRacesResult = returnNumberOfBossRaces(currentRaceVariation, 2);

    numberOfBossRacesForBoss = bossRacesResult.second;
    currentRaceVariation = bossRacesResult.first;

    currentMinimumBounty = pickRandomNumber(previousMinimumBounty + 20000, previousMinimumBounty + 40000);
    bountyGap = currentMinimumBounty - previousMinimumBounty;
    previousMinimumBounty = currentMinimumBounty;

    //Taz
    races = randomizeChapter(numberOfRacesForBoss, *originalNumberOfTazRacesPtr,
        numberOfBossRacesForBoss, 2, races, raceMap, opponentList, distanceMap, timeMap,
        "race_bin_14", 2000, 6000, "race_bin_14/vince_kilic",
        startingOpponentList, 1, currentMinimumBounty, bountyGap, tazIndexes,
        allKnockoutsConvertedToCircuits, allSpeedtrapsConvertedToSprints, maximumTrafficDensity,
        copsOnAllTrackExpansionRaces);

    numberOfRacesForBoss = returnNumberOfRaces(currentRaceVariation, *originalNumberOfVicRacesPtr);
    currentRaceVariation = currentRaceVariation + (numberOfRacesForBoss - *originalNumberOfVicRacesPtr);
    bossRacesResult = returnNumberOfBossRaces(currentRaceVariation, 2);

    numberOfBossRacesForBoss = bossRacesResult.second;
    currentRaceVariation = bossRacesResult.first;

    currentMinimumBounty = pickRandomNumber(previousMinimumBounty + 20000, previousMinimumBounty + 40000);
    bountyGap = currentMinimumBounty - previousMinimumBounty;
    previousMinimumBounty = currentMinimumBounty;

    //Vic
    races = randomizeChapter(numberOfRacesForBoss, *originalNumberOfVicRacesPtr,
        numberOfBossRacesForBoss, 2, races, raceMap, opponentList, distanceMap, timeMap,
        "race_bin_13", 2500, 6000, "race_bin_13/victor_vasquez",
        startingOpponentList, 1, currentMinimumBounty, bountyGap, vicIndexes,
        allKnockoutsConvertedToCircuits, allSpeedtrapsConvertedToSprints, maximumTrafficDensity,
        copsOnAllTrackExpansionRaces);

    numberOfRacesForBoss = returnNumberOfRaces(currentRaceVariation, *originalNumberOfIzzyRacesPtr);
    currentRaceVariation = currentRaceVariation + (numberOfRacesForBoss - *originalNumberOfIzzyRacesPtr);
    bossRacesResult = returnNumberOfBossRaces(currentRaceVariation, 2);

    numberOfBossRacesForBoss = bossRacesResult.second;
    currentRaceVariation = bossRacesResult.first;

    currentMinimumBounty = pickRandomNumber(previousMinimumBounty + 100000, previousMinimumBounty + 200000);
    bountyGap = currentMinimumBounty - previousMinimumBounty;
    previousMinimumBounty = currentMinimumBounty;

    //Izzy
    races = randomizeChapter(numberOfRacesForBoss, *originalNumberOfIzzyRacesPtr,
        numberOfBossRacesForBoss, 2, races, raceMap, opponentList, distanceMap, timeMap,
        "race_bin_12", 3000, 8000, "race_bin_12/isabel_diaz",
        startingOpponentList, 2, currentMinimumBounty, bountyGap, izzyIndexes,
        allKnockoutsConvertedToCircuits, allSpeedtrapsConvertedToSprints, maximumTrafficDensity,
        copsOnAllTrackExpansionRaces);

    numberOfRacesForBoss = returnNumberOfRaces(currentRaceVariation, *originalNumberOfBigLouRacesPtr);
    currentRaceVariation = currentRaceVariation + (numberOfRacesForBoss - *originalNumberOfBigLouRacesPtr);
    bossRacesResult = returnNumberOfBossRaces(currentRaceVariation, 2);

    numberOfBossRacesForBoss = bossRacesResult.second;
    currentRaceVariation = bossRacesResult.first;

    currentMinimumBounty = pickRandomNumber(previousMinimumBounty + 100000, previousMinimumBounty + 200000);
    bountyGap = currentMinimumBounty - previousMinimumBounty;
    previousMinimumBounty = currentMinimumBounty;

    //Big Lou
    races = randomizeChapter(numberOfRacesForBoss, *originalNumberOfBigLouRacesPtr,
         numberOfBossRacesForBoss, 2, races, raceMap, opponentList, distanceMap,  timeMap,
         "race_bin_11", 4000, 10000, "race_bin_11/lou_park",
         startingOpponentList, 2, currentMinimumBounty, bountyGap, bigLouIndexes,
         allKnockoutsConvertedToCircuits, allSpeedtrapsConvertedToSprints, maximumTrafficDensity,
         copsOnAllTrackExpansionRaces);

    numberOfRacesForBoss = returnNumberOfRaces(currentRaceVariation, *originalNumberOfBaronRacesPtr);
    currentRaceVariation = currentRaceVariation + (numberOfRacesForBoss - *originalNumberOfBaronRacesPtr);
    bossRacesResult = returnNumberOfBossRaces(currentRaceVariation, 2);

    numberOfBossRacesForBoss = bossRacesResult.second;
    currentRaceVariation = bossRacesResult.first;

    currentMinimumBounty = pickRandomNumber(previousMinimumBounty + 200000, previousMinimumBounty + 400000);
    bountyGap = currentMinimumBounty - previousMinimumBounty;
    previousMinimumBounty = currentMinimumBounty;

    //Baron
    races = randomizeChapter(numberOfRacesForBoss, *originalNumberOfBaronRacesPtr,
         numberOfBossRacesForBoss, 2, races, raceMap, opponentList, distanceMap, timeMap,
         "race_bin_10", 5000, 12000, "race_bin_10/karl_smit",
         startingOpponentList, 3, currentMinimumBounty, bountyGap, baronIndexes,
         allKnockoutsConvertedToCircuits, allSpeedtrapsConvertedToSprints, maximumTrafficDensity,
         copsOnAllTrackExpansionRaces);

    numberOfRacesForBoss = returnNumberOfRaces(currentRaceVariation, *originalNumberOfEarlRacesPtr);
    currentRaceVariation = currentRaceVariation + (numberOfRacesForBoss - *originalNumberOfEarlRacesPtr);
    bossRacesResult = returnNumberOfBossRaces(currentRaceVariation, 2);

    numberOfBossRacesForBoss = bossRacesResult.second;
    currentRaceVariation = bossRacesResult.first;

    currentMinimumBounty = pickRandomNumber(previousMinimumBounty + 200000, previousMinimumBounty + 400000);
    bountyGap = currentMinimumBounty - previousMinimumBounty;
    previousMinimumBounty = currentMinimumBounty;

    //Earl
    races = randomizeChapter(numberOfRacesForBoss, *originalNumberOfEarlRacesPtr,
          numberOfBossRacesForBoss, 2, races, raceMap, opponentList, distanceMap, timeMap,
          "race_bin_09", 6000, 16000, "race_bin_09/pierre_dupont",
          startingOpponentList, 3, currentMinimumBounty, bountyGap, earlIndexes,
          allKnockoutsConvertedToCircuits, allSpeedtrapsConvertedToSprints, maximumTrafficDensity,
          copsOnAllTrackExpansionRaces);

    numberOfRacesForBoss = returnNumberOfRaces(currentRaceVariation, *originalNumberOfJewelsRacesPtr);
    currentRaceVariation = currentRaceVariation + (numberOfRacesForBoss - *originalNumberOfJewelsRacesPtr);
    bossRacesResult = returnNumberOfBossRaces(currentRaceVariation, 2);

    numberOfBossRacesForBoss = bossRacesResult.second;
    currentRaceVariation = bossRacesResult.first;

    currentMinimumBounty = pickRandomNumber(previousMinimumBounty + 200000, previousMinimumBounty + 400000);
    bountyGap = currentMinimumBounty - previousMinimumBounty;
    previousMinimumBounty = currentMinimumBounty;

    //Jewels
    races = randomizeChapter(numberOfRacesForBoss, *originalNumberOfJewelsRacesPtr,
          numberOfBossRacesForBoss, 2, races, raceMap, opponentList, distanceMap, timeMap,
          "race_bin_08",8000, 20000, "race_bin_08/jade_barrett",
          startingOpponentList, 3, currentMinimumBounty, bountyGap, jewelsIndexes,
          allKnockoutsConvertedToCircuits, allSpeedtrapsConvertedToSprints, maximumTrafficDensity,
          copsOnAllTrackExpansionRaces);

    numberOfRacesForBoss = returnNumberOfRaces(currentRaceVariation, *originalNumberOfKazeRacesPtr);
    currentRaceVariation = currentRaceVariation + (numberOfRacesForBoss - *originalNumberOfKazeRacesPtr);
    bossRacesResult = returnNumberOfBossRaces(currentRaceVariation, 2);

    numberOfBossRacesForBoss = bossRacesResult.second;
    currentRaceVariation = bossRacesResult.first;

    currentMinimumBounty = pickRandomNumber(previousMinimumBounty + 400000, previousMinimumBounty + 1000000);
    bountyGap = currentMinimumBounty - previousMinimumBounty;
    previousMinimumBounty = currentMinimumBounty;

    //Kaze
    races = randomizeChapter(numberOfRacesForBoss, *originalNumberOfKazeRacesPtr,
          numberOfBossRacesForBoss, 2, races, raceMap, opponentList, distanceMap, timeMap,
          "race_bin_07",10000, 24000, "race_bin_07/kira_nazakato",
          startingOpponentList, 4, currentMinimumBounty, bountyGap, kazeIndexes,
          allKnockoutsConvertedToCircuits, allSpeedtrapsConvertedToSprints, maximumTrafficDensity,
          copsOnAllTrackExpansionRaces);

    numberOfRacesForBoss = returnNumberOfRaces(currentRaceVariation, *originalNumberOfMingRacesPtr);
    currentRaceVariation = currentRaceVariation + (numberOfRacesForBoss - *originalNumberOfMingRacesPtr);
    bossRacesResult = returnNumberOfBossRaces(currentRaceVariation, 2);

    numberOfBossRacesForBoss = bossRacesResult.second;
    currentRaceVariation = bossRacesResult.first;

    currentMinimumBounty = pickRandomNumber(previousMinimumBounty + 400000, previousMinimumBounty + 1000000);
    bountyGap = currentMinimumBounty - previousMinimumBounty;
    previousMinimumBounty = currentMinimumBounty;

    //Ming
    races = randomizeChapter(numberOfRacesForBoss, *originalNumberOfMingRacesPtr,
          numberOfBossRacesForBoss, 2, races, raceMap, opponentList, distanceMap, timeMap,
          "race_bin_06",12000, 28000, "race_bin_06/hector_domingo",
          startingOpponentList, 4, currentMinimumBounty, bountyGap, mingIndexes,
          allKnockoutsConvertedToCircuits, allSpeedtrapsConvertedToSprints, maximumTrafficDensity,
          copsOnAllTrackExpansionRaces);

    numberOfRacesForBoss = returnNumberOfRaces(currentRaceVariation, *originalNumberOfWebsterRacesPtr);
    currentRaceVariation = currentRaceVariation + (numberOfRacesForBoss - *originalNumberOfWebsterRacesPtr);
    bossRacesResult = returnNumberOfBossRaces(currentRaceVariation, 3);

    numberOfBossRacesForBoss = bossRacesResult.second;
    currentRaceVariation = bossRacesResult.first;

    currentMinimumBounty = pickRandomNumber(previousMinimumBounty + 400000, previousMinimumBounty + 1000000);
    bountyGap = currentMinimumBounty - previousMinimumBounty;
    previousMinimumBounty = currentMinimumBounty;

    //Webster
    races = randomizeChapter(numberOfRacesForBoss, *originalNumberOfWebsterRacesPtr,
          numberOfBossRacesForBoss, 3, races, raceMap, opponentList, distanceMap, timeMap,
          "race_bin_05",14000, 48000, "race_bin_05/wes_allen",
          startingOpponentList, 4, currentMinimumBounty, bountyGap, websterIndexes,
          allKnockoutsConvertedToCircuits, allSpeedtrapsConvertedToSprints, maximumTrafficDensity,
          copsOnAllTrackExpansionRaces);

    numberOfRacesForBoss = returnNumberOfRaces(currentRaceVariation, *originalNumberOfJVRacesPtr);
    currentRaceVariation = currentRaceVariation + (numberOfRacesForBoss - *originalNumberOfJVRacesPtr);
    bossRacesResult = returnNumberOfBossRaces(currentRaceVariation, 3);

    numberOfBossRacesForBoss = bossRacesResult.second;
    currentRaceVariation = bossRacesResult.first;

    currentMinimumBounty = pickRandomNumber(previousMinimumBounty + 400000, previousMinimumBounty + 1000000);
    bountyGap = currentMinimumBounty - previousMinimumBounty;
    previousMinimumBounty = currentMinimumBounty;

    //JV
    races = randomizeChapter(numberOfRacesForBoss, *originalNumberOfJVRacesPtr,
          numberOfBossRacesForBoss, 3, races, raceMap, opponentList, distanceMap, timeMap,
          "race_bin_04", 16000, 54000, "race_bin_04/joe_vega",
          startingOpponentList, 4, currentMinimumBounty, bountyGap, jvIndexes,
          allKnockoutsConvertedToCircuits, allSpeedtrapsConvertedToSprints, maximumTrafficDensity,
          copsOnAllTrackExpansionRaces);

    numberOfRacesForBoss = returnNumberOfRaces(currentRaceVariation, *originalNumberOfRonnieRacesPtr);
    currentRaceVariation = currentRaceVariation + (numberOfRacesForBoss - *originalNumberOfRonnieRacesPtr);
    bossRacesResult = returnNumberOfBossRaces(currentRaceVariation, 3);

    numberOfBossRacesForBoss = bossRacesResult.second;
    currentRaceVariation = bossRacesResult.first;

    currentMinimumBounty = pickRandomNumber(previousMinimumBounty + 1000000, previousMinimumBounty + 3000000);
    bountyGap = currentMinimumBounty - previousMinimumBounty;
    previousMinimumBounty = currentMinimumBounty;

    //Ronnie
    races = randomizeChapter(numberOfRacesForBoss, *originalNumberOfRonnieRacesPtr,
          numberOfBossRacesForBoss, 3, races, raceMap, opponentList, distanceMap, timeMap,
          "race_bin_03", 18000, 60000, "race_bin_03/ronnie_mccrea",
          startingOpponentList, 5, currentMinimumBounty, bountyGap, ronnieIndexes,
          allKnockoutsConvertedToCircuits, allSpeedtrapsConvertedToSprints, maximumTrafficDensity,
          copsOnAllTrackExpansionRaces);

    numberOfRacesForBoss = returnNumberOfRaces(currentRaceVariation, *originalNumberOfBullRacesPtr);
    currentRaceVariation = currentRaceVariation + (numberOfRacesForBoss - *originalNumberOfBullRacesPtr);
    bossRacesResult = returnNumberOfBossRaces(currentRaceVariation, 3);

    numberOfBossRacesForBoss = bossRacesResult.second;
    currentRaceVariation = bossRacesResult.first;

    currentMinimumBounty = pickRandomNumber(previousMinimumBounty + 1000000, previousMinimumBounty + 3000000);
    bountyGap = currentMinimumBounty - previousMinimumBounty;
    previousMinimumBounty = currentMinimumBounty;

    //Bull
    races = randomizeChapter(numberOfRacesForBoss, *originalNumberOfBullRacesPtr,
          numberOfBossRacesForBoss, 3, races, raceMap, opponentList, distanceMap, timeMap,
          "race_bin_02", 20000, 75000, "race_bin_02/toro_sato",
          startingOpponentList, 5, currentMinimumBounty, bountyGap, bullIndexes,
          allKnockoutsConvertedToCircuits, allSpeedtrapsConvertedToSprints, maximumTrafficDensity,
          copsOnAllTrackExpansionRaces);

    numberOfRacesForBoss = *originalNumberOfRazorRacesPtr + (currentRaceVariation * -1);

    currentMinimumBounty = pickRandomNumber(previousMinimumBounty + 1000000, previousMinimumBounty + 3000000);
    bountyGap = currentMinimumBounty - previousMinimumBounty;

    //Razor
    randomizeChapter(numberOfRacesForBoss, *originalNumberOfRazorRacesPtr, 5,
          5, races, raceMap, opponentList, distanceMap, timeMap, "race_bin_01",
          25000, 0, "race_bin_01/razor_callahan", startingOpponentList,
          5, currentMinimumBounty, bountyGap, razorIndexes,
          allKnockoutsConvertedToCircuits, allSpeedtrapsConvertedToSprints, maximumTrafficDensity,
          copsOnAllTrackExpansionRaces);

    //Cleanup
    deleteSpeedtrapTemplate();
    deleteMilestoneTemplates();
    deleteMarkerTemplates();

    std::cout << "\nScript successfully generated. Closing program in a few seconds.........";

    std::chrono::seconds timespan(5);
    std::this_thread::sleep_for(timespan);

    //All done
    return 0;
}
