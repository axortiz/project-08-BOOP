#include <iostream>
#include "game.h"
#include "player.h"
#include "kitten.h"
#include "cat.h"
#include "piece.h"

/**
 *
 * BOOP-Project-08
 * Alexis Ortiz
 * David Batbayar
 * 2/1/23 
 */

using namespace std;

int main() {
    string name_1, name_2;
    cout << "Player 1 name: " << endl;
    cin >> name_1;
    cout << "Player 2 name: " << endl;
    cin >> name_2;
    Boop game(name_1, name_2);
    game.play_game();
    

    return 0;
}
