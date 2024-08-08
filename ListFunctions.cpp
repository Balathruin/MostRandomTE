//
// Created by Ted on 11/05/2024
//

#include <vector>
#include <string>
#include <unordered_map>
#include <array>
#include "ListFunctions.h"
#include "GeneralFunctions.h"

std::vector<std::pair<std::string, bool>> populateRacesCustomizable(int* originalNumberOfSonnyRacesPtr,
    int* originalNumberOfTazRacesPtr, int* originalNumberOfVicRacesPtr, int* originalNumberOfIzzyRacesPtr,
    int* originalNumberOfBigLouRacesPtr, int* originalNumberOfBaronRacesPtr, int* originalNumberOfEarlRacesPtr,
    int* originalNumberOfJewelsRacesPtr, int* originalNumberOfKazeRacesPtr, int* originalNumberOfMingRacesPtr,
    int* originalNumberOfWebsterRacesPtr, int* originalNumberOfJVRacesPtr, int* originalNumberOfRonnieRacesPtr,
    int* originalNumberOfBullRacesPtr, int* originalNumberOfRazorRacesPtr, bool easyInstall)
{
    /** Populates a vector with hardcoded strings for race names, taken from vlted. */

    //Initialize vectors
    std::vector<std::pair<std::string, bool>> vector;
    std::vector<std::pair<std::string, bool>> promptedForRaces;
    std::vector<std::pair<std::string, bool>> promptedForExtraRaces;
    std::vector<std::pair<std::string, bool>> newAdditions;

    //Variables for user input
    std::string answer;

    //Memory reservation for vectors
    vector.reserve(298);
    promptedForRaces.reserve(11);
    promptedForExtraRaces.reserve(2);
    newAdditions.reserve(11);

    /**                                     Vanilla races                                           */

    //Sonny races
    vector.emplace_back("race_bin_15/15_1_1_circuit", false);            //Race 1
    vector.emplace_back("race_bin_15/15_2_1_sprint", false);             //Race 2
    vector.emplace_back("race_bin_15/15_3_1_knockout", false);           //Race 3
    vector.emplace_back("race_bin_15/15_1_2_circuit", true);             //Boss race 1
    vector.emplace_back("race_bin_15/15_1_1_circuit_reversed", true);    //Boss race 2

    //Taz races
    vector.emplace_back("race_bin_14/14_1_1_circuit", false);             //Race 1
    vector.emplace_back("race_bin_14/14_2_1_sprint", false);              //Race 2
    vector.emplace_back("race_bin_14/14_2_2_sprint", false);              //Race 3
    vector.emplace_back("race_bin_14/14_3_1_lapknockout", false);         //Race 4
    vector.emplace_back("race_bin_14/14_4_1_tollbooth", false);           //Race 5
    vector.emplace_back("race_bin_14/14_1_2_cellphone_circuit", false);   //Race 6
    vector.emplace_back("race_bin_14/14_2_4_sprint", true);               //Boss race 1
    vector.emplace_back("race_bin_14/15_2_1_sprint_reverse", true);       //Boss race 2

    //Vic races
    vector.emplace_back("race_bin_13/13_2_1_sprint", false);              //Race 1
    vector.emplace_back("race_bin_13/13_3_1_lap_ko", false);              //Race 2
    vector.emplace_back("race_bin_13/13_3_2_lap_ko", false);              //Race 3
    vector.emplace_back("race_bin_13/13_4_1_tollbooth", false);           //Race 4
    vector.emplace_back("race_bin_13/13_4_2_tollbooth", false);           //Race 5
    vector.emplace_back("race_bin_13/13_5_1_speedtrap", false);           //Race 6
    vector.emplace_back("race_bin_13/13_5_2_speedtrap", false);           //Race 7
    vector.emplace_back("race_bin_13/13_2_3_sprint", true);               //Boss race 1
    vector.emplace_back("race_bin_13/14_2_2_r_sprint", true);             //Boss race 2

    //Izzy races
    vector.emplace_back("race_bin_12/12_1_1_circuit", false);             //Race 1
    vector.emplace_back("race_bin_12/12_4_1_tollbooth", false);           //Race 2
    vector.emplace_back("race_bin_12/12_4_2_tollbooth", false);           //Race 3
    vector.emplace_back("race_bin_12/12_5_1_speedtrap", false);           //Race 4
    vector.emplace_back("race_bin_12/12_7_3_drag", false);                //Race 5
    vector.emplace_back("race_bin_12/13_2_2_r_Sprint", false);            //Race 6
    vector.emplace_back("race_bin_12/14_2_3_r_sprint", false);            //Race 7
    vector.emplace_back("race_bin_12/12_2_1_sprint", true);               //Boss race 1
    vector.emplace_back("race_bin_12/12_1_2_circuit", true);              //Boss race 2

    //Big Lou races
    vector.emplace_back("race_bin_11/11_2_1_sprint", false);              //Race 1
    vector.emplace_back("race_bin_11/11_1_1_circuit", false);             //Race 2
    vector.emplace_back("race_bin_11/11_5_1_speedtrap_race", false);      //Race 3
    vector.emplace_back("race_bin_11/11_4_2_tollbooth", false);           //Race 4
    vector.emplace_back("race_bin_11/11_4_1_tollbooth", false);           //Race 5
    vector.emplace_back("race_bin_11/12_2_1_r_sprint", false);            //Race 6
    vector.emplace_back("race_bin_11/11_5_2_speedtrap", false);           //Race 7
    vector.emplace_back("race_bin_11/11_7_1_drag", false);                //Race 8
    vector.emplace_back("race_bin_11/11_1_2_circuit", true);              //Boss race 1
    vector.emplace_back("race_bin_11/12_1_2_r_circuit", true);            //Boss race 2

    //Baron races
    vector.emplace_back("race_bin_10/10_3_1_knockout", false);            //Race 1
    vector.emplace_back("race_bin_10/10_3_2_knockout", false);            //Race 2
    vector.emplace_back("race_bin_10/10_4_2_tollbooth", false);           //Race 3
    vector.emplace_back("race_bin_10/10_4_1_tollbooth", false);           //Race 4
    vector.emplace_back("race_bin_10/11_2_1_r_sprint", false);            //Race 5
    vector.emplace_back("race_bin_10/10_2_2_sprint", false);              //Race 6
    vector.emplace_back("race_bin_10/11_1_2_r_circuit", false);           //Race 7
    vector.emplace_back("race_bin_10/11_5_1_r_speedtrap", false);         //Race 8
    vector.emplace_back("race_bin_10/10_2_1_sprint", true);               //Boss race 1
    vector.emplace_back("race_bin_10/10_7_3_drag", true);                 //Boss race 2

    //Earl races
    vector.emplace_back("race_bin_09/9_1_1_circuit", false);              //Race 1
    vector.emplace_back("race_bin_09/9_7_1_drag", false);                 //Race 2
    vector.emplace_back("race_bin_09/9_4_1_tollbooth", false);            //Race 3
    vector.emplace_back("race_bin_09/9_5_1_speedtrap", false);            //Race 4
    vector.emplace_back("race_bin_09/9_5_2_speedtrap", false);            //Race 5
    vector.emplace_back("race_bin_09/9_4_2_tollbooth", false);            //Race 6
    vector.emplace_back("race_bin_09/12_1_1_r_circuit", false);           //Race 7
    vector.emplace_back("race_bin_09/9_3_1_lapknockout", false);          //Race 8
    vector.emplace_back("race_bin_09/9_5_3_speedtrap_race", true);        //Boss race 1
    vector.emplace_back("race_bin_09/9_2_1_sprint", true);                //Boss race 2

    //Jewels races
    vector.emplace_back("race_bin_08/8_3_1_lap_ko", false);               //Race 1
    vector.emplace_back("race_bin_08/13_3_1_r_lap_ko", false);            //Race 2
    vector.emplace_back("race_bin_08/8_5_1_speedtrap", false);            //Race 3
    vector.emplace_back("race_bin_08/8_5_2_speedtrap", false);            //Race 4
    vector.emplace_back("race_bin_08/8_2_2_sprint", false);               //Race 5
    vector.emplace_back("race_bin_08/10_4_2_r_tollbooth", false);         //Race 6
    vector.emplace_back("race_bin_08/9_4_1_r_tollbooth", false);          //Race 7
    vector.emplace_back("race_bin_08/8_2_1_sprint", true);                //Boss race 1
    vector.emplace_back("race_bin_08/8_7_5_drag", true);                  //Boss race 2

    //Kaze races
    vector.emplace_back("race_bin_07/7_2_1_sprint", false);               //Race 1
    vector.emplace_back("race_bin_07/7_4_3_tollbooth", false);            //Race 2
    vector.emplace_back("race_bin_07/7_5_1_speedtrap", false);            //Race 3
    vector.emplace_back("race_bin_07/7_4_1_tollbooth", false);            //Race 4
    vector.emplace_back("race_bin_07/7_3_1_lap_ko", false);               //Race 5
    vector.emplace_back("race_bin_07/16_1_1_r_circuit", false);           //Race 6
    vector.emplace_back("race_bin_07/8_2_1_r_sprint", false);             //Race 7
    vector.emplace_back("race_bin_07/7_1_1_circuit", false);              //Race 8
    vector.emplace_back("race_bin_07/7_4_2_tollbooth", false);            //Race 9
    vector.emplace_back("race_bin_07/7_7_4_drag", false);                 //Race 10
    vector.emplace_back("race_bin_07/7_2_2_p2p", true);                   //Boss race 1
    vector.emplace_back("race_bin_07/7_2_3_p2p", true);                   //Boss race 2

    //Ming races
    vector.emplace_back("race_bin_06/6_2_2_p2p", false);                  //Race 1
    vector.emplace_back("race_bin_06/6_4_1_tollbooth", false);            //Race 2
    vector.emplace_back("race_bin_06/6_5_1_speedtraprace", false);        //Race 3
    vector.emplace_back("race_bin_06/6_2_1_p2p", false);                  //Race 4
    vector.emplace_back("race_bin_06/6_4_2_tollbooth", false);            //Race 5
    vector.emplace_back("race_bin_06/6_3_1_lap_ko", false);               //Race 6
    vector.emplace_back("race_bin_06/14_3_1_r_lap_ko", false);            //Race 7
    vector.emplace_back("race_bin_06/6_2_3_sprint", false);               //Race 8
    vector.emplace_back("race_bin_06/6_5_3_speedtrap", false);            //Race 9
    vector.emplace_back("race_bin_06/7_7_1_r_drag", false);               //Race 10
    vector.emplace_back("race_bin_06/7_4_1_r_tollbooth", false);          //Race 11
    vector.emplace_back("race_bin_06/6_1_1_circuit", true);               //Boss race 1
    vector.emplace_back("race_bin_06/6_5_2_speedtraprace", true);         //Boss race 2

    //Webster races
    vector.emplace_back("race_bin_05/5_3_1_lap_ko", false);               //Race 1
    vector.emplace_back("race_bin_05/5_1_1_circuit", false);              //Race 2
    vector.emplace_back("race_bin_05/5_2_1_sprint", false);               //Race 3
    vector.emplace_back("race_bin_05/5_5_1_speedtrap", false);            //Race 4
    vector.emplace_back("race_bin_05/5_5_2_speedtrap", false);            //Race 5
    vector.emplace_back("race_bin_05/5_4_1_tollbooth", false);            //Race 6
    vector.emplace_back("race_bin_05/5_5_3_speedtrap", false);            //Race 7
    vector.emplace_back("race_bin_05/5_2_3_sprint", false);               //Race 8
    vector.emplace_back("race_bin_05/6_4_1_r_tollbooth", false);          //Race 9
    vector.emplace_back("race_bin_05/7_4_2_r_tollbooth", false);          //Race 10
    vector.emplace_back("race_bin_05/5_2_2_sprint", true);                //Boss race 1
    vector.emplace_back("race_bin_05/5_5_4_speedtrap", true);             //Boss race 2
    vector.emplace_back("race_bin_05/5_2_1_r_sprint", true);              //Boss race 3

    //JV races
    vector.emplace_back("race_bin_04/4_4_1_tollbooth", false);            //Race 1
    vector.emplace_back("race_bin_04/4_1_1_circuit", false);              //Race 2
    vector.emplace_back("race_bin_04/4_3_1_lapknockout", false);          //Race 3
    vector.emplace_back("race_bin_04/4_5_3_speedtrap", false);            //Race 4
    vector.emplace_back("race_bin_04/4_5_1_speedtrap", false);            //Race 5
    vector.emplace_back("race_bin_04/5_5_2_r_speedtrap", false);          //Race 6
    vector.emplace_back("race_bin_04/7_2_2_r_sprint", false);             //Race 7
    vector.emplace_back("race_bin_04/6_3_1_r_knockout", false);           //Race 8
    vector.emplace_back("race_bin_04/9_1_1_r_circuit", false);            //Race 9
    vector.emplace_back("race_bin_04/5_4_1_r_tollbooth", false);          //Race 10
    vector.emplace_back("race_bin_04/7_4_3_r_tollbooth", false);          //Race 11
    vector.emplace_back("race_bin_04/4_5_2_speedtrap", true);             //Boss race 1
    vector.emplace_back("race_bin_04/4_7_4_drag", true);                  //Boss race 2
    vector.emplace_back("race_bin_04/4_5_1_r_speedtrap", true);           //Boss race 3

    //Ronnie races
    vector.emplace_back("race_bin_03/3_2_1_sprint", false);               //Race 1
    vector.emplace_back("race_bin_03/3_3_1_lap_ko", false);               //Race 2
    vector.emplace_back("race_bin_03/3_1_1_circuit", false);              //Race 3
    vector.emplace_back("race_bin_03/3_4_1_tollbooth", false);            //Race 4
    vector.emplace_back("race_bin_03/7_2_1_r_sprint", false);             //Race 5
    vector.emplace_back("race_bin_03/4_3_1_r_knockout", false);           //Race 6
    vector.emplace_back("race_bin_03/3_5_1_speedtrap", false);            //Race 7
    vector.emplace_back("race_bin_03/3_5_2_speedtrap", false);            //Race 8
    vector.emplace_back("race_bin_03/3_4_1_r_tollbooth", false);          //Race 9
    vector.emplace_back("race_bin_03/4_4_1_r_tollbooth", false);          //Race 10
    vector.emplace_back("race_bin_03/4_2_1_r_sprint_race", false);        //Race 11
    vector.emplace_back("race_bin_03/3_7_3_drag", false);                 //Race 12
    vector.emplace_back("race_bin_03/3_1_2_r_circuit", true);             //Boss race 1
    vector.emplace_back("race_bin_03/3_2_2_sprint", true);                //Boss race 2
    vector.emplace_back("race_bin_03/3_1_2_circuit", true);               //Boss race 3

    //Bull races
    vector.emplace_back("race_bin_02/2_1_1_circuit", false);              //Race 1
    vector.emplace_back("race_bin_02/2_1_1_r_circuit", false);            //Race 2
    vector.emplace_back("race_bin_02/2_4_1_tollbooth", false);            //Race 3
    vector.emplace_back("race_bin_02/2_4_2_tollbooth", false);            //Race 4
    vector.emplace_back("race_bin_02/2_4_3_tollbooth", false);            //Race 5
    vector.emplace_back("race_bin_02/2_5_1_speedtrap", false);            //Race 6
    vector.emplace_back("race_bin_02/3_2_1_r_sprint", false);             //Race 7
    vector.emplace_back("race_bin_02/3_3_1_r_knockout", false);           //Race 8
    vector.emplace_back("race_bin_02/3_3_2_r_knockout", false);           //Race 9
    vector.emplace_back("race_bin_02/5_1_1_r_Circuit", false);            //Race 10
    vector.emplace_back("race_bin_02/5_5_1_r_speedtrap", false);          //Race 11
    vector.emplace_back("race_bin_02/2_7_1_drag", false);                 //Race 12
    vector.emplace_back("race_bin_02/3_1_1_r_circuit", true);             //Boss race 1
    vector.emplace_back("race_bin_02/9_2_2_r_sprint", true);              //Boss race 2
    vector.emplace_back("race_bin_02/2_2_1_sprint", true);                //Boss race 3

    //Razor races
    vector.emplace_back("race_bin_01/1_1_1_circuit", false);              //Race 1
    vector.emplace_back("race_bin_01/1_2_1_sprint", false);               //Race 2
    vector.emplace_back("race_bin_01/1_2_2_sprint", false);               //Race 3
    vector.emplace_back("race_bin_01/1_2_4_sprint", false);               //Race 4
    vector.emplace_back("race_bin_01/1_3_1_lapknockout", false);          //Race 5
    vector.emplace_back("race_bin_01/1_4_1_tollbooth", false);            //Race 6
    vector.emplace_back("race_bin_01/1_4_2_tollbooth", false);            //Race 7
    vector.emplace_back("race_bin_01/1_5_1_speedtraprace", false);        //Race 8
    vector.emplace_back("race_bin_01/1_5_3_speedtrap", false);            //Race 9
    vector.emplace_back("race_bin_01/2_2_1_r_sprint", false);             //Race 10
    vector.emplace_back("race_bin_01/2_4_3_r_tollbooth", false);          //Race 11
    vector.emplace_back("race_bin_01/1_5_2_speedtraprace", true);         //Boss race 1
    vector.emplace_back("race_bin_01/1_7_3_drag", true);                  //Boss race 2
    vector.emplace_back("race_bin_01/4_2_1_sprint", true);                //Boss race 3
    vector.emplace_back("race_bin_01/1_1_2_circuit", true);               //Boss race 4
    vector.emplace_back("race_bin_01/1_2_3_sprint", true);                //Boss race 5

    //Prologue races
    vector.emplace_back("16_1_1_circuit", false);
    vector.emplace_back("16_2_2_sprint", false);
    vector.emplace_back("16_2_3_sprint", false);

    //Collectors edition races
    vector.emplace_back("race_bin_collectors/21_1_1_circuit", false);
    vector.emplace_back("race_bin_collectors/21_2_2_sprint", false);
    vector.emplace_back("race_bin_collectors/21_2_1_sprint", false);


    /**                                 Track Expansion races                                  */

    if ( !easyInstall )
    {
        //Section for Sonny tracks
        promptedForRaces =
        {
            std::make_pair("race_bin_15/15_1_101_circuit", false),
            std::make_pair("race_bin_15/15_2_101_sprint", false),
            std::make_pair("race_bin_15/15_3_101_knockout", false)
        };

        newAdditions = promptUser(promptedForRaces, "\nAdd Sonny tracks? Y/N\n >> ", originalNumberOfSonnyRacesPtr);

        if ( !newAdditions.empty() )
        { vector.insert(vector.end(), newAdditions.begin(), newAdditions.end()); }

        //Section for Taz tracks
        promptedForRaces =
        {
            std::make_pair("race_bin_14/14_3_101_knockout", false),
            std::make_pair("race_bin_14/14_2_101_sprint", false),
            std::make_pair("race_bin_14/14_1_101_circuit", false),
            std::make_pair("race_bin_14/14_5_101_speedtrap", false)
        };

        newAdditions = promptUser(promptedForRaces, "\nAdd Taz tracks? Y/N\n >> ", originalNumberOfTazRacesPtr);

        if ( !newAdditions.empty() )
        { vector.insert(vector.end(), newAdditions.begin(), newAdditions.end()); }

        //Section for Vic tracks
        promptedForRaces =
        {
            std::make_pair("race_bin_13/13_1_101_circuit", false),
            std::make_pair("race_bin_13/13_1_102_circuit", false),
            std::make_pair("race_bin_13/13_2_101_sprint", false),
            std::make_pair("race_bin_13/13_3_101_knockout", false)
        };

        promptedForExtraRaces = { std::make_pair("race_bin_13/13_1_103_circuit", false) };

        newAdditions = promptUser(promptedForRaces, promptedForExtraRaces, "\nAdd Vic tracks? Y/N \n>> ",
                                  "\nAdd extra Vic track? Y/N\n >> ", originalNumberOfVicRacesPtr);

        if ( !newAdditions.empty() )
        { vector.insert(vector.end(), newAdditions.begin(), newAdditions.end()); }

        //Section for Izzy tracks
        promptedForRaces =
        {
            std::make_pair("race_bin_12/12_3_101_knockout", false),
            std::make_pair("race_bin_12/12_3_102_knockout", false),
            std::make_pair("race_bin_12/12_5_101_speedtrap", false),
            std::make_pair("race_bin_12/12_1_101_circuit", false),
            std::make_pair("race_bin_12/12_1_102_circuit", false),
            std::make_pair("race_bin_12/12_2_101_sprint", false),
            std::make_pair("race_bin_12/12_3_103_knockout", false)
        };

        promptedForExtraRaces = { std::make_pair("race_bin_12/12_1_103_circuit", false) };

        newAdditions = promptUser(promptedForRaces, promptedForExtraRaces, "\nAdd Izzy tracks? Y/N\n >> ",
                                  "\nAdd extra Izzy track? Y/N\n >> ", originalNumberOfIzzyRacesPtr);

        if ( !newAdditions.empty() )
        { vector.insert(vector.end(), newAdditions.begin(), newAdditions.end()); }

        //Section for Big Lou tracks
        promptedForRaces =
        {
            std::make_pair("race_bin_11/11_3_101_knockout", false),
            std::make_pair("race_bin_11/11_2_101_sprint", false),
            std::make_pair("race_bin_11/11_3_102_knockout", false),
            std::make_pair("race_bin_11/11_1_101_circuit", false),
            std::make_pair("race_bin_11/11_1_102_circuit", false),
            std::make_pair("race_bin_11/11_5_101_speedtrap", false),
            std::make_pair("race_bin_11/11_1_103_circuit", false),
            std::make_pair("race_bin_11/11_3_103_knockout", false)
        };

        newAdditions = promptUser(promptedForRaces, "\nAdd Big Lou tracks? Y/N\n >> ", originalNumberOfBigLouRacesPtr);

        if ( !newAdditions.empty() )
        { vector.insert(vector.end(), newAdditions.begin(), newAdditions.end()); }

        //Section for Baron tracks
        promptedForRaces =
        {
            std::make_pair("race_bin_10/10_1_101_circuit", false),
            std::make_pair("race_bin_10/10_3_101_knockout", false),
            std::make_pair("race_bin_10/10_5_101_speedtrap", false),
            std::make_pair("race_bin_10/10_3_102_knockout", false),
            std::make_pair("race_bin_10/10_2_101_sprint", false),
            std::make_pair("race_bin_10/10_1_104_circuit", false)
        };

        promptedForExtraRaces =
        {
            std::make_pair("race_bin_10/10_1_102_circuit", false),
            std::make_pair("race_bin_10/10_1_103_circuit", false)
        };

        newAdditions = promptUser(promptedForRaces, promptedForExtraRaces, "\nAdd Baron tracks? Y/N\n >> ",
                                  "\nAdd extra Baron tracks? Y/N\n >> ", originalNumberOfBaronRacesPtr);

        if ( !newAdditions.empty() )
        { vector.insert(vector.end(), newAdditions.begin(), newAdditions.end()); }

        //Section for Earl tracks
        promptedForRaces =
        {
            std::make_pair("race_bin_09/9_2_101_sprint", false),
            std::make_pair("race_bin_09/9_1_101_circuit", false),
            std::make_pair("race_bin_09/9_1_102_circuit", false),
            std::make_pair("race_bin_09/9_3_101_knockout", false),
            std::make_pair("race_bin_09/9_1_103_circuit", false),
            std::make_pair("race_bin_09/9_2_102_sprint", false),
            std::make_pair("race_bin_09/9_3_102_knockout", false),
            std::make_pair("race_bin_09/9_1_104_circuit", false)
        };

        newAdditions = promptUser(promptedForRaces, "\nAdd Earl tracks? Y/N\n >> ", originalNumberOfEarlRacesPtr);

        if ( !newAdditions.empty() )
        { vector.insert(vector.end(), newAdditions.begin(), newAdditions.end()); }

        //Section for Jewels tracks
        promptedForRaces =
        {
            std::make_pair("race_bin_08/8_1_101_circuit", false),
            std::make_pair("race_bin_08/8_2_101_sprint", false),
            std::make_pair("race_bin_08/8_3_101_knockout", false),
            std::make_pair("race_bin_08/8_3_102_knockout", false),
            std::make_pair("race_bin_08/8_1_102_circuit", false),
            std::make_pair("race_bin_08/8_1_103_circuit", false),
            std::make_pair("race_bin_08/8_1_105_circuit", false)
        };

        promptedForExtraRaces = { std::make_pair("race_bin_08/8_1_104_circuit", false) };

        newAdditions = promptUser(promptedForRaces, promptedForExtraRaces, "\nAdd Jewels tracks? Y/N\n >> ",
                                  "\nAdd extra Jewels track? Y/N\n >> ", originalNumberOfJewelsRacesPtr);

        if ( !newAdditions.empty() )
        { vector.insert(vector.end(), newAdditions.begin(), newAdditions.end()); }

        //Section for Kaze tracks
        promptedForRaces =
        {
            std::make_pair("race_bin_07/7_1_101_circuit", false),
            std::make_pair("race_bin_07/7_3_101_knockout", false),
            std::make_pair("race_bin_07/7_2_101_sprint", false),
            std::make_pair("race_bin_07/7_3_102_knockout", false),
            std::make_pair("race_bin_07/7_1_102_circuit", false),
            std::make_pair("race_bin_07/7_3_103_knockout", false),
            std::make_pair("race_bin_07/7_5_101_speedtrap", false),
            std::make_pair("race_bin_07/7_1_104_circuit", false)
        };

        promptedForExtraRaces = { std::make_pair("race_bin_07/7_1_103_circuit", false) };

        newAdditions = promptUser(promptedForRaces, promptedForExtraRaces, "\nAdd Kaze tracks? Y/N\n >> ",
                                  "\nAdd extra Kaze track? Y/N\n >> ", originalNumberOfKazeRacesPtr);

        if ( !newAdditions.empty() )
        { vector.insert(vector.end(), newAdditions.begin(), newAdditions.end()); }

        //Section for Ming tracks
        promptedForRaces =
        {
            std::make_pair("race_bin_06/6_3_101_knockout", false),
            std::make_pair("race_bin_06/6_1_101_circuit", false),
            std::make_pair("race_bin_06/6_5_101_speedtrap", false),
            std::make_pair("race_bin_06/6_2_101_sprint", false),
            std::make_pair("race_bin_06/6_3_102_knockout", false),
            std::make_pair("race_bin_06/6_1_103_circuit", false),
            std::make_pair("race_bin_06/6_1_104_circuit", false),
            std::make_pair("race_bin_06/6_3_103_knockout", false),
            std::make_pair("race_bin_06/6_1_105_circuit", false)
        };

        promptedForExtraRaces = { std::make_pair("race_bin_06/6_1_102_circuit", false) };

        newAdditions = promptUser(promptedForRaces, promptedForExtraRaces, "\nAdd Ming tracks? Y/N\n >> ",
                                  "\nAdd extra Ming track? Y/N\n >> ", originalNumberOfMingRacesPtr);

        if ( !newAdditions.empty() )
        { vector.insert(vector.end(), newAdditions.begin(), newAdditions.end()); }

        //Section for Webster tracks
        promptedForRaces =
        {
            std::make_pair("race_bin_05/5_3_101_knockout", false),
            std::make_pair("race_bin_05/5_1_106_circuit", false),
            std::make_pair("race_bin_05/5_1_101_circuit", false),
            std::make_pair("race_bin_05/5_3_102_knockout", false),
            std::make_pair("race_bin_05/5_2_101_sprint", false),
            std::make_pair("race_bin_05/5_2_102_sprint", false),
            std::make_pair("race_bin_05/5_1_102_circuit", false),
            std::make_pair("race_bin_05/5_1_103_circuit", false),
            std::make_pair("race_bin_05/5_3_103_knockout", false),
            std::make_pair("race_bin_05/5_1_104_circuit", false),
            std::make_pair("race_bin_05/5_1_105_circuit", false)
        };

        newAdditions = promptUser(promptedForRaces, "\nAdd Webster tracks? Y/N\n >> ", originalNumberOfWebsterRacesPtr);

        if ( !newAdditions.empty() )
        { vector.insert(vector.end(), newAdditions.begin(), newAdditions.end()); }

        //Section for JV tracks
        promptedForRaces =
        {
            std::make_pair("race_bin_04/4_1_101_circuit", false),
            std::make_pair("race_bin_04/4_3_101_knockout", false),
            std::make_pair("race_bin_04/4_1_102_circuit", false),
            std::make_pair("race_bin_04/4_2_101_sprint", false),
            std::make_pair("race_bin_04/4_3_102_knockout", false),
            std::make_pair("race_bin_04/4_1_103_circuit", false),
            std::make_pair("race_bin_04/4_1_104_circuit", false),
            std::make_pair("race_bin_04/4_2_102_sprint", false),
            std::make_pair("race_bin_04/4_3_103_knockout", false),
            std::make_pair("race_bin_04/4_3_104_knockout", false),
            std::make_pair("race_bin_04/4_2_103_sprint", false)
        };

        newAdditions = promptUser(promptedForRaces, "\nAdd JV tracks? Y/N\n >> ", originalNumberOfJVRacesPtr);

        if ( !newAdditions.empty() )
        { vector.insert(vector.end(), newAdditions.begin(), newAdditions.end()); }

        //Section for Ronnie tracks
        promptedForRaces =
        {
            std::make_pair("race_bin_03/3_1_101_circuit", false),
            std::make_pair("race_bin_03/3_1_102_circuit", false),
            std::make_pair("race_bin_03/3_5_101_speedtrap", false),
            std::make_pair("race_bin_03/3_3_101_knockout", false),
            std::make_pair("race_bin_03/3_1_103_circuit", false),
            std::make_pair("race_bin_03/3_3_102_knockout", false),
            std::make_pair("race_bin_03/3_2_101_sprint", false),
            std::make_pair("race_bin_03/3_1_104_circuit", false),
            std::make_pair("race_bin_03/3_3_103_knockout", false),
            std::make_pair("race_bin_03/3_3_104_knockout", false)
        };

        newAdditions = promptUser(promptedForRaces, "\nAdd Ronnie tracks? Y/N\n >> ", originalNumberOfRonnieRacesPtr);

        if ( !newAdditions.empty() )
        { vector.insert(vector.end(), newAdditions.begin(), newAdditions.end()); }

        //Section for Bull tracks
        promptedForRaces =
        {
            std::make_pair("race_bin_02/2_1_101_circuit", false),
            std::make_pair("race_bin_02/2_1_105_circuit", false),
            std::make_pair("race_bin_02/2_2_101_sprint", false),
            std::make_pair("race_bin_02/2_1_102_circuit", false),
            std::make_pair("race_bin_02/2_3_101_knockout", false),
            std::make_pair("race_bin_02/2_5_101_speedtrap", false),
            std::make_pair("race_bin_02/2_3_102_knockout", false),
            std::make_pair("race_bin_02/2_1_103_circuit", false),
            std::make_pair("race_bin_02/2_1_104_circuit", false),
            std::make_pair("race_bin_02/2_3_103_knockout", false),
            std::make_pair("race_bin_02/2_1_106_circuit", false)
        };

        newAdditions = promptUser(promptedForRaces, "\nAdd Bull tracks? Y/N\n >> ", originalNumberOfBullRacesPtr);

        if ( !newAdditions.empty() )
        { vector.insert(vector.end(), newAdditions.begin(), newAdditions.end()); }

        //Section for Razor tracks
        promptedForRaces =
        {
            std::make_pair("race_bin_01/1_1_101_circuit", false),
            std::make_pair("race_bin_01/1_1_102_circuit", false),
            std::make_pair("race_bin_01/1_3_101_knockout", false),
            std::make_pair("race_bin_01/1_1_103_circuit", false),
            std::make_pair("race_bin_01/1_1_104_circuit", false),
            std::make_pair("race_bin_01/1_3_102_knockout", false),
            std::make_pair("race_bin_01/1_3_103_knockout", false),
            std::make_pair("race_bin_01/1_3_104_knockout", false),
            std::make_pair("race_bin_01/1_1_105_circuit", false),
            std::make_pair("race_bin_01/1_1_106_circuit", false)
        };

        newAdditions = promptUser(promptedForRaces, "\nAdd Razor tracks? Y/N\n >> ", originalNumberOfRazorRacesPtr);

        if ( !newAdditions.empty() )
        { vector.insert(vector.end(), newAdditions.begin(), newAdditions.end()); }
    }

    else
    {
        //Sonny track expansion races
        vector.emplace_back("race_bin_15/15_1_101_circuit", false);            //Race 4
        vector.emplace_back("race_bin_15/15_2_101_sprint", false);             //Race 5
        vector.emplace_back("race_bin_15/15_3_101_knockout", false);           //Race 6

        *originalNumberOfSonnyRacesPtr += 3;

        //Taz track expansion races
        vector.emplace_back("race_bin_14/14_3_101_knockout", false);           //Race 7
        vector.emplace_back("race_bin_14/14_2_101_sprint", false);             //Race 8
        vector.emplace_back("race_bin_14/14_1_101_circuit", false);            //Race 9
        vector.emplace_back("race_bin_14/14_5_101_speedtrap", false);          //Race 10

        *originalNumberOfTazRacesPtr += 4;

        //Vic track expansion races
        vector.emplace_back("race_bin_13/13_1_101_circuit", false);            //Race 8
        vector.emplace_back("race_bin_13/13_1_102_circuit", false);            //Race 9
        vector.emplace_back("race_bin_13/13_2_101_sprint", false);             //Race 10
        vector.emplace_back("race_bin_13/13_3_101_knockout", false);           //Race 11

        *originalNumberOfVicRacesPtr += 4;

        //Izzy track expansion races
        vector.emplace_back("race_bin_12/12_3_101_knockout", false);           //Race 8
        vector.emplace_back("race_bin_12/12_3_102_knockout", false);           //Race 9
        vector.emplace_back("race_bin_12/12_5_101_speedtrap", false);          //Race 10
        vector.emplace_back("race_bin_12/12_1_101_circuit", false);            //Race 11
        vector.emplace_back("race_bin_12/12_1_102_circuit", false);            //Race 12
        vector.emplace_back("race_bin_12/12_2_101_sprint", false);             //Race 13
        vector.emplace_back("race_bin_12/12_3_103_knockout", false);           //Race 14

        *originalNumberOfIzzyRacesPtr += 7;

        //Big Lou expansion track races
        vector.emplace_back("race_bin_11/11_3_101_knockout", false);           //Race 9
        vector.emplace_back("race_bin_11/11_2_101_sprint", false);             //Race 10
        vector.emplace_back("race_bin_11/11_3_102_knockout", false);           //Race 11
        vector.emplace_back("race_bin_11/11_1_101_circuit", false);            //Race 12
        vector.emplace_back("race_bin_11/11_1_102_circuit", false);            //Race 13
        vector.emplace_back("race_bin_11/11_5_101_speedtrap", false);          //Race 14
        vector.emplace_back("race_bin_11/11_1_103_circuit", false);            //Race 15
        vector.emplace_back("race_bin_11/11_3_103_knockout", false);           //Race 16

        *originalNumberOfBigLouRacesPtr += 8;

        //Baron track expansion races
        vector.emplace_back("race_bin_10/10_1_101_circuit", false);            //Race 9
        vector.emplace_back("race_bin_10/10_3_101_knockout", false);           //Race 10
        vector.emplace_back("race_bin_10/10_5_101_speedtrap", false);          //Race 11
        vector.emplace_back("race_bin_10/10_3_102_knockout", false);           //Race 12
        vector.emplace_back("race_bin_10/10_2_101_sprint", false);             //Race 13
        vector.emplace_back("race_bin_10/10_1_104_circuit", false);            //Race 14

        *originalNumberOfBaronRacesPtr += 6;

        //Earl track expansion races
        vector.emplace_back("race_bin_09/9_2_101_sprint", false);              //Race 9
        vector.emplace_back("race_bin_09/9_1_101_circuit", false);             //Race 10
        vector.emplace_back("race_bin_09/9_1_102_circuit", false);             //Race 11
        vector.emplace_back("race_bin_09/9_3_101_knockout", false);            //Race 12
        vector.emplace_back("race_bin_09/9_1_103_circuit", false);             //Race 13
        vector.emplace_back("race_bin_09/9_2_102_sprint", false);              //Race 14
        vector.emplace_back("race_bin_09/9_3_102_knockout", false);            //Race 15
        vector.emplace_back("race_bin_09/9_1_104_circuit", false);             //Race 16

        *originalNumberOfEarlRacesPtr += 8;

        //Jewels track expansion races
        vector.emplace_back("race_bin_08/8_1_101_circuit", false);             //Race 8
        vector.emplace_back("race_bin_08/8_2_101_sprint", false);              //Race 9
        vector.emplace_back("race_bin_08/8_3_101_knockout", false);            //Race 10
        vector.emplace_back("race_bin_08/8_3_102_knockout", false);            //Race 11
        vector.emplace_back("race_bin_08/8_1_102_circuit", false);             //Race 12
        vector.emplace_back("race_bin_08/8_1_103_circuit", false);             //Race 13
        vector.emplace_back("race_bin_08/8_1_105_circuit", false);             //Race 14

        *originalNumberOfJewelsRacesPtr += 7;

        //Kaze track expansion races
        vector.emplace_back("race_bin_07/7_1_101_circuit", false);             //Race 11
        vector.emplace_back("race_bin_07/7_3_101_knockout", false);            //Race 12
        vector.emplace_back("race_bin_07/7_2_101_sprint", false);              //Race 13
        vector.emplace_back("race_bin_07/7_3_102_knockout", false);            //Race 14
        vector.emplace_back("race_bin_07/7_1_102_circuit", false);             //Race 15
        vector.emplace_back("race_bin_07/7_3_103_knockout", false);            //Race 16
        vector.emplace_back("race_bin_07/7_5_101_speedtrap", false);           //Race 17
        vector.emplace_back("race_bin_07/7_1_104_circuit", false);             //Race 18

        *originalNumberOfKazeRacesPtr += 8;

        //Ming track expansion races
        vector.emplace_back("race_bin_06/6_3_101_knockout", false);            //Race 12
        vector.emplace_back("race_bin_06/6_1_101_circuit", false);             //Race 13
        vector.emplace_back("race_bin_06/6_5_101_speedtrap", false);           //Race 14
        vector.emplace_back("race_bin_06/6_2_101_sprint", false);              //Race 15
        vector.emplace_back("race_bin_06/6_3_102_knockout", false);            //Race 16
        vector.emplace_back("race_bin_06/6_1_103_circuit", false);             //Race 17
        vector.emplace_back("race_bin_06/6_1_104_circuit", false);             //Race 18
        vector.emplace_back("race_bin_06/6_3_103_knockout", false);            //Race 19
        vector.emplace_back("race_bin_06/6_1_105_circuit", false);             //Race 20

        *originalNumberOfMingRacesPtr += 9;

        //Webster track expansion races
        vector.emplace_back("race_bin_05/5_3_101_knockout", false);            //Race 11
        vector.emplace_back("race_bin_05/5_1_106_circuit", false);             //Race 12
        vector.emplace_back("race_bin_05/5_1_101_circuit", false);             //Race 13
        vector.emplace_back("race_bin_05/5_3_102_knockout", false);            //Race 14
        vector.emplace_back("race_bin_05/5_2_101_sprint", false);              //Race 15
        vector.emplace_back("race_bin_05/5_2_102_sprint", false);              //Race 16
        vector.emplace_back("race_bin_05/5_1_102_circuit", false);             //Race 17
        vector.emplace_back("race_bin_05/5_1_103_circuit", false);             //Race 18
        vector.emplace_back("race_bin_05/5_3_103_knockout", false);            //Race 19
        vector.emplace_back("race_bin_05/5_1_104_circuit", false);             //Race 20
        vector.emplace_back("race_bin_05/5_1_105_circuit", false);             //Race 21

        *originalNumberOfWebsterRacesPtr += 11;

        //JV track expansion races
        vector.emplace_back("race_bin_04/4_1_101_circuit", false);             //Race 12
        vector.emplace_back("race_bin_04/4_3_101_knockout", false);            //Race 13
        vector.emplace_back("race_bin_04/4_1_102_circuit", false);             //Race 14
        vector.emplace_back("race_bin_04/4_2_101_sprint", false);              //Race 15
        vector.emplace_back("race_bin_04/4_3_102_knockout", false);            //Race 16
        vector.emplace_back("race_bin_04/4_1_103_circuit", false);             //Race 17
        vector.emplace_back("race_bin_04/4_1_104_circuit", false);             //Race 18
        vector.emplace_back("race_bin_04/4_2_102_sprint", false);              //Race 19
        vector.emplace_back("race_bin_04/4_3_103_knockout", false);            //Race 20
        vector.emplace_back("race_bin_04/4_3_104_knockout", false);            //Race 21
        vector.emplace_back("race_bin_04/4_2_103_sprint", false);              //Race 22

        *originalNumberOfJVRacesPtr += 11;

        //Ronnie track expansion races
        vector.emplace_back("race_bin_03/3_1_101_circuit", false);             //Race 13
        vector.emplace_back("race_bin_03/3_1_102_circuit", false);             //Race 14
        vector.emplace_back("race_bin_03/3_5_101_speedtrap", false);           //Race 15
        vector.emplace_back("race_bin_03/3_3_101_knockout", false);            //Race 16
        vector.emplace_back("race_bin_03/3_1_103_circuit", false);             //Race 17
        vector.emplace_back("race_bin_03/3_3_102_knockout", false);            //Race 18
        vector.emplace_back("race_bin_03/3_2_101_sprint", false);              //Race 19
        vector.emplace_back("race_bin_03/3_1_104_circuit", false);             //Race 20
        vector.emplace_back("race_bin_03/3_3_103_knockout", false);            //Race 21
        vector.emplace_back("race_bin_03/3_3_104_knockout", false);            //Race 22

        *originalNumberOfRonnieRacesPtr += 10;

        //Bull track expansion races
        vector.emplace_back("race_bin_02/2_1_101_circuit", false);             //Race 13
        vector.emplace_back("race_bin_02/2_1_105_circuit", false);             //Race 14
        vector.emplace_back("race_bin_02/2_2_101_sprint", false);              //Race 15
        vector.emplace_back("race_bin_02/2_1_102_circuit", false);             //Race 16
        vector.emplace_back("race_bin_02/2_3_101_knockout", false);            //Race 17
        vector.emplace_back("race_bin_02/2_5_101_speedtrap", false);           //Race 18
        vector.emplace_back("race_bin_02/2_3_102_knockout", false);            //Race 19
        vector.emplace_back("race_bin_02/2_1_103_circuit", false);             //Race 20
        vector.emplace_back("race_bin_02/2_1_104_circuit", false);             //Race 21
        vector.emplace_back("race_bin_02/2_3_103_knockout", false);            //Race 22
        vector.emplace_back("race_bin_02/2_1_106_circuit", false);             //Race 23

        *originalNumberOfBullRacesPtr += 11;

        //Razor track expansion races
        vector.emplace_back("race_bin_01/1_1_101_circuit", false);             //Race 12
        vector.emplace_back("race_bin_01/1_1_102_circuit", false);             //Race 13
        vector.emplace_back("race_bin_01/1_3_101_knockout", false);            //Race 14
        vector.emplace_back("race_bin_01/1_1_103_circuit", false);             //Race 15
        vector.emplace_back("race_bin_01/1_1_104_circuit", false);             //Race 16
        vector.emplace_back("race_bin_01/1_3_102_knockout", false);            //Race 17
        vector.emplace_back("race_bin_01/1_3_103_knockout", false);            //Race 18
        vector.emplace_back("race_bin_01/1_3_104_knockout", false);            //Race 19
        vector.emplace_back("race_bin_01/1_1_105_circuit", false);             //Race 20
        vector.emplace_back("race_bin_01/1_1_106_circuit", false);             //Race 21

        *originalNumberOfRazorRacesPtr += 10;
    }

    return vector;
}

