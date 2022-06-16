int* my_range(int param_1, int param_2) {
    if (param_1 >= param_2) {
        return 0;
    }
    int* res = (int*) malloc((param_2 - param_1) * sizeof(int));
    int i = 0;
    while(param_1 < param_2) {
        res[i++] = param_1; 
        param_1++;
    }
    return res;
}