#include <iostream>
#include <vector>
#include <string>
#include "game.h"
#include "constants.h"
#include "piece.h"
#include "player.h"
#include "kitten.h"
#include "cat.h"
#include "empty.h"

using namespace std;
using namespace constants;

Boop::Boop(string player_name_1, string player_name_2) 
    : player_1_cat(0),
      player_2_cat(0)
{
    player_1 = new Player(player_name_1);
    player_2 = new Player(player_name_2);
    for (int i = 0; i < SIZE; i++) {
        vector<Piece*> temp;
        for (int j = 0; j < SIZE; j++) {
            temp.push_back(new Empty("game"));
        }
        game_board.push_back(temp);
    }
}

void Boop::display() {
    cout << "The board is: " << endl;
    for(int y_axis = 0; y_axis < SIZE ; y_axis++){
        for(int x_axis = 0; x_axis < SIZE ; x_axis++){
            if (game_board[y_axis][x_axis]->is_empty()) {
                cout << "0 ";
            }
            if(game_board[y_axis][x_axis]->is_cat()){
                if(game_board[y_axis][x_axis]->get_name() == player_1->get_name()){
                    cout << "2 ";
                }
                else if(game_board[y_axis][x_axis]->get_name() == player_2->get_name()){
                    cout << "4 ";
                }
            }
            else if(!game_board[y_axis][x_axis]->is_cat() && !game_board[y_axis][x_axis]->is_empty()){
                if(game_board[y_axis][x_axis]->get_name() == player_1->get_name()){
                    cout << "1 ";
                }
                else if(game_board[y_axis][x_axis]->get_name() == player_2->get_name()){
                    cout << "3 ";
                }
            }
        }
        cout << endl;
    }
}

Player* Boop::get_player(Piece* target_piece) {
    if (target_piece->get_name() == player_1->get_name()) {
        return player_1;
    }
    else {
        return player_2;
    }
}

bool Boop::place_piece(Piece* cat_or_kitten, int x, int y) {
    cout << "PLACE_PIECE" << endl;
    if(!game_board[y][x]->is_empty()){
        cout << "Uh oh! That spot is already taken! Try again!" << endl;
        return false;
    }
    else {    
        game_board[y][x] = cat_or_kitten;
        check_coordinates_for_boop(x, y);
        if (cat_or_kitten->is_cat()) {
            if (get_player(cat_or_kitten) == player_1) {
                player_1_cat++;
            }
            else {
                player_2_cat++;
            }
        }
        return true;
    }
}

void Boop::boop_cat(Piece* cat_or_kitten, int x_loc, int y_loc) {
    game_board[y_loc][x_loc] = cat_or_kitten;
}

void Boop::check_coordinates_for_boop(int x, int y){
    if(game_board[y][x]->is_cat()){
        if(x!=0){
            if(!game_board[y][x-1]->is_empty()){
                boop_piece(x-1, y, "left");
            }
        }
        if(x!=5){
            if(!game_board[y][x+1]->is_empty()){
                boop_piece(x+1, y, "right");
            }
        }
        if (y != 0) {
            if(!game_board[y-1][x]->is_empty()){
                boop_piece(x, y-1, "top");
            }
            if(x!=5){
                if(!game_board[y-1][x+1]->is_empty()){
                    boop_piece(x+1, y-1, "top right");
            }
            }
            if(x!=0){
                if(!game_board[y-1][x-1]->is_empty()){
                    boop_piece(x-1, y-1, "top left");
            }
            }
        }
        if (y != 5) {
            if(!game_board[y+1][x]->is_empty()){
                boop_piece(x, y+1, "bottom");
                }
            if(x!=0){
                if(!game_board[y+1][x-1]->is_empty()){
                    boop_piece(x-1, y+1, "bottom left");
                }
            }
            if(x!=5){
                if(!game_board[y+1][x+1]->is_empty()){
                    boop_piece(x+1, y+1, "bottom right");
                }
            }
        }
    }
    else{
        if(x!=0){
            if(!game_board[y][x-1]->is_empty()){
                if(!game_board[y][x-1]->is_cat()){
                    boop_piece(x-1, y, "left");
                }
            }
        }
        if(x!=5){
            if(!game_board[y][x+1]->is_empty()){
                if(!game_board[y][x+1]->is_cat()){
                    boop_piece(x+1, y, "right");
                }
            }
        }
        if (y != 0) {
            if(!game_board[y-1][x]->is_empty()){
                if(!game_board[y-1][x]->is_cat()){
                    boop_piece(x, y-1, "top");
                }
            }
            if(x!=5){
                if(!game_board[y-1][x+1]->is_empty()){
                    if(!game_board[y-1][x+1]->is_cat()){
                        boop_piece(x+1, y-1, "top right");
                    }
                }
            }
            if(x!=0){
                if(!game_board[y-1][x-1]->is_empty()){
                    if(!game_board[y-1][x-1]->is_cat()){
                        boop_piece(x-1, y-1, "top left");
                    }
                }
            }
        }
        if (y != 5) {
            if(!game_board[y+1][x]->is_empty()){
                if(!game_board[y+1][x]->is_cat()){
                    boop_piece(x, y+1, "bottom");
                }
            }
            if(x!=0){
                if(!game_board[y+1][x-1]->is_empty()){
                    if(!game_board[y+1][x-1]->is_cat()){
                        boop_piece(x-1, y+1, "bottom left");
                    }
                }
            }
            if(x!=5){
                if(!game_board[y+1][x+1]->is_empty()){
                    if(!game_board[y+1][x+1]->is_cat()){
                        boop_piece(x+1, y+1, "bottom right");
                    }
                }
            }
        }
    }
}

