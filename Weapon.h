#pragma once
#include <string>

using namespace std;

class Weapon {
    private:
    string name;
    int damage;
public:
    Weapon(string WeaponName, int WeaponDamage);

    string GetName () const;

    int GetDamage () const ;
};
