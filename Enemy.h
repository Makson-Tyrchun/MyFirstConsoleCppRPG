#pragma once
#include <iostream>
#include <string>

using namespace std;

class Enemy {
private:
    string name;
    int hp;

public:
    Enemy();

    string GetName() const;

    int GetHp() const;

    int GetDamage() const;

    void TakeDamage(int Incomingdamage);

    bool IsAlive();
};