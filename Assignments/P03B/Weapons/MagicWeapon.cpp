#include "Weapon.cpp"

using namespace std;

#pragma once

class MagicWeapon : public Weapon {
    /**
     * @brief Construct a new Base Weapon object
     *  Also invokes the Dice class constructor with the "die" type
     */
    public:
    MagicWeapon(Weapon* other) {
        name = "Magic " + other->name;
        damage = other->damage;
        die = other->die;
    }
    double use() {
        vector<string> diceroll = {"1.d.4", "1.d.6"};
        damage = randomChoice(diceroll);
        Dice* otherdie = new Dice(damage);
        double add = otherdie->roll();
        cout << "this weapon is MAGIC so it does " << add << " more damage." << endl;
        return die->roll() + add;
    }
};