std::unordered_map<std::string, int> createRaceMap()
{
    /** Creates an unordered map that translates race names from vlted into integers,
      * which are then intended to be used with the checking functions.                     */

    std::unordered_map<std::string, int> map =
    {
        /**                                     Vanilla races                                           */

        //Sonny races
        { "race_bin_15/15_1_1_circuit", 1 },
        { "race_bin_15/15_2_1_sprint", 2 },
        { "race_bin_15/15_3_1_knockout", 3 },
        { "race_bin_15/15_1_2_circuit", 4 },
        { "race_bin_15/15_1_1_circuit_reversed", 5 },

        //Taz races
        { "race_bin_14/14_1_1_circuit", 6 },
        { "race_bin_14/14_2_1_sprint", 7 },
        { "race_bin_14/14_2_2_sprint", 8 },
        { "race_bin_14/14_3_1_lapknockout", 9 },
        { "race_bin_14/14_4_1_tollbooth", 10 },
        { "race_bin_14/14_1_2_cellphone_circuit", 11 },
        { "race_bin_14/14_2_4_sprint", 12 },
        { "race_bin_14/15_2_1_sprint_reverse", 13 },

        //Vic races
        { "race_bin_13/13_2_1_sprint", 14 },
        { "race_bin_13/13_3_1_lap_ko", 15 },
        { "race_bin_13/13_3_2_lap_ko", 16 },
        { "race_bin_13/13_4_1_tollbooth", 17 },
        { "race_bin_13/13_4_2_tollbooth", 18 },
        { "race_bin_13/13_5_1_speedtrap", 19 },
        { "race_bin_13/13_5_2_speedtrap", 20 },
        { "race_bin_13/13_2_3_sprint", 21 },
        { "race_bin_13/14_2_2_r_sprint", 22 },

        //Izzy races
        { "race_bin_12/12_1_1_circuit", 23 },
        { "race_bin_12/12_4_1_tollbooth", 24 },
        { "race_bin_12/12_4_2_tollbooth", 25 },
        { "race_bin_12/12_5_1_speedtrap", 26 },
        { "race_bin_12/12_7_3_drag", 27 },
        { "race_bin_12/13_2_2_r_Sprint", 28 },
        { "race_bin_12/14_2_3_r_sprint", 29 },
        { "race_bin_12/12_2_1_sprint", 30 },
        { "race_bin_12/12_1_2_circuit", 31 },

        //Big Lou races
        { "race_bin_11/11_2_1_sprint", 32 },
        { "race_bin_11/11_1_1_circuit", 33 },
        { "race_bin_11/11_5_1_speedtrap_race", 34 },
        { "race_bin_11/11_4_2_tollbooth", 35 },
        { "race_bin_11/11_4_1_tollbooth", 36 },
        { "race_bin_11/12_2_1_r_sprint", 37 },
        { "race_bin_11/11_5_2_speedtrap", 38 },
        { "race_bin_11/11_7_1_drag", 39 },
        { "race_bin_11/11_1_2_circuit", 40 },
        { "race_bin_11/12_1_2_r_circuit", 41 },

        //Baron races
        { "race_bin_10/10_3_1_knockout", 42 },
        { "race_bin_10/10_3_2_knockout", 43 },
        { "race_bin_10/10_4_2_tollbooth", 44 },
        { "race_bin_10/10_4_1_tollbooth", 45 },
        { "race_bin_10/11_2_1_r_sprint", 46 },
        { "race_bin_10/10_2_2_sprint", 47 },
        { "race_bin_10/11_1_2_r_circuit", 48 },
        { "race_bin_10/11_5_1_r_speedtrap", 49 },
        { "race_bin_10/10_2_1_sprint", 50 },
        { "race_bin_10/10_7_3_drag", 51 },

        //Earl races
        { "race_bin_09/9_1_1_circuit", 52 },
        { "race_bin_09/9_7_1_drag", 53 },
        { "race_bin_09/9_4_1_tollbooth", 54 },
        { "race_bin_09/9_5_1_speedtrap", 55 },
        { "race_bin_09/9_5_2_speedtrap", 56 },
        { "race_bin_09/9_4_2_tollbooth", 57 },
        { "race_bin_09/12_1_1_r_circuit", 58 },
        { "race_bin_09/9_3_1_lapknockout", 59 },
        { "race_bin_09/9_5_3_speedtrap_race", 60 },
        { "race_bin_09/9_2_1_sprint", 61 },

        //Jewels races
        { "race_bin_08/8_3_1_lap_ko", 62 },
        { "race_bin_08/13_3_1_r_lap_ko", 63 },
        { "race_bin_08/8_5_1_speedtrap", 64 },
        { "race_bin_08/8_5_2_speedtrap", 65 },
        { "race_bin_08/8_2_2_sprint", 66 },
        { "race_bin_08/10_4_2_r_tollbooth", 67 },
        { "race_bin_08/9_4_1_r_tollbooth", 68 },
        { "race_bin_08/8_2_1_sprint", 69 },
        { "race_bin_08/8_7_5_drag", 70 },

        //Kaze races
        { "race_bin_07/7_2_1_sprint", 71 },
        { "race_bin_07/7_4_3_tollbooth", 72 },
        { "race_bin_07/7_5_1_speedtrap", 73 },
        { "race_bin_07/7_4_1_tollbooth", 74 },
        { "race_bin_07/7_3_1_lap_ko", 75 },
        { "race_bin_07/16_1_1_r_circuit", 76 },
        { "race_bin_07/8_2_1_r_sprint", 77 },
        { "race_bin_07/7_1_1_circuit", 78 },
        { "race_bin_07/7_4_2_tollbooth", 79 },
        { "race_bin_07/7_7_4_drag", 80 },
        { "race_bin_07/7_2_2_p2p", 81 },
        { "race_bin_07/7_2_3_p2p", 82 },

        //Ming races
        { "race_bin_06/6_2_2_p2p", 83 },
        { "race_bin_06/6_4_1_tollbooth", 84 },
        { "race_bin_06/6_5_1_speedtraprace", 85 },
        { "race_bin_06/6_2_1_p2p", 86 },
        { "race_bin_06/6_4_2_tollbooth", 87 },
        { "race_bin_06/6_3_1_lap_ko", 88 },
        { "race_bin_06/14_3_1_r_lap_ko", 89 },
        { "race_bin_06/6_2_3_sprint", 90 },
        { "race_bin_06/6_5_3_speedtrap", 91 },
        { "race_bin_06/7_7_1_r_drag", 92 },
        { "race_bin_06/7_4_1_r_tollbooth", 93 },
        { "race_bin_06/6_1_1_circuit", 94 },
        { "race_bin_06/6_5_2_speedtraprace", 95 },

        //Webster races
        { "race_bin_05/5_3_1_lap_ko", 96 },
        { "race_bin_05/5_1_1_circuit", 97 },
        { "race_bin_05/5_2_1_sprint", 98 },
        { "race_bin_05/5_5_1_speedtrap", 99 },
        { "race_bin_05/5_5_2_speedtrap", 100 },
        { "race_bin_05/5_4_1_tollbooth", 101 },
        { "race_bin_05/5_5_3_speedtrap", 102 },
        { "race_bin_05/5_2_3_sprint", 103 },
        { "race_bin_05/6_4_1_r_tollbooth", 104 },
        { "race_bin_05/7_4_2_r_tollbooth", 105 },
        { "race_bin_05/5_2_2_sprint", 106 },
        { "race_bin_05/5_5_4_speedtrap", 107 },
        { "race_bin_05/5_2_1_r_sprint", 108 },

        //JV races
        { "race_bin_04/4_4_1_tollbooth", 109 },
        { "race_bin_04/4_1_1_circuit", 110 },
        { "race_bin_04/4_3_1_lapknockout", 111 },
        { "race_bin_04/4_5_3_speedtrap", 112 },
        { "race_bin_04/4_5_1_speedtrap", 113 },
        { "race_bin_04/5_5_2_r_speedtrap", 114 },
        { "race_bin_04/7_2_2_r_sprint", 115 },
        { "race_bin_04/6_3_1_r_knockout", 116 },
        { "race_bin_04/9_1_1_r_circuit", 117 },
        { "race_bin_04/5_4_1_r_tollbooth", 118 },
        { "race_bin_04/7_4_3_r_tollbooth", 119 },
        { "race_bin_04/4_5_2_speedtrap", 120 },
        { "race_bin_04/4_7_4_drag", 121 },
        { "race_bin_04/4_5_1_r_speedtrap", 122 },

        //Ronnie races
        { "race_bin_03/3_2_1_sprint", 123 },
        { "race_bin_03/3_3_1_lap_ko", 124 },
        { "race_bin_03/3_1_1_circuit", 125 },
        { "race_bin_03/3_4_1_tollbooth", 126 },
        { "race_bin_03/7_2_1_r_sprint", 127 },
        { "race_bin_03/4_3_1_r_knockout", 128 },
        { "race_bin_03/3_5_1_speedtrap", 129 },
        { "race_bin_03/3_5_2_speedtrap", 130 },
        { "race_bin_03/3_4_1_r_tollbooth", 131 },
        { "race_bin_03/4_4_1_r_tollbooth", 132 },
        { "race_bin_03/4_2_1_r_sprint_race", 133 },
        { "race_bin_03/3_7_3_drag", 134 },
        { "race_bin_03/3_1_2_r_circuit", 135 },
        { "race_bin_03/3_2_2_sprint", 136 },
        { "race_bin_03/3_1_2_circuit", 137 },

        //Bull races
        { "race_bin_02/2_1_1_circuit", 138 },
        { "race_bin_02/2_1_1_r_circuit", 139 },
        { "race_bin_02/2_4_1_tollbooth", 140 },
        { "race_bin_02/2_4_2_tollbooth", 141 },
        { "race_bin_02/2_4_3_tollbooth", 142 },
        { "race_bin_02/2_5_1_speedtrap", 143 },
        { "race_bin_02/3_2_1_r_sprint", 144 },
        { "race_bin_02/3_3_1_r_knockout", 145 },
        { "race_bin_02/3_3_2_r_knockout", 146 },
        { "race_bin_02/5_1_1_r_Circuit", 147 },
        { "race_bin_02/5_5_1_r_speedtrap", 148 },
        { "race_bin_02/2_7_1_drag", 149 },
        { "race_bin_02/3_1_1_r_circuit", 150 },
        { "race_bin_02/9_2_2_r_sprint", 151 },
        { "race_bin_02/2_2_1_sprint", 152 },

        //Razor races
        { "race_bin_01/1_1_1_circuit", 153 },
        { "race_bin_01/1_2_1_sprint", 154 },
        { "race_bin_01/1_2_2_sprint", 155 },
        { "race_bin_01/1_2_4_sprint", 156 },
        { "race_bin_01/1_3_1_lapknockout", 157 },
        { "race_bin_01/1_4_1_tollbooth", 158 },
        { "race_bin_01/1_4_2_tollbooth", 159 },
        { "race_bin_01/1_5_1_speedtraprace", 160 },
        { "race_bin_01/1_5_3_speedtrap", 161 },
        { "race_bin_01/2_2_1_r_sprint", 162 },
        { "race_bin_01/2_4_3_r_tollbooth", 163 },
        { "race_bin_01/1_5_2_speedtraprace", 164 },
        { "race_bin_01/1_7_3_drag", 165 },
        { "race_bin_01/4_2_1_sprint", 166 },
        { "race_bin_01/1_1_2_circuit", 167 },
        { "race_bin_01/1_2_3_sprint", 168 },

        //Prologue races
        { "16_1_1_circuit", 169 },
        { "16_2_2_sprint", 170 },
        { "16_2_3_sprint", 171 },

        //Collectors edition races
        { "race_bin_collectors/21_1_1_circuit", 172 },
        { "race_bin_collectors/21_2_2_sprint", 173 },
        { "race_bin_collectors/21_2_1_sprint", 174 },


        /**                                 Track Expansion races                                  */

        //Sonny track expansion races
        { "race_bin_15/15_1_101_circuit", 175 },
        { "race_bin_15/15_2_101_sprint", 176 },
        { "race_bin_15/15_3_101_knockout", 177 },

        //Taz track expansion races
        { "race_bin_14/14_3_101_knockout", 178 },
        { "race_bin_14/14_2_101_sprint", 179 },
        { "race_bin_14/14_1_101_circuit", 180 },
        { "race_bin_14/14_5_101_speedtrap", 181 },

        //Vic track expansion races
        { "race_bin_13/13_1_101_circuit", 182 },
        { "race_bin_13/13_1_102_circuit", 183 },
        { "race_bin_13/13_2_101_sprint", 184 },
        { "race_bin_13/13_3_101_knockout", 185 },

        //Izzy track expansion races
        { "race_bin_12/12_3_101_knockout", 186 },
        { "race_bin_12/12_3_102_knockout", 187 },
        { "race_bin_12/12_5_101_speedtrap", 188 },
        { "race_bin_12/12_1_101_circuit", 189 },
        { "race_bin_12/12_1_102_circuit", 190 },
        { "race_bin_12/12_2_101_sprint", 191 },
        { "race_bin_12/12_3_103_knockout", 192 },

        //Big Lou track expansion races
        { "race_bin_11/11_3_101_knockout", 193 },
        { "race_bin_11/11_2_101_sprint", 194 },
        { "race_bin_11/11_3_102_knockout", 195 },
        { "race_bin_11/11_1_101_circuit", 196 },
        { "race_bin_11/11_1_102_circuit", 197 },
        { "race_bin_11/11_5_101_speedtrap", 198 },
        { "race_bin_11/11_1_103_circuit", 199 },
        { "race_bin_11/11_3_103_knockout", 200 },

        //Baron track expansion races
        { "race_bin_10/10_1_101_circuit", 201 },
        { "race_bin_10/10_3_101_knockout", 202 },
        { "race_bin_10/10_5_101_speedtrap", 203 },
        { "race_bin_10/10_3_102_knockout", 204 },
        { "race_bin_10/10_2_101_sprint", 205 },
        { "race_bin_10/10_1_104_circuit", 206 },

        //Earl track expansion races
        { "race_bin_09/9_2_101_sprint", 207 },
        { "race_bin_09/9_1_101_circuit", 208 },
        { "race_bin_09/9_1_102_circuit", 209 },
        { "race_bin_09/9_3_101_knockout", 210 },
        { "race_bin_09/9_1_103_circuit", 211 },
        { "race_bin_09/9_2_102_sprint", 212 },
        { "race_bin_09/9_3_102_knockout", 213 },
        { "race_bin_09/9_1_104_circuit", 214 },

        //Jewels track expansion races
        { "race_bin_08/8_1_101_circuit", 215 },
        { "race_bin_08/8_2_101_sprint", 216 },
        { "race_bin_08/8_3_101_knockout", 217 },
        { "race_bin_08/8_3_102_knockout", 218 },
        { "race_bin_08/8_1_102_circuit", 219 },
        { "race_bin_08/8_1_103_circuit", 220 },
        { "race_bin_08/8_1_105_circuit", 221 },

        //Kaze track expansion races
        { "race_bin_07/7_1_101_circuit", 222 },
        { "race_bin_07/7_3_101_knockout", 223 },
        { "race_bin_07/7_2_101_sprint", 224 },
        { "race_bin_07/7_3_102_knockout", 225 },
        { "race_bin_07/7_1_102_circuit", 226 },
        { "race_bin_07/7_3_103_knockout", 227 },
        { "race_bin_07/7_5_101_speedtrap", 228 },
        { "race_bin_07/7_1_104_circuit", 229 },

        //Ming track expansion races
        { "race_bin_06/6_3_101_knockout", 230 },
        { "race_bin_06/6_1_101_circuit", 231 },
        { "race_bin_06/6_5_101_speedtrap", 232 },
        { "race_bin_06/6_2_101_sprint", 233 },
        { "race_bin_06/6_3_102_knockout", 234 },
        { "race_bin_06/6_1_103_circuit", 235 },
        { "race_bin_06/6_1_104_circuit", 236 },
        { "race_bin_06/6_3_103_knockout", 237 },
        { "race_bin_06/6_1_105_circuit", 238 },

        //Webster track expansion races
        { "race_bin_05/5_3_101_knockout", 239 },
        { "race_bin_05/5_1_106_circuit", 240 },
        { "race_bin_05/5_1_101_circuit", 241 },
        { "race_bin_05/5_3_102_knockout", 242 },
        { "race_bin_05/5_2_101_sprint", 243 },
        { "race_bin_05/5_2_102_sprint", 244 },
        { "race_bin_05/5_1_102_circuit", 245 },
        { "race_bin_05/5_1_103_circuit", 246 },
        { "race_bin_05/5_3_103_knockout", 247 },
        { "race_bin_05/5_1_104_circuit", 248 },
        { "race_bin_05/5_1_105_circuit", 249 },

        //JV track expansion races
        { "race_bin_04/4_1_101_circuit", 250 },
        { "race_bin_04/4_3_101_knockout", 251 },
        { "race_bin_04/4_1_102_circuit", 252 },
        { "race_bin_04/4_2_101_sprint", 253 },
        { "race_bin_04/4_3_102_knockout", 254 },
        { "race_bin_04/4_1_103_circuit", 255 },
        { "race_bin_04/4_1_104_circuit", 256 },
        { "race_bin_04/4_2_102_sprint", 257 },
        { "race_bin_04/4_3_103_knockout", 258 },
        { "race_bin_04/4_3_104_knockout", 259 },
        { "race_bin_04/4_2_103_sprint", 260 },

        //Ronnie track expansion races
        { "race_bin_03/3_1_101_circuit", 261 },
        { "race_bin_03/3_1_102_circuit", 262 },
        { "race_bin_03/3_5_101_speedtrap", 263 },
        { "race_bin_03/3_3_101_knockout", 264 },
        { "race_bin_03/3_1_103_circuit", 265 },
        { "race_bin_03/3_3_102_knockout", 266 },
        { "race_bin_03/3_2_101_sprint", 267 },
        { "race_bin_03/3_1_104_circuit", 268 },
        { "race_bin_03/3_3_103_knockout", 269 },
        { "race_bin_03/3_3_104_knockout", 270 },

        //Bull track expansion races
        { "race_bin_02/2_1_101_circuit", 271 },
        { "race_bin_02/2_1_105_circuit", 272 },
        { "race_bin_02/2_2_101_sprint", 273 },
        { "race_bin_02/2_1_102_circuit", 274 },
        { "race_bin_02/2_3_101_knockout", 275 },
        { "race_bin_02/2_5_101_speedtrap", 276 },
        { "race_bin_02/2_3_102_knockout", 277 },
        { "race_bin_02/2_1_103_circuit", 278 },
        { "race_bin_02/2_1_104_circuit", 279 },
        { "race_bin_02/2_3_103_knockout", 280 },
        { "race_bin_02/2_1_106_circuit", 281 },

        //Razor track expansion races
        { "race_bin_01/1_1_101_circuit", 282 },
        { "race_bin_01/1_1_102_circuit", 283 },
        { "race_bin_01/1_3_101_knockout", 284 },
        { "race_bin_01/1_1_103_circuit", 285 },
        { "race_bin_01/1_1_104_circuit", 286 },
        { "race_bin_01/1_3_102_knockout", 287 },
        { "race_bin_01/1_3_103_knockout", 288 },
        { "race_bin_01/1_3_104_knockout", 289 },
        { "race_bin_01/1_1_105_circuit", 290 },
        { "race_bin_01/1_1_106_circuit", 291 },

        //Vic track expansion extra race
        { "race_bin_13/13_1_103_circuit", 292 },

        //Izzy track expansion extra race
        { "race_bin_12/12_1_103_circuit", 293 },

        //Baron track expansion extra races
        { "race_bin_10/10_1_102_circuit", 294 },
        { "race_bin_10/10_1_103_circuit", 295 },

        //Jewels track expansion extra race
        { "race_bin_08/8_1_104_circuit", 296 },

        //Kaze track expansion extra race
        { "race_bin_07/7_1_103_circuit", 297 },

        //Ming track expansion extra race
        { "race_bin_06/6_1_102_circuit", 298 }
    };

    return map;
}

