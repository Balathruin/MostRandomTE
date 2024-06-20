//
// Created by Ted on 20/06/2024
//

#include <string>
#include <fstream>
#include <vector>
#include <array>
#include "GeneralFunctions.h"
#include "BossRaceMarkerFunctions.h"

void assignWeightsToMarkerTypes(std::pair<int, int>* rangesForMarkerTypeRollsPtr,
    std::pair<int, int>* rangesForRandomMarkersPtr, std::pair<int, int>* rangesForVisualMarkersPtr,
    std::pair<int, int>* rangesForPerformanceMarkersPtr)
{
    //Weights to assign
    int chosenPair;
    std::vector<std::pair<int, int>> possibleRangesForMarkerTypes = { {1, 3}, { 4, 6}, {7, 9} };

    std::vector<std::pair<int, int>*> markerTypePointers = { rangesForRandomMarkersPtr,
        rangesForVisualMarkersPtr, rangesForPerformanceMarkersPtr };

    for ( std::pair<int, int>*& range : markerTypePointers )
    {
        chosenPair = pickRandomNumber(0, static_cast<int>(possibleRangesForMarkerTypes.size()) - 1);
        range->first = possibleRangesForMarkerTypes[chosenPair].first;
        range->second = possibleRangesForMarkerTypes[chosenPair].second;
        possibleRangesForMarkerTypes.erase(possibleRangesForMarkerTypes.begin() + chosenPair);
    }

    rangesForMarkerTypeRollsPtr->first = 1;
    rangesForMarkerTypeRollsPtr->second = 9;
}

void assignWeightsToRandomMarkers(std::pair<int, int>* rangesForRandomMarkerRollsPtr,
    std::pair<int, int>* rangesForOutOfJailFreeMarkerPtr, std::pair<int, int>* rangesForAddImpoundBoxMarkerPtr,
    std::pair<int, int>* rangesForReleaseCarFromImpoundMarkerPtr, std::pair<int, int>* rangesForPinkSlipMarkerPtr,
    std::pair<int, int>* rangesForCashBonusMarkerPtr)
{
    //Weights to assign
    int chosenPair;
    std::vector<std::pair<int, int>> possibleRangesForRandomMarkers =
            { {1, 3}, { 4, 6}, {7, 9}, {10, 12}, {13, 15} };

    std::vector<std::pair<int, int>*> randomMarkerPointers = { rangesForOutOfJailFreeMarkerPtr,
        rangesForAddImpoundBoxMarkerPtr, rangesForReleaseCarFromImpoundMarkerPtr,
        rangesForPinkSlipMarkerPtr, rangesForCashBonusMarkerPtr };

    for ( std::pair<int, int>*& range : randomMarkerPointers )
    {
        chosenPair = pickRandomNumber(0, static_cast<int>(possibleRangesForRandomMarkers.size()) - 1);
        range->first = possibleRangesForRandomMarkers[chosenPair].first;
        range->second = possibleRangesForRandomMarkers[chosenPair].second;
        possibleRangesForRandomMarkers.erase(possibleRangesForRandomMarkers.begin() + chosenPair);
    }

    rangesForRandomMarkerRollsPtr->first = 1;
    rangesForRandomMarkerRollsPtr->second = 15;
}

void assignWeightsToVisualMarkers(std::pair<int, int>* rangesForVisualMarkerRollsPtr,
    std::pair<int, int>* rangesForVinylMarkerPtr, std::pair<int, int>* rangesForRimMarkerPtr,
    std::pair<int, int>* rangesForHoodMarkerPtr, std::pair<int, int>* rangesForForHudMarkerPtr,
    std::pair<int, int>* rangesForBodyMarkerPtr, std::pair<int, int>* rangesForSpoilerMarkerPtr,
    std::pair<int, int>* rangesForRoofscoopMarkerPtr, std::pair<int, int>* rangesForPaintMarkerPtr)
{
    //Weights to assign
    int chosenPair;
    std::vector<std::pair<int, int>> possibleRangesForVisualMarkers =
            { {1, 3}, { 4, 6}, {7, 9}, {10, 12}, {13, 15},
              {16, 18}, {19, 21}, {22, 24} };

    std::vector<std::pair<int, int>*> visualMarkerPointers = { rangesForVinylMarkerPtr,
        rangesForRimMarkerPtr, rangesForHoodMarkerPtr, rangesForForHudMarkerPtr, rangesForBodyMarkerPtr,
        rangesForSpoilerMarkerPtr, rangesForRoofscoopMarkerPtr, rangesForPaintMarkerPtr };

    for ( std::pair<int, int>*& range : visualMarkerPointers )
    {
        chosenPair = pickRandomNumber(0, static_cast<int>(possibleRangesForVisualMarkers.size()) - 1);
        range->first = possibleRangesForVisualMarkers[chosenPair].first;
        range->second = possibleRangesForVisualMarkers[chosenPair].second;
        possibleRangesForVisualMarkers.erase(possibleRangesForVisualMarkers.begin() + chosenPair);
    }

    rangesForVisualMarkerRollsPtr->first = 1;
    rangesForVisualMarkerRollsPtr->second = 24;
}

void assignWeightsToPerformanceMarkers(std::pair<int, int>* rangesForPerformanceMarkerRollsPtr,
        std::pair<int, int>* rangesForBrakeMarkerPtr, std::pair<int, int>* rangesForChassisMarkerPtr,
        std::pair<int, int>* rangesForTransmissionMarkerPtr, std::pair<int, int>* rangesForInductionMarkerPtr,
        std::pair<int, int>* rangesForTireMarkerPtr, std::pair<int, int>* rangesForEngineMarkerPtr,
        std::pair<int, int>* rangesForForNosMarkerPtr)
{
    //Weights to assign
    int chosenPair;
    std::vector<std::pair<int, int>> possibleRangesForPerformanceMarkers =
            { {1, 3}, { 4, 6}, {7, 9}, {10, 12}, {13, 15},
              {16, 18}, {19, 21} };

    std::vector<std::pair<int, int>*> performanceMarkerPointers = { rangesForBrakeMarkerPtr,
        rangesForChassisMarkerPtr, rangesForTransmissionMarkerPtr, rangesForInductionMarkerPtr,
        rangesForTireMarkerPtr, rangesForEngineMarkerPtr, rangesForForNosMarkerPtr };

    for ( std::pair<int, int>*& range : performanceMarkerPointers )
    {
        chosenPair = pickRandomNumber(0, static_cast<int>(possibleRangesForPerformanceMarkers.size()) - 1);
        range->first = possibleRangesForPerformanceMarkers[chosenPair].first;
        range->second = possibleRangesForPerformanceMarkers[chosenPair].second;
        possibleRangesForPerformanceMarkers.erase(possibleRangesForPerformanceMarkers.begin() + chosenPair);
    }

    rangesForPerformanceMarkerRollsPtr->first = 1;
    rangesForPerformanceMarkerRollsPtr->second = 21;
}

std::string createCashMarker(std::ofstream& file, const std::string& raceBin,
                             const std::string& cashMarkersForBoss)
{
    std::string newCashMarkerName =
            std::string(raceBin).append("/rewards/reward_cash_bonus").append(cashMarkersForBoss);

    float medianBase = 7142;
    float multiplier;

    switch ( std::stoi(raceBin.substr(9, 2)) )
    {
        case 15: multiplier = 1; break;
        case 14: multiplier = 1.5; break;
        case 13: multiplier = 2; break;
        case 12: multiplier = 2.5; break;
        case 11: multiplier = 3; break;
        case 10: multiplier = 3.5; break;
        case 9: multiplier = 4; break;
        case 8: multiplier = 4.5; break;
        case 7: multiplier = 5; break;
        case 6: multiplier = 5.5; break;
        case 5: multiplier = 6; break;
        case 4: multiplier = 6.5; break;
        case 3: multiplier = 7; break;
        default: multiplier = 7.5;
    }

    float median = medianBase * multiplier;

    file << std::string("copy_node gameplay templates/rewards/reward_cash_bonus reward_cash_bonus ")
    .append(newCashMarkerName).append("\n");

    file << std::string("update_field gameplay ").append(newCashMarkerName).append(" CashReward ")
    .append(std::to_string(pickRandomNumber(int(median / 2), int(median * 1.5))))
    .append("\n");

    return newCashMarkerName;
}

