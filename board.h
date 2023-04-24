#ifndef BOARD_H
#define BOARD_H
#include <vector>
#include <string>
#include "game.h"
using namespace std;

class Board : public Boop {
private:
    const static int size = 6;
    vector <vector <int> > board_vec;
public:
    void board();
    void insert(int value, int x, int y);
    int remove(int x, int y);
    int check_coordinate(int x, int y);
    void change_location (int x, int y, string direction);
    void display();
};

#endif