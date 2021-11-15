#include "Weapon.cpp"

using namespace std;

#pragma once

class FireWeapon : public Weapon {
    /**
     * @brief Construct a new Base Weapon object
     *  Also invokes the Dice class constructor with the "die" type
     */
    public:
    //This is setup to where any other weapon can become a FireWeapon
    //It takes all values from the original weapon, just adds to the name
    //It overrides the use function to add a random amount of extra damage
    FireWeapon(Weapon* other) {
        name = "Fire " + other->name;
        damage = other->damage;
        die = other->die;
    }
    //overrides the use function from Weapon to add the extra damage
    int use() {
        vector<string> diceroll = {"1.d.6", "1.d.8"};
        damage = randomChoice(diceroll);
        Dice* otherdie = new Dice(damage);
        int add = otherdie->roll();
        return die->roll() + add;
    }
};