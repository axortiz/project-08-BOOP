#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <string>
using namespace std;

class Player {
private:
    string name;
public:
    Player(string);
};

Player::Player(string given_name) 
    :name(given_name)
{
    cout << "Using the MIL constructor for player" << endl;
}

#endif
