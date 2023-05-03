#include "player.h"
#include "piece.h"
#include "kitten.h"
#include "constants.h"
#include "cat.h"
#include <vector>

using namespace std;
using namespace constants;

Player::Player(string given_name) 
    :name(given_name),
    num_pieces(8)
{
    for (int i = 0; i < max_num; i++) {
        my_pieces.push_back(new Kitten(name));
    }
}

string Player::get_name(){
    return name;
}

void Player::graduate_kittens(int num_graduee) {
    for (int i = 0; i < num_graduee; i++) {
        my_pieces.push_back(new Cat(name));
        num_pieces++;
    }
}

Piece* Player::retrieve_piece(bool get_cat) {
    Piece* target_piece = nullptr;
    if (get_cat) {
        target_piece = retrieve_cat();
        num_pieces--;
    }
    else {
        target_piece = retrieve_kitten();
        num_pieces--;
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
    my_pieces.push_back(booped);
    num_pieces++;
}
