// Angelina Ju
// Text-Based Player vs Entity Game for COSC 202

#ifndef PVE_H
#define PVE_H

#include <iostream>
#include <map>

using namespace std;

class Player {

    private:
        int playerHealth;
        string playerName;
        
    public:
        void play();
        Player(string name, int health);
        void displayStats();
        map<string, int> playerAttack();

};

class Monster {

    private:
        int monsterHealth;
        string monsterName; // slime, zombie, or dragon
        

    public: 
        Monster(string name, int health, int attackPower);
        void displayStats();
        map<string, int> slimeAttack();
        map<string, int> zombieAttack();
        map<string, int> dragonAttack();

};




#endif