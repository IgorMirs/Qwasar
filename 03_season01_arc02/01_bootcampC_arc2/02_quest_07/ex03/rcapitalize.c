#include <stdio.h>

int my_isdigit(char c) {
    return (c >= '0' && c <= '9') ? 1 : 0;
}

int my_islower(char c) {
    return (c >= 'a' && c <= 'z') ? 1 : 0;
}

int my_isupper(char c) {
    return (c >= 'A' && c <= 'Z') ? 1 : 0;
}

int my_isalpha(char c) {
    return (my_isdigit(c) || my_islower(c) || my_isupper(c)) ? 1 : 0;
}

char my_toupper(char c) {
    return (c >= 'a' && c <= 'z') ? c - 32 : c;
}

char my_tolower(char c) {
    return (c >= 'A' && c <= 'Z') ? c + 32 : c;
}

char* rcapitalize(char* s) {
    for(int i = 0; s[i] != '\0'; i++) {
        if (my_isalpha(s[i]) && (s[i + 1] == ' ' || s[i + 1] == '\t' || s[i + 1] == '\0')) {
            s[i] = my_toupper(s[i]);
        }
        else {
            s[i] = my_tolower(s[i]);
        }
    }

    return s;
}
