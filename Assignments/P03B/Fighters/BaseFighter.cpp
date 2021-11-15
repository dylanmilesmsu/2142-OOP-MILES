#include <iostream>
#include <vector>
#include <string>
#include "../Weapons/Weapon.cpp"

using namespace std;

#pragma once

class BaseFighter {
    public:
        int attack() {
            int dmg = weapon->use();
            return dmg;
        }
        void attack(BaseFighter* &other) {
            int dmg = weapon->use();
            other->takeDamage(dmg);
        }
        void takeDamage(int dmg) {
            hp -= dmg;
        }

        bool alive() {
            return hp > 0;
        }

        int heal() {
            if(hp < maxhp) {
                hp += regenRate;
                return regenRate;
            }
            return 0;
        }

        string name;
        int maxhp;
        int hp;
        double regenRate;
        Weapon* weapon;
        void genStats() {
            //hp random between 10-20
            //regen rate random between 1-3
            hp = 15 + (rand() % 20);
            maxhp = hp;
            regenRate = (5 + (rand() % 6));
        }
};