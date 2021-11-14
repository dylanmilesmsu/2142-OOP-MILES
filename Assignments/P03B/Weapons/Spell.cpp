#include "Weapon.cpp"

using namespace std;

#pragma once

class Spell : public Weapon {
    /**
     * @brief Construct a new Base Weapon object
     *  Also invokes the Dice class constructor with the "die" type
     */
    public:
    Spell() {
        name = "Spell";
        vector<string> diceroll = {"1.d.20", "2.d.10", "3.d.6", "5.d.4"};
        damage = randomChoice(diceroll);
        die = new Dice(damage);
    }
};