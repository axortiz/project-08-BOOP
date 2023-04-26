#include <iostream>
#include "game.h"
using namespace std;

int main() {
    string name_1, name_2;
    cout << "Player 1 name: " << endl;
    cin >> name_1;
    cout << "Player 2 name: " << endl;
    cin >> name_2;
    Boop game(name_1, name_2);

    return 0;
}
