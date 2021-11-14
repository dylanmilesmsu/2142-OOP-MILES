#include "Weapon.cpp"

using namespace std;

#pragma once

class Bow : public Weapon {
    public:
    Bow() {
        name = "Bow";
        vector<string> diceroll = {"1.d.8", "2.d.4", "1.d.10"};
        damage = randomChoice(diceroll);
        die = new Dice(damage);
    }
};