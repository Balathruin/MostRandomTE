//
// Created by Ted on 20/06/2024
//

#include <string>
#include <fstream>
#include <array>
#include <algorithm>
#include "NodeConversionFunctions.h"

void resetPerformanceMarkers()
{
    std::array<std::string, 15> allMarkers = { "race_bin_15/rewards/reward_brakes",
       "race_bin_14/rewards/reward_chassis", "race_bin_13/rewards/reward_transmission1",
       "race_bin_12/rewards/reward_induction1", "race_bin_11/rewards/reward_tires1",
       "race_bin_10/rewards/reward_chassis1", "race_bin_09/rewards/reward_induction1",
       "race_bin_08/rewards/reward_transmission1", "race_bin_07/rewards/reward_tires1",
       "race_bin_06/rewards/reward_chassis1", "race_bin_05/rewards/reward_induction1",
       "race_bin_04/rewards/reward_engine1", "race_bin_03/rewards/reward_tires1",
       "race_bin_02/rewards/reward_induction1", "race_bin_21/rewards/reward_nos1" };

    std::array<std::string, 7> neededMarkers = { "race_bin_15/rewards/reward_brakes",
       "race_bin_14/rewards/reward_chassis", "race_bin_13/rewards/reward_transmission1",
       "race_bin_12/rewards/reward_induction1", "race_bin_11/rewards/reward_tires1",
       "race_bin_04/rewards/reward_engine1", "race_bin_21/rewards/reward_nos1" };

    std::array<std::string, 7>::iterator foundMarker;
    std::ofstream file;
    file.open("Random.nfsms", std::ios_base::app);

    file << std::string("# performance markers modified as needed").append("\n");

    //Ensure only one copy of every marker exists in vlted
    for ( const std::string& marker : allMarkers )
    {
        if ( marker != "race_bin_21/rewards/reward_nos1" )
        {
            foundMarker = std::find(neededMarkers.begin(), neededMarkers.end(), marker);

            if ( foundMarker != neededMarkers.end() )
            {
                if ( marker.back() == '1' )
                {
                    file << std::string("rename_node gameplay ").append(marker).append(" ")
                    .append("templates").append(marker.substr(11, marker.length() - 12))
                    .append("\n");

                    file << std::string("change_vault gameplay ").append("templates")
                    .append(marker.substr(11, marker.length() - 12)).append(" gpcore")
                    .append("\n");

                    file << std::string("update_field gameplay ").append("templates")
                    .append(marker.substr(11, marker.length() - 12)).append(" Name ")
                    .append("templates").append(marker.substr(11, marker.length() - 12))
                    .append("\n");
                }

                else
                {
                    file << std::string("rename_node gameplay ").append(marker).append(" ")
                    .append("templates").append(marker.substr(11, marker.length() - 11))
                    .append("\n");

                    file << std::string("change_vault gameplay ").append("templates")
                    .append(marker.substr(11, marker.length() - 11)).append(" gpcore")
                    .append("\n");

                    file << std::string("update_field gameplay ").append("templates")
                    .append(marker.substr(11, marker.length() - 11)).append(" Name ")
                    .append("templates").append(marker.substr(11, marker.length() - 11))
                    .append("\n");
                }
            }

            else
            { file << std::string("delete_node gameplay ").append(marker).append("\n"); }
        }

        //If junkman NOS, add node to database
        else
        {
            //The unused junkman NOS is re-added
            file << std::string("add_node gameplay reward_nos templates/rewards/reward_nos").append("\n");
            file << std::string("add_field gameplay templates/rewards/reward_nos Template").append("\n");
            file << std::string("add_field gameplay templates/rewards/reward_nos Name").append("\n");
            file << std::string("update_field gameplay templates/rewards/reward_nos CollectionName "
                                "templates/rewards/reward_nos").append("\n");
            file << std::string("update_field gameplay templates/rewards/reward_nos Name "
                                "templates/rewards/reward_nos").append("\n\n");
        }
    }

    file.close();
}

