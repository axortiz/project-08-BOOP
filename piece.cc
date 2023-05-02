#include "piece.h"
using namespace std;

Piece::Piece() {
    player = "bot";
}

Piece::Piece(string input_name)
{
    player = input_name;
}

Piece::~Piece() {}
