#include <stdio.h> //printf
#include <fcntl.h> //open
#include <unistd.h> //read
#include <stdlib.h> //malloc, atoi
#include <stdbool.h>
#include <string.h>
#include "my_string.h"


//******FUNCTION PROTOTYPES******//
char* my_readline(int fd);
char* malloc_double_memory(char* str);
void init_my_readline();