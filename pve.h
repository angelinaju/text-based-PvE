// Angelina Ju
// Text-Based Player vs Entity Game for COSC 202

#ifndef PVE_H
#define PVE_H

#include <iostream>
#include <map>

using namespace std;

class Player {

    private:
        int playerHealth, playerGold;
        string playerName;
        
    public:
        Player(string name, int health, int gold); // default
        int addGold(int gold); // you get gold when you defeat a monster
        string displayPlayerStats(); // print name and hp
        void takePlayerDamage(int hp); // remove hp from player
        void playerHeal(int hp); // add hp to player
        map<string, int> playerAttack(); // list of attacks available to player in the form name, damage
        void printAttacks(); // print out the list of attacks the player can choose from
        bool goMarket();
        bool isPlayerDead = false; 
       
};

class Monster {

    private:
        int monsterHealth;
        string monsterName; // slime, zombie, or dr emrich
        
    public: 
        Monster(string name, int health); // default
        string displayMonsterStats(); // display name and hp of monster
        void takeMonsterDamage(int hp); // remove hp from monster
        map<string, int> slimeAttack(); // list of slime's attacks
        map<string, int> zombieAttack(); // list of zombie's attacks
        map<string, int> emrichAttack(); // list of dr emrich's attacks
        map<string, int> getMonsterAttack(); // helps return which monster's attack is currently being used
        bool missMonsterAttack(); // chance that the monster can miss an attack
        bool isMonsterDead = false;
};

#endif