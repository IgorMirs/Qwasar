#include "my_bsq.h"

//TODO variadic macros

int main(int ac, char** av) {
    if (ac != 2) {
        return -1;
    }

    struct board_map* my_bsq = Map.new(av[1]);
    my_bsq->print(my_bsq);
    //finds the biggest square and places it on a board
    my_bsq->set_bsq(my_bsq); 
    my_bsq->print(my_bsq);
    my_bsq->delete(my_bsq);

    return 0;
}