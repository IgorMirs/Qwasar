#include "my_string.h"

/****************IMPLEMENTATIONS****************/
bool is_valid_str(const char* str) {
    if (str == NULL             || 
        my_strlen(str) == 0     || 
        !my_is_lower(str[0])    ||
        has_invalid_chars(str)  ||
        count_n_words(str) - count_spaces(str) != 1) 
    {
        return false;
    }

    return true;
}

bool my_is_lower(char ch) {
    return (ch >= 'a' && ch <= 'z');
}

int my_strlen(const char* s) {
    int size = 0;
    while (*s != 0) {
        size++;
        s++;
    }
    return size;
}

int my_strcmp(const char* s1, const char* s2) {
    int i = 0;
    while(s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] > s2[i]) {
            return 1;
        }
        else if (s1[i] < s2[i]) {
            return -1;
        }
        i++;
    }
    //strings are equal
    if (s1[i] == '\0' && s2[i] == '\0') {
        return 0; 
    }
    //s1 is longer than s2
    else if (s1[i] != '\0') {
        return 1;
    }
    //s2 is longer than s1
    else {
        return -1;
    }
}

char* my_strcpy(char* s1, char* s2) {
    if (s1 == NULL) {
        return NULL;
    }
    int i = 0, j = 0;
    while(s2[j] != 0) {
        s1[i] = s2[j++];
        i++;
    }
    s1[i] = '\0';
    return s1;
}

int count_n_words(const char* s) {
    int n_words = 0;
    bool has_words = false;
    for(int i = 0; i < my_strlen(s); ) {
        while (!is_valid_char(s[i]) && i < my_strlen(s)) {
            has_words = false;
            i++;
        }
        while (is_valid_char(s[i]) && i < my_strlen(s)) {
            has_words = true;
            i++;
        }
        n_words += (has_words) ? 1 : 0;
    }
    return n_words;
}

bool my_is_digit(char ch) {
    return (ch >= '0' && ch <= '9');
}

bool is_dash(char ch) {
    return (ch == '-');
}

bool is_star(char ch) {
    return (ch == '*');
}

bool is_valid_char(const char ch) {
    return (my_is_lower(ch) || my_is_digit(ch) || is_dash(ch) || is_star(ch));
}

bool is_space(char ch) {
    return (ch == ' ');
}

bool has_invalid_chars(const char* s) {
    for(int i = 0; i < my_strlen(s); i++) {
        if (!is_valid_char(s[i]) && !is_space(s[i])) {
            return true;
        }
    }

    return false;
}

int count_spaces(const char* s) {
    int n_spaces = 0;
    for(int i = 0; i < my_strlen(s); i++) {
        if(is_space(s[i])) {
            n_spaces++;
        }
    }

    return n_spaces;
}

bool consist_of_digits(const char* s) {
    int i = 0;
    while (s[i] != '\0') {
        if (!my_is_digit(s[i])) {
            return false;
        }
        i++;
    }

    return true;
}

int strtoi(char* str) {
    int res = 0;
    bool lead_zero = true;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '0' && lead_zero) {
            continue;
        }
        else if (str[i] != '0' && lead_zero) {
            lead_zero = false;
        }
        
        if (!lead_zero) {
            res *= 10;
            res += str[i] - '0';
            lead_zero = false;
        }
    }

    return res;
}

int get_nid(char* str) {
    return strtoi(str);
}

char* add_char_to_str(char* s1, char c) {
    int i = 0;
    while(s1[i] != 0) {
        i++;
    }
    s1[i++] = c;
    s1[i] = '\0';

    return s1;
}

char* itostr(int n, char* str) {
    char digit = n % 10 + '0';
    if (n / 10 == 0) {
        return add_char_to_str(str, digit);
    }
    else {
        str = itostr(n / 10, str);
        return add_char_to_str(str, digit);
    }
}