cmake_minimum_required(VERSION 3.20)
project(battleship_cppversion)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(battleship_cppversion
        AbstractShipFactory.h
        App.cpp
        App.h
        BasicShip.h
        BattleShip.h
        BattleShipBoard.h
        Board.h
        BoardTextView.cpp
        BoardTextView.h
        Carrier.h
        Coordinate.cpp
        Coordinate.h
        InBoundRuleChecker.h
        MyException.h
        NoCollisionRuleChecker.h
        ordinary.cpp
        ordinary.h
        Placement.cpp
        Placement.h
        PlacementRuleChecker.h
        RectangleShip.h
        Ship.h
        ShipDisplayInfo.h
        ShipFactory.cpp
        ShipFactory.h
        SimpleShipDisplayInfo.h
        TextPlayer.cpp
        TextPlayer.h)