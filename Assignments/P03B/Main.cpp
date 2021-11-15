// #include "Fighters/BaseFighter.cpp"
#include "iomanip"
#include "thread"
#include "cstdlib"
#include "cmath"
#include "Fighters/Warrior.cpp"
#include "Fighters/Wizard.cpp"
#include "Fighters/Elf.cpp"
#include "Fighters/DragonBorn.cpp"
#include "Fighters/Archer.cpp"
using namespace std;

//Adds a random amount of attackers to the provided attackers vector
//seems the assignment forgot to provide and input and in class we used random generator
//so this should be fine?
void populateAttackers(vector<BaseFighter*>& attackers) {
    for(int i = 0; i < (100 + rand() % 3000); i++) {
        BaseFighter* archer = new Archer();
        BaseFighter* warrior = new Warrior();
        BaseFighter* wizard = new Wizard();
        BaseFighter* elf = new Elf();
        BaseFighter* dragonborn = new DragonBorn();
        attackers.push_back(archer);
        attackers.push_back(warrior);
        attackers.push_back(wizard);
        attackers.push_back(elf);
        attackers.push_back(dragonborn);
    }
}
//Populates the provided defenders vector based on the size of the attackers list
//1 of each type of defender per 100 attackers
void populateDefenders(int attackersSize, vector<BaseFighter*>& defenders) {
    //Defending force can have 1 of each character type for every 100 attackers.
    int size = round(attackersSize / 100.0);
    for(int i = 0; i < size; i++) {
        BaseFighter* archer = new Archer();
        BaseFighter* warrior = new Warrior();
        BaseFighter* wizard = new Wizard();
        BaseFighter* elf = new Elf();
        BaseFighter* dragonborn = new DragonBorn();
        defenders.push_back(archer);
        defenders.push_back(warrior);
        defenders.push_back(wizard);
        defenders.push_back(elf);
        defenders.push_back(dragonborn);
    }
}

//Function to get a new defender based on the type of attacker is up for battle
//this way types will match when fighting
BaseFighter* getDefender(BaseFighter* attacker, vector<BaseFighter*>* defenders)  {
    for(BaseFighter* defender : *defenders) {
        if(defender->name == attacker->name) {
            return defender;
        }
    }
    return defenders->back();
}   

//Heals all defenders by the amount defined in their object
void healDefenders(vector<BaseFighter*>& defenders) {
    for(BaseFighter* defender : defenders) {
        int hp = defender->heal();
        if(hp > 0) {
           cout << "Idle defender: " << defender->name << " regened " << hp << " hp." << endl;
        }
    }
}
//Swaps out defender for another defender of the same time (if it exists)
BaseFighter* swapDefender(vector<BaseFighter*>* defenders, BaseFighter* curFighter) {
    for(BaseFighter* defender : *defenders) {
        if(defender != curFighter && defender->name == curFighter->name) {
            return defender;
        }
    }
    cout << "Swap failed! There are no " << curFighter->name << "\'s left." << endl;
    return curFighter;
}

int main() {
    // Create a vector of attackers
    srand(time(0));
    vector<BaseFighter*> attackers;
    vector<BaseFighter*> defenders;

    // Populate the attackers vector
    populateAttackers(attackers);
    populateDefenders(attackers.size(), defenders);

    BaseFighter* CurrentAttacker;
    BaseFighter* CurrentDefender;

    while(attackers.size() && defenders.size()) {
        // Get an attacker for this round
        CurrentAttacker = attackers.back();
        CurrentDefender = getDefender(CurrentAttacker, &defenders);
        while(CurrentAttacker->alive() && CurrentDefender->alive()) {

            // Setup interface for the round
            this_thread::sleep_for(chrono::milliseconds(1));
            system("clear");
            cout << "Attackers" << setw(5) << " " << setw(0) << "Defenders" << endl;
            cout << left << setw(13) << attackers.size() << " " << setw(0) << defenders.size() << endl;
            cout << CurrentAttacker->name << ":" << CurrentAttacker->hp << "hp | " << CurrentDefender->name << ":" <<CurrentDefender->hp << "hp" << endl << endl;

            // Attack
            // First, the attacker attacks
            int dmg = CurrentAttacker->attack();
            cout << "Attacker " << CurrentAttacker->name << " does: " << dmg << " DMG!" << endl;
            CurrentDefender->takeDamage(dmg);

            // Then, if the defender is still alive, the defender attacks
            if(CurrentDefender->alive()) {
                int dmg2 = CurrentDefender->attack();
                CurrentAttacker->takeDamage(dmg2);
                cout << "Defender " << CurrentDefender->name << " survives and counterattacks for: " << dmg << " DMG!" << endl;
                cout << "Attacks health reduced to: " << CurrentAttacker->hp << endl;
                if(CurrentDefender->hp < 6) {
                    // If the defender is low on health, swap him out for another defender of the same type
                    CurrentDefender = swapDefender(&defenders, CurrentDefender);
                }
            } else {
                // If the defender is dead, remove him from the defender list
                cout << "defender " << CurrentDefender->name << " died!!!!" << endl;
                defenders.pop_back();

            }

            // Heal the defenders
            healDefenders(defenders);
        }
        // Remove the dead attacker from the attacker list
        if(!CurrentAttacker->alive()) {
            attackers.pop_back();
            cout << "attacker " << CurrentAttacker->name << " died!!!!" << endl;
        }

        //The swapping sometime screws stuff up somehow
        int i = 0;
        for(BaseFighter* fighter : defenders) {
            if(fighter->hp <= 0) {
                defenders.erase(defenders.begin() + i);
                cout << "defender " << CurrentDefender->name << " died!!!!" << endl;
            }
            i++;
        }

    }
    // If there are no defenders left, the attackers win
    if(attackers.size()) {
        cout << "ATTACKERS WIN!!!!";
    }
    if(defenders.size()) {
        cout << "DEFENDERS WIN!!!";
    }

}