Piece* Boop::remove_button(int x_loc, int y_loc){ 
    Piece* removed_piece = game_board[y_loc][x_loc];
    Piece* thingy = new Empty("game");
    game_board[y_loc][x_loc] = thingy;
    return removed_piece;
}

void Boop::delete_from_board(int x, int y) {
    if(game_board[y][x]->is_cat()){
        deduct_cats(get_player(game_board[y][x]));
    }
    game_board[y][x] = new Empty("game");
}

bool Boop::check_boop_path(int x_loc, int y_loc) {
    if (game_board[y_loc][x_loc]->is_empty()) {
        return true;
    }
    else {
        return false;
    }
}

void Boop::deduct_cats(Player* dude){
    if(dude == player_1){
        player_1_cat--;
    }
    if(dude == player_2){
        player_2_cat--;
    }
}

void Boop::boop_piece(int x_loc, int y_loc, string path) {
    if (path == "right") {
        if (x_loc == 5){
            Piece* removed_piece = remove_button(x_loc, y_loc);
            Player* temp = get_player(removed_piece);
            temp->receive_pieces(removed_piece);
            if(removed_piece->is_cat()){
                deduct_cats(temp);
            }
        }
        else{
            if(check_boop_path(x_loc+1, y_loc)){
                Piece* removed_piece = remove_button(x_loc, y_loc);
                boop_cat(removed_piece, x_loc+1, y_loc);
            }
        }
    }
    if (path == "left") {
        if (x_loc == 0){
            Piece* removed_piece = remove_button(x_loc, y_loc);
            Player* temp = get_player(removed_piece);
            temp->receive_pieces(removed_piece);
            if(removed_piece->is_cat()){
                deduct_cats(temp);
            }
        }
        else{
            if(check_boop_path(x_loc-1, y_loc)){
                Piece* removed_piece = remove_button(x_loc, y_loc);
                boop_cat(removed_piece, x_loc-1, y_loc);
            }
        }
    }
    if (path == "top") {
        if (y_loc == 0){
            Piece* removed_piece = remove_button(x_loc, y_loc);
            Player* temp = get_player(removed_piece);
            temp->receive_pieces(removed_piece);
            if(removed_piece->is_cat()){
                deduct_cats(temp);
            }
        }
        else{
            if(check_boop_path(x_loc, y_loc-1)){
                Piece* removed_piece = remove_button(x_loc, y_loc);
                boop_cat(removed_piece, x_loc, y_loc-1);
            }
        }
    }
    if (path == "bottom") {
        if (y_loc == 5){
            Piece* removed_piece = remove_button(x_loc, y_loc);
            Player* temp = get_player(removed_piece);
            temp->receive_pieces(removed_piece);
            if(removed_piece->is_cat()){
                deduct_cats(temp);
            }
        }
        else{
            if(check_boop_path(x_loc, y_loc+1)){
                Piece* removed_piece = remove_button(x_loc, y_loc);
                boop_cat(removed_piece, x_loc, y_loc+1);
            }
        }
    }
    if (path == "top right") {
        if (y_loc == 0 && x_loc == 5){
            Piece* removed_piece = remove_button(x_loc, y_loc);
            Player* temp = get_player(removed_piece);
            temp->receive_pieces(removed_piece);
            if(removed_piece->is_cat()){
                deduct_cats(temp);
            }
        }
        else{
            if(y_loc == 0 || x_loc == 5){
                Piece* removed_piece = remove_button(x_loc, y_loc);
                Player* temp = get_player(removed_piece);
                temp->receive_pieces(removed_piece);
                if(removed_piece->is_cat()){
                    deduct_cats(temp);
                }
            }
            else if(check_boop_path(x_loc+1, y_loc-1)){
                Piece* removed_piece = remove_button(x_loc, y_loc);
                boop_cat(removed_piece, x_loc+1, y_loc-1);
            }
        }
    }
    if (path == "top left") {
        if (y_loc == 0 && x_loc == 0){
            Piece* removed_piece = remove_button(x_loc, y_loc);
            Player* temp = get_player(removed_piece);
            temp->receive_pieces(removed_piece);
            if(removed_piece->is_cat()){
                deduct_cats(temp);
            }
        }
        else{
            if(y_loc == 0 || x_loc == 5){
                Piece* removed_piece = remove_button(x_loc, y_loc);
                Player* temp = get_player(removed_piece);
                temp->receive_pieces(removed_piece);
                if(removed_piece->is_cat()){
                    deduct_cats(temp);
                }
            }
            else if(check_boop_path(x_loc-1, y_loc-1)){
                Piece* removed_piece = remove_button(x_loc, y_loc);
                boop_cat(removed_piece, x_loc-1, y_loc-1);
            }
        }
    }
    if (path == "bottom right") {
        if (y_loc == 5 && x_loc == 5){
            Piece* removed_piece = remove_button(x_loc, y_loc);
            Player* temp = get_player(removed_piece);
            temp->receive_pieces(removed_piece);
            if(removed_piece->is_cat()){
                deduct_cats(temp);
            }
            return;
        }
        else{
            if(y_loc == 5){
                Piece* removed_piece = remove_button(x_loc, y_loc);
                Player* temp = get_player(removed_piece);
                temp->receive_pieces(removed_piece);
                if(removed_piece->is_cat()){
                    deduct_cats(temp);
                }
                return;
            }
            else if(x_loc == 5){
                Piece* removed_piece = remove_button(x_loc, y_loc);
                Player* temp = get_player(removed_piece);
                temp->receive_pieces(removed_piece);
                if(removed_piece->is_cat()){
                    deduct_cats(temp);
                }
                return;
            }
            if(check_boop_path(x_loc+1, y_loc+1)){
                Piece* removed_piece = remove_button(x_loc, y_loc);
                boop_cat(removed_piece, x_loc+1, y_loc+1);
                return;
            }
        }
    }
    if (path == "bottom left") {
        if (y_loc == 5 && x_loc == 0){
            Piece* removed_piece = remove_button(x_loc, y_loc);
            Player* temp = get_player(removed_piece);
            temp->receive_pieces(removed_piece);
            if(removed_piece->is_cat()){
                deduct_cats(temp);
            }
            return;
        }
        else{
            if(y_loc == 5 || x_loc == 0){
                Piece* removed_piece = remove_button(x_loc, y_loc);
                Player* temp = get_player(removed_piece);
                temp->receive_pieces(removed_piece);
                if(removed_piece->is_cat()){
                    deduct_cats(temp);
                }
                return;
            }
           if(check_boop_path(x_loc-1, y_loc+1)){
                Piece* removed_piece = remove_button(x_loc, y_loc);
                boop_cat(removed_piece, x_loc-1, y_loc+1);
                return;
            }
        }
    }
}

