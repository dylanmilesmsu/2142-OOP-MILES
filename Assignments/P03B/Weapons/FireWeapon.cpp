#include "Weapon.cpp"

using namespace std;

#pragma once

class FireWeapon : public Weapon {
    /**
     * @brief Construct a new Base Weapon object
     *  Also invokes the Dice class constructor with the "die" type
     */
    public:
    FireWeapon(Weapon* other) {
        name = "Fire " + other->name;
        damage = other->damage;
        die = other->die;
    }
    int use() {
        vector<string> diceroll = {"1.d.6", "1.d.8"};
        damage = randomChoice(diceroll);
        Dice* otherdie = new Dice(damage);
        int add = otherdie->roll();
        return die->roll() + add;
    }
};