#include "my_bsq.h"

Bsq* create_bsq(char* file_name) {
    char    *str = NULL;
    int     fd = open(file_name, O_RDONLY); // TODO not opened
    
    //allocate memory for string data
    Bsq* res = (Bsq*) malloc(sizeof(Bsq)); // TODO not malloc
    str = my_readline(fd); //get the number of rows
    res->size = strtoi(str); //TODO check if the file is incorrect
    if (str != NULL) {
        free(str);
    }
    //allocate memory for data of pointers
    res->data = (char**)malloc(res->size * sizeof(char *)); //TODO not malloc
    int i = 0;
    while ((str = my_readline(fd)) != NULL)
    {
        res->data[i] = (char*) malloc((my_strlen(str) + 1) * sizeof(char));
        my_strcpy(res->data[i], str);
        i++;
        free(str);
    }

    //assign pointer to a function
    res->print = (void*) &print_bsq;
    res->delete = (void*) &delete_bsq;
    res->set_bsq = (void*) &set_bsq;
    
    close(fd);
    return res;
}

static void print_bsq(Bsq* arr) {
    if(arr->size == 0) {
        return;
    }

    for (size_t i = 0; i < arr->size; i++) {
        printf("%s\n", arr->data[i]);
    }
    printf("%c", '\n');
}

static void set_ones (Bsq* tbl) {
    for(int i = 0; i < tbl->size; i++) {
        int j = 0;
        while(tbl->data[i][j] != '\0') {
            if (tbl->data[i][j] == '.') {
                tbl->data[i][j] = '1';
            }
            else if (tbl->data[i][j] == 'o') {
                tbl->data[i][j] = '0';
            }
            j++;
        }
    }
}

static void set_dots(Bsq* tbl) {
    for(int i = 0; i < tbl->size; i++) {
        int j = 0;
        while(tbl->data[i][j] != '\0') {
            if (tbl->data[i][j] == 'x') {
                j++;
                continue;
            }
            else if (tbl->data[i][j] == '0') {
                tbl->data[i][j] = 'o';
            }
            else {
                tbl->data[i][j] = '.';
            }
            j++;
        }
    }    
}

static Point set_numbers(Bsq* tbl) {
    Point res;
    res.row = 0;
    res.column = 0;
    char max = '0';
    for(int i = 1; i < tbl->size; i++) {
        int j = 1;
        while(tbl->data[i][j] != '\0') {
            if (tbl->data[i][j] == '1') {
                tbl->data[i][j] = (char) min(tbl->data[i - 1][j], tbl->data[i - 1][j - 1], tbl->data[i][j - 1]) + 1;
            }
            if (tbl->data[i][j] > max) {
                max = tbl->data[i][j];
                res.row = i;
                res.column = j;
            }
            j++;
        }
    }

    return res;    
}

static void delete_bsq(Bsq* arr) {
    for(size_t i = 0; i < arr->size; i++) {
        free(arr->data[i]);
    }
    free(arr);
}


static int min(int a, int b, int c) {
    int m = a;
    if (m > b) {
        m = b;
    }
    if (m > c) {
        m = c;
    }

    return m;
}

static void set_bsq(Bsq* tbl) {
    set_ones(tbl);
    Point p = set_numbers(tbl);
    set_x(tbl, p);
    set_dots(tbl);
}

static void set_x(Bsq* tbl, Point p) {
    int size = tbl->data[p.row][p.column] - '0';

    for (int i = p.row; i > p.row - size; i--) {
        for (int j = p.column; j > p.column - size; j--) {
            tbl->data[i][j] = 'x';
        }
    }
}