Piece* Boop::check_coordinates_for_three(int x, int y){
    if(!game_board[y][x+1]->is_empty()){//checks if the coordineate is to the left of another piece
        
        if(!game_board[y][x-1]->is_empty()){//checks if the coordinate is the center of three in a row
            string path = "center";
            return check_three_in_a_row_horizontal(x, y, path);
        }
        else if(!game_board[y][x+2]->is_empty()){//checks if the coordinate is the leftmost piece of three in a row
            string path = "left";
            return check_three_in_a_row_horizontal(x, y, path);
        }
    }
    else if(!game_board[y][x-1]->is_empty()){
        if(!game_board[y][x-2]->is_empty()){//checks if the coordinate is the rightmost piece of three in a row
            string path = "right";
            return check_three_in_a_row_horizontal(x, y, path);
        }
    }
    else if(!game_board[y-1][x]->is_empty()){
        if(!game_board[y+1][x]->is_empty()){
            string path = "center";
            return check_three_in_a_row_vertical(x, y, path);//checks if the coordinate is the center of a vertical three in a row
        }
        else{
            if(!game_board[y-2][x]->is_empty()){
                string path = "bottom";
                return check_three_in_a_row_vertical(x, y, path);//checks if the coordinate is the bottom of a vertical three in a row
            }
        }
    }
    else if(!game_board[y+1][x]->is_empty()){
        if(!game_board[y+2][x]->is_empty()){
            string path = "top";
            return check_three_in_a_row_vertical(x, y, path);//checks if the coordinate is the top of a vertical three in a row
        }
    }
    else{
        if(!game_board[y-1][x+1]->is_empty()){
            if(!game_board[y+1][x-1]->is_empty()){
                string path = "center right";
                return check_three_in_a_row_diagonal(x, y, path);//checks if the coordintae is the center of a diagonal three in a row in / direction
            }
            else{
                if(!game_board[y-2][x+2]->is_empty()){
                    string path = "bottom left";
                    return check_three_in_a_row_diagonal(x, y, path);//checks if the coordinate is the bottom left of a diagonal three in / direction
                }
            }
        }
        else if(!game_board[y+1][x]->is_empty()){
            if(!game_board[y+2][x-2]->is_empty()){
                string path = "top right";
                return check_three_in_a_row_diagonal(x, y, path);//checks if the coordinate is the top right of a diagonal three in / direction
            }
        }
        else{
            if(!game_board[y-1][x-1]->is_empty()){
                if(!game_board[y+1][x+1]->is_empty()){
                    string path = "center left";
                    return check_three_in_a_row_diagonal(x, y, path);//checks if the coordinate is the center of a diagonal three in a row in \ direction
                }
                else{
                    if(!game_board[y-2][x-2]->is_empty()){
                        string path = "bottom right";
                        return check_three_in_a_row_diagonal(x, y, path);//checks if the coordinate is the bottom right of a diagonal three in  \ direction
                    }
                }
            }
            else if(!game_board[y+1][x+1]->is_empty()){
                if(!game_board[y+2][x+2]->is_empty()){
                    string path = "top left";
                    return check_three_in_a_row_diagonal(x, y, path);//checks if the coordinate is the top left of a diagonal three in  \ direction
                }
            }
        }
    }
    return new Empty("game");
}

