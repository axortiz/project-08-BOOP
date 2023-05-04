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
    for (int i = 0; i < MAX_NUM; i++) {
        my_pieces.push_back(new Kitten(name));
    }
}

string Player::get_name(){
    return name;
}

bool Player::check_pieces(string target) {
    if (target == "cat") {
        return check_cat();
    }
    else if (target == "kitten") {
        return check_kitten();
    }
    return false;
}

bool Player::check_cat() { 
    int count = 0;
    for (int i = 0; i < (int) my_pieces.size(); i++) {
        if (my_pieces[i]->is_cat()) {
            count++;
        }
    }
    if (count > 0) {
        cout << "you have "<<count<< "cats" << endl;
        return true;
    }
    return false;
}

bool Player::check_kitten() {
    int count = 0;
    for (int i = 0; i < (int) my_pieces.size(); i++) {
        if (!my_pieces[i]->is_cat()) {
            count++;
        }
    }
    if (count > 0) {
        cout << "you have "<<count<< "kittens" << endl;
        return true;
    }
    return false;
}

void Player::graduate_kittens() {
    cout << "inside graduate kittens" << endl;
    for (int i = 0; i < 3; i++) {
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
    if (check_pieces("cat")) {
        for (int i = 0; i < (int) my_pieces.size(); i++) {
            if (my_pieces[i]->is_cat()) {
                cat_piece = my_pieces[i];
                my_pieces.erase(my_pieces.begin()+i);
                break;
            }
        }
    }
    return cat_piece;
}

Piece* Player::retrieve_kitten() {
    Piece* kitten_piece = nullptr;
    if (check_pieces("kitten")) {
        for (int i = 0; i < (int) my_pieces.size(); i++) {
            if (!my_pieces[i]->is_cat()) {
                kitten_piece = my_pieces[i];
                my_pieces.erase(my_pieces.begin()+i);
                break;
            }
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
