#include <stdbool.h>
#ifndef STRUCT_INTEGER_ARRAY
#define STRUCT_INTEGER_ARRAY
typedef struct s_integer_array
{
    int size;
    int* array;
} integer_array;
#endif

bool my_is_sort(integer_array* param_1) {
    //not set - 0; asc - 1; desc - 2;
    int order = 0;
    for (int i = 0; i < param_1->size - 1; i++) {
        if (order == 0) {
            if (param_1->array[i] > param_1->array[i + 1]) {
                order = 2;
            }
            else if (param_1->array[i] < param_1->array[i + 1]) {
                order = 1;
            }
        }
        else if (order == 1) {
            if (param_1->array[i] > param_1->array[i + 1]) {
                return false;
            }
        }
        else {
            if (param_1->array[i] < param_1->array[i + 1]) {
                return false;
            }
        }
    }
    return true;
}