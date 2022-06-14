char* my_strrchr(char* param_1, char param_2) {
    char* iter = param_1;
    while(*iter != 0) {
        iter++;
    }
    while(iter != param_1) {
        if (*iter == param_2) {
            return iter;
        }
        iter--;
    }
    return (*iter == param_2) ? iter : 0;
}