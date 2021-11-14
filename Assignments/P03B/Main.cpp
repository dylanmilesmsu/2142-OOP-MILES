// #include "Fighters/BaseFighter.cpp"
#include "Fighters/Warrior.cpp"
#include "Fighters/Wizard.cpp"
#include "Fighters/Elf.cpp"
#include "Fighters/DragonBorn.cpp"
using namespace std;

int main() {
    srand(time(0));
    cout << "hi\n";
    BaseFighter* fighter = new BaseFighter();
    BaseFighter* defender = new BaseFighter();

    DragonBorn* warrior1 = new DragonBorn();
    Warrior* warrior2 = new Warrior();
    fighter = warrior1;
    defender = warrior2;

    cout << "Fighter has " << fighter->hp << " health" << endl;
    cout << "Defender has " << defender->hp << " health" << endl;
    int damage = fighter->attack();
    cout << "Fighter attacks! and does: " << damage << " damage" << endl << endl;
    defender->takeDamage(damage);

    cout << "Fighter has " << fighter->hp << " health" << endl;
    cout << "Defender has " << defender->hp << " health" << endl;

}