void resetVisualMarkers()
{
    std::array<std::string, 29> allMarkers = { "race_bin_15/rewards/reward_vinyl", "race_bin_15/rewards/reward_rims",
       "race_bin_14/rewards/reward_vinyl", "race_bin_14/rewards/reward_hood", "race_bin_13/rewards/reward_hud1",
       "race_bin_13/rewards/reward_body1", "race_bin_12/rewards/reward_vinyl1", "race_bin_12/rewards/reward_body1",
       "race_bin_11/rewards/reward_rims1", "race_bin_11/rewards/reward_spoiler1",
       "race_bin_10/rewards/reward_roofscoop1", "race_bin_10/rewards/reward_hood1", "race_bin_09/rewards/reward_hud1",
       "race_bin_09/rewards/reward_hood1", "race_bin_08/rewards/reward_spoiler1", "race_bin_08/rewards/reward_body1",
       "race_bin_07/rewards/reward_vinyl1", "race_bin_07/rewards/reward_spoiler1", "race_bin_06/rewards/reward_vinyl1",
       "race_bin_06/rewards/reward_rims1", "race_bin_05/rewards/reward_vinyl1", "race_bin_05/rewards/reward_hood1",
       "race_bin_04/rewards/reward_body1", "race_bin_04/rewards/reward_vinyl1",
       "race_bin_03/rewards/reward_roofscoop1", "race_bin_03/rewards/reward_rims1",
       "race_bin_02/rewards/reward_vinyl1", "race_bin_02/rewards/reward_hud1", "race_bin_21/rewards/reward_paint1" };

    std::array<std::string, 8> neededMarkers = { "race_bin_15/rewards/reward_vinyl", "race_bin_15/rewards/reward_rims",
       "race_bin_14/rewards/reward_hood", "race_bin_13/rewards/reward_hud1", "race_bin_13/rewards/reward_body1",
       "race_bin_11/rewards/reward_spoiler1", "race_bin_10/rewards/reward_roofscoop1",
       "race_bin_21/rewards/reward_paint1" };

    //Variables and header
    std::array<std::string, 8>::iterator foundMarker;
    std::ofstream file;
    file.open("Random.nfsms", std::ios_base::app);

    file << std::string("# visual markers modified as needed").append("\n");

    //Ensure only one copy of every marker exists in vlted
    for ( const std::string& marker : allMarkers )
    {
        if ( marker != "race_bin_21/rewards/reward_paint1" )
        {
            foundMarker = std::find(neededMarkers.begin(), neededMarkers.end(), marker);

            if ( foundMarker != neededMarkers.end() )
            {
                if ( marker.back() == '1' )
                {
                    file << std::string("rename_node gameplay ").append(marker).append(" ")
                    .append("templates").append(marker.substr(11, marker.length() - 12))
                    .append("\n");

                    file << std::string("change_vault gameplay ").append("templates")
                    .append(marker.substr(11, marker.length() - 12)).append(" gpcore")
                    .append("\n");

                    file << std::string("update_field gameplay ").append("templates")
                    .append(marker.substr(11, marker.length() - 12)).append(" Name ")
                    .append("templates").append(marker.substr(11, marker.length() - 12))
                    .append("\n");
                }

                else
                {
                    file << std::string("rename_node gameplay ").append(marker).append(" ")
                    .append("templates").append(marker.substr(11, marker.length() - 11))
                    .append("\n");

                    file << std::string("change_vault gameplay ").append("templates")
                    .append(marker.substr(11, marker.length() - 11)).append(" gpcore")
                    .append("\n");

                    file << std::string("update_field gameplay ").append("templates")
                    .append(marker.substr(11, marker.length() - 11)).append(" Name ")
                    .append("templates").append(marker.substr(11, marker.length() - 11))
                    .append("\n");
                }
            }

            else
            { file << std::string("delete_node gameplay ").append(marker).append("\n"); }
        }

        //If junkman paint, add node to database
        else
        {
            //The unused junkman paint is re-added
            file << std::string("add_node gameplay reward_paint templates/rewards/reward_paint").append("\n");
            file << std::string("add_field gameplay templates/rewards/reward_paint Template").append("\n");
            file << std::string("add_field gameplay templates/rewards/reward_paint Name").append("\n");
            file << std::string("update_field gameplay templates/rewards/reward_paint CollectionName "
                                "templates/rewards/reward_paint").append("\n");
            file << std::string("update_field gameplay templates/rewards/reward_paint Name "
                                "templates/rewards/reward_paint").append("\n\n");
        }
    }

    file.close();
}