std::unordered_map<int, float> createDistanceMap()
{
    std::unordered_map<int, float> map =
    {
        /**                                     Vanilla races                                           */

        //Sonny races
        { 1, 6821.787 },
        { 3, 8072.063 },
        { 4, 9071.073 },
        { 5, 6867.008 },

        //Taz races
        { 6, 9093.753 },
        { 9, 11878.16 },
        { 11, 12012.39 },

        //Vic races
        { 15, 7651.285 },
        { 16, 16436.66 },

        //Izzy races
        { 23, 10412.57 },
        { 31, 14270.22 },

        //Big Lou races
        { 33, 14873.77 },
        { 40, 10937.99 },
        { 41, 14255.78 },

        //Baron races
        { 42, 20812.8 },
        { 43, 15418.85 },
        { 48, 11309.25 },

        //Earl races
        { 52, 11856.15 },
        { 58, 10394.67 },
        { 59, 14941.07 },

        //Jewels races
        { 62, 11431.2 },
        { 63, 15005.2 },

        //Kaze races
        { 75, 16910.86 },
        { 76, 6624.065 },
        { 78, 11356.84 },

        //Ming races
        { 88, 11650.45 },
        { 89, 11646.06 },
        { 94, 8091.473 },

        //Webster races
        { 96, 16676.22 },
        { 97, 13528.04 },

        //JV races
        { 110, 8550.73 },
        { 111, 15231.44 },
        { 116, 11631.94 },
        { 117, 11371.47 },

        //Ronnie races
        { 124, 28295.89 },
        { 125, 13665.87 },
        { 128, 15369.18 },
        { 135, 12610.69 },
        { 137, 12702 },

        //Bull races
        { 138, 22309.38 },
        { 139, 22289.91 },
        { 145, 28644.66 },
        { 146, 16029.05 },
        { 147, 13623.32 },
        { 150, 13595.77 },

        //Razor races
        { 153, 28774.36 },
        { 157, 18671.18 },
        { 167, 16663.59 },

        //Prologue race
        { 169, 6624.065 },

        //Collectors Edition race
        { 172, 15919.88 },


        /**                                 Track Expansion races                                  */

        //Baron track expansion race
        { 206, 12920 },

        //Earl track expansion races
        { 213, 16755 },
        { 214, 12525 },

        //Jewels track expansion race
        { 221, 18578 },

        //Kaze track expansion race
        { 229, 12895 },

        //Ming track expansion races
        { 237, 11215 },
        { 238, 10860 },

        //Webster track expansion races
        { 240, 18916 },
        { 249, 14245 },

        //JV track expansion race
        { 259, 15290 },

        //Ronnie track expansion race
        { 270, 11800 },

        //Bull track expansion race
        { 281, 18405 },

        //Razor track expansion races
        { 290, 19470 },
        { 291, 20220 }
    };

    return map;
}

