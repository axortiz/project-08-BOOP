#include <iostream>
#include "kitten.h"
using namespace std;

Kitten::~Kitten() {}

Kitten::Kitten(string name) {
     player_name = name;
}

bool Kitten::is_cat() {
    return false;
}

bool Kitten::is_empty() {
    return false;
}

string Kitten::get_name() {
    return player_name;
}

void Kitten::display() {
    cout << "Kitten "; // work on this after we have separate display
}
