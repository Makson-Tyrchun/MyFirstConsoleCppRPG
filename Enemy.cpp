#include <iostream>
#include "Enemy.h"
#include "Team.h"

Enemy::Enemy() {
    name = "Ogr";
    hp = 2500;
}

string Enemy::GetName() const {
    return name;
}

int Enemy::GetHp() const {
    return hp;
}

int Enemy::GetDamage() const {
    int damage = rand() % (450 - 350 + 1) + 350;
    return damage;
}

void Enemy::TakeDamage(int Incomingdamage) {
    hp -= Incomingdamage;
    cout << name << " will be applied " << Incomingdamage << " damage " << endl;
    if (hp <= 0) {
        hp = 0;
        cout << name << " is dead!" << endl;
    }
}

bool Enemy::IsAlive() { return hp > 0; }
