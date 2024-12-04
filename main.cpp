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

    cout << "\nHello " << name << "! Let me explain the rules a bit. You will fight 3 monsters with increasing difficulty. Select your attacks carefully!" << endl;
    cout << "Sorry for throwing you in so soon. Get ready to fight!\n\n";

    Player player(name, 100);
    Monster monsters[] = {Monster("Slime", 100), Monster("Zombie", 165), Monster("Emrich", 225)};

    map<string, int> playerAttacks = player.playerAttack();
    map<string, int> monsterattacks;

    vector<pair<string, int>> attacks; // convert the map into a vector to access by index
    copy(playerAttacks.begin(), playerAttacks.end(), back_inserter(attacks)); // from geeks4geeks & chatgpt

    while (!(player.isPlayerDead) && currentMonster < 3){
        Monster& fight = monsters[currentMonster];
        vector<pair<string, int>> monsterMove;

        if (currentMonster == 0){monsterattacks = fight.slimeAttack();} 
        else if (currentMonster == 1){monsterattacks = fight.zombieAttack();} 
        else {monsterattacks = fight.emrichAttack();}

        copy(monsterattacks.begin(), monsterattacks.end(), back_inserter(monsterMove));
        
        cout << player.displayPlayerStats() << "\n" << fight.displayMonsterStats() << endl;

        int action = 0;
        cout << "What would you like to do? Press (1) Attack or (2) Heal" << endl;
        cin >> action;

        if (action == 1){
            player.printAttacks();

            int atk;
            cout << "\nWhich attack would you like to use? Press (1), (2), or (3): ";
            cin >> atk;
            atk += -1;

            if (atk >= 0 && atk < 3){
                const auto& selectedAttack = attacks[atk];
                cout << "You used " << selectedAttack.first << " and dealt " << selectedAttack.second << " damage!\n";
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

        if (!fight.isMonsterDead){
            int monsterATK = rand() % 3;
            bool missed = fight.missMonsterAttack();
            if (!missed){
                const auto& selectedATK = monsterMove[monsterATK];
                cout << "The monster used " << selectedATK.first << " and dealt " << selectedATK.second << " damage to you! " << endl;
                player.takePlayerDamage(selectedATK.second);
            } else {
                cout << "The monster missed its attack! You survive to see a few more minutes. " << endl;
            }
        } else {
            cout << "Congratulations! You've defeated the monster." << endl;
            cout << "You consumed the essence of the monster and have absorbed health." << endl;
            player.playerHeal(100);
            currentMonster++;
            continue;
        }

        if (player.isPlayerDead){
            cout << "Oh no! The monster has killed you. Try again next time!" << endl;
            break;
        }
    }
    if (!player.isPlayerDead){
        cout << "Congratulations! You've defeated all the monsters and lived to tell the tale! Good job, " << name << "!\n";
    }
    return 0;
}