#include <stdio.h>
#include <stdarg.h>
#include <stdbool.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

///***************FUNCTIONS PROTOTYPES***********////

/**
 * @brief   Implementation of a printf function which formats 
 *          and prints its arguments, after the first, 
 *          under control of the format.
 *          Handling of 'douxcsp' conversion specifiers was implemented
 *          Field width was implemented as well. 
 * @param   format a character string which specifies the output format         
 * @return  total number of characters printed, -1 in case of incorrect format control string
 */
int my_printf(char* format, ...);

/**
 * @brief   Check is the given character a % sign or not         
 * @return  true if the character is % and false otherwise
 */
bool is_percent_char(char c);

/**
 * @brief   Check is the given character a \ sign or not         
 * @return  true if the character is \ and false otherwise
 */
bool is_backslash_char(char c);

/**
 * @brief   Check is the given character a digit or not         
 * @return  true if the character is a digit and false otherwise
 */
bool is_digit(char c);

/**
 * @brief   Prints positive and negative integers
 * @param   num an integer number to print
 * @param   fieldWidth the width of the output field
 * @param   nIter number of iteration to track the first call of a recursion
 * @param   nPrintedChars total number of characters printed by my_printf function.
 *          Passed as a pointer to update the previous value.
 * 
 * @return  void
 */
void print_decimal(int num, int fieldWidth, int nIter, int* nPrintedChars);

/**
 * @brief   Converts the given unsigned int to octal and prints it.
 * @param   num an integer number to print
 * @param   fieldWidth the width of the output field
 * @param   nIter number of iteration to track the first call of a recursion
 * @param   nPrintedChars total number of characters printed by my_printf function.
 *          Passed as a pointer to update the previous value.
 * 
 * @return  void
 */
void print_octal(unsigned num, int fieldWidth, int nIter, int* nPrintedChars);

/**
 * @brief   Converts the given unsigned int to hex and prints it.
 * @param   num an integer number to print
 * @param   fieldWidth the width of the output field
 * @param   nIter number of iteration to track the first call of a recursion
 * @param   nPrintedChars total number of characters printed by my_printf function.
 *          Passed as a pointer to update the previous value.
 * 
 * @return  void
 */
void print_hex(unsigned num, int fieldWidth, int nIter, int* nPrintedChars);

/**
 * @brief   Prints the given unsigned integer number.
 * @param   num an integer number to print
 * @param   fieldWidth the width of the output field
 * @param   nIter number of iteration to track the first call of a recursion
 * @param   nPrintedChars total number of characters printed by my_printf function.
 *          Passed as a pointer to update the previous value.
 * 
 * @return  void
 */
void print_unsigned(unsigned num, int fieldWidth, int nIter, int* nPrintedChars);

/**
 * @brief   Prints the given address in hexadecimal format.
 * @param   num an integer number to print
 * @param   fieldWidth the width of the output field
 * @param   nIter number of iteration to track the first call of a recursion
 * @param   nPrintedChars total number of characters printed by my_printf function.
 *          Passed as a pointer to update the previous value.
 * 
 * @return  void
 */
void print_pointer(unsigned num, int fieldWidth, int nIter, int* nPrintedChars);

/**
 * @brief   Prints the given character.
 * @return  void
 */
int my_putchar(char c, int* nPrintedChars);

/**
 * @brief   Prints the given string.
 * @return  void
 */
void print_string(char* str, int fieldWidth, int* nPrintedChars);

/**
 * @brief   Counts the number of digits in the given integer number.
 * @return  number of digits in the given number
 */
int count_digits(int num);

/**
 * @brief   Counts the number of digits in the given unsigned integer number.
 * @return  number of digits in the given number
 */
int count_digits_unsigned(unsigned num);

/**
 * @brief   Converts the given unsigned number to octal and
 *          counts the number of digits in the converted number.
 * @return  number of digits
 */
int count_digits_octal(unsigned num);

/**
 * @brief   Converts the given unsigned number to hex and
 *          counts the number of digits in the converted number.
 * @return  number of digits
 */
