#include "array_string.h"
#include "my_string.h"
#include <stdio.h>

int main(int ac, char** av) {
    //no files or flags
    if (ac == 1) {
        print_cur_dir(0, 0); //current dir with no directories, no sorting by time
        return 0;
    }

    int withDirectories = 0;
    int sortedByTime = 0;
    int nFlags = 0;
    
    if (ac > 1) {
        nFlags = check_flags(av, ac, &withDirectories, &sortedByTime);
    }
    //if there are only flags and there are no dirs or files
    if (nFlags == ac) {
        print_cur_dir(withDirectories, sortedByTime);
        return 0;
    }
    //if there are some invalid flags
    else if (nFlags == -1) {
        return 0;
    }

    //if there are some (non files, files or dirs to print)
    my_ls(av, ac, withDirectories, sortedByTime, nFlags);

    return 0;
}


/**
 * 
 * 1) main -> count flags and check for invalid, -a and -t flags
 * 2) my_ls -> creates three string array (non files, dirs, files)
 *      initialize arrays with dir names, file names or non file names
 *      sort string arrays by names or by times
 *      print non files, files, dirs
 *      free memory
 * 
 
 */