#include <iostream>
#include <vector>
#include <string>
#include "BaseFighter.cpp"
#include "../Weapons/Spell.cpp"
using namespace std;

/*
* just uses stuff from basefighter and spell class
*/ 

class Wizard : public BaseFighter { 
    public:
    Wizard() {
        name = "Wizard";
        Spell* spell = new Spell();
        weapon = spell; 
        genStats();
    }
};