#include <iostream>
#include <vector>
#include <string>
#include "BaseFighter.cpp"
#include "../Weapons/Spell.cpp"
using namespace std;

class Wizard : public BaseFighter { 
    public:
    Wizard() {
        name = "Wizard";
        Spell* spell = new Spell();
        weapon = spell; 
        genStats();
    }
};