#include <iostream>
#include "empty.h"
using namespace std;

Empty::~Empty() {}

Empty::Empty(string given_name) {
    name = given_name;
}

bool Empty::is_empty() {
    return true;
}

bool Empty::is_cat() {
    return false;
}

void Empty::display() {
    cout << "Empty " << endl;
}

string Empty::get_name() {
    return name;
}