void Boop::graduation(){
    for (int y = 0; y < SIZE; y++) {
        for (int x = 0; x < SIZE; x++) {
            if (!game_board[y][x]->is_empty()) {
                check_for_graduees(x, y);
            }
        }
    }
}

Piece* Boop::check_three_in_a_row(int x, int y) {
    if(x!=0){
        if(x!=5){
            if(game_board[y][x]->get_name() == game_board[y][x-1]->get_name() &&
            game_board[y][x]->get_name() == game_board[y][x+1]->get_name()){//checks if graduee is in the center of two other cats of the 
                if (game_board[y][x-1]->is_cat() && game_board[y][x+1]->is_cat()) {
                    get_player(game_board[y][x])->graduate_kittens();
                    delete_from_board(x,y);
                    delete_from_board(x+1,y);
                    delete_from_board(x-1,y);
                    return game_board[y][x];
                }
            }
            if(y!=0){
                if(y!=5){
                    if(game_board[y][x]->get_name() == game_board[y-1][x+1]->get_name() &&
                    game_board[y][x]->get_name() == game_board[y+1][x-1]->get_name()){
                        if(game_board[y-1][x+1]->is_cat() && game_board[y+1][x-1]->is_cat()){
                            get_player(game_board[y][x])->graduate_kittens();
                            delete_from_board(x,y);
                            delete_from_board(x+1,y-1);
                            delete_from_board(x-1,y+1);
                            return game_board[y][x];
                        }
                    }
                    else if(game_board[y][x]->get_name() == game_board[y+1][x+1]->get_name() &&
                    game_board[y][x]->get_name()== game_board[y-1][x-1]->get_name()){
                        if (game_board[y+1][x+1]->is_cat() && game_board[y-1][x-1]->is_cat()) {
                            get_player(game_board[y][x])->graduate_kittens();
                            delete_from_board(x,y);
                            delete_from_board(x+1,y+1);
                            delete_from_board(x-1,y-1);
                            return game_board[y][x];
                        }
                    }
                    else if(game_board[y][x]->get_name() == game_board[y+1][x-1]->get_name() &&
                    game_board[y][x]->get_name() == game_board[y-1][x+1]->get_name()){
                        if(game_board[y+1][x-1]->is_cat() && game_board[y-1][x+1]->is_cat()){
                            get_player(game_board[y][x])->graduate_kittens();
                            delete_from_board(x,y);
                            delete_from_board(x-1,y-1);
                            delete_from_board(x+1,y-1);
                            return game_board[y][x];
                        }
                    }
                }        
            }
        }
    }
    if(y!=0){
        if(y!=5){
            if(game_board[y][x]->get_name() == game_board[y-1][x]->get_name() &&
            game_board[y][x]->get_name()== game_board[y+1][x]->get_name()){
                if (game_board[y-1][x]->is_cat() && game_board[y+1][x]->is_cat()) {
                    get_player(game_board[y][x])->graduate_kittens();
                    delete_from_board(x,y);
                    delete_from_board(x,y+1);
                    delete_from_board(x,y-1);
                    return game_board[y][x];
                }
            }
        }
    }
    return new Empty("game");
}

