#include <stdio.h>
#include <stdlib.h>

int my_strlen(char* s) {
    int res = 0;
    while (*s != 0) {
        res++;
        s++;
    }

    return res;
}

char* my_union(char* s1, char* s2) {
    int alph[128] = {0};
    char* res = (char*) malloc(my_strlen(s1) + my_strlen(s2) + 1);
    int j = 0;
    for(int i = 0; s1[i] != 0; i++) {
        if (alph[(int)s1[i]] == 0) {
            alph[(int)s1[i]]++;
            res[j++] = s1[i];
        }
    } 
    for(int i = 0; s2[i] != 0; i++) {
        if (alph[(int)s2[i]] == 0) {
            alph[(int)s2[i]]++;
            res[j++] = s2[i];
        }
    }
    res[j] = '\0';

    return res;   
}
