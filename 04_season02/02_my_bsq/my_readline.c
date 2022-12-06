#include "my_readline.h"

//******FUNCTION IMPLEMENTATIONS******//

    char* my_readline(int fd) {
    char* str = (char*) malloc((512 + 1) * sizeof(char));
    char temp[2];
    int sz = 0;
    int index = 0;
    bool exit = true;
    while((sz = read(fd, temp, 1)) == 1) {
        exit = false;
        if (*temp == '\n') {
            break;
        }
        str[index++] = *temp;
        if (index >= 512 - 1) {
            str = malloc_double_memory(str); 
        }
    }
    
    //error
    if (sz <= 0 && exit) {
        free(str);
        return NULL;
    }

    str[index] = '\0';
    return str;
}

char* malloc_double_memory(char* str) {
    char* new_str = (char*) malloc(1024);
    for(int i = 0; i < 512; i++) {
        new_str[i] = str[i];
    }

    free(str);
    return new_str;
}
