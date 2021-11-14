#include "Weapon.cpp"

using namespace std;

#pragma once

class Sword : public Weapon {
    /**
     * @brief Construct a new Base Weapon object
     *  Also invokes the Dice class constructor with the "die" type
     */
    public:
    Sword() {
        name = "Sword";
        vector<string> diceroll = {"1.d.12", "2.d.6", "3.d.4"};
        damage = randomChoice(diceroll);
        die = new Dice(damage);
    }
};