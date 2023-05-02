#include <iostream>
#include <vector>
#include <string>
#include "game.h"
#include "piece.h"
#include "player.h"
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

Boop::Boop(string player_name_1, string player_name_2) {
    player_1 = new Player(player_name_1);
    player_2 = new Player(player_name_2);
    for (int i = 0; i < SIZE; i++) {
        DoublyLinkedList temp;
        game_board.push_back(temp);
    }
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
                if(!current->key->is_cat()){
                    if(current->key->get_name() == player_1->get_name()){
                        temp = 1;
                    }
                    else if(current->key->get_name() == player_2->get_name()){
                        temp = 3;
                    }
                }
                if(current->key->is_cat()){
                    if(current->key->get_name() == player_1->get_name()){
                        temp = 2;
                    }
                    else if(current->key->get_name() == player_2->get_name()){
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

Player* Boop::get_player(Piece* target_piece) {
    if (target_piece->get_name() == player_1->get_name()) {
        return player_1;
    }
    else {
        return player_2;
    }
}

void Boop::place_piece(Piece* cat_or_kitten, int x, int y) {
    if (game_board[y].locate(x) == nullptr) {    
        game_board[y].append(cat_or_kitten, x);
    }
    if (cat_or_kitten->is_cat()) {
        if (get_player(cat_or_kitten) == player_1) {
            player_1_cat++;
        }
        else {
            player_2_cat++;
        }
    }
}

void Boop::check_coordinates_for_boop(int x, int y){
    string current_player = game_board[y].locate(x)->key->get_name();
    Node* right = game_board[y].locate(x+1);
    Node* top = game_board[y-1].locate(x);
    Node* bottom = game_board[y+1].locate(x);
    if(right!=nullptr){
        if(right->key->get_name()!= current_player){
            //boop function
        }
        right = game_board[y].locate(x-1);
        if(right!=nullptr){
            if(right->key->get_name()!= current_player){
                //boop function
            }
        }
    }
    if(top!=nullptr){
        if(top->key->get_name()!= current_player){
            //boop function
        }
    }
    top = game_board[y-1].locate(x+1);//top right
    if(top!=nullptr){
        if(top->key->get_name()!= current_player){
            //boop function
        }
    }
    top = game_board[y-1].locate(x-1);//top left
    if(top!=nullptr){
        if(top->key->get_name()!= current_player){
            //boop function
        }
    }
    if(bottom!=nullptr){
        if(bottom->key->get_name()!= current_player){
            //boop function
        }
    }
    bottom = game_board[y+1].locate(x+1);//bottom right
    if(bottom!=nullptr){
        if(bottom->key->get_name()!= current_player){
            //boop function
        }
    }
    bottom = game_board[y+1].locate(x-1);//bottom left
    if(bottom!=nullptr){
        if(bottom->key->get_name()!= current_player){
            //boop function
        }
    }
}

// void Boop::boop_piece(int x_loc, int y_loc) { need work
//     //boop
//     if ( ) {
//         Piece* removed_piece = remove_button(x_loc, y_loc);
//         Player* temp = get_player(removed_piece);
//         temp->receive_pieces(removed_piece);
//     }

// }

Piece* Boop::check_coordinates_for_three(int x, int y){
    //check-right-left
    //MAIN ISSUE: Segmentation faults with the y-1 and y-2
    Node* current = game_board[y].locate(x);
    Node* top = game_board[y-1].locate(x);
    Node* bottom = game_board[y+1].locate(x);
    if(current->next!=nullptr){//checks if the coordineate is to the left of another piece
        if(current->prev!=nullptr){//checks if the coordinate is the center of three in a row
            string path = "center";
            return check_three_in_a_row_horizontal(x, y, path);
        }
        else if(current->next->next!=nullptr){//checks if the coordinate is the leftmost piece of three in a row
            string path = "left";
            return check_three_in_a_row_horizontal(x, y, path);
        }
    }
    else if(current->prev!=nullptr){
        if(current->prev->prev!=nullptr){//checks if the coordinate is the rightmost piece of three in a row
            string path = "right";
            return check_three_in_a_row_horizontal(x, y, path);
        }
    }
    else if(top!=nullptr){
        if(bottom!=nullptr){
            string path = "center";
            return check_three_in_a_row_vertical(x, y, path);//checks if the coordinate is the center of a vertical three in a row
        }
        else{
            top = game_board[y-2].locate(x);
            if(top!=nullptr){
                string path = "bottom";
                return check_three_in_a_row_vertical(x, y, path);//checks if the coordinate is the bottom of a vertical three in a row
            }
        }
    }
    else if(bottom!=nullptr){
        bottom = game_board[y+2].locate(x);
        if(bottom!=nullptr){
            string path = "top";
            return check_three_in_a_row_vertical(x, y, path);//checks if the coordinate is the top of a vertical three in a row
        }
    }
    else{
        top = game_board[y-1].locate(x+1);
        bottom = game_board[y+1].locate(x-1);
        if(top!=nullptr){
            if(bottom!=nullptr){
                string path = "center right";
                return check_three_in_a_row_diagonal(x, y, path);//checks if the coordintae is the center of a diagonal three in a row in / direction
            }
            else{
                top = game_board[y-2].locate(x+2);
                if(top!=nullptr){
                    string path = "bottom left";
                    return check_three_in_a_row_diagonal(x, y, path);//checks if the coordinate is the bottom left of a diagonal three in / direction
                }
            }
        }
        else if(bottom!=nullptr){
            bottom = game_board[y+2].locate(x-2);
            if(bottom!=nullptr){
                string path = "top right";
                return check_three_in_a_row_diagonal(x, y, path);//checks if the coordinate is the top right of a diagonal three in / direction
            }
        }
        else{
            top = game_board[y-1].locate(x-1);
            bottom = game_board[y+1].locate(x+1);
            if(top!=nullptr){
                if(bottom!=nullptr){
                    string path = "center left";
                    return check_three_in_a_row_diagonal(x, y, path);//checks if the coordinate is the center of a diagonal three in a row in \ direction
                }
                else{
                    top = game_board[y-2].locate(x-2);
                    if(top!=nullptr){
                        string path = "bottom right";
                        return check_three_in_a_row_diagonal(x, y, path);//checks if the coordinate is the bottom right of a diagonal three in  \ direction
                    }
                }
            }
            else if(bottom!=nullptr){
                bottom = game_board[y+2].locate(x+2);
                if(bottom!=nullptr){
                    string path = "top left";
                    return check_three_in_a_row_diagonal(x, y, path);//checks if the coordinate is the top left of a diagonal three in  \ direction
                }
            }
        }
    }
    return nullptr;
}

Piece* Boop::check_three_in_a_row_horizontal(int x, int y, string path){
    if(path == "center"){
        Node* current = game_board[y].locate(x);
        Node* right_neighbor = game_board[y].locate(x+1);
        Node* left_neighbor = game_board[y].locate(x-1);
        if(current->key->is_cat()){
            if(right_neighbor->key->get_name()==current->key->get_name()){
                if(right_neighbor->key->is_cat()){
                    if(left_neighbor->key->get_name()==current->key->get_name()){
                        if(left_neighbor->key->is_cat()){
                            return current->key;
                        }
                    }
                }
            }
        }
    }
    if(path == "left"){
        Node* current = game_board[y].locate(x);
        Node* right_neighbor = game_board[y].locate(x+1);
        Node* right_right_neighbor = game_board[y].locate(x+2);
        if(current->key->is_cat()){
            if(right_neighbor->key->get_name()==current->key->get_name()){
                if(right_neighbor->key->is_cat()){
                    if(right_right_neighbor->key->get_name()==current->key->get_name()){
                        if(right_right_neighbor->key->is_cat()){
                            return current->key;
                        }
                    }
                }
            }
        }
    }
    if(path == "right"){
        Node* current = game_board[y].locate(x);
        Node* left_neighbor = game_board[y].locate(x-1);
        Node* left_left_neighbor = game_board[y].locate(x-2);
        if(current->key->is_cat()){
            if(left_neighbor->key->get_name()==current->key->get_name()){
                if(left_neighbor->key->is_cat()){
                    if(left_left_neighbor->key->get_name()==current->key->get_name()){
                        if(left_left_neighbor->key->is_cat()){
                            return current->key;
                        }
                    }
                }
            }
        }
    }
    return nullptr;
}

Piece* Boop::check_three_in_a_row_vertical(int x, int y, string path){
    if(path == "center"){
        Node* current = game_board[y].locate(x);
        Node* upper_neighbor = game_board[y-1].locate(x);
        Node* lower_neighbor = game_board[y+1].locate(x);
        if(current->key->is_cat()){
            if(upper_neighbor->key->get_name()==current->key->get_name()){
                if(upper_neighbor->key->is_cat()){
                    if(lower_neighbor->key->get_name()==current->key->get_name()){
                        if(lower_neighbor->key->is_cat()){
                            return current->key;
                        }
                    }
                }
            }
        }
    }
    if(path == "top"){
        Node* current = game_board[y].locate(x);
        Node* lower_neighbor = game_board[y+1].locate(x);
        Node* lower_lower_neighbor = game_board[y+2].locate(x);
        if(current->key->is_cat()){
            if(lower_neighbor->key->get_name()==current->key->get_name()){
                if(lower_neighbor->key->is_cat()){
                    if(lower_lower_neighbor->key->get_name()==current->key->get_name()){
                        if(lower_lower_neighbor->key->is_cat()){
                            return current->key;
                        }
                    }
                }
            }
        }
    }
    if(path == "bottom"){
        Node* current = game_board[y].locate(x);
        Node* upper_neighbor = game_board[y-1].locate(x);
        Node* upper_upper_neighbor = game_board[y-2].locate(x);
        if(current->key->is_cat()){
            if(upper_neighbor->key->get_name()==current->key->get_name()){
                if(upper_neighbor->key->is_cat()){
                    if(upper_upper_neighbor->key->get_name()==current->key->get_name()){
                        if(upper_upper_neighbor->key->is_cat()){
                            return current->key;
                        }
                    }
                }
            }
        }
    }
    return nullptr;
}

Piece* Boop::check_three_in_a_row_diagonal(int x, int y, string path){
    if(path == "center right"){
        Node* current = game_board[y].locate(x);
        Node* top = game_board[y-1].locate(x+1);
        Node* bottom = game_board[y+1].locate(x-1);
        if(current->key->is_cat()){
            if(top->key->get_name()==current->key->get_name()){
                if(top->key->is_cat()){
                    if(bottom->key->get_name()==current->key->get_name()){
                        if(bottom->key->is_cat()){
                            return current->key;
                        }
                    }
                }
            }
        }
    }
    if(path == "center left"){
        Node* current = game_board[y].locate(x);
        Node* top = game_board[y-1].locate(x-1);
        Node* bottom = game_board[y+1].locate(x+1);
        if(current->key->is_cat()){
            if(top->key->get_name()==current->key->get_name()){
                if(top->key->is_cat()){
                    if(bottom->key->get_name()==current->key->get_name()){
                        if(top->key->is_cat()){
                            return current->key;
                        }
                    }
                }
            }
        }
    }
    if(path == "bottom left"){
        Node* current = game_board[y].locate(x);
        Node* top = game_board[y-1].locate(x+1);
        Node* top_top = game_board[y-2].locate(x+2);
        if(current->key->is_cat()){
            if(top->key->get_name()==current->key->get_name()){
                if(top->key->is_cat()){
                    if(top_top->key->get_name()==current->key->get_name()){
                        if(top_top->key->is_cat()){
                            return current->key;
                        } 
                    }
                }
            }
        }
    }
    if(path == "bottom right"){
        Node* current = game_board[y].locate(x);
        Node* top = game_board[y-1].locate(x-1);
        Node* top_top = game_board[y-2].locate(x-2);
        if(current->key->is_cat()){
            if(top->key->get_name()==current->key->get_name()){
                if(top->key->is_cat()){
                    if(top_top->key->get_name()==current->key->get_name()){
                        if(top_top->key->is_cat()){
                            return current->key;
                        }
                    }
                }
            }
        }
    }
    if(path == "top left"){
        Node* current = game_board[y].locate(x);
        Node* top = game_board[y+1].locate(x+1);
        Node* top_top = game_board[y+2].locate(x+2);
        if(current->key->is_cat()){
            if(top->key->get_name()==current->key->get_name()){
                if(top->key->is_cat()){
                    if(top_top->key->get_name()==current->key->get_name()){
                        if(top_top->key->is_cat()){
                            return current->key;
                        }
                    }
                }
            }
        }
    }
    if(path == "top right"){
        Node* current = game_board[y].locate(x);
        Node* top = game_board[y+1].locate(x-1);
        Node* top_top = game_board[y+2].locate(x-2);
        if(current->key->is_cat()){
            if(top->key->get_name()==current->key->get_name()){
                if(top->key->is_cat()){
                    if(top_top->key->get_name()==current->key->get_name()){
                        if(top_top->key->is_cat()){
                            return current->key;
                        }
                    }
                }
            }
        }   
    }
    return nullptr;
}

Player* Boop::check_eight(){
    int first_player = 0;
    int second_player = 0;
    for(int i = 0; i < SIZE; i++){
        Node* current = game_board[i].get_head();
        while(current != nullptr){
            if(current->key->get_name() == "player 1"){
                if(current->key->is_cat()){
                    first_player++;
                }
            }
            if(current->key->get_name() == "player 2"){
                if(current->key->is_cat()){
                    second_player++;
                }
            }
        }
    }
    if(first_player == 8){
        return player_1;
    }
    if(second_player == 8){
        return player_2;
    }
    return nullptr;
}

Player* Boop::check_victory() {
    Piece* winning_piece;
    if(player_1_cat >= 3 || player_2_cat >= 3) {
        for(int i = 0; i < SIZE; i++){
            Node* current = game_board[i].get_head();
            while(current != nullptr){
                if(current->key->is_cat()){
                    winning_piece = check_coordinates_for_three(i, current->location);
                    if (winning_piece != nullptr) {
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
    y_loc--;
    place_piece(play_piece, x_loc, y_loc);
    check_coordinates_for_boop(x_loc, y_loc);
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
