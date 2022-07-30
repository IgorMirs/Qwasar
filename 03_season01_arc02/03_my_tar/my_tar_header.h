#ifndef MY_TAR_HEADER_H
#include "my_tar_params.h"

#define MY_TAR_HEADER_H
typedef struct {
    char name[100];
    char mode[8];
} my_tar_header;

#endif

void init_my_tar_header(my_tar_header* tar_head_ptr, my_tar_params* tar_param_ptr); //add my_tar_flag here

/**
 * @brief   Initialize a string with the a mode of a file
 * 
 * @param   n number representing the file mode in octal format
 * @param   k how many digits to consider 
 */
void set_mode(my_tar_header* tar_head_ptr, unsigned n, int k);

void set_name(my_tar_header* tar_head_ptr, char* name);

void print_tar_header(my_tar_header* tar_head_ptr);