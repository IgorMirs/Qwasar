#include <stdio.h>
#include <stdlib.h>

#define RED     "\x1b[31m"
#define WHITE   "\x1b[37m"
#define GREEN   "\x1b[32m"
#define BLACK   "\x1b[30m"

void my_christmas_tree(int size);
int n_rows(int size);
int print_crown(int size);
int count_left_shift(int size);
void print_trunk(int size, int n_stars_last_row);


////****FUNCTION IMPLEMENTATION****////

int count_left_shift(int size) {
    int left_shift = 0;
    int shift = 1;
    for (int i = 1; i <= size; i++) {
        if (i % 2 == 0) {
            shift += 1;
        }
        left_shift += shift;
    }

    return left_shift;
}

int print_crown(int size) {
    int num_rows = n_rows(size);
    int level_border = 5;
    int next_level = 5;
    int new_level = 0;
    int n_spaces = 0, n_stars = 0;
    int shift = 2;
    int n_stars_last_row = 0;

    for(int i = 1; i <= num_rows; i++) {
        if (i == level_border) {
            n_spaces += shift;
            n_stars += shift;
            level_border += next_level;
            next_level++;
            if (new_level != 0 && new_level % 2 == 0) {
                n_spaces++;
                n_stars++;
                shift += 1;
            }
            new_level++;
        }
        int left_shift = count_left_shift(size);
        //printing spaces
        for(int j = left_shift - 1; j < num_rows - i + n_spaces; j++) {
            putchar(' ');
        }
        for(int k = 0; k < (i - n_stars) * 2 - 1; k++) {
            if (k % 2) {
                printf(RED "*");
            }
            else {
                printf(GREEN "*");
            }
            n_stars_last_row = k;
        }
        //printf("%d", n_stars_last_row + 1);
        putchar('\n');
    }

    return n_stars_last_row + 1;
}

void print_trunk(int size, int n_stars_last_row) {
    for(int i = 0; i < size; i++) {
        for(int j = 0; j <= n_stars_last_row / 2 + size / 2; j++) {
            if (j < n_stars_last_row / 2 - size / 2) {
                printf( " ");
            }
            else {
                printf(BLACK "|");
            }
        }
        putchar('\n');
    }

}

void my_christmas_tree(int size) {
    int n_stars_last_row = print_crown(size);
    print_trunk(size, n_stars_last_row);
} 

int n_rows(int size) {
    if (size < 1) {
        return 0;
    }
    int res = 0;
    int level_rows = 4;
    for(int i = 1; i <= size; i++) {
        res += level_rows;
        level_rows++;
    }

    return res;
}


int main(int ac, char** av) {
    if (ac != 2) {
        return -1;
    }
    my_christmas_tree(atoi(av[1]));

    //printf("%d\n", n_rows(atoi(av[1])));
    return 0;
}