void randomizeBossMarkers(std::ofstream& file, const std::string& raceBin, const std::string& raceName)
{
    //Create and randomly pick markers for final boss race
    std::array<std::string, 6> chosenMarkers;
    std::string pickedMarker;
    std::string newMarkerName;

    int cashMarkersForThisBoss = 0;
    int numberOfOutOfJailMarkersForThisBoss = 0;
    int numberOfImpoundStrikeMarkersForThisBoss = 0;
    int numberOfPinkSlipMarkersForThisBoss = 0;
    int numberOfImpoundReleaseMarkersForThisBoss = 0;

    int numberOfJunkmanTransmissionMarkersForThisBoss = 0;
    int numberOfJunkmanEngineMarkersForThisBoss = 0;
    int numberOfJunkmanSuspensionMarkersForThisBoss = 0;
    int numberOfJunkmanTireMarkersForThisBoss = 0;
    int numberOfJunkmanBrakeMarkersForThisBoss = 0;
    int numberOfJunkmanTurboMarkersForThisBoss = 0;
    int numberOfJunkmanNOSMarkersForThisBoss = 0;

    int numberOfBodyKitMarkersForThisBoss = 0;
    int numberOfHoodMarkersForThisBoss = 0;
    int numberOfHUDMarkersForThisBoss = 0;
    int numberOfPaintMarkersForThisBoss = 0;
    int numberOfRimMarkersForThisBoss = 0;
    int numberOfRoofscoopMarkersForThisBoss = 0;
    int numberOfSpoilerMarkersForThisBoss = 0;
    int numberOfVinylMarkersForThisBoss = 0;

    //Single variable for rolls
    int rngRoll;

    //Ranges for marker type selection
    std::pair<int, int> rangesForMarkerTypeRolls;
    std::pair<int, int> rangesForRandomMarkers;
    std::pair<int, int> rangesForVisualMarkers;
    std::pair<int, int> rangesForPerformanceMarkers;

    std::pair<int, int>* rangesForMarkerTypeRollsPtr = &rangesForMarkerTypeRolls;
    std::pair<int, int>* rangesForRandomMarkersPtr = &rangesForRandomMarkers;
    std::pair<int, int>* rangesForVisualMarkersPtr = &rangesForVisualMarkers;
    std::pair<int, int>* rangesForPerformanceMarkersPtr = &rangesForPerformanceMarkers;

    //Ranges for random marker selection
    std::pair<int, int> rangesForRandomMarkerRolls;
    std::pair<int, int> rangesForOutOfJailFreeMarker;
    std::pair<int, int> rangesForAddImpoundBoxMarker;
    std::pair<int, int> rangesForReleaseCarFromImpoundMarker;
    std::pair<int, int> rangesForPinkSlipMarker;
    std::pair<int, int> rangesForCashBonusMarker;

    std::pair<int, int>* rangesForRandomMarkerRollsPtr = &rangesForRandomMarkerRolls;
    std::pair<int, int>* rangesForOutOfJailFreeMarkerPtr = &rangesForOutOfJailFreeMarker;
    std::pair<int, int>* rangesForAddImpoundBoxMarkerPtr = &rangesForAddImpoundBoxMarker;
    std::pair<int, int>* rangesForReleaseCarFromImpoundMarkerPtr = &rangesForReleaseCarFromImpoundMarker;
    std::pair<int, int>* rangesForPinkSlipMarkerPtr = &rangesForPinkSlipMarker;
    std::pair<int, int>* rangesForCashBonusMarkerPtr = &rangesForCashBonusMarker;

    //Ranges for visual marker selection
    std::pair<int, int> rangesForVisualMarkerRolls;
    std::pair<int, int> rangesForVinylMarker;
    std::pair<int, int> rangesForRimMarker;
    std::pair<int, int> rangesForHoodMarker;
    std::pair<int, int> rangesForForHudMarker;
    std::pair<int, int> rangesForBodyMarker;
    std::pair<int, int> rangesForSpoilerMarker;
    std::pair<int, int> rangesForRoofscoopMarker;
    std::pair<int, int> rangesForPaintMarker;

    std::pair<int, int>* rangesForVisualMarkerRollsPtr = &rangesForVisualMarkerRolls;
    std::pair<int, int>* rangesForVinylMarkerPtr = &rangesForVinylMarker;
    std::pair<int, int>* rangesForRimMarkerPtr = &rangesForRimMarker;
    std::pair<int, int>* rangesForHoodMarkerPtr = &rangesForHoodMarker;
    std::pair<int, int>* rangesForHudMarkerPtr = &rangesForForHudMarker;
    std::pair<int, int>* rangesForBodyMarkerPtr = &rangesForBodyMarker;
    std::pair<int, int>* rangesForSpoilerMarkerPtr = &rangesForSpoilerMarker;
    std::pair<int, int>* rangesForRoofscoopMarkerPtr = &rangesForRoofscoopMarker;
    std::pair<int, int>* rangesForPaintMarkerPtr = &rangesForPaintMarker;

    //Ranges for performance marker selection
    std::pair<int, int> rangesForPerformanceMarkerRolls;
    std::pair<int, int> rangesForBrakeMarker;
    std::pair<int, int> rangesForChassisMarker;
    std::pair<int, int> rangesForTransmissionMarker;
    std::pair<int, int> rangesForInductionMarker;
    std::pair<int, int> rangesForTireMarker;
    std::pair<int, int> rangesForEngineMarker;
    std::pair<int, int> rangesForForNosMarker;

    std::pair<int, int>* rangesForPerformanceMarkerRollsPtr = &rangesForPerformanceMarkerRolls;
    std::pair<int, int>* rangesForBrakeMarkerPtr = &rangesForBrakeMarker;
    std::pair<int, int>* rangesForChassisMarkerPtr = &rangesForChassisMarker;
    std::pair<int, int>* rangesForTransmissionMarkerPtr = &rangesForTransmissionMarker;
    std::pair<int, int>* rangesForInductionMarkerPtr = &rangesForInductionMarker;
    std::pair<int, int>* rangesForTireMarkerPtr = &rangesForTireMarker;
    std::pair<int, int>* rangesForEngineMarkerPtr = &rangesForEngineMarker;
    std::pair<int, int>* rangesForForNosMarkerPtr = &rangesForForNosMarker;

    assignWeightsToMarkerTypes(rangesForMarkerTypeRollsPtr, rangesForRandomMarkersPtr,
       rangesForVisualMarkersPtr, rangesForPerformanceMarkersPtr);

    assignWeightsToRandomMarkers(rangesForRandomMarkerRollsPtr, rangesForOutOfJailFreeMarkerPtr,
       rangesForAddImpoundBoxMarkerPtr, rangesForReleaseCarFromImpoundMarkerPtr,
       rangesForPinkSlipMarkerPtr, rangesForCashBonusMarkerPtr);

    assignWeightsToVisualMarkers(rangesForVisualMarkerRollsPtr, rangesForVinylMarkerPtr,
       rangesForRimMarkerPtr, rangesForHoodMarkerPtr, rangesForHudMarkerPtr, rangesForBodyMarkerPtr,
       rangesForSpoilerMarkerPtr, rangesForRoofscoopMarkerPtr, rangesForPaintMarkerPtr);

    assignWeightsToPerformanceMarkers(rangesForPerformanceMarkerRollsPtr, rangesForBrakeMarkerPtr,
       rangesForChassisMarkerPtr, rangesForTransmissionMarkerPtr, rangesForInductionMarkerPtr,
       rangesForTireMarkerPtr, rangesForEngineMarkerPtr, rangesForForNosMarkerPtr);

    for ( int markerSelectionLoop = 0; markerSelectionLoop < 6; markerSelectionLoop++ )
    {
        rngRoll = pickRandomNumber(rangesForMarkerTypeRollsPtr->first, rangesForMarkerTypeRollsPtr->second);

        if ( rngRoll >= rangesForRandomMarkersPtr->first && rngRoll <= rangesForRandomMarkersPtr->second )
        {
            rngRoll = 1;
            rangesForMarkerTypeRollsPtr->second--;

            if ( rangesForRandomMarkersPtr->first == rangesForRandomMarkersPtr->second )
            {
                rangesForRandomMarkersPtr->first = 0;
                rangesForRandomMarkersPtr->second = 0;
            }

            else { rangesForRandomMarkersPtr->second--; }

            if ( rangesForVisualMarkersPtr->first > rangesForRandomMarkersPtr->second )
            { rangesForVisualMarkersPtr->first--, rangesForVisualMarkersPtr->second--; }

            if ( rangesForPerformanceMarkersPtr->first > rangesForRandomMarkersPtr->second )
            { rangesForPerformanceMarkersPtr->first--; rangesForPerformanceMarkersPtr->second--; }
        }

        else if ( rngRoll >= rangesForVisualMarkersPtr->first && rngRoll <= rangesForVisualMarkersPtr->second )
        {
            rngRoll = 2;
            rangesForMarkerTypeRollsPtr->second--;

            if ( rangesForVisualMarkersPtr->first == rangesForVisualMarkersPtr->second )
            {
                rangesForVisualMarkersPtr->first = 0;
                rangesForVisualMarkersPtr->second = 0;
            }

            else { rangesForVisualMarkersPtr->second--; }

            if ( rangesForRandomMarkersPtr->first > rangesForVisualMarkersPtr->second )
            { rangesForRandomMarkersPtr->first--, rangesForRandomMarkersPtr->second--; }

            if ( rangesForPerformanceMarkersPtr->first > rangesForVisualMarkersPtr->second )
            { rangesForPerformanceMarkersPtr->first--; rangesForPerformanceMarkersPtr->second--; }
        }

        else
        {
            rngRoll = 3;
            rangesForMarkerTypeRollsPtr->second--;

            if ( rangesForPerformanceMarkersPtr->first == rangesForPerformanceMarkersPtr->second )
            {
                rangesForPerformanceMarkersPtr->first = 0;
                rangesForPerformanceMarkersPtr->second = 0;
            }

            else { rangesForPerformanceMarkersPtr->second--; }

            if ( rangesForRandomMarkersPtr->first > rangesForPerformanceMarkersPtr->second )
            { rangesForRandomMarkersPtr->first--, rangesForRandomMarkersPtr->second--; }

            if ( rangesForVisualMarkersPtr->first > rangesForPerformanceMarkersPtr->second )
            { rangesForVisualMarkersPtr->first--; rangesForVisualMarkersPtr->second--; }
        }

        switch (rngRoll)
        {
            case 1:
                rngRoll = pickRandomNumber(rangesForRandomMarkerRollsPtr->first,
                               rangesForRandomMarkerRollsPtr->second);

                if ( rngRoll >= rangesForOutOfJailFreeMarkerPtr->first &&
                               rngRoll <= rangesForOutOfJailFreeMarkerPtr->second )
                {
                    rangesForRandomMarkerRollsPtr->second--;

                    if ( rangesForOutOfJailFreeMarkerPtr->first == rangesForOutOfJailFreeMarkerPtr->second )
                    {
                        rangesForOutOfJailFreeMarkerPtr->first = 0;
                        rangesForOutOfJailFreeMarkerPtr->second = 0;
                    }

                    else { rangesForOutOfJailFreeMarkerPtr->second--; }

                    if ( rangesForAddImpoundBoxMarkerPtr->first > rangesForOutOfJailFreeMarkerPtr->second )
                    { rangesForAddImpoundBoxMarkerPtr->first--, rangesForAddImpoundBoxMarkerPtr->second--; }

                    if ( rangesForReleaseCarFromImpoundMarkerPtr->first > rangesForOutOfJailFreeMarkerPtr->second )
                    {
                        rangesForReleaseCarFromImpoundMarkerPtr->first--;
                        rangesForReleaseCarFromImpoundMarkerPtr->second--;
                    }

                    if ( rangesForPinkSlipMarkerPtr->first > rangesForOutOfJailFreeMarkerPtr->second )
                    { rangesForPinkSlipMarkerPtr->first--, rangesForPinkSlipMarkerPtr->second--; }

                    if ( rangesForCashBonusMarkerPtr->first > rangesForOutOfJailFreeMarkerPtr->second )
                    { rangesForCashBonusMarkerPtr->first--, rangesForCashBonusMarkerPtr->second--; }

                    pickedMarker = "templates/rewards/reward_out_of_jail_free";
                }

                else if ( rngRoll >= rangesForAddImpoundBoxMarkerPtr->first &&
                               rngRoll <= rangesForAddImpoundBoxMarkerPtr->second )
                {
                    rangesForRandomMarkerRollsPtr->second--;

                    if ( rangesForAddImpoundBoxMarkerPtr->first == rangesForAddImpoundBoxMarkerPtr->second )
                    {
                        rangesForAddImpoundBoxMarkerPtr->first = 0;
                        rangesForAddImpoundBoxMarkerPtr->second = 0;
                    }

                    else { rangesForAddImpoundBoxMarkerPtr->second--; }

                    if ( rangesForOutOfJailFreeMarkerPtr->first > rangesForAddImpoundBoxMarkerPtr->second )
                    { rangesForOutOfJailFreeMarkerPtr->first--, rangesForOutOfJailFreeMarkerPtr->second--; }

                    if ( rangesForReleaseCarFromImpoundMarkerPtr->first > rangesForAddImpoundBoxMarkerPtr->second )
                    {
                        rangesForReleaseCarFromImpoundMarkerPtr->first--;
                        rangesForReleaseCarFromImpoundMarkerPtr->second--;
                    }

                    if ( rangesForPinkSlipMarkerPtr->first > rangesForAddImpoundBoxMarkerPtr->second )
                    { rangesForPinkSlipMarkerPtr->first--, rangesForPinkSlipMarkerPtr->second--; }

                    if ( rangesForCashBonusMarkerPtr->first > rangesForAddImpoundBoxMarkerPtr->second )
                    { rangesForCashBonusMarkerPtr->first--, rangesForCashBonusMarkerPtr->second--; }

                    pickedMarker = "templates/rewards/reward_add_impound_box";
                }

                else if ( rngRoll >= rangesForReleaseCarFromImpoundMarkerPtr->first &&
                               rngRoll <= rangesForReleaseCarFromImpoundMarkerPtr->second )
                {
                    rangesForRandomMarkerRollsPtr->second--;

                    if ( rangesForReleaseCarFromImpoundMarkerPtr->first ==
                         rangesForReleaseCarFromImpoundMarkerPtr->second )
                    {
                        rangesForReleaseCarFromImpoundMarkerPtr->first = 0;
                        rangesForReleaseCarFromImpoundMarkerPtr->second = 0;
                    }

                    else { rangesForReleaseCarFromImpoundMarkerPtr->second--; }

                    if ( rangesForOutOfJailFreeMarkerPtr->first > rangesForReleaseCarFromImpoundMarkerPtr->second )
                    { rangesForOutOfJailFreeMarkerPtr->first--, rangesForOutOfJailFreeMarkerPtr->second--; }

                    if ( rangesForAddImpoundBoxMarkerPtr->first > rangesForReleaseCarFromImpoundMarkerPtr->second )
                    { rangesForAddImpoundBoxMarkerPtr->first--, rangesForAddImpoundBoxMarkerPtr->second--; }

                    if ( rangesForPinkSlipMarkerPtr->first > rangesForReleaseCarFromImpoundMarkerPtr->second )
                    { rangesForPinkSlipMarkerPtr->first--, rangesForPinkSlipMarkerPtr->second--; }

                    if ( rangesForCashBonusMarkerPtr->first > rangesForReleaseCarFromImpoundMarkerPtr->second )
                    { rangesForCashBonusMarkerPtr->first--, rangesForCashBonusMarkerPtr->second--; }

                    pickedMarker = "templates/rewards/reward_release_car_from_impound";
                }

                else if ( rngRoll >= rangesForPinkSlipMarkerPtr->first &&
                               rngRoll <= rangesForPinkSlipMarkerPtr->second )
                {
                    rangesForRandomMarkerRollsPtr->second--;

                    if ( rangesForPinkSlipMarkerPtr->first == rangesForPinkSlipMarkerPtr->second )
                    {
                        rangesForPinkSlipMarkerPtr->first = 0;
                        rangesForPinkSlipMarkerPtr->second = 0;
                    }

                    else { rangesForPinkSlipMarkerPtr->second--; }

                    if ( rangesForOutOfJailFreeMarkerPtr->first > rangesForPinkSlipMarkerPtr->second )
                    { rangesForOutOfJailFreeMarkerPtr->first--, rangesForOutOfJailFreeMarkerPtr->second--; }

                    if ( rangesForAddImpoundBoxMarkerPtr->first > rangesForPinkSlipMarkerPtr->second )
                    { rangesForAddImpoundBoxMarkerPtr->first--, rangesForAddImpoundBoxMarkerPtr->second--; }

                    if ( rangesForReleaseCarFromImpoundMarkerPtr->first > rangesForPinkSlipMarkerPtr->second )
                    {
                        rangesForReleaseCarFromImpoundMarkerPtr->first--;
                        rangesForReleaseCarFromImpoundMarkerPtr->second--;
                    }

                    if ( rangesForCashBonusMarkerPtr->first > rangesForPinkSlipMarkerPtr->second )
                    { rangesForCashBonusMarkerPtr->first--, rangesForCashBonusMarkerPtr->second--; }

                    pickedMarker = "templates/rewards/reward_pink_slip";
                }

                else
                {
                    cashMarkersForThisBoss++;
                    rangesForRandomMarkerRollsPtr->second--;

                    if ( rangesForCashBonusMarkerPtr->first == rangesForCashBonusMarkerPtr->second )
                    {
                        rangesForCashBonusMarkerPtr->first = 0;
                        rangesForCashBonusMarkerPtr->second = 0;
                    }

                    else { rangesForCashBonusMarkerPtr->second--; }

                    if ( rangesForOutOfJailFreeMarkerPtr->first > rangesForCashBonusMarkerPtr->second )
                    { rangesForOutOfJailFreeMarkerPtr->first--, rangesForOutOfJailFreeMarkerPtr->second--; }

                    if ( rangesForAddImpoundBoxMarkerPtr->first > rangesForCashBonusMarkerPtr->second )
                    { rangesForAddImpoundBoxMarkerPtr->first--, rangesForAddImpoundBoxMarkerPtr->second--; }

                    if ( rangesForReleaseCarFromImpoundMarkerPtr->first > rangesForCashBonusMarkerPtr->second )
                    {
                        rangesForReleaseCarFromImpoundMarkerPtr->first--;
                        rangesForReleaseCarFromImpoundMarkerPtr->second--;
                    }

                    if ( rangesForPinkSlipMarkerPtr->first > rangesForCashBonusMarkerPtr->second )
                    { rangesForPinkSlipMarkerPtr->first--, rangesForPinkSlipMarkerPtr->second--; }

                    pickedMarker = "templates/rewards/reward_cash_bonus";
                    chosenMarkers[markerSelectionLoop] = std::string(createCashMarker
                           (file, raceBin, std::to_string(cashMarkersForThisBoss)));
                }

                if ( pickedMarker != "templates/rewards/reward_cash_bonus" )
                { chosenMarkers[markerSelectionLoop] = pickedMarker; }
                break;

            case 2:
                rngRoll = pickRandomNumber(rangesForVisualMarkerRollsPtr->first,
                               rangesForVisualMarkerRollsPtr->second);

                if ( rngRoll >= rangesForVinylMarkerPtr->first && rngRoll <= rangesForVinylMarkerPtr->second )
                {
                    rangesForVisualMarkerRollsPtr->second--;

                    if ( rangesForVinylMarkerPtr->first == rangesForVinylMarkerPtr->second )
                    {
                        rangesForVinylMarkerPtr->first = 0;
                        rangesForVinylMarkerPtr->second = 0;
                    }

                    else { rangesForVinylMarkerPtr->second--; }

                    if ( rangesForRimMarkerPtr->first > rangesForVinylMarkerPtr->second )
                    { rangesForRimMarkerPtr->first--, rangesForRimMarkerPtr->second--; }

                    if ( rangesForHoodMarkerPtr->first > rangesForVinylMarkerPtr->second )
                    { rangesForHoodMarkerPtr->first--; rangesForHoodMarkerPtr->second--; }

                    if ( rangesForHudMarkerPtr->first > rangesForVinylMarkerPtr->second )
                    { rangesForHudMarkerPtr->first--, rangesForHudMarkerPtr->second--; }

                    if ( rangesForBodyMarkerPtr->first > rangesForVinylMarkerPtr->second )
                    { rangesForBodyMarkerPtr->first--; rangesForBodyMarkerPtr->second--; }

                    if ( rangesForSpoilerMarkerPtr->first > rangesForVinylMarkerPtr->second )
                    { rangesForSpoilerMarkerPtr->first--; rangesForSpoilerMarkerPtr->second--; }

                    if ( rangesForRoofscoopMarkerPtr->first > rangesForVinylMarkerPtr->second )
                    { rangesForRoofscoopMarkerPtr->first--, rangesForRoofscoopMarkerPtr->second--; }

                    if ( rangesForPaintMarkerPtr->first > rangesForVinylMarkerPtr->second )
                    { rangesForPaintMarkerPtr->first--; rangesForPaintMarkerPtr->second--; }

                    pickedMarker = "templates/rewards/reward_vinyl";
                }

                else if ( rngRoll >= rangesForRimMarkerPtr->first && rngRoll <= rangesForRimMarkerPtr->second )
                {
                    rangesForVisualMarkerRollsPtr->second--;

                    if ( rangesForRimMarkerPtr->first == rangesForRimMarkerPtr->second )
                    {
                        rangesForRimMarkerPtr->first = 0;
                        rangesForRimMarkerPtr->second = 0;
                    }

                    else { rangesForRimMarkerPtr->second--; }

                    if ( rangesForVinylMarkerPtr->first > rangesForRimMarkerPtr->second )
                    { rangesForVinylMarkerPtr->first--, rangesForVinylMarkerPtr->second--; }

                    if ( rangesForHoodMarkerPtr->first > rangesForRimMarkerPtr->second )
                    { rangesForHoodMarkerPtr->first--; rangesForHoodMarkerPtr->second--; }

                    if ( rangesForHudMarkerPtr->first > rangesForRimMarkerPtr->second )
                    { rangesForHudMarkerPtr->first--, rangesForHudMarkerPtr->second--; }

                    if ( rangesForBodyMarkerPtr->first > rangesForRimMarkerPtr->second )
                    { rangesForBodyMarkerPtr->first--; rangesForBodyMarkerPtr->second--; }

                    if ( rangesForSpoilerMarkerPtr->first > rangesForRimMarkerPtr->second )
                    { rangesForSpoilerMarkerPtr->first--; rangesForSpoilerMarkerPtr->second--; }

                    if ( rangesForRoofscoopMarkerPtr->first > rangesForRimMarkerPtr->second )
                    { rangesForRoofscoopMarkerPtr->first--, rangesForRoofscoopMarkerPtr->second--; }

                    if ( rangesForPaintMarkerPtr->first > rangesForRimMarkerPtr->second )
                    { rangesForPaintMarkerPtr->first--; rangesForPaintMarkerPtr->second--; }

                    pickedMarker = "templates/rewards/reward_rims";
                }

                else if ( rngRoll >= rangesForHoodMarkerPtr->first && rngRoll <= rangesForHoodMarkerPtr->second )
                {
                    rangesForVisualMarkerRollsPtr->second--;

                    if ( rangesForHoodMarkerPtr->first == rangesForHoodMarkerPtr->second )
                    {
                        rangesForHoodMarkerPtr->first = 0;
                        rangesForHoodMarkerPtr->second = 0;
                    }

                    else { rangesForHoodMarkerPtr->second--; }

                    if ( rangesForVinylMarkerPtr->first > rangesForHoodMarkerPtr->second )
                    { rangesForVinylMarkerPtr->first--, rangesForVinylMarkerPtr->second--; }

                    if ( rangesForRimMarkerPtr->first > rangesForHoodMarkerPtr->second )
                    { rangesForRimMarkerPtr->first--; rangesForRimMarkerPtr->second--; }

                    if ( rangesForHudMarkerPtr->first > rangesForHoodMarkerPtr->second )
                    { rangesForHudMarkerPtr->first--, rangesForHudMarkerPtr->second--; }

                    if ( rangesForBodyMarkerPtr->first > rangesForHoodMarkerPtr->second )
                    { rangesForBodyMarkerPtr->first--; rangesForBodyMarkerPtr->second--; }

                    if ( rangesForSpoilerMarkerPtr->first > rangesForHoodMarkerPtr->second )
                    { rangesForSpoilerMarkerPtr->first--; rangesForSpoilerMarkerPtr->second--; }

                    if ( rangesForRoofscoopMarkerPtr->first > rangesForHoodMarkerPtr->second )
                    { rangesForRoofscoopMarkerPtr->first--, rangesForRoofscoopMarkerPtr->second--; }

                    if ( rangesForPaintMarkerPtr->first > rangesForHoodMarkerPtr->second )
                    { rangesForPaintMarkerPtr->first--; rangesForPaintMarkerPtr->second--; }

                    pickedMarker = "templates/rewards/reward_hood";
                }

                else if ( rngRoll >= rangesForHudMarkerPtr->first && rngRoll <= rangesForHudMarkerPtr->second )
                {
                    rangesForVisualMarkerRollsPtr->second--;

                    if ( rangesForHudMarkerPtr->first == rangesForHudMarkerPtr->second )
                    {
                        rangesForHudMarkerPtr->first = 0;
                        rangesForHudMarkerPtr->second = 0;
                    }

                    else { rangesForHudMarkerPtr->second--; }

                    if ( rangesForVinylMarkerPtr->first > rangesForHudMarkerPtr->second )
                    { rangesForVinylMarkerPtr->first--, rangesForVinylMarkerPtr->second--; }

                    if ( rangesForRimMarkerPtr->first > rangesForHudMarkerPtr->second )
                    { rangesForRimMarkerPtr->first--; rangesForRimMarkerPtr->second--; }

                    if ( rangesForHoodMarkerPtr->first > rangesForHudMarkerPtr->second )
                    { rangesForHoodMarkerPtr->first--, rangesForHoodMarkerPtr->second--; }

                    if ( rangesForBodyMarkerPtr->first > rangesForHudMarkerPtr->second )
                    { rangesForBodyMarkerPtr->first--; rangesForBodyMarkerPtr->second--; }

                    if ( rangesForSpoilerMarkerPtr->first > rangesForHudMarkerPtr->second )
                    { rangesForSpoilerMarkerPtr->first--; rangesForSpoilerMarkerPtr->second--; }

                    if ( rangesForRoofscoopMarkerPtr->first > rangesForHudMarkerPtr->second )
                    { rangesForRoofscoopMarkerPtr->first--, rangesForRoofscoopMarkerPtr->second--; }

                    if ( rangesForPaintMarkerPtr->first > rangesForHudMarkerPtr->second )
                    { rangesForPaintMarkerPtr->first--; rangesForPaintMarkerPtr->second--; }

                    pickedMarker = "templates/rewards/reward_hud";
                }

                else if ( rngRoll >= rangesForBodyMarkerPtr->first && rngRoll <= rangesForBodyMarkerPtr->second )
                {
                    rangesForVisualMarkerRollsPtr->second--;

                    if ( rangesForBodyMarkerPtr->first == rangesForBodyMarkerPtr->second )
                    {
                        rangesForBodyMarkerPtr->first = 0;
                        rangesForBodyMarkerPtr->second = 0;
                    }

                    else { rangesForBodyMarkerPtr->second--; }

                    if ( rangesForVinylMarkerPtr->first > rangesForBodyMarkerPtr->second )
                    { rangesForVinylMarkerPtr->first--, rangesForVinylMarkerPtr->second--; }

                    if ( rangesForRimMarkerPtr->first > rangesForBodyMarkerPtr->second )
                    { rangesForRimMarkerPtr->first--; rangesForRimMarkerPtr->second--; }

                    if ( rangesForHoodMarkerPtr->first > rangesForBodyMarkerPtr->second )
                    { rangesForHoodMarkerPtr->first--, rangesForHoodMarkerPtr->second--; }

                    if ( rangesForHudMarkerPtr->first > rangesForBodyMarkerPtr->second )
                    { rangesForHudMarkerPtr->first--; rangesForHudMarkerPtr->second--; }

                    if ( rangesForSpoilerMarkerPtr->first > rangesForBodyMarkerPtr->second )
                    { rangesForSpoilerMarkerPtr->first--; rangesForSpoilerMarkerPtr->second--; }

                    if ( rangesForRoofscoopMarkerPtr->first > rangesForBodyMarkerPtr->second )
                    { rangesForRoofscoopMarkerPtr->first--, rangesForRoofscoopMarkerPtr->second--; }

                    if ( rangesForPaintMarkerPtr->first > rangesForBodyMarkerPtr->second )
                    { rangesForPaintMarkerPtr->first--; rangesForPaintMarkerPtr->second--; }

                    pickedMarker = "templates/rewards/reward_body";
                }

                else if ( rngRoll >= rangesForSpoilerMarkerPtr->first && rngRoll <= rangesForSpoilerMarkerPtr->second )
                {
                    rangesForVisualMarkerRollsPtr->second--;

                    if ( rangesForSpoilerMarkerPtr->first == rangesForSpoilerMarkerPtr->second )
                    {
                        rangesForSpoilerMarkerPtr->first = 0;
                        rangesForSpoilerMarkerPtr->second = 0;
                    }

                    else { rangesForSpoilerMarkerPtr->second--; }

                    if ( rangesForVinylMarkerPtr->first > rangesForSpoilerMarkerPtr->second )
                    { rangesForVinylMarkerPtr->first--, rangesForVinylMarkerPtr->second--; }

                    if ( rangesForRimMarkerPtr->first > rangesForSpoilerMarkerPtr->second )
                    { rangesForRimMarkerPtr->first--; rangesForRimMarkerPtr->second--; }

                    if ( rangesForHoodMarkerPtr->first > rangesForSpoilerMarkerPtr->second )
                    { rangesForHoodMarkerPtr->first--, rangesForHoodMarkerPtr->second--; }

                    if ( rangesForHudMarkerPtr->first > rangesForSpoilerMarkerPtr->second )
                    { rangesForHudMarkerPtr->first--; rangesForHudMarkerPtr->second--; }

                    if ( rangesForBodyMarkerPtr->first > rangesForSpoilerMarkerPtr->second )
                    { rangesForBodyMarkerPtr->first--; rangesForBodyMarkerPtr->second--; }

                    if ( rangesForRoofscoopMarkerPtr->first > rangesForSpoilerMarkerPtr->second )
                    { rangesForRoofscoopMarkerPtr->first--, rangesForRoofscoopMarkerPtr->second--; }

                    if ( rangesForPaintMarkerPtr->first > rangesForSpoilerMarkerPtr->second )
                    { rangesForPaintMarkerPtr->first--; rangesForPaintMarkerPtr->second--; }

                    pickedMarker = "templates/rewards/reward_spoiler";
                }

                else if ( rngRoll >= rangesForRoofscoopMarkerPtr->first &&
                               rngRoll <= rangesForRoofscoopMarkerPtr->second )
                {
                    rangesForVisualMarkerRollsPtr->second--;

                    if ( rangesForRoofscoopMarkerPtr->first == rangesForRoofscoopMarkerPtr->second )
                    {
                        rangesForRoofscoopMarkerPtr->first = 0;
                        rangesForRoofscoopMarkerPtr->second = 0;
                    }

                    else { rangesForRoofscoopMarkerPtr->second--; }

                    if ( rangesForVinylMarkerPtr->first > rangesForRoofscoopMarkerPtr->second )
                    { rangesForVinylMarkerPtr->first--, rangesForVinylMarkerPtr->second--; }

                    if ( rangesForRimMarkerPtr->first > rangesForRoofscoopMarkerPtr->second )
                    { rangesForRimMarkerPtr->first--; rangesForRimMarkerPtr->second--; }

                    if ( rangesForHoodMarkerPtr->first > rangesForRoofscoopMarkerPtr->second )
                    { rangesForHoodMarkerPtr->first--, rangesForHoodMarkerPtr->second--; }

                    if ( rangesForHudMarkerPtr->first > rangesForRoofscoopMarkerPtr->second )
                    { rangesForHudMarkerPtr->first--; rangesForHudMarkerPtr->second--; }

                    if ( rangesForBodyMarkerPtr->first > rangesForRoofscoopMarkerPtr->second )
                    { rangesForBodyMarkerPtr->first--; rangesForBodyMarkerPtr->second--; }

                    if ( rangesForSpoilerMarkerPtr->first > rangesForRoofscoopMarkerPtr->second )
                    { rangesForSpoilerMarkerPtr->first--, rangesForSpoilerMarkerPtr->second--; }

                    if ( rangesForPaintMarkerPtr->first > rangesForRoofscoopMarkerPtr->second )
                    { rangesForPaintMarkerPtr->first--; rangesForPaintMarkerPtr->second--; }

                    pickedMarker = "templates/rewards/reward_roofscoop";
                }

                else
                {
                    rangesForVisualMarkerRollsPtr->second--;

                    if ( rangesForPaintMarkerPtr->first == rangesForPaintMarkerPtr->second )
                    {
                        rangesForPaintMarkerPtr->first = 0;
                        rangesForPaintMarkerPtr->second = 0;
                    }

                    else { rangesForPaintMarkerPtr->second--; }

                    if ( rangesForVinylMarkerPtr->first > rangesForPaintMarkerPtr->second )
                    { rangesForVinylMarkerPtr->first--, rangesForVinylMarkerPtr->second--; }

                    if ( rangesForRimMarkerPtr->first > rangesForPaintMarkerPtr->second )
                    { rangesForRimMarkerPtr->first--; rangesForRimMarkerPtr->second--; }

                    if ( rangesForHoodMarkerPtr->first > rangesForPaintMarkerPtr->second )
                    { rangesForHoodMarkerPtr->first--, rangesForHoodMarkerPtr->second--; }

                    if ( rangesForHudMarkerPtr->first > rangesForPaintMarkerPtr->second )
                    { rangesForHudMarkerPtr->first--; rangesForHudMarkerPtr->second--; }

                    if ( rangesForBodyMarkerPtr->first > rangesForPaintMarkerPtr->second )
                    { rangesForBodyMarkerPtr->first--; rangesForBodyMarkerPtr->second--; }

                    if ( rangesForSpoilerMarkerPtr->first > rangesForPaintMarkerPtr->second )
                    { rangesForSpoilerMarkerPtr->first--, rangesForSpoilerMarkerPtr->second--; }

                    if ( rangesForRoofscoopMarkerPtr->first > rangesForPaintMarkerPtr->second )
                    { rangesForRoofscoopMarkerPtr->first--; rangesForRoofscoopMarkerPtr->second--; }

                    pickedMarker = "templates/rewards/reward_paint";
                }

                chosenMarkers[markerSelectionLoop] = pickedMarker;
                break;

            default:
                rngRoll = pickRandomNumber(rangesForPerformanceMarkerRollsPtr->first,
                                rangesForPerformanceMarkerRollsPtr->second);

                if ( rngRoll >= rangesForBrakeMarkerPtr->first && rngRoll <= rangesForBrakeMarkerPtr->second )
                {
                    rangesForPerformanceMarkerRollsPtr->second--;

                    if ( rangesForBrakeMarkerPtr->first == rangesForBrakeMarkerPtr->second )
                    {
                        rangesForBrakeMarkerPtr->first = 0;
                        rangesForBrakeMarkerPtr->second = 0;
                    }

                    else { rangesForBrakeMarkerPtr->second--; }

                    if ( rangesForChassisMarkerPtr->first > rangesForBrakeMarkerPtr->second )
                    { rangesForChassisMarkerPtr->first--, rangesForChassisMarkerPtr->second--; }

                    if ( rangesForTransmissionMarkerPtr->first > rangesForBrakeMarkerPtr->second )
                    { rangesForTransmissionMarkerPtr->first--; rangesForTransmissionMarkerPtr->second--; }

                    if ( rangesForInductionMarkerPtr->first > rangesForBrakeMarkerPtr->second )
                    { rangesForInductionMarkerPtr->first--, rangesForInductionMarkerPtr->second--; }

                    if ( rangesForTireMarkerPtr->first > rangesForBrakeMarkerPtr->second )
                    { rangesForTireMarkerPtr->first--; rangesForTireMarkerPtr->second--; }

                    if ( rangesForEngineMarkerPtr->first > rangesForBrakeMarkerPtr->second )
                    { rangesForEngineMarkerPtr->first--; rangesForEngineMarkerPtr->second--; }

                    if ( rangesForForNosMarkerPtr->first > rangesForBrakeMarkerPtr->second )
                    { rangesForForNosMarkerPtr->first--, rangesForForNosMarkerPtr->second--; }

                    pickedMarker = "templates/rewards/reward_brakes";
                }

                else if ( rngRoll >= rangesForChassisMarkerPtr->first && rngRoll <= rangesForChassisMarkerPtr->second )
                {
                    rangesForPerformanceMarkerRollsPtr->second--;

                    if ( rangesForChassisMarkerPtr->first == rangesForChassisMarkerPtr->second )
                    {
                        rangesForChassisMarkerPtr->first = 0;
                        rangesForChassisMarkerPtr->second = 0;
                    }

                    else { rangesForChassisMarkerPtr->second--; }

                    if ( rangesForBrakeMarkerPtr->first > rangesForChassisMarkerPtr->second )
                    { rangesForBrakeMarkerPtr->first--, rangesForBrakeMarkerPtr->second--; }

                    if ( rangesForTransmissionMarkerPtr->first > rangesForChassisMarkerPtr->second )
                    { rangesForTransmissionMarkerPtr->first--; rangesForTransmissionMarkerPtr->second--; }

                    if ( rangesForInductionMarkerPtr->first > rangesForChassisMarkerPtr->second )
                    { rangesForInductionMarkerPtr->first--, rangesForInductionMarkerPtr->second--; }

                    if ( rangesForTireMarkerPtr->first > rangesForChassisMarkerPtr->second )
                    { rangesForTireMarkerPtr->first--; rangesForTireMarkerPtr->second--; }

                    if ( rangesForEngineMarkerPtr->first > rangesForChassisMarkerPtr->second )
                    { rangesForEngineMarkerPtr->first--; rangesForEngineMarkerPtr->second--; }

                    if ( rangesForForNosMarkerPtr->first > rangesForChassisMarkerPtr->second )
                    { rangesForForNosMarkerPtr->first--, rangesForForNosMarkerPtr->second--; }

                    pickedMarker = "templates/rewards/reward_chassis";
                }

                else if ( rngRoll >= rangesForTransmissionMarkerPtr->first &&
                               rngRoll <= rangesForTransmissionMarkerPtr->second )
                {
                    rangesForPerformanceMarkerRollsPtr->second--;

                    if ( rangesForTransmissionMarkerPtr->first == rangesForTransmissionMarkerPtr->second )
                    {
                        rangesForTransmissionMarkerPtr->first = 0;
                        rangesForTransmissionMarkerPtr->second = 0;
                    }

                    else { rangesForTransmissionMarkerPtr->second--; }

                    if ( rangesForBrakeMarkerPtr->first > rangesForTransmissionMarkerPtr->second )
                    { rangesForBrakeMarkerPtr->first--, rangesForBrakeMarkerPtr->second--; }

                    if ( rangesForChassisMarkerPtr->first > rangesForTransmissionMarkerPtr->second )
                    { rangesForChassisMarkerPtr->first--; rangesForChassisMarkerPtr->second--; }

                    if ( rangesForInductionMarkerPtr->first > rangesForTransmissionMarkerPtr->second )
                    { rangesForInductionMarkerPtr->first--, rangesForInductionMarkerPtr->second--; }

                    if ( rangesForTireMarkerPtr->first > rangesForTransmissionMarkerPtr->second )
                    { rangesForTireMarkerPtr->first--; rangesForTireMarkerPtr->second--; }

                    if ( rangesForEngineMarkerPtr->first > rangesForTransmissionMarkerPtr->second )
                    { rangesForEngineMarkerPtr->first--; rangesForEngineMarkerPtr->second--; }

                    if ( rangesForForNosMarkerPtr->first > rangesForTransmissionMarkerPtr->second )
                    { rangesForForNosMarkerPtr->first--, rangesForForNosMarkerPtr->second--; }

                    pickedMarker = "templates/rewards/reward_transmission";
                }

                else if ( rngRoll >= rangesForInductionMarkerPtr->first && rngRoll <= rangesForInductionMarkerPtr->second )
                {
                    rangesForPerformanceMarkerRollsPtr->second--;

                    if ( rangesForInductionMarkerPtr->first == rangesForInductionMarkerPtr->second )
                    {
                        rangesForInductionMarkerPtr->first = 0;
                        rangesForInductionMarkerPtr->second = 0;
                    }

                    else { rangesForInductionMarkerPtr->second--; }

                    if ( rangesForBrakeMarkerPtr->first > rangesForInductionMarkerPtr->second )
                    { rangesForBrakeMarkerPtr->first--, rangesForBrakeMarkerPtr->second--; }

                    if ( rangesForChassisMarkerPtr->first > rangesForInductionMarkerPtr->second )
                    { rangesForChassisMarkerPtr->first--; rangesForChassisMarkerPtr->second--; }

                    if ( rangesForTransmissionMarkerPtr->first > rangesForInductionMarkerPtr->second )
                    { rangesForTransmissionMarkerPtr->first--, rangesForTransmissionMarkerPtr->second--; }

                    if ( rangesForTireMarkerPtr->first > rangesForInductionMarkerPtr->second )
                    { rangesForTireMarkerPtr->first--; rangesForTireMarkerPtr->second--; }

                    if ( rangesForEngineMarkerPtr->first > rangesForInductionMarkerPtr->second )
                    { rangesForEngineMarkerPtr->first--; rangesForEngineMarkerPtr->second--; }

                    if ( rangesForForNosMarkerPtr->first > rangesForInductionMarkerPtr->second )
                    { rangesForForNosMarkerPtr->first--, rangesForForNosMarkerPtr->second--; }

                    pickedMarker = "templates/rewards/reward_induction";
                }

                else if ( rngRoll >= rangesForTireMarkerPtr->first && rngRoll <= rangesForTireMarkerPtr->second )
                {
                    rangesForPerformanceMarkerRollsPtr->second--;

                    if ( rangesForTireMarkerPtr->first == rangesForTireMarkerPtr->second )
                    {
                        rangesForTireMarkerPtr->first = 0;
                        rangesForTireMarkerPtr->second = 0;
                    }

                    else { rangesForTireMarkerPtr->second--; }

                    if ( rangesForBrakeMarkerPtr->first > rangesForTireMarkerPtr->second )
                    { rangesForBrakeMarkerPtr->first--, rangesForBrakeMarkerPtr->second--; }

                    if ( rangesForChassisMarkerPtr->first > rangesForTireMarkerPtr->second )
                    { rangesForChassisMarkerPtr->first--; rangesForChassisMarkerPtr->second--; }

                    if ( rangesForTransmissionMarkerPtr->first > rangesForTireMarkerPtr->second )
                    { rangesForTransmissionMarkerPtr->first--, rangesForTransmissionMarkerPtr->second--; }

                    if ( rangesForInductionMarkerPtr->first > rangesForTireMarkerPtr->second )
                    { rangesForInductionMarkerPtr->first--; rangesForInductionMarkerPtr->second--; }

                    if ( rangesForEngineMarkerPtr->first > rangesForTireMarkerPtr->second )
                    { rangesForEngineMarkerPtr->first--; rangesForEngineMarkerPtr->second--; }

                    if ( rangesForForNosMarkerPtr->first > rangesForTireMarkerPtr->second )
                    { rangesForForNosMarkerPtr->first--, rangesForForNosMarkerPtr->second--; }

                    pickedMarker = "templates/rewards/reward_tires";
                }

                else if ( rngRoll >= rangesForEngineMarkerPtr->first && rngRoll <= rangesForEngineMarkerPtr->second )
                {
                    rangesForPerformanceMarkerRollsPtr->second--;

                    if ( rangesForEngineMarkerPtr->first == rangesForEngineMarkerPtr->second )
                    {
                        rangesForEngineMarkerPtr->first = 0;
                        rangesForEngineMarkerPtr->second = 0;
                    }

                    else { rangesForEngineMarkerPtr->second--; }

                    if ( rangesForBrakeMarkerPtr->first > rangesForEngineMarkerPtr->second )
                    { rangesForBrakeMarkerPtr->first--, rangesForBrakeMarkerPtr->second--; }

                    if ( rangesForChassisMarkerPtr->first > rangesForEngineMarkerPtr->second )
                    { rangesForChassisMarkerPtr->first--; rangesForChassisMarkerPtr->second--; }

                    if ( rangesForTransmissionMarkerPtr->first > rangesForEngineMarkerPtr->second )
                    { rangesForTransmissionMarkerPtr->first--, rangesForTransmissionMarkerPtr->second--; }

                    if ( rangesForInductionMarkerPtr->first > rangesForEngineMarkerPtr->second )
                    { rangesForInductionMarkerPtr->first--; rangesForInductionMarkerPtr->second--; }

                    if ( rangesForTireMarkerPtr->first > rangesForEngineMarkerPtr->second )
                    { rangesForTireMarkerPtr->first--; rangesForTireMarkerPtr->second--; }

                    if ( rangesForForNosMarkerPtr->first > rangesForEngineMarkerPtr->second )
                    { rangesForForNosMarkerPtr->first--, rangesForForNosMarkerPtr->second--; }

                    pickedMarker = "templates/rewards/reward_engine";
                }

                else
                {
                    rangesForPerformanceMarkerRollsPtr->second--;

                    if ( rangesForForNosMarkerPtr->first == rangesForForNosMarkerPtr->second )
                    {
                        rangesForForNosMarkerPtr->first = 0;
                        rangesForForNosMarkerPtr->second = 0;
                    }

                    else { rangesForForNosMarkerPtr->second--; }

                    if ( rangesForBrakeMarkerPtr->first > rangesForForNosMarkerPtr->second )
                    { rangesForBrakeMarkerPtr->first--, rangesForBrakeMarkerPtr->second--; }

                    if ( rangesForChassisMarkerPtr->first > rangesForForNosMarkerPtr->second )
                    { rangesForChassisMarkerPtr->first--; rangesForChassisMarkerPtr->second--; }

                    if ( rangesForTransmissionMarkerPtr->first > rangesForForNosMarkerPtr->second )
                    { rangesForTransmissionMarkerPtr->first--, rangesForTransmissionMarkerPtr->second--; }

                    if ( rangesForInductionMarkerPtr->first > rangesForForNosMarkerPtr->second )
                    { rangesForInductionMarkerPtr->first--; rangesForInductionMarkerPtr->second--; }

                    if ( rangesForTireMarkerPtr->first > rangesForForNosMarkerPtr->second )
                    { rangesForTireMarkerPtr->first--; rangesForTireMarkerPtr->second--; }

                    if ( rangesForEngineMarkerPtr->first > rangesForForNosMarkerPtr->second )
                    { rangesForEngineMarkerPtr->first--, rangesForEngineMarkerPtr->second--; }

                    pickedMarker = "templates/rewards/reward_nos";
                }

                chosenMarkers[markerSelectionLoop] = pickedMarker;
        }
    }

    for ( int rewardsLoop = 0; rewardsLoop < 6; rewardsLoop++ )
    {
        //Junkman parts first
        if ( chosenMarkers[rewardsLoop] == "templates/rewards/reward_brakes" )
        {
            numberOfJunkmanBrakeMarkersForThisBoss++;

            newMarkerName = std::string(raceBin).append("/rewards/reward_brakes")
            .append(std::to_string(numberOfJunkmanBrakeMarkersForThisBoss));
        }

        else if ( chosenMarkers[rewardsLoop] == "templates/rewards/reward_chassis" )
        {
            numberOfJunkmanSuspensionMarkersForThisBoss++;

            newMarkerName = std::string(raceBin).append("/rewards/reward_chassis")
            .append(std::to_string(numberOfJunkmanSuspensionMarkersForThisBoss));
        }

        else if ( chosenMarkers[rewardsLoop] == "templates/rewards/reward_transmission" )
        {
            numberOfJunkmanTransmissionMarkersForThisBoss++;

            newMarkerName = std::string(raceBin).append("/rewards/reward_transmission")
            .append(std::to_string(numberOfJunkmanTransmissionMarkersForThisBoss));
        }

        else if ( chosenMarkers[rewardsLoop] == "templates/rewards/reward_induction" )
        {
            numberOfJunkmanTurboMarkersForThisBoss++;

            newMarkerName = std::string(raceBin).append("/rewards/reward_induction")
            .append(std::to_string(numberOfJunkmanTurboMarkersForThisBoss));
        }

        else if ( chosenMarkers[rewardsLoop] == "templates/rewards/reward_tires" )
        {
            numberOfJunkmanTireMarkersForThisBoss++;

            newMarkerName = std::string(raceBin).append("/rewards/reward_tires")
            .append(std::to_string(numberOfJunkmanTireMarkersForThisBoss));
        }

        else if ( chosenMarkers[rewardsLoop] == "templates/rewards/reward_engine" )
        {
            numberOfJunkmanEngineMarkersForThisBoss++;

            newMarkerName = std::string(raceBin).append("/rewards/reward_engine")
            .append(std::to_string(numberOfJunkmanEngineMarkersForThisBoss));
        }

        else if ( chosenMarkers[rewardsLoop] == "templates/rewards/reward_nos" )
        {
            numberOfJunkmanNOSMarkersForThisBoss++;

            newMarkerName = std::string(raceBin).append("/rewards/reward_nos")
            .append(std::to_string(numberOfJunkmanNOSMarkersForThisBoss));
        }

        //Visual parts
        else if ( chosenMarkers[rewardsLoop] == "templates/rewards/reward_vinyl" )
        {
            numberOfVinylMarkersForThisBoss++;

            newMarkerName = std::string(raceBin).append("/rewards/reward_vinyl")
            .append(std::to_string(numberOfVinylMarkersForThisBoss));
        }

        else if ( chosenMarkers[rewardsLoop] == "templates/rewards/reward_rims" )
        {
            numberOfRimMarkersForThisBoss++;

            newMarkerName = std::string(raceBin).append("/rewards/reward_rims")
            .append(std::to_string(numberOfRimMarkersForThisBoss));
        }

        else if ( chosenMarkers[rewardsLoop] == "templates/rewards/reward_hood" )
        {
            numberOfHoodMarkersForThisBoss++;

            newMarkerName = std::string(raceBin).append("/rewards/reward_hood")
            .append(std::to_string(numberOfHoodMarkersForThisBoss));
        }

        else if ( chosenMarkers[rewardsLoop] == "templates/rewards/reward_hud" )
        {
            numberOfHUDMarkersForThisBoss++;

            newMarkerName = std::string(raceBin).append("/rewards/reward_hud")
            .append(std::to_string(numberOfHUDMarkersForThisBoss));
        }

        else if ( chosenMarkers[rewardsLoop] == "templates/rewards/reward_body" )
        {
            numberOfBodyKitMarkersForThisBoss++;

            newMarkerName = std::string(raceBin).append("/rewards/reward_body")
            .append(std::to_string(numberOfBodyKitMarkersForThisBoss));
        }

        else if ( chosenMarkers[rewardsLoop] == "templates/rewards/reward_spoiler" )
        {
            numberOfSpoilerMarkersForThisBoss++;

            newMarkerName = std::string(raceBin).append("/rewards/reward_spoiler")
            .append(std::to_string(numberOfSpoilerMarkersForThisBoss));
        }

        else if ( chosenMarkers[rewardsLoop] == "templates/rewards/reward_roofscoop" )
        {
            numberOfRoofscoopMarkersForThisBoss++;

            newMarkerName = std::string(raceBin).append("/rewards/reward_roofscoop")
            .append(std::to_string(numberOfRoofscoopMarkersForThisBoss));
        }

        else if ( chosenMarkers[rewardsLoop] == "templates/rewards/reward_paint" )
        {
            numberOfPaintMarkersForThisBoss++;

            newMarkerName = std::string(raceBin).append("/rewards/reward_paint")
            .append(std::to_string(numberOfPaintMarkersForThisBoss));
        }

        //Random markers
        else if ( chosenMarkers[rewardsLoop] == "templates/rewards/reward_pink_slip" )
        {
            numberOfPinkSlipMarkersForThisBoss++;

            newMarkerName = std::string(raceBin).append("/rewards/reward_pink_slip")
            .append(std::to_string(numberOfPinkSlipMarkersForThisBoss));
        }

        else if ( chosenMarkers[rewardsLoop] == "templates/rewards/reward_out_of_jail_free" )
        {
            numberOfOutOfJailMarkersForThisBoss++;

            newMarkerName = std::string(raceBin).append("/rewards/reward_out_of_jail_free")
            .append(std::to_string(numberOfOutOfJailMarkersForThisBoss));
        }

        else if ( chosenMarkers[rewardsLoop] == "templates/rewards/reward_add_impound_box" )
        {
            numberOfImpoundStrikeMarkersForThisBoss++;

            newMarkerName = std::string(raceBin).append("/rewards/reward_add_impound_box")
            .append(std::to_string(numberOfImpoundStrikeMarkersForThisBoss));
        }

        else if ( chosenMarkers[rewardsLoop] == "templates/rewards/reward_release_car_from_impound" )
        {
            numberOfImpoundReleaseMarkersForThisBoss++;

            newMarkerName = std::string(raceBin).append("/rewards/reward_release_car_from_impound")
            .append(std::to_string(numberOfImpoundReleaseMarkersForThisBoss));
        }

        //This branch is to be used for cash markers
        else { newMarkerName = chosenMarkers[rewardsLoop]; }

        if ( chosenMarkers[rewardsLoop].substr(0, 9) == "templates" )
        {
            file << std::string("copy_node gameplay ").append(chosenMarkers[rewardsLoop]).append(" ")
            .append(chosenMarkers[rewardsLoop].substr(18, chosenMarkers[rewardsLoop].length() - 18))
            .append(" ").append(newMarkerName).append("\n");
        }

        file << std::string("change_vault gameplay ").append(newMarkerName)
        .append(" ").append(raceBin).append("\n");

        file << std::string("update_field gameplay ").append(newMarkerName).append(" Name ")
        .append(newMarkerName).append("\n");

        file << std::string("update_field gameplay ").append(newMarkerName).append(" CollectionName ")
        .append(newMarkerName).append("\n");

        file << std::string("update_field gameplay ").append(raceName).append(" RewardsForWinner[")
        .append(std::to_string(rewardsLoop)).append("] ").append(newMarkerName).append("\n");

        file << std::string("update_field gameplay ").append(raceBin).append("/rewards Children[")
        .append(std::to_string(rewardsLoop)).append("] ").append(newMarkerName).append("\n");
    }
}

