#include <iostream>
#include <vector>
#include <string>
#include "../Weapons/Weapon.cpp"

using namespace std;

#pragma once

/**
 *  Abstract fighter class that all other fighters will be based on 
 *  it implements several functions to keep implementing new characters
 *  as fast and simple as possible.
 */

class BaseFighter {
    public:
    //Attack function, mostly relies on stuff in weapon class
        int attack() {
            int dmg = weapon->use();
            return dmg;
        }
        //attack function that allows you to directly attack another fighter
        //unused but could be useful for future additions
        void attack(BaseFighter* &other) {
            int dmg = weapon->use();
            other->takeDamage(dmg);
        }
        //Take damage function, self explanatory
        void takeDamage(int dmg) {
            hp -= dmg;
        }
        //boolean to check if character is still alive
        bool alive() {
            return hp > 0;
        }
    //healing, only heals to maxhp
    //used only by defenders 
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
        //randomly generates character stats upon creation
        //all childs will have to call this function
        //unless they want to define their own stats.
        void genStats() {
            //hp random between 15-35.
            //regen rate random between 5-15
            //These numbers were carefully chosen
            //to balance attackers vs defenders
            hp = 15 + (rand() % 20);
            maxhp = hp;
            regenRate = (5 + (rand() % 10));
        }
};