#include "my_tar_header.h"
#include "my_string.h"
#include "my_tar_params.h"
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>

void init_my_tar_header(my_tar_header* tar_head_ptr, my_tar_params* tar_param_ptr) {
    //set name
    set_name(tar_head_ptr, tar_param_ptr->file_names[0]);
    
    //set mode
    struct stat* buf = (struct stat*) malloc(sizeof(struct stat));
    if(stat(tar_param_ptr->file_names[0], buf) == 0) {
        set_mode(tar_head_ptr, buf->st_mode, 3);
        printf("%o\n", buf->st_mode);
        if (S_ISREG(buf->st_mode)) {
            my_puts("Reg file");
        }
    }
    else{
        my_puts("ERROR stat");
    }

    free(buf);     

    
}

void set_mode(my_tar_header* tar_head, unsigned n, int k) {
    if (k < 1 || k > 7) {
        tar_head->mode[0] = '\0';
        return;
    }
    int i = 0;
    while(i < 7 - k) {
        tar_head->mode[i] = '0';
        i++;
    } 
    
    while(k > 0) {
        tar_head->mode[i + k - 1] = n % 8 + '0';
        n /= 8;
        k--;
    }
    tar_head->mode[7] = '\0';
}  


void set_name(my_tar_header* tar_head_ptr, char* name) {
    my_strcpy(tar_head_ptr->name, name);
}

void print_tar_header(my_tar_header* tar_head_ptr) {
    printf("%s", tar_head_ptr->name);
    printf("%s", tar_head_ptr->mode);
}