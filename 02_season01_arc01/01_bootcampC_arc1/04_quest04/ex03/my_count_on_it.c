#ifndef STRUCT_STRING_ARRAY
#define STRUCT_STRING_ARRAY
typedef struct s_string_array
{
    int size;
    char** array;
} string_array;
#endif

#ifndef STRUCT_INTEGER_ARRAY
#define STRUCT_INTEGER_ARRAY
typedef struct s_integer_array
{
    int size;
    int* array;
} integer_array;
#endif

int count_length(char* str) {
    int i = 0;
    while(str[i] != 0) {
        i++;
    }
    return i;
}

integer_array* my_count_on_it(string_array* param_1) {
    integer_array* res = (integer_array*) malloc(sizeof(integer_array));
    res->size = param_1->size;
    res->array = (int*) malloc(param_1->size * sizeof(int));
    for(int i = 0; i < param_1->size; i++) {
        for(int j = 0; param_1->array[j] != 0; j++) {
            res->array[j] = count_length(param_1->array[j]);           
        }
    }
    
    return res;
}