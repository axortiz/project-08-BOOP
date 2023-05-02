#ifndef PIECE_H
#define PIECE_H
#include <string>


class Piece {
private:
    std::string player;
public:
    Piece();
    Piece(std::string);
    ~Piece ();
    virtual std::string get_name() = 0;
    virtual void display() = 0;
    virtual bool is_cat() = 0;
};

#endif
