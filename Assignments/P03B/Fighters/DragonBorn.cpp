#include <iostream>
#include <vector>
#include <string>
#include "BaseFighter.cpp"
#include "../Weapons/Spell.cpp"
#include "../Weapons/FireWeapon.cpp"
using namespace std;

class DragonBorn : public BaseFighter { 
    public:
    DragonBorn() {
        name = "DragonBorn";
        Spell* spell = new Spell();
        FireWeapon* magicsword = new FireWeapon(spell);
        weapon = magicsword; 
        genStats();
    }
};