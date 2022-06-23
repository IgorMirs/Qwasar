#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

/**
 * @brief   Checks the validity to the given code.
 *          Code should contain of only 4 digits from 0 to 7, 
 *          have no duplicates.          
 * @return  1 if the code is valid and 0 otherwise
 */
int check_code(const char* s);

/**
 * @brief   Compares two given strings.
 * @return  1 if strings are equal and 0 otherwise
 */
int my_strcmp(const char* s1, const char* s2);

/**
 * @brief   Checks is the given character in the range [0; 7].          
 * @return  1 if the code is valid and 0 otherwise
 */
int my_isdigit(char c);

/**
 * @brief   Copies the content of the second string to the first string.
 * @param   s1 first string.
 * @param   s2 second string.
 * @return  void
 */
void my_strcpy(char* s1, const char* s2);

/**
 * @brief   Checks if the given input equals to the code.
 *          Prints the number of misplaced and well placed
 *          pieces. 
 * @param   input user's input
 * @param   code code to guess
 * @return  1 if all the pieces well places and 0 otherwise
 */
int check_end_game(const char* input, const char* code);

/**
 * @brief   Search for the flags (-c and -t) in the given arguments.
 *          If the given code is correct sets the code or sets 
 *          the random code. -t sets the number of rounds. 
 *          10 rounds by default.
 *          Prints which code was set and the number of rounds.
 * @param   ac number of program arguments
 * @param   av array of arguments
 * @param   code stores the generated code (given or random)
 * @param   nRounds stores number of rounds (10 by default)
 * @return  void
 */
void check_arguments(int ac, char **av, char* code, int* nRounds);

/**
 * @brief   Generates a 4 digit random code with no duplicates
 * @param   code stores the code
 * @return  void
 */
void set_random_code(char* code);

/**
 * @brief   Checks if the given code has duplicates
 * @return  1 if there are duplicates and 0 otherwise
 */
int contains_duplicates(const char* code);

/**
 * @brief   Runs nRounds of game, reads the input from the user,
 *          calls the appropriate functions to check the validity of
 *          the users input, display the number of well placed and misplaced
 *          digits, check the end of game.
 * @param   code The code of the current game
 * @param   nRounds number of rounds in this game
 * @return  void 
 */
void play_mastermind(char * code, int nRounds);



int my_strcmp(const char* s1, const char* s2) {
    int i = 0;
    while(s1[i] != 0 && s2[i] != 0) {
        if (s1[i] != s2[i]) {
            return 0;
        }
        i++;
    }
    return (s1[i] == 0 && s2[i] == 0) ? 1 : 0;
}

int my_isdigit(char c) {
    return (c <= '7' && c >= '0') ? 1 : 0;
}

int check_code(const char* s) {
    int i;
    for(i = 0; s[i] != 0; i++) {
        if (!my_isdigit(s[i])) {
            return 0;
        }
    }
    return (i == 4 && !contains_duplicates(s)) ? 1 : 0;
}

void my_strcpy(char* s1, const char* s2) {
    int i;
    for(i = 0; s2[i] != 0; i++) {
        s1[i] = s2[i];
    }
    s1[i] = '\0';
}

int check_end_game(const char* input, const char* code) {
    //count well placed
    int i = 0;
    int wellPlaced = 0, misplaced = 0;
    int occupiedDigits[4] = {0};
    while (code[i] != 0) {
        if(code[i] == input[i]) {
            wellPlaced++;
            occupiedDigits[i]++;
        }
        i++;
    }
    if (wellPlaced == 4) {
        printf("%s", "Gongratz! You did it!\n");
        return 1;
    }
    else {
        printf("Well placed pieces: %d\n", wellPlaced);
    }

    //count misplaced pieces
    for(int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (occupiedDigits[j] == 1) {
                continue;
            }
            else if (input[i] == code[j]) {
                misplaced++;
                occupiedDigits[j]++;
                break;
            }
        }
    }
    printf("Misplaced pieces: %d\n", misplaced);

    return 0;
}

void check_arguments(int ac, char **av, char* code, int* nRounds) {
    int nCFlags = 0; //number of -c flags in the arguments
    int nTFlags = 0; //number of -t flags in the arguments
    int codeIsCorrect = 0;
    int i = 1;
    //iterate through the program arguments
    while(i < ac) {
        //if find -c flag
        if (my_strcmp(av[i], "-c")) {
            //increment the number of -c flags
            nCFlags++;
            //if more than one -c flag
            if (nCFlags > 1) {
                codeIsCorrect = 0;
            }
            //if it is the first -c flag -> check the code
            else if (check_code(av[i + 1]) && (i != ac - 1)) {
                my_strcpy(code, av[i + 1]);
                codeIsCorrect = 1;
            }
        }
        //if find -t flag
        else if (my_strcmp(av[i], "-t")) {
            nTFlags++;
            if (nTFlags > 1) {
                *nRounds = 10; 
            }
            else if (i != ac - 1) {
                *nRounds = atoi(av[i + 1]);
            }
        }
        i++;
    }

    if (codeIsCorrect) {
        printf("%s", "You successfully set the code\n");
    }
    else {
        printf("%s", "You DID NOT set the code or the given code is incorrect "
                "A random 4 digits code was generated\n");
        set_random_code(code);
    }
    //printf("The code is %s\n", code);
    printf("The number of rounds is %d\n\n", *nRounds);
}

void set_random_code(char* code) {
    srand(time(0));
    int pieces[8] = {0};
    int i = 0;
    while (i < 4) {
        int rNum;
        while (pieces[rNum = rand() % 8] != 0) {
        
        }
        pieces[rNum]++; 
        code[i] = rNum + '0';
        i++;
    }
    code[i] = '\0';
}

int contains_duplicates(const char* code) {
    //empty string
    if (code[0] == 0) {
        return 0;
    }
    for (int i = 0; code[i + 1] != 0; i++) {
        for (int j = i + 1; code[j] != 0; j++) {
            if (code[i] == code[j]) {
                return 1;
            }
        }
    }
    return 0;
}

void play_mastermind(char * code, int nRounds) {
    printf("%s", "Will you find the secret code?\n");
    int round = 0;
    char input[100];
    while (round < nRounds) {
        printf("---\nRound %d\n", round++);
        while (1 == 1) {
            int nread = read(STDIN_FILENO, input, 99);
            //printf("Bytes read %d\n", nread);
            input[nread - 1] = '\0';
            //printf("The input is \"%s\"\n", input);

            if(check_code(input)) {
                int end = check_end_game(input, code);
                if (end) {
                    return;
                }
                else {
                    break;
                }
            }
            else {
                printf("%s", "Wrong input!\n");
            }
        } 
    }

    printf("%s", "GAME OVER\n");
}