// Angelina Ju
// Text-Based Player vs Entity Game for COSC 202
// https://www.geeksforgeeks.org/convert-map-to-a-vector-of-pairs-in-cpp/

#include "pve.h"
#include <iostream>
#include <vector>

using namespace std;


int main() {
    string name;
    int currentMonster = 0; // counter for which monster you're facing
    bool hasSteelSword = false; // upgraded sword
    cout << "Welcome to Entity Clash! What is your name? ";
    cin >> name;

    cout << "\nHello " << name << "! Let me explain the rules a bit. You will fight 3 monsters with increasing difficulty. Select your attacks carefully!" << endl;
    cout << "Sorry for throwing you in so soon. Get ready to fight!\n\n";

    Player player(name, 100, 0);
    Monster monsters[] = {Monster("Slime", 100), Monster("Zombie", 165), Monster("Emrich", 225)}; // array of the list of monsters & default declaration

    map<string, int> playerAttacks = player.playerAttack(); // copy the attacks

    vector<pair<string, int>> attacks; // convert the map into a vector to access by index
    copy(playerAttacks.begin(), playerAttacks.end(), back_inserter(attacks)); // from geeks4geeks & chatgpt

    while (!(player.isPlayerDead) && currentMonster < 3){  
        Monster& fight = monsters[currentMonster]; 

        map<string, int> monsterattacks = fight.getMonsterAttack(); // same thing with the monster's attacks but changes depending on what monster it is
        vector<pair<string, int>> monsterMove; // map into vector of monster's attacks
        copy(monsterattacks.begin(), monsterattacks.end(), back_inserter(monsterMove)); 
        
        cout << player.displayPlayerStats() << "\n" << fight.displayMonsterStats() << endl; // print out the current health stats

        int action = 0;
        cout << "What would you like to do? Press (1) Attack or (2) Heal" << endl; // player has 2 options: attack or heal
        cin >> action;

        if (action == 1){
            player.printAttacks(); // display the player's attacks

            int atk;
            cout << "\nWhich attack would you like to use? Press (1), (2), or (3): "; // choose the attack of the player
            cin >> atk;
            atk += -1; // subtract 1 for index

            if (atk >= 0 && atk < 3){ // depending on what number you input, use that attack on the monster
                const auto& selectedAttack = attacks[atk]; 
                if (hasSteelSword){ // if you have the steel sword, damage is increased 1.2X or 20%
                    int modDMG = selectedAttack.second * 1.2; // modified dmg amount 
                    cout << "You used " << selectedAttack.first << " and dealt " << modDMG << " damage!\n";
                    fight.takeMonsterDamage(modDMG);
                } else { // if you don't have the steel sword, damage stays the same
                    cout << "You used " << selectedAttack.first << " and dealt " << selectedAttack.second << " damage!\n";
                    fight.takeMonsterDamage(selectedAttack.second);
                }
            } else {
                cout << "Oh no, looks like you missed! You forfeit your turn." << endl; // any other input causes you to forfeit
            }

        } else if (action == 2){ // heal 10 health if you chose to heal
            cout << "You have healed yourself for 10 health. " << endl;
            player.playerHeal(10);
        } else {
            cout << "Oh no, looks like you missed! You forfeit your turn. " << endl;
        }

        if (!fight.isMonsterDead){
            int monsterATK = rand() % 3; // the monster's attack is chosen randomly from 0-2
            bool missed = fight.missMonsterAttack(); // monster has a 1/5 chance of "missing" the attack 
            if (!missed){
                const auto& selectedATK = monsterMove[monsterATK]; // get the move name and damage of the randomly selected attack
                cout << "The monster used " << selectedATK.first << " and dealt " << selectedATK.second << " damage to you! " << endl;
                player.takePlayerDamage(selectedATK.second);
            } else {
                cout << "The monster missed its attack! You survive to see a few more minutes. " << endl;
            }
        } else {
            int monsterGold = rand() % 10 + 1; // when you kill the monster, you get a random amount of gold from 1-10
            cout << "Congratulations! You've defeated the monster. You've also gained " << monsterGold << " gold." << endl;
            cout << "You consumed the essence of the monster and have absorbed health." << endl; // you also get some health
            
            player.addGold(monsterGold);
            player.playerHeal(100);
            currentMonster++; // increment monster counter to move on to the next monster

            if (currentMonster < 3 && !hasSteelSword){ // if you haven't beat all the monsters yet and you don't have the sword upgrade, prompt player to go buy it
                char market;
                cout << "Would you like to go to the market to purchase a new weapon? Press (Y) for Yes and (N) for No. ";
                cin >> market;

                if (market == 'Y' || market == 'y'){ // set steel sword to true or false
                    hasSteelSword = player.goMarket();
                } else {
                    cout << "You have skipped going to the market." << endl;
                }
            }
            continue;
        }
 
        if (player.isPlayerDead){ // if you die during the game loop, end it
            cout << "Oh no! The monster has killed you. Try again next time!" << endl;
            break;
        }
    }
    if (!player.isPlayerDead){ // if you make it through the last loop iteration and you're not dead
        cout << "Congratulations! You've defeated all the monsters and lived to tell the tale! Good job, " << name << "!\n";
    }
    return 0;
}