#ifndef BSQ_H
#define BSQ_H

#include <stddef.h>
#include "my_readline.h"
#include "my_point.h"

typedef struct Bsq {
    char** data;
    size_t size;

    void (* print)(struct Bsq* bsq);
    void (* delete)(struct Bsq* bsq);
    void (* set_bsq)(struct Bsq* bsq);
} Bsq;


Bsq* create_bsq(char* file_name);
static void print_bsq(Bsq* arr); 
static void set_bsq(Bsq* arr); 
static void delete_bsq(Bsq* arr);
static void set_ones (Bsq* const tbl);
static Point set_numbers(Bsq* tbl);
static void set_dots(Bsq* tbl);
static int min(int, int, int);
static void set_x(Bsq* tbl, Point p);

#endif