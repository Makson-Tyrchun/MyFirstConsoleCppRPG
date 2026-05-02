#pragma once
#include "Enemy.h"
#include "Team.h"
#include "BattleArena.h"
#include    "Weapon.h"

    enum class GameState {
        Menu,
        Playing,
        Exit,
        Infirmary,
        Forest,
    };

    class Game {
    private:

        int PlayerInput;

        GameState currentState;

        Enemy boss;

        Team myTeam;

        Arena myArena;

        Weapon *startSword;

    public:
        ~Game();

        void Input();

        void Render();

        void Update();

        void Run();

        void Init();

    };