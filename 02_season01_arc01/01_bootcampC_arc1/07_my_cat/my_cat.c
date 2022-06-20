#include <stdio.h>

int main(int ac, char **av) {
    FILE *fPtr = NULL;
    int i = 1;
    while (i < ac) {
        if ((fPtr = fopen(av[i], "r")) == NULL) {
            printf("File %s couldn't be opened\n", av[i]);
        }
        else {
            char c = fgetc(fPtr);
            while(!feof(fPtr)) {
                printf("%c", c);
                c = fgetc(fPtr);
            }
            fclose(fPtr);
        }
        i++;
    }
    
    return 0;
}