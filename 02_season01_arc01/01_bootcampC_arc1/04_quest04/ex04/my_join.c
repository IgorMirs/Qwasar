
#ifndef STRUCT_STRING_ARRAY
#define STRUCT_STRING_ARRAY
typedef struct s_string_array
{
    int size;
    char** array;
} string_array;
#endif

int count_total_chars(string_array* sa) {
    int total = 0;
    for(int i = 0; i < sa->size; i++) {
        for(int j = 0; sa->array[i][j] != 0; j++) {
            total++;
        }
    }

    return total;
}


char* my_join(string_array* param_1, char* param_2) {
    if (param_1->size == 0) {
        return 0;
    }
    char* res = (char*) malloc(count_total_chars(param_1) + 1);
    int k = 0;
    for(int i = 0; i < param_1->size; i++) {
        for(int j = 0; param_1->array[i][j] != 0; j++) {
            res[k++] = param_1->array[i][j];
        }
        if (i != param_1->size - 1) {
            int z = 0;
            while(param_2[z] != 0) {
                res[k++] = param_2[z];
                z++;
            }
        }
    }
    res[k] = '\0';
    
    return res;
}