// Angelina Ju
// Text-Based Player vs Entity Game for COSC 202
// https://www.geeksforgeeks.org/convert-map-to-a-vector-of-pairs-in-cpp/

#include "pve.h"
#include <iostream>
#include <vector>

using namespace std;


int main() {
    string name;
    int currentMonster;
    cout << "Welcome to Entity Clash! What is your name? ";
    cin >> name;

    cout << "Hello " << name << "! Let me explain the rules a bit. You will fight 3 monsters with increasing difficulty. Select your attacks carefully!" << endl;

    Player player(name, 100);
    Monster monsters[] = {Monster("Slime", 150), Monster("Zombie", 200), Monster("Emrich", 400)};

    map<string, int> playerAttacks = player.playerAttack();

    vector<pair<string, int>> attacks;
    copy(playerAttacks.begin(), playerAttacks.end(), back_inserter(attacks));

    while (!(player.isPlayerDead) && currentMonster < 3){

        Monster& fight = monsters[currentMonster];
        cout << "Get ready to face the " << fight.displayMonsterStats() << endl;

        int action = 0;
        cout << "What would you like to do? Press (1) Attack or (2) Heal" << endl;
        cin >> action;

        if (action == 1){
            player.printAttacks();

            int atk;
            cout << "Which attack would you like to use? Press (1), (2), or (3)" << endl;
            cin >> atk;

            if (atk > 0 && atk <= 3){
                const auto& selectedAttack = attacks[atk - 1];
                cout << "You used " << selectedAttack.first << " and dealt " << selectedAttack.second << " damage!" << endl;
                fight.takeMonsterDamage(selectedAttack.second);
            } else {
                cout << "Invalid attack! You forfeit your turn." << endl;
            }


            
        }

        return 0;
    }

}