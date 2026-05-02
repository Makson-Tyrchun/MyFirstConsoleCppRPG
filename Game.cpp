#include <iostream>
#include "Game.h"
#include  "Team.h"



using namespace std;

// This method is called first, before the main loop starts. Its task is to set the initial parameters.
void Game::Init() {
    currentState = GameState::Menu;
    startSword = new Weapon("Excalibur", 300);
}

//This one doesn't make decisions, it just displays text on the screen depending on what "program" is currently on.
void Game::Render() {
    switch (currentState)
        {
        case GameState::Menu: {
            cout << "MENU\n"
            << "1.Start Game\n"
            << "2.Exit\n"
            << endl;
            break;
            }
        case GameState::Playing: {
            cout << "The arena is loading... The game is on!" << endl;
            myTeam.showTeam();
            cout <<"Arena Menu\n"
                << "1.Hit Boss\n"
                << "2.Flee to Main Menu"
                << endl;
            break;
        }
        case GameState::Infirmary: {
            cout << "1.Going to Infirmary\n"
                 << "2.Exit"
                 << endl;
            break;
        }
        case GameState::Forest: {
            cout << "After infimary your team is planning to go into the forest. Go?" << endl;
            cout << "1.Goin to Forest\n"
                 << "2.Exit\n"
                 << endl;
            break;
        }
    }

}

//This method waits for user input.
void Game::Input() {
    cin >> PlayerInput;
    cin.get();
}

//This method looks at what the player clicked and decides where to switch the state.
void Game::Update() {
    if (currentState == GameState::Menu) {
        if (PlayerInput == 1) {
            currentState = GameState::Playing;
            myTeam.CreatTeam();
            myTeam.EquipWeaponToHero(1, startSword);
        }else if (PlayerInput == 2) {
            currentState = GameState::Exit;
        }
    }
    else if (currentState == GameState::Playing) {
        if (PlayerInput == 1) {
            myArena.Raid(myTeam, boss);
            currentState = GameState::Infirmary;
        } else if (PlayerInput == 2) {
            currentState = GameState::Menu;
        }
    } else if (currentState == GameState::Infirmary) {
        if (PlayerInput == 1) {
        myTeam.HealTeam();
            currentState = GameState::Forest;
        }
        if (PlayerInput == 2){
            currentState = GameState::Exit;
        }
    } else if (currentState == GameState::Forest) {
        if (PlayerInput == 1) {
            myArena.RandomEvent(myTeam);
            currentState = GameState::Menu;
        }
            if (PlayerInput == 2) {
                currentState = GameState::Exit;
            }
        }
    }


    //A method to launch the game
    void Game::Run() {
        Init();
        while (currentState != GameState::Exit) {
            Render();
            Input();
            Update();
        }
    }

Game::~Game() {
    delete startSword;
}
