char* my_strdup(char* param_1) {
    //count the size of the given string
    int i;
    for(i = 0; param_1[i] != 0; i++) {
        
    }
    //allocate the memory
    char* res = (char*) malloc(i);
    //copy the string
    i = 0;
    while(*param_1 != 0) {
        res[i++] = *param_1;
        param_1++;
    }
    res[i] = '\0';

    return res;
}