void Boop::check_for_graduees(int x, int y){
    if(x!=0){
        if(x!=5){
            if(game_board[y][x]->get_name() == game_board[y][x-1]->get_name() &&
            game_board[y][x]->get_name() == game_board[y][x+1]->get_name()){//checks if graduee is in the center of two other cats of the 
                get_player(game_board[y][x])->graduate_kittens();
                delete_from_board(x,y);
                delete_from_board(x+1,y);
                delete_from_board(x-1,y);
                return;
            }
            if(y!=0){
                if(y!=5){
                    if(game_board[y][x]->get_name() == game_board[y-1][x+1]->get_name() &&
                    game_board[y][x]->get_name() == game_board[y+1][x-1]->get_name()){
                        get_player(game_board[y][x])->graduate_kittens();
                        delete_from_board(x,y);
                        delete_from_board(x+1,y-1);
                        delete_from_board(x-1,y+1);
                        return;
                    }
                    else if(game_board[y][x]->get_name() == game_board[y+1][x+1]->get_name() &&
                    game_board[y][x]->get_name()== game_board[y-1][x-1]->get_name()){
                        get_player(game_board[y][x])->graduate_kittens();
                        delete_from_board(x,y);
                        delete_from_board(x+1,y+1);
                        delete_from_board(x-1,y-1);
                        return;
                    }
                    else if(game_board[y][x]->get_name() == game_board[y+1][x-1]->get_name() &&
                    game_board[y][x]->get_name() == game_board[y-1][x+1]->get_name()){
                        get_player(game_board[y][x])->graduate_kittens();
                        delete_from_board(x,y);
                        delete_from_board(x-1,y-1);
                        delete_from_board(x+1,y-1);
                        return;
                    }
                }        
            }
        }
    }
    if(y!=0){
        if(y!=5){
            if(game_board[y][x]->get_name() == game_board[y-1][x]->get_name() &&
            game_board[y][x]->get_name()== game_board[y+1][x]->get_name()){
                get_player(game_board[y][x])->graduate_kittens();
                delete_from_board(x,y);
                delete_from_board(x,y+1);
                delete_from_board(x,y-1);

                return;
            }
        }
    }
}

