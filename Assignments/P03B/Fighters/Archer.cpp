#include <iostream>
#include <vector>
#include <string>
#include "BaseFighter.cpp"
#include "../Weapons/Bow.cpp"
using namespace std;

class Archer : public BaseFighter { 
    public:
    Archer() {
        name = "Archer";
        Bow* bow = new Bow();
        weapon = bow; 
        genStats();
    }
};