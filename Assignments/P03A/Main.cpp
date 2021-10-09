#include "emojis.h"
#include "rockPaper.cpp"

using namespace std;
struct Player{
    string weapon1;
    string weapon2;
    // other possible stuff

    /**
     * Constructor guarantees a player has two different "weapons"
     */
    Player(){
        weapon1 = Hands::RandHand();
        weapon2 = Hands::RandHand();

        while(weapon2==weapon1){
            weapon2 = Hands::RandHand();
        }
    }
    // other possible methods
/**
 * Returns 0 if p1 wins, returns 1 if p2 wins
 */
bool determineWinner(Player _p1, Player _p2) {
    string p1 = _p1.weapon1;
    string p2 = _p2.weapon1;

    string rock = Hands::Rock();
    string paper = Hands::Paper();
    string scissors = Hands::Scissors();
    string lizard = Hands::Lizard();
    string spock = Hands::Spock();

    //swap to secondaries if weapons are the same
    if(p1 == p2) {
        cout << "DRAW DETECTED: " << p1 << " " << p2 << endl;
        p1 = _p1.weapon2;
        p2 = _p2.weapon2;
        cout << "SECOND WEAPONS EQUIPPED: " << p1 << " " << p2 << endl;
    }
    
    //If they still have the same weapons after the secondary weapons 
    //then its just a draw
    if(p1 == p2) {
        return false;
    }

    //Every case where p1 beats p2
    if(p1 == scissors && (p2 == paper || p2 == lizard))
        return true;
    if(p1 == paper && (p2 == rock || p2 == spock))
        return true;
    if(p1 == rock && (p2 == lizard || p2 == scissors)) 
        return true;
    if(p1 == lizard && (p2 == spock || p2 == paper))
        return true;
    if(p1 == spock && (p2 == scissors || p2 == rock))
        return true;
    
    //if it gets to here, p2 wins
    return false;
}

    //overload > to call determineWinner
    bool operator>(const Player rhs) {
        bool result = determineWinner(*this, rhs);
        return result;
    }
};




int main() {
    for(int i = 0; i < 25; i++) {
        Player p1; // gets two random weapons when constructed
        Player p2; // same
        cout << "Player 1: " << p1.weapon1 << endl;
        cout << "Player 2: " << p2.weapon1 << endl;

        // // Hmmm. Look familiar?
        if(p1 > p2){
            cout<<"Player 1 Wins!" << endl;
        }else if(p2 > p1){
             cout<<"Player 2 Wins!" << endl;
        }else{
            cout<<"It's a tie!"<<endl;
            // print all 4 weapons here...
        }
        cout << endl;
    }
}