#include "array_string.h"
#include "my_string.h"
#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <stdlib.h>

////****FUNCTION IMPLEMENTATION****////
int count_files(char** dirs, int nDirs, int type, int toStart) {
    int count = 0;
    int i = (toStart) ? toStart : 1;
    for (; i < nDirs; i++) {
        struct stat* buf = (struct stat*) malloc(sizeof(struct stat));
        
        DIR *dr = opendir(dirs[i]);
        //not a directory nor a file
        if (dr == NULL && stat(dirs[i], buf) != 0 && type == 2) {
            //printf("my_ls: %s: No such file or directory\n", dirs[i]);
            count++;
        }
        //count files
        else if (dr == NULL && stat(dirs[i], buf) == 0 && type == 0) {
            count++;
        }
        //count dirs
        else if (dr != NULL && type == 1) {
            count++;
        }
        free(buf);
        closedir(dr);
    }

    return count;
}

int count_files_in_dir(char* dir, int withDirectories) {
    int count = 0;
    struct dirent *de;

    DIR *dr = opendir(dir);
    while((de = readdir(dr)) != NULL) { 
        if (!withDirectories && de->d_name[0] == '.') {
            continue;
        }
        count++;
    }

    closedir(dr);
    return count;
}

void init_s_array(array_string* arr, int type, char** dirs, int nDirs, int toStart) {
    arr->size = count_files(dirs, nDirs, type, toStart);
    if (arr->size == 0) {
        return;
    }
    arr->array = (char**) malloc(sizeof(char*) * arr->size);
    arr->mod_time = (long*) malloc(sizeof(long) * arr->size);
    
    int index = 0;
    
    //initialize array of strings with file and dirs names
    int i = (toStart) ? toStart : 1;
    for (; i < nDirs; i++) {
        //helps differenciate valid file or directory for invalid ones
        struct stat* buf = (struct stat*) malloc(sizeof(struct stat));
        
        DIR *dr = opendir(dirs[i]);
        //init not files nor dirs (type 2)
        if (dr == NULL && stat(dirs[i], buf) != 0 && type == 2) {
            arr->array[index] = (char*)malloc((my_strlen(dirs[i]) + 1) * sizeof(char));
            my_strcpy(arr->array[index], dirs[i]);
            index++;
        }
        //init files (type 0)
        else if (dr == NULL && stat(dirs[i], buf) == 0 && type == 0) {
            arr->array[index] = (char*)malloc((my_strlen(dirs[i]) + 1) * sizeof(char));
            my_strcpy(arr->array[index], dirs[i]);
            arr->mod_time[index] = buf->st_mtim.tv_sec;
            index++;
        }
        //init dirs (type 1)
        else if (dr != NULL && type == 1) {
            arr->array[index] = (char*)malloc((my_strlen(dirs[i]) + 1) * sizeof(char));
            my_strcpy(arr->array[index], dirs[i]);
            arr->mod_time[index] = buf->st_mtim.tv_sec;
            index++;
        }
        free(buf);
        closedir(dr);
    }
}

void init_s_array_files(array_string* dirs_arr, char* dir, int withDirectories) {
    dirs_arr->size = count_files_in_dir(dir, withDirectories);

    dirs_arr->array = (char**) malloc(sizeof(char*) * dirs_arr->size);
    dirs_arr->mod_time = (long*) malloc(sizeof(long) * dirs_arr->size);
    struct dirent *de;

    DIR *dr = opendir(dir);
    int d_index = 0;

    while((de = readdir(dr)) != NULL) { 
        if (!withDirectories && de->d_name[0] == '.') {
            continue;
        }
        dirs_arr->array[d_index] = (char*)malloc((my_strlen(de->d_name) + 1) * sizeof(char));
        my_strcpy(dirs_arr->array[d_index], de->d_name);
        struct stat* buf = (struct stat*) malloc(sizeof(struct stat));
        stat(de->d_name, buf);
        dirs_arr->mod_time[d_index] = buf->st_mtim.tv_sec;
        d_index++;
        free (buf);
    }

    closedir(dr);

}

void print_files_names(array_string* arr) {
    for(int i = 0; i < arr->size; i++) {
        printf("%s\n", arr->array[i]);
    }
}

void print_not_files_names(array_string* not_files_arr) {
    for(int i = 0; i < not_files_arr->size; i++) {
        printf("my_ls: %s: No such file or directory\n", not_files_arr->array[i]);
    }
}


void print_files_in_dirs(array_string* dirs_arr, int withDirectories, int sortByTime, int printDirName) {
    for(int i = 0; i < dirs_arr->size; i++) {
        if (printDirName) {
            printf("\n%s:\n", dirs_arr->array[i]);
        }
        else if (i == 0 && dirs_arr->size > 1) {
            printf("%s:\n", dirs_arr->array[i]);
        }
        else if (dirs_arr->size > 1) {
            printf("\n%s:\n", dirs_arr->array[i]);
        }

        array_string* files_arr = (array_string*) malloc(sizeof(array_string));

        init_s_array_files(files_arr, dirs_arr->array[i], withDirectories);
        sort_s_array(files_arr, sortByTime);
        print_files_names(files_arr);

        free_s_array(files_arr);
    }
}

