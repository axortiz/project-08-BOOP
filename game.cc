#include <iostream>
#include <vector>
#include "game.h"
using namespace std;

Node::Node(Piece* new_key, int x_loc) 
    : key(new_key),
      location(x_loc) 
{
}

DoublyLinkedList::DoublyLinkedList(){
    head = nullptr;
    tail = nullptr;
}

bool DoublyLinkedList::empty() {
    return tail == nullptr;
}

void DoublyLinkedList::append(Piece* new_key, int x_loc) {
    Node* address_of_new_node = new Node(new_key, x_loc);
    if (empty()) {
        head = address_of_new_node;
        tail = address_of_new_node;
        return;
    }
    else if(x_loc < head->location){
        head = address_of_new_node;
        head->next = tail;
        tail->prev = head;
    }
    else if(x_loc > tail->location){
        tail->next = address_of_new_node;
        tail = address_of_new_node;
    }
    else if(x_loc > head->location){
        Node* current = head;
        while(x_loc > head->location){
            current = current->next;
        }
        current->prev->next = address_of_new_node;
        address_of_new_node->prev = current->prev;
        current->prev = address_of_new_node;
        address_of_new_node->next = current;
    }
    tail->next = address_of_new_node;
    address_of_new_node->prev = tail;
    tail = address_of_new_node;
}

void Boop::display() {
    cout << "The board is: " << endl;
    Node* current;//How do you get access to the doublylinkedlist private
    for(int y_axis = 0; y_axis < SIZE ; y_axis++){
        if(game_board[y_axis].empty()){
            for(int x = 0; x < SIZE-1 ; x++){
                cout << "0 ";
            }
            cout << "0" << endl; // cout here is for spacing purposes at the end of the line
        }
        else{
            current = game_board[y_axis].get_head();
            for(int x = 0; x < SIZE ; x++){
                int temp;
                if(current->key == Kitten){
                    if(Kitten.get_name() == "Player 1"){
                        temp = 1;
                    }
                    else if(Kitten.get_name() == "Player 2"){
                        temp = 3;
                    }
                }
                if(current->key == Cat){
                    if(Cat.get_name() == "Player 1"){
                        temp = 2;
                    }
                    else if(Cat.get_name() == "Player 2"){
                        temp = 4;
                    }
                }
                if(current->location == x){
                    cout << temp << ' ';
                }
                if(current->location != x){
                    if(x != SIZE-1){
                        cout << "0 ";
                    }
                current = current->next;
                }
            }
        }
    }
}

Node* DoublyLinkedList::get_head() {
    return head;
}

Node* DoublyLinkedList::locate(int search_key) {
    Node* current = head;
    return recursive_locate(current, search_key);
}

Node* DoublyLinkedList::recursive_locate(Node* current, int search_key) {
    if (current->location == search_key) {
        return current;
    }
    else if (current == tail) {
        return nullptr;
    }
    return recursive_locate(current->next, search_key);
}

Boop::Boop(string player_name_1, string player_name_2)
    : player_1(player_name_1),
      player_2(player_name_2),
{
    for (int i = 0; i < SIZE; i++) {
        DoublyLinkedList temp;
        game_board.push_back(temp);
    }
}

void Boop::place_piece(Piece* cat_or_kitten, int x, int y) {
    if (game_board[y].locate(x) == nullptr) {    
        game_board[y].append(cat_or_kitten, x);
    }
}
