// Angelina Ju
// Text-Based Player vs Entity Game for COSC 202
// https://www.geeksforgeeks.org/map-associative-containers-the-c-standard-template-library-stl/

#include "pve.h"
#include <iostream>
#include <map>
#include <string>
#include <random>
#include <cstdlib>

using namespace std;

Player::Player(string name, int health, int gold) {
    playerName = name;
    playerHealth = health;
    playerGold = gold;
}

string Player::displayPlayerStats(){
    return "Your Name: " + playerName + " Health: " + to_string(playerHealth) + "\n";
}

int Player::addGold(int gold){
    playerGold += gold;
    return playerGold;
}

void Player::takePlayerDamage(int health){
    playerHealth -= health;
    if (playerHealth <= 0){ // player health cant be negative
        playerHealth = 0;
        isPlayerDead = true; // player is dead
    } 
}

void Player::playerHeal(int hp){
    playerHealth += hp;
    cout << "Your health is now " << playerHealth << ".\n";
}

map<string, int> Player::playerAttack(){ // player attack list
    map<string, int> attackList;
    attackList["Sword Slash"] = 18;
    attackList["Upper Slice"] = 27;
    attackList["Whirlwind"] = 34;
    return attackList;
} 

void Player::printAttacks(){ // display the attacks
    map<string, int> attacks = playerAttack();
    map<string, int>::iterator it = attacks.begin(); // code from geeks4geeks
    cout << "Available Attacks: ";
    while (it != attacks.end()){
        cout << it->first << " ";
        ++it;
    }
}

bool Player::goMarket(){
    char upgrade;
    cout << "\nWelcome to the market! You currently have a Stone Sword." << endl;
    cout << "Would you like to upgrade to a Steel Sword? This upgrade will cost you 7 gold.\nYou currently have " << playerGold << " gold.\nPress (Y) for Yes and (N) for No." << endl; 
    cin >> upgrade;

    if (upgrade == 'Y' || upgrade == 'y'){
        if (playerGold >= 7){
            cout << "You have successfully purchased the Steel Sword! Your damage will now be increased by 20%.\nSending you back to the monster's den..." << endl;
            playerGold -= 7;
            return true;
        } else {
            cout << "Sorry, you don't have enough gold! Try again later.\nSending you back to the monster's den..." << endl;
            return false;
        }
    } else {
        cout << "You have rejected the upgrade.\nSending you back to the monster's den..." << endl;
        return false;
    }
}

Monster::Monster(string name, int health){
    monsterName = name;
    monsterHealth = health;
}

string Monster::displayMonsterStats(){
    return "Monster Name: " + monsterName + " Health: " + to_string(monsterHealth) + "\n";
}

void Monster::takeMonsterDamage(int hp){
    monsterHealth -= hp;
    if (monsterHealth <= 0){
        monsterHealth = 0;
        isMonsterDead = true;
    }
    cout << "The " << monsterName << " is now at " << monsterHealth << " HP!\n\n";
}

map<string, int> Monster::slimeAttack(){ // list of slime's attacks
    map<string, int> attackList;
    attackList["Cute Stare"] = 10;
    attackList["High Jump"] = 15;
    attackList["Acid Slobber"] = 20;
    return attackList;
}

map<string, int> Monster::zombieAttack(){ // list of zombie's attacks
    map<string, int> attackList;
    attackList["Fist Punch"] = 12;
    attackList["High Jump"] = 18;
    attackList["Bite"] = 22;
    return attackList;
}

map<string, int> Monster::emrichAttack(){ // list of emrich's attacks
    map<string, int> attackList;
    attackList["202 Lecture"] = 18;
    attackList["Lab Due Friday"] = 25;
    attackList["Assignment Graded"] = 35;
    return attackList;
}

map<string, int> Monster::getMonsterAttack(){ // returns the attacks here and cleaned up my main a bit
    if (monsterName == "Slime"){return slimeAttack();}
    else if (monsterName == "Zombie"){return zombieAttack();}
    else return emrichAttack();
}

bool Monster::missMonsterAttack(){
    int randomValue = rand() % 5; // random function will miss an attack if it lands on the 1/5 chance
    if (randomValue == 4){ // fun fact 4 sounds really similar to death in Chinese
        return true;
    }
    return false;
}