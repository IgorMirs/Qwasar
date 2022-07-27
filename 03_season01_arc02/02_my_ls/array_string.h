#ifdef __APPLE__
#ifndef st_mtim
#define st_mtim st_mtimespec
#endif
#endif

#ifndef ARRAY_STRING
#define ARRAY_STRING
typedef struct {
    int size;
    char** array;
    long* mod_time;
} array_string;

////****FUNCTION PROTOTYPES****////
/**
 * 
 * 
 * @param type 0 - files; 1 - dirs; 2 - not file nor dir
 */
int     count_files(char** dirs, int nDirs, int type, int toStart);

/**
 * @brief Counts the number of files in the given directory
 * 
 * @param dir directory name
 * @param withDirectories if 0 - count only files
 *                          if 1 - count files with directories
 * @return int the number of files 
 */
int     count_files_in_dir(char* dir, int withDirectories);

/**
 * @brief Initialize the given array of strings with the names of files,
 *          non files, or directories. Dynamically allocates the memory
 *          for the array of string and for modification times.
 * 
 * @param dirs_arr array of strings
 * @param type 0 - files; 1 - dirs; 2 - not file nor dir 
 * @param dirs the list of (files/ non files/ dirs)
 * @param nDirs the number of (files/ non files/ dirs)
 * @param toStart from which number of file in the list to start initialization
 */
void    init_s_array(array_string* dirs_arr, int type, char** dirs, int nDirs, int toStart);

void    init_s_array_files(array_string* dirs_arr, char* dir, int withDirectories);
void    print_files_names(array_string* files_arr);
void    print_not_files_names(array_string* files_arr);

/**
 * @brief   Print files in the given dir.
 * 
 * @param   dirs_arr array with dir names 
 * @param   withDirectories 
 * @param   sortByTime 
 * @param   printDirName    1 - print dir name as a first line
 *                          0 - not to print the dir name
 */
void    print_files_in_dirs(array_string* dirs_arr, int withDirectories, int sortByTime, int printDirName);

void    print_cur_dir(int withDirectories, int sortByTime);
void    free_s_array(array_string* arr);
void    sort_s_array(array_string* arr, const int sortByTime);
void    swap_strings(char** s1, char** s2);
void    swap_times(long* t1, long* t2);

/**
 * @brief Checks and updates the given flag
 * 
 * @param s         The list of strings with possible flags 
 * @param size      the size of the list of strings
 * @param a_flag    pointer that stores 0 if '-a' is presented in the list of flags
 *                  and 1 otherwise
 * @param t_flag    pointer that stores 0 if '-a' is presented in the list of flags
 *                  and 1 otherwise
 * @return int      The number of valid flags in the given list of flags (s)
 *                  Returns -1 if at least one flag is invalid
 */
int     check_flags(char** s, int size, int* a_flag, int* t_flag);

/**
 * @brief   Checks does the given flag consist of valid characters.
 *          For this project valid characters are ('a', 't').
 * 
 * @param   flag string representing flag(s) 
 * @return  int 1 - if the given string consist only of valid characters
 *          and 0 otherwise. 
 */
int     is_valid_flag(char* flag);

/**
 * @brief   Returns the first invalid flag character from the given
 *          string flag
 * 
 * @param   flag string representing flag(s) 
 * @return  char the first invalid flag character from the given
 *          string flag 
 */
char    get_invalid_flag(char* flag);

void    update_flags(char* flag, int* a_flag, int* t_flag);

/**
 * @brief   Checks is the given string could be a potential flag.
 *          The flag should start with '-' and be at least two characters
 *          long.
 * 
 * @param   flag  string representing flag(s) 
 * @return  int 1 - if the given string cannot be a flag and 0 otherwise 
 */
int     is_not_flag(char* flag);

/**
 * @brief   Reproduce the behavior of ls function. (man ls)
 * 
 * @param   dirs  the list of (files/ non files/ dirs)
 * @param   nDirs the number of (files/ non files/ dirs)
 * @param   withDirectories if 0 - count only files
 *                          if 1 - count files with directories
 * @param   sortByTime      if 1 - Sort by time modified 
 *                          (most recently modified first) 
 * @param   toStart from which number of file in the list (dirs) to start
 */
void    my_ls(char** dirs, int nDirs, int withDirectories, int sortByTime, int toStart);

#endif