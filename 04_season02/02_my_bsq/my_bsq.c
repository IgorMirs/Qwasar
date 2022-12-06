#include "my_bsq.h"
/**
 * @brief   Create a map object in the heap. 
 *          To restrict access to functions, we make them static.
 * 
 * @param   file_name - text file with a map
 * @return  struct board_map* - the pointer to the object in the heap.
 */
static struct board_map* create_map(char* file_name);

static void print_bsq(struct board_map* map); 

/**
 * @brief   Find and mark the biggest square on the board
 */
static void set_bsq(struct board_map* map); 

/**
 * @brief   Free allocated memory for the map
 */
static void delete_bsq(struct board_map* map);

/**
 * @brief   Replace all '.' with '1' on the board.
 */
static void set_ones (struct board_map* const map);

/**
 * @brief   Look at each point on the map, 
 *          and fill it with the minimum value around plus one.
 * 
 * @return  Point - the coordinates of the biggest number on the board 
 */
static Point set_numbers(struct board_map* map);

/**
 * @brief   Replace all numbers to '.'
 */ 
static void set_dots(struct board_map* map);

/**
 * @brief   Find the minimum of three ints
 */
static int min(int, int, int);

/**
 * @brief   Mark the biggest square on the map with 'x'
 * 
 * @param   p - coordinates of the point with the biggest number on the map.
 */
static void set_x(struct board_map* map, Point p);


//initialize Map variable
const struct board_map_class Map = {
            .new = &create_map
};

static struct board_map* create_map(char* file_name) {
    char    *str = NULL;
    int     fd = open(file_name, O_RDONLY);
    if (fd == -1) { //open error
        return NULL;
    }
    //allocate memory for string data
    struct board_map* res = (struct board_map*) malloc(sizeof(struct board_map));
    if (res == NULL) { //malloc error
        return NULL;
    }
    str = my_readline(fd); //get the number of rows
    res->size = strtoi(str);
    if (str != NULL) {
        free(str);
    }
    //allocate memory for data of pointers
    res->data = (char**)malloc(res->size * sizeof(char *)); //TODO not malloc
    if (res->data == NULL) { //malloc error
        free(res);
        return NULL;
    }
    int i = 0;
    while ((str = my_readline(fd)) != NULL)
    {
        res->data[i] = (char*) malloc((my_strlen(str) + 1) * sizeof(char));
        if (res->data[i] == NULL) { //malloc error
            i--;
            while (i >= 0) {
                free(res->data[i]);
                i--;
            }
            free(res->data);
            free(res);
            return NULL;
        }
        my_strcpy(res->data[i], str);
        i++;
        if (str != NULL) {
            free(str);
        }
    }

    //assign pointer to a function
    res->print = (void*) &print_bsq;
    res->delete = (void*) &delete_bsq;
    res->set_bsq = (void*) &set_bsq;
    
    close(fd);
    return res;
}

static void print_bsq(struct board_map* map) {
    if(map->size == 0) {
        return;
    }

    for (size_t i = 0; i < map->size; i++) {
        printf("%s\n", map->data[i]);
    }
    printf("%c", '\n');
}

static void set_ones (struct board_map* map) {
    for(int i = 0; i < map->size; i++) {
        int j = 0;
        while(map->data[i][j] != '\0') {
            if (map->data[i][j] == '.') {
                map->data[i][j] = '1';
            }
            else if (map->data[i][j] == 'o') {
                map->data[i][j] = '0';
            }
            j++;
        }
    }
}

static void set_dots(struct board_map* map) {
    for(int i = 0; i < map->size; i++) {
        int j = 0;
        while(map->data[i][j] != '\0') {
            if (map->data[i][j] == 'x') {
                j++;
                continue;
            }
            else if (map->data[i][j] == '0') {
                map->data[i][j] = 'o';
            }
            else {
                map->data[i][j] = '.';
            }
            j++;
        }
    }    
}

static Point set_numbers(struct board_map* map) {
    Point res;
    res.row = 0;
    res.column = 0;
    char max = '0';
    for(int i = 1; i < map->size; i++) {
        int j = 1;
        while(map->data[i][j] != '\0') {
            if (map->data[i][j] == '1') {
                map->data[i][j] = (char) min(map->data[i - 1][j], map->data[i - 1][j - 1], map->data[i][j - 1]) + 1;
            }
            if (map->data[i][j] > max) {
                max = map->data[i][j];
                res.row = i;
                res.column = j;
            }
            j++;
        }
    }

    return res;    
}

static void delete_bsq(struct board_map* map) {
    for(size_t i = 0; i < map->size; i++) {
        free(map->data[i]);
    }
    free(map->data);
    free(map);
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

static void set_bsq(struct board_map* map) {
    set_ones(map);
    Point p = set_numbers(map);
    set_x(map, p);
    set_dots(map);
}

static void set_x(struct board_map* map, Point p) {
    int size = map->data[p.row][p.column] - '0';

    for (int i = p.row; i > p.row - size; i--) {
        for (int j = p.column; j > p.column - size; j--) {
            map->data[i][j] = 'x';
        }
    }
}