void print_cur_dir(int withDirectories, int sortByTime) {
    array_string* files_arr = (array_string*) malloc(sizeof(array_string));
    init_s_array_files(files_arr, ".", withDirectories);
    sort_s_array(files_arr, sortByTime);
    print_files_names(files_arr);
    free_s_array(files_arr);
}

void free_s_array(array_string* arr) {
    if (arr->size == 0) {
        free(arr);
        return;
    }
    for(int i = 0; i < arr->size; i++) {
        free(arr->array[i]);
    }

    free(arr->array);
    free(arr->mod_time);
    free(arr);
}

void sort_s_array(array_string* arr, const int sortByTime) {
    if (arr->size < 2) {
        return;
    }

    int wall = 0;
    for (int i = 0; i < arr->size; i++) {
        for (int j = 0; j < arr->size - 1 - wall; j++) {
            if (!sortByTime) {
                //if the left string is smaller than the right one
                if (my_strcmp(arr->array[j], arr->array[j + 1]) > 0) {
                    swap_strings(&arr->array[j], &arr->array[j + 1]);
                    swap_times(&arr->mod_time[j], &arr->mod_time[j + 1]);
                }
            }
            if (sortByTime == 1) {
                if (arr->mod_time[j] < arr->mod_time[j + 1]) {
                    swap_strings(&arr->array[j], &arr->array[j + 1]);
                    swap_times(&arr->mod_time[j], &arr->mod_time[j + 1]);
                }
            }
        }
        wall++;
    }

}

void swap_strings(char** s1, char** s2) {
    char* temp = *s1;
    *s1 = *s2;
    *s2 = temp;
}

void swap_times(long* t1, long* t2) {
    long temp = *t1;
    *t1 = *t2;
    *t2 = temp;
}

int check_flags(char** s, int size, int* a_flag, int* t_flag) {
  
    int i = 1; //start from the second parameter

    //if the second parameter is not a flag
    if (is_not_flag(s[i])) {
        *a_flag = 0;
        *t_flag = 0;
        return 0;
    }
    else if (!is_valid_flag(s[i])) {
        printf("my_ls: invalid option -- %c\n", get_invalid_flag(s[i]));
        my_puts("usage: my_ls [-at] [file ...]");
        return -1;
    }
    //good flag - update options
    update_flags(s[i], a_flag, t_flag);
    i++; //finished checking the first flag

    while (i < size && is_not_flag(s[i]) == 0) {
        if (!is_valid_flag(s[i])) {
            printf("my_ls: invalid option -- %c\n", get_invalid_flag(s[i]));
            my_puts("usage: my_ls [-at] [file ...]");
            return -1;
        }
        update_flags(s[i], a_flag, t_flag);
        i++;
    }
    return i;

}

int is_valid_flag(char* flag) {
    for (int i = 1; i < my_strlen(flag); i++) {
        if (flag[i] != 'a' && flag[i] != 't') {
            return 0;
        }
    }
    return 1;
}

char get_invalid_flag(char* flag) {
    for (int i = 1; i < my_strlen(flag); i++) {
        if (flag[i] != 'a' && flag[i] != 't') {
            return flag[i];
        }
    }
    return -1;
}

void update_flags(char* flag, int* a_flag, int* t_flag) {
    for(int i = 1; i < my_strlen(flag); i++) {
        if (*a_flag == 0 && flag[i] == 'a') {
            *a_flag = 1;
        }
        else if (*t_flag == 0 && flag[i] == 't') {
            *t_flag = 1;
        }
    }
}

int is_not_flag(char* flag) {
    return(my_strlen(flag) <= 1 || flag[0] != '-');
}

void my_ls(char** dirs, int nDirs, int withDirectories, int sortByTime, int toStart) {
    //create and initialize arrays of string for (non files, files and dirs)
    array_string* not_files_arr = (array_string*) malloc(sizeof(array_string));
    array_string* files_arr = (array_string*) malloc(sizeof(array_string));
    array_string* dirs_arr = (array_string*) malloc(sizeof(array_string));
    init_s_array(not_files_arr, 2, dirs, nDirs, toStart);
    init_s_array(files_arr, 0, dirs, nDirs, toStart);
    init_s_array(dirs_arr, 1, dirs, nDirs, toStart);
    
    //sorting
    sort_s_array(not_files_arr, sortByTime);
    sort_s_array(files_arr, sortByTime);
    sort_s_array(dirs_arr, sortByTime);
    
    //printing
    print_not_files_names(not_files_arr);
    print_files_names(files_arr);
    int printDirNames = (not_files_arr->size != 0 || files_arr->size != 0) ? 1 : 0;
    print_files_in_dirs(dirs_arr, withDirectories, sortByTime, printDirNames);
    
    //free the memory
    free_s_array(files_arr);
    free_s_array(dirs_arr);
    free_s_array(not_files_arr);
}
