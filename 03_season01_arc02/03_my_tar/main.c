#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>

#include "my_tar_params.h"
#include "my_tar_header.h"
#include "my_string.h"

/**
 * 1. Get the size of file with stat
 * 2. Open(create) .tar file
 * 3. Read file in array of chars.
 * 4. 
 *  
 */

bool isOnBit(int num, int pos) {
	int mask = 1;
	mask = mask << pos;
	return num & mask;
}

void displayBits(int num) {
	for (int i = sizeof(num) * 8 - 1; i >= 0; i--) {
		my_putchar(isOnBit(num, i) ? '1' : '0');
	}
	putchar('\n');
}



int main(int ac, char** av) {
    my_tar_params* tar_p_ptr = (my_tar_params*) malloc(sizeof(my_tar_params));
    my_tar_header* tar_h_ptr = (my_tar_header*) malloc(sizeof(my_tar_header));
    
    //init parameters (flags, files)
    init_my_tar_params(tar_p_ptr, ac, av);
    
    //init the header(name, mode ...)
    init_my_tar_header(tar_h_ptr, tar_p_ptr);

    print_tar_header(tar_h_ptr);

    //free the memory   
    clean_my_tar_params(tar_p_ptr);
    free(tar_h_ptr);
    free(tar_p_ptr);

    return 0;

    
    
    // int fd = 0;
    // if(ac > 1) {
    //     struct stat* buf = (struct stat*) malloc(sizeof(struct stat));
    //     stat(av[1], buf);
    //     int size = buf->st_size;
    //     printf("File size is %d\n", size);

    //     fd = open(av[1], O_RDONLY);
    //     char *str = (char*) malloc(sizeof(char) * size + 1);
    //     int sz = read(fd, str, size); //returns the number of read bytes

    //     str[sz] = '\0';
    //     printf("%s\n", str);

    //     int new_fd = open(av[2], O_CREAT | O_WRONLY);
    //     int wr_size = write(new_fd, str, size); 
    //     printf("wr_size %d\n", wr_size);

    //     free(str);

    //     close(fd);
    //     close(new_fd);

    // }
    // else {
    //     printf("%s\n", "my_tar: Must specify one of -c, -r, -t, -u, -x");
    // }

}