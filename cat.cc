#include <iostream>
#include "cat.h"
using namespace std;

Cat::~Cat() {}

Cat::Cat(string name){
    player_name = name;
}

bool Cat::is_cat() {
    return true;
}

bool Cat::is_empty() {
    return false;
}

string Cat::get_name() {
    return player_name;
}

void Cat::display() {
    cout << "Cat ";
}
