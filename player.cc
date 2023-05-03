#include "player.h"
#include "piece.h"
#include "kitten.h"
#include "constants.h"
#include "cat.h"
#include <vector>

using namespace std;
using namespace constants;

Player::Player(string given_name) 
    :name(given_name)
{
    for (int i = 0; i < MAX_NUM; i++) {
        my_pieces.push_back(new Kitten(name));
    }
    num_pieces = (int) my_pieces.size();
}

string Player::get_name(){
    return name;
}

void Player::graduate_kittens(int num_graduee) {
    for (int i = 0; i < num_graduee; i++) {
        my_pieces.push_back(new Cat(name));
        num_pieces = (int) my_pieces.size();
    }
}

Piece* Player::retrieve_piece(bool get_cat) {
    Piece* target_piece = nullptr;
    if ((int) my_pieces.size() > 0) {
        if (get_cat) {
            target_piece = retrieve_cat();
            num_pieces = (int) my_pieces.size();
        }
        else {
            target_piece = retrieve_kitten();
            num_pieces = (int) my_pieces.size();
        }
    }
    return target_piece;
}

Piece* Player::retrieve_cat() {
    Piece* cat_piece = nullptr;
    for (int i = 0; i < (int) my_pieces.size(); i++) {
        if (my_pieces[i]->is_cat()) {
            cat_piece = my_pieces[i];
            my_pieces.erase(my_pieces.begin()+i);
            break;
        }
    }
    return cat_piece;
}

Piece* Player::retrieve_kitten() {
    Piece* kitten_piece = nullptr;
    for (int i = 0; i < (int) my_pieces.size(); i++) {
        if (!my_pieces[i]->is_cat()) { 
            kitten_piece = my_pieces[i];
            my_pieces.erase(my_pieces.begin()+i);
            break;
        }
    }
    return kitten_piece;
}

void Player::display_pieces() {
    cout << "You have " << (int) my_pieces.size() << " pieces." << endl;
}

void Player::receive_pieces(Piece* booped) {
    if (num_pieces >= MAX_NUM){
        cout << "error too many pieces" << endl;
    }
    my_pieces.push_back(booped);
    num_pieces = (int) my_pieces.size();
}
