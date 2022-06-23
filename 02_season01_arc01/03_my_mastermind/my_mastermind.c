#include "my_mastermind.h"

int main(int ac, char **av) {
    char code[5];
    int nRounds = 10;
    check_arguments(ac, av, code, &nRounds);
    play_mastermind(code, nRounds);

    return 0;
}