void resetRandomMarkers()
{
    std::array<std::string, 42> allMarkers = { "race_bin_02/rewards/reward_pink_slip1",
       "race_bin_15/rewards/reward_out_of_jail_free1", "race_bin_14/rewards/reward_add_impound_box1",
       "race_bin_14/rewards/reward_cash_bonus", "race_bin_13/rewards/reward_cash_bonus1",
       "race_bin_13/rewards/reward_cash_bonus2", "race_bin_12/rewards/reward_add_impound_box1",
       "race_bin_12/rewards/reward_release_car_from_impound1", "race_bin_11/rewards/reward_cash_bonus1",
       "race_bin_11/rewards/reward_out_of_jail_free1", "race_bin_10/rewards/reward_add_impound_box1",
       "race_bin_10/rewards/reward_out_of_jail_free1", "race_bin_09/rewards/reward_add_impound_box1",
       "race_bin_09/rewards/reward_release_car_from_impound1", "race_bin_08/rewards/reward_add_impound_box1",
       "race_bin_08/rewards/reward_out_of_jail_free1", "race_bin_07/rewards/reward_out_of_jail_free1",
       "race_bin_07/rewards/reward_release_car_from_impound1", "race_bin_06/rewards/reward_out_of_jail_free1",
       "race_bin_06/rewards/reward_cash_bonus1", "race_bin_05/rewards/reward_add_impound_box1",
       "race_bin_05/rewards/reward_out_of_jail_free1", "race_bin_04/rewards/reward_release_car_from_impound1",
       "race_bin_04/rewards/reward_cash_bonus1", "race_bin_03/rewards/reward_add_impound_box1",
       "race_bin_03/rewards/reward_out_of_jail_free1", "race_bin_02/rewards/reward_out_of_jail_free1",
       "race_bin_02/rewards/reward_release_car_from_impound1", "race_bin_15/rewards/reward_pink_slip1",
       "race_bin_14/rewards/reward_pink_slip1", "race_bin_13/rewards/reward_pink_slip1",
       "race_bin_12/rewards/reward_pink_slip1", "race_bin_11/rewards/reward_pink_slip1",
       "race_bin_10/rewards/reward_pink_slip1", "race_bin_09/rewards/reward_pink_slip1",
       "race_bin_08/rewards/reward_pink_slip1", "race_bin_07/rewards/reward_pink_slip1",
       "race_bin_06/rewards/reward_pink_slip1", "race_bin_05/rewards/reward_pink_slip1",
       "race_bin_04/rewards/reward_pink_slip1", "race_bin_03/rewards/reward_pink_slip1",
       "race_bin_15/rewards/reward_cash_bonus1" };

    std::array<std::string, 5> markersToKeep = { "race_bin_15/rewards/reward_out_of_jail_free1",
       "race_bin_14/rewards/reward_add_impound_box1", "race_bin_12/rewards/reward_release_car_from_impound1",
       "race_bin_15/rewards/reward_pink_slip1", "race_bin_15/rewards/reward_cash_bonus1" };

    std::array<std::string, 5>::iterator foundMarker;
    std::ofstream file;
    file.open("Random.nfsms", std::ios_base::app);

    file << std::string("# random markers modified as needed").append("\n");

    //Ensure only one copy of every marker exists in vlted
    for ( const std::string& marker : allMarkers )
    {
        if ( marker != "race_bin_15/rewards/reward_cash_bonus1" )
        {
            foundMarker = std::find(markersToKeep.begin(), markersToKeep.end(), marker);

            if ( foundMarker != markersToKeep.end() )
            {
                if ( marker.back() == '1' )
                {
                    file << std::string("rename_node gameplay ").append(marker).append(" ")
                    .append("templates").append(marker.substr(11, marker.length() - 12))
                    .append("\n");

                    file << std::string("change_vault gameplay ").append("templates")
                    .append(marker.substr(11, marker.length() - 12)).append(" gpcore")
                    .append("\n");

                    file << std::string("update_field gameplay ").append("templates")
                    .append(marker.substr(11, marker.length() - 12)).append(" Name ")
                    .append("templates").append(marker.substr(11, marker.length() - 12))
                    .append("\n");
                }

                else
                {
                    file << std::string("rename_node gameplay ").append(marker).append(" ")
                    .append("templates").append(marker.substr(11, marker.length() - 11))
                    .append("\n");

                    file << std::string("change_vault gameplay ").append("templates")
                    .append(marker.substr(11, marker.length() - 11)).append(" gpcore")
                    .append("\n");

                    file << std::string("update_field gameplay ").append("templates")
                    .append(marker.substr(11, marker.length() - 11)).append(" Name ")
                    .append("templates").append(marker.substr(11, marker.length() - 11))
                    .append("\n");
                }
            }

            else
            { file << std::string("delete_node gameplay ").append(marker).append("\n"); }
        }

            //If Sonny cash marker, rename and keep as template
        else
        {
            file << std::string("rename_node gameplay race_bin_15/rewards/reward_cash_bonus1 "
                                "templates/rewards/reward_cash_bonus").append("\n");

            file << std::string("update_field gameplay templates/rewards/reward_cash_bonus Name "
                                "templates/rewards/reward_cash_bonus").append("\n");

            file << std::string("change_vault gameplay templates/rewards/reward_cash_bonus gpcore")
            .append("\n");
        }
    }

    file << std::string("\n");

    file.close();
}

