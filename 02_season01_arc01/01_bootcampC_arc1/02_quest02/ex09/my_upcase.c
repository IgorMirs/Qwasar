char* my_upcase(char* param_1) {
    char* res = param_1;
    while(*param_1 != 0) {
        if (*param_1 >= 'a' && *param_1 <= 'z') {
            *param_1 -= 32;
        }
        param_1++;
    }
    return res;
}