std::unordered_map<int, float> createTimeMap()
{
    std::unordered_map<int, float> map =
    {
        /**                                 Track Expansion races                                  */

        //Sonny track expansion races
        { 175, 37.82 },
        { 177, 37.90 },

        //Taz track expansion races
        { 178, 42.63 },
        { 180, 107.76 },

        //Vic track expansion races
        { 182, 40.90 },
        { 183, 45.10 },
        { 185, 37.82 },

        //Izzy track expansion races
        { 186, 39.80 },
        { 187, 43.82 },
        { 189, 51.72 },
        { 190, 106.33 },
        { 189, 33.44 },
        { 192, 48.84 },

        //Big Lou track expansion races
        { 193, 46.37 },
        { 195, 49.11 },
        { 196, 57.76 },
        { 197, 45.85 },
        { 199, 107.31 },
        { 200, 38.54 },

        //Baron track expansion races
        { 201, 115.84 },
        { 202, 55.75 },
        { 204, 53.95 },

        //Earl track expansion races
        { 208, 115.61 },
        { 209, 52.57 },
        { 210, 48.67 },
        { 211, 37.82 },

        //Jewels track expansion races
        { 215, 55.93 },
        { 217, 104.97 },
        { 218, 46.95 },
        { 219, 42.62 },
        { 220, 59.20 },

        //Kaze track expansion races
        { 222, 128.86 },
        { 223, 108.47 },
        { 225, 52.62 },
        { 226, 131.34 },
        { 227, 53.93 },

        //Ming track expansion races
        { 230, 112.19 },
        { 231, 143.33 },
        { 234, 119.60 },
        { 235, 135.16 },
        { 236, 127.23 },

        //Webster track expansion races
        { 239, 111.89 },
        { 241, 53.80 },
        { 242, 112.13 },
        { 245, 144.99 },
        { 246, 102.61 },
        { 247, 105.94 },
        { 248, 56.53 },

        //JV track expansion races
        { 250, 56.43 },
        { 251, 111.38 },
        { 252, 141.97 },
        { 254, 104.93 },
        { 255, 136.60 },
        { 256, 55.90 },
        { 258, 115.81 },

        //Ronnie track expansion races
        { 261, 150.83 },
        { 262, 150.30 },
        { 264, 117.66 },
        { 265, 208.87 },
        { 266, 101.98 },
        { 268, 108.58 },
        { 269, 118.48 },

        //Bull track expansion races
        { 271, 152.72 },
        { 272, 153.43 },
        { 274, 131.29 },
        { 275, 117.24 },
        { 277, 115.69 },
        { 278, 150.58 },
        { 279, 203.88 },
        { 280, 100.76 },

        //Razor track expansion races
        { 282, 143.77 },
        { 283, 143.34 },
        { 284, 132.96 },
        { 285, 122.77 },
        { 286, 241.69 },
        { 287, 128.65 },
        { 288, 140.77 },
        { 289, 131.54 },

        //Vic track expansion extra race
        { 292, 37.77 },

        //Izzy track expansion extra race
        { 293, 33.44 },

        //Baron track expansion extra races
        { 294, 36.47 },
        { 295, 35.97 },

        //Jewels track expansion extra race
        { 296, 33.99 },

        //Kaze track expansion extra race
        { 297, 36.15 },

        //Ming track expansion extra race
        { 298, 35.58 }
    };

    return map;
}

std::vector<std::pair<std::string, std::string>> getListOfChildrenFieldUpdatesForSpeedtraps(int raceInteger)
{
    std::vector<std::pair<std::string, std::string>> list;

    switch(raceInteger)
    {
        /**                                     Vanilla races                                           */

        //Vic speedtrap races
        case 19:
            list.reserve(7);
            list =
            {
                { "race_bin_13/13_5_1_speedtrap/checkpoint5", "5" },
                { "race_bin_13/13_5_1_speedtrap/checkpoint6", "6" },
                { "race_bin_13/13_5_1_speedtrap/checkpoint7", "7" },
                { "race_bin_13/13_5_1_speedtrap/checkpoint8", "8" },
                { "race_bin_13/13_5_1_speedtrap/finishline", "9" },
                { "race_bin_13/13_5_1_speedtrap/shortcut2", "10" },
                { "race_bin_13/13_5_1_speedtrap/wrongway", "11" }
            };

            return list;

        case 20:
            list.reserve(6);
            list =
            {
                { "race_bin_13/13_5_2_speedtrap/wrongway", "10" },
                { "race_bin_13/13_5_2_speedtrap/shortcut1", "11" },
                { "race_bin_13/13_5_2_speedtrap/shortcut2", "12" },
                { "race_bin_13/13_5_2_speedtrap/shortcut3", "13" },
                { "race_bin_13/13_5_2_speedtrap/shortcut4", "14" },
                { "race_bin_13/13_5_2_speedtrap/shortcut5", "15" }
            };

            return list;

        //Izzy speedtrap races
        case 26:
            list.reserve(6);
            list =
            {
                { "race_bin_12/12_5_1_speedtrap/wrongway", "9" },
                { "race_bin_12/12_5_1_speedtrap/12_5_1_finishline_reverse", "10" },
                { "race_bin_12/12_5_1_speedtrap/12_5_1_startgrid_reverse", "11" },
                { "race_bin_12/12_5_1_speedtrap/shortcut1", "12" },
                { "race_bin_12/12_5_1_speedtrap/shortcut3", "13" },
                { "race_bin_12/12_5_1_speedtrap/shortcut4", "14" }
            };

            return list;

        //Big Lou speedtraps races
        case 34:
            list = { { "race_bin_11/11_5_1_speedtrap_race/wrongway", "12" } };
            return list;

        case 38:
            list.reserve(7);
            list =
            {
                { "race_bin_11/11_5_2_speedtrap/wrongway", "12" },
                { "race_bin_11/11_5_2_speedtrap/shortcut11", "13" },
                { "race_bin_11/11_5_2_speedtrap/shortcut12", "14" },
                { "race_bin_11/11_5_2_speedtrap/shortcut13", "15" },
                { "race_bin_11/11_5_2_speedtrap/shortcut14", "16" },
                { "race_bin_11/11_5_2_speedtrap/shortcut15", "17" },
                { "race_bin_11/11_5_2_speedtrap/shortcut16", "18" }
            };

            return list;

        //Baron speedtrap races
        case 49:
            list = { { "race_bin_10/11_5_1_r_speedtrap/wrongway", "11" } };
            return list;

        //Earl speedtrap races
        case 55:
            list.reserve(5);
            list =
            {
                { "race_bin_09/9_5_1_speedtrap/wrongway", "9" },
                { "race_bin_09/9_5_1_speedtrap/shortcut1", "10" },
                { "race_bin_09/9_5_1_speedtrap/shortcut2", "11" },
                { "race_bin_09/9_5_1_speedtrap/shortcut3", "12" },
                { "race_bin_09/9_5_1_speedtrap/shortcut4", "13" }
            };

            return list;

        case 56:
            list.reserve(7);
            list =
            {
                { "race_bin_09/9_5_2_speedtrap/wrongway", "9" },
                { "race_bin_09/9_5_2_speedtrap/shortcut1", "10" },
                { "race_bin_09/9_5_2_speedtrap/shortcut2", "11" },
                { "race_bin_09/9_5_2_speedtrap/shortcut3", "12" },
                { "race_bin_09/9_5_2_speedtrap/shortcut4", "13" },
                { "race_bin_09/9_5_2_speedtrap/shortcut5", "14" },
                { "race_bin_09/9_5_2_speedtrap/shortcut6", "15" }
            };

            return list;

        case 60:
            list.reserve(8);
            list =
            {
                { "race_bin_09/9_5_3_speedtrap_race/wrongway", "11" },
                { "race_bin_09/9_5_3_speedtrap_race/shortcut1", "12" },
                { "race_bin_09/9_5_3_speedtrap_race/shortcut2", "13" },
                { "race_bin_09/9_5_3_speedtrap_race/shortcut3", "14" },
                { "race_bin_09/9_5_3_speedtrap_race/shortcut4", "15" },
                { "race_bin_09/9_5_3_speedtrap_race/shortcut5", "16" },
                { "race_bin_09/9_5_3_speedtrap_race/shortcut6", "17" },
                { "race_bin_09/9_5_3_speedtrap_race/shortcut7", "18" }
            };

            return list;

        //Jewels speedtrap races
        case 64:
            list.reserve(12);
            list =
            {
                { "race_bin_08/8_5_1_speedtrap/wrongway", "12" },
                { "race_bin_08/8_5_1_speedtrap/8_5_1_finishline_reverse", "13" },
                { "race_bin_08/8_5_1_speedtrap/8_5_1_startgrid_reverse", "14" },
                { "race_bin_08/8_5_1_speedtrap/shortcut1", "15" },
                { "race_bin_08/8_5_1_speedtrap/shortcut2", "16" },
                { "race_bin_08/8_5_1_speedtrap/shortcut3", "17" },
                { "race_bin_08/8_5_1_speedtrap/shortcut4", "18" },
                { "race_bin_08/8_5_1_speedtrap/shortcut5", "19" },
                { "race_bin_08/8_5_1_speedtrap/shortcut6", "20" },
                { "race_bin_08/8_5_1_speedtrap/shortcut7", "21" },
                { "race_bin_08/8_5_1_speedtrap/shortcut8", "22" },
                { "race_bin_08/8_5_1_speedtrap/shortcut9", "23" }
            };

            return list;

        case 65:
            list.reserve(7);
            list =
            {
                { "race_bin_08/8_5_2_speedtrap/wrongway", "9" },
                { "race_bin_08/8_5_2_speedtrap/8_5_2_finishline_reverse", "10" },
                { "race_bin_08/8_5_2_speedtrap/8_5_2_startgrid_reverse", "11" },
                { "race_bin_08/8_5_2_speedtrap/shortcut1", "12" },
                { "race_bin_08/8_5_2_speedtrap/shortcut2", "13" },
                { "race_bin_08/8_5_2_speedtrap/shortcut3", "14" },
                { "race_bin_08/8_5_2_speedtrap/shortcut4", "15" }
            };

            return list;

        //Kaze speedtrap race
        case 73:
            list.reserve(12);
            list =
            {
                { "race_bin_07/7_5_1_speedtrap/checkpoint8", "9" },
                { "race_bin_07/7_5_1_speedtrap/checkpoint9", "10" },
                { "race_bin_07/7_5_1_speedtrap/checkpoint10", "11" },
                { "race_bin_07/7_5_1_speedtrap/shortcut1", "12" },
                { "race_bin_07/7_5_1_speedtrap/shortcut2", "13" },
                { "race_bin_07/7_5_1_speedtrap/shortcut3", "14" },
                { "race_bin_07/7_5_1_speedtrap/wrongway", "15" },
                { "race_bin_07/7_5_1_speedtrap/shortcut5", "16" },
                { "race_bin_07/7_5_1_speedtrap/shortcut6", "17" },
                { "race_bin_07/7_5_1_speedtrap/shortcut7", "18" },
                { "race_bin_07/7_5_1_speedtrap/shortcut8", "19" },
                { "race_bin_07/7_5_1_speedtrap/shortcut9", "20" }
            };

            return list;

        //Ming speedtrap races
        case 85:
            list.reserve(5);
            list =
            {
                { "race_bin_06/6_5_1_speedtraprace/wrongway", "9" },
                { "race_bin_06/6_5_1_speedtraprace/shortcut1", "10" },
                { "race_bin_06/6_5_1_speedtraprace/shortcut2", "11" },
                { "race_bin_06/6_5_1_speedtraprace/shortcut3", "12" },
                { "race_bin_06/6_5_1_speedtraprace/shortcut5", "13" }
            };

            return list;

        case 91:
            list.reserve(9);
            list =
            {
                { "race_bin_06/6_5_3_speedtrap/wrongway", "12" },
                { "race_bin_06/6_5_3_speedtrap/shortcut1", "13" },
                { "race_bin_06/6_5_3_speedtrap/shortcut2", "14" },
                { "race_bin_06/6_5_3_speedtrap/shortcut3", "15" },
                { "race_bin_06/6_5_3_speedtrap/shortcut4", "16" },
                { "race_bin_06/6_5_3_speedtrap/shortcut5", "17" },
                { "race_bin_06/6_5_3_speedtrap/shortcut6", "18" },
                { "race_bin_06/6_5_3_speedtrap/shortcut7", "19" },
                { "race_bin_06/6_5_3_speedtrap/shortcut8", "20" }
            };

            return list;

        case 95:
            list.reserve(6);
            list =
            {
                { "race_bin_06/6_5_2_speedtraprace/wrongway", "10" },
                { "race_bin_06/6_5_2_speedtraprace/shortcut1", "11" },
                { "race_bin_06/6_5_2_speedtraprace/shortcut2", "12" },
                { "race_bin_06/6_5_2_speedtraprace/shortcut3", "13" },
                { "race_bin_06/6_5_2_speedtraprace/shortcut4", "14" },
                { "race_bin_06/6_5_2_speedtraprace/shortcut5", "15" }
            };

            return list;

        //Webster speedtrap races
        case 99:
            list.reserve(4);
            list =
            {
                { "race_bin_05/5_5_1_speedtrap/wrongway", "10" },
                { "race_bin_05/5_5_1_speedtrap/shortcut1", "11" },
                { "race_bin_05/5_5_1_speedtrap/shortcut2", "12" },
                { "race_bin_05/5_5_1_speedtrap/shortcut3", "13" }
            };

            return list;

        case 100:
            list.reserve(4);
            list =
            {
                { "race_bin_05/5_5_2_speedtrap/wrongway", "10" },
                { "race_bin_05/5_5_2_speedtrap/shortcut1", "11" },
                { "race_bin_05/5_5_2_speedtrap/shortcut2", "12" },
                { "race_bin_05/5_5_2_speedtrap/shortcut3", "13" }
            };

            return list;

        case 102:
            list.reserve(11);
            list =
            {
                { "race_bin_05/5_5_3_speedtrap/wrongway", "9" },
                { "race_bin_05/5_5_3_speedtrap/finishline_reverse", "10" },
                { "race_bin_05/5_5_3_speedtrap/startgrid_reverse", "11" },
                { "race_bin_05/5_5_3_speedtrap/shortcut1", "12" },
                { "race_bin_05/5_5_3_speedtrap/shortcut2", "13" },
                { "race_bin_05/5_5_3_speedtrap/shortcut3", "14" },
                { "race_bin_05/5_5_3_speedtrap/shortcut4", "15" },
                { "race_bin_05/5_5_3_speedtrap/shortcut5", "16" },
                { "race_bin_05/5_5_3_speedtrap/shortcut6", "17" },
                { "race_bin_05/5_5_3_speedtrap/shortcut7", "18" },
                { "race_bin_05/5_5_3_speedtrap/shortcut8", "19" }
            };

            return list;

        case 107:
            list.reserve(12);
            list =
            {
                { "race_bin_05/5_5_4_speedtrap/wrongway", "12" },
                { "race_bin_05/5_5_4_speedtrap/shortcut1", "13" },
                { "race_bin_05/5_5_4_speedtrap/shortcut2", "14" },
                { "race_bin_05/5_5_4_speedtrap/shortcut3", "15" },
                { "race_bin_05/5_5_4_speedtrap/shortcut4", "16" },
                { "race_bin_05/5_5_4_speedtrap/shortcut5", "17" },
                { "race_bin_05/5_5_4_speedtrap/shortcut6", "18" },
                { "race_bin_05/5_5_4_speedtrap/shortcut7", "19" },
                { "race_bin_05/5_5_4_speedtrap/shortcut8", "20" },
                { "race_bin_05/5_5_4_speedtrap/shortcut9", "21" },
                { "race_bin_05/5_5_4_speedtrap/shortcut10", "22" },
                { "race_bin_05/5_5_4_speedtrap/shortcut11", "23" }
            };

            return list;

        //JV speedtrap races
        case 112:
            list.reserve(21);
            list =
            {
                { "race_bin_04/4_5_3_speedtrap/4_5_3_ai_cpt8", "9" },
                { "race_bin_04/4_5_3_speedtrap/4_5_3_ai_cpt9", "10" },
                { "race_bin_04/4_5_3_speedtrap/4_5_3_ai_cpt10", "11" },
                { "race_bin_04/4_5_3_speedtrap/wrongway", "12" },
                { "race_bin_04/4_5_3_speedtrap/startgrid_reverse", "13" },
                { "race_bin_04/4_5_3_speedtrap/finishline_reverse", "14" },
                { "race_bin_04/4_5_3_speedtrap/shortcut1", "15" },
                { "race_bin_04/4_5_3_speedtrap/shortcut2", "16" },
                { "race_bin_04/4_5_3_speedtrap/shortcut3", "17" },
                { "race_bin_04/4_5_3_speedtrap/shortcut4", "18" },
                { "race_bin_04/4_5_3_speedtrap/shortcut5", "19" },
                { "race_bin_04/4_5_3_speedtrap/shortcut6", "20" },
                { "race_bin_04/4_5_3_speedtrap/shortcut7", "21" },
                { "race_bin_04/4_5_3_speedtrap/shortcut8", "22" },
                { "race_bin_04/4_5_3_speedtrap/shortcut9", "23" },
                { "race_bin_04/4_5_3_speedtrap/shortcut10", "24" },
                { "race_bin_04/4_5_3_speedtrap/shortcut11", "25" },
                { "race_bin_04/4_5_3_speedtrap/shortcut12", "26" },
                { "race_bin_04/4_5_3_speedtrap/shortcut13", "27" },
                { "race_bin_04/4_5_3_speedtrap/shortcut14", "28" },
                { "race_bin_04/4_5_3_speedtrap/shortcut15", "29" }
            };

            return list;

        case 113:
            list.reserve(8);
            list =
            {
                { "race_bin_04/4_5_1_speedtrap/wrongway", "9" },
                { "race_bin_04/4_5_1_speedtrap/finishline_reverse", "10" },
                { "race_bin_04/4_5_1_speedtrap/startgrid_reverse", "11" },
                { "race_bin_04/4_5_1_speedtrap/shortcut1", "12" },
                { "race_bin_04/4_5_1_speedtrap/shortcut2", "13" },
                { "race_bin_04/4_5_1_speedtrap/shortcut3", "14" },
                { "race_bin_04/4_5_1_speedtrap/shortcut4", "15" },
                { "race_bin_04/4_5_1_speedtrap/shortcut5", "16" }
            };

            return list;

        case 114:
            list.reserve(2);
            list =
            {
                { "race_bin_04/5_5_2_r_speedtrap/wrongway", "10" },
                { "race_bin_04/5_5_2_r_speedtrap/shortcut1", "11" }
            };

            return list;

        case 120:
            list.reserve(7);
            list =
            {
                { "race_bin_04/4_5_2_speedtrap/wrongway", "11" },
                { "race_bin_04/4_5_2_speedtrap/shortcut1", "12" },
                { "race_bin_04/4_5_2_speedtrap/shortcut2", "13" },
                { "race_bin_04/4_5_2_speedtrap/shortcut3", "14" },
                { "race_bin_04/4_5_2_speedtrap/shortcut4", "15" },
                { "race_bin_04/4_5_2_speedtrap/shortcut5", "16" },
                { "race_bin_04/4_5_2_speedtrap/shortcut6", "17" }
            };

            return list;

        case 122:
            list.reserve(6);
            list =
            {
                { "race_bin_04/4_5_1_r_speedtrap/wrongway", "9" },
                { "race_bin_04/4_5_1_r_speedtrap/shortcut1", "10" },
                { "race_bin_04/4_5_1_r_speedtrap/shortcut2", "11" },
                { "race_bin_04/4_5_1_r_speedtrap/shortcut3", "12" },
                { "race_bin_04/4_5_1_r_speedtrap/shortcut4", "13" },
                { "race_bin_04/4_5_1_r_speedtrap/shortcut5", "14" }
            };

            return list;

        //Ronnie speedtrap races
        case 129:
            list.reserve(7);
            list =
            {
                { "race_bin_03/3_5_1_speedtrap/wrongway", "12" },
                { "race_bin_03/3_5_1_speedtrap/finishline_reverse", "13" },
                { "race_bin_03/3_5_1_speedtrap/startgrid_reverse", "14" },
                { "race_bin_03/3_5_1_speedtrap/shortcut1", "15" },
                { "race_bin_03/3_5_1_speedtrap/shortcut2", "16" },
                { "race_bin_03/3_5_1_speedtrap/shortcut3", "17" },
                { "race_bin_03/3_5_1_speedtrap/shortcut4", "18" }
            };

            return list;

        case 130:
            list.reserve(14);
            list =
            {
                { "race_bin_03/3_5_2_speedtrap/wrongway", "9" },
                { "race_bin_03/3_5_2_speedtrap/finishline_reverse", "10" },
                { "race_bin_03/3_5_2_speedtrap/startgrid_reverse", "11" },
                { "race_bin_03/3_5_2_speedtrap/shortcut1", "12" },
                { "race_bin_03/3_5_2_speedtrap/shortcut2", "13" },
                { "race_bin_03/3_5_2_speedtrap/shortcut3", "14" },
                { "race_bin_03/3_5_2_speedtrap/shortcut4", "15" },
                { "race_bin_03/3_5_2_speedtrap/shortcut5", "16" },
                { "race_bin_03/3_5_2_speedtrap/shortcut6", "17" },
                { "race_bin_03/3_5_2_speedtrap/shortcut7", "18" },
                { "race_bin_03/3_5_2_speedtrap/shortcut8", "19" },
                { "race_bin_03/3_5_2_speedtrap/shortcut9", "20" },
                { "race_bin_03/3_5_2_speedtrap/shortcut10", "21" },
                { "race_bin_03/3_5_2_speedtrap/shortcut11", "22" }
            };

            return list;

        //Bull speedtrap races
        case 143:
            list.reserve(14);
            list =
            {
                { "race_bin_02/2_5_1_speedtrap/wrongway", "11" },
                { "race_bin_02/2_5_1_speedtrap/startgrid_reverse", "12" },
                { "race_bin_02/2_5_1_speedtrap/finishline_reverse", "13" },
                { "race_bin_02/2_5_1_speedtrap/shortcut1", "14" },
                { "race_bin_02/2_5_1_speedtrap/shortcut2", "15" },
                { "race_bin_02/2_5_1_speedtrap/shortcut3", "16" },
                { "race_bin_02/2_5_1_speedtrap/shortcut4", "17" },
                { "race_bin_02/2_5_1_speedtrap/shortcut5", "18" },
                { "race_bin_02/2_5_1_speedtrap/shortcut6", "19" },
                { "race_bin_02/2_5_1_speedtrap/shortcut7", "20" },
                { "race_bin_02/2_5_1_speedtrap/shortcut8", "21" },
                { "race_bin_02/2_5_1_speedtrap/shortcut9", "22" },
                { "race_bin_02/2_5_1_speedtrap/shortcut10", "23" },
                { "race_bin_02/2_5_1_speedtrap/shortcut11", "24" }
            };

            return list;

        case 148:
            list.reserve(7);
            list =
            {
                { "race_bin_02/5_5_1_r_speedtrap/wrongway", "10" },
                { "race_bin_02/5_5_1_r_speedtrap/shortcut1", "11" },
                { "race_bin_02/5_5_1_r_speedtrap/shortcut2", "12" },
                { "race_bin_02/5_5_1_r_speedtrap/shortcut3", "13" },
                { "race_bin_02/5_5_1_r_speedtrap/shortcut4", "14" },
                { "race_bin_02/5_5_1_r_speedtrap/shortcut5", "15" },
                { "race_bin_02/5_5_1_r_speedtrap/shortcut6", "16" }
            };

            return list;

        //Razor speedtrap races
        case 160:
            list.reserve(10);
            list =
            {
                { "race_bin_01/1_5_1_speedtraprace/1_5_1_ai_cp8", "9" },
                { "race_bin_01/1_5_1_speedtraprace/wrongway", "10" },
                { "race_bin_01/1_5_1_speedtraprace/startgrid_reverse", "11" },
                { "race_bin_01/1_5_1_speedtraprace/finishline_reverse", "12" },
                { "race_bin_01/1_5_1_speedtraprace/shortcut1", "13" },
                { "race_bin_01/1_5_1_speedtraprace/shortcut2", "14" },
                { "race_bin_01/1_5_1_speedtraprace/shortcut3", "15" },
                { "race_bin_01/1_5_1_speedtraprace/shortcut4", "16" },
                { "race_bin_01/1_5_1_speedtraprace/shortcut5", "17" },
                { "race_bin_01/1_5_1_speedtraprace/shortcut6", "18" }
            };

            return list;

        case 161:
            list.reserve(20);
            list =
            {
                { "race_bin_01/1_5_3_speedtrap/wrongway", "9" },
                { "race_bin_01/1_5_3_speedtrap/startgrid_reverse", "10" },
                { "race_bin_01/1_5_3_speedtrap/finishline_reverse", "11" },
                { "race_bin_01/1_5_3_speedtrap/shortcut1", "12" },
                { "race_bin_01/1_5_3_speedtrap/shortcut2", "13" },
                { "race_bin_01/1_5_3_speedtrap/shortcut3", "14" },
                { "race_bin_01/1_5_3_speedtrap/shortcut4", "15" },
                { "race_bin_01/1_5_3_speedtrap/shortcut5", "16" },
                { "race_bin_01/1_5_3_speedtrap/shortcut6", "17" },
                { "race_bin_01/1_5_3_speedtrap/shortcut7", "18" },
                { "race_bin_01/1_5_3_speedtrap/shortcut8", "19" },
                { "race_bin_01/1_5_3_speedtrap/shortcut9", "20" },
                { "race_bin_01/1_5_3_speedtrap/shortcut10", "21" },
                { "race_bin_01/1_5_3_speedtrap/shortcut11", "22" },
                { "race_bin_01/1_5_3_speedtrap/shortcut12", "23" },
                { "race_bin_01/1_5_3_speedtrap/shortcut13", "24" },
                { "race_bin_01/1_5_3_speedtrap/shortcut14", "25" },
                { "race_bin_01/1_5_3_speedtrap/shortcut15", "26" },
                { "race_bin_01/1_5_3_speedtrap/shortcut16", "27" },
                { "race_bin_01/1_5_3_speedtrap/shortcut17", "28" }
            };

            return list;

        case 164:
            list = { { "race_bin_01/1_5_2_speedtraprace/wrongway", "9" } };

            return list;


        /**                                 Track Expansion races                                  */

        //Taz track expansion speedtrap race
        case 181:
            list = { { "race_bin_14/14_5_101_speedtrap/wrongway", "10" } };

            return list;

        //Izzy track expansion speedtrap race
        case 188:
            list.reserve(3);
            list =
            {
                { "race_bin_12/12_5_101_speedtrap/shortcut1", "6" },
                { "race_bin_12/12_5_101_speedtrap/shortcut2", "7" },
                { "race_bin_12/12_5_101_speedtrap/shortcut3", "8" }
            };

            return list;

        //The Baron and Kaze track expansion speedtrap races
        case 203: case 228:
            list = { { "", "14" } };

            return list;

        //Ronnie track expansion speedtrap race
        case 263:
            list = { { "", "13" } };

            return list;

        //Bull, Big Lou and Ming track expansion speedtrap races
        default:
            list = { { "", "9" } };

            return list;
    }
}

