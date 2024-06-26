//
// Created by Ted on 13/05/2024
//

#include <fstream>
#include <vector>
#include <array>
#include "PursuitFunctions.h"
#include "ListFunctions.h"
#include "GeneralFunctions.h"

void randomizeMilestones(std::ofstream& file, int heatLevel, int bountyGap, const std::string& raceBin)
{
    /** Takes the highest possible heat level for the provided blacklist member and randomizes
      * milestones. Milestone selection, number, minimum and maximum ranges depend on heat level.       */

    //Variables
    std::array<std::string, 43> milestoneSpawnPoints = getListOfMilestoneSpawnPoints();
    std::vector<std::string> milestones;
    int selectedMilestone;
    int newMilestoneValue;
    int newMilestoneBountyValue;
    int numberOfNewMilestones = 4;
    std::string newNodeName;
    std::string newMilestoneValueStr;
    std::string binNumber = std::to_string(std::stoi(raceBin.substr(9, 2)));
    std::string binNumberWithZeros = raceBin.substr(9, 2);

    //Construct array with selections based on heat level
    switch(heatLevel)
    {
        case 1:
            milestones = { "milestones/templates/challenge_cops_damaged",
              "milestones/templates/challenge_cops_destroyed", "milestones/templates/challenge_cost_to_state",
              "milestones/templates/challenge_pursuit_evasion_time", "milestones/templates/challenge_pursuit_length",
              "milestones/templates/challenge_total_infractions", "milestones/templates/challenge_cops_immobilized" };
            break;

        case 2: case 3:
            milestones = { "milestones/templates/challenge_cops_damaged",
              "milestones/templates/challenge_cops_destroyed", "milestones/templates/challenge_cost_to_state",
              "milestones/templates/challenge_pursuit_evasion_time", "milestones/templates/challenge_pursuit_length",
              "milestones/templates/challenge_total_infractions", "milestones/templates/challenge_roadblocks_dodged",
              "milestones/templates/challenge_cops_immobilized" };
            break;

        default:
            milestones = { "milestones/templates/challenge_cops_damaged",
              "milestones/templates/challenge_cops_destroyed", "milestones/templates/challenge_cost_to_state",
              "milestones/templates/challenge_pursuit_evasion_time", "milestones/templates/challenge_pursuit_length",
              "milestones/templates/challenge_total_infractions", "milestones/templates/challenge_roadblocks_dodged",
              "milestones/templates/challenge_tire_spikes_dodged", "milestones/templates/challenge_cops_immobilized" };
    }

    file << std::string("# randomizing milestones for ").append(raceBin).append("\n");

    if ( raceBin == "race_bin_15" || raceBin == "race_bin_14" || raceBin == "race_bin_13"
         || raceBin == "race_bin_12" || raceBin == "race_bin_11" )
    {
        file << std::string("resize_field gameplay milestones/").append(raceBin.substr(5, 6))
        .append(" Children ").append(std::to_string(numberOfNewMilestones)).append("\n");
    }

    switch(heatLevel)
    {
        case 1:
            switch(pickRandomNumber(1, 3))
            {
                case 1: newMilestoneBountyValue = static_cast<int>(bountyGap * 0.20); break;
                case 2: newMilestoneBountyValue = static_cast<int>(bountyGap * 0.19); break;
                default: newMilestoneBountyValue = static_cast<int>(bountyGap * 0.18);
            }

            break;

        case 2:
            switch(pickRandomNumber(1, 3))
            {
                case 1: newMilestoneBountyValue = static_cast<int>(bountyGap * 0.20); break;
                case 2: newMilestoneBountyValue = static_cast<int>(bountyGap * 0.18); break;
                default: newMilestoneBountyValue = static_cast<int>(bountyGap * 0.16);
            }

            break;

        case 3:
            switch(pickRandomNumber(1, 3))
            {
                case 1: newMilestoneBountyValue = static_cast<int>(bountyGap * 0.21); break;
                case 2: newMilestoneBountyValue = static_cast<int>(bountyGap * 0.17); break;
                default: newMilestoneBountyValue = static_cast<int>(bountyGap * 0.14);
            }

            break;

        case 4:
            switch(pickRandomNumber(1, 2))
            {
                case 1: newMilestoneBountyValue = static_cast<int>(bountyGap * 0.12); break;
                default: newMilestoneBountyValue = static_cast<int>(bountyGap * 0.11);
            }

            break;

        default:
            switch(pickRandomNumber(1, 2))
            {
                case 1: newMilestoneBountyValue = static_cast<int>(bountyGap * 0.07); break;
                default: newMilestoneBountyValue = static_cast<int>(bountyGap * 0.06);
            }
    }

    //Select and randomize between 2 and 4 milestones
    for ( int loop = 0; loop < numberOfNewMilestones; loop++ )
    {
        selectedMilestone = pickRandomNumber(0, static_cast<int>(milestones.size()) - 1);

        if ( milestones[selectedMilestone] == "milestones/templates/challenge_cops_damaged" )
        {
            newNodeName = std::string("milestones/bin_").append(binNumberWithZeros).append("/challenge_")
            .append(binNumber).append("_cops_damaged");

            file << std::string("copy_node gameplay milestones/templates/challenge_cops_damaged "
            "milestone_cops_damaged ").append(newNodeName).append("\n");

            switch(heatLevel)
            {
                case 1: newMilestoneValue = pickRandomNumber(2, 6); break;
                case 2: newMilestoneValue = pickRandomNumber(8, 16); break;
                case 3: newMilestoneValue = pickRandomNumber(12, 24); break;
                case 4: newMilestoneValue = pickRandomNumber(18, 30); break;
                default: newMilestoneValue = pickRandomNumber(22, 40);
            }
        }

        else if ( milestones[selectedMilestone] == "milestones/templates/challenge_cops_destroyed" )
        {
            newNodeName = std::string("milestones/bin_").append(binNumberWithZeros).append("/challenge_")
            .append(binNumber).append("_cops_destroyed");

            file << std::string("copy_node gameplay milestones/templates/challenge_cops_destroyed "
            "milestone_cops_destroyed ").append(newNodeName).append("\n");

            switch(heatLevel)
            {
                case 1: newMilestoneValue = pickRandomNumber(1000, 4000); break;
                case 2: newMilestoneValue = pickRandomNumber(5000, 10000); break;
                case 3: newMilestoneValue = pickRandomNumber(10000, 50000); break;
                case 4: newMilestoneValue = pickRandomNumber(60000, 350000); break;
                default: newMilestoneValue = pickRandomNumber(500000, 1000000);
            }
        }

        else if ( milestones[selectedMilestone] == "milestones/templates/challenge_cost_to_state" )
        {
            newNodeName = std::string("milestones/bin_").append(binNumberWithZeros).append("/challenge_")
            .append(binNumber).append("_cost_to_state");

            file << std::string("copy_node gameplay milestones/templates/challenge_cost_to_state "
            "milestone_cost_to_state ").append(newNodeName).append("\n");

            switch(heatLevel)
            {
                case 1: case 2: newMilestoneValue = pickRandomNumber(10000, 20000); break;
                case 3: newMilestoneValue = pickRandomNumber(20000, 60000); break;
                case 4: newMilestoneValue = pickRandomNumber(100000, 175000); break;
                default: newMilestoneValue = pickRandomNumber(125000, 225000);
            }
        }

        else if ( milestones[selectedMilestone] == "milestones/templates/challenge_pursuit_evasion_time" )
        {
            newNodeName = std::string("milestones/bin_").append(binNumberWithZeros).append("/challenge_")
            .append(binNumber).append("_pursuit_evasion_time");

            file << std::string("copy_node gameplay milestones/templates/challenge_pursuit_evasion_time "
            "milestone_pursuit_evasion_time ").append(newNodeName).append("\n");

            switch(heatLevel)
            {
                case 1: newMilestoneValue = pickRandomNumber(180, 240); break;
                case 2: newMilestoneValue = pickRandomNumber(135, 210); break;
                case 3: newMilestoneValue = pickRandomNumber(90, 180); break;
                case 4: newMilestoneValue = pickRandomNumber(75, 135); break;
                default: newMilestoneValue = pickRandomNumber(60, 120);
            }
        }

        else if ( milestones[selectedMilestone] == "milestones/templates/challenge_pursuit_length" )
        {
            newNodeName = std::string("milestones/bin_").append(binNumberWithZeros).append("/challenge_")
            .append(binNumber).append("_pursuit_length");

            file << std::string("copy_node gameplay milestones/templates/challenge_pursuit_length "
            "milestone_pursuit_length ").append(newNodeName).append("\n");

            switch(heatLevel)
            {
                case 1: newMilestoneValue = pickRandomNumber(120, 240); break;
                case 2: newMilestoneValue = pickRandomNumber(150, 270); break;
                case 3: newMilestoneValue = pickRandomNumber(180, 360); break;
                case 4: newMilestoneValue = pickRandomNumber(240, 480); break;
                default: newMilestoneValue = pickRandomNumber(300, 720);
            }
        }

        else if ( milestones[selectedMilestone] == "milestones/templates/challenge_total_infractions" )
        {
            newNodeName = std::string("milestones/bin_").append(binNumberWithZeros).append("/challenge_")
            .append(binNumber).append("_total_infractions");

            file << std::string("copy_node gameplay milestones/templates/challenge_total_infractions "
            "milestone_total_infractions ").append(newNodeName).append("\n");

            switch(heatLevel)
            {
                case 1: case 2: newMilestoneValue = pickRandomNumber(3, 5); break;
                case 3: newMilestoneValue = pickRandomNumber(3, 6); break;
                case 4: newMilestoneValue = pickRandomNumber(3, 7); break;
                default: newMilestoneValue = pickRandomNumber(3, 8);
            }
        }

        else if ( milestones[selectedMilestone] == "milestones/templates/challenge_roadblocks_dodged" )
        {
            newNodeName = std::string("milestones/bin_").append(binNumberWithZeros).append("/challenge_")
            .append(binNumber).append("_roadblocks_dodged");

            file << std::string("copy_node gameplay milestones/templates/challenge_roadblocks_dodged "
            "milestone_roadblocks_dodged ").append(newNodeName).append("\n");

            switch(heatLevel)
            {
                case 2: newMilestoneValue = pickRandomNumber(1, 2); break;
                case 3: newMilestoneValue = pickRandomNumber(4, 8); break;
                case 4: newMilestoneValue = pickRandomNumber(6, 10); break;
                default: newMilestoneValue = pickRandomNumber(8, 12);
            }
        }

        else if ( milestones[selectedMilestone] == "milestones/templates/challenge_tire_spikes_dodged" )
        {
            newNodeName = std::string("milestones/bin_").append(binNumberWithZeros).append("/challenge_")
            .append(binNumber).append("_tire_spikes_dodged");

            file << std::string("copy_node gameplay milestones/templates/challenge_tire_spikes_dodged "
            "milestone_tire_spikes_dodged ").append(newNodeName).append("\n");

            if ( heatLevel == 4 ) { newMilestoneValue = pickRandomNumber(1, 4); }
            else { newMilestoneValue = pickRandomNumber(6, 10); }
        }

        else
        {
            newNodeName = std::string("milestones/bin_").append(binNumberWithZeros).append("/challenge_")
            .append(binNumber).append("_cops_immobilized");

            file << std::string("copy_node gameplay milestones/templates/challenge_cops_immobilized "
            "milestone_cops_immobilized ").append(newNodeName).append("\n");

            switch(heatLevel)
            {
                case 1: newMilestoneValue = pickRandomNumber(1, 4); break;
                case 2: case 3: newMilestoneValue = pickRandomNumber(4, 12); break;
                default: newMilestoneValue = pickRandomNumber(12, 24);
            }
        }

        newMilestoneValueStr = std::to_string(newMilestoneValue);

        file << std::string("update_field gameplay milestones/").append(raceBin.substr(5, 6))
        .append(" Children[").append(std::to_string(loop)).append("] ").append(newNodeName)
        .append("\n");

        file << std::string("update_field gameplay ").append(newNodeName).append(" Name ")
        .append(newNodeName).append("\n");

        file << std::string("update_field gameplay ").append(newNodeName).append(" CollectionName ")
        .append(newNodeName).append("\n");

        file << std::string("update_field gameplay ").append(newNodeName).append(" BinIndex ")
        .append(binNumber).append("\n");

        file << std::string("update_field gameplay ").append(newNodeName).append(" GoalEasy ")
        .append(newMilestoneValueStr).append("\n");

        file << std::string("update_field gameplay ").append(newNodeName).append(" GoalHard ")
        .append(newMilestoneValueStr).append("\n");

        file << std::string("update_field gameplay ").append(newNodeName).append(" Bounty ")
        .append(std::to_string(newMilestoneBountyValue)).append("\n");

        file << std::string("update_field gameplay ").append(newNodeName).append(" SpawnPoint ")
        .append(milestoneSpawnPoints[pickRandomNumber(0, (int)milestoneSpawnPoints.size() - 1)]).append("\n");

        milestones.erase(milestones.begin() + selectedMilestone);
    }

    file << std::string("\n");
}

