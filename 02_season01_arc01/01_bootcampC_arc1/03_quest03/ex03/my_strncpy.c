char* my_strncpy(char* param_1, char* param_2, int param_3) {
    int i = 0, j = 0;
    while(param_1[i] != 0) {
        i++;
    }
    while(param_2[j] != 0 && j < param_3) {
        param_1[i] = param_2[j++];
        i++;
    }
    param_1[i] = '\0';
    return param_1;
}

