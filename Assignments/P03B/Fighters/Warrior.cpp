#include <iostream>
#include <vector>
#include <string>
#include "BaseFighter.cpp"
#include "../Weapons/Sword.cpp"
using namespace std;

class Warrior : public BaseFighter { 
    public:
    Warrior() {
        name = "Warrior";
        Sword* sword = new Sword();
        weapon = sword; 
        genStats();
    }
};