int count_digits_hex(unsigned num);

/**
 * @brief   Prints the leading spaces to match the required fieldWidth. Updates
 *          the total number of printed characters. If number of digits < width,
 *          print the diffirence in ' '.
 * @return  void
 */
void print_spaces(int nDigits, int width, int* nPrintedChars);

/**
 * @brief   Counts the length of the given string excluding the termination null character.
 *
 * @return  number of characters in the given string
 */
int my_strlen(char* str);


///***************FUNCTIONS IMPLEMENTATION***********////

int my_printf(char* format, ...) {
    // va_list is a type to hold information about
    // variable arguments
    va_list valist;

    // va_start must be called before accessing
    // variable argument list
    va_start(valist, format);

    //iterate through the format string
    int i = 0;
    int nSpaces = 0;   //field width size
    int nPrintedChars = 0; //total number of printed characters
    while(format[i] != 0) {
        //if the charactes is a conversion specifier
        if (is_percent_char(format[i])){
            //increment the index and test the next character
            i++;

            //if it's a digit - get the field width and store is in nSpaces
            if (is_digit(format[i])) {
                char width[9];
                int j = 0;
                while (is_digit(format[i])) {
                    width[j++] = format[i];
                    i++;
                }
                nSpaces = atoi(width);
            }

            //check the conversion specifier
            switch (format[i]) {
            // Now arguments can be accessed one by one
            // using va_arg macro. 
            case 'd':
                print_decimal(va_arg(valist, int), nSpaces, 0, &nPrintedChars);
                break;
            case 'o':
                print_octal(va_arg(valist, int), nSpaces, 0, &nPrintedChars);
                break;
            case 'x':
                print_hex(va_arg(valist, int), nSpaces, 0, &nPrintedChars);
                break;
            case 'u':
                print_unsigned(va_arg(valist, int), nSpaces, 0, &nPrintedChars);
                break;
            case 'c':
                print_spaces(1, nSpaces, &nPrintedChars);
                my_putchar(va_arg(valist, int), &nPrintedChars);
                break;
            case 's':
                print_string(va_arg(valist, char*), nSpaces, &nPrintedChars);
                break;
            case 'p':
                print_pointer(va_arg(valist, int), nSpaces, 0, &nPrintedChars);
                break;
            default:
                //if invalid conversion specifier return -1
                return -1;
            } //end switch
        } //end if (is_percent_char(format[i]))
        //if the character is a backslash
        else if (is_backslash_char(format[i])) {
            my_putchar(92, &nPrintedChars); //print backslash character
        }
        else {
            my_putchar(format[i], &nPrintedChars);
        }
        i++;
    }
    // va_end should be executed before the function
    // returns whenever va_start has been previously
    // used in that function
    va_end(valist);

    return nPrintedChars;
}

int my_putchar(char c, int* nPrintedChars) {
    (*nPrintedChars)++;
    return write(1, &c, 1);
}

void print_string(char* str, int fieldWidth, int* nPrintedChars) {
    print_spaces(my_strlen(str), fieldWidth, nPrintedChars);
    if(str) {
        while (*str != 0) {
            my_putchar(*str, nPrintedChars);
            str++;
        }
    }
    else {
        print_string("(null)", fieldWidth, nPrintedChars);
    }
}

void print_decimal(int num, int fieldWidth, int nIter, int* nPrintedChars) {
    //print leading spaces
    if (!nIter) {
        print_spaces(count_digits(num), fieldWidth, nPrintedChars);
    }
    
    if (num == INT_MIN) {
        char int_min[12] = "-2147483648";
        print_string(int_min, 0, nPrintedChars);
        //increment the total number of printed chars
        *nPrintedChars += 11;
    }
    else if (num < 0) {
        my_putchar('-', nPrintedChars);
        print_decimal(num * -1, fieldWidth, nIter + 1, nPrintedChars);
    }
    else if (num / 10 == 0) {
        my_putchar(num + '0', nPrintedChars);
        return;
    }
    else {
        print_decimal(num / 10, fieldWidth, nIter + 1, nPrintedChars);
        my_putchar(num % 10 + '0', nPrintedChars);
    }
}

