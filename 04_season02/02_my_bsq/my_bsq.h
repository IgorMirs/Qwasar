#ifndef BSQ_H
#define BSQ_H

#include <stddef.h>
#include "my_readline.h"
#include "my_point.h"

struct board_map {
    char** data;    //2D array of chars representing the map
    size_t size;    //the size of the map 

    //pointers to functions
    void (* print)(struct board_map* map);
    void (* delete)(struct board_map* map);
    void (* set_bsq)(struct board_map* map);
};

//additional class for implementing constructor for board_map
struct board_map_class {
    struct board_map* (*new)(char* file_name);
};

/*
The EXTERN keyword extends the visibility of the C variables and C functions.
Used when a particular files need to access a variable from another file.
Creating a constant board_map_class variable Map.
*/
extern const struct board_map_class Map;


#endif