std::vector<std::array<std::string, 4>> getSpeedtrapCoordinatesForSprints(int raceInteger)
{
    std::vector<std::array<std::string, 4>> coordinates;

    switch(raceInteger)
    {
        /**                                     Vanilla races                                           */

        //Sonny sprint
        case 2:
            coordinates.reserve(4);
            coordinates =
            {
                std::array<std::string, 4> { "1032.5", "2133.5", "153", "20" },
                std::array<std::string, 4> { "-143.5", "2862", "199", "25" },
                std::array<std::string, 4> { "-152.5", "3642", "223.5", "25" },
                std::array<std::string, 4> { "467", "3349.5", "195.5", "15" }
            };

            return coordinates;

        //Taz sprints
        case 7:
            coordinates.reserve(5);
            coordinates =
            {
                std::array<std::string, 4> { "370.5", "2974", "183", "15" },
                std::array<std::string, 4> { "336", "4132.5", "194", "20" },
                std::array<std::string, 4> { "685.5", "3297.5", "201", "30" },
                std::array<std::string, 4> { "1972.5", "3563.5", "160.5", "30" },
                std::array<std::string, 4> { "2192", "2553", "133", "15" }
            };

            return coordinates;

        case 8:
            coordinates.reserve(5);
            coordinates =
            {
                std::array<std::string, 4> { "1160.925", "3048.544", "199.8564", "15" },
                std::array<std::string, 4> { "1513.042", "2528.768", "153.832", "20" },
                std::array<std::string, 4> { "1309.661", "2143.88", "147.9023", "20" },
                std::array<std::string, 4> { "809.5", "2746.5", "150.5", "15" },
                std::array<std::string, 4> { "565.3503", "2315.002", "159.4199", "20" }
            };

            return coordinates;

        case 12:
            coordinates.reserve(4);
            coordinates =
            {
                std::array<std::string, 4> { "612.5", "2805", "169.5", "15" },
                std::array<std::string, 4> { "1468", "2302.5", "143.5", "20" },
                std::array<std::string, 4> { "2287.5", "2664.5", "133", "30" },
                std::array<std::string, 4> { "2612", "4230", "259", "35" }
            };

            return coordinates;

        case 13:
            coordinates.reserve(4);
            coordinates =
            {
                std::array<std::string, 4> { "567", "3209", "202", "15" },
                std::array<std::string, 4> { "-224.5", "3494.5", "216", "15" },
                std::array<std::string, 4> { "393.5", "2430.5", "165", "20" },
                std::array<std::string, 4> { "1592", "2273.5", "145", "15" }
            };

            return coordinates;

        //Vic sprints
        case 14:
            coordinates.reserve(6);
            coordinates =
            {
                std::array<std::string, 4> { "588", "3292.5", "200", "20" },
                std::array<std::string, 4> { "356.6913", "3047.893", "189", "15" },
                std::array<std::string, 4> { "595.3471", "2424.04", "164", "15" },
                std::array<std::string, 4> { "1323", "2286", "146.5", "25" },
                std::array<std::string, 4> { "1892", "1910", "150", "20" },
                std::array<std::string, 4> { "1761.553", "1241.2", "141", "20" }
            };

            return coordinates;

        case 21:
            coordinates.reserve(6);
            coordinates =
            {
                std::array<std::string, 4> { "1130", "2425", "154", "15" },
                std::array<std::string, 4> { "395.5", "3212.5", "188.5", "15" },
                std::array<std::string, 4> { "1284", "3651", "199.5", "20" },
                std::array<std::string, 4> { "2087.5", "3236.5", "147.5", "15" },
                std::array<std::string, 4> { "2550.194", "1967.421", "106.4493", "15" },
                std::array<std::string, 4> { "2035", "1158", "151.5", "20" }
            };

            return coordinates;

        case 22:
            coordinates.reserve(4);
            coordinates =
            {
                std::array<std::string, 4> { "664.5", "2389", "158", "15" },
                std::array<std::string, 4> { "982.5", "2585", "153.5", "15" },
                std::array<std::string, 4> { "1704", "2346", "150.5", "15" },
                std::array<std::string, 4> { "1200.5", "2777", "175", "15" }
            };

            return coordinates;

        //Izzy sprints
        case 28:
            coordinates.reserve(4);
            coordinates =
            {
                std::array<std::string, 4> { "1483.5", "2162", "144.5", "15" },
                std::array<std::string, 4> { "591", "2290.5", "159", "20" },
                std::array<std::string, 4> { "357", "3047", "189.5", "15" },
                std::array<std::string, 4> { "336", "4132.5", "194", "25" }
            };

            return coordinates;

        case 29:
            coordinates.reserve(5);
            coordinates =
            {
                std::array<std::string, 4> { "134.5", "2051.5", "219", "20" },
                std::array<std::string, 4> { "1524", "1700.5", "170.5", "30" },
                std::array<std::string, 4> { "2121.5", "2704", "124.5", "30" },
                std::array<std::string, 4> { "1610", "3809", "184.5", "15" },
                std::array<std::string, 4> { "692.5", "4000.5", "214", "20" }
            };

            return coordinates;

        case 30:
            coordinates.reserve(4);
            coordinates =
            {
                std::array<std::string, 4> { "4261", "508", "52.5", "15" },
                std::array<std::string, 4> { "4500", "1234.5", "24.5", "20" },
                std::array<std::string, 4> { "4085", "2302", "33", "20" },
                std::array<std::string, 4> { "4168.5", "3301", "15.5", "20" }
            };

            return coordinates;

        //Big Lou sprints
        case 32:
            coordinates.reserve(5);
            coordinates =
            {
                std::array<std::string, 4> { "4385.5", "46", "9", "20" },
                std::array<std::string, 4> { "4337", "597.399", "51", "15" },
                std::array<std::string, 4> { "3711.414", "1046", "54.26367", "20" },
                std::array<std::string, 4> { "3124.5", "1252", "77", "25" },
                std::array<std::string, 4> { "2915", "1999", "114", "30" }
            };

            return coordinates;

        case 37:
            coordinates.reserve(6);
            coordinates =
            {
                std::array<std::string, 4> { "4192", "3208", "17.5", "25" },
                std::array<std::string, 4> { "4085", "2302", "33", "20" },
                std::array<std::string, 4> { "4382.5", "1436", "14", "15" },
                std::array<std::string, 4> { "4795.5", "995.5", "12.5", "20" },
                std::array<std::string, 4> { "4423", "593.5", "52.5", "20" },
                std::array<std::string, 4> { "3843.5", "508", "24", "25" }
            };

            return coordinates;

        //Baron sprints
        case 46:
            coordinates.reserve(6);
            coordinates =
            {
                std::array<std::string, 4> { "3176.5", "1743", "102.5", "20" },
                std::array<std::string, 4> { "3098", "1073", "66", "25" },
                std::array<std::string, 4> { "3710.265", "1046.2", "54.29004", "20" },
                std::array<std::string, 4> { "4132.485", "705.2825", "56.5", "15" },
                std::array<std::string, 4> { "4690.651", "261.7112", "9.004883", "20" },
                std::array<std::string, 4> { "4143.658", "-150.2335", "16.45215", "25" }
            };

            return coordinates;

        case 47:
            coordinates.reserve(7);
            coordinates =
            {
                std::array<std::string, 4> { "2546.5", "1086.5", "90.5", "20" },
                std::array<std::string, 4> { "3707.5", "1047.5", "55.5", "25" },
                std::array<std::string, 4> { "4443", "602.5", "54.5", "20" },
                std::array<std::string, 4> { "4501", "1217", "23.5", "25" },
                std::array<std::string, 4> { "3935.5", "2226", "40.5", "25" },
                std::array<std::string, 4> { "3679", "2833.5", "10.5", "15" },
                std::array<std::string, 4> { "2805", "2992.5", "64", "25" }
            };

            return coordinates;

        case 50:
            coordinates.reserve(6);
            coordinates =
            {
                std::array<std::string, 4> { "683.5", "4020", "212.5", "20" },
                std::array<std::string, 4> { "1149.5", "3070", "199.5", "15" },
                std::array<std::string, 4> { "1792.5", "2415", "151.5", "20" },
                std::array<std::string, 4> { "2110.5", "1486", "151.5", "15" },
                std::array<std::string, 4> { "2832", "669.5", "46", "20" },
                std::array<std::string, 4> { "3283.5", "-211", "15.5", "30" }
            };

            return coordinates;

        //Earl sprint
        case 61:
            coordinates.reserve(8);
            coordinates =
            {
                std::array<std::string, 4> { "3649.5", "3576", "35.5", "20" },
                std::array<std::string, 4> { "3107", "2595", "41", "25" },
                std::array<std::string, 4> { "3997.227", "2148.108", "25.69825", "20" },
                std::array<std::string, 4> { "3934.583", "1330.231", "54", "20" },
                std::array<std::string, 4> { "3850.916", "892.6737", "42.5", "20" },
                std::array<std::string, 4> { "4312.198", "357.556", "38", "20" },
                std::array<std::string, 4> { "4402.343", "1019.323", "64", "20" },
                std::array<std::string, 4> { "4793.972", "774.312", "13", "20" }
            };

            return coordinates;

        //Jewels sprints
        case 66:
            coordinates.reserve(7);
            coordinates =
            {
                std::array<std::string, 4> { "921.3778", "2191.046", "154.5059", "20" },
                std::array<std::string, 4> { "1698.595", "1829.437", "168.3076", "30" },
                std::array<std::string, 4> { "995.6763", "1721.156", "153.3623", "30" },
                std::array<std::string, 4> { "-417.6116", "2402.144", "243.8887", "30" },
                std::array<std::string, 4> { "-100.0152", "3657.865", "226.5215", "25" },
                std::array<std::string, 4> { "491.0581", "3342.904", "194.8252", "15" },
                std::array<std::string, 4> { "1137", "3092", "199", "20" }
            };

            return coordinates;

        case 69:
            coordinates.reserve(7);
            coordinates =
            {
                std::array<std::string, 4> { "2922.5", "607", "38", "25" },
                std::array<std::string, 4> { "1642", "-83.5", "101", "20" },
                std::array<std::string, 4> { "1802", "576", "93.5", "20" },
                std::array<std::string, 4> { "2066", "1523.5", "150.5", "25" },
                std::array<std::string, 4> { "2127", "2198.5", "164.5", "30" },
                std::array<std::string, 4> { "2446.5", "3432.5", "201", "35" },
                std::array<std::string, 4> { "2008", "4379.5", "244", "35" }
            };

            return coordinates;

        //Kaze sprints
        case 71:
            coordinates.reserve(5);
            coordinates =
            {
                std::array<std::string, 4> { "2361", "3324.5", "206.5", "25" },
                std::array<std::string, 4> { "1849.5", "1951.5", "149.5", "20" },
                std::array<std::string, 4> { "2005.249", "1057.231", "139.9834", "20" },
                std::array<std::string, 4> { "1801.98", "576.4349", "93.01855", "20" },
                std::array<std::string, 4> { "2020", "-138.5", "107.5", "20" }
            };

            return coordinates;

        case 77:
            coordinates.reserve(9);
            coordinates =
            {
                std::array<std::string, 4> { "1094.084", "4436.212", "215.5", "30" },
                std::array<std::string, 4> { "2542.5", "4526", "262.5", "35" },
                std::array<std::string, 4> { "2434.295", "3422.83", "200", "35" },
                std::array<std::string, 4> { "2126.33", "2197.729", "164.2608", "30" },
                std::array<std::string, 4> { "2080.125", "1218.93", "151.1944", "25" },
                std::array<std::string, 4> { "1559.921", "516.071", "86.68262", "20" },
                std::array<std::string, 4> { "1004.636", "190.2112", "100.7393", "20" },
                std::array<std::string, 4> { "1758.688", "-32.39207", "105.5", "20" },
                std::array<std::string, 4> { "2756", "606", "46.5", "25" }
            };

            return coordinates;

        case 81:
            coordinates.reserve(5);
            coordinates =
            {
                std::array<std::string, 4> { "2445.5", "2524", "123", "20" },
                std::array<std::string, 4> { "2500", "1108", "99.5", "25" },
                std::array<std::string, 4> { "2521", "230", "91", "20" },
                std::array<std::string, 4> { "1536", "-95.5", "98.5", "20" },
                std::array<std::string, 4> { "1388", "367.5", "104", "25" }
            };

            return coordinates;

        case 82:
            coordinates.reserve(7);
            coordinates =
            {
                std::array<std::string, 4> { "1242.524", "2137.573", "149.8017", "20" },
                std::array<std::string, 4> { "1980.578", "1741.158", "150.501", "15" },
                std::array<std::string, 4> { "2678.63", "790.3736", "69.21777", "25" },
                std::array<std::string, 4> { "3436", "-333", "15.5", "30" },
                std::array<std::string, 4> { "4325.552", "16.81068", "9.846677", "25" },
                std::array<std::string, 4> { "4819.451", "809.3515", "15.5", "20" },
                std::array<std::string, 4> { "3869", "1105.5", "66.5", "15" }
            };

            return  coordinates;

        //Ming sprints
        case 83:
            coordinates.reserve(4);
            coordinates =
            {
                std::array<std::string, 4> { "1192.523", "-773.6458", "124.0781", "20" },
                std::array<std::string, 4> { "1779.915", "-24.77111", "104.5", "20" },
                std::array<std::string, 4> { "1761.318", "377.5", "92.89063", "20" },
                std::array<std::string, 4> { "1638.656", "712.4404", "121.8071", "25" }
            };

            return coordinates;

        case 86:
            coordinates.reserve(4);
            coordinates =
            {
                std::array<std::string, 4> { "1657.5", "822.5", "124", "30" },
                std::array<std::string, 4> { "1561", "-688.5", "116", "30" },
                std::array<std::string, 4> { "407.5", "-515.5", "133.5", "30" },
                std::array<std::string, 4> { "957", "418.5", "110.5", "20" }
            };

            return coordinates;

        case 90:
            coordinates.reserve(6);
            coordinates =
            {
                std::array<std::string, 4> { "2119", "-89.5", "105", "20" },
                std::array<std::string, 4> { "1802", "576.5", "93", "20" },
                std::array<std::string, 4> { "2005.249", "1057.231", "139.9834", "20" },
                std::array<std::string, 4> { "1980.5", "1725", "150", "20" },
                std::array<std::string, 4> { "2355.5", "3082", "182.5", "35" },
                std::array<std::string, 4> { "2252.5", "4516", "247.5", "35" }
            };

            return coordinates;

        //Webster sprints
        case 98:
            coordinates.reserve(10);
            coordinates =
            {
                std::array<std::string, 4> { "986", "1732.5", "153.5", "25" },
                std::array<std::string, 4> { "-361", "2356.5", "241.5", "20" },
                std::array<std::string, 4> { "-138.5", "3646.5, 223", "20" },
                std::array<std::string, 4> { "633", "4146", "199", "20" },
                std::array<std::string, 4> { "2018.5", "3549.5", "159.5", "20" },
                std::array<std::string, 4> { "1760.5", "2039.5", "148", "35" },
                std::array<std::string, 4> { "1362", "2822", "171.5", "20" },
                std::array<std::string, 4> { "726", "3255.5", "199", "20" },
                std::array<std::string, 4> { "339", "3092.5", "188.5", "20" },
                std::array<std::string, 4> { "546", "2647.5", "166", "20" }
            };

            return coordinates;

        case 103:
            coordinates.reserve(4);
            coordinates =
            {
                std::array<std::string, 4> { "2476.5", "1114.5", "102.5", "20" },
                std::array<std::string, 4> { "3283.5", "-211", "15.5", "30" },
                std::array<std::string, 4> { "4207.5", "79.5", "13.5", "20" },
                std::array<std::string, 4> { "3454.844", "1244.703", "80.45313", "20" }
            };

            return coordinates;

        case 106:
            coordinates.reserve(5);
            coordinates =
            {
                std::array<std::string, 4> { "4338.974", "160.613", "19.49707", "15" },
                std::array<std::string, 4> { "3283.5", "-211", "15.5", "30" },
                std::array<std::string, 4> { "2726.5", "704.5", "55.5", "15" },
                std::array<std::string, 4> { "2082", "1718.5", "162.5", "15" },
                std::array<std::string, 4> { "1509.5", "2534.5", "155", "15" }
            };

            return coordinates;

        case 108:
            coordinates.reserve(7);
            coordinates =
            {
                std::array<std::string, 4> { "610.6276", "2727.391", "170.9599", "15" },
                std::array<std::string, 4> { "891.5", "3174.5", "204.5", "25" },
                std::array<std::string, 4> { "1564.5", "2242", "145.5", "20" },
                std::array<std::string, 4> { "2078.5", "3283", "154", "15" },
                std::array<std::string, 4> { "629", "4150.5", "198.5", "25" },
                std::array<std::string, 4> { "-356.5", "2973.5", "190", "30" },
                std::array<std::string, 4> { "994.8439", "1723.021", "153.8359", "25" }
            };

            return coordinates;

        //JV sprint
        case 115:
            coordinates.reserve(9);
            coordinates =
            {
                std::array<std::string, 4> { "976.1771", "413.8442", "108.8809", "20" },
                std::array<std::string, 4> { "1584", "184", "94", "25" },
                std::array<std::string, 4> { "1088.5", "161", "99.5", "20" },
                std::array<std::string, 4> { "1721.5", "-152", "96.5", "25" },
                std::array<std::string, 4> { "2576.919", "-338.6137", "115.9219", "30" },
                std::array<std::string, 4> { "2709.72", "598.3825", "52.58887", "25" },
                std::array<std::string, 4> { "2500.232", "1108.753", "98.46289", "20" },
                std::array<std::string, 4> { "2520.698", "1763.646", "112.0498", "30" },
                std::array<std::string, 4> { "2145.47", "2215.343", "160.5527", "30" }
            };

            return coordinates;

        //Ronnie sprints
        case 123:
            coordinates.reserve(6);
            coordinates =
            {
                std::array<std::string, 4> { "3163", "3129", "40", "15" },
                std::array<std::string, 4> { "2990", "2480", "43.5", "25" },
                std::array<std::string, 4> { "2527", "1754.5", "114", "30" },
                std::array<std::string, 4> { "2132", "796.5", "131", "15" },
                std::array<std::string, 4> { "1032.5", "126.5", "101.5", "20" },
                std::array<std::string, 4> { "2448", "261.5", "91", "20" }
            };

            return coordinates;

        case 127:
            coordinates.reserve(5);
            coordinates =
            {
                std::array<std::string, 4> { "2128.5", "307", "99", "20" },
                std::array<std::string, 4> { "2005", "1057", "140.5", "20" },
                std::array<std::string, 4> { "1881", "1920.5", "150.5", "20" },
                std::array<std::string, 4> { "2355.5", "3082", "182.5", "35" },
                std::array<std::string, 4> { "2623.5", "4393.5", "275", "35" }
            };

            return coordinates;

        case 133:
            coordinates.reserve(6);
            coordinates =
            {
                std::array<std::string, 4> { "3182", "1812.5", "102", "20" },
                std::array<std::string, 4> { "4538.5", "1123", "15", "20" },
                std::array<std::string, 4> { "4248.5", "1034.5", "63.5", "20" },
                std::array<std::string, 4> { "4327", "54", "10", "20" },
                std::array<std::string, 4> { "3054", "-24.5", "18", "30" },
                std::array<std::string, 4> { "2559", "-6", "112.5", "30" }
            };

            return coordinates;

        case 136:
            coordinates.reserve(5);
            coordinates =
            {
                std::array<std::string, 4> { "4045.412", "921.2703", "58.39453", "15" },
                std::array<std::string, 4> { "4643", "1122.5", "11.5", "20" },
                std::array<std::string, 4> { "3723", "1300", "72", "20" },
                std::array<std::string, 4> { "2293.575", "1300.333", "146.0538", "20" },
                std::array<std::string, 4> { "2128.5", "307", "99", "20" }
            };

            return coordinates;

        //Bull sprints
        case 144:
            coordinates.reserve(7);
            coordinates =
            {
                std::array<std::string, 4> { "2673.5", "469.5", "70", "20" },
                std::array<std::string, 4> { "1529.5", "-96", "98", "20" },
                std::array<std::string, 4> { "1801.94", "596.3895", "94.05957", "20" },
                std::array<std::string, 4> { "2534.5", "1698", "122", "30" },
                std::array<std::string, 4> { "3120.5", "2600", "41", "25" },
                std::array<std::string, 4> { "2957.5", "2996", "59", "15" },
                std::array<std::string, 4> { "3331", "3618", "40", "15" }
            };

            return coordinates;

        case 151:
            coordinates.reserve(7);
            coordinates =
            {
                std::array<std::string, 4> { "2805", "2313", "93", "25" },
                std::array<std::string, 4> { "2914.5", "3027", "63.5", "15" },
                std::array<std::string, 4> { "3630.5", "2938.5", "11", "15" },
                std::array<std::string, 4> { "3925", "2220", "39", "25" },
                std::array<std::string, 4> { "4312", "1333", "31.5", "25" },
                std::array<std::string, 4> { "3450", "1238", "80", "20" },
                std::array<std::string, 4> { "4118.835", "724.795", "54.61914", "15" }
            };

            return coordinates;

        case 152:
            coordinates.reserve(10);
            coordinates =
            {
                std::array<std::string, 4> { "1636", "999.5", "122.5", "25" },
                std::array<std::string, 4> { "1749.5", "2050.5", "147", "30" },
                std::array<std::string, 4> { "921.5", "2191", "155", "20" },
                std::array<std::string, 4> { "220", "2836.5", "180.5", "15" },
                std::array<std::string, 4> { "247.5", "3621", "188.5", "15" },
                std::array<std::string, 4> { "1134.5", "4423.5", "219", "30" },
                std::array<std::string, 4> { "2255.5", "4522", "248.5", "35" },
                std::array<std::string, 4> { "2553.5", "3815.5", "233", "35" },
                std::array<std::string, 4> { "2438", "2528.5", "122.5", "20" },
                std::array<std::string, 4> { "3001.855", "1924.179", "107.1719", "25" }
            };

            return coordinates;

        //Razor sprints
        case 154:
            coordinates.reserve(9);
            coordinates =
            {
                std::array<std::string, 4> { "967", "548", "115.5", "20" },
                std::array<std::string, 4> { "1454.829", "1348.722", "125.8047", "20" },
                std::array<std::string, 4> { "1980.506", "1724.759", "150.2153", "20" },
                std::array<std::string, 4> { "2043.5", "2885.5", "142", "30" },
                std::array<std::string, 4> { "1466.443", "3742.286", "190", "20" },
                std::array<std::string, 4> { "698", "3988.483", "214", "20" },
                std::array<std::string, 4> { "341.5", "3085.5", "188", "20" },
                std::array<std::string, 4> { "-342", "3938", "236", "25" },
                std::array<std::string, 4> { "468.6606", "4527.372", "231", "25" }
            };

            return coordinates;

        case 155:
            coordinates.reserve(10);
            coordinates =
            {
                std::array<std::string, 4> { "4054.582", "2925", "30.08105", "20" },
                std::array<std::string, 4> { "3558", "2053.5", "68", "20" },
                std::array<std::string, 4> { "3643.443", "1306.033", "81.2998", "20" },
                std::array<std::string, 4> { "4229.982", "1262.5", "47", "20" },
                std::array<std::string, 4> { "4700.5", "545", "9.671875", "20" },
                std::array<std::string, 4> { "4329", "23", "9", "20" },
                std::array<std::string, 4> { "3713.5", "-320.5", "21", "20" },
                std::array<std::string, 4> { "3106.605", "-32", "13.61719", "25" },
                std::array<std::string, 4> { "2640", "759", "63", "25" },
                std::array<std::string, 4> { "2302", "1297.5", "146", "20" }
            };

            return coordinates;

        case 156:
            coordinates.reserve(4);
            coordinates =
            {
                std::array<std::string, 4> { "2564", "308", "86.5", "20" },
                std::array<std::string, 4> { "1227.5", "784.5", "116", "25" },
                std::array<std::string, 4> { "337.2456", "-46.02396", "115.9004", "25" },
                std::array<std::string, 4> { "1209.5", "-784", "125.5", "15" }
            };

            return coordinates;

        case 162:
            coordinates.reserve(11);
            coordinates =
            {
                std::array<std::string, 4> { "2915", "1999", "113.5", "30" },
                std::array<std::string, 4> { "2445", "2524", "122", "20" },
                std::array<std::string, 4> { "2553.405", "3815.501", "233", "35" },
                std::array<std::string, 4> { "2552.619", "4515.849", "262.5", "35" },
                std::array<std::string, 4> { "1106.951", "4431.651", "215", "30" },
                std::array<std::string, 4> { "161.5", "3839", "189", "20" },
                std::array<std::string, 4> { "220", "2836.5", "180", "15" },
                std::array<std::string, 4> { "527.1174", "2340.25", "161.623", "20" },
                std::array<std::string, 4> { "1771.045", "2027.657", "149", "30" },
                std::array<std::string, 4> { "1637.671", "1000.336", "122.5", "30" },
                std::array<std::string, 4> { "2314.857", "932.5", "133", "20" }
            };

            return coordinates;

        case 166:
            coordinates.reserve(7);
            coordinates =
            {
                std::array<std::string, 4> { "2644", "341.5", "85.5", "25" },
                std::array<std::string, 4> { "3283.5", "-211", "15.5", "30" },
                std::array<std::string, 4> { "4342.5", "179", "22", "20" },
                std::array<std::string, 4> { "4061.5", "937", "60", "15" },
                std::array<std::string, 4> { "4636.5", "1123", "12", "20" },
                std::array<std::string, 4> { "3574", "1316.5", "80.5", "25" },
                std::array<std::string, 4> { "2633", "2236", "108", "25" }
            };

            return coordinates;

        case 168:
            coordinates.reserve(7);
            coordinates =
            {
                std::array<std::string, 4> { "588.5", "4548.5", "223.5", "20" },
                std::array<std::string, 4> { "-26", "3667.5", "222", "15" },
                std::array<std::string, 4> { "588", "3292.5", "199.5", "15" },
                std::array<std::string, 4> { "1433", "2497.5", "157.5", "15" },
                std::array<std::string, 4> { "1989", "2045.5", "144", "20" },
                std::array<std::string, 4> { "2808.5", "973.5", "79", "20" },
                std::array<std::string, 4> { "4132.5", "1024.5", "66", "15" }
            };

            return coordinates;

        //Prologue sprints
        case 170:
            coordinates.reserve(3);
            coordinates =
            {
                std::array<std::string, 4> { "1803", "618.5", "96", "15" },
                std::array<std::string, 4> { "2139", "1294.5", "149", "20" },
                std::array<std::string, 4> { "2713.5", "886", "83.5", "20" }
            };

            return coordinates;

        case 171:
            coordinates.reserve(3);
            coordinates =
            {
                std::array<std::string, 4> { "2327.5", "929.5", "134", "20" },
                std::array<std::string, 4> { "1658", "26.5", "99", "20" },
                std::array<std::string, 4> { "1051", "445.5", "107", "25" }
            };

            return coordinates;

        //Collectors edition sprints
        case 173:
            coordinates.reserve(10);
            coordinates =
            {
                std::array<std::string, 4> { "2507.224", "3868.502", "232.2305", "30" },
                std::array<std::string, 4> { "2848.753", "2409.61", "76.70801", "20" },
                std::array<std::string, 4> { "3708.155", "3490.401", "25.28125", "15" },
                std::array<std::string, 4> { "4329", "1515.5", "21.5", "15" },
                std::array<std::string, 4> { "4342.854", "180.237", "21.33691", "15" },
                std::array<std::string, 4> { "2664", "353", "84", "15" },
                std::array<std::string, 4> { "361.916", "-468.2354", "126.165", "25" },
                std::array<std::string, 4> { "1460", "1193", "117", "20" },
                std::array<std::string, 4> { "-566.2511", "2677.333", "230.3691", "20" },
                std::array<std::string, 4> { "389.8765", "4514.552", "234.1826", "25" }
            };

            return coordinates;

        case 174:
            coordinates.reserve(4);
            coordinates =
            {
                std::array<std::string, 4> { "3402.981", "-179.9392", "12.4834", "15" },
                std::array<std::string, 4> { "3363.5", "790", "19.5", "15" },
                std::array<std::string, 4> { "3923", "957.5", "58", "15" },
                std::array<std::string, 4> { "2952.474", "1035.983", "67.19727", "20" }
            };

            return coordinates;


        /**                                 Track Expansion races                                  */

        //Sonny sprint
        case 176:
            coordinates.reserve(4);
            coordinates =
            {
                 std::array<std::string, 4> { "1225.19", "3359.63", "204.5", "20" },
                 std::array<std::string, 4> { "754.24", "3476.9", "199.5", "20" },
                 std::array<std::string, 4> { "259.12", "3278.5", "189", "15" },
                 std::array<std::string, 4> { "484.67", "4188.59", "196.5", "15" }
            };

            return coordinates;

        //Taz sprint
        case 179:
            coordinates.reserve(5);
            coordinates =
            {
                 std::array<std::string, 4> { "521.63", "2517.27", "169.5", "15" },
                 std::array<std::string, 4> { "1216.33", "2133.1", "151.5", "15" },
                 std::array<std::string, 4> { "1606.68", "2288.94", "146.5", "15" },
                 std::array<std::string, 4> { "1164.42", "3041.6", "200.5", "15" },
                 std::array<std::string, 4> { "693.32", "3991.51", "213.5", "15" }
            };

            return coordinates;

        //Vic sprint
        case 184:
            coordinates.reserve(5);
            coordinates =
            {
                 std::array<std::string, 4> { "1648.6", "2334.9", "150.5", "15" },
                 std::array<std::string, 4> { "948.7", "2177.05", "154.5", "15" },
                 std::array<std::string, 4> { "787.88", "2778.35", "151.5", "15" },
                 std::array<std::string, 4> { "1432.65", "2424.7", "150.5", "15" },
                 std::array<std::string, 4> { "1154.9", "3059.25", "199.5", "15" }
            };

            return coordinates;

        //Izzy sprint
        case 191:
            coordinates.reserve(6);
            coordinates =
            {
                 std::array<std::string, 4> { "4584.9", "943.12", "40", "15" },
                 std::array<std::string, 4> { "4711.6", "530.9", "10.5", "15" },
                 std::array<std::string, 4> { "4518.85", "86.58", "4.5", "15" },
                 std::array<std::string, 4> { "3693.45", "-326.5", "22.5", "20" },
                 std::array<std::string, 4> { "3085.12", "285.16", "12.75", "20" },
                 std::array<std::string, 4> { "2701.33", "835.93", "73.5", "15" }
            };

            return coordinates;

        //Big Lou sprint
        case 194:
            coordinates.reserve(5);
            coordinates =
            {
                 std::array<std::string, 4> { "1154.9", "3059.25", "199.5", "15" },
                 std::array<std::string, 4> { "1432.65", "2424.7", "150.5", "15" },
                 std::array<std::string, 4> { "787.88", "2778.35", "151.5", "15" },
                 std::array<std::string, 4> { "948.7", "2177.05", "154.5", "20" },
                 std::array<std::string, 4> { "1648.6", "2334.9", "150.5", "15" }
            };

            return coordinates;

        //Baron sprint
        case 205:
            coordinates.reserve(3);
            coordinates =
            {
                 std::array<std::string, 4> { "1321.13", "1410.66", "127", "25" },
                 std::array<std::string, 4> { "1591.32", "2511.14", "151.1", "15" },
                 std::array<std::string, 4> { "1165.4", "3039.5", "200", "15" }
            };

            return coordinates;

        //Earl sprints
        case 207:
            coordinates.reserve(4);
            coordinates =
            {
                 std::array<std::string, 4> { "1133.44", "2404.74", "154.7", "15" },
                 std::array<std::string, 4> { "1577.26", "2028.65", "144.5", "15" },
                 std::array<std::string, 4> { "1626.28", "2311.15", "149", "15" },
                 std::array<std::string, 4> { "1162.16", "3045.25", "200", "15" }
            };

            return coordinates;

        case 212:
            coordinates.reserve(6);
            coordinates =
            {
                 std::array<std::string, 4> { "2081.88", "3348.87", "156", "15" },
                 std::array<std::string, 4> { "1651.72", "3920.77", "176.75", "15" },
                 std::array<std::string, 4> { "617.2", "3312.7", "199.5", "15" },
                 std::array<std::string, 4> { "-32.6", "3666.77", "223.5", "15" },
                 std::array<std::string, 4> { "206.77", "2837.3", "180.5", "15" },
                 std::array<std::string, 4> { "1135.58", "2244.77", "154.5", "20" }
            };

            return coordinates;

        //Jewels sprint
        case 216:
            coordinates.reserve(5);
            coordinates =
            {
                 std::array<std::string, 4> { "1126.32", "2441.7", "154.7", "15" },
                 std::array<std::string, 4> { "911.04", "2196.57", "154.5", "15" },
                 std::array<std::string, 4> { "1867.55", "1934.95", "149.75", "15" },
                 std::array<std::string, 4> { "1442.35", "2667.6", "162.5", "15" },
                 std::array<std::string, 4> { "1239.14", "3404.37", "205.5", "20" }
            };

            return coordinates;

        //Kaze sprint
        case 224:
            coordinates.reserve(4);
            coordinates =
            {
                 std::array<std::string, 4> { "1162.16", "3045.25", "200", "15" },
                 std::array<std::string, 4> { "1626.28", "2311.15", "149", "15" },
                 std::array<std::string, 4> { "1577.26", "2028.65", "144.5", "15" },
                 std::array<std::string, 4> { "1133.44", "2404.74", "154.7", "15" }
            };

            return coordinates;

        //Ming sprint
        case 233:
            coordinates.reserve(5);
            coordinates =
            {
                 std::array<std::string, 4> { "911.04", "2196.57", "154.5", "15" },
                 std::array<std::string, 4> { "1049.78", "2360.32", "154", "15" },
                 std::array<std::string, 4> { "171.84", "2831.56", "181.5", "15" },
                 std::array<std::string, 4> { "146.6", "3861.12", "189", "15" },
                 std::array<std::string, 4> { "496", "4532.9", "231.5", "35" }
            };

            return coordinates;

        //Webster sprints
        case 243:
            coordinates.reserve(5);
            coordinates =
            {
                 std::array<std::string, 4> { "3064.83", "2581.08", "41.5", "25" },
                 std::array<std::string, 4> { "2480.84", "2510.35", "122.5", "15" },
                 std::array<std::string, 4> { "2077.23", "3307.9", "155.2", "15" },
                 std::array<std::string, 4> { "1150.8", "3067.72", "199.5", "15" },
                 std::array<std::string, 4> { "1216.33", "2133.1", "151.5", "15" }
            };

            return coordinates;

        case 244:
            coordinates.reserve(5);
            coordinates =
            {
                 std::array<std::string, 4> { "1139.9", "2245.65", "154.5", "20" },
                 std::array<std::string, 4> { "364.32", "2470.35", "166.5", "15" },
                 std::array<std::string, 4> { "-59.2", "3664.57", "225.55", "15" },
                 std::array<std::string, 4> { "742.3", "3875.7", "207.5", "15" },
                 std::array<std::string, 4> { "2086.27", "3373.22", "156.5", "15" }
            };

            return coordinates;

        //JV sprints
        case 253:
            coordinates.reserve(5);
            coordinates =
            {
                 std::array<std::string, 4> { "1216.33", "2133.1", "151.5", "15" },
                 std::array<std::string, 4> { "1150.8", "3067.72", "199.5", "15" },
                 std::array<std::string, 4> { "2077.23", "3307.9", "155.2", "15" },
                 std::array<std::string, 4> { "2480.84", "2510.35", "122.5", "15" },
                 std::array<std::string, 4> { "3064.48", "2580.7", "41.5", "25" }
            };

            return coordinates;

        case 257:
            coordinates.reserve(3);
            coordinates =
            {
                 std::array<std::string, 4> { "1702.43", "2345.77", "150.2", "15" },
                 std::array<std::string, 4> { "1988.19", "-113.96", "102.2", "15" },
                 std::array<std::string, 4> { "1516.46", "-521.35", "86.5", "15" }
            };

            return coordinates;

        case 260:
            coordinates.reserve(8);
            coordinates =
            {
                 std::array<std::string, 4> { "774.62", "3215.03", "199.5", "15" },
                 std::array<std::string, 4> { "259.12", "3278.5", "189", "15" },
                 std::array<std::string, 4> { "-333.75", "3819.5", "226", "30" },
                 std::array<std::string, 4> { "629.02", "4553.28", "221.5", "35" },
                 std::array<std::string, 4> { "1650.8", "3922.15", "176.5", "15" },
                 std::array<std::string, 4> { "2139.97", "2690.25", "123", "30" },
                 std::array<std::string, 4> { "2534.48", "3500.52", "197.5", "35" },
                 std::array<std::string, 4> { "2255.29", "4520.42", "237.2275", "30" }
            };

            return coordinates;

        //Ronnie track expansion sprint
        case 267:
            coordinates.reserve(5);
            coordinates =
            {
                 std::array<std::string, 4> { "469.9", "4527.9", "231", "25" },
                 std::array<std::string, 4> { "24.36", "3678.24", "213.1", "15" },
                 std::array<std::string, 4> { "2091.32", "3401.53", "156.75", "15" },
                 std::array<std::string, 4> { "2087.22", "2735.58", "126.7", "30" },
                 std::array<std::string, 4> { "2118.26", "1272.1", "150.5", "20" }
            };

            return coordinates;

        //Bull track expansion sprint
        default:
            coordinates.reserve(7);
            coordinates =
            {
                 std::array<std::string, 4> { "719.8", "3451.38", "199.7", "15" },
                 std::array<std::string, 4> { "1165.4", "3039.5", "200", "15" },
                 std::array<std::string, 4> { "1129.87", "2424.8", "154.5", "15" },
                 std::array<std::string, 4> { "593.86", "2424.77", "164", "15" },
                 std::array<std::string, 4> { "1576.45", "2029.62", "144.7", "20" },
                 std::array<std::string, 4> { "2037.46", "1089.65", "147.7", "15" },
                 std::array<std::string, 4> { "1936.03", "362.3", "91", "15" }
            };

            return coordinates;
    }
}