bool is_percent_char(char c) {
    return (c == '%') ? true : false;
}

bool is_backslash_char(char c) {
    return (c == 92) ? true : false;
}

bool is_digit(char c) {
    return (c >= '0' && c <= '9') ? true : false;
}

void print_octal(unsigned num, int fieldWidth, int nIter, int* nPrintedChars) {
    //print leading spaces
    if (!nIter) {
        print_spaces(count_digits_octal(num), fieldWidth, nPrintedChars);
    }
    if (num / 8 == 0) {
        my_putchar(num + '0', nPrintedChars);
    }
    else {
        print_octal(num / 8, fieldWidth, nIter + 1, nPrintedChars);
        my_putchar(num % 8 + '0', nPrintedChars);
    }
}

void print_hex(unsigned num, int fieldWidth, int nIter, int* nPrintedChars) {
    //print leading spaces
    if (!nIter) {
        print_spaces(count_digits_hex(num), fieldWidth, nPrintedChars);
    }
    int digit = num % 16;
    char letter;
    switch (digit) {
    case 10:
        letter = 'a';
        break;
    case 11:
        letter = 'b';
        break;
    case 12:
        letter = 'c';
        break;
    case 13:
        letter = 'd';
        break;
    case 14:
        letter = 'e';
        break;
    case 15:
        letter = 'f';
        break;
    default:
        letter = digit + '0';
    }

    if (num / 16 == 0) {
        my_putchar(letter, nPrintedChars);
    }
    else {
        print_hex(num / 16, fieldWidth, nIter + 1, nPrintedChars);
        my_putchar(letter, nPrintedChars);
    }
}

void print_unsigned(unsigned num, int fieldWidth, int nIter, int* nPrintedChars) {
    //print leading spaces
    if (!nIter) {
        print_spaces(count_digits_unsigned(num), fieldWidth, nPrintedChars);
    }
    
    if (num / 10 == 0) {
        my_putchar(num + '0', nPrintedChars);
        return;
    }
    else {
        print_unsigned(num / 10, fieldWidth, nIter + 1, nPrintedChars);
        my_putchar(num % 10 + '0', nPrintedChars);
    }
}

void print_pointer(unsigned num, int fieldWidth, int nIter, int* nPrintedChars) {
    //adjust the field width as we print leading characters for the address
    fieldWidth -= (num) ? 3 : 2;
    
    //print leading spaces
    print_spaces(count_digits_hex(num), fieldWidth, nPrintedChars);
    print_string("0x", 0, nPrintedChars);
    if (num) {
        my_putchar('1', nPrintedChars);
    }
    print_hex(num, fieldWidth, nIter + 1, nPrintedChars);
}

int count_digits(int num) {
    if (num == 0) {
        return 1;
    }
    int nDigits = 0;
    //additional place for - sign
    if (num < 0) {
        nDigits++;
    }
    while(num != 0) {
        nDigits++;
        num /= 10;
    }
    
    return nDigits;
}

int count_digits_unsigned(unsigned num) {
    if (num == 0) {
        return 1;
    }
    int nDigits = 0;
    while(num != 0) {
        nDigits++;
        num /= 10;
    }
    
    return nDigits;
}

int count_digits_octal(unsigned num) {
    if (num / 8 == 0) {
        return 1;
    }
    else {
        return 1 + count_digits_octal(num / 8);
    }
}

int count_digits_hex(unsigned num) {
    if (num / 16 == 0) {
        return 1;
    }
    else {
        return 1 + count_digits_hex(num / 16);
    }
}

void print_spaces(int nDigits, int width, int* nPrintedChars) {
    int nSpaces = width - nDigits;
    while (nSpaces > 0) {
        my_putchar(' ', nPrintedChars);
        nSpaces--;
    }
}

int my_strlen(char* str) {
    if (!str) {
        return 0;
    }
    int i = 0;
    for (; str[i] != 0; i++) {

    }
    return i;
}
