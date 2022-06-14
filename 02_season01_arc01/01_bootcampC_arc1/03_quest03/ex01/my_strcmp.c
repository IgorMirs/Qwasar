int my_strcmp(char* param_1, char* param_2) {
    int i;
    for(i = 0; param_1[i] != 0 && param_2[i] != 0; i++) {
        if (param_1[i] < param_2[i]) {
            return -1;
        }
        else if (param_2[i] < param_1[i]) {
            return 1;
        }
    }
    //second string longer than first one
    if (param_1[i] == 0 && param_2[i] != 0) {
        return -1;
    }
    //first string longer than second one
    else if (param_2[i] == 0 && param_1[i] != 0) {
        return 1;
    }
    //strings are equal
    else {
        return 0;
    }
}