std::vector<std::string> getListOfRaceSpeedtraps(int raceInteger)
{
    std::vector<std::string> speedtrapNames;

    switch(raceInteger)
    {
        /**                                     Vanilla races                                           */

        //Vic speedtrap races
        case 19:
            speedtrapNames.reserve(5);
            speedtrapNames =
            { "race_bin_13/13_5_1_speedtrap/speedtrap1", "race_bin_13/13_5_1_speedtrap/speedtrap2",
              "race_bin_13/13_5_1_speedtrap/speedtrap3", "race_bin_13/13_5_1_speedtrap/speedtrap4",
              "race_bin_13/13_5_1_speedtrap/speedtrap7" };

            return speedtrapNames;

        case 20:
            speedtrapNames.reserve(6);
            speedtrapNames =
            { "race_bin_13/13_5_2_speedtrap/speedtrap1", "race_bin_13/13_5_2_speedtrap/speedtrap2",
              "race_bin_13/13_5_2_speedtrap/speedtrap3", "race_bin_13/13_5_2_speedtrap/speedtrap4",
              "race_bin_13/13_5_2_speedtrap/speedtrap5", "race_bin_13/13_5_2_speedtrap/speedtrap6" };

            return speedtrapNames;

        //Izzy speedtrap race
        case 26:
            speedtrapNames.reserve(5);
            speedtrapNames =
            { "race_bin_12/12_5_1_speedtrap/speedtrap1", "race_bin_12/12_5_1_speedtrap/speedtrap2",
              "race_bin_12/12_5_1_speedtrap/speedtrap4", "race_bin_12/12_5_1_speedtrap/speedtrap5",
              "race_bin_12/12_5_1_speedtrap/speedtrap6" };

            return speedtrapNames;

        //Big Lou speedtrap races
        case 34:
            speedtrapNames.reserve(5);
            speedtrapNames =
            { "race_bin_11/11_5_1_speedtrap_race/speedtrap1", "race_bin_11/11_5_1_speedtrap_race/speedtrap2",
              "race_bin_11/11_5_1_speedtrap_race/speedtrap3", "race_bin_11/11_5_1_speedtrap_race/speedtrap4",
              "race_bin_11/11_5_1_speedtrap_race/speedtrap5" };

            return speedtrapNames;

        case 38:
            speedtrapNames.reserve(7);
            speedtrapNames =
            { "race_bin_11/11_5_2_speedtrap/speedtrap1", " race_bin_11/11_5_2_speedtrap/speedtrap2",
              "race_bin_11/11_5_2_speedtrap/speedtrap3", "race_bin_11/11_5_2_speedtrap/speedtrap4",
              "race_bin_11/11_5_2_speedtrap/speedtrap5", "race_bin_11/11_5_2_speedtrap/speedtrap6",
              "race_bin_11/11_5_2_speedtrap/speedtrap7" };

            return speedtrapNames;

        //Baron speedtrap races
        case 49:
            speedtrapNames.reserve(4);
            speedtrapNames =
            { "race_bin_10/11_5_1_r_speedtrap/speedtrap1", "race_bin_10/11_5_1_r_speedtrap/speedtrap3",
              "race_bin_10/11_5_1_r_speedtrap/speedtrap4", "race_bin_10/11_5_1_r_speedtrap/speedtrap5" };

            return speedtrapNames;

        //Earl speedtrap races
        case 55:
            speedtrapNames.reserve(6);
            speedtrapNames =
            { "race_bin_09/9_5_1_speedtrap/speedtrap1", "race_bin_09/9_5_1_speedtrap/speedtrap2",
              "race_bin_09/9_5_1_speedtrap/speedtrap4", "race_bin_09/9_5_1_speedtrap/speedtrap5",
              "race_bin_09/9_5_1_speedtrap/speedtrap6", "race_bin_09/9_5_1_speedtrap/speedtrap7" };

            return speedtrapNames;

        case 56:
            speedtrapNames.reserve(7);
            speedtrapNames =
            { "race_bin_09/9_5_2_speedtrap/speedtrap1", "race_bin_09/9_5_2_speedtrap/speedtrap2",
              "race_bin_09/9_5_2_speedtrap/speedtrap3", "race_bin_09/9_5_2_speedtrap/speedtrap4",
              "race_bin_09/9_5_2_speedtrap/speedtrap5", "race_bin_09/9_5_2_speedtrap/speedtrap6",
              "race_bin_09/9_5_2_speedtrap/speedtrap7" };

            return speedtrapNames;

        case 60:
            speedtrapNames.reserve(5);
            speedtrapNames =
            { "race_bin_09/9_5_3_speedtrap_race/speedtrap1", "race_bin_09/9_5_3_speedtrap_race/speedtrap2",
              "race_bin_09/9_5_3_speedtrap_race/speedtrap3", "race_bin_09/9_5_3_speedtrap_race/speedtrap4",
              "race_bin_09/9_5_3_speedtrap_race/speedtrap6" };

            return speedtrapNames;

        //Jewels speedtrap races
        case 64:
            speedtrapNames.reserve(4);
            speedtrapNames =
            { "race_bin_08/8_5_1_speedtrap/speedtrap1", "race_bin_08/8_5_1_speedtrap/speedtrap2",
              "race_bin_08/8_5_1_speedtrap/speedtrap3", "race_bin_08/8_5_1_speedtrap/speedtrap5" };

            return speedtrapNames;

        case 65:
            speedtrapNames.reserve(7);
            speedtrapNames =
            { "race_bin_08/8_5_2_speedtrap/speedtrap1", "race_bin_08/8_5_2_speedtrap/speedtrap2",
              "race_bin_08/8_5_2_speedtrap/speedtrap3", "race_bin_08/8_5_2_speedtrap/speedtrap4",
              "race_bin_08/8_5_2_speedtrap/speedtrap5", "race_bin_08/8_5_2_speedtrap/speedtrap6",
              "race_bin_08/8_5_2_speedtrap/speedtrap7" };

            return speedtrapNames;

        //Kaze speedtrap race
        case 73:
            speedtrapNames.reserve(6);
            speedtrapNames =
            { "race_bin_07/7_5_1_speedtrap/speedtrap2", "race_bin_07/7_5_1_speedtrap/speedtrap3",
              "race_bin_07/7_5_1_speedtrap/speedtrap4", "race_bin_07/7_5_1_speedtrap/speedtrap5",
              "race_bin_07/7_5_1_speedtrap/speedtrap6", "race_bin_07/7_5_1_speedtrap/speedtrap7" };

            return speedtrapNames;

        //Ming speedtrap races
        case 85:
            speedtrapNames.reserve(6);
            speedtrapNames =
            { "race_bin_06/6_5_1_speedtraprace/speedtrap1", "race_bin_06/6_5_1_speedtraprace/speedtrap2",
              "race_bin_06/6_5_1_speedtraprace/speedtrap3", "race_bin_06/6_5_1_speedtraprace/speedtrap4",
              "race_bin_06/6_5_1_speedtraprace/speedtrap5", "race_bin_06/6_5_1_speedtraprace/speedtrap6" };

            return speedtrapNames;

        case 91:
            speedtrapNames.reserve(6);
            speedtrapNames =
            { "race_bin_06/6_5_3_speedtrap/speedtrap1", "race_bin_06/6_5_3_speedtrap/speedtrap2",
              "race_bin_06/6_5_3_speedtrap/speedtrap3", "race_bin_06/6_5_3_speedtrap/speedtrap4",
              "race_bin_06/6_5_3_speedtrap/speedtrap5", "race_bin_06/6_5_3_speedtrap/speedtrap6" };

            return speedtrapNames;

        case 95:
            speedtrapNames.reserve(8);
            speedtrapNames =
            { "race_bin_06/6_5_2_speedtraprace/speedtrap1", "race_bin_06/6_5_2_speedtraprace/speedtrap2",
              "race_bin_06/6_5_2_speedtraprace/speedtrap3", "race_bin_06/6_5_2_speedtraprace/speedtrap4",
              "race_bin_06/6_5_2_speedtraprace/speedtrap5", "race_bin_06/6_5_2_speedtraprace/speedtrap7",
              "race_bin_06/6_5_2_speedtraprace/speedtrap8", "race_bin_06/6_5_2_speedtraprace/speedtrap6" };

            return speedtrapNames;

        //Webster speedtrap races
        case 99:
            speedtrapNames.reserve(6);
            speedtrapNames =
            { "race_bin_05/5_5_1_speedtrap/speedtrap1", "race_bin_05/5_5_1_speedtrap/speedtrap2",
              "race_bin_05/5_5_1_speedtrap/speedtrap3", "race_bin_05/5_5_1_speedtrap/speedtrap4",
              "race_bin_05/5_5_1_speedtrap/speedtrap5", "race_bin_05/5_5_1_speedtrap/speedtrap6" };

            return speedtrapNames;

        case 100:
            speedtrapNames.reserve(5);
            speedtrapNames =
            { "race_bin_05/5_5_2_speedtrap/speedtrap1", "race_bin_05/5_5_2_speedtrap/speedtrap2",
              "race_bin_05/5_5_2_speedtrap/speedtrap3", "race_bin_05/5_5_2_speedtrap/speedtrap4",
              "race_bin_05/5_5_2_speedtrap/speedtrap5" };

            return speedtrapNames;

        case 102:
            speedtrapNames.reserve(5);
            speedtrapNames =
            { "race_bin_05/5_5_3_speedtrap/speedtrap1", "race_bin_05/5_5_3_speedtrap/speedtrap2",
              "race_bin_05/5_5_3_speedtrap/speedtrap3", "race_bin_05/5_5_3_speedtrap/speedtrap4",
              "race_bin_05/5_5_3_speedtrap/speedtrap5" };

            return speedtrapNames;

        case 107:
            speedtrapNames.reserve(7);
            speedtrapNames =
            { "race_bin_05/5_5_4_speedtrap/speedtrap1", "race_bin_05/5_5_4_speedtrap/speedtrap2",
              "race_bin_05/5_5_4_speedtrap/speedtrap3", "race_bin_05/5_5_4_speedtrap/speedtrap4",
              "race_bin_05/5_5_4_speedtrap/speedtrap5", "race_bin_05/5_5_4_speedtrap/speedtrap6",
              "race_bin_05/5_5_4_speedtrap/speedtrap7" };

            return speedtrapNames;

        //JV speedtrap races
        case 112:
            speedtrapNames.reserve(6);
            speedtrapNames =
            { "race_bin_04/4_5_3_speedtrap/speedtrap1", "race_bin_04/4_5_3_speedtrap/speedtrap2",
              "race_bin_04/4_5_3_speedtrap/speedtrap3", "race_bin_04/4_5_3_speedtrap/speedtrap4",
              "race_bin_04/4_5_3_speedtrap/speedtrap5", "race_bin_04/4_5_3_speedtrap/speedtrap6" };

            return speedtrapNames;

        case 113:
            speedtrapNames.reserve(7);
            speedtrapNames =
            { "race_bin_04/4_5_1_speedtrap/speedtrap1", "race_bin_04/4_5_1_speedtrap/speedtrap2",
              "race_bin_04/4_5_1_speedtrap/speedtrap3", "race_bin_04/4_5_1_speedtrap/speedtrap4",
              "race_bin_04/4_5_1_speedtrap/speedtrap5", "race_bin_04/4_5_1_speedtrap/speedtrap6",
              "race_bin_04/4_5_1_speedtrap/speedtrap7" };

            return speedtrapNames;

        case 114:
            speedtrapNames.reserve(6);
            speedtrapNames =
            { "race_bin_04/5_5_2_r_speedtrap/speedtrap1", "race_bin_04/5_5_2_r_speedtrap/speedtrap2",
              "race_bin_04/5_5_2_r_speedtrap/speedtrap3", "race_bin_04/5_5_2_r_speedtrap/speedtrap4",
              "race_bin_04/5_5_2_r_speedtrap/speedtrap5", "race_bin_04/5_5_2_r_speedtrap/speedtrap6" };

            return speedtrapNames;

        case 120:
            speedtrapNames.reserve(6);
            speedtrapNames =
            { "race_bin_04/4_5_2_speedtrap/speedtrap6", "race_bin_04/4_5_2_speedtrap/speedtrap1",
              "race_bin_04/4_5_2_speedtrap/speedtrap2", "race_bin_04/4_5_2_speedtrap/speedtrap3",
              "race_bin_04/4_5_2_speedtrap/speedtrap4", "race_bin_04/4_5_2_speedtrap/speedtrap5" };

            return speedtrapNames;

        case 122:
            speedtrapNames.reserve(4);
            speedtrapNames =
            { "race_bin_04/4_5_1_r_speedtrap/speedtrap1", "race_bin_04/4_5_1_r_speedtrap/speedtrap2",
              "race_bin_04/4_5_1_r_speedtrap/speedtrap3", "race_bin_04/4_5_1_r_speedtrap/speedtrap4" };

            return speedtrapNames;

        //Ronnie speedtrap races
        case 129:
            speedtrapNames.reserve(10);
            speedtrapNames =
            { "race_bin_03/3_5_1_speedtrap/speedtrap1", "race_bin_03/3_5_1_speedtrap/speedtrap2",
              "race_bin_03/3_5_1_speedtrap/speedtrap3", "race_bin_03/3_5_1_speedtrap/speedtrap4",
              "race_bin_03/3_5_1_speedtrap/speedtrap5", "race_bin_03/3_5_1_speedtrap/speedtrap6",
              "race_bin_03/3_5_1_speedtrap/speedtrap7", "race_bin_03/3_5_1_speedtrap/speedtrap8",
              "race_bin_03/3_5_1_speedtrap/speedtrap9", "race_bin_03/3_5_1_speedtrap/speedtrap10" };

            return speedtrapNames;

        case 130:
            speedtrapNames.reserve(7);
            speedtrapNames =
            { "race_bin_03/3_5_2_speedtrap/speedtrap1", "race_bin_03/3_5_2_speedtrap/speedtrap2",
              "race_bin_03/3_5_2_speedtrap/speedtrap3", "race_bin_03/3_5_2_speedtrap/speedtrap4",
              "race_bin_03/3_5_2_speedtrap/speedtrap5", "race_bin_03/3_5_2_speedtrap/speedtrap6",
              "race_bin_03/3_5_2_speedtrap/speedtrap7" };

            return speedtrapNames;

        //Bull speedtrap races
        case 143:
            speedtrapNames.reserve(7);
            speedtrapNames =
            { "race_bin_02/2_5_1_speedtrap/speedtrap1", "race_bin_02/2_5_1_speedtrap/speedtrap2",
              "race_bin_02/2_5_1_speedtrap/speedtrap3", "race_bin_02/2_5_1_speedtrap/speedtrap4",
              "race_bin_02/2_5_1_speedtrap/speedtrap5", "race_bin_02/2_5_1_speedtrap/speedtrap6",
              "race_bin_02/2_5_1_speedtrap/speedtrap7" };

            return speedtrapNames;

        case 148:
            speedtrapNames.reserve(6);
            speedtrapNames =
            { "race_bin_02/5_5_1_r_speedtrap/speedtrap1", "race_bin_02/5_5_1_r_speedtrap/speedtrap2",
              "race_bin_02/5_5_1_r_speedtrap/speedtrap3", "race_bin_02/5_5_1_r_speedtrap/speedtrap4",
              "race_bin_02/5_5_1_r_speedtrap/speedtrap5", "race_bin_02/5_5_1_r_speedtrap/speedtrap6" };

            return speedtrapNames;

        //Razor speedtrap races
        case 160:
            speedtrapNames.reserve(7);
            speedtrapNames =
            { "race_bin_01/1_5_1_speedtraprace/speedtrap1", "race_bin_01/1_5_1_speedtraprace/speedtrap2",
              "race_bin_01/1_5_1_speedtraprace/speedtrap3", "race_bin_01/1_5_1_speedtraprace/speedtrap4",
              "race_bin_01/1_5_1_speedtraprace/speedtrap5", "race_bin_01/1_5_1_speedtraprace/speedtrap6",
              "race_bin_01/1_5_1_speedtraprace/speedtrap7" };

            return speedtrapNames;

        case 161:
            speedtrapNames.reserve(9);
            speedtrapNames =
            { "race_bin_01/1_5_3_speedtrap/speedtrap1", "race_bin_01/1_5_3_speedtrap/speedtrap2",
              "race_bin_01/1_5_3_speedtrap/speedtrap3", "race_bin_01/1_5_3_speedtrap/speedtrap4",
              "race_bin_01/1_5_3_speedtrap/speedtrap5", "race_bin_01/1_5_3_speedtrap/speedtrap6",
              "race_bin_01/1_5_3_speedtrap/speedtrap7", "race_bin_01/1_5_3_speedtrap/speedtrap8",
              "race_bin_01/1_5_3_speedtrap/speedtrap9" };

            return speedtrapNames;

        case 164:
            speedtrapNames.reserve(10);
            speedtrapNames =
            { "race_bin_01/1_5_2_speedtraprace/speedtrap1", "race_bin_01/1_5_2_speedtraprace/speedtrap2",
              "race_bin_01/1_5_2_speedtraprace/speedtrap3", "race_bin_01/1_5_2_speedtraprace/speedtrap4",
              "race_bin_01/1_5_2_speedtraprace/speedtrap5", "race_bin_01/1_5_2_speedtraprace/speedtrap6",
              "race_bin_01/1_5_2_speedtraprace/speedtrap7", "race_bin_01/1_5_2_speedtraprace/speedtrap8",
              "race_bin_01/1_5_2_speedtraprace/speedtrap9", "race_bin_01/1_5_2_speedtraprace/speedtrap10" };

            return speedtrapNames;


        /**                                 Track Expansion races                                  */

        //Taz track expansion speedtrap race
        case 181:
            speedtrapNames.reserve(4);
            speedtrapNames =
                    { "race_bin_14/14_5_101_speedtrap/speedtrap1", "race_bin_14/14_5_101_speedtrap/speedtrap2",
                      "race_bin_14/14_5_101_speedtrap/speedtrap3", "race_bin_14/14_5_101_speedtrap/speedtrap4" };

            return speedtrapNames;

        //Izzy track expansion speedtrap race
        case 188:
            speedtrapNames.reserve(5);
            speedtrapNames =
                    { "race_bin_12/12_5_101_speedtrap/speedtrap1", "race_bin_12/12_5_101_speedtrap/speedtrap2",
                      "race_bin_12/12_5_101_speedtrap/speedtrap3", "race_bin_12/12_5_101_speedtrap/speedtrap4",
                      "race_bin_12/12_5_101_speedtrap/speedtrap5" };

            return speedtrapNames;

        //Big Lou track expansion speedtrap race
        case 198:
            speedtrapNames.reserve(8);
            speedtrapNames =
                    { "race_bin_11/11_5_101_speedtrap/speedtrap1", "race_bin_11/11_5_101_speedtrap/speedtrap2",
                      "race_bin_11/11_5_101_speedtrap/speedtrap3", "race_bin_11/11_5_101_speedtrap/speedtrap4",
                      "race_bin_11/11_5_101_speedtrap/speedtrap5", "race_bin_11/11_5_101_speedtrap/speedtrap6",
                      "race_bin_11/11_5_101_speedtrap/speedtrap7", "race_bin_11/11_5_101_speedtrap/speedtrap8" };

            return speedtrapNames;

        //Baron track expansion speedtrap race
        case 203:
            speedtrapNames.reserve(7);
            speedtrapNames =
                    { "race_bin_10/10_5_101_speedtrap/speedtrap1", "race_bin_10/10_5_101_speedtrap/speedtrap2",
                      "race_bin_10/10_5_101_speedtrap/speedtrap3", "race_bin_10/10_5_101_speedtrap/speedtrap4",
                      "race_bin_10/10_5_101_speedtrap/speedtrap5", "race_bin_10/10_5_101_speedtrap/speedtrap6",
                      "race_bin_10/10_5_101_speedtrap/speedtrap7" };

            return speedtrapNames;

        //Kaze track expansion speedtrap race
        case 228:
            speedtrapNames.reserve(8);
            speedtrapNames =
                    { "race_bin_07/7_5_101_speedtrap/speedtrap1", "race_bin_07/7_5_101_speedtrap/speedtrap2",
                      "race_bin_07/7_5_101_speedtrap/speedtrap3", "race_bin_07/7_5_101_speedtrap/speedtrap4",
                      "race_bin_07/7_5_101_speedtrap/speedtrap5", "race_bin_07/7_5_101_speedtrap/speedtrap6",
                      "race_bin_07/7_5_101_speedtrap/speedtrap7", "race_bin_07/7_5_101_speedtrap/speedtrap8" };

            return speedtrapNames;

        //Ming track expansion speedtrap race
        case 232:
            speedtrapNames.reserve(7);
            speedtrapNames =
                    { "race_bin_06/6_5_101_speedtrap/speedtrap1", "race_bin_06/6_5_101_speedtrap/speedtrap2",
                      "race_bin_06/6_5_101_speedtrap/speedtrap3", "race_bin_06/6_5_101_speedtrap/speedtrap4",
                      "race_bin_06/6_5_101_speedtrap/speedtrap5", "race_bin_06/6_5_101_speedtrap/speedtrap6",
                      "race_bin_06/6_5_101_speedtrap/speedtrap7" };

            return speedtrapNames;

        //Ronnie track expansion speedtrap race
        case 263:
            speedtrapNames.reserve(8);
            speedtrapNames =
                    { "race_bin_03/3_5_101_speedtrap/speedtrap1", "race_bin_03/3_5_101_speedtrap/speedtrap2",
                      "race_bin_03/3_5_101_speedtrap/speedtrap3", "race_bin_03/3_5_101_speedtrap/speedtrap4",
                      "race_bin_03/3_5_101_speedtrap/speedtrap5", "race_bin_03/3_5_101_speedtrap/speedtrap6",
                      "race_bin_03/3_5_101_speedtrap/speedtrap7", "race_bin_03/3_5_101_speedtrap/speedtrap8" };

            return speedtrapNames;

        //Bull track expansion speedtrap race
        default:
            speedtrapNames.reserve(8);
            speedtrapNames =
                    { "race_bin_02/2_5_101_speedtrap/speedtrap1", "race_bin_02/2_5_101_speedtrap/speedtrap2",
                      "race_bin_02/2_5_101_speedtrap/speedtrap3", "race_bin_02/2_5_101_speedtrap/speedtrap4",
                      "race_bin_02/2_5_101_speedtrap/speedtrap5", "race_bin_02/2_5_101_speedtrap/speedtrap6",
                      "race_bin_02/2_5_101_speedtrap/speedtrap7", "race_bin_02/2_5_101_speedtrap/speedtrap8" };

            return speedtrapNames;
    }
}

