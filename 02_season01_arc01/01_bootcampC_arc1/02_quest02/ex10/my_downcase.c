char* my_downcase(char* param_1) {
    char* res = param_1;
    while(*param_1 != 0) {
        if (*param_1 >= 'A' && *param_1 <= 'Z') {
            *param_1 += 32;
        }
        param_1++;
    }
    return res;
}