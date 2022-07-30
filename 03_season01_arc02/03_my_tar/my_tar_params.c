#include "my_string.h"
#include "my_tar_params.h"
#include <stdlib.h>
#include <stdbool.h>

void init_my_tar_params(my_tar_params* tar_params_ptr, int ac, char**av) {
    tar_params_ptr->file_names = NULL;
    tar_params_ptr->n_files = 0;
    tar_params_ptr->n_flags = 0;
    
    //no parameters
    if (ac == 1) {
        my_puts("my_tar: Must specify one of -c, -r, -t, -u, -x");
    }
    //invalid parameters
    else if (ac > 1 && is_not_flag(av[1])) {
        my_puts("Usage:\n"
            "  List:    my_tar -tf <archive-filename>\n"
            "  Extract: my_tar -xf <archive-filename>\n"
            "  Create:  my_tar -cf <archive-filename> [filenames...]");
    }
    //valid parameters
    else {
        
        tar_params_ptr->n_files = ac - 2; //TODO ac - (count n_flags);
        tar_params_ptr->file_names = (char**) malloc(sizeof(char*) * (tar_params_ptr->n_files));
        
        int av_index = 2; // TODO count n_flags
        int names_index = 0;
        while (av_index < ac) {
            tar_params_ptr->file_names[names_index] = (char*) malloc((my_strlen(av[av_index]) + 1) * sizeof(char));
            my_strcpy(tar_params_ptr->file_names[names_index], av[av_index]);
            names_index++;
            av_index++;
        }
    }
}

void clean_my_tar_params(my_tar_params* tar_params_ptr) {
    for(int i = 0; i < tar_params_ptr->n_files; i++) {
        free(tar_params_ptr->file_names[i]);
    }
    free(tar_params_ptr->file_names);
}

int is_not_flag(char* flag) {
    return(my_strlen(flag) <= 1 || flag[0] != '-');
}

