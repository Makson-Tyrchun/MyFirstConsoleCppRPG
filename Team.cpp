#include <iostream>
#include "Team.h"
#include "Weapon.h"

using namespace std;

void Team::CreatTeam() {
    team.clear();
    for (int i = 0; i < 3; i++) {
        string tempName;

        cout << "Enter the name of the hero " << i + 1 << ": ";
        cin >> tempName;

        Hero newHero;
        newHero.SetName(tempName);

        team.push_back(newHero);
    }
}

int Team::TotalHp() {
    int totalHp = 0;
    for (int i = 0; i < team.size(); i++) {
        totalHp += team[i].GetHp();
    }
    return totalHp;
}

void Team::teamGetXp() {
    for (Hero &hero: team) {
        hero.TakeXp();
    }
}

void Team::showTeam() const {
    cout << "Your team:" << endl;
    for (int i = 0; i < team.size(); i++) {
        cout << i + 1 << ". " << team[i].GetName() << " - " << team[i].GetHp()
                << " HP, " << team[i].GetXp() << " XP" << endl;
    }
}

int Team::CalculateTeamDamage() {
    int TotalDamage = 0;
    for (int i = 0; i < team.size(); i++) {
        int currentDamage = team[i].GetAttackDamage();
        TotalDamage += currentDamage;
        cout << team[i].GetName() << " deal " << currentDamage << endl;
    }
    return TotalDamage;
}

void Team::TakeRandomHit(int IncomingDamage) {
    if (TotalHp() <= 0) {
        return;
    }
    int randomTarget = rand () % team.size();
    while (team[randomTarget].GetHp() <= 0) {
        randomTarget = rand () % team.size();
    }
    team[randomTarget].TakeDamage(IncomingDamage);
}

void Team::HealTeam() {
    cout << "Chose hero to heal" << endl;

    while (true){
    int healIndex;
    cin >> healIndex;
    int healAmount;
        if (healIndex >= 1 && healIndex <= team.size()) {
            if (team[healIndex - 1].GetHp() == 0 ) {
                cout << "This hero died" << endl;
                continue;
            }
            cout << "How much do you want to heal your hero?" << endl;
            cin >> healAmount;
            team[healIndex - 1].Heal(healAmount);
            showTeam();
            break;
        } else {
            cout << "You write wrong number try again" << endl;
        }
    }
}

void Team::EquipWeaponToHero(int heroIndex, Weapon *weapon) {
    if (heroIndex >= 1 && heroIndex <= team.size()) {
        team[heroIndex - 1].EquipWeapon(weapon);
    }
}
