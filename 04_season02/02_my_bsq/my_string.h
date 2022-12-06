#include <stdbool.h>
#include <stdlib.h> 
#include <stdio.h>
#include <unistd.h>

/****************PROTOTYPES****************/
/**
 *  @brief      Should consist of lower case characters, digits, - and * separated
 *              with one space.
 *  @returns    True is the given string is valid
 **/
bool is_valid_str(const char* str);
bool my_is_lower(char ch);
bool my_is_digit(char ch);
bool is_dash(char ch);
bool is_space(char ch);
bool is_star(char ch);
/**
 * @brief       Checks is the given character a valid character
 *              (lowercase letter, digit, dash, star) 
 */
bool is_valid_char(const char ch);
/**
 * @brief       Returns true is the given string has any character other
 *              than (lowercase letter, digit, dash, star or space)
 */
bool has_invalid_chars(const char* s);

int     my_strlen(const char* s);
int     my_strcmp(const char* s1, const char* s2);
char*   my_strcpy(char* s1, char* s2);
/**
 * @brief       Counts the number of words in the given string.
 */
int count_n_words(const char* s); 
/**
 * @brief       Counts the number of spaces in the given string.
 */
int count_spaces(const char* s);

/**
 * @brief       Adds the given character at the end of the given string.
 * @return      char* an updated string 
 */
char* add_char_to_str(char* s1, char c);
/**
 * @brief       Converts the given int to a string.
 * @return      char* an updated string 
 */
char* itostr(int n, char* str);


bool consist_of_digits(const char* s);
/**
 * @brief       Converts the given string to an int.
 * @return      the number or 0 if the string is not a number 
 */
int strtoi(char* str);
int get_nid(char* str);



