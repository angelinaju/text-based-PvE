// Angelina Ju
// Text-Based Player vs Entity Game for COSC 202

#include "pve.h"
#include <iostream>

using namespace std;


int main() {
    string name;
    cout << "Welcome to Entity Clash! What is your name? ";
    cin >> name;

    cout << "Hello " << name << "! Let me explain the rules a bit. You will fight 3 monsters with increasing difficulty. Select your attacks carefully!" << endl;

    Player Player(name, 100);

}