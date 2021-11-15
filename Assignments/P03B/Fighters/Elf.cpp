#include <iostream>
#include <vector>
#include <string>
#include "BaseFighter.cpp"
#include "../Weapons/Sword.cpp"
#include "../Weapons/MagicWeapon.cpp"
using namespace std;

/*
* just uses stuff from basefighter, sword, and MagicWeapon class
*/ 

class Elf : public BaseFighter { 
    public:
    Elf() {
        name = "Elf";
        Sword* sword = new Sword();
        MagicWeapon* magicsword = new MagicWeapon(sword);
        weapon = magicsword; 
        genStats();
    }
};