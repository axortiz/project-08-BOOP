#include <iostream>
#include <string>
using namespace std;

class Player {
private:
    Player() = delete;
    string name;
public:
    Player(string)
};

Player::Player(string given_name) {
    cout << "Using the normal constructor for player" << endl;
    name = given_name;
}

Player::Player(string given_name) 
    :name(given_name)
{
    cout << "Using the MIL constructor for player" << endl;
}

int main() {
    Player ("Cornelius");

}