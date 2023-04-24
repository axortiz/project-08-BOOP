#ifndef HEADER_H
#define HEADER_H
#include "board.h"
#include <vector>
using namespace std;

class Boop {
private:
    Board game_board;
    Pieces player_1;
    Pieces player_2;
protected:
public:
    Boop();
    void place_piece(bool cat_or_kitten, int x, int y);
    vector <int> check_coordinates(int x, int y);
};

#endif