void resetMilestones()
{
    /** This function is meant to be called before randomizing milestones. Deletes all but one
      * of every type of milestone. The remaining milestone nodes are used as templates.             */

    std::ofstream file;
    file.open("Random.nfsms", std::ios_base::app);

    //Header for function call
    file << std::string("# deleting old milestone nodes\n");

    //Tag milestones
    file << std::string("delete_node gameplay milestones/bin_01/challenge_1_cops_damaged\n");
    file << std::string("delete_node gameplay milestones/bin_03/challenge_3_cops_damaged\n");
    file << std::string("delete_node gameplay milestones/bin_04/challenge_4_cops_damaged\n");
    file << std::string("delete_node gameplay milestones/bin_06/challenge_6_cops_damaged\n");
    file << std::string("delete_node gameplay milestones/bin_08/challenge_8_cops_damaged\n");
    file << std::string("delete_node gameplay milestones/bin_09/challenge_9_cops_damaged\n");
    file << std::string("delete_node gameplay milestones/bin_12/challenge_12_cops_damaged\n");
    file << std::string("delete_node gameplay milestones/bin_13/challenge_13_cops_damaged\n");

    //Bounty milestones
    file << std::string("delete_node gameplay milestones/bin_01/challenge_1_cops_destroyed\n");
    file << std::string("delete_node gameplay milestones/bin_03/challenge_3_cops_destroyed\n");
    file << std::string("delete_node gameplay milestones/bin_04/challenge_4_cops_destroyed\n");
    file << std::string("delete_node gameplay milestones/bin_05/challenge_5_cops_destroyed\n");
    file << std::string("delete_node gameplay milestones/bin_07/challenge_7_cops_destroyed\n");
    file << std::string("delete_node gameplay milestones/bin_09/challenge_9_cops_destroyed\n");
    file << std::string("delete_node gameplay milestones/bin_10/challenge_10_cops_destroyed\n");
    file << std::string("delete_node gameplay milestones/bin_13/challenge_13_cops_destroyed\n");

    //Cost-to-state milestones
    file << std::string("delete_node gameplay milestones/bin_02/challenge_2_cost_to_state\n");
    file << std::string("delete_node gameplay milestones/bin_04/challenge_4_cost_to_state\n");
    file << std::string("delete_node gameplay milestones/bin_05/challenge_5_cost_to_state\n");
    file << std::string("delete_node gameplay milestones/bin_07/challenge_7_cost_to_state\n");
    file << std::string("delete_node gameplay milestones/bin_10/challenge_10_cost_to_state\n");
    file << std::string("delete_node gameplay milestones/bin_11/challenge_11_cost_to_state\n");

    //Evasion milestones
    file << std::string("delete_node gameplay milestones/bin_01/challenge_1_pursuit_evasion_time\n");
    file << std::string("delete_node gameplay milestones/bin_03/challenge_3_pursuit_evasion_time\n");
    file << std::string("delete_node gameplay milestones/bin_05/challenge_5_pursuit_evasion_time\n");
    file << std::string("delete_node gameplay milestones/bin_07/challenge_7_pursuit_evasion_time\n");
    file << std::string("delete_node gameplay milestones/bin_09/challenge_9_pursuit_evasion_time\n");
    file << std::string("delete_node gameplay milestones/bin_12/challenge_12_pursuit_evasion_time\n");
    file << std::string("delete_node gameplay milestones/bin_13/challenge_13_pursuit_evasion_time\n");

    //Pursuit length milestones
    file << std::string("delete_node gameplay milestones/bin_01/challenge_1_pursuit_length\n");
    file << std::string("delete_node gameplay milestones/bin_02/challenge_2_pursuit_length\n");
    file << std::string("delete_node gameplay milestones/bin_03/challenge_3_pursuit_length\n");
    file << std::string("delete_node gameplay milestones/bin_06/challenge_6_pursuit_length\n");
    file << std::string("delete_node gameplay milestones/bin_08/challenge_8_pursuit_length\n");
    file << std::string("delete_node gameplay milestones/bin_10/challenge_10_pursuit_length\n");
    file << std::string("delete_node gameplay milestones/bin_12/challenge_12_pursuit_length\n");

    //Roadblock milestones
    file << std::string("delete_node gameplay milestones/bin_02/challenge_2_roadblocks_dodged\n");
    file << std::string("delete_node gameplay milestones/bin_06/challenge_6_roadblocks_dodged\n");
    file << std::string("delete_node gameplay milestones/bin_07/challenge_7_roadblocks_dodged\n");
    file << std::string("delete_node gameplay milestones/bin_09/challenge_9_roadblocks_dodged\n");
    file << std::string("delete_node gameplay milestones/bin_10/challenge_10_roadblocks_dodged\n");

    //Spike strip milestones
    file << std::string("delete_node gameplay milestones/bin_02/challenge_2_tire_spikes_dodged\n");
    file << std::string("delete_node gameplay milestones/bin_05/challenge_5_tire_spikes_dodged\n");
    file << std::string("delete_node gameplay milestones/bin_06/challenge_6_tire_spikes_dodged\n");

    //Infraction milestones
    file << std::string("delete_node gameplay milestones/bin_04/challenge_4_total_infractions\n");
    file << std::string("delete_node gameplay milestones/bin_08/challenge_8_total_infractions\n");
    file << std::string("delete_node gameplay milestones/bin_11/challenge_11_total_infractions\n");

    //Rename remaining milestones to template names
    file << std::string("rename_node gameplay milestones/bin_15/challenge_15_cops_damaged "
                        "milestones/templates/challenge_cops_damaged\n");

    file << std::string("rename_node gameplay milestones/bin_14/challenge_14_cops_destroyed "
                        "milestones/templates/challenge_cops_destroyed\n");

    file << std::string("rename_node gameplay milestones/bin_14/challenge_14_cost_to_state "
                        "milestones/templates/challenge_cost_to_state\n");

    file << std::string("rename_node gameplay milestones/bin_15/challenge_15_pursuit_evasion_time "
                        "milestones/templates/challenge_pursuit_evasion_time\n");

    file << std::string("rename_node gameplay milestones/bin_15/challenge_15_pursuit_length "
                        "milestones/templates/challenge_pursuit_length\n");

    file << std::string("rename_node gameplay milestones/bin_11/challenge_11_roadblocks_dodged "
                        "milestones/templates/challenge_roadblocks_dodged\n");

    file << std::string("rename_node gameplay milestones/bin_08/challenge_8_tire_spikes_dodged "
                        "milestones/templates/challenge_tire_spikes_dodged\n");

    file << std::string("rename_node gameplay milestones/bin_14/challenge_14_total_infractions "
                        "milestones/templates/challenge_total_infractions\n");

    //Add unused cops immobilized milestone
    file << std::string("copy_node gameplay milestone_cops_destroyed milestone milestone_cops_immobilized\n");
    file << std::string("update_field gameplay milestone_cops_immobilized Name milestone_cops_immobilized\n");
    file << std::string("update_field gameplay milestone_cops_immobilized MilestoneName cops_destroyed_in_pursuit\n");
    file << std::string("copy_node gameplay milestones/templates/challenge_cops_destroyed "
                        "milestone_cops_immobilized milestones/templates/challenge_cops_immobilized\n\n");

    file.close();
}

