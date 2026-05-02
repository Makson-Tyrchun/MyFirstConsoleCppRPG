#pragma once
#include "Team.h"
#include "Enemy.h"

class Arena {
public:

    void Raid(Team &team, Enemy &boss);

    void RandomEvent (Team &team);

};