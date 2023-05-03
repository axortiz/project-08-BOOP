#ifndef GAME_H
#define GAME_H
#include "player.h"
#include "piece.h"
#include <vector>
#include <string>


class Boop {
private:
    std::vector <std::vector <Piece*>> game_board;
    Player* player_1;
    Player* player_2;
    int player_1_cat;
    int player_2_cat;
protected:
public:
    Boop(std::string player_1, std::string player_2);
    void display();
    Player* get_player(Piece*);
    bool place_piece(Piece* cat_or_kitten, int x, int y);
    Piece* remove_button(int x_loc, int y_loc);
    void check_coordinates_for_boop(int x, int y);
    void boop_piece(int x_loc, int y_loc, std::string path);
    void boop_cat(Piece* cat_or_kitten, int x_loc, int y_loc);
    bool check_boop_path(int x_loc, int y_loc);
    void deduct_cats(Player*);
    Piece* check_coordinates_for_three(int x, int y); 
    Piece* check_three_in_a_row_horizontal(int x, int y, std::string path);
    Piece* check_three_in_a_row_vertical(int x, int y, std::string path);
    Piece* check_three_in_a_row_diagonal(int x, int y, std::string path); 
    Player* check_eight(); 
    Player* check_victory();
    void player_turn(int);
    void play_game();
};

#endif
