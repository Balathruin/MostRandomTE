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
    int* originalNumberOfBullRacesPtr, int* originalNumberOfRazorRacesPtr)
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

    //Section for Sonny tracks
    promptedForRaces =
    {
        std::make_pair("race_bin_15/15_1_101_circuit", false),
        std::make_pair("race_bin_15/15_2_101_sprint", false),
        std::make_pair("race_bin_15/15_3_101_knockout", false)
    };

    newAdditions = promptUser(promptedForRaces, "Add Sonny tracks? Y/N\n >> ", originalNumberOfSonnyRacesPtr);

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
            coordinates.reserve(10);
            coordinates =
            {
                std::array<std::string, 4> { "918.9474", "2192.522", "154.6827", "15" },
                std::array<std::string, 4> { "647.2923", "2267.94", "155.2334", "15" },
                std::array<std::string, 4> { "339.7794", "2509.759", "165.8652", "15" },
                std::array<std::string, 4> { "75.01915", "2813.721", "181.9326", "15" },
                std::array<std::string, 4> { "-257.5334", "3106.408", "186.1562", "30" },
                std::array<std::string, 4> { "-148.6559", "3643.847", "224.625", "20" },
                std::array<std::string, 4> { "237.4056", "3646.836", "188.6806", "15" },
                std::array<std::string, 4> { "386.9245", "3208.586", "188.7832", "15" },
                std::array<std::string, 4> { "633.6992", "3420.494", "199.3398", "20" },
                std::array<std::string, 4> { "727.4005", "3903.406", "210.5361", "20" }
            };

            return coordinates;

        //Taz sprints
        case 7:
            coordinates.reserve(11);
            coordinates =
            {
                std::array<std::string, 4> { "-227.2868", "2900.204", "193.4189", "20" },
                std::array<std::string, 4> { "371.6307", "2973.813", "182.6944", "15" },
                std::array<std::string, 4> { "260.6436", "3275.008", "188.7246", "15" },
                std::array<std::string, 4> { "636.1453", "4127.933", "201.7725", "20" },
                std::array<std::string, 4> { "693.0433", "3663.954", "207.6631", "20" },
                std::array<std::string, 4> { "730.2437", "3245.798", "199.502", "20" },
                std::array<std::string, 4> { "1141.478", "3247.251", "199.9218", "35" },
                std::array<std::string, 4> { "1301.541", "3659.868", "199.5752", "15" },
                std::array<std::string, 4> { "1972.719", "3563.479", "159.5918", "25" },
                std::array<std::string, 4> { "2119.642", "3031.964", "134.7988", "15" },
                std::array<std::string, 4> { "2171.775", "2353.044", "147.1025", "25" }
            };

            return coordinates;

        case 8:
            coordinates.reserve(9);
            coordinates =
            {
                std::array<std::string, 4> { "1243.259", "3512.799", "201.5566", "20" },
                std::array<std::string, 4> { "1160.925", "3048.544", "199.8564", "15" },
                std::array<std::string, 4> { "1513.042", "2528.768", "153.832", "15" },
                std::array<std::string, 4> { "1636.158", "2322.748", "149.877", "15" },
                std::array<std::string, 4> { "1309.661", "2143.88", "147.9023", "20" },
                std::array<std::string, 4> { "1135.069", "2394.461", "154.6777", "15" },
                std::array<std::string, 4> { "610.7286", "2750.194", "170.0684", "15" },
                std::array<std::string, 4> { "520.1992", "2520.386", "169.7187", "20" },
                std::array<std::string, 4> { "565.3503", "2315.002", "159.4199", "15" }
            };

            return coordinates;

        case 12:
            coordinates.reserve(9);
            coordinates =
            {
                std::array<std::string, 4> { "-134.1395", "2859.386", "197.3935", "20" },
                std::array<std::string, 4> { "732.2509", "2805.393", "153.0117", "15" },
                std::array<std::string, 4> { "887.9932", "2409.629", "151.537", "15" },
                std::array<std::string, 4> { "1468.987", "2303.455", "141.991", "20" },
                std::array<std::string, 4> { "1669.888", "2132.089", "139.4316", "25" },
                std::array<std::string, 4> { "2170.72", "2264.667", "153.7481", "25" },
                std::array<std::string, 4> { "2386.846", "2883.917", "143.6162", "25" },
                std::array<std::string, 4> { "2521.552", "3490.231", "187.9471", "30" },
                std::array<std::string, 4> { "2582.09", "4180.105", "251.1943", "30" }
            };

            return coordinates;

        case 13:
            coordinates.reserve(10);
            coordinates =
            {
                std::array<std::string, 4> { "729.682", "3710.044", "199.8594", "20" },
                std::array<std::string, 4> { "594.937", "3298.873", "199.7178", "15" },
                std::array<std::string, 4> { "259.2776", "3277.874", "188.7344", "15" },
                std::array<std::string, 4> { "110.8528", "3714.579", "195.8662", "15" },
                std::array<std::string, 4> { "-213.2061", "3369.544", "212.0331", "20" },
                std::array<std::string, 4> { "-226.8266", "2899.885", "193.4658", "20" },
                std::array<std::string, 4> { "393.464", "2430.737", "164.8359", "15" },
                std::array<std::string, 4> { "912.355", "2195.72", "155.1026", "15" },
                std::array<std::string, 4> { "1245.154", "2138.188", "149.7275", "15" },
                std::array<std::string, 4> { "1815.492", "2277.494", "145.0928", "15" }
            };

            return coordinates;

        //Vic sprints
        case 14:
            coordinates.reserve(10);
            coordinates =
            {
                std::array<std::string, 4> { "670.6066", "3610.698", "200.5244", "20" },
                std::array<std::string, 4> { "588.9578", "3293.153", "200.3203", "15" },
                std::array<std::string, 4> { "356.6913", "3047.893", "189.2695", "15" },
                std::array<std::string, 4> { "491.2178", "2809.916", "178.9034", "15" },
                std::array<std::string, 4> { "519.4848", "2521.248", "166.1739", "25" },
                std::array<std::string, 4> { "595.3471", "2424.04", "162.1279", "15" },
                std::array<std::string, 4> { "1892.167", "1910.006", "150.1299", "15" },
                std::array<std::string, 4> { "2084.131", "1227.667", "150.959", "20" },
                std::array<std::string, 4> { "1761.553", "1241.2", "140.3389", "20" },
                std::array<std::string, 4> { "1313.944", "1428.054", "127.0585", "20" }
            };

            return coordinates;

        case 21:
            coordinates.reserve(12);
            coordinates =
            {
                std::array<std::string, 4> { "1766.766", "2033.14", "148.9873", "25" },
                std::array<std::string, 4> { "1315.61", "2144.044", "147.045", "15" },
                std::array<std::string, 4> { "1129.863", "2425.04", "153.3515", "15" },
                std::array<std::string, 4> { "370.1951", "2986.205", "183.9229", "15" },
                std::array<std::string, 4> { "395.6783", "3212.337", "182.9941", "15" },
                std::array<std::string, 4> { "685.743", "3413.195", "202.0458", "20" },
                std::array<std::string, 4> { "1283.806", "3653.809", "198.2168", "20" },
                std::array<std::string, 4> { "2089.124", "3236.629", "145.1064", "20" },
                std::array<std::string, 4> { "2395.52", "2545.369", "122.1416", "15" },
                std::array<std::string, 4> { "2550.194", "1967.421", "106.4493", "15" },
                std::array<std::string, 4> { "2129.077", "1284.677", "149.5302", "20" },
                std::array<std::string, 4> { "1679.455", "1262.416", "137.7186", "15" }
            };

            return coordinates;

        case 22:
            coordinates.reserve(9);
            coordinates =
            {
                std::array<std::string, 4> { "557.4293", "2325.034", "160.0234", "20" },
                std::array<std::string, 4> { "497.1766", "2565.516", "169.6855", "30" },
                std::array<std::string, 4> { "611.4219", "2726.615", "171.6465", "20" },
                std::array<std::string, 4> { "862.5847", "2662.773", "151.7773", "20" },
                std::array<std::string, 4> { "1240.85", "2139.153", "149.8428", "20" },
                std::array<std::string, 4> { "1473.83", "2153.437", "144.2432", "20" },
                std::array<std::string, 4> { "1613.03", "2512.587", "151.0811", "20" },
                std::array<std::string, 4> { "1200.404", "2972.296", "192.6377", "20" },
                std::array<std::string, 4> { "1217.595", "3340.844", "204.0488", "20" }
            };

            return coordinates;

        //Izzy sprints
        case 28:
            coordinates.reserve(9);
            coordinates =
            {
                std::array<std::string, 4> { "1206.542", "2959.256", "195.792", "20" },
                std::array<std::string, 4> { "1432.493", "2357.719", "144.1231", "20" },
                std::array<std::string, 4> { "1473.398", "2148.207", "144.333", "20" },
                std::array<std::string, 4> { "931.4027", "2186.257", "154.3701", "20" },
                std::array<std::string, 4> { "390.8716", "2434.537", "165.1864", "20" },
                std::array<std::string, 4> { "159.3222", "2782.846", "181.0225", "20" },
                std::array<std::string, 4> { "284.4357", "2835.235", "179.6562", "20" },
                std::array<std::string, 4> { "355.9077", "3046.74", "189.6738", "20" },
                std::array<std::string, 4> { "233.7324", "3337.005", "188.7295", "20" }
            };

            return coordinates;

        case 29:
            coordinates.reserve(9);
            coordinates =
            {
                std::array<std::string, 4> { "-462.4389", "2857.449", "202.4853", "30" },
                std::array<std::string, 4> { "134.4955", "2050.079", "227.6347", "20" },
                std::array<std::string, 4> { "1524.221", "1696.495", "166.4942", "20" },
                std::array<std::string, 4> { "1874.274", "2080.781", "156.8798", "20" },
                std::array<std::string, 4> { "2125.426", "2704.232", "121.5264", "20" },
                std::array<std::string, 4> { "1610.244", "3818.848", "183.3486", "20" },
                std::array<std::string, 4> { "1160.069", "3696.237", "200.2568", "20" },
                std::array<std::string, 4> { "683.7432", "4000.387", "209.0527", "20" },
                std::array<std::string, 4> { "691.3384", "4274.299", "206.838", "20" }
            };

            return coordinates;

        case 30:
            coordinates.reserve(10);
            coordinates =
            {
                std::array<std::string, 4> { "3876.244", "707.8425", "22.84278", "20" },
                std::array<std::string, 4> { "3971.848", "434.7128", "33.24316", "20" },
                std::array<std::string, 4> { "4440.777", "599.2013", "53.2041", "25" },
                std::array<std::string, 4> { "4483.741", "832.8619", "58.94629", "20" },
                std::array<std::string, 4> { "4743.761", "826.8389", "19.14355", "30" },
                std::array<std::string, 4> { "4635.085", "1124.795", "10.43555", "20" },
                std::array<std::string, 4> { "4384.807", "1434.583", "14.12109", "20" },
                std::array<std::string, 4> { "4033.54", "2241.259", "32.75391", "20" },
                std::array<std::string, 4> { "4068.643", "2853.294", "24.36426", "20" },
                std::array<std::string, 4> { "3891.955", "3387.954", "13.12207", "25" }
            };

            return coordinates;

        //Big Lou sprints
        case 32:
            coordinates.reserve(9);
            coordinates =
            {
                std::array<std::string, 4> { "4103.956", "-170.5849", "16.46582", "20" },
                std::array<std::string, 4> { "4385.472", "50.77212", "9.012695", "15" },
                std::array<std::string, 4> { "4680.667", "268.7491", "10.444336", "20" },
                std::array<std::string, 4> { "4336.232", "597.399", "50.02832", "15" },
                std::array<std::string, 4> { "4132.485", "705.2825", "55.45996", "20" },
                std::array<std::string, 4> { "4135.575", "1002.327", "65.59666", "20" },
                std::array<std::string, 4> { "3711.414", "1048.957", "54.26367", "15" },
                std::array<std::string, 4> { "3094.094", "1073.008", "65.92188", "25" },
                std::array<std::string, 4> { "3027.14", "1923.864", "103.3711", "30" }
            };

            return coordinates;

        case 37:
            coordinates.reserve(10);
            coordinates =
            {
                std::array<std::string, 4> { "3336.415", "3615.32", "41.18751", "30" },
                std::array<std::string, 4> { "4065.412", "2847.523", "23.88477", "30" },
                std::array<std::string, 4> { "4085.03", "2290.792", "32.87696", "25" },
                std::array<std::string, 4> { "4382.644", "1429.824", "14.10937", "20" },
                std::array<std::string, 4> { "4800.435", "995.467", "12.49121", "20" },
                std::array<std::string, 4> { "4706.543", "798.1749", "26.4668", "30" },
                std::array<std::string, 4> { "4485.155", "965.7788", "58.58398", "20" },
                std::array<std::string, 4> { "4438.696", "597.8345", "53.47559", "20" },
                std::array<std::string, 4> { "3966.656", "430.8192", "31.2041", "20" },
                std::array<std::string, 4> { "3875.864", "718.8088", "21.09863", "20" }
            };

            return coordinates;

        //Baron sprints
        case 46:
            coordinates.reserve(9);
            coordinates =
            {
                std::array<std::string, 4> { "3021.856", "1915.133", "103.4297", "20" },
                std::array<std::string, 4> { "3091.069", "1073.008", "65.93067", "20" },
                std::array<std::string, 4> { "3710.265", "1046.2", "54.29004", "20" },
                std::array<std::string, 4> { "4136.724", "1003.016", "65.62302", "20" },
                std::array<std::string, 4> { "4132.485", "705.2825", "55.45996", "20" },
                std::array<std::string, 4> { "4336.232", "601.741", "50.05762", "20" },
                std::array<std::string, 4> { "4690.651", "261.7112", "9.004883", "20" },
                std::array<std::string, 4> { "4367.796", "50.26893", "9.046875", "20" },
                std::array<std::string, 4> { "4143.658", "-150.2335", "16.45215", "20" }
            };

            return coordinates;

        case 47:
            coordinates.reserve(13);
            coordinates =
            {
                std::array<std::string, 4> { "2346.335", "1289.311", "132.4012", "20" },
                std::array<std::string, 4> { "2812.778", "968.6901", "77.47119", "20" },
                std::array<std::string, 4> { "3707.364", "1047.466", "63.73804", "20" },
                std::array<std::string, 4> { "3873.488", "698.6506", "23.4834", "20" },
                std::array<std::string, 4> { "3949.139", "426.7924", "29.58012", "20" },
                std::array<std::string, 4> { "4443.084", "602.6832", "56.68018", "20" },
                std::array<std::string, 4> { "4517.928", "987.8903", "61.03461", "20" },
                std::array<std::string, 4> { "4499.97", "1216.876", "25.6748", "25" },
                std::array<std::string, 4> { "3937.606", "2224.862", "41.40723", "20" },
                std::array<std::string, 4> { "3546.854", "2402.916", "22.26855", "20" },
                std::array<std::string, 4> { "3677.772", "2833.426", "6.282227", "20" },
                std::array<std::string, 4> { "3199.403", "3300.484", "36.76465", "20" },
                std::array<std::string, 4> { "3095.171", "2592.551", "40.89355", "20" }
            };

            return coordinates;

        case 50:
            coordinates.reserve(9);
            coordinates =
            {
                std::array<std::string, 4> { "789.8304", "4334.063", "234.9121", "30" },
                std::array<std::string, 4> { "677.3022", "4019.977", "212.6358", "30" },
                std::array<std::string, 4> { "916.7797", "3790.159", "202.0938", "15" },
                std::array<std::string, 4> { "1149.681", "3069.881", "199.7412", "15" },
                std::array<std::string, 4> { "1539.177", "2515.244", "151.5596", "20" },
                std::array<std::string, 4> { "1984.578", "1959.909", "145.2959", "15" },
                std::array<std::string, 4> { "2829.067", "669.582", "45.76074", "20" },
                std::array<std::string, 4> { "2998.231", "-6.117301", "17.14254", "35" },
                std::array<std::string, 4> { "3691.184", "-327.6299", "21.59274", "15" }
            };

            return coordinates;

        //Earl sprint
        case 61:
            coordinates.reserve(9);
            coordinates =
            {
                std::array<std::string, 4> { "4793.972", "774.312", "12.38184", "20" },
                std::array<std::string, 4> { "4402.343", "1019.323", "63.10352", "20" },
                std::array<std::string, 4> { "4312.198", "357.556", "37.30664", "20" },
                std::array<std::string, 4> { "3850.916", "892.6737", "41.78125", "20" },
                std::array<std::string, 4> { "3934.583", "1330.231", "53.375", "20" },
                std::array<std::string, 4> { "3997.227", "2148.108", "25.69825", "20" },
                std::array<std::string, 4> { "3106.976", "2603.62", "40.8623", "25" },
                std::array<std::string, 4> { "3616.332", "3625.956", "29.41504", "25" },
                std::array<std::string, 4> { "4166.567", "3100.76", "30.09277", "20" }
            };

            return coordinates;

        //Jewels sprints
        case 66:
            coordinates.reserve(6);
            coordinates =
            {
                std::array<std::string, 4> { "921.3778", "2191.046", "154.5059", "20" },
                std::array<std::string, 4> { "1698.595", "1829.437", "168.3076", "25" },
                std::array<std::string, 4> { "995.6763", "1721.156", "160.3623", "20" },
                std::array<std::string, 4> { "-417.6116", "2402.144", "243.8887", "20" },
                std::array<std::string, 4> { "-100.0152", "3657.865", "226.5215", "20" },
                std::array<std::string, 4> { "491.0581", "3342.904", "194.8252", "20" }
            };

            return coordinates;

        case 69:
            coordinates.reserve(9);
            coordinates =
            {
                std::array<std::string, 4> { "2922.35", "604.2132", "37.23242", "20" },
                std::array<std::string, 4> { "1761.094", "-33.72891", "90.5", "20" },
                std::array<std::string, 4> { "1016.281", "285.3146", "104.2354", "20" },
                std::array<std::string, 4> { "1802.531", "576.2384", "93.01172", "20" },
                std::array<std::string, 4> { "1972.493", "1006.612", "132.0538", "20" },
                std::array<std::string, 4> { "2126.947", "2198.662", "164.1445", "20" },
                std::array<std::string, 4> { "2436.45", "3422.405", "192.8828", "25" },
                std::array<std::string, 4> { "1758.109", "4312.465", "219.7559", "25" },
                std::array<std::string, 4> { "1089.748", "4437.092", "212.167", "25" }
            };

            return coordinates;

        //Kaze sprints
        case 71:
            coordinates.reserve(7);
            coordinates =
            {
                std::array<std::string, 4> { "2624.771", "4272.51", "259.0157", "30" },
                std::array<std::string, 4> { "2360.804", "3324.683", "197.5361", "25" },
                std::array<std::string, 4> { "2240.428", "2582.153", "131.9121", "20" },
                std::array<std::string, 4> { "1851.476", "1951.398", "149.4697", "20" },
                std::array<std::string, 4> { "2005.249", "1057.231", "139.9834", "20" },
                std::array<std::string, 4> { "1801.98", "576.4349", "93.01855", "20" },
                std::array<std::string, 4> { "2021.62", "-138.7498", "110.0488", "20" }
            };

            return coordinates;

        case 77:
            coordinates.reserve(9);
            coordinates =
            {
                std::array<std::string, 4> { "1094.084", "4436.212", "212.2891", "20" },
                std::array<std::string, 4> { "1758.011", "4310.501", "219.7559", "30" },
                std::array<std::string, 4> { "2434.295", "3422.83", "192.9707", "30" },
                std::array<std::string, 4> { "2126.33", "2197.729", "164.2608", "20" },
                std::array<std::string, 4> { "2080.125", "1218.93", "151.1944", "20" },
                std::array<std::string, 4> { "1559.921", "516.071", "86.68262", "20" },
                std::array<std::string, 4> { "1004.636", "190.2112", "100.7393", "20" },
                std::array<std::string, 4> { "1758.688", "-32.39207", "90.5293", "20" },
                std::array<std::string, 4> { "2759.875", "609.0981", "45.48047", "20" }
            };

            return coordinates;

        case 81:
            coordinates.reserve(12);
            coordinates =
            {
                std::array<std::string, 4> { "2145.47", "2215.343", "160.5527", "20" },
                std::array<std::string, 4> { "2520.698", "1763.646", "112.0498", "30" },
                std::array<std::string, 4> { "2500.232", "1108.753", "98.46289", "20" },
                std::array<std::string, 4> { "2695.183", "596.1105", "52.91504", "20" },
                std::array<std::string, 4> { "2553.38", "10.24371", "96.0547", "25" },
                std::array<std::string, 4> { "2577.787", "-339.2645", "115.8965", "25" },
                std::array<std::string, 4> { "1719.465", "-152.0413", "133.5869", "20" },
                std::array<std::string, 4> { "1535.658", "-95.8205", "99.61133", "20" },
                std::array<std::string, 4> { "1089.474", "160.8677", "98.49809", "20" },
                std::array<std::string, 4> { "1588.042", "185.681", "93.95117", "20" },
                std::array<std::string, 4> { "1388.942", "366.3758", "99.18359", "20" },
                std::array<std::string, 4> { "976.1771", "413.8442", "108.8809", "20" }
            };

            return coordinates;

        case 82:
            coordinates.reserve(7);
            coordinates =
            {
                std::array<std::string, 4> { "1242.524", "2137.573", "149.8017", "20" },
                std::array<std::string, 4> { "1980.578", "1741.158", "150.501", "15" },
                std::array<std::string, 4> { "2678.63", "790.3736", "69.21777", "25" },
                std::array<std::string, 4> { "3436.222", "-337.1812", "14.79199", "30" },
                std::array<std::string, 4> { "4325.552", "16.81068", "9.846677", "20" },
                std::array<std::string, 4> { "4819.451", "809.3515", "14.83594", "20" },
                std::array<std::string, 4> { "4281.265", "1328.468", "38.62012", "15" }
            };

            return  coordinates;

        //Ming sprints
        case 83:
            coordinates.reserve(7);
            coordinates =
            {
                std::array<std::string, 4> { "1192.523", "-773.6458", "124.0781", "20" },
                std::array<std::string, 4> { "1727.031", "-663.2106", "115.666", "20" },
                std::array<std::string, 4> { "1779.915", "-24.77111", "104.0625", "20" },
                std::array<std::string, 4> { "2128.433", "22.27049", "94.64063", "20" },
                std::array<std::string, 4> { "1761.318", "375.2563", "92.89063", "20" },
                std::array<std::string, 4> { "1481.271", "450.1915", "115.8877", "20" },
                std::array<std::string, 4> { "1636.792", "997.9111", "122.1162", "20" }
            };

            return coordinates;

        case 86:
            coordinates.reserve(6);
            coordinates =
            {
                std::array<std::string, 4> { "1657.254", "822.4499", "123.291", "20" },
                std::array<std::string, 4> { "1664.791", "-33.42774", "101.0752", "20" },
                std::array<std::string, 4> { "1561.23", "-688.5742", "114.8926", "25" },
                std::array<std::string, 4> { "358.3468", "-464.7075", "125.8887", "25" },
                std::array<std::string, 4> { "363.3483", "-18.02285", "115.4884", "25" },
                std::array<std::string, 4> { "956.8276", "416.8457", "110.1797", "20" }
            };

            return coordinates;

        case 90:
            coordinates.reserve(7);
            coordinates =
            {
                std::array<std::string, 4> { "2021.838", "-139.6848", "110.0957", "20" },
                std::array<std::string, 4> { "1802.773", "576.3218", "93.01367", "20" },
                std::array<std::string, 4> { "2005.249", "1057.231", "139.9834", "20" },
                std::array<std::string, 4> { "1851.476", "1951.398", "149.4697", "20" },
                std::array<std::string, 4> { "2240.428", "2582.153", "131.9121", "20" },
                std::array<std::string, 4> { "2360.804", "3324.683", "197.5361", "35" },
                std::array<std::string, 4> { "2622.347", "4260.308", "258.0323", "35" }
            };

            return coordinates;

        //Webster sprints
        case 98:
            coordinates.reserve(10);
            coordinates =
            {
                std::array<std::string, 4> { "1521.057", "1155.492", "117.6865", "25" },
                std::array<std::string, 4> { "-364.7754", "2356.698", "241.5479", "20" },
                std::array<std::string, 4> { "-138.3705", "3646.626", "224.1143", "20" },
                std::array<std::string, 4> { "629.2085", "4146.218", "198.5791", "20" },
                std::array<std::string, 4> { "1779.739", "3769.392", "169.5869", "20" },
                std::array<std::string, 4> { "1762.375", "2039.609", "148.0371", "35" },
                std::array<std::string, 4> { "1197.741", "2982.079", "193.4541", "20" },
                std::array<std::string, 4> { "894.2403", "3170.992", "199.3975", "20" },
                std::array<std::string, 4> { "342.0208", "3092.73", "188.7441", "20" },
                std::array<std::string, 4> { "610.6276", "2727.391", "170.9599", "20" }
            };

            return coordinates;

        case 103:
            coordinates.reserve(10);
            coordinates =
            {
                std::array<std::string, 4> { "2509.52", "2497.671", "122.4208", "25" },
                std::array<std::string, 4> { "2533.438", "1718.266", "117.0381", "35" },
                std::array<std::string, 4> { "2476.298", "1113.672", "102.0938", "20" },
                std::array<std::string, 4> { "2682.315", "791.5881", "68.54492", "30" },
                std::array<std::string, 4> { "3020.413", "-16.46531", "19.22071", "35" },
                std::array<std::string, 4> { "3326.444", "-309.7901", "16.79883", "20" },
                std::array<std::string, 4> { "4207.369", "80.39259", "2.411133", "15" },
                std::array<std::string, 4> { "3852.282", "886.8719", "41.00293", "20" },
                std::array<std::string, 4> { "3454.844", "1244.703", "80.45313", "20" },
                std::array<std::string, 4> { "3338.535", "1731.643", "105.3887", "20" }
            };

            return coordinates;

        case 106:
            coordinates.reserve(9);
            coordinates =
            {
                std::array<std::string, 4> { "4824.769", "818.5687", "21.10449", "20" },
                std::array<std::string, 4> { "4338.974", "160.613", "19.49707", "20" },
                std::array<std::string, 4> { "3779.361", "-305.3108", "17.90625", "20" },
                std::array<std::string, 4> { "3000.168", "-5.882346", "19.26269", "30" },
                std::array<std::string, 4> { "2776.275", "725.6134", "55.38477", "20" },
                std::array<std::string, 4> { "2292.33", "1305.056", "146.2793", "20" },
                std::array<std::string, 4> { "2081.125", "1718.344", "162.585", "20" },
                std::array<std::string, 4> { "1509.561", "2534.324", "154.7051", "20" },
                std::array<std::string, 4> { "1990.381", "2063.037", "144.5127", "20" }
            };

            return coordinates;

        case 108:
            coordinates.reserve(10);
            coordinates =
            {
                std::array<std::string, 4> { "610.6276", "2727.391", "170.9599", "20" },
                std::array<std::string, 4> { "342.9821", "3080.659", "189.2275", "20" },
                std::array<std::string, 4> { "888.5839", "3171.73", "199.3965", "20" },
                std::array<std::string, 4> { "1180.232", "3011.503", "198.1855", "20" },
                std::array<std::string, 4> { "1743.441", "2057.177", "146.3945", "25" },
                std::array<std::string, 4> { "1777.774", "3762.915", "168.875", "25" },
                std::array<std::string, 4> { "627.0817", "4150.441", "198.8281", "20" },
                std::array<std::string, 4> { "-138.3705", "3646.626", "224.1143", "20" },
                std::array<std::string, 4> { "-363.409", "2357.869", "241.5235", "20" },
                std::array<std::string, 4> { "994.8439", "1723.021", "153.8359", "20" }
            };

            return coordinates;

        //JV sprint
        case 115:
            coordinates.reserve(12);
            coordinates =
            {
                std::array<std::string, 4> { "976.1771", "413.8442", "108.8809", "20" },
                std::array<std::string, 4> { "1388.942", "366.3758", "99.18359", "20" },
                std::array<std::string, 4> { "1586.931", "184.1451", "93.91699", "20" },
                std::array<std::string, 4> { "1089.474", "160.8677", "98.49809", "25" },
                std::array<std::string, 4> { "1535.964", "-94.29073", "99.5", "15" },
                std::array<std::string, 4> { "1719.465", "-152.0413", "133.5869", "20" },
                std::array<std::string, 4> { "2576.919", "-338.6137", "115.9219", "25" },
                std::array<std::string, 4> { "2553.746", "13.52119", "95.78126", "25" },
                std::array<std::string, 4> { "2709.72", "598.3825", "52.58887", "20" },
                std::array<std::string, 4> { "2500.232", "1108.753", "98.46289", "20" },
                std::array<std::string, 4> { "2520.698", "1763.646", "112.0498", "30" },
                std::array<std::string, 4> { "2145.47", "2215.343", "160.5527", "25" }
            };

            return coordinates;

        //Ronnie sprints
        case 123:
            coordinates.reserve(7);
            coordinates =
            {
                std::array<std::string, 4> { "3331.309", "3617.967", "37.60938", "20" },
                std::array<std::string, 4> { "2915.188", "3023.835", "63.63086", "20" },
                std::array<std::string, 4> { "3103.047", "2599.732", "40.94043", "25" },
                std::array<std::string, 4> { "2538.102", "1954.67", "105.5889", "20" },
                std::array<std::string, 4> { "2007.052", "1057.502", "140.2119", "20" },
                std::array<std::string, 4> { "1801.94", "596.3895", "94.05957", "20" },
                std::array<std::string, 4> { "995.4659", "221.4725", "102.1533", "20" }
            };

            return coordinates;

        case 127:
            coordinates.reserve(7);
            coordinates =
            {
                std::array<std::string, 4> { "2011.476", "-134.4106", "104.1563", "20" },
                std::array<std::string, 4> { "1800.17", "576.3218", "93.01172", "20" },
                std::array<std::string, 4> { "2005.249", "1057.231", "139.9834", "20" },
                std::array<std::string, 4> { "1880.91", "1920.266", "149.8974", "20" },
                std::array<std::string, 4> { "2240.428", "2582.153", "131.9121", "20" },
                std::array<std::string, 4> { "2379.766", "3356.098", "196.08", "30" },
                std::array<std::string, 4> { "2623.366", "4393.721", "265.7617", "30" }
            };

            return coordinates;

        case 133:
            coordinates.reserve(7);
            coordinates =
            {
                std::array<std::string, 4> { "2134.598", "2692.088", "123.3223", "20" },
                std::array<std::string, 4> { "3020.17", "1912.663", "104.2197", "20" },
                std::array<std::string, 4> { "4608.567", "1123.98", "13.03222", "20" },
                std::array<std::string, 4> { "4061.515", "934.571", "59.30469", "20" },
                std::array<std::string, 4> { "4330.065", "113.7581", "16.44629", "20" },
                std::array<std::string, 4> { "3053.976", "-31.63036", "17.27929", "30" },
                std::array<std::string, 4> { "1725.069", "-662.8195", "114.5", "25" }
            };

            return coordinates;

        case 136:
            coordinates.reserve(9);
            coordinates =
            {
                std::array<std::string, 4> { "4045.412", "921.2703", "58.39453", "15" },
                std::array<std::string, 4> { "4642.887", "1121.286", "11.37305", "20" },
                std::array<std::string, 4> { "3722.703", "1298.985", "72.16698", "20" },
                std::array<std::string, 4> { "2859.015", "988.7518", "78.00781", "20" },
                std::array<std::string, 4> { "2293.575", "1300.333", "146.0538", "20" },
                std::array<std::string, 4> { "2010.297", "1062.017", "141.1143", "20" },
                std::array<std::string, 4> { "1801.616", "600.6136", "94.43262", "20" },
                std::array<std::string, 4> { "2182.013", "186.2478", "80.24609", "20" },
                std::array<std::string, 4> { "1763.749", "-29.95683", "90.5", "20" }
            };

            return coordinates;

        //Bull sprints
        case 144:
            coordinates.reserve(7);
            coordinates =
            {
                std::array<std::string, 4> { "994.015", "232.354", "102.5693", "25" },
                std::array<std::string, 4> { "1801.94", "596.3895", "94.05957", "25" },
                std::array<std::string, 4> { "2007.052", "1057.502", "140.2119", "20" },
                std::array<std::string, 4> { "2540.304", "1957.851", "105.7998", "20" },
                std::array<std::string, 4> { "3120.457", "2609.163", "49.46973", "35" },
                std::array<std::string, 4> { "2953.734", "2993.214", "57.72754", "20" },
                std::array<std::string, 4> { "3331.071", "3618.003", "37.65234", "25" }
            };

            return coordinates;

        case 151:
            coordinates.reserve(7);
            coordinates =
            {
                std::array<std::string, 4> { "2545.093", "1961.012", "106.1162", "20" },
                std::array<std::string, 4> { "2812.677", "3026.861", "61.71289", "15" },
                std::array<std::string, 4> { "3632.76", "2619.8", "11.10254", "15" },
                std::array<std::string, 4> { "3926.081", "2219.097", "38.91797", "15" },
                std::array<std::string, 4> { "4311.945", "1332.048", "31.32227", "15" },
                std::array<std::string, 4> { "3448.821", "1238.087", "80.21387", "15" },
                std::array<std::string, 4> { "4118.835", "724.795", "54.61914", "15" }
            };

            return coordinates;

        case 152:
            coordinates.reserve(11);
            coordinates =
            {
                std::array<std::string, 4> { "2314.857", "932.59", "132.7686", "15" },
                std::array<std::string, 4> { "1638.01", "999.5876", "122.0977", "25" },
                std::array<std::string, 4> { "1748.355", "2049.513", "146.9756", "30" },
                std::array<std::string, 4> { "527.1174", "2340.25", "161.623", "20" },
                std::array<std::string, 4> { "220.058", "2839.601", "180.2275", "15" },
                std::array<std::string, 4> { "246.0561", "3620.818", "187.917", "20" },
                std::array<std::string, 4> { "1134.592", "4423.688", "214.0049", "25" },
                std::array<std::string, 4> { "2260.479", "4521.984", "253.0771", "30" },
                std::array<std::string, 4> { "2553.405", "3815.501", "226.6563", "35" },
                std::array<std::string, 4> { "2437.83", "2528.435", "120.8857", "20" },
                std::array<std::string, 4> { "3001.855", "1924.179", "107.1719", "25" }
            };

            return coordinates;

        //Razor sprints
        case 154:
            coordinates.reserve(7);
            coordinates =
            {
                std::array<std::string, 4> { "1091.964", "647.8892", "113.7383", "25" },
                std::array<std::string, 4> { "1454.829", "1348.722", "125.8047", "20" },
                std::array<std::string, 4> { "2038.331", "2885.37", "141.8662", "30" },
                std::array<std::string, 4> { "689.9584", "3988.483", "216.164", "20" },
                std::array<std::string, 4> { "-201.6377", "3226.595", "192.6211", "20" },
                std::array<std::string, 4> { "-341.812", "3938.311", "239.0909", "25" },
                std::array<std::string, 4> { "598.3944", "4550.684", "223.6309", "20" }
            };

            return coordinates;

        case 155:
            coordinates.reserve(7);
            coordinates =
            {
                std::array<std::string, 4> { "4054.582", "2920.971", "30.08105", "20" },
                std::array<std::string, 4> { "3643.443", "1306.033", "81.2998", "20" },
                std::array<std::string, 4> { "4229.982", "1260.079", "46.625", "20" },
                std::array<std::string, 4> { "4699.709", "543.241", "9.671875", "20" },
                std::array<std::string, 4> { "3106.605", "-33.30618", "13.61719", "20" },
                std::array<std::string, 4> { "2636.196", "755.7601", "62.91601", "20" },
                std::array<std::string, 4> { "1980.634", "1725.876", "150.7041", "20" }
            };

            return coordinates;

        case 156:
            coordinates.reserve(9);
            coordinates =
            {
                std::array<std::string, 4> { "2956.667", "591.6778", "31.76758", "20" },
                std::array<std::string, 4> { "2564.191", "308.5582", "85.21191", "20" },
                std::array<std::string, 4> { "2098.772", "950.547", "125.6777", "25" },
                std::array<std::string, 4> { "1226.783", "784.5218", "116.1973", "25" },
                std::array<std::string, 4> { "537.397", "371.5119", "112.7119", "25" },
                std::array<std::string, 4> { "337.2456", "-46.02396", "115.9004", "25" },
                std::array<std::string, 4> { "369.3607", "-476.8636", "126.7666", "25" },
                std::array<std::string, 4> { "1209.287", "-783.1482", "125.4199", "15" },
                std::array<std::string, 4> { "1731.349", "-171.5293", "95.2373", "20" }
            };

            return coordinates;

        case 162:
            coordinates.reserve(11);
            coordinates =
            {
                std::array<std::string, 4> { "2914.99", "2003.755", "113.6572", "30" },
                std::array<std::string, 4> { "2444.71", "2522.113", "123.3222", "20" },
                std::array<std::string, 4> { "2553.405", "3815.501", "226.6563", "30" },
                std::array<std::string, 4> { "2552.619", "4515.849", "264.7412", "25" },
                std::array<std::string, 4> { "1106.951", "4431.651", "212.8614", "20" },
                std::array<std::string, 4> { "154.6939", "3839.064", "188.5869", "20" },
                std::array<std::string, 4> { "220.058", "2839.601", "180.2275", "20" },
                std::array<std::string, 4> { "527.1174", "2340.25", "161.623", "20" },
                std::array<std::string, 4> { "1771.045", "2027.657", "148.8017", "25" },
                std::array<std::string, 4> { "1637.671", "1000.336", "122.0713", "20" },
                std::array<std::string, 4> { "2314.857", "932.59", "133.7686", "20" }
            };

            return coordinates;

        case 166:
            coordinates.reserve(7);
            coordinates =
            {
                std::array<std::string, 4> { "2483.41", "-518.9597", "132.8066", "25" },
                std::array<std::string, 4> { "2643.953", "341.2476", "82.22459", "25" },
                std::array<std::string, 4> { "4343.349", "178.8255", "19.27441", "20" },
                std::array<std::string, 4> { "4061.515", "934.571", "59.30469", "25" },
                std::array<std::string, 4> { "4636.692", "1123.586", "11.09375", "20" },
                std::array<std::string, 4> { "3011.289", "1916.332", "110.123", "25" },
                std::array<std::string, 4> { "2134.979", "2693.232", "122.9952", "35" }
            };

            return coordinates;

        case 168:
            coordinates.reserve(8);
            coordinates =
            {
                std::array<std::string, 4> { "1128.374", "3724.939", "211.6504", "20" },
                std::array<std::string, 4> { "-340.0385", "3880.324", "238.1221", "30" },
                std::array<std::string, 4> { "1160.184", "3049.883", "199.7002", "20" },
                std::array<std::string, 4> { "2133.702", "1455.354", "147.1582", "20" },
                std::array<std::string, 4> { "3682.142", "1054.742", "57.57422", "20" },
                std::array<std::string, 4> { "4131.563", "1024.649", "64.59668", "25" },
                std::array<std::string, 4> { "4311.674", "670.6627", "34.29004", "25" },
                std::array<std::string, 4> { "2361.781", "226.1072", "92.7793", "20" }
            };

            return coordinates;

        //Prologue sprints
        case 170:
            coordinates.reserve(6);
            coordinates =
            {
                std::array<std::string, 4> { "1051.489", "449.1164", "107.3145", "20" },
                std::array<std::string, 4> { "1646.948", "542.022", "89.66888", "20" },
                std::array<std::string, 4> { "1807.978", "618.4438", "106.7948", "25" },
                std::array<std::string, 4> { "2082.837", "1224.404", "149.5263", "20" },
                std::array<std::string, 4> { "2306.271", "1301.342", "142.2041", "20" },
                std::array<std::string, 4> { "2712.685", "886.0176", "85.79781", "20" }
            };

            return coordinates;

        case 171:
            coordinates.reserve(9);
            coordinates =
            {
                std::array<std::string, 4> { "2691.895", "594.6967", "55.57323", "25" },
                std::array<std::string, 4> { "2675.015", "363.6713", "80.80369", "25" },
                std::array<std::string, 4> { "2423.423", "538.7394", "90.90327", "15" },
                std::array<std::string, 4> { "2327.354", "929.0919", "121.8642", "20" },
                std::array<std::string, 4> { "1604.702", "658.0076", "121.5811", "20" },
                std::array<std::string, 4> { "1454.518", "290.3804", "99.35154", "20" },
                std::array<std::string, 4> { "1545.155", "-94.73048", "101.9454", "15" },
                std::array<std::string, 4> { "1251.987", "-40.4714", "97.55575", "15" },
                std::array<std::string, 4> { "1050.964", "445.5285", "110.1933", "15" }
            };

            return coordinates;

        //Collectors edition sprints
        case 173:
            coordinates.reserve(14);
            coordinates =
            {
                std::array<std::string, 4> { "1988.909", "4367.445", "230.5", "20" },
                std::array<std::string, 4> { "2507.224", "3868.502", "232.2305", "30" },
                std::array<std::string, 4> { "2457.124", "2520.289", "122.0303", "15" },
                std::array<std::string, 4> { "2848.753", "2409.61", "76.70801", "20" },
                std::array<std::string, 4> { "2814.279", "3031.535", "61.58984", "15" },
                std::array<std::string, 4> { "3708.155", "3490.401", "25.28125", "15" },
                std::array<std::string, 4> { "4061.009", "2968.255", "33.49121", "15" },
                std::array<std::string, 4> { "4328.876", "1515.571", "21.9834", "15" },
                std::array<std::string, 4> { "4342.854", "180.237", "21.33691", "15" },
                std::array<std::string, 4> { "2664.15", "354.9085", "83.76367", "15" },
                std::array<std::string, 4> { "361.916", "-468.2354", "126.165", "25" },
                std::array<std::string, 4> { "1462.778", "1192.881", "116.7998", "20" },
                std::array<std::string, 4> { "-566.2511", "2677.333", "230.3691", "20" },
                std::array<std::string, 4> { "389.8765", "4514.552", "234.1826", "25" }
            };

            return coordinates;

        case 174:
            coordinates.reserve(7);
            coordinates =
            {
                std::array<std::string, 4> { "4207.762", "-121.5554", "13.13281", "20" },
                std::array<std::string, 4> { "3402.981", "-179.9392", "12.4834", "15" },
                std::array<std::string, 4> { "3365.51", "790.0809", "19.67871", "15" },
                std::array<std::string, 4> { "3968.946", "785.3812", "39.91504", "15" },
                std::array<std::string, 4> { "3923.051", "959.6981", "58.79297", "15" },
                std::array<std::string, 4> { "2952.474", "1035.983", "67.19727", "20" },
                std::array<std::string, 4> { "2425.672", "1153.64", "113.3741", "15" }
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
            speedtrapNames.reserve(5);
            speedtrapNames =
            { "race_bin_13/13_5_2_speedtrap/speedtrap1", "race_bin_13/13_5_2_speedtrap/speedtrap2",
              "race_bin_13/13_5_2_speedtrap/speedtrap3", "race_bin_13/13_5_2_speedtrap/speedtrap5",
              "race_bin_13/13_5_2_speedtrap/speedtrap6" };

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

std::array<std::string, 73> getListOfPlayerCars()
{
    return std::array<std::string, 73> { "M3GTRCAREERSTART", "RAZORMUSTANG", "DDAYSUPRA", "OPM_MUSTANG_BOSS",
        "OPM_WRX_VERSION2", "OPM_RX8_Version3", "BL15", "BL14", "BL13", "BL12", "BL11", "BL10", "BL9", "BL8",
        "BL7", "BL6", "BL5", "BL4", "BL3", "BL2", "E3_DEMO_BMW", "CS_CAR_01", "CS_CAR_02", "CS_CAR_03",
        "CS_CAR_04", "CS_CAR_05", "CS_CAR_06", "CS_CAR_07", "CS_CAR_08", "CS_CAR_09", "CS_CAR_10", "CS_CAR_11",
        "CS_CAR_12", "CS_CAR_13", "CS_CAR_14", "CS_CAR_15", "CS_CAR_16", "CS_CAR_17", "CS_CAR_18", "CS_CAR_19",
        "CS_CAR_20", "CS_CAR_21", "CS_CAR_22", "CS_CAR_23", "CS_CAR_24", "CS_CAR_26", "CS_CAR_27", "CS_CAR_28",
        "CS_CAR_29", "CS_CAR_30", "CS_CAR_31", "CS_CAR_32", "CS_CAR_33", "CS_CAR_34", "CS_CAR_PIZZA",
        "CS_CAR_MINIVAN", "CS_CAR_COPGTO", "CS_CAR_TAXI", "CS_CAR_HENCH", "CASTROLGT", "BONUS_C6R", "BONUS_GT2",
        "BONUS_SL65", "CE_997S", "CE_C6R", "CE_CAMARO", "CE_CORVETTE", "CE_ELISE", "CE_GT2", "CE_GTRSTREET",
        "CE_SL500", "CE_SL65", "CE_SUPRA" };
}

std::array<std::string, 35> getListOfAICars()
{
    return std::array<std::string, 35> { "M3GTRCAREERSTART", "RAZORMUSTANG", "DDAYSUPRA", "OPM_MUSTANG_BOSS",
        "OPM_WRX_VERSION2", "OPM_RX8_Version3", "BL15", "BL14", "BL13", "BL12", "BL11", "BL10", "BL9", "BL8",
        "BL7", "BL6", "BL5", "BL4","BL3", "BL2", "E3_DEMO_BMW", "CASTROLGT", "BONUS_C6R", "BONUS_GT2",
        "BONUS_SL65", "CE_997S", "CE_C6R", "CE_CAMARO", "CE_CORVETTE", "CE_ELISE", "CE_GT2", "CE_GTRSTREET",
        "CE_SL500", "CE_SL65", "CE_SUPRA" };
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
