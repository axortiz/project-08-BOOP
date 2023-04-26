#ifndef HEADER_H
#define HEADER_H
#include "board.h"
#include "player.h"
#include "piece.h"
#include <vector>
const int SIZE = 6;
using namespace std;

struct Node {
    Piece* key;
    int location;
    Node* prev;
    Node* next;
    Node(Piece* new_key, int x_loc);
};

struct DoublyLinkedList {
private:
    Node* head;
    Node* tail;
public:
    DoublyLinkedList();
    bool empty();
    void append(Piece* new_key, int x_loc);
    void display();
    Node* get_head();
    Node* locate(int search_key);
    Node* recursive_locate(Node* current, int search_key);
};

class Boop {
private:
    vector <DoublyLinkedList> game_board;
    Player player_1;
    Player player_2;
protected:
public:
    Boop(string player_1, string player_2);
    void place_piece(Piece* cat_or_kitten, int x, int y);
    vector <int> check_coordinates(int x, int y);
    bool check_victory();
    Piece* remove_button(int x_loc, int y_loc);
    void boop_cat(int x_loc, int y_loc);
};

#endif
