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
        bool isPlayerDead = false;
        
    public:
        Player(string name, int health);
        void displayPlayerStats(string name, int health);
        void takePlayerDamage(int hp);
        map<string, int> playerAttack();
        bool missPlayerAttack();
       
 
};

class Monster {

    private:
        int monsterHealth;
        string monsterName; // slime, zombie, or dragon
        
    public: 
        Monster(string name, int health);
        void displayMonsterStats(string name, int health);
        void takeMonsterDamage(int hp); 
        map<string, int> slimeAttack();
        map<string, int> zombieAttack();
        map<string, int> emrichAttack();
        int missMonsterAttack();

};




#endif