#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#ifndef STRUCT_STRING_ARRAY
#define STRUCT_STRING_ARRAY
typedef struct s_string_array
{
    int size;
    char** array;
} string_array;
#endif

////****FUNCTION PROTOTYPES****////
int my_strlen(char* s);
char* my_strstr(char* param_1, char* param_2);
char* my_strcpy(char* param_1, char* param_2);
string_array* my_split(char* s, char* sprtr);
void my_split_helper(char* s1, char* s2, string_array* arr);
int n_substrings(char* s1, char* s2);
void add_string(string_array* arr, char* s, int* index);
void print_string_array(string_array* arr);

////****FUNCTION IMPLEMENTATION****////
int my_strlen(char* s) {
    int res = 0;
    while (*s != 0) {
        res++;
        s++;
    }

    return res;
}

char* my_strstr(char* param_1, char* param_2) {
    if (*param_2 == 0) {
        return param_1;
    }
    for(int i = 0; param_1[i] != 0; i++) {
        if (param_1[i] == param_2[0]) {
            int j = 1, k = i + 1;
            while (param_2[j] != 0) {
                if (param_2[j] != param_1[k++]) {
                    break;
                }
                j++;
            }
            if (param_2[j] == 0) {
                return (param_1 + i);
            }
        }
    }
    return 0;
}

char* my_strcpy(char* param_1, char* param_2) {
    int i = 0, j = 0;
    while(param_1[i] != 0) {
        i++;
    }
    while(param_2[j] != 0) {
        param_1[i] = param_2[j++];
        i++;
    }
    param_1[i] = '\0';
    return param_1;
}

string_array* my_split(char* s, char* sprtr) {
    //allocate memory for string array
    string_array* res = (string_array*) malloc(sizeof(string_array));
    //count the number of strings after spliting and updating the array size
    res->size = n_substrings(s, sprtr);
    //allocate memory for array of pointers
    res->array = (char**)malloc(res->size * sizeof(char *));
    //split the string and update the array
    my_split_helper(s, sprtr, res);

    return res;
}

void print_string_array(string_array* arr) {
    if(arr->size == 0) {
        return;
    }
    printf("%s", "[ ");
    for (int i = 0; i < arr->size; i++) {
        if (i != arr->size - 1) {
            printf("\"%s\", ", arr->array[i]);
        }
        else {
            printf("\"%s\" ]", arr->array[i]);
        }
    }
}

void add_string(string_array* arr, char* s, int* index) {
    arr->array[*index] = (char*)malloc(my_strlen(s) + 1);
    my_strcpy(arr->array[*index], s);
    (*index)++;
}


int n_substrings(char* s1, char* s2) {
    if ((*s2) == '\0') {
        return 0;
    }
    int n_subs = 0;
    char* iter = s1;
    while (1 == 1) {
        //search for the next separator
        iter = my_strstr(s1, s2);
        //didn't find the separator    
        if (iter == 0) {
            break;
        }
        //if the current character is a separator
        else if (s1 == iter) {
            s1 = iter + my_strlen(s2);
        }
        else {
            n_subs++;
            s1 = iter + my_strlen(s2);
        }

    }
    if (*s1 != 0) {
        n_subs++;
    }

    return n_subs;
}

void my_split_helper(char* s1, char* s2, string_array* arr) {
    if ((*s2) == '\0') {
        return;
    }
    char* iter = s1;
    int index = 0;
    while (1 == 1) {
        //search for the next separator
        iter = my_strstr(s1, s2);
        //didn't find the separator    
        if (iter == 0) {
            break;
        }
        //if the current character is a separator
        else if (s1 == iter) {
            s1 = iter + my_strlen(s2);
        }
        else {
            *iter = '\0';
            add_string(arr, s1, &index);
            s1 = iter + my_strlen(s2);
        }

    }
    if (*s1 != 0) {
        add_string(arr, s1, &index);
    }
}

// int main(int ac, char** av) {
//     if (ac != 3) {
//         return -1;
//     }

    
//     print_string_array(my_split(av[1], av[2]));
    
//     return 0;
// }

