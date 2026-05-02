cmake_minimum_required(VERSION 4.1)
project(MyFirstRpg)

set(CMAKE_CXX_STANDARD 20)

add_executable(MyFirstRpg main.cpp
        Hero.h
        Enemy.h
        Weapon.h
        Weapon.cpp
        Hero.cpp
        Game.h
        Game.cpp
        Team.h
        Team.cpp
        BattleArena.h
        Enemy.cpp
        BattleArena.cpp)
