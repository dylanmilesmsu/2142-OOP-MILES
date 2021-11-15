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

void populateAttackers(vector<BaseFighter*>& attackers) {
    for(int i = 0; i < (100 + rand() % 5000); i++) {
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

BaseFighter* getDefender(BaseFighter* attacker, vector<BaseFighter*>* defenders)  {
    for(BaseFighter* defender : *defenders) {
        if(defender->name == attacker->name) {
            return defender;
        }
    }
    return defenders->back();
}   

void healDefenders(vector<BaseFighter*>& defenders) {
    for(BaseFighter* defender : defenders) {
        int hp = defender->heal();
        if(hp > 0) {
           cout << "Idle defender: " << defender->name << " regened " << hp << " hp." << endl;
        }
    }
}
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

    srand(time(0));
    vector<BaseFighter*> attackers;
    vector<BaseFighter*> defenders;

    populateAttackers(attackers);
    populateDefenders(attackers.size(), defenders);

    BaseFighter* CurrentAttacker;
    BaseFighter* CurrentDefender;

    while(attackers.size() && defenders.size()) {
        CurrentAttacker = attackers.back();
        CurrentDefender = getDefender(CurrentAttacker, &defenders);
        while(CurrentAttacker->alive() && CurrentDefender->alive()) {
            this_thread::sleep_for(chrono::milliseconds(10));
            system("clear");
            cout << "Attackers" << setw(5) << " " << setw(0) << "Defenders" << endl;
            cout << left << setw(13) << attackers.size() << " " << setw(0) << defenders.size() << endl;
            cout << CurrentAttacker->name << ":" << CurrentAttacker->hp << "hp | " << CurrentDefender->name << ":" <<CurrentDefender->hp << "hp" << endl << endl;

            int dmg = CurrentAttacker->attack();
            cout << "Attacker " << CurrentAttacker->name << " does: " << dmg << " DMG!" << endl;
            CurrentDefender->takeDamage(dmg);
            if(CurrentDefender->alive()) {
                int dmg2 = CurrentDefender->attack();
                CurrentAttacker->takeDamage(dmg2);
                cout << "Defender " << CurrentDefender->name << " survives and counterattacks for: " << dmg << " DMG!" << endl;
                cout << "Attacks health reduced to: " << CurrentAttacker->hp << endl;
                if(CurrentDefender->hp < 6) {
                    CurrentDefender = swapDefender(&defenders, CurrentDefender);
                }
            } else {
                defenders.pop_back();
            }
            healDefenders(defenders);
        }
        if(!CurrentAttacker->alive()) {
            attackers.pop_back();
            cout << "attacker " << CurrentAttacker->name << " died!!!!" << endl;
        }

        //The swapping sometime screws stuff up somehow
        int i = 0;
        for(BaseFighter* fighter : defenders) {
            if(fighter->hp < 0) {
                defenders.erase(defenders.begin() + i);
            }
            i++;
        }

        // for(BaseFighter* fighter : defenders) {
        //     cout << fighter->hp << endl;
        //             this_thread::sleep_for(chrono::milliseconds(200));
        // }
    }
    if(attackers.size()) {
        cout << "ATTACKERS WIN!!!!";
    }
    if(defenders.size()) {
        cout << "DEFENDERS WIN!!!";
    }

}