Piece* Boop::check_three_in_a_row_horizontal(int x, int y, string path){
    if(path == "center"){
        if(game_board[y][x]->is_cat()){
            if(game_board[y][x+1]->get_name()==game_board[y][x]->get_name()){
                if(game_board[y][x+1]->is_cat()){
                    if(game_board[y][x-1]->get_name()==game_board[y][x]->get_name()){
                        if(game_board[y][x-1]->is_cat()){
                            return game_board[x][y];
                        }
                    }
                }
            }
        }
    }
    if(path == "left"){
        if(game_board[y][x]->is_cat()){
            if(game_board[y][x+1]->get_name()==game_board[y][x]->get_name()){
                if(game_board[y][x+1]->is_cat()){
                    if(game_board[y][x+2]->get_name()==game_board[y][x]->get_name()){
                        if(game_board[y][x+2]->is_cat()){
                            return game_board[y][x];
                        }
                    }
                }
            }
        }
    }
    if(path == "right"){
        if(game_board[y][x]->is_cat()){
            if(game_board[y][x-1]->get_name()==game_board[y][x]->get_name()){
                if(game_board[y][x-1]->is_cat()){
                    if(game_board[y][x-2]->get_name()==game_board[y][x]->get_name()){
                        if(game_board[y][x+2]->is_cat()){
                            return game_board[y][x];
                        }
                    }
                }
            }
        }
    }
    return new Empty("game");
}

Piece* Boop::check_three_in_a_row_vertical(int x, int y, string path){
    if(path == "center"){
        if(game_board[y][x]->is_cat()){
            if(game_board[y-1][x]->get_name()==game_board[y][x]->get_name()){
                if(game_board[y-1][x]->is_cat()){
                    if(game_board[y+1][x]->get_name()==game_board[y][x]->get_name()){
                        if(game_board[y+1][x]->is_cat()){
                            return game_board[y][x];
                        }
                    }
                }
            }
        }
    }
    if(path == "top"){
        if(game_board[y][x]->is_cat()){
            if(game_board[y+1][x]->get_name()==game_board[y][x]->get_name()){
                if(game_board[y+1][x]->is_cat()){
                    if(game_board[y+2][x]->get_name()==game_board[y][x]->get_name()){
                        if(game_board[y+2][x]->is_cat()){
                            return game_board[y][x];
                        }
                    }
                }
            }
        }
    }
    if(path == "bottom"){
        if(game_board[y][x]->is_cat()){
            if(game_board[y-1][x]->get_name()==game_board[y][x]->get_name()){
                if(game_board[y-1][x]->is_cat()){
                    if(game_board[y-2][x]->get_name()==game_board[y][x]->get_name()){
                        if(game_board[y-2][x]->is_cat()){
                            return game_board[y][x];
                        }
                    }
                }
            }
        }
    }
    return new Empty("game");
}

Piece* Boop::check_three_in_a_row_diagonal(int x, int y, string path){
    if(path == "center right"){
        if(game_board[y][x]->is_cat()){
            if(game_board[y-1][x+1]->get_name()==game_board[y][x]->get_name()){
                if(game_board[y-1][x+1]->is_cat()){
                    if(game_board[y+1][x-1]->get_name()==game_board[y][x]->get_name()){
                        if(game_board[y+1][x-1]->is_cat()){
                            return game_board[y][x];
                        }
                    }
                }
            }
        }
    }
    if(path == "center left"){
        if(game_board[y][x]->is_cat()){
            if(game_board[y-1][x-1]->get_name()==game_board[y][x]->get_name()){
                if(game_board[y-1][x-1]->is_cat()){
                    if(game_board[y+1][x+1]->get_name()==game_board[y][x]->get_name()){
                        if(game_board[y+1][x+1]->is_cat()){
                            return game_board[y][x];
                        }
                    }
                }
            }
        }
    }
    if(path == "bottom left"){
        if(game_board[y][x]->is_cat()){
            if(game_board[y-1][x+1]->get_name()==game_board[y][x]->get_name()){
                if(game_board[y-1][x+1]->is_cat()){
                    if(game_board[y-2][x+2]->get_name()==game_board[y][x]->get_name()){
                        if(game_board[y-2][x+2]->is_cat()){
                            return game_board[y][x];
                        } 
                    }
                }
            }
        }
    }
    if(path == "bottom right"){
        if(game_board[y][x]->is_cat()){
            if(game_board[y-1][x-1]->get_name()==game_board[y][x]->get_name()){
                if(game_board[y-1][x-1]->is_cat()){
                    if(game_board[y-2][x-2]->get_name()==game_board[y][x]->get_name()){
                        if(game_board[y-2][x-2]->is_cat()){
                            return game_board[y][x];
                        }
                    }
                }
            }
        }
    }
    if(path == "top left"){
        if(game_board[y][x]->is_cat()){
            if(game_board[y+1][x+1]->get_name()==game_board[y][x]->get_name()){
                if(game_board[y+1][x+1]->is_cat()){
                    if(game_board[y+2][x+2]->get_name()==game_board[y][x]->get_name()){
                        if(game_board[y+2][x+2]->is_cat()){
                            return game_board[y][x];
                        }
                    }
                }
            }
        }
    }
    if(path == "top right"){
        if(game_board[y][x]->is_cat()){
            if(game_board[y+1][x-1]->get_name()==game_board[y][x]->get_name()){
                if(game_board[y+1][x-1]->is_cat()){
                    if(game_board[y+2][x-2]->get_name()==game_board[y][x]->get_name()){
                        if(game_board[y+2][x-2]->is_cat()){
                            return game_board[y][x];
                        }
                    }
                }
            }
        }   
    }
    return new Empty("game");
}

