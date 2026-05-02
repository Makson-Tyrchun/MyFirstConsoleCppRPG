#include <iostream>
#include "BattleArena.h"
#include "Team.h"
#include "Game.h"
#include <thread>
#include <chrono>

void Arena::Raid(Team &team, Enemy &boss) {
    if (team.TotalHp() >= 3000) {
        while (boss.IsAlive() && team.TotalHp() > 0) {
            boss.TakeDamage(team.CalculateTeamDamage());
            if (!boss.IsAlive()) {
                team.teamGetXp();
                break;
            }
            team.TakeRandomHit(boss.GetDamage());
            this_thread::sleep_for(chrono::seconds(2));


        }
        if (team.TotalHp() <= 0 ) {
            cout << "Game Over! Your team destoyed" << endl;
        } else if (team.TotalHp() > 0) {
            cout << "Raid is over. Going to infimary" << endl;
            team.showTeam();
        }
            } else if (team.TotalHp() < 3000) {
            cout << "Your team HP < 3000." << endl;
        }
    }


void Arena::RandomEvent(Team &team) {
    int  randomDamage = rand() % 100;
    cout << "On the way to the forest, you are suddenly hit by a boy with a slingshot." << endl;
    team.TakeRandomHit(randomDamage);
    team.showTeam();
}
