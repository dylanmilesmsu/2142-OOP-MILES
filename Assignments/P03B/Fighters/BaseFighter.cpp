#include <iostream>
#include <vector>
#include <string>
#include "../Weapons/Weapon.cpp"

using namespace std;

#pragma once

class BaseFighter {
    public:
        double attack() {
            double dmg = weapon->use();
            return dmg;
        }
        void attack(BaseFighter* &other) {
            double dmg = weapon->use();
            other->takeDamage(dmg);
        }
        void takeDamage(double dmg) {
            hp -= dmg;
        }
        string name;
        int hp;
        double regenRate;
        Weapon* weapon;
        void genStats() {
            //hp random between 10-15
            //regen rate random between 1-3
            hp = 10 + (rand() % 5);
            regenRate = (1 + (rand() % 2));
        }
};