std::vector<std::array<float, 4>> getFreeRoamZoneCoordinates()
{
    std::vector<std::array<float, 4>> zoneCoordinates;
    zoneCoordinates.reserve(15);

    zoneCoordinates =
     {
         //Car lot coordinates
         std::array<float, 4> { 981.6318, 2147.321, 152.2939, 4 },
         std::array<float, 4> { 4204.79, 1257.427, 46.18896, 4 },
         std::array<float, 4> { 1750.89, 512.1406, 90.85645, 4 },

         //Customization shop coordinates
         std::array<float, 4> { 698.1821, 4523.472, 214.6646, 6 },
         std::array<float, 4> { 1509.355, 2563.893, 157.6162, 7 },
         std::array<float, 4> { 1850.652, 1211.021, 143.5498, 6 },
         std::array<float, 4> { 3595.972, 3627.557, 30.47705, 7 },
         std::array<float, 4> { 3497.088, 2011.371, 73.98682, 7 },
         std::array<float, 4> { 4246.829, 719.4024, 54.27002, 7 },
         std::array<float, 4> { 3398.796, -231.7847, 12.44727, 7 },
         std::array<float, 4> { 1064.187, 51.79076, 99.67774, 5 },

         //Safehouse coordinates
         std::array<float, 4> { 1777.095, 2503.468, 147.7935, 7 },
         std::array<float, 4> { 4257.524, 78.69839, 9.291016, 7 },
         std::array<float, 4> { 3627.767, 3340.5, 6.772949, 7 },
         std::array<float, 4> { 2328.785, -66.36417, 90.9668, 7 }
     };

    return zoneCoordinates;
}

