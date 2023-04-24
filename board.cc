#include <iostream>
#include "board.h"
using namespace std;

void Board::board() {
    for (int i = 0; i < size; i++) {
        vector<int> temp;
  
        for (int j = 0; j < size; j++) {
            temp.push_back(0);
        }
        board_vec.push_back(temp);
    }
}

void Board::insert(int value, int x, int y) {
    if (board_vec[x][y] == 0) {
        board_vec[x][y] = value;
    }
    else {
        cout << "Cannot insert here" << endl;
    }
}

int Board::remove(int x, int y) {
    int value = board_vec[x][y];
    board_vec[x][y] = 0;
    return value;
}

int Board::check_coordinate(int x, int y) {
    return board_vec[x][y];
}

// void Board::change_location(int x, int y, string direction) {
//     int value = remove(x, y);
//     if (direction == "up") {
        
//     }
// }

void Board::display() {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << board_vec[i][j] << "  ";
        }
        cout << endl;
    }
}