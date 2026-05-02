#include "Hero.h"
#include <iostream>
#include <string>
#include "Weapon.h"

Hero::Hero () {
    name = "Unknow";
    maxHp = 1000;
    hp = maxHp;
    xp = 0;
    currentWeapon = nullptr;
}

void Hero::SetName(string n) {
    name = n;
}

void Hero::SetHP(int h) {
    hp = h;
}

string Hero::GetName() const {
    return name;
}

int Hero::GetHp() const {
    return hp;
}

int Hero::GetXp() const {
    return xp;
}

void Hero::TakeDamage(int damage) {
    cout << "Your hero " << name << " will be applied " << damage << " damage " << endl;

    hp -= damage;

    if (hp <= 0) {
        hp = 0;
        cout << "Your hero " << name << " died." << endl;
    }
}

void Hero::Heal(int amount) {
    if (GetHp() == 0) {
        cout << "This hero died";
        return;
    }

    cout << "Your hero " << name << " will be cured on " << amount << " hp " << endl;

    hp += amount;

    if (hp > maxHp) {
        cout << "Your hero has " << name << " already maximum HP points" << endl;
        hp = maxHp;
    }
}

void Hero::TakeXp() {
    int tempXp = rand() % 100;
    xp += tempXp;
    cout << "Your hero " << GetName() << " take " << tempXp << " XP." << endl;
    LevelUp();
}

void Hero::LevelUp() {
    if (GetXp() >= 100) {
        maxHp += 500;
        hp = maxHp;
        xp = 0;
        cout << "Your hero " << GetName() << " Has level Up! Your max HP is now " << maxHp << endl;
    }
}

void Hero::EquipWeapon(Weapon *newWeapon) {
    currentWeapon = newWeapon;
    cout << GetName() << " picked up " << currentWeapon->GetName() << " ! " << endl;
}

int Hero::GetAttackDamage() {
    if (GetHp() > 0) {
         if (currentWeapon != nullptr) {
            return currentWeapon->GetDamage();
        }else {
            int randDamage = rand() % (200 - 100 + 1) + 100;
            return randDamage;
        }
    }
    cout << "This hero died" << endl;
    return 0;
    }
