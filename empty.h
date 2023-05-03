#ifndef EMPTY_H
#define EMPTY_H
#include "piece.h"
#include <string>

class Empty : public Piece {
private:
    std::string name;
protected:
public:
    ~Empty();
    Empty(std::string given_name);
    bool is_empty();
    bool is_cat();
    void display();
    std::string get_name();
};

#endif
