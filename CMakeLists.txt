cmake_minimum_required(VERSION 3.24)
project(MostRandomTE)

set(CMAKE_CXX_STANDARD 20)

add_executable(MostRandomTE main.cpp
        ListFunctions.cpp
        ListFunctions.h
        EventTriggerFunctions.cpp
        EventTriggerFunctions.h
        GeneralFunctions.cpp
        GeneralFunctions.h
        RaceFunctions.cpp
        RaceFunctions.h
        PursuitFunctions.cpp
        PursuitFunctions.h
        UnusedFunctions.cpp
        BossRaceMarkerFunctions.cpp
        BossRaceMarkerFunctions.h
        FreeRoamFunctions.cpp
        FreeRoamFunctions.h
        NodeConversionFunctions.cpp
        NodeConversionFunctions.h
        XoshiroCpp.hpp)
