#include "Weapon.h"
#include <string>

Weapon::Weapon(string WeaponName, int WeaponDamage) {
    name = WeaponName;
    damage = WeaponDamage;
}

int Weapon::GetDamage() const {
    return damage;
}

string Weapon::GetName() const {
    return name;
}