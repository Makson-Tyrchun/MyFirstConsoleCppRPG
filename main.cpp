#include <ctime>
#include <iostream>
#include <string>
#include "Game.h"

using namespace std;

int main() {
    srand(time(nullptr));

    Game myGame;

    myGame.Run();

    return 0;
}