Player* Boop::check_eight(){
    if(player_1_cat ==8){
        return player_1;
    }
    if(player_2_cat == 8){
        return player_2;
    }
    return nullptr;
}

Player* Boop::check_victory() {
    Piece* winning_piece;
    if(player_1_cat >= 3 || player_2_cat >= 3) {
        for(int y_axis = 0; y_axis < SIZE; y_axis++){
            for(int x_axis = 0; x_axis < SIZE; x_axis++){
                if(game_board[y_axis][x_axis]->is_cat()){
                    // winning_piece = check_coordinates_for_three(y_axis, x_axis);
                    winning_piece = check_three_in_a_row(x_axis, y_axis);
                    if (!winning_piece->is_empty()) {
                        return get_player(winning_piece);
                    }
                }
            }
        }
    }
    return check_eight();
}

void Boop::player_turn(int player_num) {
    Player* current;
    char player_choice;
    Piece* play_piece;
    int x_loc, y_loc;
    bool repeat = false;
    if (player_num == 1) {
        current = player_1;
    }
    else {
        current = player_2;
    }
    cout << endl << current->get_name() << "'s turn: "<< endl;
    current->display_pieces();
    while (true) {
    cout << "Please choose which you would like to play";
    if (repeat == true) {
        cout << " again.";
    }
    cout << endl;
    cout << "A. Cat         B. Kitten" << endl;
    cin >> player_choice;
        if (toupper(player_choice) == 'A') {
            if (current->check_cat()) {
                play_piece = current->retrieve_cat();
                break;
            }
        }
        else if(toupper(player_choice) == 'B'){
            if (current->check_kitten()) {
            play_piece = current->retrieve_kitten();
            break;
            }
        }
        repeat = true;
    }    
    repeat = false;
    while (true) {
        if (repeat == false) {
            cout << "Where would you like to put the piece?" << endl;
        }
        else {
            cout << "Where ON THE 6x6 BOARD would you like to put the piece?" << endl;
        }
        cout << "Please enter x, y coordinate: " << endl;
        cin >> x_loc;
        cin >> y_loc;
        if (x_loc <= 6 && x_loc > 0){
            if (y_loc <= 6 && y_loc > 0){
                break;
            }
        }
        repeat = true;
    }
    repeat = false;
    x_loc--;
    y_loc--;
    bool turn_complete = place_piece(play_piece, x_loc, y_loc);
    if (!turn_complete) {
        if(get_player(play_piece) == player_1){
            current->receive_pieces(play_piece);
            player_turn(1);
        }
        else{
            current->receive_pieces(play_piece);
            player_turn(2);
        }
    }
}

void Boop::play_game(){
    int turn_count = 0;
    while (true) {
        if (turn_count % 2 == 0) {
            player_turn(1);
        }
        else {
            player_turn(2);
        }
        if (check_victory() != nullptr) {
            break;
        }
        graduation();
        display();
        turn_count++;
    }
    display();
    Player* winner = check_victory();
    cout << winner->get_name() << " is the winner!" << endl;
    return;
}
