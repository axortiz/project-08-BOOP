#include <iostream>
#include <vector>
#include "game.h"
using namespace std;

Node::Node(Piece* new_key, int x_loc) 
    : key(new_key),
      location(x_loc) 
{
}

DoublyLinkedList::DoublyLinkedList() {
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
        display();
        return;
    }
    tail->next = address_of_new_node;
    address_of_new_node->prev = tail;
    tail = address_of_new_node;
    display();
}

void DoublyLinkedList::display() {
    cout << "The SLL is: ";
    Node* current = head;
    while (current != nullptr) {
        current->key->display();
        cout << ' ';
        current = current->next;
    }
    cout << endl;
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
      Player_2(player_name_2),
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
