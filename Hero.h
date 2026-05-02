#pragma once
#include <string>

using namespace std;

class Weapon;

class Hero {
private:
    string name;
    int hp;
    int maxHp;
    int xp;
    Weapon* currentWeapon;

public:
    Hero();

    void SetName(string n);

    string GetName() const;

    void SetHP(int h);

    int GetHp() const;

    int GetXp() const;

    void TakeDamage(int damage);

    void Heal(int amount);

    void TakeXp();

    void LevelUp();;

    void EquipWeapon(Weapon* newWeapon);

    int GetAttackDamage ();

};