// Angelina Ju
// Text-Based Player vs Entity Game for COSC 202
// https://www.geeksforgeeks.org/convert-map-to-a-vector-of-pairs-in-cpp/

#include "pve.h"
#include <iostream>
#include <vector>

using namespace std;


int main() {
    string name;
    int currentMonster = 0;
    cout << "Welcome to Entity Clash! What is your name? ";
    cin >> name;

    cout << "Hello " << name << "! Let me explain the rules a bit. You will fight 3 monsters with increasing difficulty. Select your attacks carefully!" << endl;

    Player player(name, 100);
    Monster monsters[] = {Monster("Slime", 150), Monster("Zombie", 200), Monster("Emrich", 400)};

    map<string, int> playerAttacks = player.playerAttack();

    vector<pair<string, int>> attacks; // convert the map into a vector to access by index
    copy(playerAttacks.begin(), playerAttacks.end(), back_inserter(attacks)); // from geeks4geeks

    while (!(player.isPlayerDead) && currentMonster < 3){

        Monster& fight = monsters[currentMonster];
        cout << "Get ready to fight!" << player.displayPlayerStats() << fight.displayMonsterStats() << endl;

        int action = 0;
        cout << "What would you like to do? Press (1) Attack or (2) Heal" << endl;
        cin >> action;

        if (action == 1){
            player.printAttacks();

            int atk;
            cout << "Which attack would you like to use? Press (1), (2), or (3)" << endl;
            cin >> atk;
            atk += -1;

            if (atk = 0 && atk < 3){
                const auto& selectedAttack = attacks[atk];
                cout << "You used " << selectedAttack.first << " and dealt " << selectedAttack.second << " damage!" << endl;
                fight.takeMonsterDamage(selectedAttack.second);
            } else {
                cout << "Invalid attack! You forfeit your turn." << endl;
            }

        } else if (action == 2){
            cout << "You have healed yourself for 10 health. " << endl;
            player.playerHeal(10);
        } else {
            cout << "Invalid action! You forfeit your turn. " << endl;
        }

        return 0;
    }

}