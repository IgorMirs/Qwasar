#include <stdio.h>

int main(int ac, char **av) {
    char letters[128] = {0};
    int i = 1;
    while (i < ac) {
        for(int j = 0; av[i][j] != 0; j++) {
            if (av[i][j] != 34) {
                letters[(int)av[i][j]]++;
            }
        }
        i++;
    }
    
    for (int i = 0; i < 128; i++) {
        if (letters[i] != 0) {
            printf("%c:%d\n", i, letters[i]);
        }
    }
    
    return 0;
}