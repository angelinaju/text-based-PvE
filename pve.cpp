// Angelina Ju
// Text-Based Player vs Entity Game for COSC 202

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

map<string, int> Player::playerAttack(){
    map<string, int> attackList;
    attackList["Sword Slash"] = 10;
    attackList["Upper Slice"] = 15;
    attackList["Whirlwind"] = 25;
} 

bool Player::missPlayerAttack(){
    int randomValue = rand() % 10 + 1; // random function will miss an attack if it lands on the 1/10 chance
    if (randomValue == 4){ // fun fact 4 sounds really similar to death in Chinese
        return true;
    }
    return false;
}


