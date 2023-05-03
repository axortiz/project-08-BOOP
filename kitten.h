#ifndef KITTEN_H
#define KITTEN_H
#include "piece.h"
#include <string>

class Kitten : public Piece {
private:
    std::string player_name;
protected:
public:
    ~Kitten();
    Kitten(std::string);
    bool is_cat();
    bool is_empty();
    std::string get_name();
    void display();
};

 #endif
