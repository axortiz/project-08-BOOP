#include <iostream>
#include "game.h"
#include "player.h"

void Boop::create_players() {
    Player("Player 1");
    Player("Player 2");
    cout << "Players created..." << endl;
}