std::vector<std::array<float, 4>> getFreeRoamZoneRespawnCoordinates()
{
    std::vector<std::array<float, 4>> respawnCoordinates;
    respawnCoordinates.reserve(15);

    respawnCoordinates =
    {
        //Car lot coordinates
        std::array<float, 4> { 986.6693, 2149.918, 152.3054, -27.31243 },
        std::array<float, 4> { 4206.655, 1269.722, 45.99024, -25.45867 },
        std::array<float, 4> { 1749.084, 517.2923, 90.7334, 170.7765 },

        //Customization shop coordinates
        std::array<float, 4> { 716.1008, 4523.805, 212.8496, 82.59451 },
        std::array<float, 4> { 1497.653, 2571.383, 158.8467, -141.6609 },
        std::array<float, 4> { 1842.902, 1215.779, 143.1494, -127.0229 },
        std::array<float, 4> { 3591.582, 3636.861, 30.63086, 34.06722 },
        std::array<float, 4> { 3508.649, 2016.714, 72.72363, 108.2595 },
        std::array<float, 4> { 4256.169, 718.0107, 54.12597, -95.68618 },
        std::array<float, 4> { 3398.938, -223.0549, 12.44238, 4.07827 },
        std::array<float, 4> { 1069.119, 42.14526, 99.5957, 34.98735 },

        //Safehouse coordinates
        std::array<float, 4> { 1762.762, 2508.818, 147.2841, -115.4158 },
        std::array<float, 4> { 4245.938, 79.00754, 9.711914, -107.1375 },
        std::array<float, 4> { 3623.124, 3355.153, 7.018555, -27.47683 },
        std::array<float, 4> { 2329.8, -82.48916, 90.88281, 169.4336 }
    };

    return respawnCoordinates;
}

std::vector<std::string> getListOfFreeRoamZones()
{
    std::vector<std::string> zones;
    zones.reserve(15);

    zones = { "menu_gate_carlot/zone_carlot_1", "menu_gate_carlot/zone_carlot_2", "menu_gate_carlot/zone_carlot_3",
        "menu_gate_customshop/zone_customshop_1", "menu_gate_customshop/zone_customshop_2",
        "menu_gate_customshop/zone_customshop_3", "menu_gate_customshop/zone_customshop_4",
        "menu_gate_customshop/zone_customshop_5", "menu_gate_customshop/zone_customshop_6",
        "menu_gate_customshop/zone_customshop_7", "menu_gate_customshop/zone_customshop_8",
        "menu_gate_safehouse/zone_safehouse_1", "menu_gate_safehouse/zone_safehouse_2",
        "menu_gate_safehouse/zone_safehouse_4", "menu_gate_safehouse/zone_safehouse_5" };

    return zones;
}

std::array<std::string, 41> getListOfRegularOpponents()
{
    return std::array<std::string, 41> { "16_1_1_circuit/opponent2", "16_1_1_circuit/opponent3",
        "race_bin_01/character1", "race_bin_01/character2", "race_bin_01/character3", "race_bin_02/character1",
        "race_bin_02/character2", "race_bin_02/character3", "race_bin_03/character1", "race_bin_03/character2",
        "race_bin_03/character3", "race_bin_04/character1", "race_bin_04/character2", "race_bin_04/character3",
        "race_bin_05/character1", "race_bin_05/character2", "race_bin_05/character3", "race_bin_06/character1",
        "race_bin_06/character2", "race_bin_06/character3", "race_bin_07/character1", "race_bin_07/character2",
        "race_bin_07/character3", "race_bin_08/character1", "race_bin_08/character2", "race_bin_08/character3",
        "race_bin_09/character1", "race_bin_09/character2", "race_bin_09/character3", "race_bin_10/character1",
        "race_bin_10/character2", "race_bin_10/character3", "race_bin_11/character1", "race_bin_11/character2",
        "race_bin_11/character3", "race_bin_12/character1", "race_bin_12/character2", "race_bin_12/character3",
        "race_bin_13/character1", "race_bin_13/character2", "race_bin_13/character3" };
}

std::array<std::string, 18> getListOfScriptedOpponents()
{
    return std::array<std::string, 18> { "16_2_2_sprint/ronnie_mccrae", "16_2_3_sprint/toru_sato",
        "16_1_1_circuit/opponent", "race_bin_15/tony_ho", "race_bin_14/vince_kilic", "race_bin_13/victor_vasquez",
        "race_bin_12/isabel_diaz", "race_bin_11/lou_park", "race_bin_10/karl_smit", "race_bin_09/pierre_dupont",
        "race_bin_08/jade_barrett", "race_bin_07/kira_nazakato", "race_bin_06/hector_domingo",
        "race_bin_05/wes_allen", "race_bin_04/joe_vega", "race_bin_03/ronnie_mccrea", "race_bin_02/toro_sato",
        "race_bin_01/razor_callahan" };
}

std::array<std::string, 6> getListOfStartingOpponents()
{
    return std::array<std::string, 6> { "race_bin_14/character1", "race_bin_14/character2", "race_bin_14/character3",
        "race_bin_15/opponent1", "race_bin_15/opponent2", "race_bin_15/opponent3" };
}

std::array<std::string, 73> getListOfPresetCars()
{
    return std::array<std::string, 73> { "M3GTRCAREERSTART", "RAZORMUSTANG", "DDAYSUPRA", "OPM_MUSTANG_BOSS",
        "OPM_MUSTANG_VERSION2", "GT_ELISE_ROG", "OPM_WRX_VERSION2", "OPM_RX8_Version3", "OPM_RX8_VERSION2",
        "STARKY_HUTCH_EVO_ROG", "BL15", "BL14", "BL13", "BL12", "BL11", "BL10", "BL9", "BL8", "BL7", "BL6", "BL5",
        "BL4","BL3", "BL2", "E3_DEMO_BMW", "E3_DEMO_RX8", "CASTROLGT", "BONUS_C6R", "BONUS_GT2", "BONUS_SL65",
        "CE_997S", "CE_C6R", "CE_CAMARO", "CE_CORVETTE", "CE_ELISE", "CE_GT2", "CE_GTRSTREET", "CE_SL500", "CE_SL65",
        "CE_SUPRA", "CS_CAR_01", "CS_CAR_02", "CS_CAR_03", "CS_CAR_04", "CS_CAR_05", "CS_CAR_06", "CS_CAR_07",
        "CS_CAR_08", "CS_CAR_09", "CS_CAR_10", "CS_CAR_11", "CS_CAR_12", "CS_CAR_13", "CS_CAR_14", "CS_CAR_15",
        "CS_CAR_16", "CS_CAR_17", "CS_CAR_18", "CS_CAR_19", "CS_CAR_20", "CS_CAR_22", "CS_CAR_24", "CS_CAR_COPGTO",
        "CS_CAR_HENCH", "CS_CAR_26", "CS_CAR_27", "CS_CAR_28", "CS_CAR_29", "CS_CAR_30", "CS_CAR_31", "CS_CAR_32",
        "CS_CAR_33", "CS_CAR_34" };
}

std::array<std::string, 69> getListOfEngineSounds()
{
    return std::array<std::string, 69> { "ac_integ", "am_db9", "aud_s4", "bmw_m3_a", "bmw_m3_c", "bmw_m3_e", "bmw_m5_a",
        "chv_cav_a", "chv_cav_b", "corvette_z06", "corvette_z06_v2", "dodg_viper_a", "dodg_viper_b", "fer_360",
        "for_foc_a", "for_foc_b", "for_mus_a", "for_mus_b", "for_mus_c", "for_mus_gt_a", "for_mus_gt_a_tranny",
        "hon_prel", "hon_s2k_a", "hon_s2k_b", "hon_s2k_c", "hon_s2k_d", "hon_s2k_e", "hum_h1", "inf_g35",
        "lam_diablo", "lam_gallardo", "lam_murc", "lot_elise", "maz_miat", "maz_prot_a", "maz_prot_b", "maz_rx7",
        "maz_rx8", "mbz_cl500", "mbz_cl55", "mbz_sl65", "mbz_slr", "mit_eclip_a", "mit_eclip_b", "nis_240sx",
        "nis_300zx", "nis_350z_a", "nis_350z_b", "nis_sky", "por_911_a", "por_911_b", "por_928", "por_996",
        "por_car_gt", "por_dp6", "por_gt4r", "sub_wrx_a", "sub_wrx_b", "sub_wrx_c", "toy_gts", "toy_gts_low_rpm",
        "trck_log", "tvr_cerb", "tvr_tuscan", "vw_cab", "vw_gti", "vw_jet_m3", "vw_jet_m4", "vw_scir" };
}

std::array<std::string, 46> getListOfCars()
{
    return std::array<std::string, 46> { "911turbo", "911gt2", "997s", "a3", "a4", "bmwm3gtr", "bmwm3gtre46",
        "m3gtre46careerstart", "carreragt", "caymans", "clio", "clk500", "cobaltss", "corvette",
        "cs_c6_copsporthench", "cts", "db9", "eclipsegt", "elise", "fordgt", "gallardo", "gti", "gto",
        "cs_gto_copgto", "imprezawrx", "is300", "lancerevo8", "monaro", "murcielago", "mustanggt",
        "cs_mustang_copsuv", "punto", "rx7", "rx8", "sl500", "sl65", "slr", "supra", "viper", "cs_semi",
        "cs_clio_trafpizza", "cs_clio_traftaxi", "cs_cts_traf_minivan", "cs_cts_traffictruck", "cs_trafcement",
        "cs_trafgarb" };
}

std::array<std::string, 12> getListOfFMVs()
{
    /** Returns a new-style array with the names of the FMVs in the MOVIES folder.
      * To be used with randomizePrologueRaces to randomize intro and outro movies.     */

    return std::array<std::string, 12> { "attract_movie", "ealogo", "psa", "storyfmv_bla134", "storyfmv_bus12",
        "storyfmv_cro06_coh06a", "storyfmv_her136", "storyfmv_pin11", "storyfmv_rac01", "storyfmv_rap30",
        "storyfmv_raz08", "storyfmv_saf25" };
}

std::array<std::string, 43> getListOfMilestoneSpawnPoints()
{
    return std::array<std::string, 43> { "milestones/default_spawn_point", "milestones/bin_15/taggedcarmarker1",
        "milestones/bin_12/taggedcarmarker1", "milestones/bin_08/taggedcarmarker1",
        "speedtraps/bin_15/taggedcarmarker1", "speedtraps/bin_14/taggedcarmarker1",
        "speedtraps/bin_14/taggedcarmarker2", "speedtraps/bin_13/taggedcarmarker1",
        "speedtraps/bin_13/taggedcarmarker2", "speedtraps/bin_12/taggedcarmarker1",
        "speedtraps/bin_12/taggedcarmarker2", "speedtraps/bin_11/taggedcarmarker1",
        "speedtraps/bin_11/taggedcarmarker2", "speedtraps/bin_10/taggedcarmarker1",
        "speedtraps/bin_10/taggedcarmarker2", "speedtraps/bin_10/taggedcarmarker3",
        "speedtraps/bin_09/taggedcarmarker1", "speedtraps/bin_09/taggedcarmarker2",
        "speedtraps/bin_09/taggedcarmarker3", "speedtraps/bin_08/taggedcarmarker1",
        "speedtraps/bin_08/taggedcarmarker2", "speedtraps/bin_08/taggedcarmarker3",
        "speedtraps/bin_07/taggedcarmarker1", "speedtraps/bin_07/taggedcarmarker2",
        "speedtraps/bin_07/taggedcarmarker3", "speedtraps/bin_06/taggedcarmarker1",
        "speedtraps/bin_06/taggedcarmarker2", "speedtraps/bin_06/taggedcarmarker3",
        "speedtraps/bin_05/taggedcarmarker1", "speedtraps/bin_05/taggedcarmarker2",
        "speedtraps/bin_05/taggedcarmarker3", "speedtraps/bin_04/taggedcarmarker1",
        "speedtraps/bin_04/taggedcarmarker2", "speedtraps/bin_04/taggedcarmarker3",
        "speedtraps/bin_03/taggedcarmarker1", "speedtraps/bin_03/taggedcarmarker2",
        "speedtraps/bin_03/taggedcarmarker3", "speedtraps/bin_02/taggedcarmarker1",
        "speedtraps/bin_02/taggedcarmarker2", "speedtraps/bin_02/taggedcarmarker3",
        "speedtraps/bin_01/taggedcarmarker1", "speedtraps/bin_01/taggedcarmarker2",
        "speedtraps/bin_01/taggedcarmarker3" };
}