void convertCollectorsEditionRaces()
{
    std::ofstream file;

    file.open("Random.nfsms", std::ios_base::app);

    file << std::string("# converting black edition races to regular races\n");
    file << std::string("delete_field gameplay race_bin_collectors/21_2_2_sprint CollectorsEditionRace\n");
    file << std::string("delete_field gameplay race_bin_collectors/21_2_1_sprint CollectorsEditionRace\n");
    file << std::string("delete_field gameplay race_bin_collectors/21_1_1_circuit CollectorsEditionRace\n");
    file << std::string("add_field gameplay race_bin_collectors/21_1_1_circuit Opponents 3\n");
    file << std::string("add_field gameplay race_bin_collectors/21_2_1_sprint Opponents 3\n");
    file << std::string("add_field gameplay race_bin_collectors/21_2_2_sprint Opponents 3\n");
    file << std::string("update_field gameplay race_bin_collectors gameplayvault gpcore\n\n");

    //All done
    file.close();
}

void createSpeedtrapTemplate()
{
    std::ofstream file;
    file.open("Random.nfsms", std::ios_base::app);

    file << std::string("# copy one of the speedtraps to use as a template for race conversions").append("\n");

    file << std::string("copy_node gameplay race_bin_09/9_5_3_speedtrap_race/speedtrap4 speedtrap_template")
            .append("\n\n");

    file.close();
}