std::string createBossRace(std::ofstream& file, const std::string& raceName, int bossRaceCashValue, int numberOfRaces,
                           int numberOfBossRaces, int loop, int raceInteger, const std::string& raceType,
                           const std::string& bossOpponentString, const std::string& raceBin,
                           std::string emptyPostRaceActivityField)
{
    /** Called from randomizeRaces if a race is chosen to be a boss race, no matter what it was
      * originally. Takes details needed for its lines and a string with the last race processed
      * by this function to fill out the PostRaceActivity field for the current one. Reassigns and
      * returns the string.                                                                             */

    //Check all boss race fields, add and update
    if ( !checkForField(raceInteger, 1) )
    { file << std::string("add_field gameplay ").append(raceName).append(" BossRace").append("\n"); }

    file << std::string("update_field gameplay ").append(raceName)
    .append(" BossRace ").append("True").append("\n");

    if ( !checkForField(raceInteger, 5) )
    { file << std::string("add_field gameplay ").append(raceName).append(" RivalBestTime").append("\n"); }

    int randomTime = pickRandomNumber(100, 500);
    file << std::string("update_field gameplay ").append(raceName)
    .append(" RivalBestTime ").append(std::to_string(randomTime)).append("\n");

    //Remove opponent field for tollbooths
    if ( raceType != "tollbooth" )
    {
        file << std::string("resize_field gameplay ").append(raceName)
        .append(" Opponents 1").append("\n");

        file << std::string("update_field gameplay ").append(raceName).append(" Opponents[0] ")
        .append(bossOpponentString).append("\n");
    }

    //Add current race to PostRaceActivity field of last race, if not first boss race
    if ( !emptyPostRaceActivityField.empty() )
    {
        file << std::string("update_field gameplay ").append(emptyPostRaceActivityField)
        .append(" PostRaceActivity ").append(raceName).append("\n");
    }

    emptyPostRaceActivityField = raceName;

    //Run if race is not final boss race. Final boss race for final blacklist member is the only exception
    if ( loop != numberOfRaces + numberOfBossRaces - 1 ||
         loop == numberOfRaces + numberOfBossRaces - 1 && raceBin == "race_bin_01" )
    {
        //Consistent field, no need to check
        file << std::string("update_field gameplay ").append(raceName)
        .append(" CashValue ").append("0").append("\n");

        if ( checkForField(raceInteger, 2) )
        {
            file << std::string("delete_field gameplay ").append(raceName)
            .append(" IsMarkerRace").append("\n");
        }

        if ( !checkForField(raceInteger, 4) )
        {
            file << std::string("add_field gameplay ").append(raceName)
            .append(" PostRaceActivity").append("\n");
        }

        //Set final chase to be after this race, if last boss race for last blacklist member
        if ( loop == numberOfRaces + numberOfBossRaces - 1 && raceBin == "race_bin_01" )
        {
            file << std::string("update_field gameplay ").append(raceName)
            .append(" PostRaceActivity race_bin_01/epic_pursuit").append("\n");
        }
    }

    //Branch for final boss race
    else
    {
        file << std::string("update_field gameplay ").append(raceName).append(" CashValue ")
        .append(std::to_string(pickRandomNumber(bossRaceCashValue / 2,
                                      int(bossRaceCashValue * 1.5)))).append("\n");

        if ( !checkForField(raceInteger, 2) )
        { file << std::string("add_field gameplay ").append(raceName).append(" IsMarkerRace").append("\n"); }

        file << std::string("update_field gameplay ").append(raceName)
        .append(" IsMarkerRace ").append("True").append("\n");

        if ( !checkForField(raceInteger, 3) )
        {
            file << std::string("add_field gameplay ").append(raceName)
            .append(" RewardsForWinner 6").append("\n");
        }

        else if ( raceName == "16_2_3_sprint" )
        {
            file << std::string("resize_field gameplay ").append(raceName)
            .append(" RewardsForWinner 6").append("\n");
        }

        randomizeBossMarkers(file, raceBin, raceName);
    }

    //Return reassigned string for future function calls
    return emptyPostRaceActivityField;
}
