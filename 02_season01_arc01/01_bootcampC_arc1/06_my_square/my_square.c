#include <stdio.h>
#include <stdlib.h>

void my_square(int row, int column) {
    if (row < 0 || column < 0) {
        return;
    }
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            //corners
            if ((i == 0 && j == 0) || 
                (i == 0 && j == column - 1) ||
                (i == row - 1 && j == 0) || 
                (i == row - 1 && j == column - 1)) {
                    putchar('o');
            }
            //first and last row
            else if (i == 0 || i == row - 1) {
                putchar('-');
            }
            //first and last column
            else if (j == 0 || j == column - 1) {
                putchar('|');
            }
            else {
                putchar(' ');
            }
        }
        putchar('\n');
    }
}

int main(int ac, char** av) {
    if (ac == 3) {
        my_square(atoi(av[1]), atoi(av[2]));
    }
}