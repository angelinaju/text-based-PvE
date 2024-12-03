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

Player::Player(string name, int health) {
    playerName = name;
    playerHealth = health;
}

void Player::displayPlayerStats(string name, int health){
    cout << "Name: " << playerName << endl;
    cout << "Health: " << health << endl;
}

void Player::takePlayerDamage(int health){
    playerHealth -= health;
    if (playerHealth < 0){
        playerHealth = 0;
        isPlayerDead = true;
    } 
}

void Player::playerHeal(int hp){
    playerHealth += hp;
    if (playerHealth > 100){
        playerHealth = 100;
    }
}

map<string, int> Player::playerAttack(){
    map<string, int> attackList;
    attackList["Sword Slash"] = 10;
    attackList["Upper Slice"] = 15;
    attackList["Whirlwind"] = 25;
    return attackList;
} 

void Player::printAttacks(){
    map<string, int> attacks = playerAttack();
    map<string, int>::iterator it = attacks.begin(); // code from geeks4geeks

    while (it != attacks.end()){
        cout << "Available Attacks: " << it->first  << ", ";
        ++it;
    }
}

// bool Player::missPlayerAttack(){
//     int randomValue = rand() % 7 + 1; // random function will miss an attack if it lands on the 1/7 chance
//     if (randomValue == 4){ // fun fact 4 sounds really similar to death in Chinese
//         return true;
//     }
//     return false;
// }

string Monster::displayMonsterStats(string monsterName, int monsterHealth){
    cout << "Name: " << monsterName << endl;
    cout << "Health: " << monsterHealth << endl;
}

void Monster::takeMonsterDamage(int hp){
    monsterHealth -= hp;
    if (monsterHealth < 0){
        monsterHealth = 0;
        isMonsterDead = true;
    }
}

map<string, int> Monster::slimeAttack(){
    map<string, int> attackList;
    attackList["Cute Stare"] = 10;
    attackList["High Jump"] = 15;
    attackList["Acid Slobber"] = 20;
    return attackList;
}

map<string, int> Monster::zombieAttack(){
    map<string, int> attackList;
    attackList["Fist Punch"] = 14;
    attackList["High Jump"] = 18;
    attackList["Bite"] = 22;
    return attackList;
}

map<string, int> Monster::emrichAttack(){
    map<string, int> attackList;
    attackList["202 Lecture"] = 18;
    attackList["Case Study"] = 25;
    attackList["Assignment Graded"] = 35;
    return attackList;
}

bool Monster::missMonsterAttack(){
    int randomValue = rand() % 7 + 1; // random function will miss an attack if it lands on the 1/7 chance
    if (randomValue == 4){ // fun fact 4 sounds really similar to death in Chinese
        return true;
    }
    return false;
}