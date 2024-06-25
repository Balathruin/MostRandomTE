//
// Created by Ted on 20/06/2024
//

#include <vector>
#include <fstream>
#include <array>
#include "GeneralFunctions.h"
#include "ListFunctions.h"
#include "FreeRoamFunctions.h"

void randomizeFreeRoam()
{
    //General variables
    std::ofstream file;
    std::vector<std::string> freeRoamZones = getListOfFreeRoamZones();
    std::vector<std::array<float, 4>> zoneCoordinates = getFreeRoamZoneCoordinates();
    std::vector<std::array<float, 4>> respawnPointCoordinates = getFreeRoamZoneRespawnCoordinates();
    int numberOfZones = (int)freeRoamZones.size();

    //Variables that change every loop
    std::string chosenZone;
    int chosenZoneInteger;
    int chosenCoordinateSet;

    //Change these numbers, if the zones in the vectors are changed or rearranged!
    std::string newGPSTarget = freeRoamZones[pickRandomNumber(11, 14)];
    std::string newCareerStart = freeRoamZones[pickRandomNumber(0, 2)];

    file.open("TERandomized.nfsms", std::ios_base::app);
    file << std::string("# free roam zones and the prologue drive to safehouse are randomized").append("\n");

    for ( int loop = 0; loop < numberOfZones; loop++ )
    {
        //Select zone and coordinates to pair up
        chosenZoneInteger = pickRandomNumber(0, (int)freeRoamZones.size() - 1);
        chosenZone = freeRoamZones[chosenZoneInteger];
        chosenCoordinateSet = pickRandomNumber(0, (int)zoneCoordinates.size() - 1);
        std::array<float, 4> chosenZoneCoordinates = zoneCoordinates[chosenCoordinateSet];
        std::array<float, 4> chosenRespawnCoordinates = respawnPointCoordinates[chosenCoordinateSet];

        //Change nodes in vlted to match selection
        file << std::string("update_field gameplay ").append(chosenZone).append(" Position X ")
        .append(std::to_string(chosenZoneCoordinates[0])).append("\n");

        file << std::string("update_field gameplay ").append(chosenZone).append(" Position Y ")
        .append(std::to_string(chosenZoneCoordinates[1])).append("\n");

        file << std::string("update_field gameplay ").append(chosenZone).append(" Position Z ")
        .append(std::to_string(chosenZoneCoordinates[2])).append("\n");

        file << std::string("update_field gameplay ").append(chosenZone).append(" Radius ")
        .append(std::to_string(chosenZoneCoordinates[3])).append("\n");

        file << std::string("update_field gameplay ").append(chosenZone).append("/respawn Position X ")
        .append(std::to_string(chosenRespawnCoordinates[0])).append("\n");

        file << std::string("update_field gameplay ").append(chosenZone).append("/respawn Position Y ")
        .append(std::to_string(chosenRespawnCoordinates[1])).append("\n");

        file << std::string("update_field gameplay ").append(chosenZone).append("/respawn Position Z ")
        .append(std::to_string(chosenRespawnCoordinates[2])).append("\n");

        file << std::string("update_field gameplay ").append(chosenZone).append("/respawn Rotation ")
        .append(std::to_string(chosenRespawnCoordinates[3])).append("\n");

        if ( chosenZone == newGPSTarget || chosenZone == newCareerStart )
        {
            if ( chosenZone == newCareerStart )
            {
                file << std::string("update_field gameplay career_start_l2ra Position X ")
                .append(std::to_string(chosenRespawnCoordinates[0])).append("\n");

                file << std::string("update_field gameplay career_start_l2ra Position Y ")
                .append(std::to_string(chosenRespawnCoordinates[1])).append("\n");

                file << std::string("update_field gameplay career_start_l2ra Position Z ")
                .append(std::to_string(chosenRespawnCoordinates[2])).append("\n");

                file << std::string("update_field gameplay career_start_l2ra Rotation ")
                .append(std::to_string(chosenRespawnCoordinates[3])).append("\n");
            }

            else if ( chosenZone == newGPSTarget )
            {
                file << std::string("update_field gameplay race_bin_16/drive_to_safe_house/gpstarget Position X ")
                .append(std::to_string(chosenZoneCoordinates[0])).append("\n");

                file << std::string("update_field gameplay race_bin_16/drive_to_safe_house/gpstarget Position Y ")
                .append(std::to_string(chosenZoneCoordinates[1])).append("\n");

                file << std::string("update_field gameplay race_bin_16/drive_to_safe_house/gpstarget Position Z ")
                .append(std::to_string(chosenZoneCoordinates[2])).append("\n");

                file << std::string("update_field gameplay race_bin_16/drive_to_safe_house/gpstarget Rotation ")
                .append(std::to_string(chosenRespawnCoordinates[3])).append("\n");

                file << std::string("update_field gameplay race_bin_16/drive_to_safe_house/gpstarget Dimensions X ")
                .append("25").append("\n");

                file << std::string("update_field gameplay race_bin_16/drive_to_safe_house/gpstarget Dimensions Y ")
                .append("25").append("\n");

                file << std::string("update_field gameplay race_bin_16/drive_to_safe_house/gpstarget Dimensions Z ")
                .append("25").append("\n");

                file << std::string("update_field gameplay race_bin_16/drive_to_safe_house MiniMapItem ")
                .append(chosenZone).append("\n");

                file << std::string("update_field gameplay race_bin_16/drive_to_safe_house RespawnMarker ")
                .append(chosenZone).append("/respawn").append("\n");

                file << std::string("update_field gameplay ").append(chosenZone)
                .append(" BinIndex 16").append("\n");
            }
        }

        if ( chosenZone != newGPSTarget )
        {
            file << std::string("update_field gameplay ").append(chosenZone)
            .append(" BinIndex 15").append("\n");
        }

        //Remove processed zone/coordinate pair from pool
        freeRoamZones.erase(freeRoamZones.begin() + chosenZoneInteger);
        zoneCoordinates.erase(zoneCoordinates.begin() + chosenCoordinateSet);
        respawnPointCoordinates.erase(respawnPointCoordinates.begin() + chosenCoordinateSet);
    }

    //Remove all barriers blocking Camden and Rockport
    file << std::string("delete_field gameplay race_bin_16 Barriers\n");
    file << std::string("delete_field gameplay race_bin_15 Barriers\n");
    file << std::string("delete_field gameplay race_bin_14 Barriers\n");
    file << std::string("delete_field gameplay race_bin_13 Barriers\n");
    file << std::string("delete_field gameplay race_bin_12 Barriers\n");
    file << std::string("delete_field gameplay race_bin_11 Barriers\n");
    file << std::string("delete_field gameplay race_bin_10 Barriers\n");
    file << std::string("delete_field gameplay race_bin_09 Barriers\n\n");

    file.close();
}
