#include <iostream>
#include <vector>
#include <string>
#include "game.h"
#include "constants.h"
#include "piece.h"
#include "player.h"
#include "kitten.h"
#include "cat.h"

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
            temp.push_back(new Piece("0"));
        }
        game_board.push_back(temp);
    }
}

void Boop::display() {
    cout << "The board is: " << endl;
    for(int y_axis = 0; y_axis < SIZE ; y_axis++){
        for(int x_axis = 0; x_axis < SIZE ; x_axis++){
            if(game_board[y_axis][x_axis]->is_cat()){
                if(game_board[y_axis][x_axis]->get_name() == player_1->get_name()){
                    cout << "2 ";
                }
                else if(game_board[y_axis][x_axis]->get_name() == player_2->get_name()){
                    cout << "4 ";
                }
            }
            else if(!game_board[y_axis][x_axis]->is_cat()){
                if(game_board[y_axis][x_axis]->get_name() == player_1->get_name()){
                    cout << "1 ";
                }
                else if(game_board[y_axis][x_axis]->get_name() == player_2->get_name()){
                    cout << "3 ";
                }
            }
            else{
                cout << "0 ";
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
    if(game_board[y][x] != empty){
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
    if(x!=0){
        if(game_board[y][x-1] != empty){
        boop_piece(x-1, y, "left");
        }
    }
    if(x!=5){
        if(game_board[y][x+1] != empty){
            boop_piece(x, y, "right");
        }
    }
    if (y != 0) {
        if(game_board[y-1][x] != empty){
            boop_piece(x, y, "top");
        }
        if(game_board[y-1][x+1] != empty){
            boop_piece(x, y, "top_r");
        }
        if(game_board[y-1][x-1] != empty){
            boop_piece(x, y, "top_l");
        }
    }
    if (y != 5) {
        if(game_board[y+1][x] != empty){
            boop_piece(x, y, "bottom");
        }
        if(game_board[y+1][x+1] != empty){
            boop_piece(x, y, "bottom_r");
        }
        if(game_board[y+1][x-1] != empty){
            boop_piece(x, y, "bottom_l");
        }
    }
}

Piece* Boop::remove_button(int x_loc, int y_loc){ // DELETE LINE IS SKETCHY HERE
    Piece* removed_piece = game_board[y_loc][x_loc];
    game_board[y_loc][x_loc] = empty;
    return removed_piece;
}

bool Boop::check_boop_path(int x_loc, int y_loc) {
    if (game_board[y_loc][x_loc] == empty) {
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
        if (x_loc == 6){
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
        if (x_loc == 1){
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
        if (y_loc == 1){
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
        if (y_loc == 6){
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
        if (y_loc == 1 && x_loc == 6){
            Piece* removed_piece = remove_button(x_loc, y_loc);
            Player* temp = get_player(removed_piece);
            temp->receive_pieces(removed_piece);
            if(removed_piece->is_cat()){
                deduct_cats(temp);
            }
        }
        else{
            if(check_boop_path(x_loc+1, y_loc-1)){
                Piece* removed_piece = remove_button(x_loc, y_loc);
                boop_cat(removed_piece, x_loc+1, y_loc-1);
            }
        }
    }
    if (path == "top left") {
        if (y_loc == 1 && x_loc == 1){
            Piece* removed_piece = remove_button(x_loc, y_loc);
            Player* temp = get_player(removed_piece);
            temp->receive_pieces(removed_piece);
            if(removed_piece->is_cat()){
                deduct_cats(temp);
            }
        }
        else{
            if(check_boop_path(x_loc-1, y_loc-1)){
                Piece* removed_piece = remove_button(x_loc, y_loc);
                boop_cat(removed_piece, x_loc-1, y_loc-1);
            }
        }
    }
    if (path == "bottom right") {
        if (y_loc == 6 && x_loc == 6){
            Piece* removed_piece = remove_button(x_loc, y_loc);
            Player* temp = get_player(removed_piece);
            temp->receive_pieces(removed_piece);
            if(removed_piece->is_cat()){
                deduct_cats(temp);
            }
        }
        else{
            if(check_boop_path(x_loc+1, y_loc+1)){
                Piece* removed_piece = remove_button(x_loc, y_loc);
                boop_cat(removed_piece, x_loc+1, y_loc+1);
            }
        }
    }
    if (path == "bottom left") {
        if (y_loc == 6 && x_loc == 1){
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
                boop_cat(removed_piece, x_loc-1, y_loc+1);
            }
        }
    }
}

Piece* Boop::check_coordinates_for_three(int x, int y){
    if(game_board[y][x+1]!=empty){//checks if the coordineate is to the left of another piece
        if(game_board[y][x-1]!=empty){//checks if the coordinate is the center of three in a row
            string path = "center";
            return check_three_in_a_row_horizontal(x, y, path);
        }
        else if(game_board[y][x+2]!=empty){//checks if the coordinate is the leftmost piece of three in a row
            string path = "left";
            return check_three_in_a_row_horizontal(x, y, path);
        }
    }
    else if(game_board[y][x-1]!=empty){
        if(game_board[y][x-2]!=empty){//checks if the coordinate is the rightmost piece of three in a row
            string path = "right";
            return check_three_in_a_row_horizontal(x, y, path);
        }
    }
    else if(game_board[y-1][x]!=empty){
        if(game_board[y+1][x]!=empty){
            string path = "center";
            return check_three_in_a_row_vertical(x, y, path);//checks if the coordinate is the center of a vertical three in a row
        }
        else{
            if(game_board[y-2][x]!=empty){
                string path = "bottom";
                return check_three_in_a_row_vertical(x, y, path);//checks if the coordinate is the bottom of a vertical three in a row
            }
        }
    }
    else if(game_board[y+1][x]!=nullptr){
        if(game_board[y+2][x]!=empty){
            string path = "top";
            return check_three_in_a_row_vertical(x, y, path);//checks if the coordinate is the top of a vertical three in a row
        }
    }
    else{
        if(game_board[y-1][x+1]!=empty){
            if(game_board[y+1][x-1]!=empty){
                string path = "center right";
                return check_three_in_a_row_diagonal(x, y, path);//checks if the coordintae is the center of a diagonal three in a row in / direction
            }
            else{
                if(game_board[y-2][x+2]!=empty){
                    string path = "bottom left";
                    return check_three_in_a_row_diagonal(x, y, path);//checks if the coordinate is the bottom left of a diagonal three in / direction
                }
            }
        }
        else if(game_board[y+1][x]!=empty){
            if(game_board[y+2][x-2]!=empty){
                string path = "top right";
                return check_three_in_a_row_diagonal(x, y, path);//checks if the coordinate is the top right of a diagonal three in / direction
            }
        }
        else{
            if(game_board[y-1][x-1]!=empty){
                if(game_board[y+1][x+1]!=empty){
                    string path = "center left";
                    return check_three_in_a_row_diagonal(x, y, path);//checks if the coordinate is the center of a diagonal three in a row in \ direction
                }
                else{
                    if(game_board[y-2][x-2]!=empty){
                        string path = "bottom right";
                        return check_three_in_a_row_diagonal(x, y, path);//checks if the coordinate is the bottom right of a diagonal three in  \ direction
                    }
                }
            }
            else if(game_board[y+1][x+1]!=empty){
                if(game_board[y+2][x+2]!=empty){
                    string path = "top left";
                    return check_three_in_a_row_diagonal(x, y, path);//checks if the coordinate is the top left of a diagonal three in  \ direction
                }
            }
        }
    }
    return empty;
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
    return empty;
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
    return empty;
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
    return empty;
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
                    winning_piece = check_coordinates_for_three(y_axis, x_axis);
                    if (winning_piece != empty) {
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
    string player_choice;
    Piece* play_piece;
    int x_loc, y_loc;
    if (player_num == 1) {
        current = player_1;
    }
    else {
        current = player_2;
    }
    cout << endl << current->get_name() << "'s turn: "<< endl;
    current->display_pieces();
    cout << "Please choose which you would like to play" << endl;
    cout << "A. Cat         B. Kitten" << endl;
    cin >> player_choice;
    if (player_choice == "A") {
        play_piece = current->retrieve_cat();
    }
    else {
        play_piece = current->retrieve_kitten();
    }
    cout << "Where would you like to put the piece?" << endl;
    cout << "Please enter x, y coordinate: " << endl;
    cin >> x_loc;
    cin >> y_loc;
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
    else {
        display();
    }
}

void Boop::play_game(){
    int turn_count = 0;
    while (check_victory() == nullptr) {
        if (turn_count % 2 == 0) {
            player_turn(1);
        }
        else {
            player_turn(2);
        }
        turn_count++;
    }
    Player* winner = check_victory();
    cout << winner->get_name() << " is the winner!" << endl;
    return;
}
