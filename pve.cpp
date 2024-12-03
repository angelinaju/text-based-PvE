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

string Player::displayPlayerStats(){
    return "Your Name: " + playerName + " Health: " + to_string(playerHealth) + "\n";
}

void Player::takePlayerDamage(int health){
    playerHealth -= health;
    if (playerHealth <= 0){
        playerHealth = 0;
        isPlayerDead = true;
    } 
}

void Player::playerHeal(int hp){
    playerHealth += hp;
    if (playerHealth > 100){
        playerHealth = 100;
    }
    cout << "Your health is now " << playerHealth << ".\n";
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
    cout << "Available Attacks: ";
    while (it != attacks.end()){
        cout << it->first << " ";
        ++it;
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