void deleteSpeedtrapTemplate()
{
    std::ofstream file;
    file.open("Random.nfsms", std::ios_base::app);

    file << std::string("# delete the speedtrap template from earlier").append("\n");
    file << std::string("delete_node gameplay speedtrap_template").append("\n\n");

    file.close();
}

void deleteMilestoneTemplates()
{
    /** This function is meant to be called at the end of the program. Deletes all nodes kept as
      * templates from resetMilestones.                                                                 */

    std::ofstream file;
    file.open("Random.nfsms", std::ios_base::app);

    //Header for function call
    file << std::string("# deleting milestone template nodes\n");

    //Rename remaining milestones to template names
    file << std::string("delete_node gameplay milestones/templates/challenge_cops_damaged\n");
    file << std::string("delete_node gameplay milestones/templates/challenge_cops_destroyed\n");
    file << std::string("delete_node gameplay milestones/templates/challenge_cost_to_state\n");
    file << std::string("delete_node gameplay milestones/templates/challenge_pursuit_evasion_time\n");
    file << std::string("delete_node gameplay milestones/templates/challenge_pursuit_length\n");
    file << std::string("delete_node gameplay milestones/templates/challenge_roadblocks_dodged\n");
    file << std::string("delete_node gameplay milestones/templates/challenge_tire_spikes_dodged\n");
    file << std::string("delete_node gameplay milestones/templates/challenge_total_infractions\n");
    file << std::string("delete_node gameplay milestones/templates/challenge_cops_immobilized\n\n");

    file.close();
}

void deleteMarkerTemplates()
{
    //File variables
    std::ofstream file;
    file.open("Random.nfsms", std::ios_base::app);

    file << std::string("# deleting template marker nodes\n");
    file << std::string("delete_node gameplay templates/rewards/reward_add_impound_box").append("\n");
    file << std::string("delete_node gameplay templates/rewards/reward_body").append("\n");
    file << std::string("delete_node gameplay templates/rewards/reward_brakes").append("\n");
    file << std::string("delete_node gameplay templates/rewards/reward_chassis").append("\n");
    file << std::string("delete_node gameplay templates/rewards/reward_engine").append("\n");
    file << std::string("delete_node gameplay templates/rewards/reward_hood").append("\n");
    file << std::string("delete_node gameplay templates/rewards/reward_hud").append("\n");
    file << std::string("delete_node gameplay templates/rewards/reward_induction").append("\n");
    file << std::string("delete_node gameplay templates/rewards/reward_nos").append("\n");
    file << std::string("delete_node gameplay templates/rewards/reward_paint").append("\n");
    file << std::string("delete_node gameplay templates/rewards/reward_rims").append("\n");
    file << std::string("delete_node gameplay templates/rewards/reward_roofscoop").append("\n");
    file << std::string("delete_node gameplay templates/rewards/reward_spoiler").append("\n");
    file << std::string("delete_node gameplay templates/rewards/reward_tires").append("\n");
    file << std::string("delete_node gameplay templates/rewards/reward_transmission").append("\n");
    file << std::string("delete_node gameplay templates/rewards/reward_vinyl").append("\n");
    file << std::string("delete_node gameplay templates/rewards/reward_cash_bonus").append("\n");
    file << std::string("delete_node gameplay templates/rewards/reward_out_of_jail_free").append("\n");
    file << std::string("delete_node gameplay templates/rewards/reward_pink_slip").append("\n");
    file << std::string("delete_node gameplay templates/rewards/reward_release_car_from_impound").append("\n");

    file.close();
}