void randomizeSpeedtraps(std::ofstream& file, int bountyGap, int heatLevel, const std::string& raceBin)
{
    int numberOfSpeedtraps;
    int speedtrapBountyValue;

    switch(std::stoi(raceBin.substr(9, 2)))
    {
        case 15: numberOfSpeedtraps = 1; break;
        case 14: case 13: case 12: case 11: numberOfSpeedtraps = 2; break;
        default: numberOfSpeedtraps = 3;
    }

    file << std::string("# randomizing speedtrap bounty for ").append(raceBin).append("\n");

    switch(heatLevel)
    {
        case 1:
            switch(pickRandomNumber(1, 3))
            {
                case 1: speedtrapBountyValue = static_cast<int>(bountyGap * 0.16); break;
                case 2: speedtrapBountyValue = static_cast<int>(bountyGap * 0.145); break;
                default: speedtrapBountyValue = static_cast<int>(bountyGap * 0.13);
            }

            break;

        case 2:
            switch(pickRandomNumber(1, 3))
            {
                case 1: speedtrapBountyValue = static_cast<int>(bountyGap * 0.10); break;
                case 2: speedtrapBountyValue = static_cast<int>(bountyGap * 0.08); break;
                default: speedtrapBountyValue = static_cast<int>(bountyGap * 0.06);
            }

            break;

        case 3:
            switch(pickRandomNumber(1, 3))
            {
                case 1: speedtrapBountyValue = static_cast<int>(bountyGap * 0.12); break;
                case 2: speedtrapBountyValue = static_cast<int>(bountyGap * 0.10); break;
                default: speedtrapBountyValue = static_cast<int>(bountyGap * 0.08);
            }

            break;

        case 4:
            switch(pickRandomNumber(1, 2))
            {
                case 1: speedtrapBountyValue = static_cast<int>(bountyGap * 0.08); break;
                default: speedtrapBountyValue = static_cast<int>(bountyGap * 0.07);
            }

            break;

        default: speedtrapBountyValue = static_cast<int>(bountyGap * 0.05);
    }

    for ( int loop = 0; loop < numberOfSpeedtraps; loop++ )
    {
        file << std::string("update_field gameplay speedtraps/").append(raceBin.substr(5, 6))
        .append("/speedtrap").append(std::to_string(loop + 1)).append(" Bounty ")
        .append(std::to_string(speedtrapBountyValue)).append("\n");
    }

    file << std::string("\n");
}
