#pragma once
#include "Hero.h"
#include <vector>

class Team {
private:
    vector<Hero> team;
public:
    void CreatTeam();

    int  TotalHp();

    void teamGetXp();

    void showTeam() const;

    int CalculateTeamDamage();

    void TakeRandomHit (int IncomingDamage);

    void HealTeam ();

    void EquipWeaponToHero(int heroIndex, Weapon *weapon);
};