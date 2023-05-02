#ifndef CAT_H
#define CAT_H
#include "piece.h"
#include <string>

class Cat : public Piece {
private:
    std::string player_name;
protected:
public:
    ~Cat();
    Cat(std::string player_name);
    bool is_cat();
    std::string get_name();
    void display();
};

#endif
