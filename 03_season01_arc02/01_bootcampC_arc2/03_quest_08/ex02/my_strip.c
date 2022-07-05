#include <stdlib.h>
#include <stdio.h>

int my_isspace(char c) {
    return (c == ' ' || c == '\t') ? 1 : 0;
}

int my_strlen(char* s) {
    int res = 0;
    while (*s != 0) {
        res++;
        s++;
    }

    return res;
}

char* my_strip(char* s) {
    char *res = (char*) malloc(my_strlen(s) + 1); 

    //remove spaces in the begining
    while(my_isspace(*s)) {
        s++;
    }
    int i = 0, j = 0;
    while(s[i] != 0) {
        if (!my_isspace(s[i])) {
            res[j++] = s[i];
            i++;
            continue;
        }
        if (s[i] == '\t') {
            s[i] = ' ';
        }
        res[j++] = s[i];
        do {
            i++;
        } while (my_isspace(s[i]) && s[i] != 0);
    }
    //remove trailing spaces
    while(my_isspace(res[j - 1])) {
        j--;
    }
    res[j] = '\0';

    return res;
}
