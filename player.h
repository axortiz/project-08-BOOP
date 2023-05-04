#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <string>
#include "piece.h"
#include <vector>
#include <string>

class Player {
private:
    std::string name;
    int num_pieces;
protected:
    std::vector <Piece*> my_pieces;
public:
    Player(std::string);
    std::string get_name();
    bool check_pieces(std::string target);
    bool check_cat();
    bool check_kitten();
    void graduate_kittens();
    Piece* retrieve_piece(bool get_cat);
    Piece* retrieve_cat();
    Piece* retrieve_kitten();
    void display_pieces();
    void receive_pieces(Piece* booped);
};

#endif
