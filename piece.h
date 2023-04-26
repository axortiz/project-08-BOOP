#ifndef PIECE_H
#define PIECE_H
#include "game.h"
#include <vector>
using namespace std;

class Piece {
private:
    string player;
public:
    Piece();
    Piece(string);
    void display();

};

#endif
